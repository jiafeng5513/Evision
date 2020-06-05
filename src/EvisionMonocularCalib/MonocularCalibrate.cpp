#include "MonocularCalibrate.h"
#include <QMessageBox>
#include "QFileDialog"
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include "EvisionUtils.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QPixmap>


MonocularCalibrate::MonocularCalibrate(std::vector<std::string>* imagelistL,QObject * parent)
{
	m_entity = MonocularCalibrateParamEntity::getInstance();
	this->imagelistL = imagelistL;
	QFileInfo *_fileInfo = new QFileInfo(QString::fromStdString(imagelistL->at(0)));
	this->cameraParamsFilename = _fileInfo->absolutePath().toStdString().append("/MonocularCameraParams.yml");
}

MonocularCalibrate::~MonocularCalibrate()
{

}
/*
 * 线程方法
 */
void MonocularCalibrate::run()
{
	ready_to_save = false;
	try
	{
		cv::Size boardSize(m_entity->getBoardWidth(), m_entity->getBoardHeight());
		float squareSize = m_entity->getSquareSize();
		int flags_1D = getCalibrate1D_flags();

		bool showRectified = true;
		float  aspectRatio = 1;
		Pattern pattern = CHESSBOARD;
		bool showUndistorted = true;

		std::cout << "标定单目相机" << std::endl;
		Calib1D(boardSize, squareSize, *imagelistL, cameraMatrix_L, distCoeffs_L, aspectRatio, pattern, flags_1D, showUndistorted);

		ready_to_save = true;
	}
	catch (std::exception e)
	{
		std::cout << "标定出现严重错误!" <<e.what() << std::endl;

	}
}
/*
 * 把标定产生的参数保存到文件
 */
bool MonocularCalibrate::SaveCameraParamsToFile()
{
	if (ready_to_save==false)
	{
		std::cout << "没有准备好保存参数!" << std::endl;
		return false;
	}
	else
	{
		// 保存参数
		bool flag = EvisionUtils::write_MonocularCameraParams(cameraParamsFilename, cameraMatrix_L, distCoeffs_L, imageSize);
		std::cout << "参数已经保存到:" << cameraParamsFilename << std::endl;
		if (!flag)
		{
			emit openMessageBox(QStringLiteral("文件访问错误"), QStringLiteral("无法写入:cameraParams.yml"));
			return false;
		}
	}
	return true;
}

/*
 * 计算重投影误差
 */
double MonocularCalibrate::computeReprojectionErrors(const std::vector<std::vector<cv::Point3f>>& objectPoints,
	const std::vector<std::vector<cv::Point2f>>& imagePoints, const std::vector<cv::Mat>& rvecs,
	const std::vector<cv::Mat>& tvecs, const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs,
	std::vector<float>& perViewErrors)
{
	std::vector<cv::Point2f> imagePoints2;
	int i, totalPoints = 0;
	double totalErr = 0, err;
	perViewErrors.resize(objectPoints.size());

	for (i = 0; i < (int)objectPoints.size(); i++)
	{
		projectPoints(cv::Mat(objectPoints[i]), rvecs[i], tvecs[i],
			cameraMatrix, distCoeffs, imagePoints2);
		err = norm(cv::Mat(imagePoints[i]), cv::Mat(imagePoints2), cv::NORM_L2);
		int n = (int)objectPoints[i].size();
		perViewErrors[i] = (float)std::sqrt(err*err / n);
		totalErr += err * err;
		totalPoints += n;
	}

	return std::sqrt(totalErr / totalPoints);
}
/*
 * 初始化标定板corners
 */
void MonocularCalibrate::calcChessboardCorners(cv::Size boardSize, float squareSize, std::vector<cv::Point3f>& corners,
	Pattern patternType)
{
	corners.resize(0);

	switch (patternType)
	{
	case CHESSBOARD:
	case CIRCLES_GRID:
		for (int i = 0; i < boardSize.height; i++)
			for (int j = 0; j < boardSize.width; j++)
				corners.push_back(cv::Point3f(float(j*squareSize),
					float(i*squareSize), 0));
		break;

	case ASYMMETRIC_CIRCLES_GRID:
		for (int i = 0; i < boardSize.height; i++)
			for (int j = 0; j < boardSize.width; j++)
				corners.push_back(cv::Point3f(float((2 * j + i % 2)*squareSize),
					float(i*squareSize), 0));
		break;

	default:
		CV_Error(cv::Error::StsBadArg, "Unknown pattern type\n");
	}
}
/*
 * 单目标定的核心代码
 */
bool MonocularCalibrate::calibrate_1D_core(const std::vector<std::vector<cv::Point2f>>& imagePoints, cv::Size imageSize,
	cv::Size boardSize, float squareSize, float aspectRatio, int flags, cv::Mat& cameraMatrix, cv::Mat& distCoeffs)
{
	std::vector<cv::Mat> rvecs, tvecs;
	std::vector<float> reprojErrs;


	cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
	if (flags & cv::CALIB_FIX_ASPECT_RATIO)
		cameraMatrix.at<double>(0, 0) = aspectRatio;

	distCoeffs = cv::Mat::zeros(8, 1, CV_64F);

	std::vector<std::vector<cv::Point3f> > objectPoints(1);
	calcChessboardCorners(boardSize, squareSize, objectPoints[0]);

	objectPoints.resize(imagePoints.size(), objectPoints[0]);

	double rms = calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix,
		distCoeffs, rvecs, tvecs, flags);// cv::CALIB_FIX_K3 |
	printf("RMS error reported by calibrateCamera: %g\n", rms);

	bool ok = checkRange(cameraMatrix) && checkRange(distCoeffs);

	double totalAvgErr = computeReprojectionErrors(objectPoints, imagePoints,
		rvecs, tvecs, cameraMatrix, distCoeffs, reprojErrs);

	printf("%s. avg reprojection error = %.2f\n", ok ? "Calibration succeeded" : "Calibration failed", totalAvgErr);

	return ok;
}
/*
 * 单目标定的驱动代码
 *	cv::Size		[in]	boardSize				标定板尺寸
	float			[in]	squareSize				方格尺寸
	vector<string>	[in]	imageList				标定图片文件名
	Mat&			[io]	cameraMatrix			相机矩阵
	Mat&			[io]	distCoeffs				畸变系数
	float			[in]	aspectRatio=1			宽高比,只有当flag中指定CALIB_FIX_ASPECT_RATIO时才起作用
	Pattern			[in]	pattern=CHESSBOARD		标定板模式,可选:
														CHESSBOARD				象棋盘,
														CIRCLES_GRID			圆点阵列,
														ASYMMETRIC_CIRCLES_GRID	非对称圆点阵列
	int				[in]	flags=0					标定标志位,可选
														CALIB_FIX_ASPECT_RATIO	固定宽高比
														CALIB_ZERO_TANGENT_DIST
														CALIB_FIX_PRINCIPAL_POINT
	bool			[in]	showUndistorted=true	是否显示矫正之后的情况
 */
void MonocularCalibrate::Calib1D(cv::Size boardSize, float squareSize, std::vector<std::string> imageList,
	cv::Mat& cameraMatrix, cv::Mat& distCoeffs, float aspectRatio, Pattern pattern, int flags, bool showUndistorted)
{
	try
	{
		//cv::Size imageSize;//改成成员变量
		std::vector<std::vector<cv::Point2f> > imagePoints;
		int nframes = (int)imageList.size();
		//cv::namedWindow("Image View", 1);



		for (int i = 0;; i++)
		{
			cv::Mat view, viewGray;
			if (i < (int)imageList.size())
				view = cv::imread(imageList[i], 1);

			if (view.empty())//数据读完了,开始标定
			{
				if (imagePoints.size() > 0)
					std::cout << "数据读完了,开始标定" << std::endl;
					calibrate_1D_core(imagePoints, imageSize, boardSize, squareSize, aspectRatio, flags, cameraMatrix, distCoeffs);
				break;
			}

			imageSize = view.size();

			std::vector<cv::Point2f> pointbuf;
			cvtColor(view, viewGray, cv::COLOR_BGR2GRAY);

			bool found;
			switch (pattern)
			{
			case CHESSBOARD:
				found = findChessboardCorners(view, boardSize, pointbuf,
					cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_FAST_CHECK | cv::CALIB_CB_NORMALIZE_IMAGE);
				break;
			case CIRCLES_GRID:
				found = findCirclesGrid(view, boardSize, pointbuf);
				break;
			case ASYMMETRIC_CIRCLES_GRID:
				found = findCirclesGrid(view, boardSize, pointbuf, cv::CALIB_CB_ASYMMETRIC_GRID);
				break;
			default:
				return;
			}

			// improve the found corners' coordinate accuracy
			if (pattern == CHESSBOARD && found)
				cv::cornerSubPix(viewGray, pointbuf, cv::Size(11, 11), cv::Size(-1, -1),
					cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1));

			if (found)
			{
				imagePoints.push_back(pointbuf);
			}

			if (found)
				drawChessboardCorners(view, boardSize, cv::Mat(pointbuf), found);

			std::string msg = "100/100";
			int baseLine = 0;
			cv::Size textSize = cv::getTextSize(msg, 1, 1, 1, &baseLine);
			cv::Point textOrigin(view.cols - 2 * textSize.width - 10, view.rows - 2 * baseLine - 10);


			msg = cv::format("%d/%d", (int)imagePoints.size(), nframes);

			putText(view, msg, textOrigin, 1, 1, cv::Scalar(0, 0, 255));

			m_entity->insertItem(view);
		}

		if (showUndistorted)
		{
			cv::Mat view, rview, map1, map2;
			cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::Mat(),
				getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
				imageSize, CV_16SC2, map1, map2);

			for (int i = 0; i < (int)imageList.size(); i++)
			{
				view = cv::imread(imageList[i], 1);
				if (view.empty())
					continue;
				remap(view, rview, map1, map2, cv::INTER_LINEAR);
				m_entity->insertItem(rview);
			}
			std::cout << "单目相机矫正成功完成" << std::endl;
		}
	}
	catch (std::exception e)
	{
		std::cout << "Calib1D出现严重错误" << e.what() << std::endl;
	}
}

/*
 * 获取单目标定的flags
 */
int MonocularCalibrate::getCalibrate1D_flags()
{
	int flag = 0;
	if (m_entity->getCALIB_FIX_PRINCIPAL_POINT())
	{
		flag |= cv::CALIB_FIX_PRINCIPAL_POINT;
	}
	if (m_entity->getCALIB_FIX_ASPECT_RATIO())
	{
		flag |= cv::CALIB_FIX_ASPECT_RATIO;
	}
	if (m_entity->getCALIB_ZERO_TANGENT_DIST())
	{
		flag |= cv::CALIB_ZERO_TANGENT_DIST;
	}

	if (m_entity->getCALIB_FIX_K1())
	{
		flag |= cv::CALIB_FIX_K1;
	}
	if (m_entity->getCALIB_FIX_K2())
	{
		flag |= cv::CALIB_FIX_K2;
	}
	if (m_entity->getCALIB_FIX_K3())
	{
		flag |= cv::CALIB_FIX_K3;
	}
	if (m_entity->getCALIB_FIX_K4())
	{
		flag |= cv::CALIB_FIX_K4;
	}
	if (m_entity->getCALIB_FIX_K5())
	{
		flag |= cv::CALIB_FIX_K5;
	}
	if (m_entity->getCALIB_FIX_K6())
	{
		flag |= cv::CALIB_FIX_K6;
	}
	if(m_entity->getCALIB_RATIONAL_MODEL())
	{
		flag |= cv::CALIB_RATIONAL_MODEL;
	}
	if (m_entity->getCALIB_THIN_PRISM_MODEL())
	{
		flag |= cv::CALIB_THIN_PRISM_MODEL;
	}
	if (m_entity->getCALIB_FIX_S1_S2_S3_S4())
	{
		flag |= cv::CALIB_FIX_S1_S2_S3_S4;
	}
	if (m_entity->getCALIB_TILTED_MODEL())
	{
		flag |= cv::CALIB_TILTED_MODEL;
	}
	if (m_entity->getCALIB_FIX_TAUX_TAUY())
	{
		flag |= cv::CALIB_FIX_TAUX_TAUY;
	}
	return flag;
}

