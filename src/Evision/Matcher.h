#pragma once

#include <QWidget>
#include "ui_Matcher.h"

class Matcher : public QWidget
{
	Q_OBJECT

public:
	Matcher(QWidget *parent = Q_NULLPTR);
	~Matcher();

private:
	Ui::Matcher ui;
};
