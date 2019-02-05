#pragma once

#include <QWidget>
#include "ui_ObjectDetectionView.h"

class ObjectDetectionView : public QWidget
{
	Q_OBJECT

public:
	ObjectDetectionView(QWidget *parent = Q_NULLPTR);
	~ObjectDetectionView();

private:
	Ui::ObjectDetectionView ui;
	QString cfgFileName = "";
	QString weightsFileName = "";
	QString nameFileNames = "";
public slots:
	void OnBrowseCfg();
	void OnBrowseWeights();
	void OnBrowseNames();
	void OnSwitch();
	
signals:
	void frameRefresh();
};
