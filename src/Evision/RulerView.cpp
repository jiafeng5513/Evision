#include "RulerView.h"
#include "EvisionUtils.h"
#include "QGraphicsScene"
#include <QFileDialog>
#include "StereoMatch.h"
#include <QMessageBox>
#include <iostream>
//直接启动视图,后设置参数
RulerView::RulerView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.checkBox_RawDispOK->setEnabled(false);
	ui.checkBox_OriginOK->setEnabled(false);
	ui.checkBox_CameraParamOK->setEnabled(false);
	ui.pushButton_start->setEnabled(false);
	sceneL = new QGraphicsScene();
}

RulerView::~RulerView()
{
}
//向O窗口画图
void RulerView::printImgToO(cv::Mat value)
{
	sceneL->clear();
	QImage QImage = EvisionUtils::cvMat2QImage(value);
	sceneL->addPixmap(QPixmap::fromImage(QImage));
	ui.customGraphicsView_O->setScene(sceneL);
	ui.customGraphicsView_O->setMinimumSize(QImage.width(), QImage.height());
	ui.customGraphicsView_O->setMaximumSize(QImage.width(), QImage.height());
	ui.customGraphicsView_O->show();
	ui.customGraphicsView_O->update();
}

void RulerView::checkEnable()
{
	if(ui.checkBox_RawDispOK->isChecked()&&ui.checkBox_OriginOK->isChecked()&&ui.checkBox_CameraParamOK->isChecked())
	{
		ui.pushButton_start->setEnabled(true);
	}
}

//响应鼠标移动
void RulerView::onMouseMove(int x, int y)
{
	ui.lineEdit_ImgX->setText(QString::fromStdString(std::to_string(x)));
	ui.lineEdit_ImgY->setText(QString::fromStdString(std::to_string(y)));

}
//响应鼠标左键击键
void RulerView::onMouseLButtonDown(int x, int y)
{
	if (started)
	{
		float disp;

		if (RawDisp.type() == CV_32F)
			disp = RawDisp.at<float>(y, x);
		else
			disp = RawDisp.at<uchar>(y, x);

		float vec3DAbs;
		if (disp > 0)
		{
			cv::Point3f vec3D = image3D.at<cv::Point3f>(y, x);
			vec3DAbs = sqrt(pow(vec3D.x, 2) + pow(vec3D.y, 2) + pow(vec3D.z, 2));
		}
		else
		{
			vec3DAbs = -1;
		}
		ui.lineEdit_Res->setText(QString::fromStdString(std::to_string(vec3DAbs)));
	}
}
//响应鼠标右键击键
void RulerView::onMouseRButtonDown(int x, int y)
{

}
/*
 * 选择原始视差文件
 */
void RulerView::onSelectRawDispFile()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择原始视差文件"));
	fileDialog->setNameFilter(QStringLiteral("序列化(*.xml)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		try
		{
			cv::FileStorage fStorage(fileDialog->selectedFiles().at(0).toStdString(), cv::FileStorage::READ);
			fStorage["disp"] >> RawDisp;
			fStorage.release();
		}
		catch (cv::Exception e)
		{
			std::cout << "原始视差数据读取失败!" << e.err << std::endl;
		}
		ui.checkBox_RawDispOK->setChecked(true);
		checkEnable();
	}
}
/*
 * 选择原图
 */
void RulerView::onSelectOriginImg()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择参与生成所选视差图的左视图或右视图"));
	fileDialog->setNameFilter(QStringLiteral("图片文件(*.jpg *.png *.jpeg *.bmp)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		try
		{
			this->img = cv::imread(fileDialog->selectedFiles().at(0).toStdString());
		}
		catch (cv::Exception e)
		{
			std::cout << "原图读取失败!" << e.err << std::endl;
		}
		ui.checkBox_OriginOK->setChecked(true);
		checkEnable();
	}
}
/*
 * 选择相机参数文件
 */
void RulerView::onSelectCameraParamFile()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择相机参数文件"));
	fileDialog->setNameFilter(QStringLiteral("序列化文件(*.xml *.yml)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		try
		{
			cv::FileStorage fStorage(fileDialog->selectedFiles().at(0).toStdString(), cv::FileStorage::READ);
			fStorage["Q"] >> Q;
			fStorage.release();
			ui.checkBox_CameraParamOK->setChecked(true);
			checkEnable();
		}
		catch (cv::Exception e)
		{
			std::cout << "相机参数读取失败!" << e.err << std::endl;
		}

	}
}

void RulerView::onStart()
{
	cv::reprojectImageTo3D(RawDisp, image3D, Q);
	cv::Mat resizedImage, resizedDispMap;
	cv::resize(img, resizedImage, cv::Size(), scaleFactor, scaleFactor);
	cv::resize(RawDisp, resizedDispMap, cv::Size(), scaleFactor, scaleFactor);
	img = resizedImage.clone();
	RawDisp = resizedDispMap.clone();
	cv::resize(image3D, image3D, cv::Size(), scaleFactor, scaleFactor);

	if (RawDisp.type() == CV_32F)
	{
		//ADCensus的原始视差数据是CV_32F,不能直接显示
		EvisionUtils::getGrayDisparity<float>(RawDisp, disparityGary, true);
	}
	else if(RawDisp.type() == CV_8U)
	{
		//BM,SGBM和ELAS的视差数据是CV_8U,可以直接显示
		disparityGary = RawDisp;
	}
	printImgToO(disparityGary);
	ui.pushButton_selectRawDisp->setEnabled(false);
	ui.pushButton_selectOrigin->setEnabled(false);
	ui.pushButton_selectCameraParam->setEnabled(false);
	started = true;
}

void RulerView::onSwitchImageToShow()
{
	if(DispIsShowing)
	{
		printImgToO(img);
		DispIsShowing = !DispIsShowing;
	}
	else
	{
		printImgToO(disparityGary);
		DispIsShowing = !DispIsShowing;
	}
}
