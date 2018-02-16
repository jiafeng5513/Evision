#pragma once

#include <QWidget>
#include "ui_Measurement.h"

class Measurement : public QWidget
{
	Q_OBJECT

public:
	Measurement(QWidget *parent = Q_NULLPTR);
	~Measurement();

private:
	Ui::Measurement ui;
};
