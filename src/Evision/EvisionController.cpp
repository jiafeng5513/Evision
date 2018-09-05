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
//命令:标定默认参数
void EvisionController::setDefaultCalibParamCommand()
{
	m_entity->setBoardWidth(9);
	m_entity->setBoardHeight(6);
	m_entity->setSquareSize(25);
	m_entity->setshowRectified(false);
	m_entity->setBouguet(true);
}
//命令:标定
void EvisionController::CalibrateCommand()
{
	//1.验证参数
	if (m_entity->getBoardWidth()*m_entity->getBoardHeight()*m_entity->getSquareSize()<=0)
	{
		//未通过参数完整性验证
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("参数有误!请检查!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	//2.选择文件
	QFileDialog * fileDialog=new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片文件序列"));
	fileDialog->setNameFilter("图片文件(*.jpg *.png *.jpeg)");
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		ImageListL = fileDialog->selectedFiles();
		fileDialog->setWindowTitle(QStringLiteral("请选择右摄像头拍摄的图片文件序列"));
		if (fileDialog->exec() == QDialog::Accepted)
		{
			ImageListR = fileDialog->selectedFiles();
			//两个文件列表都点击了确定
			//验证数量
			if (ImageListL.size() != ImageListR.size() || ImageListL.size() == 0 || ImageListR.size() == 0)
			{
				//有一侧图像数目为0或者两侧的图像数量不一样,退出
				QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("左右视图数量不相等或为空"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				return;
			}
			else
			{
				/*
				 *3.一切正常,可以进行从图片标定
				 */
				std::vector<std::string>* imagelist = new std::vector<std::string>();
				std::vector<std::string>* imagelistL = new std::vector<std::string>();
				std::vector<std::string>* imagelistR = new std::vector<std::string>();
				for (int i = 0; i < std::min(ImageListL.size(),ImageListR.size()); ++i)
				{
					imagelist->push_back(ImageListL.at(i).toStdString());
					imagelist->push_back(ImageListR.at(i).toStdString());
					imagelistL->push_back(ImageListL.at(i).toStdString());
					imagelistR->push_back(ImageListR.at(i).toStdString());

				}
				cv::Size * _size = new cv::Size();
				_size->width = m_entity->getBoardWidth();
				_size->height = m_entity->getBoardHeight();
				StereoCalibrate * _stereoCalib = new StereoCalibrate(imagelistL, imagelistR, *_size,m_entity->getSquareSize(),m_entity->getBouguet(),m_entity->getshowRectified());
				connect(_stereoCalib,SIGNAL(openMessageBox(QString, QString)),this,SLOT(onOpenMessageBox(QString,QString)));
				_stereoCalib->start();
			}
		}
		else
		{
			//选择右图的时候退出
			return;
		}
	}
	else
	{
		//选择左图的时候退出
		return;
	}
}
//命令:匹配默认参数
void EvisionController::setDefaultMatchParamCommand()
{
	if (m_entity->getBM())
	{
		m_entity->setPrefilcap(31);
		m_entity->setSadWinsz(51);
		m_entity->setMinDisp(0);
		m_entity->setNumDisparities(144);
		m_entity->setUniradio(15);
		m_entity->setSpecwinsz(100);
		m_entity->setSpecrange(32);
		m_entity->setTextThread(10);
		m_entity->setMaxdifdisp12(1);
	}
	else if (m_entity->getSGBM())
	{
		m_entity->setMinDisp(0);
		m_entity->setUniradio(10);
		m_entity->setSpecwinsz(100);
		m_entity->setNumDisparities(144);
		m_entity->setSpecrange(32);
		m_entity->setPrefilcap(63);
		m_entity->setSadWinsz(25);
		m_entity->setMaxdifdisp12(1);
		m_entity->setMODE_HH(true);
	}
	else if (m_entity->getMODE_HH())
	{
		m_entity->setMinDisp(-64);
		m_entity->setNumDisparities(64);
	}
	else
	{
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("没有选择匹配算法"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}
//命令:匹配
void EvisionController::MatchCommand()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片"));
	fileDialog->setNameFilter(QStringLiteral("图片文件(*.jpg *.png *.jpeg)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		ImageL = fileDialog->selectedFiles().at(0);
		fileDialog->setWindowTitle(QStringLiteral("请选择右摄像头拍摄的图片"));
		if (fileDialog->exec() == QDialog::Accepted)
		{
			ImageR = fileDialog->selectedFiles().at(0);
			if (!ImageL.isEmpty()&&!ImageR.isEmpty())
			{
				//两侧图片文件正常
				QFileDialog * fileDialog2 = new QFileDialog();
				fileDialog2->setWindowTitle(QStringLiteral("请选择内参文件"));
				fileDialog2->setNameFilter(QStringLiteral("YML/XML文件(*.yml *.yaml *.xml)"));
				fileDialog2->setFileMode(QFileDialog::ExistingFile);
				if (fileDialog2->exec() == QDialog::Accepted)
				{
					insFile= fileDialog2->selectedFiles().at(0);
					fileDialog2->setWindowTitle(QStringLiteral("请选择外参文件"));
					if (fileDialog2->exec() == QDialog::Accepted)
					{
						extFile = fileDialog2->selectedFiles().at(0);
						if (!insFile.isEmpty()&&!extFile.isEmpty())
						{
							//内外参数文件正常
							StereoMatch *_stereoMatch = new StereoMatch(ImageL.toStdString(),
								ImageR.toStdString(), insFile.toStdString(), extFile.toStdString());
							connect(_stereoMatch, SIGNAL(openMessageBox(QString, QString)), this, SLOT(onOpenMessageBox(QString, QString)));
							_stereoMatch->start();
							
						}
						else
						{
							QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的内外参文件!"));
							return;
						}
					}
				}else
				{
					return;
				}

			}else
			{
				QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("请选择有效的两侧图片!"));
				return;
			}

		}else
		{
			return;
		}
	}else
	{
		return;
	}
}
//命令:刷新视差图
void EvisionController::RefreshStereoMatchCommand()
{
	StereoMatch *_stereoMatch = new StereoMatch(ImageL.toStdString(),
		ImageR.toStdString(), insFile.toStdString(), extFile.toStdString());
	connect(_stereoMatch, SIGNAL(openMessageBox(QString, QString)), this, SLOT(onOpenMessageBox(QString, QString)));
	_stereoMatch->start();
}
//命令:测量
void EvisionController::getDistanceCommand()
{
	cv::Mat img, disp, xyz;
	//测试Entity中视差图,左视图,点云这三个变量的值是否非空
	if (m_entity->getImageLtoShow().empty()||m_entity->getDisparity().empty()||m_entity->getXYZ().empty())
	{
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
	}
	else
	{
		//状态良好,转移变量值
		img = m_entity->getImageLtoShow();
		disp = m_entity->getDisparity();
		xyz = m_entity->getXYZ();
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

