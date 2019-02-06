#pragma once

#include <QWidget>
#include "ui_LogView.h"

class LogView : public QWidget
{
	Q_OBJECT

public:
	LogView(QWidget *parent = Q_NULLPTR);
	~LogView();

private:
	Ui::LogView ui;
};
