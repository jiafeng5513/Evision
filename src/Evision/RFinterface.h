#pragma once

#include <QWidget>
#include "ui_RFinterface.h"
#include <core/core.hpp>
#include <QtWidgets/QGraphicsView>
/*
 * 负责交互式测量功能的view
 */
class RFinterface : public QWidget
{
	Q_OBJECT

public:
	RFinterface(QWidget *parent = Q_NULLPTR);
	RFinterface(cv::Mat img, cv::Mat disp, cv::Mat xyz, QWidget  *parent = 0);
	~RFinterface();

private:
	Ui::RFinterface ui;
	cv::Mat img;
	cv::Mat disp;
	cv::Mat xyz;
	cv::Mat depth;
	double m_ObjectDistance;
private:
	void printImgToO(cv::Mat value);
	void printImgToD(cv::Mat value);
public slots:
	void onMouseMove(int x, int y);
	void onMouseLButtonDown(int x, int y);
	void onMouseRButtonDown(int x, int y);

};
