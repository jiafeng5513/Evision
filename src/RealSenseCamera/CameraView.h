#pragma once

#include <QWidget>
#include "ui_CameraView.h"
#include <opencv2/opencv.hpp>
#include <QGraphicsScene>
class CameraView : public QWidget
{
	Q_OBJECT

public:
	CameraView(QWidget *parent = Q_NULLPTR);
	~CameraView();

private:
	Ui::CameraView ui;
	QString saveToHere;
	cv::Mat* color;
	cv::Mat* pic_right;
	cv::Mat* pic_left;
	cv::Mat* pic_depth;

	QGraphicsScene* sceneL;
	QGraphicsScene* sceneR;
	QGraphicsScene* sceneRGB;
	QGraphicsScene* sceneDepth;

	bool keepRunning = true;
	const int width = 1280;
	const int height = 720;
	const int fps = 30;
	const cv::Size imgsize = cv::Size(width, height);
private:
	void closeEvent(QCloseEvent * e) override;
	void RealSenseThread();
	void printImgToL(cv::Mat value);
	void printImgToR(cv::Mat value);
	void printImgToRGB(cv::Mat value);
	void printImgToDepth(cv::Mat value);
private slots:
	void OnFindSavePath();
	void OnCameraPowerOn();
	void OnCameraPowerOff();
	void OnShot();

	void OnParamChange_ImgL();
	void OnParamChange_ImgR();
	void OnParamChange_ImgRGB();
	void OnParamChange_ImgDepth();

signals:
	void paramChange_ImgL();
	void paramChange_ImgR();
	void paramChange_ImgRGB();
	void paramChange_ImgDepth();
};
