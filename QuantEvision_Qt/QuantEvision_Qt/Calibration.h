#pragma once

#include <QWidget>
#include "ui_Calibration.h"
#include <core/affine.hpp>
#include "Calibrater.h"
#include <QMetaType>
#include <core/core.hpp>

class Calibration : public QWidget
{
	Q_OBJECT

public:
	Calibration(QWidget *parent = Q_NULLPTR);
	~Calibration();

private:
	Ui::Calibration ui;
private:
	//Calibrater * m_stereoCalibrator;//标定的业务逻辑
	QStringList ImageListL, ImageListR;//从图片标定时需要的两组图片
	void ShowImage(cv::Mat imgL, cv::Mat imgR);//显示Mat到界面上
	QString WorkPath=".\\";
	cv::Mat imgLtoShow, imgRtoShow;
signals:
	void IsTimeToShowImages();
public slots:
	void OnShowImages();					//响应显示图片的信号
	void OnDefaultBoardParams();            //标定板默认参数
	void OnChecked_Bouguet();				//点击"Bouguet"选项
	void OnChecked_Hartley();				//点击"Hartley"选项
	void OnChecked_Fi();					//点击"Fi"选项
	void OnChecked_Uig();					//点击"Uig"选项
	void OnChecked_Sfl();					//点击"SFI"选项
	void OnChecked_FPP();					//点击"FPP选项"
	void OnChecked_Far();					//点击"FAR"选项
	void OnChooseImages();					//选择标定图片
	void OnCalibrateFromImage();			//从图片标定
	void OnChanged_LCameraComboBox();		//变更左摄像头
	void OnChanged_RChangeComboBox();		//变更右摄像头
	void OnChanged_ResolutionComboBox();	//变更分辨率
	void OnRefreshCameras();				//刷新摄像头
	void OnCamerasPowerOn();				//启动/关闭摄像头
	void OnCalibrateFromCameras();			//从摄像头标定
	void OnChooseCalibrateFile();			//选择标定文件
	void OnCalibrateFromFile();				//从文件标定

	void OnShowImg();						//测试:显示图片
};
