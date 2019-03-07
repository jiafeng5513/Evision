#pragma once

#include <QWidget>
#include "ui_RulerView.h"
#include <core/core.hpp>
#include <QtWidgets/QGraphicsView>
/*
 * 负责交互式测量功能的view
 */
class RulerView : public QWidget
{
	Q_OBJECT

public:
	RulerView(QWidget *parent = Q_NULLPTR);
	~RulerView();

private:
	Ui::RulerView ui;

	cv::Mat img;		   //原图
	cv::Mat RawDisp;	   //原始视差图
	cv::Mat Q;			   //Q矩阵
	cv::Mat image3D;	   //
	float scaleFactor=1.0;     //缩放因子
	cv::Mat disparityGary; //灰度视差图
	bool DispIsShowing = true;
	QGraphicsScene *sceneL;
	bool started = false;
private:
	void printImgToO(cv::Mat value);
	void checkEnable();
public slots:
	void onMouseMove(int x, int y);
	void onMouseLButtonDown(int x, int y);
	void onMouseRButtonDown(int x, int y);

	void onSelectRawDispFile();
	void onSelectOriginImg();
	void onSelectCameraParamFile();
	void onStart();
	void onSwitchImageToShow();
};
