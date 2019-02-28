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

	std::map<QString, cv::Mat> itemMap;//存储<索引,Mat>
	int index = 0;
	enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };
	enum Pattern { CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };

public:
	StereoCalibrate(std::vector<std::string>* imagelistL,
					std::vector<std::string>* imagelistR,QObject *parent = 0);
	~StereoCalibrate();
	void run();
private:
	void insertMat(cv::Mat img);
signals:
	void openMessageBox(QString, QString);
};

