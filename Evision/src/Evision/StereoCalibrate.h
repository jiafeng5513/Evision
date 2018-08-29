#pragma once
#include <QThread>
#include <core/mat.hpp>
#include "EvisionParamEntity.h"

class StereoCalibrate:public QThread
{
	Q_OBJECT
private:
	std::vector<std::string>* imagelist;
	std::vector<std::string>* imagelistL;
	std::vector<std::string>* imagelistR;
	cv::Size boardSize;
	float squareSize;
	bool useCalibrated; //
	bool showRectified; //是否显示标定图片的矫正结果
	EvisionParamEntity *m_entity;
public:
	StereoCalibrate(std::vector<std::string>* imagelist,
		cv::Size boardSize,
		float squareSize,
		bool useCalibrated,
		bool showRectified,
		QObject *parent = 0);
	StereoCalibrate(std::vector<std::string>* imagelistL,
		std::vector<std::string>* imagelistR,
		cv::Size boardSize,
		float squareSize,
		bool useCalibrated,
		bool showRectified,
		QObject *parent = 0);

	~StereoCalibrate();
	void run_old() ;
	void run();
signals:
	void openMessageBox(QString, QString);
};

