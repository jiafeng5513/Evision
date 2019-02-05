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
	RulerView(cv::Mat img, cv::Mat disp, cv::Mat xyz, QWidget  *parent = 0);
	~RulerView();

private:
	Ui::RulerView ui;
	cv::Mat img;
	cv::Mat disp;
	cv::Mat xyz;
	cv::Mat depth;
	double m_ObjectDistance;
	bool started = false;
private:
	void printImgToO(cv::Mat value);
	void printImgToD(cv::Mat value);
	void checkEnable();
public slots:
	void onMouseMove(int x, int y);
	void onMouseLButtonDown(int x, int y);
	void onMouseRButtonDown(int x, int y);
	void onSelectDisparityMap();
	void onSelectleftMap();
	void onSelectPointcloudFile();
	void onStart();
};
