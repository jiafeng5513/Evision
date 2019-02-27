#pragma once
#include <QThread>
#include <core/mat.hpp>
#include "EvisionParamEntity.h"
#include "CalibrateParamEntity.h"

class StereoCalibrate:public QThread
{
	Q_OBJECT
private:
	std::vector<std::string>* imagelist;
	std::vector<std::string>* imagelistL;
	std::vector<std::string>* imagelistR;
	cv::Size boardSize;
	float squareSize;
	bool useCalibrated; //true=使用BOUGUET矫正方法,false=使用HARTLEY矫正方法
	bool showRectified; //是否显示标定图片的矫正结果

	std::string cameraParamsFilename;
	CalibrateParamEntity * m_entity;

	enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };
	enum Pattern { CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };

	void StereoCalib(const std::vector<std::string>& imagelist, cv::Size boardSize,float squareSize,
		bool displayCorners = false,bool useCalibrated = true,bool showRectified = true);

	double computeReprojectionErrors(
		const std::vector<std::vector<cv::Point3f> >& objectPoints,
		const std::vector<std::vector<cv::Point2f> >& imagePoints,
		const std::vector<cv::Mat>& rvecs, const std::vector<cv::Mat>& tvecs,
		const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs,
		std::vector<float>& perViewErrors);

	void calcChessboardCorners(cv::Size boardSize, float squareSize, std::vector<cv::Point3f>& corners, Pattern patternType = CHESSBOARD);

	bool calibrate_1D_core(const std::vector<std::vector< cv::Point2f> >& imagePoints,
		cv::Size imageSize, cv::Size boardSize, Pattern patternType, float squareSize,
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
public:
	StereoCalibrate(std::vector<std::string>* imagelistL,
		std::vector<std::string>* imagelistR,
		cv::Size boardSize,
		float squareSize,
		bool useCalibrated,
		bool showRectified,
		QObject *parent = 0);
	void UseCalib();
	~StereoCalibrate();
	void run_old() ;
	void run();
signals:
	void openMessageBox(QString, QString);
};

