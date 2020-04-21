#pragma once

#include <QWidget>
#include <QImage>
#include "ui_ObjectDetectionView.h"
#include "ObjectDetectionEntity.h"
#include "ObjectDetectionEngine.h"

class ObjectDetectionView : public QWidget
{
	Q_OBJECT

public:
	ObjectDetectionView(QWidget *parent = Q_NULLPTR);
	~ObjectDetectionView();

private:
	Ui::ObjectDetectionView ui;
	ObjectDetectionEntity * m_entity;
	ObjectDetectionEngine * m_engine;
	QImage _cvMat2QImage(const cv::Mat& mat);
public slots:
	void OnBrowseCfg();
	void OnBrowseWeights();
	void OnBrowseNames();
	void OnSwitch();

	void OnParamChanged_DetectionPlayer();
	void OnParamChanged_cfgFilename();
	void OnParamChanged_weightsFilename();
	void OnParamChanged_namesFilename();
};
