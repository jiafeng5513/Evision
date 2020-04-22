#pragma once

#include <QWidget>
#include "ui_EvisionRectify.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>

class EvisionRectifyView : public QWidget
{
	Q_OBJECT

public:
	EvisionRectifyView(QWidget *parent = Q_NULLPTR);
	~EvisionRectifyView();

private:
	Ui::EvisionRectify ui;
	QFileInfoList GetFileList(QString path);
	std::map<QString, QString> filesMap;

	QString target_path;
	std::string camera_param_file;
	std::vector<cv::Mat> images;
	std::vector<cv::Mat> undistortedImages;
	cv::Mat cameraMatrix1, cameraMatrix2, distCoeffs1, distCoeffs2,R1,R2,P1,P2;
	cv::Rect roi1, roi2;

	void init();
public slots:
	void onPush_SelectSrcFolder();
	void onPush_SelectTargetFolder();
	void onPush_SelectCameraParamFile();
	void onAddToTargetList();
	void onDeleteFromTargetList();
	void onStart();
};
