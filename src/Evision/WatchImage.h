#pragma once

#include <QWidget>
#include "ui_WatchImage.h"

class WatchImage : public QWidget
{
	Q_OBJECT

public:
	WatchImage(QWidget *parent = Q_NULLPTR);
	~WatchImage();

private:
	Ui::WatchImage ui;
};
