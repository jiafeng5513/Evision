#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Evision.h"

class Evision : public QMainWindow
{
	Q_OBJECT

public:
	Evision(QWidget *parent = Q_NULLPTR);

private:
	Ui::EvisionClass ui;
};
