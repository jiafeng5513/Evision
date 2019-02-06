#include "LogView.h"

LogView::LogView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(this->windowFlags() &~Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
	this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
}

LogView::~LogView()
{
}
