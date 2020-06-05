#pragma once
#include <QThread>
#include <opencv2/core/mat.hpp>
#include "MonocularCalibrateParamEntity.h"

class MonocularCalibrate:public QThread
{
	Q_OBJECT
private:
	std::vector<std::string>* imagelistL;
	std::string cameraParamsFilename;
	MonocularCalibrateParamEntity * m_entity;


	enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };
	enum Pattern { CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };
	cv::Mat cameraMatrix_L, distCoeffs_L;
	cv::Size imageSize;
	bool ready_to_save = false;
public:
	MonocularCalibrate(std::vector<std::string>* imagelistL, QObject *parent = 0);
	~MonocularCalibrate();
	void run()override;
	bool SaveCameraParamsToFile();
private:
	double computeReprojectionErrors(
		const std::vector<std::vector<cv::Point3f> >& objectPoints,
		const std::vector<std::vector<cv::Point2f> >& imagePoints,
		const std::vector<cv::Mat>& rvecs, const std::vector<cv::Mat>& tvecs,
		const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs,
		std::vector<float>& perViewErrors);
	void calcChessboardCorners(cv::Size boardSize, float squareSize, std::vector<cv::Point3f>& corners, Pattern patternType = CHESSBOARD);
	bool calibrate_1D_core(const std::vector<std::vector< cv::Point2f> >& imagePoints,
		cv::Size imageSize, cv::Size boardSize, float squareSize,
		float aspectRatio, int flags, cv::Mat& cameraMatrix,
		cv::Mat& distCoeffs);
	void Calib1D(cv::Size boardSize,
		float squareSize,
		std::vector<std::string> imageList,
		cv::Mat& cameraMatrix,
		cv::Mat& distCoeffs,
		float aspectRatio = 1,
		Pattern pattern = CHESSBOARD,
		int flags = 0,
		bool showUndistorted = true);
	int getCalibrate1D_flags();
signals:
	void openMessageBox(QString, QString);
};

