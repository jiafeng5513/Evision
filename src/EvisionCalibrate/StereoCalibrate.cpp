#include "StereoCalibrate.h"
#include <QFileInfo>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "EvisionUtils.h"
#include "CalibrationCore.h"

StereoCalibrate::StereoCalibrate(const std::vector<std::string>& imagelistL,
	const std::vector<std::string>& imagelistR, QObject * parent)
	: QThread(parent), imagelistL(imagelistL), imagelistR(imagelistR)
{
	m_entity = CalibrateParamEntity::getInstance();
	if (!this->imagelistL.empty())
	{
		QFileInfo fileInfo(QString::fromStdString(this->imagelistL[0]));
		this->cameraParamsFilename = fileInfo.absolutePath().toStdString().append("/cameraParams.yml");
	}
	else
	{
		this->cameraParamsFilename = std::string("cameraParams.yml");
	}
}

StereoCalibrate::~StereoCalibrate()
{
}

/*
 * 线程方法
 */
void StereoCalibrate::run()
{
	ready_to_save = false;
	if (imagelistL.size() != imagelistR.size())
	{
		emit openMessageBox(QStringLiteral("错误"), QStringLiteral("图片不成对!"));
		return;
	}

	try
	{
		BoardConfig cfg;
		switch (m_entity->getBoardTypeIndex())
		{
		case 0:
		default:
			cfg.type = BoardType::Chessboard;
			break;
		case 1:
			cfg.type = BoardType::CirclesGrid;
			break;
		case 2:
			cfg.type = BoardType::AsymmetricCirclesGrid;
			break;
		case 3:
			cfg.type = BoardType::Charuco;
			break;
		}
		cfg.boardSize = cv::Size(m_entity->getBoardWidth(), m_entity->getBoardHeight());
		cfg.squareSize = static_cast<float>(m_entity->getSquareSize());
		cfg.markerSize = m_entity->getMarkerSize();
		// dictionaryId 使用默认值

		int flags_1D = getCalibrate1D_flags();
		int flags_2D = getCalibrate2D_flags();

		imageSize = cv::Size();
		std::vector<DetectionResult> detsL(imagelistL.size());
		std::vector<DetectionResult> detsR(imagelistR.size());
		std::vector<int> validOrigL, validOrigR;
		std::vector<std::vector<cv::Point2f>> imgPtsL, imgPtsR;
		std::vector<std::vector<cv::Point3f>> objPtsL, objPtsR;
		int skippedL = 0, skippedR = 0;

		std::cout << "检测左相机标定板" << std::endl;
		if (!detectAndCollectSide(imagelistL, cfg, QStringLiteral("左"),
			detsL, validOrigL, imgPtsL, objPtsL, skippedL))
		{
			return;
		}
		std::cout << "检测右相机标定板" << std::endl;
		if (!detectAndCollectSide(imagelistR, cfg, QStringLiteral("右"),
			detsR, validOrigR, imgPtsR, objPtsR, skippedR))
		{
			return;
		}

		if (imgPtsL.size() < 3)
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("左相机有效视图不足"));
			return;
		}
		if (imgPtsR.size() < 3)
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("右相机有效视图不足"));
			return;
		}

		std::cout << "标定左相机" << std::endl;
		resL = CalibrationCore::calibrateMonocular(imgPtsL, objPtsL, imageSize, flags_1D, 1.f);
		std::cout << "标定右相机" << std::endl;
		resR = CalibrationCore::calibrateMonocular(imgPtsR, objPtsR, imageSize, flags_1D, 1.f);
		if (!resL.ok || !resR.ok)
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("单目标定失败"));
			return;
		}
		cameraMatrix_L = resL.cameraMatrix;
		distCoeffs_L = resL.distCoeffs;
		cameraMatrix_R = resR.cameraMatrix;
		distCoeffs_R = resR.distCoeffs;

		std::cout << "匹配立体图像对" << std::endl;
		std::vector<std::string> goodImageList;
		std::vector<std::vector<cv::Point2f>> pairCornersL, pairCornersR;
		std::vector<std::vector<cv::Point3f>> pairObjects;
		std::vector<int> pairOrigL;
		for (size_t i = 0; i < imagelistL.size(); ++i)
		{
			if (detsL[i].found && detsR[i].found)
			{
				StereoPairDetection pair = CalibrationCore::matchStereoPair(detsL[i], detsR[i], cfg);
				if (pair.ok)
				{
					pairCornersL.push_back(pair.cornersL);
					pairCornersR.push_back(pair.cornersR);
					pairObjects.push_back(pair.objects);
					pairOrigL.push_back((int)i);
					goodImageList.push_back(imagelistL[i]);
					goodImageList.push_back(imagelistR[i]);
				}
			}
		}
		if (pairCornersL.size() < 2)
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("有效立体视图对不足"));
			return;
		}

		std::cout << "标定双目系统" << std::endl;
		cv::Mat m1 = resL.cameraMatrix;
		cv::Mat d1 = resL.distCoeffs;
		cv::Mat m2 = resR.cameraMatrix;
		cv::Mat d2 = resR.distCoeffs;
		resStereo = CalibrationCore::calibrateStereo(pairCornersL, pairCornersR, pairObjects,
			imageSize, m1, d1, m2, d2, flags_2D);
		if (!resStereo.ok)
		{
			emit openMessageBox(QStringLiteral("错误"), QStringLiteral("双目标定失败"));
			return;
		}
		R = resStereo.R;
		T = resStereo.T;
		E = resStereo.E;
		F = resStereo.F;
		R1 = resStereo.R1;
		P1 = resStereo.P1;
		R2 = resStereo.R2;
		P2 = resStereo.P2;
		Q = resStereo.Q;
		roi1 = resStereo.roi1;
		roi2 = resStereo.roi2;
		imageSize = resStereo.imageSize;

		std::cout << "生成单目畸变校正图像" << std::endl;
		showUndistortedSide(cameraMatrix_L, distCoeffs_L, imagelistL);
		showUndistortedSide(cameraMatrix_R, distCoeffs_R, imagelistR);

		std::cout << "生成立体校正图像" << std::endl;
		showRectifiedPairs(goodImageList);

		ready_to_save = true;

		QString report = buildReport((int)imagelistL.size(), (int)imagelistR.size(),
			skippedL, skippedR, validOrigL, validOrigR, pairOrigL);
		emit reportReady(report);
	}
	catch (const std::exception& e)
	{
		std::cout << "标定出现严重错误!" << e.what() << std::endl;
	}
}

/*
 * 把标定产生的参数保存到文件
 */
bool StereoCalibrate::SaveCameraParamsToFile()
{
	if (ready_to_save == false)
	{
		std::cout << "没有准备好保存参数!" << std::endl;
		return false;
	}
	else
	{
		bool flag = EvisionUtils::write_AllCameraParams(cameraParamsFilename, cameraMatrix_L, distCoeffs_L,
			cameraMatrix_R, distCoeffs_R, R, T, imageSize, R1, P1, R2, P2, Q, roi1, roi2);
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
 * 检测单侧相机的所有视图并收集有效角点
 */
bool StereoCalibrate::detectAndCollectSide(
	const std::vector<std::string>& imageList,
	const BoardConfig& cfg,
	const QString& sideName,
	std::vector<DetectionResult>& detections,
	std::vector<int>& validOrigIndices,
	std::vector<std::vector<cv::Point2f>>& imagePoints,
	std::vector<std::vector<cv::Point3f>>& objectPoints,
	int& skippedCount)
{
	for (size_t idx = 0; idx < imageList.size(); ++idx)
	{
		cv::Mat view = cv::imread(imageList[idx], cv::IMREAD_COLOR);
		if (view.empty())
		{
			++skippedCount;
			m_entity->insertItem(view);
			continue;
		}
		if (imageSize == cv::Size())
		{
			imageSize = view.size();
		}
		else if (view.size() != imageSize)
		{
			++skippedCount;
			m_entity->insertItem(view);
			continue;
		}

		DetectionResult det = CalibrationCore::detectBoard(view, cfg);
		detections[idx] = det;
		if (det.found)
		{
			cv::Mat annotated = CalibrationCore::drawDetection(view, cfg, det);
			m_entity->insertItem(annotated);
			imagePoints.push_back(det.corners);
			objectPoints.push_back(det.objects);
			validOrigIndices.push_back((int)idx);
		}
		else
		{
			m_entity->insertItem(view);
		}
	}
	return true;
}

/*
 * 显示单目畸变校正结果
 */
void StereoCalibrate::showUndistortedSide(const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs,
	const std::vector<std::string>& imageList)
{
	if (imageSize.width <= 0 || imageSize.height <= 0)
		return;

	cv::Mat map1, map2;
	cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::Mat(),
		cv::getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
		imageSize, CV_16SC2, map1, map2);

	for (size_t i = 0; i < imageList.size(); ++i)
	{
		cv::Mat view = cv::imread(imageList[i], cv::IMREAD_COLOR);
		if (view.empty())
			continue;
		cv::Mat rview;
		cv::remap(view, rview, map1, map2, cv::INTER_LINEAR);
		m_entity->insertItem(rview);
	}
}

/*
 * 显示立体校正后的图像对(含极线与ROI)
 */
void StereoCalibrate::showRectifiedPairs(const std::vector<std::string>& goodImageList)
{
	if (goodImageList.size() % 2 != 0 || imageSize.width <= 0 || imageSize.height <= 0)
		return;

	cv::Mat rmap[2][2];
	cv::initUndistortRectifyMap(cameraMatrix_L, distCoeffs_L, R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);
	cv::initUndistortRectifyMap(cameraMatrix_R, distCoeffs_R, R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);

	bool isVerticalStereo = std::fabs(P2.at<double>(1, 3)) > std::fabs(P2.at<double>(0, 3));
	cv::Mat canvas;
	double sf = 0.0;
	int w = 0, h = 0;
	if (!isVerticalStereo)
	{
		sf = 600.0 / std::max(imageSize.width, imageSize.height);
		w = cvRound(imageSize.width * sf);
		h = cvRound(imageSize.height * sf);
		canvas.create(h, w * 2, CV_8UC3);
	}
	else
	{
		sf = 300.0 / std::max(imageSize.width, imageSize.height);
		w = cvRound(imageSize.width * sf);
		h = cvRound(imageSize.height * sf);
		canvas.create(h * 2, w, CV_8UC3);
	}

	int nimages = (int)goodImageList.size() / 2;
	for (int i = 0; i < nimages; ++i)
	{
		for (int k = 0; k < 2; ++k)
		{
			cv::Mat img = cv::imread(goodImageList[i * 2 + k], cv::IMREAD_GRAYSCALE);
			if (img.empty())
				continue;
			cv::Mat rimg, cimg;
			cv::remap(img, rimg, rmap[k][0], rmap[k][1], cv::INTER_LINEAR);
			cv::cvtColor(rimg, cimg, cv::COLOR_GRAY2BGR);
			cv::Mat canvasPart = !isVerticalStereo
				? canvas(cv::Rect(w * k, 0, w, h))
				: canvas(cv::Rect(0, h * k, w, h));
			cv::resize(cimg, canvasPart, canvasPart.size(), 0, 0, cv::INTER_AREA);

			cv::Rect validRoi = (k == 0) ? roi1 : roi2;
			cv::Rect vroi(cvRound(validRoi.x * sf), cvRound(validRoi.y * sf),
				cvRound(validRoi.width * sf), cvRound(validRoi.height * sf));
			cv::rectangle(canvasPart, vroi, cv::Scalar(0, 0, 255), 3, 8);
		}

		if (!isVerticalStereo)
		{
			for (int j = 0; j < canvas.rows; j += 16)
				cv::line(canvas, cv::Point(0, j), cv::Point(canvas.cols, j), cv::Scalar(0, 255, 0), 1, 8);
		}
		else
		{
			for (int j = 0; j < canvas.cols; j += 16)
				cv::line(canvas, cv::Point(j, 0), cv::Point(j, canvas.rows), cv::Scalar(0, 255, 0), 1, 8);
		}
		m_entity->insertItem(canvas);
	}
}

/*
 * 格式化标定报告
 */
QString StereoCalibrate::buildReport(int totalL, int totalR, int skippedL, int skippedR,
	const std::vector<int>& validOrigL, const std::vector<int>& validOrigR,
	const std::vector<int>& pairOrigL) const
{
	std::vector<float> leftErr(totalL, -1.f);
	for (size_t i = 0; i < validOrigL.size(); ++i)
	{
		if (validOrigL[i] >= 0 && validOrigL[i] < totalL)
			leftErr[validOrigL[i]] = resL.perViewErrors[i];
	}

	std::vector<float> rightErr(totalR, -1.f);
	for (size_t i = 0; i < validOrigR.size(); ++i)
	{
		if (validOrigR[i] >= 0 && validOrigR[i] < totalR)
			rightErr[validOrigR[i]] = resR.perViewErrors[i];
	}

	std::vector<float> stereoErr(totalL, -1.f);
	for (size_t i = 0; i < pairOrigL.size(); ++i)
	{
		if (pairOrigL[i] >= 0 && pairOrigL[i] < totalL)
			stereoErr[pairOrigL[i]] = resStereo.perViewErrors[i];
	}

	QString report = QStringLiteral("==== 标定报告 ====\n");
	report += QStringLiteral("左相机单目标定 RMS: %1, 平均重投影误差: %2, 有效视图: %3/%4, 跳过: %5\n")
		.arg(resL.rms, 0, 'f', 4).arg(resL.avgReprojErr, 0, 'f', 4)
		.arg(resL.usedViews).arg(totalL).arg(skippedL);
	report += QStringLiteral("左相机逐视图重投影误差:\n");
	for (int i = 0; i < totalL; ++i)
	{
		report += QStringLiteral("  视图%1: ").arg(i);
		report += (leftErr[i] < 0.f) ? QStringLiteral("剔除\n") : QStringLiteral("%1\n").arg(leftErr[i], 0, 'f', 4);
	}

	report += QStringLiteral("右相机单目标定 RMS: %1, 平均重投影误差: %2, 有效视图: %3/%4, 跳过: %5\n")
		.arg(resR.rms, 0, 'f', 4).arg(resR.avgReprojErr, 0, 'f', 4)
		.arg(resR.usedViews).arg(totalR).arg(skippedR);
	report += QStringLiteral("右相机逐视图重投影误差:\n");
	for (int i = 0; i < totalR; ++i)
	{
		report += QStringLiteral("  视图%1: ").arg(i);
		report += (rightErr[i] < 0.f) ? QStringLiteral("剔除\n") : QStringLiteral("%1\n").arg(rightErr[i], 0, 'f', 4);
	}

	report += QStringLiteral("双目标定 RMS: %1, 平均极线误差: %2, 有效立体对: %3\n")
		.arg(resStereo.rms, 0, 'f', 4).arg(resStereo.avgEpipolarErr, 0, 'f', 4)
		.arg((int)pairOrigL.size());
	report += QStringLiteral("左相机逐视图重投影误差(基于立体对):\n");
	for (int i = 0; i < totalL; ++i)
	{
		report += QStringLiteral("  视图%1: ").arg(i);
		report += (stereoErr[i] < 0.f) ? QStringLiteral("剔除\n") : QStringLiteral("%1\n").arg(stereoErr[i], 0, 'f', 4);
	}
	return report;
}

/*
 * 获取单目标定的flags
 */
int StereoCalibrate::getCalibrate1D_flags()
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

/*
 * 获取立体标定的flags
 */
int StereoCalibrate::getCalibrate2D_flags()
{
	int flag = 0 | cv::CALIB_FIX_INTRINSIC;
	if (m_entity->getCALIB_SAME_FOCAL_LENGTH())
	{
		flag |= cv::CALIB_SAME_FOCAL_LENGTH;
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
