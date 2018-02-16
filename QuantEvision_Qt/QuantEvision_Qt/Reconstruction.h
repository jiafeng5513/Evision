#pragma once

#include <QWidget>
#include "ui_Reconstruction.h"

class Reconstruction : public QWidget
{
	Q_OBJECT

public:
	Reconstruction(QWidget *parent = Q_NULLPTR);
	~Reconstruction();

private:
	Ui::Reconstruction ui;
};
