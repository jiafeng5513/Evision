#include "CalibrateController.h"
#include "StereoCalibrate.h"
#include <QMessageBox>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include "EvisionUtils.h"

CalibrateController::CalibrateController(QObject* parent)
	: QObject(parent), _stereoCalib(nullptr)
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
	m_calib_entity->setBoardTypeIndex(0);
	m_calib_entity->setMarkerSize(18.75f);
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
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("参数有误!请检查!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	//2.选择文件
	QFileDialog fileDialog;
	fileDialog.setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片文件序列"));
	fileDialog.setNameFilter("图片文件(*.jpg *.png *.jpeg *.bmp)");
	fileDialog.setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	fileDialog.setFileMode(QFileDialog::ExistingFiles);
	if (fileDialog.exec() == QDialog::Accepted)
	{
		ImageListL = fileDialog.selectedFiles();
		fileDialog.setWindowTitle(QStringLiteral("请选择右摄像头拍摄的图片文件序列"));
		if (fileDialog.exec() == QDialog::Accepted)
		{
			ImageListR = fileDialog.selectedFiles();
			//验证数量
			if (ImageListL.size() != ImageListR.size() || ImageListL.size() == 0 || ImageListR.size() == 0)
			{
				QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("左右视图数量不相等或为空"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				return;
			}
			else
			{
				std::vector<std::string> imagelistL;
				std::vector<std::string> imagelistR;
				for (int i = 0; i < std::min(ImageListL.size(), ImageListR.size()); ++i)
				{
					imagelistL.push_back(ImageListL.at(i).toStdString());
					imagelistR.push_back(ImageListR.at(i).toStdString());
				}
				m_calib_entity->clearItemMap();

				if (_stereoCalib != nullptr)
				{
					disconnect(_stereoCalib, nullptr, this, nullptr);
					if (_stereoCalib->isRunning())
					{
						_stereoCalib->wait();
					}
					_stereoCalib->deleteLater();
				}

				_stereoCalib = new StereoCalibrate(imagelistL, imagelistR);
				connect(_stereoCalib, &StereoCalibrate::openMessageBox, this, &CalibrateController::onOpenMessageBox);
				connect(_stereoCalib, &StereoCalibrate::reportReady, m_calib_entity, &CalibrateParamEntity::calibReportReady);
				_stereoCalib->start();
			}
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
}

//命令:把参数保存到文件中
void CalibrateController::SaveParamsToFileCommand()
{
	if (_stereoCalib != nullptr && !_stereoCalib->isRunning())
	{
		_stereoCalib->SaveCameraParamsToFile();
	}
}

//消息响应:弹出对话框
void CalibrateController::onOpenMessageBox(QString title, QString msg)
{
	QMessageBox::information(NULL, title, msg);
}
