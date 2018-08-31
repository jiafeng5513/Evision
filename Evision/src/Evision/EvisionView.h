#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Evision.h"
#include "EvisionParamEntity.h"
#include "EvisionController.h"

class EvisionView : public QMainWindow
{
	Q_OBJECT

public:
	EvisionView(QWidget *parent = Q_NULLPTR);

private:
	Ui::EvisionClass ui;
	EvisionParamEntity * m_entity;
	EvisionController * m_controller;
	QLabel *msgLabel;
public slots:
	//按钮
	void setDefaultCalibParam();
	void doCalib();
	void setDefaultMatchParam();
	void doMatch();
	void getDistance();
	void getGap();
	//值更改事件,响应UI元素的变化
	//标定参数值更改事件
	void onValueChanged_BoardWidth(QString value);
	void onParamChanged_BoardWidth() const;
	void onValueChanged_BoardHeight(QString value);
	void onParamChanged_BoardHeight();
	void onValueChanged_SquareSize(QString value);
	void onParamChanged_SquareSize();
	//标定标志位值更改事件
	void onClicked_showRectified(bool value);
	void onParamChanged_showRectified();
	//标定算法
	void onClicked_Bouguet(bool value);
	void onParamChanged_Bouguet();
	void onClicked_Hartley(bool value);
	void onParamChanged_Hartley();
	//匹配参数
	void valueChanged_MinDisp(int value);
	void onParamChanged_MinDisp();
	void valueChanged_uniradio(int value);
	void onParamChanged_uniradio();
	void valueChanged_specwinsz(int value);
	void onParamChanged_specwinsz();
	void valueChanged_MaxDisp(int value);
	void onParamChanged_MaxDisp();
	void valueChanged_Specrange(int value);
	void onParamChanged_Specrange();
	void valueChanged_Prefilcap(int value);
	void onParamChanged_Prefilcap();
	void valueChanged_SadWinSize(int value);
	void onParamChanged_SadWinSize();
	void valueChanged_TextThread(int value);
	void onParamChanged_TextThread();
	void valueChanged_MaxDifdisp2(int value);
	void onParamChanged_MaxDifdisp2();

	//匹配算法
	void onClicked_BM(bool value);
	void onParamChanged_BM();
	void onClicked_SGBM(bool value);
	void onParamChanged_SGBM();
	void onClicked_VAR(bool value);
	void onParamChanged_VAR();

	void onParamChanged_Distance();
	//更新左视图和右视图
	void onParamChanged_imgLtoShow();
	void onParamChanged_imgRtoShow();
	void onParamChanged_imgDtoShow();

	void onTestAlltheParam();
	//状态栏
	void onParamChanged_StatusBarText();
	
	/*
	 * 被动更新的组件:
	 *	图片显示区域
	 *	匹配参数的textarea
	 *	距离值显示
	 * 用函数监控某个变量,变量发生变化的时候更新界面
	 */
};
