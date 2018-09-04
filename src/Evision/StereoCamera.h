#pragma once

#include <QWidget>
#include "ui_StereoCamera.h"

class StereoCamera : public QWidget
{
	Q_OBJECT

public:
	StereoCamera(QWidget *parent = Q_NULLPTR);
	~StereoCamera();

private:
	Ui::StereoCamera ui;
};
