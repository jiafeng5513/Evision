#include "CameraView.h"
#include <QMessageBox>
#include <QPalette>
#include <QtWidgets>
#include <QVariant>
#include <QCameraDevice>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include <EvisionUtils.h>

Q_DECLARE_METATYPE(QCameraDevice)

CameraView::CameraView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//CameraView devices:

	const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();
	int id = 0;
	for (const QCameraDevice &cameraDevice : availableCameras) {
		ui.comboBox_CameraDevice->addItem(QString::fromStdString(std::to_string(id)+"-")+cameraDevice.description(),QVariant::fromValue(cameraDevice));
		id++;
	}

	setCamera(ui.comboBox_CameraDevice->currentData().value<QCameraDevice>());
	ui.lcdNumber->display(0);
	ui.pushButton_CameraOn->setEnabled(false);
	ui.pushButton_CameraOff->setEnabled(true);

	ui.lineEdit_SavePath->setText(QDir::currentPath());
}

CameraView::~CameraView()
{
	m_pCamera->stop();
}
/*
 *setCamera：设置相机
 *const QCameraDevice& ：相机设备
 *
 *return：void
 */
void CameraView::setCamera(const QCameraDevice &cameraDevice)
{
	m_pCamera.reset(new QCamera(cameraDevice));
	m_pImageCapture.reset(new QImageCapture);
	m_pSession.reset(new QMediaCaptureSession);
	m_pSession->setCamera(m_pCamera.data());
	m_pSession->setImageCapture(m_pImageCapture.data());
	m_pSession->setVideoSink(ui.viewfinder->videoSink());
	refreshResAndCodecList();
	//开启相机
	m_pCamera->start();

}

void CameraView::refreshResAndCodecList()
{
	ui.comboBox_Codec->clear();
	ui.comboBox_Codec->addItem(tr("Default image format"), QVariant(QString()));
	// Qt6: QImageCapture 不再暴露 supportedImageCodecs() — 编解码器选择已移除
	ui.comboBox_Resolution->clear();
	ui.comboBox_Resolution->addItem(tr("Default Resolution"));
	const QList<QSize> supportedResolutions = m_pCamera->cameraDevice().photoResolutions();
	for (const QSize &resolution : supportedResolutions) {
		ui.comboBox_Resolution->addItem(QString("%1x%2").arg(resolution.width()).arg(resolution.height()),
			QVariant(resolution));
	}
	ui.horizontalSlider_Quality->setRange(0, int(QImageCapture::VeryHighQuality));
}

QVariant CameraView::boxValue(const QComboBox* box) const
{
	int idx = box->currentIndex();
	if (idx == -1)
		return QVariant();

	return box->itemData(idx);
}

void CameraView::closeEvent(QCloseEvent * e)
{
	m_pCamera->stop();
}

void CameraView::OnFindSavePath()
{
	QFileDialog * fileDialog2 = new QFileDialog();
	fileDialog2->setWindowTitle(QStringLiteral("请选择保存位置"));
	//fileDialog2->setNameFilter(QStringLiteral("点云文件(*.xml *.yml *.yaml)"));
	fileDialog2->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	fileDialog2->setFileMode(QFileDialog::Directory);
	if (fileDialog2->exec() == QDialog::Accepted)
	{
		saveToHere = fileDialog2->selectedFiles().at(0);
		ui.lineEdit_SavePath->setText(saveToHere);
	}
}

void CameraView::OnCameraPowerOn()
{
	setCamera(ui.comboBox_CameraDevice->currentData().value<QCameraDevice>());
	ui.pushButton_CameraOn->setEnabled(false);
	ui.pushButton_CameraOff->setEnabled(true);
	ui.pushButton_Focus->setEnabled(true);
	ui.pushButton_Shot->setEnabled(true);
	ui.horizontalSlider_exposureCompensation->setEnabled(true);
	ui.horizontalSlider_Quality->setEnabled(true);
}

void CameraView::OnCameraPowerOff()
{
	ui.pushButton_CameraOff->setEnabled(false);
	ui.pushButton_CameraOn->setEnabled(true);
	ui.pushButton_Focus->setEnabled(false);
	ui.pushButton_Shot->setEnabled(false);
	ui.horizontalSlider_exposureCompensation->setEnabled(false);
	ui.horizontalSlider_Quality->setEnabled(false);
	m_pCamera->stop();
}

void CameraView::OnFocus()
{
	if (m_pCamera->focusMode() == QCamera::FocusModeAuto)
		m_pCamera->setFocusMode(QCamera::FocusModeManual);
	else
		m_pCamera->setFocusMode(QCamera::FocusModeAuto);
}

void CameraView::OnShot()
{
	QString idt = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
	m_pImageCapture->captureToFile(ui.lineEdit_SavePath->text() + "/S" + idt + ".jpg");
	ui.lcdNumber->display(ui.lcdNumber->intValue()+1);
}

void CameraView::OnValueChanged_ExposureCompensation(int value)
{
	m_pCamera->setExposureCompensation(value*0.5);
}

void CameraView::OnValueChanged_Quality(int value)
{
	m_pImageCapture->setQuality(QImageCapture::Quality(ui.horizontalSlider_Quality->value()));
}

void CameraView::OnSelectedChanged_CameraDevice(QString value)
{
	setCamera(ui.comboBox_CameraDevice->currentData().value<QCameraDevice>());
}

void CameraView::OnSelectedChanged_Resolution(QString value)
{
	m_pImageCapture->setResolution(boxValue(ui.comboBox_Resolution).toSize());
}

void CameraView::OnSelectedChanged_Codec(QString value)
{
	// Qt6: QImageCapture 不再暴露编解码器 API — 槽保留为空以保持 UI 兼容
	Q_UNUSED(value);
}




