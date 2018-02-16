#pragma once

#include <QWidget>
#include "ui_Match.h"

class Match : public QWidget
{
	Q_OBJECT

public:
	Match(QWidget *parent = Q_NULLPTR);
	~Match();

private:
	Ui::Match ui;
};
