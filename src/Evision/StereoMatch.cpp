#include "StereoMatch.h"
#include <QFileDialog>
#include "EvisionUtils.h"
#include <direct.h>
#include <qDebug>

StereoMatch::StereoMatch(std::string img1_filename, std::string img2_filename, std::string cameraParams_filename)
{
	m_entity = StereoMatchParamEntity::getInstance();
	this->img1_filename = img1_filename;
	this->img2_filename = img2_filename;
	QFileInfo *_fileInfo1 = new QFileInfo(QString::fromStdString(img1_filename));
	QFileInfo *_fileInfo2 = new QFileInfo(QString::fromStdString(img2_filename));
	
	if(_fileInfo1->absolutePath()!=_fileInfo2->absolutePath())
	{
		//左右视图不在一起
		//先把左右视图拷贝到一起
	}

	this->cameraParams_filename = cameraParams_filename;
	//构造midname:左视图名_右视图名
	std::string midname = _fileInfo1->baseName().toStdString();
	midname.append("_");
	midname.append(_fileInfo2->baseName().toStdString());

	this->disparity_filename = _fileInfo1->absolutePath().toStdString().append("/disp-"+ midname+".jpg");
	this->point_cloud_filename = _fileInfo1->absolutePath().toStdString().append("/pointcloud-"+ midname +".xml");

	//
}

StereoMatch::~StereoMatch()
{
}
/*
 * 初始化
 */
bool StereoMatch::init(bool needCameraParamFile)
{
	std::cout<<"初始化..." <<std::endl;
	try
	{
		//1.打开图片
		
		std::cout << "加载图片..." << std::endl;
		if(m_entity->getBM() == true)//使用BM算法
		{
			cv::Mat img1proc, img2proc;

			img1proc = cv::imread(img1_filename);
			img2proc = cv::imread(img2_filename);
			cv::cvtColor(img1proc, img1, CV_BGR2GRAY);
			cv::cvtColor(img2proc, img2, CV_BGR2GRAY);

		}else//使用SGBM算法
		{
			img1 = cv::imread(img1_filename);
			img2 = cv::imread(img2_filename);
		}
		img1.convertTo(img1, CV_8UC1);
		img2.convertTo(img2, CV_8UC1);
		qDebug() << "channels="<<img1.channels()<<"   depth=" << img1.depth();
		if (img1.empty() || img2.empty())
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("输入图像为空!"));
			return false;
		}
		img_size = img1.size();
		if (needCameraParamFile==true)//需要使用参数文件
		{
			//2.打开参数文件,读取参数

			std::cout << "加载参数..." << std::endl;

			bool flag = EvisionUtils::read_ParamsForStereoMatch(cameraParams_filename,
				&cameraMatrix1, &distCoeffs1, &cameraMatrix2, &distCoeffs2, &R1, &P1, &R2, &P2, &Q, &roi1, &roi2);
			if (flag == false)
			{
				return false;
			}
			//3.矫正左右视图

			std::cout << "矫正图片..." << std::endl;

			//先分别计算出x方向和y方向的两个镜头的校正矩阵
			cv::Mat mapx1, mapy1, mapx2, mapy2;
			initUndistortRectifyMap(cameraMatrix1, distCoeffs1, R1, P1, img_size, CV_16SC2, mapx1, mapy1);
			initUndistortRectifyMap(cameraMatrix2, distCoeffs2, R2, P2, img_size, CV_16SC2, mapx2, mapy2);
			//进行校正计算
			cv::Mat img1r, img2r;
			remap(img1, img1r, mapx1, mapy1, cv::INTER_LINEAR);
			remap(img2, img2r, mapx2, mapy2, cv::INTER_LINEAR);

			img1 = img1r;
			img2 = img2r;
		}
		
	}
	catch (...)
	{
		return false;
	}
	
	std::cout << "初始化完毕..." << std::endl;

	return true;
}

/*
 * 线程方法
 */
void StereoMatch::run()
{
	if (m_entity->getUseExpeModule()==true)
	{
		NewMatchFunc();
	}
	else
	{
		MatchFunc();
	}
}
//实验性匹配方法
void StereoMatch::NewMatchFunc()
{
	/************************************************************************/
	/* load and resize images                                               */
	/************************************************************************/


	cv::Mat imgL = cv::imread(img1_filename);
	cv::Mat imgR = cv::imread(img2_filename);


	if (!(imgL.data) || !(imgR.data))
	{
		std::cerr << "can't load image!" << std::endl;
		return;
	}
	m_entity->setIconImgL(imgL);
	m_entity->setIconImgR(imgR);

	float stdWidth = 800, resizeScale = 1;//stdWidth can change
	if (imgL.cols > stdWidth * 1.2)
	{
		resizeScale = stdWidth / imgL.cols;
		cv::Mat imgL1, imgR1;
		cv::resize(imgL, imgL1, cv::Size(), resizeScale, resizeScale);
		cv::resize(imgR, imgR1, cv::Size(), resizeScale, resizeScale);
		imgL = imgL1.clone();
		imgR = imgR1.clone();
	}

	/************************************************************************/
	/* decide which points in the left image should be chosen               */
	/* and calculate their corresponding points in the right image          */
	/************************************************************************/
	std::cout << "calculating feature points..." << std::endl;
	std::vector<cv::Point2f> ptsL, ptsR;
	std::vector<int> ptNum;
	if (g_algo == FEATURE_PT)
	{
		//if ( ! LoadPtsPairs(ptsL, ptsR, groupname+".pairs"))	{
		GetPair(imgL, imgR, ptsL, ptsR);
		//SavePtsPairs(ptsL, ptsR, groupname+".pairs");	}
	}
	else if (g_algo == DENSE)
		GetPairBM(imgL, imgR, ptsL, ptsR);

	/************************************************************************/
	/* calculate 3D coordinates                                             */
	/************************************************************************/
	std::vector<cv::Point3f> pts3D;
	float focalLenInPixel = 3740 * resizeScale,
		baselineInMM = 160;
	cv::Point3f center3D;
	cv::Vec3f size3D;
	float scale = .2; // scale the z coordinate so that it won't be too large spreaded
	//float imgHinMM = 400, // approximate real height of the scene in picture, useless
	//float MMperPixel = imgHinMM / imgL.rows;
	//float focalLenInMM = focalLenInPixel * MMperPixel;
	focalLenInPixel *= scale;

	std::cout << "calculating 3D coordinates..." << std::endl;
	StereoTo3D(ptsL, ptsR, pts3D, focalLenInPixel, baselineInMM, imgL, center3D, size3D);

}
//稳定版匹配方法
void StereoMatch::MatchFunc()
{
	std::cout << "开始计算..." << std::endl;
	m_entity->setIconImgL(img1);
	m_entity->setIconImgR(img2);
	cv::Ptr<cv::StereoBM> bm = cv::StereoBM::create(16, 9);
	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(0, 16, 3);

	//numberOfDisparities = numberOfDisparities > 0 ? numberOfDisparities : ((img_size.width / 8) + 15) & -16;
	bm->setROI1(roi1);
	bm->setROI2(roi2);
	bm->setPreFilterCap(m_entity->getPrefilcap());
	bm->setBlockSize(m_entity->getSadWinsz());
	bm->setMinDisparity(m_entity->getMinDisp());
	bm->setNumDisparities(m_entity->getNumDisparities());
	bm->setTextureThreshold(m_entity->getTextThread());
	bm->setUniquenessRatio(m_entity->getUniradio());
	bm->setSpeckleWindowSize(m_entity->getSpecwinsz());
	bm->setSpeckleRange(m_entity->getSpecrange());
	bm->setDisp12MaxDiff(m_entity->getMaxdifdisp12());

	sgbm->setPreFilterCap(m_entity->getPrefilcap());
	sgbm->setBlockSize(m_entity->getSadWinsz());
	int cn = img1.channels();
	sgbm->setP1(48 * cn*m_entity->getSadWinsz()*m_entity->getSadWinsz());
	sgbm->setP2(48 * cn*m_entity->getSadWinsz()*m_entity->getSadWinsz());
	sgbm->setMinDisparity(m_entity->getMinDisp());
	sgbm->setNumDisparities(m_entity->getNumDisparities());
	sgbm->setUniquenessRatio(m_entity->getUniradio());
	sgbm->setSpeckleWindowSize(m_entity->getSpecwinsz());
	sgbm->setSpeckleRange(m_entity->getSpecrange());
	sgbm->setDisp12MaxDiff(m_entity->getMaxdifdisp12());
	if (m_entity->getMODE_HH())
		sgbm->setMode(cv::StereoSGBM::MODE_HH);
	else if (m_entity->getMODE_SGBM())
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM);
	else if (m_entity->getMODE_3WAY())
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM_3WAY);

	// 对左右视图的左边进行边界延拓，以获取与原始视图相同大小的有效视差区域
	cv::Mat img1p, img2p;
	copyMakeBorder(img1, img1p, 0, 0, m_entity->getNumDisparities(), 0, IPL_BORDER_REPLICATE);
	copyMakeBorder(img2, img2p, 0, 0, m_entity->getNumDisparities(), 0, IPL_BORDER_REPLICATE);

	cv::Mat dispWithBorder;
	int64 t = cv::getTickCount();
	if (m_entity->getBM())
	{
		bm->compute(img1p, img2p, dispWithBorder);
	}	
	else if (m_entity->getSGBM())
	{
		sgbm->compute(img1p, img2p, dispWithBorder);
	}

	// 截取与原始画面对应的视差区域（舍去加宽的部分）
	cv::Mat dispWithoutBorder;
	cv::Mat m_Calib_Mat_Mask_Roi = cv::Mat::zeros(img_size.height, img_size.width, CV_8UC1);
	cv::rectangle(m_Calib_Mat_Mask_Roi, roi1, cv::Scalar(255), -1);
	dispWithBorder.colRange(m_entity->getNumDisparities(), img1p.cols).copyTo(dispWithoutBorder, m_Calib_Mat_Mask_Roi);
	//获取用于显示的原始视差图,显示效果和保存的视差图一致
	cv::Mat disp8;
	dispWithoutBorder.convertTo(disp8, CV_8U, 255 / (m_entity->getNumDisparities()*16.));
	m_entity->setIconRawDisp(disp8);
	//获取并显示伪彩色视差图
	cv::Mat colordisp;
	getColorDisparityImage(dispWithoutBorder, colordisp, true);
	m_entity->setIconPcolorDisp(colordisp);

	t = cv::getTickCount() - t;

	std::cout << "Time elapsed: "<< t * 1000 / cv::getTickFrequency() <<"ms\nStereoMatch计算完毕,正在输出..." << std::endl;

	if (!disparity_filename.empty())
	{
		imwrite(disparity_filename, dispWithoutBorder);
		std::cout << "视差图已经保存到:" << disparity_filename << std::endl;
	}
	if (m_entity->getDoRectify()==true)//给出相机参数
	{
		std::cout << "正在输出点云文件..." << std::endl;

		cv::Mat xyz;
		reprojectImageTo3D(dispWithoutBorder, xyz, Q, true);
		//disp.convertTo(disp, CV_32F, 1.0 / 16.0);
		//Q.convertTo(Q, CV_32F);
		//customReproject(disp, Q, xyz);


		if (EvisionUtils::write_PointCloud(point_cloud_filename, xyz))
		{
			m_entity->setXYZ(xyz);
			std::cout << "点云文件已经保存到:" << point_cloud_filename << std::endl;
		}
		else
		{
			std::cout << "点云保存失败..." << std::endl;
		}
		//保存PCL点云文件,PCL点云使用左视图和视差图构建
		/*相机参数取自左摄像头
		 * 视差图:disp
		 * 左视图:img1
		 * u0,v0 焦距
		   fx,fy 主点
		   Tx 基线长度
		   doffs cx1-cx2,主点的横坐标差
		前四个来自相机矩阵,极限长度来自...Tx来自...
		 */

		std::cout << "计算完毕" << std::endl;
		saveXYZ("F:\\xyz.txt", xyz);
		std::cout << "F:\\xyz.txt保存完毕" << std::endl;
	}
	else
	{
		std::cout << "不使用相机参数则无法计算坐标!" << std::endl;
	}
	
	return ;
}

void StereoMatch::saveXYZ(const std::string& fileName, const cv::Mat& image3D)
{
	CV_Assert(image3D.type() == CV_32FC3 && !image3D.empty());
	CV_Assert(!fileName.empty());

	std::ofstream outFile(fileName);

	if (!outFile.is_open())
	{
		std::cerr << "ERROR: Could not open " << fileName << std::endl;
		return;
	}

	for (int i = 0; i < image3D.rows; i++)
	{
		const cv::Vec3f* image3D_ptr = image3D.ptr<cv::Vec3f>(i);

		for (int j = 0; j < image3D.cols; j++)
		{
			if(image3D_ptr[j][2]>=-10000&& image3D_ptr[j][2]<=10000)
			{
				outFile << image3D_ptr[j][0] << " " << image3D_ptr[j][1] << " " << image3D_ptr[j][2] << std::endl;
			}
		}
	}

	outFile.close();
}
/*
 * 自定义三维重投影
 * cv::Mat&		[in]	disparity	视差图
 * cv::Mat&		[in]	Q			Q矩阵
 * cv::Mat&		[out]	out3D		含有三维坐标的三通道图片
 */
void StereoMatch::customReproject(const cv::Mat& disparity, const cv::Mat& Q, cv::Mat& out3D)
{
	CV_Assert(disparity.type() == CV_32F);
	CV_Assert(!disparity.empty());
	CV_Assert(Q.type() == CV_32F);
	CV_Assert(Q.cols == 4);
	CV_Assert(Q.rows == 4);
	// 3-channel matrix for containing the reprojected 3D world coordinates
	out3D = cv::Mat::zeros(disparity.size(), CV_32FC3);

	// Getting the interesting parameters from Q, everything else is zero or one
	float Q03 = Q.at<float>(0, 3);
	float Q13 = Q.at<float>(1, 3);
	float Q23 = Q.at<float>(2, 3);
	float Q32 = Q.at<float>(3, 2);
	float Q33 = Q.at<float>(3, 3);

	// Transforming a single-channel disparity map to a 3-channel image representing a 3D surface
	for (int i = 0; i < disparity.rows; i++)
	{
		const float* disp_ptr = disparity.ptr<float>(i);
		cv::Vec3f* out3D_ptr = out3D.ptr<cv::Vec3f>(i);

		for (int j = 0; j < disparity.cols; j++)
		{
			const float pw = 1.0f / (disp_ptr[j] * Q32 + Q33);

			cv::Vec3f& point = out3D_ptr[j];
			point[0] = (static_cast<float>(j) + Q03) * pw;
			point[1] = (static_cast<float>(i) + Q13) * pw;
			point[2] = Q23 * pw;
		}
	}
}
/*
 * 获取用于显示的视差图
 * cv::Mat&		[in]	disparity			视差图
 * cv::Mat&		[out]	disparityImage		转换结果
 * bool			[in]	isclolr				是否添加伪彩效果
 */
void StereoMatch::getColorDisparityImage(cv::Mat& disparity, cv::Mat& disparityImage, bool isColor)
{
	//将原始视差数据的位深转换为 8 位
		cv::Mat disp8u;
	if (disparity.depth() != CV_8U)
	{
		disparity.convertTo(disp8u, CV_8U, 255 / (m_entity->getNumDisparities()*16.));
	}
	else
	{
		disp8u = disparity;
	}

	// 转换为伪彩色图像 或 灰度图像
	if (isColor)
	{
		if (disparityImage.empty() || disparityImage.type() != CV_8UC3)
		{
			disparityImage = cv::Mat::zeros(disparity.rows, disparity.cols, CV_8UC3);
		}

		for (int y = 0; y < disparity.rows; y++)
		{
			for (int x = 0; x < disparity.cols; x++)
			{
				uchar val = disp8u.at<uchar>(y, x);
				uchar r, g, b;

				if (val == 0)
					r = g = b = 0;
				else
				{
					r = 255 - val;
					g = val < 128 ? val * 2 : (uchar)((255 - val) * 2);
					b = val;
				}

				disparityImage.at<cv::Vec3b>(y, x) = cv::Vec3b(r, g, b);
			}
		}
	}
	else
	{
		disp8u.copyTo(disparityImage);
	}

	return;
}

void StereoMatch::StereoTo3D(std::vector<cv::Point2f> ptsL, std::vector<cv::Point2f> ptsR,
	std::vector<cv::Point3f>& pts3D, float focalLenInPixel, float baselineInMM, cv::Mat img, cv::Point3f& center3D,
	cv::Vec3f& size3D)
{
	std::vector<cv::Point2f>::iterator iterL = ptsL.begin(),
		iterR = ptsR.begin();

	float xl, xr, ylr;
	float imgH = float(img.rows), imgW = float(img.cols);
	cv::Point3f pt3D;
	float minX = 1e9, maxX = -1e9;
	float minY = 1e9, maxY = -1e9;
	float minZ = 1e9, maxZ = -1e9;

	cv::Mat imgShow = img.clone();
	char str[100];
	int ptCnt = ptsL.size(), showPtNum = 30, cnt = 0;
	int showIntv = max(ptCnt / showPtNum, 1);
	for (; iterL != ptsL.end(); iterL++, iterR++)
	{
		xl = iterL->x;
		xr = iterR->x; // need not add baseline
		ylr = (iterL->y + iterR->y) / 2;

		//if (yl-yr>5 || yr-yl>5) // may be wrong correspondence, discard. But vector can't be changed during iteration
		//{}

		pt3D.z = -focalLenInPixel * baselineInMM / (xl - xr); // xl should be larger than xr, if xl is shot by the left camera
		pt3D.y = -(-ylr + imgH / 2) * pt3D.z / focalLenInPixel;
		pt3D.x = (imgW / 2 - xl) * pt3D.z / focalLenInPixel;

		minX = min(minX, pt3D.x); maxX = max(maxX, pt3D.x);
		minY = min(minY, pt3D.y); maxY = max(maxY, pt3D.y);
		minZ = min(minZ, pt3D.z); maxZ = max(maxZ, pt3D.z);
		pts3D.push_back(pt3D);

		if ((cnt++) % showIntv == 0)
		{
			cv::Scalar color = CV_RGB(rand() & 64, rand() & 64, rand() & 64);
			sprintf_s(str, 100, "%.0f,%.0f,%.0f", pt3D.x, pt3D.y, pt3D.z);
			putText(imgShow, str, cv::Point(xl - 13, ylr - 3), cv::FONT_HERSHEY_SIMPLEX, .3, color);
			circle(imgShow, *iterL, 2, color, 3);
		}
		//cv::imshow("test", imgShow);
	}

	imshow("back project", imgShow);
	//m_entity->setIconPointImgL(imgShow);
	//cv::waitKey();

	center3D.x = (minX + maxX) / 2;
	center3D.y = (minY + maxY) / 2;
	center3D.z = (minZ + maxZ) / 2;
	size3D[0] = maxX - minX;
	size3D[1] = maxY - minY;
	size3D[2] = maxZ - minZ;
}

void StereoMatch::GetPair(cv::Mat& imgL, cv::Mat& imgR, std::vector<cv::Point2f>& ptsL,
	std::vector<cv::Point2f>& ptsR)
{
	cv::Mat descriptorsL, descriptorsR;
	double tt = (double)cv::getTickCount();

	cv::Ptr<cv::Feature2D> detector = cv::xfeatures2d::SIFT::create();
	std::vector<cv::KeyPoint> keypointsL, keypointsR;
	detector->detect(imgL, keypointsL);
	detector->detect(imgR, keypointsR);

	//Ptr<DescriptorExtractor> de = DescriptorExtractor::create(DESCRIPTOR_TYPE);
	//SurfDescriptorExtractor de(4,2,true);
	detector->compute(imgL, keypointsL, descriptorsL);
	detector->compute(imgR, keypointsR, descriptorsR);

	tt = ((double)cv::getTickCount() - tt) / cv::getTickFrequency(); // 620*555 pic, about 2s for SURF, 120s for SIFT

	cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create(MATCHER_TYPE);
	std::vector<std::vector<cv::DMatch>> matches;
	matcher->knnMatch(descriptorsL, descriptorsR, matches, 2); // L:query, R:train

	std::vector<cv::DMatch> passedMatches; // save for drawing
	cv::DMatch m1, m2;
	std::vector<cv::Point2f> ptsRtemp, ptsLtemp;
	for (int i = 0; i < matches.size(); i++)
	{
		m1 = matches[i][0];
		m2 = matches[i][1];
		if (m1.distance < MAXM_FILTER_TH * m2.distance)
		{
			ptsRtemp.push_back(keypointsR[m1.trainIdx].pt);
			ptsLtemp.push_back(keypointsL[i].pt);
			passedMatches.push_back(m1);
		}
	}

	cv::Mat HLR;
	HLR = findHomography(cv::Mat(ptsLtemp), cv::Mat(ptsRtemp), CV_RANSAC, 3);
	std::cout << "Homography:" << std::endl << HLR << std::endl;
	cv::Mat ptsLt;
	perspectiveTransform(cv::Mat(ptsLtemp), ptsLt, HLR);

	std::vector<char> matchesMask(passedMatches.size(), 0);
	int cnt = 0;
	for (int i1 = 0; i1 < ptsLtemp.size(); i1++)
	{
		cv::Point2f prjPtR = ptsLt.at<cv::Point2f>((int)i1, 0); // prjx = ptsLt.at<float>((int)i1,0), prjy = ptsLt.at<float>((int)i1,1);
		 // inlier
		if (abs(ptsRtemp[i1].x - prjPtR.x) < HOMO_FILTER_TH &&
			abs(ptsRtemp[i1].y - prjPtR.y) < 2) // restriction on y is more strict
		{
			std::vector<cv::Point2f>::iterator iter = ptsL.begin();
			for (; iter != ptsL.end(); iter++)
			{
				cv::Point2f diff = *iter - ptsLtemp[i1];
				float dist = abs(diff.x) + abs(diff.y);
				if (dist < NEAR_FILTER_TH) break;
			}
			if (iter != ptsL.end()) continue;

			ptsL.push_back(ptsLtemp[i1]);
			ptsR.push_back(ptsRtemp[i1]);
			cnt++;
			if (cnt % 1 == 0) matchesMask[i1] = 1; // don't want to draw to many matches
		}
	}

	cv::Mat outImg;
	drawMatches(imgL, keypointsL, imgR, keypointsR, passedMatches, outImg,
		cv::Scalar::all(-1), cv::Scalar::all(-1), matchesMask, cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	char title[50];
	sprintf_s(title, 50, "%.3f s, %d matches, %d passed", tt, matches.size(), cnt);
	imshow(title, outImg);
	cv::waitKey();
}

void StereoMatch::GetPairBM(cv::Mat& imgL, cv::Mat& imgR, std::vector<cv::Point2f>& ptsL,
	std::vector<cv::Point2f>& ptsR)
{
	cv::Mat_<float> disp;
	//imshow("left image", imgL);

	int numOfDisp = 80; // number of disparity, must be divisible by 16// algorithm parameters that can be modified
	CalcDisparity(imgL, imgR, disp, numOfDisp);
	cv::Mat dispSave, dispS;
	normalize(disp, dispSave, 0, 1, cv::NORM_MINMAX);
	dispSave.convertTo(dispSave, CV_8U, 255);
	imwrite("disp.jpg", dispSave);

	//int numOfEgdePt = 80, numOfFlatPt = 50;	// algorithm parameters that can be modified
	//ChooseKeyPointsBM(disp, numOfDisp, numOfEgdePt, numOfFlatPt, ptsL, ptsR);
	//cv::waitKey();
}

void StereoMatch::CalcDisparity(cv::Mat& imgL, cv::Mat& imgR, cv::Mat_<float>& disp, int nod)
{
	enum { STEREO_BM = 0, STEREO_SGBM = 1, STEREO_HH = 2 };
	int alg = STEREO_SGBM;

	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create();
	int cn = imgR.channels();

	sgbm->setBlockSize(3);
	sgbm->setNumDisparities(nod);
	sgbm->setPreFilterCap(63);
	sgbm->setP1(8 * cn*sgbm->getBlockSize()*sgbm->getBlockSize());
	sgbm->setP2(32 * cn*sgbm->getBlockSize()*sgbm->getBlockSize());
	sgbm->setMinDisparity(0);
	sgbm->setUniquenessRatio(10);
	sgbm->setSpeckleWindowSize(100);
	sgbm->setSpeckleRange(32);
	sgbm->setDisp12MaxDiff(1);
	sgbm->setMode(cv::StereoSGBM::MODE_HH);

	cv::Mat dispTemp, disp8;
	sgbm->compute(imgL, imgR, dispTemp);
	dispTemp.convertTo(disp, CV_32FC1, 1.0 / 16);
	disp.convertTo(disp8, CV_8U, 255.0 / nod);
	//imshow("origin disparity", disp8);
	m_entity->setIconRawDisp(disp8);
	//waitKey();

	FixDisparity(disp, nod);
	disp.convertTo(disp8, CV_8U, 255.0 / nod);
	//imshow("fixed disparity", disp8);
	m_entity->setIconFixDisp(disp8);
}

// roughly smooth the glitches on the disparity map
void StereoMatch::FixDisparity(cv::Mat_<float>& disp, int numberOfDisparities)
{
	cv::Mat_<float> disp1;
	float lastPixel = 10;
	float minDisparity = 23;// algorithm parameters that can be modified
	for (int i = 0; i < disp.rows; i++)
	{
		for (int j = numberOfDisparities; j < disp.cols; j++)
		{
			if (disp(i, j) <= minDisparity) disp(i, j) = lastPixel;
			else lastPixel = disp(i, j);
		}
	}
	int an = 4;	// algorithm parameters that can be modified
	copyMakeBorder(disp, disp1, an, an, an, an, cv::BORDER_REPLICATE);
	cv::Mat element = getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(an * 2 + 1, an * 2 + 1));
	morphologyEx(disp1, disp1, CV_MOP_OPEN, element);
	morphologyEx(disp1, disp1, CV_MOP_CLOSE, element);
	disp = disp1(cv::Range(an, disp.rows - an), cv::Range(an, disp.cols - an)).clone();
}