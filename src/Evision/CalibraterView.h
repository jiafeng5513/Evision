#pragma once

#include <QWidget>
#include "ui_CalibraterView.h"
#include "CalibrateParamEntity.h"
#include "CalibrateController.h"
/*
 * 标定:view
 */
class CalibraterView : public QWidget
{
	Q_OBJECT

public:
	CalibraterView(QWidget *parent = Q_NULLPTR);
	~CalibraterView();

private:
	Ui::CalibraterView ui;
	CalibrateParamEntity * m_calib_entity;
	CalibrateController * m_calib_controller;
public slots:
	void setDefaultCalibParam();
	void doCalib();
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

	void onParamChanged_imgLtoShow();//更新左视图
	void onParamChanged_imgRtoShow();//更新右视图

	void onParamChanged_msgBuffer();//消息缓存更新
};
