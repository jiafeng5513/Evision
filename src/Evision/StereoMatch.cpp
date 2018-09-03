#include "StereoMatch.h"
#include <QFileDialog>


StereoMatch::StereoMatch(std::string img1_filename, std::string img2_filename, std::string intrinsic_filename, std::string extrinsic_filename)
{
	m_entity = EvisionParamEntity::getInstance();
	this->img1_filename = img1_filename;
	this->img2_filename = img2_filename;
	QFileInfo *_fileInfo1 = new QFileInfo(QString::fromStdString(img1_filename));
	QFileInfo *_fileInfo2 = new QFileInfo(QString::fromStdString(img2_filename));
	
	if(_fileInfo1->absolutePath()!=_fileInfo2->absolutePath())
	{
		//左右视图不在一起
		//先把左右视图拷贝到一起
	}

	this->intrinsic_filename = intrinsic_filename;
	this->extrinsic_filename = extrinsic_filename;
	std::string midname = _fileInfo1->baseName().toStdString();
	midname.append("_");
	midname.append(_fileInfo2->baseName().toStdString());
	this->disparity_filename = _fileInfo1->absolutePath().toStdString().append("/disp-"+ midname+".jpg");
	this->point_cloud_filename = _fileInfo1->absolutePath().toStdString().append("/pointcloud-"+ midname +".xml");
}

StereoMatch::~StereoMatch()
{
}


void StereoMatch::run()
{
	cv::Ptr<cv::StereoBM> bm = cv::StereoBM::create(16, 9);
	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(0, 16, 3);

	int color_mode = alg == STEREO_BM ? 0 : -1;
	cv::Mat img1 = cv::imread(img1_filename, color_mode);
	cv::Mat img2 = cv::imread(img2_filename, color_mode);

	if (img1.empty()||img2.empty())
	{
		emit openMessageBox(QStringLiteral("错误"), QStringLiteral("输入图像为空!"));
		return;
	}

	if (scale != 1.f)
	{
		cv::Mat temp1, temp2;
		int method = scale < 1 ? cv::INTER_AREA : cv::INTER_CUBIC;
		resize(img1, temp1, cv::Size(), scale, scale, method);
		img1 = temp1;
		resize(img2, temp2, cv::Size(), scale, scale, method);
		img2 = temp2;
	}

	cv::Size img_size = img1.size();

	cv::Rect roi1, roi2;
	cv::Mat Q;

	if (!intrinsic_filename.empty())
	{
		// 读取内参文件
		cv::FileStorage fs(intrinsic_filename, cv::FileStorage::READ);
		if (!fs.isOpened())
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("读取内部参数文件失败!"));
			return;
		}

		cv::Mat M1, D1, M2, D2;
		fs["M1"] >> M1;
		fs["D1"] >> D1;
		fs["M2"] >> M2;
		fs["D2"] >> D2;

		M1 *= scale;
		M2 *= scale;
		//读取外参文件
		fs.open(extrinsic_filename, cv::FileStorage::READ);
		if (!fs.isOpened())
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("读取外部参数文件失败!"));
			return ;
		}
		m_entity->setStatusBarText(QStringLiteral("参数就位,开始StereoMatch计算..."));
		cv::Mat R, T, R1, P1, R2, P2;
		fs["R"] >> R;
		fs["T"] >> T;

		stereoRectify(M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q, cv::CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2);

		cv::Mat map11, map12, map21, map22;
		initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
		initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);

		cv::Mat img1r, img2r;
		remap(img1, img1r, map11, map12, cv::INTER_LINEAR);
		remap(img2, img2r, map21, map22, cv::INTER_LINEAR);

		img1 = img1r;
		img2 = img2r;
	}

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
		bm->compute(img1, img2, disp);
	else if (m_entity->getSGBM())
		sgbm->compute(img1, img2, disp);
	t = cv::getTickCount() - t;
	char buff[128];
	sprintf(buff,"Time elapsed: %fms\n,StereoMatch计算完毕,正在输出...", t * 1000 / cv::getTickFrequency());
	m_entity->setStatusBarText(QString::fromStdString(buff));

	//disp = dispp.colRange(numberOfDisparities, img1p.cols);
	
	disp.convertTo(disp8, CV_8U, 255 / (m_entity->getNumDisparities()*16.));
	
	m_entity->setImageLtoShow(img1);
	m_entity->setImageRtoShow(img2);
	m_entity->setImageDtoShow(disp8);
	//d

	if (!disparity_filename.empty())
		imwrite(disparity_filename, disp8);

	if (!point_cloud_filename.empty())
	{
		//printf("storing the point cloud...");
		m_entity->setStatusBarText(QStringLiteral("正在输出点云文件..."));
		//fflush(stdout);
		cv::Mat xyz;
		reprojectImageTo3D(disp, xyz, Q, true);
		m_entity->setDisparity(disp8);
		m_entity->setXYZ(xyz);
		m_entity->setQ(Q);
		saveXYZ(point_cloud_filename.c_str(), xyz);
		//printf("\n");
	}
	m_entity->setStatusBarText(QStringLiteral("就绪"));

	return ;
}

void StereoMatch::saveXYZ(const char* filename, const cv::Mat& mat)
{
	const double max_z = 1.0e4;
	FILE* fp = fopen(filename, "wt");
	for (int y = 0; y < mat.rows; y++)
	{
		for (int x = 0; x < mat.cols; x++)
		{
			cv::Vec3f point = mat.at<cv::Vec3f>(y, x);
			if (fabs(point[2] - max_z) < FLT_EPSILON || fabs(point[2]) > max_z) continue;
			fprintf(fp, "%f %f %f\n", point[0], point[1], point[2]);
		}
	}
	fclose(fp);
}

//读取点云文件
cv::Mat StereoMatch::readXYZ(const char* filename)
{
	FILE* fp = fopen(filename, "rt");
}