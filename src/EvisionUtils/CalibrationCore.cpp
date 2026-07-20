#include "CalibrationCore.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <utility>

namespace
{
	/*
	 * 根据标定板配置生成三维角点坐标.
	 */
	void calcObjectPoints(const BoardConfig& cfg, std::vector<cv::Point3f>& corners)
	{
		corners.clear();
		switch (cfg.type)
		{
		case BoardType::Chessboard:
		case BoardType::CirclesGrid:
			for (int i = 0; i < cfg.boardSize.height; ++i)
				for (int j = 0; j < cfg.boardSize.width; ++j)
					corners.push_back(cv::Point3f(float(j * cfg.squareSize),
						float(i * cfg.squareSize), 0.f));
			break;

		case BoardType::AsymmetricCirclesGrid:
			for (int i = 0; i < cfg.boardSize.height; ++i)
				for (int j = 0; j < cfg.boardSize.width; ++j)
					corners.push_back(cv::Point3f(float((2 * j + i % 2) * cfg.squareSize),
						float(i * cfg.squareSize), 0.f));
			break;

		default:
			break;
		}
	}
}

/*
 * 在单张图像中检测标定板.
 */
DetectionResult CalibrationCore::detectBoard(const cv::Mat& image, const BoardConfig& cfg)
{
	DetectionResult result;
	try
	{
		if (image.empty())
			return result;

		cv::Mat gray;
		if (image.channels() == 1)
			gray = image;
		else
			cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

		switch (cfg.type)
		{
		case BoardType::Chessboard:
		{
			std::vector<cv::Point2f> corners;
			bool found = cv::findChessboardCornersSB(gray, cfg.boardSize, corners,
				cv::CALIB_CB_NORMALIZE_IMAGE);
			if (!found)
			{
				found = cv::findChessboardCorners(gray, cfg.boardSize, corners,
					cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_NORMALIZE_IMAGE);
				if (found)
				{
					cv::cornerSubPix(gray, corners, cv::Size(11, 11), cv::Size(-1, -1),
						cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01));
				}
			}
			if (found)
			{
				result.found = true;
				result.corners = std::move(corners);
				calcObjectPoints(cfg, result.objects);
			}
			break;
		}

		case BoardType::CirclesGrid:
		case BoardType::AsymmetricCirclesGrid:
		{
			int flags = (cfg.type == BoardType::AsymmetricCirclesGrid) ? cv::CALIB_CB_ASYMMETRIC_GRID : 0;
			bool found = cv::findCirclesGrid(gray, cfg.boardSize, result.corners, flags);
			if (found)
			{
				result.found = true;
				calcObjectPoints(cfg, result.objects);
			}
			break;
		}

		case BoardType::Charuco:
		{
			cv::aruco::CharucoBoard board(cfg.boardSize, cfg.squareSize, cfg.markerSize,
				cv::aruco::getPredefinedDictionary(cfg.dictionaryId));
			cv::aruco::CharucoDetector detector(board);
			std::vector<cv::Point2f> charucoCorners;
			std::vector<int> charucoIds;
			detector.detectBoard(gray, charucoCorners, charucoIds);
			if (!charucoCorners.empty() && charucoCorners.size() == charucoIds.size())
			{
				const std::vector<cv::Point3f>& allObjPoints = board.getChessboardCorners();
				result.found = true;
				result.corners.reserve(charucoIds.size());
				result.objects.reserve(charucoIds.size());
				for (size_t i = 0; i < charucoIds.size(); ++i)
				{
					int id = charucoIds[i];
					if (id >= 0 && id < (int)allObjPoints.size())
					{
						result.corners.push_back(charucoCorners[i]);
						result.objects.push_back(allObjPoints[id]);
					}
				}
				if (result.corners.empty())
					result.found = false;
			}
			break;
		}

		default:
			break;
		}
	}
	catch (const cv::Exception&)
	{
		result.found = false;
	}
	return result;
}

/*
 * 在图像副本上绘制检测结果并返回.
 */
cv::Mat CalibrationCore::drawDetection(cv::Mat image, const BoardConfig& cfg, const DetectionResult& det)
{
	cv::Mat out = image.clone();
	if (!det.found || out.empty())
		return out;

	try
	{
		switch (cfg.type)
		{
		case BoardType::Chessboard:
		case BoardType::CirclesGrid:
		case BoardType::AsymmetricCirclesGrid:
			cv::drawChessboardCorners(out, cfg.boardSize, cv::Mat(det.corners), det.found);
			break;

		case BoardType::Charuco:
			for (const auto& pt : det.corners)
			{
				cv::circle(out, pt, 4, cv::Scalar(0, 0, 255), -1);
				cv::circle(out, pt, 6, cv::Scalar(0, 255, 0), 1);
			}
			break;

		default:
			break;
		}
	}
	catch (const cv::Exception&)
	{
		// 绘制失败时返回原图副本
	}
	return out;
}

/*
 * 计算重投影误差.
 */
double CalibrationCore::computeReprojectionErrors(
	const std::vector<std::vector<cv::Point3f>>& objectPoints,
	const std::vector<std::vector<cv::Point2f>>& imagePoints,
	const std::vector<cv::Mat>& rvecs,
	const std::vector<cv::Mat>& tvecs,
	const cv::Mat& cameraMatrix,
	const cv::Mat& distCoeffs,
	std::vector<float>& perViewErrors)
{
	std::vector<cv::Point2f> imagePoints2;
	int totalPoints = 0;
	double totalErr = 0.0;
	perViewErrors.resize(objectPoints.size());

	for (size_t i = 0; i < objectPoints.size(); ++i)
	{
		cv::projectPoints(cv::Mat(objectPoints[i]), rvecs[i], tvecs[i],
			cameraMatrix, distCoeffs, imagePoints2);
		double err = cv::norm(cv::Mat(imagePoints[i]), cv::Mat(imagePoints2), cv::NORM_L2);
		int n = (int)objectPoints[i].size();
		perViewErrors[i] = (float)std::sqrt(err * err / n);
		totalErr += err * err;
		totalPoints += n;
	}

	return totalPoints > 0 ? std::sqrt(totalErr / totalPoints) : 0.0;
}

/*
 * 单目标定核心.
 */
MonoCalibResult CalibrationCore::calibrateMonocular(
	const std::vector<std::vector<cv::Point2f>>& imagePoints,
	const std::vector<std::vector<cv::Point3f>>& objectPoints,
	cv::Size imageSize,
	int flags,
	float aspectRatio,
	double outlierPx,
	int maxOutlierIters)
{
	MonoCalibResult result;
	if (imagePoints.size() < 3 || imagePoints.size() != objectPoints.size())
		return result;

	for (const auto& pts : imagePoints)
	{
		if (pts.size() < 4)
			return result;
	}

	try
	{
		std::vector<int> active(imagePoints.size());
		for (size_t i = 0; i < active.size(); ++i)
			active[i] = (int)i;

		cv::Mat cameraMatrix, distCoeffs;
		std::vector<cv::Mat> rvecs, tvecs;
		std::vector<float> activeErrors;
		std::vector<int> excluded;
		double finalRms = 0.0;
		double finalAvgErr = 0.0;

		for (int iter = 0; iter <= maxOutlierIters; ++iter)
		{
			std::vector<std::vector<cv::Point2f>> activeImgPts;
			std::vector<std::vector<cv::Point3f>> activeObjPts;
			activeImgPts.reserve(active.size());
			activeObjPts.reserve(active.size());
			for (int idx : active)
			{
				activeImgPts.push_back(imagePoints[idx]);
				activeObjPts.push_back(objectPoints[idx]);
			}

			cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
			if (flags & cv::CALIB_FIX_ASPECT_RATIO)
				cameraMatrix.at<double>(0, 0) = aspectRatio;
			distCoeffs = cv::Mat::zeros(8, 1, CV_64F);

			finalRms = cv::calibrateCamera(activeObjPts, activeImgPts, imageSize,
				cameraMatrix, distCoeffs, rvecs, tvecs, flags);
			finalAvgErr = computeReprojectionErrors(activeObjPts, activeImgPts,
				rvecs, tvecs, cameraMatrix, distCoeffs, activeErrors);

			if (iter == maxOutlierIters)
				break;

			std::vector<float> sorted = activeErrors;
			std::sort(sorted.begin(), sorted.end());
			double median = 0.0;
			if (!sorted.empty())
			{
				if (sorted.size() % 2 == 0)
					median = (sorted[sorted.size() / 2 - 1] + sorted[sorted.size() / 2]) * 0.5;
				else
					median = sorted[sorted.size() / 2];
			}
			double threshold = std::max(outlierPx, 2.0 * median);

			std::vector<int> newActive;
			for (size_t i = 0; i < activeErrors.size(); ++i)
			{
				if (activeErrors[i] <= threshold)
					newActive.push_back(active[i]);
			}

			if (newActive.size() == active.size() || newActive.size() < 3)
				break;

			for (int idx : active)
			{
				if (std::find(newActive.begin(), newActive.end(), idx) == newActive.end())
					excluded.push_back(idx);
			}
			active.swap(newActive);
		}

		result.ok = cv::checkRange(cameraMatrix) && cv::checkRange(distCoeffs);
		result.cameraMatrix = cameraMatrix;
		result.distCoeffs = distCoeffs;
		result.imageSize = imageSize;
		result.usedViews = (int)active.size();
		result.excludedViews = std::move(excluded);
		result.rms = finalRms;
		result.avgReprojErr = finalAvgErr;
		result.perViewErrors.resize(imagePoints.size(), -1.0f);
		for (size_t i = 0; i < active.size(); ++i)
			result.perViewErrors[active[i]] = activeErrors[i];
	}
	catch (const cv::Exception&)
	{
		result.ok = false;
	}
	return result;
}

/*
 * 匹配左右视图检测结果的公共子集.
 */
StereoPairDetection CalibrationCore::matchStereoPair(
	const DetectionResult& detL,
	const DetectionResult& detR,
	const BoardConfig& cfg)
{
	StereoPairDetection result;
	if (!detL.found || !detR.found)
		return result;

	try
	{
		if (cfg.type == BoardType::Charuco)
		{
			for (size_t i = 0; i < detL.objects.size(); ++i)
			{
				for (size_t j = 0; j < detR.objects.size(); ++j)
				{
					if (detL.objects[i] == detR.objects[j])
					{
						result.cornersL.push_back(detL.corners[i]);
						result.cornersR.push_back(detR.corners[j]);
						result.objects.push_back(detL.objects[i]);
						break;
					}
				}
			}
			result.ok = result.objects.size() >= 8;
		}
		else
		{
			if (detL.corners.size() != detR.corners.size() || detL.objects.empty())
				return result;
			result.cornersL = detL.corners;
			result.cornersR = detR.corners;
			result.objects = detL.objects;
			result.ok = true;
		}
	}
	catch (const cv::Exception&)
	{
		result.ok = false;
	}
	return result;
}

/*
 * 双目标定核心.
 */
StereoCalibResult CalibrationCore::calibrateStereo(
	const std::vector<std::vector<cv::Point2f>>& imagePointsL,
	const std::vector<std::vector<cv::Point2f>>& imagePointsR,
	const std::vector<std::vector<cv::Point3f>>& objectPoints,
	cv::Size imageSize,
	cv::Mat& cameraMatrix_L,
	cv::Mat& distCoeffs_L,
	cv::Mat& cameraMatrix_R,
	cv::Mat& distCoeffs_R,
	int flags)
{
	StereoCalibResult result;
	if (imagePointsL.size() < 2 ||
		imagePointsL.size() != imagePointsR.size() ||
		imagePointsL.size() != objectPoints.size())
		return result;

	try
	{
		double rms = cv::stereoCalibrate(objectPoints, imagePointsL, imagePointsR,
			cameraMatrix_L, distCoeffs_L, cameraMatrix_R, distCoeffs_R,
			imageSize, result.R, result.T, result.E, result.F,
			flags,
			cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, 1e-5));
		result.rms = rms;

		// 计算平均极线误差
		double err = 0.0;
		int npoints = 0;
		std::vector<cv::Vec3f> lines[2];
		for (size_t i = 0; i < imagePointsL.size(); ++i)
		{
			int npt = (int)imagePointsL[i].size();
			cv::Mat imgpt[2];

			imgpt[0] = cv::Mat(imagePointsL[i]);
			cv::undistortPoints(imgpt[0], imgpt[0], cameraMatrix_L, distCoeffs_L, cv::Mat(), cameraMatrix_L);
			cv::computeCorrespondEpilines(imgpt[0], 1, result.F, lines[0]);

			imgpt[1] = cv::Mat(imagePointsR[i]);
			cv::undistortPoints(imgpt[1], imgpt[1], cameraMatrix_R, distCoeffs_R, cv::Mat(), cameraMatrix_R);
			cv::computeCorrespondEpilines(imgpt[1], 2, result.F, lines[1]);

			for (int j = 0; j < npt; ++j)
			{
				double errij = std::fabs(imagePointsL[i][j].x * lines[1][j][0] +
					imagePointsL[i][j].y * lines[1][j][1] + lines[1][j][2]) +
					std::fabs(imagePointsR[i][j].x * lines[0][j][0] +
						imagePointsR[i][j].y * lines[0][j][1] + lines[0][j][2]);
				err += errij;
			}
			npoints += npt;
		}
		result.avgEpipolarErr = npoints > 0 ? err / npoints : 0.0;

		// 立体校正
		cv::stereoRectify(cameraMatrix_L, distCoeffs_L,
			cameraMatrix_R, distCoeffs_R,
			imageSize, result.R, result.T,
			result.R1, result.R2, result.P1, result.P2, result.Q,
			0, 1, imageSize, &result.roi1, &result.roi2);

		// 左相机逐视图重投影误差
		std::vector<cv::Mat> rvecs, tvecs;
		cv::calibrateCamera(objectPoints, imagePointsL, imageSize,
			cameraMatrix_L, distCoeffs_L, rvecs, tvecs, cv::CALIB_FIX_INTRINSIC);
		computeReprojectionErrors(objectPoints, imagePointsL, rvecs, tvecs,
			cameraMatrix_L, distCoeffs_L, result.perViewErrors);

		result.imageSize = imageSize;
		result.ok = true;
	}
	catch (const cv::Exception&)
	{
		result.ok = false;
	}
	return result;
}
