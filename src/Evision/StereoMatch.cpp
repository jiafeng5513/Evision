#define NOMINMAX
#include "StereoMatch.h"
#include <QFileDialog>
#include <QTime>
#include "EvisionUtils.h"
#include "../EvisionElas/EvisionElas.h"
#include "../EvisionADCensus/imageprocessor.h"
#include "../EvisionADCensus/stereoprocessor.h"
#include "rectify.h"
#include <algorithm>
#include "../EvisionElas/elas.h"

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

		//2.如果输入的是未校正的图片,则在此处进行校正
		if (!m_entity->getRectifiedInput())
		{
			//3.读取相机参数
			std::cout << "读取相机参数..." << std::endl;
			bool flag = EvisionUtils::read_AllCameraParams(cameraParams_filename,
				&cameraMatrix1, &distCoeffs1, &cameraMatrix2, &distCoeffs2, &R, &T, &E, &F, &img_size, &R1, &P1, &R2, &P2, &Q, &roi1, &roi2);
			if(flag==false)
			{
				std::cout << "相机参数读取失败!" << std::endl;
				return false;
			}
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
	if (!Raw_Disp_Data.empty() && !Visual_Disp_Data.empty())
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
			cv::imwrite(disparity_filename, Visual_Disp_Data);
			std::cout << "已经保存视差示意图:" << disparity_filename << std::endl;

//			//保存pcd点云
//#ifdef WITH_PCL
//			EvisionUtils::createAndSavePointCloud(Raw_Disp_Data, img2, Q, point_cloud_filename);
//			std::cout << "已经保存PCD点云:" << point_cloud_filename << std::endl;
//#endif
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
	cv::Size censusWin;
	censusWin.height = m_entity->getCensusWinH();
	censusWin.width = m_entity->getCensusWinW();
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

			StereoProcessor sP(m_entity->getDMin(), m_entity->getDMax(), images[i * 2], images[i * 2 + 1],
				censusWin, m_entity->getDefaultBorderCost(), m_entity->getLambdaAD(), m_entity->getLambdaCensus(), root,
				m_entity->getAggregatingIterations(), m_entity->getColorThreshold1(), m_entity->getColorThreshold2(), 
				m_entity->getMaxLength1(), m_entity->getMaxLength2(),m_entity->getColorDifference(), m_entity->getPi1(), 
				m_entity->getPi2(), m_entity->getDispTolerance(), m_entity->getVotingThreshold(), m_entity->getVotingRatioThreshold(),
				m_entity->getMaxSearchDepth(), m_entity->getBlurKernelSize(), 
				m_entity->getCannyThreshold1(), m_entity->getCannyThreshold2(), m_entity->getCannyKernelSize());
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

				Visual_Disp_Data = sP.getGrayDisparity();
				//cv::normalize(Visual_Disp_Data, Visual_Disp_Data, 0, 255, cv::NORM_MINMAX);
				//界面显示灰度视差图
				m_entity->setIconRawDisp(Visual_Disp_Data);
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
	if (m_entity->getBM_preFilterType_XSOBEL()==true)
	{
		bm->setPreFilterType(cv::StereoBM::PREFILTER_XSOBEL);
	}
	else
	{
		bm->setPreFilterType(cv::StereoBM::PREFILTER_NORMALIZED_RESPONSE);
	}
	bm->setPreFilterSize(m_entity->getBM_preFilterSize());
	bm->setPreFilterCap(m_entity->getBM_preFilterCap());
	bm->setBlockSize(m_entity->getBM_SADWindowSize());//bm算法的BlockSize就是SADWindowSize
	bm->setMinDisparity(m_entity->getBM_minDisparity());
	bm->setNumDisparities(m_entity->getBM_numDisparities());
	bm->setTextureThreshold(m_entity->getBM_textureThreshold());
	bm->setUniquenessRatio(m_entity->getBM_uniquenessRatio());
	bm->setSpeckleRange(m_entity->getBM_speckleRange());
	bm->setSpeckleWindowSize(m_entity->getBM_speckleWindowSize());
	bm->setDisp12MaxDiff(m_entity->getBM_disp12MaxDiff());
	int64 t = cv::getTickCount();
	bm->compute(img1G, img2G, Raw_Disp_Data);
	Raw_Disp_Data.convertTo(Raw_Disp_Data, CV_8U, 1 / 16.);
	//获取用于显示的视差示意图
	cv::normalize(Raw_Disp_Data, Visual_Disp_Data, 0, 255, CV_MINMAX);
	m_entity->setIconRawDisp(Visual_Disp_Data);

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

	sgbm->setMinDisparity(m_entity->getSGBM_minDisparity());
	sgbm->setNumDisparities(m_entity->getSGBM_numDisparities());
	sgbm->setBlockSize(m_entity->getSGBM_blockSize());

	int delta = img1.channels()*m_entity->getSGBM_blockSize()*m_entity->getSGBM_blockSize();
	sgbm->setP1((m_entity->getSGBM_P1() < m_entity->getSGBM_P2() ? m_entity->getSGBM_P1()* delta : 8 * delta));
	sgbm->setP2((m_entity->getSGBM_P1() < m_entity->getSGBM_P2() ? m_entity->getSGBM_P2()* delta : 32 * delta));

	sgbm->setDisp12MaxDiff(m_entity->getSGBM_disp12MaxDiff());
	sgbm->setPreFilterCap(m_entity->getSGBM_preFilterCap());
	sgbm->setUniquenessRatio(m_entity->getSGBM_uniquenessRatio());
	sgbm->setSpeckleWindowSize(m_entity->getSGBM_speckleWindowSize());
	sgbm->setSpeckleRange(m_entity->getSGBM_speckleRange());

	if (m_entity->getSGBM_MODEL_HH4())
		sgbm->setMode(cv::StereoSGBM::MODE_HH4);
	else if (m_entity->getSGBM_MODEL_3WAY())
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM_3WAY);
	else if (m_entity->getSGBM_MODEL_Default())
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM);
	else 
		sgbm->setMode(cv::StereoSGBM::MODE_HH);

	int64 t = cv::getTickCount();
	sgbm->compute(img1, img2, Raw_Disp_Data);
	Raw_Disp_Data.convertTo(Raw_Disp_Data, CV_8U, 1 / 16.);

	//获取用于显示的视差示意图
	cv::normalize(Raw_Disp_Data, Visual_Disp_Data, 0, 255, CV_MINMAX);
	m_entity->setIconRawDisp(Visual_Disp_Data);

	t = cv::getTickCount() - t;
	std::cout << "Time elapsed: " << t * 1000 / cv::getTickFrequency() << "ms\n SGBM计算完毕" << std::endl;
}
/*
 * Elas
 */
void StereoMatch::Elas()
{

	std::cout << "Elas 开始计算..." << std::endl;
	m_entity->setIconImgL(img1);
	m_entity->setIconImgR(img2);
	Elas::parameters param;
	param.disp_min = m_entity->getDispMin();
	param.disp_max = m_entity->getDispMax();
	param.support_threshold = m_entity->getSupportThreshold();
	param.support_texture = m_entity->getSupportTexture();
	param.candidate_stepsize = m_entity->getCandidateStepsize();
	param.incon_window_size = m_entity->getInconWindowSize();
	param.incon_threshold = m_entity->getInconThreshold();
	param.incon_min_support = m_entity->getInconMinSupport();
	param.add_corners = m_entity->getAddCorners();
	param.grid_size = m_entity->getGridSize();
	param.beta = m_entity->getBeta();
	param.gamma = m_entity->getGamma();
	param.sigma = m_entity->getSigma();
	param.sradius = m_entity->getSradius();
	param.match_texture = m_entity->getMatchTexture();
	param.lr_threshold = m_entity->getLrThreshold();
	param.speckle_sim_threshold = m_entity->getSpeckleSimThreshold();
	param.speckle_size = m_entity->getSpeckleSize();
	param.ipol_gap_width = m_entity->getIpolGapWidth();
	param.filter_median = m_entity->getFilterMedian();
	param.filter_adaptive_mean = m_entity->getFilterAdaptiveMean();
	param.postprocess_only_left = m_entity->getPostprocessOnlyLeft();
	param.subsampling = m_entity->getSubSampling();

	int64 t = cv::getTickCount();
	ElasMatch(param,img1, img2,&Raw_Disp_Data, &Visual_Disp_Data);
	t = cv::getTickCount() - t;
	std::cout << "Time elapsed: " << t * 1000 / cv::getTickFrequency() << "ms\n ELAS计算完毕" << std::endl;
	m_entity->setIconRawDisp(Visual_Disp_Data);

}