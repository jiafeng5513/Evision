#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Evision.h"
#include "EvisionParamEntity.h"
#include <QLabel>
#include "LogView.h"

class EvisionView : public QMainWindow
{
	Q_OBJECT

public:
	EvisionView(QWidget *parent = Q_NULLPTR);

private:
	Ui::EvisionClass ui;
	EvisionParamEntity * m_entity;
	//EvisionController * m_controller;
	QLabel *msgLabel;

	QPoint old_pos;
	QSize old_size;
	LogView * logView;
public slots:
	//菜单
	void on_action_Camera_triggered();						//单目相机
	void on_action_StereoCamera_triggered();					//双目相机
	void on_action_ShowPointCloud_triggered();				//显示点云

	void on_action_CalibrateView_triggered();		//启动标定视图
	void on_action_Rectify_triggered();				//启动校正视图
	void on_action_StereoMatchView_triggered();		//启动匹配视图
	void on_action_Measure_View_triggered();			//启动测量界面
	void on_action_PolyTracker_triggered();		//启动几何体追踪视图
	void on_action_LogView_triggered();			//LOGVIEW
	void on_action_dispToPCD_triggered();			//视差转点云
	void on_action_CreateParamFile_triggered();			//创建相机参数文件
	void on_action_MonocularCalib_triggered();   //单目标定视图
	//状态栏
	void onParamChanged_StatusBarText();
private:
	void dragEnterEvent(QDragEnterEvent *event) override;//文件被拖到窗口区域上
	void dropEvent(QDropEvent *event) override;//文件在窗口区域上被放下
	void mouseReleaseEvent(QMouseEvent *event) override;//鼠标释放事件
	void moveEvent(QMoveEvent* event) override;
	void resizeEvent(QResizeEvent* event) override;
	void changeEvent(QEvent*) override;
	void closeEvent(QCloseEvent* event) override;
};
