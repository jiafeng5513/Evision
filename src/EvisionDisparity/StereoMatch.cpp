#define NOMINMAX
#include "StereoMatch.h"
#include <QFileDialog>
#include <QTime>
#include "EvisionUtils.h"
#include "EvisionElas.h"
#include "EvisionADCensus.h"
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
	//cv::Mat Q(4, 4, CV_64F);
	//Q=this->Q;
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

			float percentageOfDeletion = 0.1;
			std::string blurMethod = "gauss";//"median"
			int kernelSize = 3;
			float alpha = 1.9;
			float beta = -1;

			EvisionADCensus adcensus( percentageOfDeletion, blurMethod, kernelSize, alpha, beta,
				m_entity->getDMin(), m_entity->getDMax(), images[i * 2], images[i * 2 + 1],
				censusWin, m_entity->getDefaultBorderCost(), m_entity->getLambdaAD(), m_entity->getLambdaCensus(), root,
				m_entity->getAggregatingIterations(), m_entity->getColorThreshold1(), m_entity->getColorThreshold2(), 
				m_entity->getMaxLength1(), m_entity->getMaxLength2(),m_entity->getColorDifference(), m_entity->getPi1(), 
				m_entity->getPi2(), m_entity->getDispTolerance(), m_entity->getVotingThreshold(), m_entity->getVotingRatioThreshold(),
				m_entity->getMaxSearchDepth(), m_entity->getBlurKernelSize(), 
				m_entity->getCannyThreshold1(), m_entity->getCannyThreshold2(), m_entity->getCannyKernelSize());
			std::string errorMsg;
			error = !adcensus.init(errorMsg);

			if (!error && adcensus.compute())
			{
				//保存视差数据
				Raw_Disp_Data = adcensus.getDisparity();
				/*
				 * 用于显示的视差图并不是准确数据,为了获得良好的显示效果而对数据进行了一些裁剪和压缩
				 * 例如归一化到0~255会改变原始的视差数据,因此,测量时必须使用原始视差数据
				 */

				Visual_Disp_Data = adcensus.getGrayDisparity();
				//cv::normalize(Visual_Disp_Data, Visual_Disp_Data, 0, 255, cv::NORM_MINMAX);
				//界面显示灰度视差图
				m_entity->setIconRawDisp(Visual_Disp_Data);
			}
			else
			{
				std::cout << "[ADCensusCV] " << errorMsg << std::endl;
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
	EvisionElas elas(
		m_entity->getDispMin(),m_entity->getDispMax(),m_entity->getSupportThreshold(),m_entity->getSupportTexture(),
		m_entity->getCandidateStepsize(),m_entity->getInconWindowSize(),m_entity->getInconThreshold(),
		m_entity->getInconMinSupport(),m_entity->getAddCorners(),m_entity->getGridSize(),m_entity->getBeta(),
		m_entity->getGamma(),m_entity->getSigma(),m_entity->getSradius(),m_entity->getMatchTexture(),
		m_entity->getLrThreshold(),m_entity->getSpeckleSimThreshold(),m_entity->getSpeckleSize(),
		m_entity->getIpolGapWidth(),m_entity->getFilterMedian(),m_entity->getFilterAdaptiveMean(),
		m_entity->getPostprocessOnlyLeft(),m_entity->getSubSampling(), 100);

	int64 t = cv::getTickCount();
	elas.Match(img1, img2, &Raw_Disp_Data, &Visual_Disp_Data);
	t = cv::getTickCount() - t;
	std::cout << "Time elapsed: " << t * 1000 / cv::getTickFrequency() << "ms\n ELAS计算完毕" << std::endl;
	m_entity->setIconRawDisp(Visual_Disp_Data);

}