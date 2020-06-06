#include "CalibrateController.h"
#include "StereoCalibrate.h"
#include <QMessageBox>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include "EvisionUtils.h"
CalibrateController::CalibrateController(QObject* parent)
	: QObject(parent)
{
	m_calib_entity = CalibrateParamEntity::getInstance();
}

CalibrateController::~CalibrateController()
{
}
//命令:默认标定参数
void CalibrateController::setDefaultCalibParamCommand()
{
	m_calib_entity->setBoardWidth(9);
	m_calib_entity->setBoardHeight(6);
	m_calib_entity->setSquareSize(25);
	m_calib_entity->setCALIB_SAME_FOCAL_LENGTH(true);
	m_calib_entity->setCALIB_RATIONAL_MODEL(true);
	m_calib_entity->setCALIB_FIX_K3(true);
	m_calib_entity->setCALIB_FIX_K4(true);
	m_calib_entity->setCALIB_FIX_K5(true);
}
//命令:标定
void CalibrateController::CalibrateCommand()
{
	//1.验证参数
	if (m_calib_entity->getBoardWidth() * m_calib_entity->getBoardHeight() * m_calib_entity->getSquareSize() <= 0)
	{
		//未通过参数完整性验证
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("参数有误!请检查!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	//2.选择文件
	QFileDialog* fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片文件序列"));
	fileDialog->setNameFilter("图片文件(*.jpg *.png *.jpeg *.bmp)");
	fileDialog->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	fileDialog->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
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
				std::vector<std::string>* imagelistL = new std::vector<std::string>();
				std::vector<std::string>* imagelistR = new std::vector<std::string>();
				for (int i = 0; i < std::min(ImageListL.size(), ImageListR.size()); ++i)
				{
					imagelistL->push_back(ImageListL.at(i).toStdString());
					imagelistR->push_back(ImageListR.at(i).toStdString());
				}
				m_calib_entity->clearItemMap();
				_stereoCalib = new StereoCalibrate(imagelistL, imagelistR);
				connect(_stereoCalib, SIGNAL(openMessageBox(QString, QString)), this, SLOT(onOpenMessageBox(QString, QString)));
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
//命令:把参数保存到文件中
void CalibrateController::SaveParamsToFileCommand()
{
	if (_stereoCalib != NULL)
	{
		_stereoCalib->SaveCameraParamsToFile();
	}
}

//消息响应:弹出对话框
void CalibrateController::onOpenMessageBox(QString title, QString msg)
{
	QMessageBox::information(NULL, title, msg);
}
