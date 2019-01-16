#pragma once

#include <QWidget>
#include "ui_Calibrater.h"

class Calibrater : public QWidget
{
	Q_OBJECT

public:
	Calibrater(QWidget *parent = Q_NULLPTR);
	~Calibrater();

private:
	Ui::Calibrater ui;
};
