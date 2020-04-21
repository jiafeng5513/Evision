#include "LogView.h"
#ifdef WIN32
#include <corecrt_wstdio.h>
#endif
#include <stdio.h>
#include <iostream>
#include <QTimer>
#include <qdebug.h>
#include <QDateTime>
LogView::LogView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(this->windowFlags() &~Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
	this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);//保持在界面的最前面
	ui.checkBox_StayOnTop->setChecked(true);
	redirector = new StdoutRedirector(this, StdoutRedirector::StandardOutput | StdoutRedirector::StandardError);
	connect(redirector, SIGNAL(readyRead()), this, SLOT(readData()));

}

LogView::~LogView()
{
}
//获取实例
LogView* LogView::getInstance()
{
	static LogView * m_pInstance;
	if (m_pInstance == NULL) //判断是否第一次调用
		m_pInstance = new LogView();
	return m_pInstance;
}

void LogView::readData()
{
	ui.textEdit->append(QString::fromLocal8Bit(redirector->read(1024)));
}
//
void LogView::onChecked_StayOnTop(bool value)
{
	if (value==true)
	{
		this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);//保持在界面的最前面
	}
	else
	{
		this->setWindowFlags(this->windowFlags() &~Qt::WindowStaysOnTopHint);
	}
	this->show();
}
//清空
void LogView::onPush_Delete()
{
	ui.textEdit->clear();
}
