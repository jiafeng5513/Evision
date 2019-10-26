#pragma once
#include "evision3dviz_global.h"
#include <QtWidgets/QWidget>
#include "opencv2/opencv.hpp"
class Evision3dViz;//Ç°ÏòÉùÃ÷

class EVISION3DVIZ_EXPORT Evision3dVizFactory : public QWidget
{
	Q_OBJECT
public:
	Evision3dVizFactory();
	~Evision3dVizFactory();
	static QWidget* CreateEvision3dViz(QWidget *parent = Q_NULLPTR);
	static void createAndSavePointCloud(cv::Mat &disparity, cv::Mat &leftImage, cv::Mat &Q, std::string filename);
};

