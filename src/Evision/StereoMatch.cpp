#define NOMINMAX
#include "StereoMatch.h"
#include <QFileDialog>
#include "EvisionUtils.h"
//#include <direct.h>
#include <qDebug>
#include "../EvisionElas/EvisionElas.h"
//#include <boost/filesystem/path.hpp>
//#include <boost/filesystem/operations.hpp>
//#include <pcl/common/common_headers.h>
//#include <pcl/io/pcd_io.h>
#include "../EvisionADCensus/imageprocessor.h"
#include "../EvisionADCensus/stereoprocessor.h"
//#include <boost/date_time/posix_time/ptime.hpp>
//#include <boost/thread/lock_algorithms.hpp>

#include <QTime>
#include "rectify.h"
#include <algorithm>
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
	this->root = _fileInfo1->absolutePath().toStdString().append("/");
	this->disparity_filename = _fileInfo1->absolutePath().toStdString().append("/disp-"+ midname+".png");
	this->disparity_raw_filename= _fileInfo1->absolutePath().toStdString().append("/disp-raw-" + midname + ".xml");
	this->point_cloud_filename = _fileInfo1->absolutePath().toStdString().append("/pointcloud-"+ midname +".pcd");

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
		//1.打开图片,按照原图格式打开,如果所选的算法对于图片的格式有要求,自行转换
		std::cout << "加载图片..." << std::endl;
		img1 = cv::imread(img1_filename);
		img2 = cv::imread(img2_filename);
		if (img1.empty() || img2.empty())
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("输入图像为空!"));
			return false;
		}
		//2.读取相机参数
		std::cout << "读取相机参数..." << std::endl;
		bool flag = EvisionUtils::read_AllCameraParams(cameraParams_filename,
			&cameraMatrix1, &distCoeffs1, &cameraMatrix2, &distCoeffs2, &R, &T, &E, &F, &img_size, &R1, &P1, &R2, &P2, &Q, &roi1, &roi2);
		if(flag==false)
		{
			std::cout << "相机参数读取失败!" << std::endl;
			return false;
		}
		//3.如果输入的是未校正的图片,则在此处进行校正
		if (!m_entity->getRectifiedInput())
		{
			std::cout << "输入的是未校正的图片,进行校正..." << std::endl;
			try
			{
				std::vector<cv::Mat>images, undistortedImages;
				images.push_back(img1);
				images.push_back(img2);

				cv::Size imageSize;
				imageSize.height = ((cv::Mat)images.at(0)).rows;
				imageSize.width = ((cv::Mat)images.at(0)).cols;

				//先把两侧的图片利用畸变矩阵分别消除畸变
				intrinsicExtrinsic::undistortStereoImages(images, undistortedImages, cameraMatrix1, cameraMatrix2, distCoeffs1, distCoeffs2);
				//这一步计算极线矫正矩阵,畸变已经消除了所以畸变参数设置为了0
				cv::Mat rmap[2][2];
				cv::Mat noDist = cv::Mat::zeros(5, 1, CV_32F);
				initUndistortRectifyMap(cameraMatrix1, noDist, R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);
				initUndistortRectifyMap(cameraMatrix2, noDist, R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);
				int imgCount = undistortedImages.size() / 2;
				//计算ROI
				/*
				 *(std::max)for disable the macro max in winnt.h
				 *see: http://www.voidcn.com/article/p-okycmabx-bms.html
				 */
				cv::Point2i rectCorner1((std::max)(roi1.x, roi2.x), (std::max)(roi1.y, roi2.y));
				cv::Point2i rectCorner2((std::min)(roi1.x + roi1.width, roi2.x + roi2.width),
					(std::min)(roi1.y + roi1.height, roi2.y + roi2.height));
				cv::Rect validRoi = cv::Rect(rectCorner1.x, rectCorner1.y, rectCorner2.x - rectCorner1.x, rectCorner2.y - rectCorner1.y);
				cv::Mat  remapImg1, rectImg1, remapImg2, rectImg2;
				remap(undistortedImages[0], remapImg1, rmap[0][0], rmap[0][1], CV_INTER_LINEAR);
				rectImg1 = remapImg1(validRoi);//校正结果
				remap(undistortedImages[1], remapImg2, rmap[1][0], rmap[1][1], CV_INTER_LINEAR);
				rectImg2 = remapImg2(validRoi);//校正结果

				img1 = rectImg1;
				img2 = rectImg2;
				std::cout << "校正完毕" << std::endl;

			}catch(...)
			{
				std::cout << "校正过程中发生了严重错误" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "输入的是校正过的图片,跳过校正..." << std::endl;
		}		
	}
	catch (...)
	{
		std::cout << "匹配模块的初始化过程发生严重错误!" << std::endl;
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
	try
	{
		if (m_entity->getBM() == true)
		{
			OpenCVBM();
		}
		else if (m_entity->getSGBM() == true)
		{
			OpenCVSGBM();
		}
		else if (m_entity->getElas() == true)
		{
			Elas();
		}
		else if (m_entity->getADCensus() == true)
		{
			ADCensusDriver();
		}
	}
	catch(...)
	{
		std::cout << "算法执行过程中出现严重错误,地点在:[StereoMatch 线程方法]" << std::endl;
	}
}
/*
 * 保存原始视差数据,视差示意图,PCD点云
 */
void StereoMatch::Save()
{
	if (!Raw_Disp_Data.empty() && !Gray_Disp_Data.empty())
	{
		try
		{
			cv::FileStorage fs(disparity_raw_filename, cv::FileStorage::WRITE);
			fs << "disp" << Raw_Disp_Data;
			fs.release();
			std::cout << "已经保存原始视差数据:" << disparity_raw_filename << std::endl;
			/*
			 * 用于显示的视差图并不是准确数据,为了获得良好的显示效果而对数据进行了一些裁剪和压缩
			 * 例如归一化到0~255会改变原始的视差数据,因此,测量时必须使用原始视差数据
			 */
			 //获取灰度视差图并保存
			cv::imwrite(disparity_filename, Gray_Disp_Data);
			std::cout << "已经保存视差示意图:" << disparity_filename << std::endl;

			//保存pcd点云
#ifdef WITH_PCL
			EvisionUtils::createAndSavePointCloud(Raw_Disp_Data, img2, Q, point_cloud_filename);
			std::cout << "已经保存PCD点云:" << point_cloud_filename << std::endl;
#endif
		}
		catch (...)
		{
			std::cout << "保存过程中出现严重错误!\n" << "地点在:StereoMatch.cpp, void StereoMatch::Save()" << std::endl;
		}

	}
}

/*
 * ADCensus
 */
void StereoMatch::ADCensusDriver()
{

#pragma region 参数
	// Minimum and maximum disparity
	uint dMin = 0;
	uint dMax = 60;

	// Parameters for the cost-initialization for the ADCensus
	cv::Size censusWin;
	censusWin.height = 9;
	censusWin.width = 7;
	float defaultBorderCost = 0.999;
	float lambdaAD = 10.0; // TODO Namen anpassen
	float lambdaCensus = 30.0;


	// Parameters for the cross-based cost aggregation
	uint aggregatingIterations = 4;
	uint colorThreshold1 = 20;
	uint colorThreshold2 = 6;
	uint maxLength1 = 34;
	uint maxLength2 = 17;

	// Parameters for the optimization of image cells
	uint colorDifference = 15;
	float pi1 = 0.1;
	float pi2 = 0.3;

	// Parameters for outlier detection
	uint dispTolerance = 0;
	// Parameters for the iterative range rating
	uint votingThreshold = 20;
	float votingRatioThreshold = 4;

	// Parameters for the proper interpolation
	uint maxSearchDepth = 20;

	// Parameters for the approximation of depths discontinuities 
	uint cannyThreshold1 = 20;
	uint cannyThreshold2 = 60;
	uint cannyKernelSize = 3;

	// Parameters for the sub-pixel enhancement
	uint blurKernelSize = 3;
#pragma endregion 
	m_entity->setIconImgL(img1);
	m_entity->setIconImgR(img2);
	//加载Q矩阵
	cv::Mat Q(4, 4, CV_64F);
	Q=this->Q;
	//加载images
	std::vector<cv::Mat> images;
	images.push_back(img1);
	images.push_back(img2);
	if (images.size() % 2 == 0)
	{
		bool error = false;
		for (int i = 0; i < (images.size() / 2) && !error; ++i)
		{
			QTime time;
			time.start();//计时开始

			ImageProcessor iP(0.1);
			cv::Mat eLeft, eRight;
			eLeft = iP.unsharpMasking(images[i * 2], "gauss", 3, 1.9, -1);
			eRight = iP.unsharpMasking(images[i * 2 + 1], "gauss", 3, 1.9, -1);

			StereoProcessor sP(dMin, dMax, images[i * 2], images[i * 2 + 1], 
				censusWin, defaultBorderCost, lambdaAD, lambdaCensus, root,
				aggregatingIterations, colorThreshold1, colorThreshold2, maxLength1, maxLength2,
				colorDifference, pi1, pi2, dispTolerance, votingThreshold, votingRatioThreshold,
				maxSearchDepth, blurKernelSize, cannyThreshold1, cannyThreshold2, cannyKernelSize);
			string errorMsg;
			error = !sP.init(errorMsg);

			if (!error && sP.compute())
			{
				//保存视差数据
				Raw_Disp_Data = sP.getDisparity();
				/*
				 * 用于显示的视差图并不是准确数据,为了获得良好的显示效果而对数据进行了一些裁剪和压缩
				 * 例如归一化到0~255会改变原始的视差数据,因此,测量时必须使用原始视差数据
				 */

				Gray_Disp_Data = sP.getGrayDisparity();
				//界面显示灰度视差图
				m_entity->setIconRawDisp(Gray_Disp_Data);
			}
			else
			{
				std::cout << "[ADCensusCV] " << errorMsg << endl;
			}
			std::cout << "Finished computation after " << time.elapsed() / 1000.0 << "s" << std::endl;
		}
	}
	else
	{
		std::cout << "[ADCensusCV] Not an even image number!" << std::endl;
	}
}
/*
 * OpenCV-BM
 */
void StereoMatch::OpenCVBM()
{
	std::cout << "BM开始计算..." << std::endl;
	cv::Mat img1G,img2G;
	cv::cvtColor(img1, img1G, CV_RGB2GRAY);//把图片转化为灰度图
	cv::cvtColor(img2, img2G, CV_RGB2GRAY);//把图片转化为灰度图

	m_entity->setIconImgL(img1G);
	m_entity->setIconImgR(img2G);
	cv::Ptr<cv::StereoBM> bm = cv::StereoBM::create();
	//bm->setROI1(roi1);
	//bm->setROI2(roi2);
	bm->setPreFilterCap(m_entity->getPrefilcap());
	bm->setBlockSize(m_entity->getSadWinsz());
	bm->setMinDisparity(m_entity->getMinDisp());
	bm->setNumDisparities(m_entity->getNumDisparities());
	bm->setTextureThreshold(m_entity->getTextThread());
	bm->setUniquenessRatio(m_entity->getUniradio());
	bm->setSpeckleWindowSize(m_entity->getSpecwinsz());
	bm->setSpeckleRange(m_entity->getSpecrange());
	bm->setDisp12MaxDiff(m_entity->getMaxdifdisp12());
	int64 t = cv::getTickCount();
	bm->compute(img1G, img2G, Raw_Disp_Data);

	//获取用于显示的视差示意图
	EvisionUtils::getGrayDisparity<float>(Raw_Disp_Data, Gray_Disp_Data);
	m_entity->setIconRawDisp(Gray_Disp_Data);

	t = cv::getTickCount() - t;

	std::cout << "Time elapsed: " << t * 1000 / cv::getTickFrequency() << "ms\n BM计算完毕" << std::endl;
}
/*
 * OpenCV-SGBM
 */
void StereoMatch::OpenCVSGBM()
{
	std::cout << "SGBM 开始计算..." << std::endl;
	m_entity->setIconImgL(img1);
	m_entity->setIconImgR(img2);
	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(0, 16, 3);

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

	int64 t = cv::getTickCount();
	sgbm->compute(img1, img2, Raw_Disp_Data);
	

	//获取用于显示的视差示意图
	EvisionUtils::getGrayDisparity<float>(Raw_Disp_Data, Gray_Disp_Data);
	m_entity->setIconRawDisp(Gray_Disp_Data);

	t = cv::getTickCount() - t;
	std::cout << "Time elapsed: " << t * 1000 / cv::getTickFrequency() << "ms\n SGBM计算完毕" << std::endl;
}
/*
 * Elas
 */
void StereoMatch::Elas()
{
	ElasMatch(img1, img2);
}