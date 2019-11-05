#pragma once

#include <QtCore/qglobal.h>
#include <string>
#include <QWidget>
#include "opencv2/opencv.hpp"
#ifndef BUILD_STATIC
# if defined( EVISIONCLOUDVIEWERFACTORY_LIB)
#  define  EVISIONCLOUDVIEWERFACTORY_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONCLOUDVIEWERFACTORY_EXPORT Q_DECL_IMPORT
# endif
#else
# define EVISIONCLOUDVIEWERFACTORY_EXPORT
#endif
class EVISIONCLOUDVIEWERFACTORY_EXPORT EvisionCloudViewerFactory
{
public:
	EvisionCloudViewerFactory();
	static QWidget* CreateEvisionEvisionCloudViewer(std::string filename,QWidget *parent = Q_NULLPTR);
	static void createAndSavePointCloud(cv::Mat &disparity, cv::Mat &leftImage, cv::Mat &Q, std::string filename);
};
