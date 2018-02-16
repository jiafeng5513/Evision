#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QuantEvision_Qt.h"

class QuantEvision_Qt : public QMainWindow
{
	Q_OBJECT

public:
	QuantEvision_Qt(QWidget *parent = Q_NULLPTR);

private:
	Ui::QuantEvision_QtClass ui;
public slots:
	void RangeGuide();		//启动/关闭测距向导
	void ShowCalibrate();	//启动标定界面
	void ShowMatch();		//启动匹配界面
	void ShowReconstruct();	//启动三维重建界面
	void ShowRange();		//启动测距界面

};
