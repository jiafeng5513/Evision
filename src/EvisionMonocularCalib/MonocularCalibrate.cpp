#include "MonocularCalibrate.h"
#include <QFileInfo>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include "EvisionUtils.h"

MonocularCalibrate::MonocularCalibrate(const std::vector<std::string>& imagelistL, QObject* parent)
	: QThread(parent), imagelistL(imagelistL)
{
	m_entity = MonocularCalibrateParamEntity::getInstance();
	if (!this->imagelistL.empty())
	{
		QFileInfo fileInfo(QString::fromStdString(this->imagelistL[0]));
		this->cameraParamsFilename = fileInfo.absolutePath().toStdString() + "/MonocularCameraParams.yml";
	}
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
	m_calibResult = MonoCalibResult();
	try
	{
		BoardConfig cfg;
		cfg.type = static_cast<BoardType>(m_entity->getBoardTypeIndex());
		cfg.boardSize = cv::Size(m_entity->getBoardWidth(), m_entity->getBoardHeight());
		cfg.squareSize = static_cast<float>(m_entity->getSquareSize());
		cfg.markerSize = m_entity->getMarkerSize();

		int flags_1D = getCalibrate1D_flags();

		std::cout << "标定单目相机" << std::endl;

		std::vector<std::vector<cv::Point2f>> imagePoints;
		std::vector<std::vector<cv::Point3f>> objectPoints;

		bool imageSizeInitialized = false;
		int validViews = 0;

		for (size_t i = 0; i < imagelistL.size(); ++i)
		{
			cv::Mat view = cv::imread(imagelistL[i], cv::IMREAD_COLOR);
			if (view.empty())
			{
				std::cout << "无法读取图像: " << imagelistL[i] << std::endl;
				continue;
			}

			if (!imageSizeInitialized)
			{
				imageSize = view.size();
				imageSizeInitialized = true;
			}
			else if (view.size() != imageSize)
			{
				std::cout << "跳过尺寸不匹配的图像: " << imagelistL[i] << std::endl;
				m_entity->insertItem(view);
				continue;
			}

			DetectionResult det = CalibrationCore::detectBoard(view, cfg);
			cv::Mat display = view.clone();

			if (det.found)
			{
				display = CalibrationCore::drawDetection(view, cfg, det);
				imagePoints.push_back(det.corners);
				objectPoints.push_back(det.objects);
				++validViews;
			}

			std::string msg = cv::format("%d/%d", (int)imagePoints.size(), (int)imagelistL.size());
			int baseLine = 0;
			cv::Size textSize = cv::getTextSize(msg, 1, 1, 1, &baseLine);
			cv::Point textOrigin(display.cols - 2 * textSize.width - 10, display.rows - 2 * baseLine - 10);
			cv::putText(display, msg, textOrigin, 1, 1, cv::Scalar(0, 0, 255));

			m_entity->insertItem(display);
		}

		if (validViews < 3)
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("有效视图不足,至少需要3个有效视图."));
			ready_to_save = false;
			return;
		}

		m_calibResult = CalibrationCore::calibrateMonocular(imagePoints, objectPoints, imageSize, flags_1D);
		if (!m_calibResult.ok)
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("单目标定失败."));
			ready_to_save = false;
			return;
		}

		cameraMatrix_L = m_calibResult.cameraMatrix.clone();
		distCoeffs_L = m_calibResult.distCoeffs.clone();
		imageSize = m_calibResult.imageSize;
		ready_to_save = true;

		// 生成中文标定报告
		QString report;
		report.append(QStringLiteral("========== 单目标定报告 ==========\n"));
		report.append(QStringLiteral("RMS: %1\n").arg(m_calibResult.rms, 0, 'f', 4));
		report.append(QStringLiteral("平均重投影误差: %1\n").arg(m_calibResult.avgReprojErr, 0, 'f', 4));
		report.append(QStringLiteral("有效视图数: %1 / %2\n").arg(m_calibResult.usedViews).arg((int)imagelistL.size()));
		report.append(QStringLiteral("逐视图误差(剔除标注为 -1):\n"));
		for (size_t i = 0; i < m_calibResult.perViewErrors.size(); ++i)
		{
			if (m_calibResult.perViewErrors[i] < 0.0f)
				report.append(QStringLiteral("视图%1: 已剔除\n").arg((int)i + 1));
			else
				report.append(QStringLiteral("视图%1: %2\n").arg((int)i + 1).arg(m_calibResult.perViewErrors[i], 0, 'f', 4));
		}
		emit reportReady(report);

		// 畸变校正预览
		cv::Mat map1, map2;
		cv::Mat newCameraMatrix = cv::getOptimalNewCameraMatrix(cameraMatrix_L, distCoeffs_L, imageSize, 1, imageSize, 0);
		cv::initUndistortRectifyMap(cameraMatrix_L, distCoeffs_L, cv::Mat(), newCameraMatrix, imageSize, CV_16SC2, map1, map2);
		for (size_t i = 0; i < imagelistL.size(); ++i)
		{
			cv::Mat view = cv::imread(imagelistL[i], cv::IMREAD_COLOR);
			if (view.empty())
				continue;
			if (view.size() != imageSize)
				continue;
			cv::Mat rview;
			cv::remap(view, rview, map1, map2, cv::INTER_LINEAR);
			m_entity->insertItem(rview);
		}
		std::cout << "单目相机矫正成功完成" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "标定出现严重错误!" << e.what() << std::endl;
		ready_to_save = false;
	}
}

/*
 * 把标定产生的参数保存到文件
 */
bool MonocularCalibrate::SaveCameraParamsToFile()
{
	if (ready_to_save == false)
	{
		std::cout << "没有准备好保存参数!" << std::endl;
		return false;
	}
	bool flag = EvisionUtils::write_MonocularCameraParams(cameraParamsFilename, cameraMatrix_L, distCoeffs_L, imageSize);
	std::cout << "参数已经保存到:" << cameraParamsFilename << std::endl;
	if (!flag)
	{
		emit openMessageBox(QStringLiteral("文件访问错误"), QStringLiteral("无法写入:cameraParams.yml"));
		return false;
	}
	return true;
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
	if (m_entity->getCALIB_RATIONAL_MODEL())
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
