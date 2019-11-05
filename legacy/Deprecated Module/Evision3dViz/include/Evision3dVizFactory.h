#pragma once

#include <QtWidgets/QWidget>
#include "opencv2/opencv.hpp"

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EVISION3DVIZ_LIB)
#  define EVISION3DVIZ_EXPORT Q_DECL_EXPORT
# else
#  define EVISION3DVIZ_EXPORT Q_DECL_IMPORT
# endif
#else
# define EVISION3DVIZ_EXPORT
#endif

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

