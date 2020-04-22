#pragma once
#include <QThread>
#include <opencv2/core/mat.hpp>
#include "CalibrateParamEntity.h"

class StereoCalibrate:public QThread
{
	Q_OBJECT
private:
	std::vector<std::string>* imagelistL;
	std::vector<std::string>* imagelistR;

	std::string cameraParamsFilename;
	CalibrateParamEntity * m_entity;


	enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };
	enum Pattern { CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };
	cv::Mat cameraMatrix_L, distCoeffs_L, cameraMatrix_R, distCoeffs_R;
	cv::Mat R, T, E, F, R1, P1, R2, P2, Q;
	cv::Rect roi1, roi2;
	cv::Size imageSize;
	bool ready_to_save = false;
public:
	StereoCalibrate(std::vector<std::string>* imagelistL,
					std::vector<std::string>* imagelistR,QObject *parent = 0);
	~StereoCalibrate();
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
	void StereoCalib(const std::vector<std::string>& imagelist,
		cv::Size boardSize,
		float squareSize,
		cv::Mat &cameraMatrix_L,cv::Mat &distCoeffs_L,
		cv::Mat &cameraMatrix_R,cv::Mat &distCoeffs_R,
		cv::Mat& R, cv::Mat& T, cv::Mat& E, cv::Mat&F, cv::Mat& R1, cv::Mat& P1, cv::Mat&R2, cv::Mat&P2, cv::Mat&Q,
		cv::Rect &roi1, cv::Rect &roi2,
		int flags,
		bool displayCorners = false,
		bool useCalibrated = true,
		bool showRectified = true);
	int getCalibrate1D_flags();
	int getCalibrate2D_flags();
signals:
	void openMessageBox(QString, QString);
};

