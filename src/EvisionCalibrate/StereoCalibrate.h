#pragma once
#include <QThread>
#include <QFileInfo>
#include <opencv2/core/mat.hpp>
#include <vector>
#include <string>
#include "CalibrationCore.h"
#include "CalibrateParamEntity.h"

class StereoCalibrate : public QThread
{
	Q_OBJECT
private:
	std::vector<std::string> imagelistL;
	std::vector<std::string> imagelistR;

	std::string cameraParamsFilename;
	CalibrateParamEntity * m_entity;

	cv::Mat cameraMatrix_L, distCoeffs_L, cameraMatrix_R, distCoeffs_R;
	cv::Mat R, T, E, F, R1, P1, R2, P2, Q;
	cv::Rect roi1, roi2;
	cv::Size imageSize;
	bool ready_to_save = false;

	MonoCalibResult resL;
	MonoCalibResult resR;
	StereoCalibResult resStereo;

	bool detectAndCollectSide(
		const std::vector<std::string>& imageList,
		const BoardConfig& cfg,
		const QString& sideName,
		std::vector<DetectionResult>& detections,
		std::vector<int>& validOrigIndices,
		std::vector<std::vector<cv::Point2f>>& imagePoints,
		std::vector<std::vector<cv::Point3f>>& objectPoints,
		int& skippedCount);

	void showUndistortedSide(const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs,
		const std::vector<std::string>& imageList);
	void showRectifiedPairs(const std::vector<std::string>& goodImageList);
	QString buildReport(int totalL, int totalR, int skippedL, int skippedR,
		const std::vector<int>& validOrigL, const std::vector<int>& validOrigR,
		const std::vector<int>& pairOrigL) const;

public:
	StereoCalibrate(const std::vector<std::string>& imagelistL,
		const std::vector<std::string>& imagelistR, QObject *parent = nullptr);
	~StereoCalibrate();
	void run() override;
	bool SaveCameraParamsToFile();

private:
	int getCalibrate1D_flags();
	int getCalibrate2D_flags();

signals:
	void openMessageBox(QString, QString);
	void reportReady(QString);
};
