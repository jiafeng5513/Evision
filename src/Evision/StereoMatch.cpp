#include "StereoMatch.h"
#include <QFileDialog>
#include "EvisionUtils.h"


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
bool StereoMatch::init()
{
	std::cout<<"初始化..." <<std::endl;
	try
	{
		//1.打开图片
		
		std::cout << "加载图片..." << std::endl;
		int color_mode = (m_entity->getBM()==true ? cv::IMREAD_GRAYSCALE : cv::IMREAD_COLOR);
		img1 = cv::imread(img1_filename, color_mode);
		img2 = cv::imread(img2_filename, color_mode);
		if (img1.empty() || img2.empty())
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("输入图像为空!"));
			return false;
		}
		img_size = img1.size();
		//2.打开参数文件,读取参数
		
		std::cout << "加载参数..." << std::endl;

		bool flag = EvisionUtils::read_ParamsForStereoMatch(cameraParams_filename,
			&cameraMatrix1, &distCoeffs1, &cameraMatrix2, &distCoeffs2, &R1, &P1, &R2, &P2, &Q,&roi1,&roi2);
		if (flag == false)
		{
			return false;
		}
		//3.矫正左右视图
		
		std::cout << "矫正图片..." << std::endl;

		cv::Mat mapx1, mapy1, mapx2, mapy2;
		initUndistortRectifyMap(cameraMatrix1, distCoeffs1, R1, P1, img_size, CV_16SC2, mapx1, mapy1);
		initUndistortRectifyMap(cameraMatrix2, distCoeffs2, R2, P2, img_size, CV_16SC2, mapx2, mapy2);

		cv::Mat img1r, img2r;
		remap(img1, img1r, mapx1, mapy1, cv::INTER_LINEAR);
		remap(img2, img2r, mapx2, mapy2, cv::INTER_LINEAR);

		//img1 = img1r;
		//img2 = img2r;
	}
	catch (...)
	{
		return false;
	}
	
	std::cout << "初始化完毕..." << std::endl;

	return true;
}


void StereoMatch::run()
{
	
	std::cout << "开始计算..." << std::endl;

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
	sgbm->setP1(8 * cn*m_entity->getSadWinsz()*m_entity->getSadWinsz());
	sgbm->setP2(32 * cn*m_entity->getSadWinsz()*m_entity->getSadWinsz());
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

	cv::Mat disp, disp8;
	//Mat img1p, img2p, dispp;
	//copyMakeBorder(img1, img1p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);
	//copyMakeBorder(img2, img2p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);

	int64 t = cv::getTickCount();
	if (m_entity->getBM())
	{
		bm->compute(img1, img2, disp);
	}	
	else if (m_entity->getSGBM())
	{
		sgbm->compute(img1, img2, disp);
	}
		
	t = cv::getTickCount() - t;

	std::cout << "Time elapsed: "<< t * 1000 / cv::getTickFrequency() <<"ms\n,StereoMatch计算完毕,正在输出..." << std::endl;

	//disp = dispp.colRange(numberOfDisparities, img1p.cols);
	
	disp.convertTo(disp8, CV_8U, 255 / (m_entity->getNumDisparities()*16.));
	
	//m_entity->setImageLtoShow(img1);
	//m_entity->setImageRtoShow(img2);
	m_entity->setImageDtoShow(disp8);
	//d

	if (!disparity_filename.empty())
	{
		imwrite(disparity_filename, disp);
		std::cout << "视差图已经保存到:" << disparity_filename << std::endl;
	}
		
	std::cout << "正在输出点云文件..." << std::endl;

	cv::Mat xyz;
	reprojectImageTo3D(disp, xyz, Q, false,-1);
	//disp.convertTo(disp, CV_32F, 1.0 / 16.0);
	//Q.convertTo(Q, CV_32F);
	//customReproject(disp, Q, xyz);


	if (EvisionUtils::write_PointCloud(point_cloud_filename,xyz))
	{
		m_entity->setXYZ(xyz);
		std::cout << "点云文件已经保存到:"<< point_cloud_filename << std::endl;
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
 * OpenCV(3.4.1) Error: 
 * Assertion failed (disparity.type() == 5 && !disparity.empty()) in StereoMatch::custo
mReproject, file e:\visualstudio\evision\src\evision\stereomatch.cpp, line 223

OpenCV(3.4.1) Error:
Assertion failed (((((sizeof(size_t)<<28)|0x8442211) >> ((traits::Depth<_Tp>::value) & ((1 << 3) - 1))*4) & 15) == elemSize1()) 

in cv::Mat::at, file e:\visualstudio\evision\package\opencv\build\include\opencv2\core\mat.inl.hpp, line 1119
 */