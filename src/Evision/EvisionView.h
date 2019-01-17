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
private:
	void dragEnterEvent(QDragEnterEvent *event) override;//文件被拖到窗口区域上
	void dropEvent(QDropEvent *event) override;//文件在窗口区域上被放下
	void mouseReleaseEvent(QMouseEvent *event) override;//鼠标释放事件
};
