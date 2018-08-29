#pragma once
#include <QThread>
#include <core/mat.hpp>
#include "EvisionParamEntity.h"

class StereoCalibrate:public QThread
{
private:
	std::vector<std::string>* imagelist;
	cv::Size boardSize;
	float squareSize;
	bool displayCorners;
	bool useCalibrated;
	bool showRectified;
	EvisionParamEntity *m_entity;
public:
	StereoCalibrate(std::vector<std::string>* imagelist,
		cv::Size boardSize,
		float squareSize,
		bool displayCorners,
		bool useCalibrated,
		bool showRectified,
		QObject *parent = 0);
	~StereoCalibrate();
	void run() ;
};

