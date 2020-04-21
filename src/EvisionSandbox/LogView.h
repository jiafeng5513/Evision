#pragma once

#include <QWidget>
#include "ui_LogView.h"
#include "StdoutRedirector.h"

class LogView : public QWidget
{
	Q_OBJECT

public:
	LogView(QWidget *parent = Q_NULLPTR);
	~LogView();
	static LogView *getInstance();
private:
	Ui::LogView ui;
	StdoutRedirector *redirector;
public slots:
	void readData();//接收重定向过来的信息
	void onChecked_StayOnTop(bool value);//保持在前端
	void onPush_Delete();//清空
};
