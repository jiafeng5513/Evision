#include "EvisionController.h"
#include <QMessageBox>
#include "QFileDialog"
#include <imgcodecs/imgcodecs_c.h>
#include <imgproc.hpp>
#include <highgui.hpp>
#include <iostream>
#include <calib3d/calib3d.hpp>
#include "StereoCalibrate.h"
#include "QMessageBox"
#include "StereoMatch.h"
#include "PointCloudUtils.h"
#include "RFinterface.h"
#include "Camera.h"
#include "StereoCamera.h"


EvisionController::EvisionController(QObject * parent):QObject(parent)
{
	m_entity = EvisionParamEntity::getInstance();
}

EvisionController::~EvisionController()
{
}


//命令:测量
void EvisionController::getDistanceCommand()
{
	cv::Mat img, disp, xyz;

		//询问文件位置并载入变量
		QString imgFile, dispFile, xyzFile;
		QFileDialog * fileDialog = new QFileDialog();
		fileDialog->setWindowTitle(QStringLiteral("请选择视差图"));
		fileDialog->setNameFilter(QStringLiteral("图片文件(*.jpg *.png *.jpeg)"));
		fileDialog->setFileMode(QFileDialog::ExistingFile);
		if (fileDialog->exec() == QDialog::Accepted)
		{
			imgFile = fileDialog->selectedFiles().at(0);
			fileDialog->setWindowTitle(QStringLiteral("请选择参与生成所选视差图的左视图"));
			if (fileDialog->exec() == QDialog::Accepted)
			{
				dispFile = fileDialog->selectedFiles().at(0);

				QFileDialog * fileDialog2 = new QFileDialog();
				fileDialog2->setWindowTitle(QStringLiteral("请选择点云文件"));
				fileDialog2->setNameFilter(QStringLiteral("点云文件(*.xml *.yml *.yaml)"));
				fileDialog2->setFileMode(QFileDialog::ExistingFile);
				if (fileDialog2->exec() == QDialog::Accepted)
				{
					xyzFile = fileDialog2->selectedFiles().at(0);
					if (imgFile.isEmpty()||dispFile.isEmpty()||xyzFile.isEmpty())
					{
						//文件不全,弹出提示退出
						QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的文件!"));
						return;
					}
					else
					{
						//文件齐全,读取内容
						img= cv::imread(imgFile.toStdString());
						disp= cv::imread(dispFile.toStdString());
						xyz = StereoMatch::readXYZ(xyzFile.toStdString().c_str());
					}
				}
				else
				{
					QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的文件!"));
					return;
				}
			}
			else
			{
				QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的文件!"));
				return;
			}
		}
		else
		{
			QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的文件!"));
			return;
		}
	

	//准备工作结束,如果程序运行到这个位置,说明三个变量的值都有了有效值,此时可以启动交互式测量的view
	//img,disp.xyz
	RFinterface * _Rfinterface = new RFinterface(img, disp, xyz);
	_Rfinterface->show();
}
//命令:显示点云
void EvisionController::ShowPointCloudCommand()
{
	QFileDialog * fileDialog2 = new QFileDialog();
	fileDialog2->setWindowTitle(QStringLiteral("请选择点云文件"));
	fileDialog2->setNameFilter(QStringLiteral("点云文件(*.xml *.yml *.yaml)"));
	fileDialog2->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog2->exec() == QDialog::Accepted)
	{
		QString xyzFile = fileDialog2->selectedFiles().at(0);
		cv::Mat xyz = StereoMatch::readXYZ(xyzFile.toStdString().c_str());
	}
	else
	{
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的点云文件!"));
		return;
	}
	//点云获取ok,准备显示
}
//命令:启动相机
void EvisionController::openCameraCommand()
{
	Camera * _camera = new Camera();
	_camera->show();
}
//命令:启动双目相机
void EvisionController::openStereoCameraCommand()
{
	StereoCamera * _stereoCamera = new StereoCamera();
	_stereoCamera->show();
}

//消息响应:弹出对话框
void EvisionController::onOpenMessageBox(QString title, QString msg)
{
	QMessageBox::information(NULL, title, msg);
}

