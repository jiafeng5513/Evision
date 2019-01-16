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

	std::string intrFilename;
	std::string extrFilename;
	CalibrateParamEntity * m_entity;
public:
	//交错列表
	StereoCalibrate(std::vector<std::string>* imagelist,
		cv::Size boardSize,
		float squareSize,
		bool useCalibrated,
		bool showRectified,
		QObject *parent = 0);
	//两个独立列表
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

