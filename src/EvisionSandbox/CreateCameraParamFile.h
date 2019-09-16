#pragma once

#include <QWidget>
#include "ui_CreateCameraParamFile.h"

class CreateCameraParamFile : public QWidget
{
	Q_OBJECT

public:
	CreateCameraParamFile(QWidget *parent = Q_NULLPTR);
	~CreateCameraParamFile();

private:
	Ui::CreateCameraParamFile ui;
	bool checkpass = false;
	double fxl = 0.0;
	double fyl = 0.0;
	double cxl = 0.0;
	double cyl = 0.0;
	double fxr = 0.0;
	double fyr = 0.0;
	double cxr = 0.0;
	double cyr = 0.0;
	std::vector<double> coeffsl;
	std::vector<double> coeffsr;
	std::vector<double> rotation;
	std::vector<double> translation;
public slots:
	void onPush_check();
	void onPush_save();
};
