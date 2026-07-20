#pragma once
#include <QThread>
#include <opencv2/core/mat.hpp>
#include <string>
#include <vector>
#include "MonocularCalibrateParamEntity.h"
#include "CalibrationCore.h"

class MonocularCalibrate : public QThread
{
	Q_OBJECT
private:
	std::vector<std::string> imagelistL;
	std::string cameraParamsFilename;
	MonocularCalibrateParamEntity * m_entity;
	MonoCalibResult m_calibResult;
	cv::Mat cameraMatrix_L, distCoeffs_L;
	cv::Size imageSize;
	bool ready_to_save = false;
public:
	MonocularCalibrate(const std::vector<std::string>& imagelistL, QObject *parent = nullptr);
	~MonocularCalibrate();
	void run() override;
	bool SaveCameraParamsToFile();
private:
	int getCalibrate1D_flags();
signals:
	void openMessageBox(QString, QString);
	void reportReady(QString);
};

