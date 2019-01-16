#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Evision.h"
#include "EvisionParamEntity.h"
#include "EvisionController.h"
#include <QLabel>

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
	void getDistance();//按钮

	//菜单
	void onCamera();
	void onStereoCamera();
	void onShowPointCloud();//显示点云

	void on_action_calibrate_view();//启动标定视图
	void on_action_stereoMatch_view();//启动匹配视图
	void on_action_Measure_view();//启动测量界面

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
