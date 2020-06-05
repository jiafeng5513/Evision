#pragma once

#include <QWidget>
#include "ui_MonocularCalibraterView.h"
#include "MonocularCalibrateParamEntity.h"
#include "MonocularCalibrateController.h"
/*
 * 标定:view
 */
class MonocularCalibraterView : public QWidget
{
	Q_OBJECT

public:
	MonocularCalibraterView(QWidget *parent = Q_NULLPTR);
	~MonocularCalibraterView();

private:
	Ui::MonocularCalibraterView ui;
	MonocularCalibrateParamEntity * m_calib_entity;
	MonocularCalibrateController * m_calib_controller;
	QGraphicsScene *m_MainScene;
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

	void onValueChanged_FIX_PRINCIPAL_POINT(bool value);
	void onParamChanged_FIX_PRINCIPAL_POINT();

	void onValueChanged_FIX_ASPECT_RATIO(bool value);
	void onParamChanged_FIX_ASPECT_RATIO();

	void onValueChanged_ZERO_TANGENT_DIST(bool value);
	void onParamChanged_ZERO_TANGENT_DIST();

	void onValueChanged_FIX_K1(bool value);
	void onParamChanged_FIX_K1();

	void onValueChanged_FIX_K2(bool value);
	void onParamChanged_FIX_K2();

	void onValueChanged_FIX_K3(bool value);
	void onParamChanged_FIX_K3();

	void onValueChanged_FIX_K4(bool value);
	void onParamChanged_FIX_K4();

	void onValueChanged_FIX_K5(bool value);
	void onParamChanged_FIX_K5();

	void onValueChanged_FIX_K6(bool value);
	void onParamChanged_FIX_K6();

	void onValueChanged_RATIONAL_MODEL(bool value);
	void onParamChanged_RATIONAL_MODEL();

	void onValueChanged_THIN_PRISM_MODEL(bool value);
	void onParamChanged_THIN_PRISM_MODEL();

	void onValueChanged_FIX_S1_S2_S3_S4(bool value);
	void onParamChanged_FIX_S1_S2_S3_S4();

	void onValueChanged_TILTED_MODEL(bool value);
	void onParamChanged_TILTED_MODEL();

	void onValueChanged_FIX_TAUX_TAUY(bool value);
	void onParamChanged_FIX_TAUX_TAUY();


	void onParamChanged_NewToItemMap();//有人插入了缩略图Map,界面上要响应一下
	void onParamChanged_ClearItemMap();//有人清空了缩略图的Map,界面上响应一下
	void onItemClicked(QListWidgetItem*item);//响应点击缩略图

	void onPush_saveParamsToFile();
};
