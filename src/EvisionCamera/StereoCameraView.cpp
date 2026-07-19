#include "StereoCameraView.h"
#include <QMessageBox>
#include <QPalette>
#include <QtWidgets>
#include <QVariant>
#include <QCameraDevice>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaCaptureSession>
#include "EvisionUtils.h"
Q_DECLARE_METATYPE(QCameraDevice)

StereoCameraView::StereoCameraView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();

	if(availableCameras.size()<=1)
	{
		this->close();
		QMessageBox::information(NULL, QStringLiteral("警告"), QStringLiteral("可用摄像头数量小于2,无法启动该功能!"));
		return;
	}

	int id = 0;
	for (const QCameraDevice &cameraDevice : availableCameras) {
		ui.comboBox_Lcam->addItem(QString::fromStdString(std::to_string(id) + "-") + cameraDevice.description(), QVariant::fromValue(cameraDevice));
		ui.comboBox_Rcam->addItem(QString::fromStdString(std::to_string(id) + "-") + cameraDevice.description(), QVariant::fromValue(cameraDevice));
		id++;
	}
	ui.comboBox_Lcam->setCurrentIndex(0);
	ui.comboBox_Lcam->setCurrentIndex(1);
	setLCamera(ui.comboBox_Lcam->currentData().value<QCameraDevice>());
	setRCamera(ui.comboBox_Rcam->currentData().value<QCameraDevice>());

	ui.pushButton_CloseCamera->setEnabled(true);
	ui.pushButton_OpenCamera->setEnabled(false);
	ui.lcdNumber->display(0);
	ui.lineEdit_SaveTo->setText(QDir::currentPath());
}

StereoCameraView::~StereoCameraView()
{
	m_pLCamera->stop();
	m_pRCamera->stop();
}
//设置左相机
void StereoCameraView::setLCamera(const QCameraDevice &cameraDevice)
{
	m_pLCamera.reset(new QCamera(cameraDevice));
	m_pLImageCapture.reset(new QImageCapture);
	m_pLSession.reset(new QMediaCaptureSession);
	m_pLSession->setCamera(m_pLCamera.data());
	m_pLSession->setImageCapture(m_pLImageCapture.data());
	m_pLSession->setVideoSink(ui.viewfinderL->videoSink());
	refreshResAndCodecListL();
	//开启相机
	m_pLCamera->start();
}
//设置右相机
void StereoCameraView::setRCamera(const QCameraDevice &cameraDevice)
{
	m_pRCamera.reset(new QCamera(cameraDevice));
	m_pRImageCapture.reset(new QImageCapture);
	m_pRSession.reset(new QMediaCaptureSession);
	m_pRSession->setCamera(m_pRCamera.data());
	m_pRSession->setImageCapture(m_pRImageCapture.data());
	m_pRSession->setVideoSink(ui.viewfinder_R->videoSink());
	refreshResAndCodecListR();
	//开启相机
	m_pRCamera->start();
}

void StereoCameraView::refreshResAndCodecListL()
{
	ui.comboBox_LCodec->clear();
	ui.comboBox_LCodec->addItem(tr("Default image format"), QVariant(QString()));
	// Qt6: QImageCapture 不再暴露 supportedImageCodecs() — 编解码器选择已移除
	ui.comboBox_Lresolution->clear();
	ui.comboBox_Lresolution->addItem(tr("Default Resolution"));
	const QList<QSize> supportedResolutions = m_pLCamera->cameraDevice().photoResolutions();
	for (const QSize &resolution : supportedResolutions) {
		ui.comboBox_Lresolution->addItem(QString("%1x%2").arg(resolution.width()).arg(resolution.height()),
			QVariant(resolution));
	}
	ui.horizontalSlider_LQuality->setRange(0, int(QImageCapture::VeryHighQuality));
}

void StereoCameraView::refreshResAndCodecListR()
{
	ui.comboBox_RCodec->clear();
	ui.comboBox_RCodec->addItem(tr("Default image format"), QVariant(QString()));
	// Qt6: QImageCapture 不再暴露 supportedImageCodecs() — 编解码器选择已移除
	ui.comboBox_Rresolution->clear();
	ui.comboBox_Rresolution->addItem(tr("Default Resolution"));
	const QList<QSize> supportedResolutions = m_pRCamera->cameraDevice().photoResolutions();
	for (const QSize &resolution : supportedResolutions) {
		ui.comboBox_Rresolution->addItem(QString("%1x%2").arg(resolution.width()).arg(resolution.height()),
			QVariant(resolution));
	}
	ui.horizontalSlider_RQuality->setRange(0, int(QImageCapture::VeryHighQuality));
}

QVariant StereoCameraView::boxValue(const QComboBox* box) const
{
	int idx = box->currentIndex();
	if (idx == -1)
		return QVariant();

	return box->itemData(idx);
}

void StereoCameraView::closeEvent(QCloseEvent* e)
{
	m_pLCamera->stop();
	m_pRCamera->stop();
}

void StereoCameraView::OnFindSavePath()
{
	QFileDialog * fileDialog2 = new QFileDialog();
	fileDialog2->setWindowTitle(QStringLiteral("请选择保存位置"));
	//fileDialog2->setNameFilter(QStringLiteral("点云文件(*.xml *.yml *.yaml)"));
	fileDialog2->setFileMode(QFileDialog::Directory);
	fileDialog2->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	if (fileDialog2->exec() == QDialog::Accepted)
	{
		saveToHere = fileDialog2->selectedFiles().at(0);
		ui.lineEdit_SaveTo->setText(saveToHere);
	}
}

//拍照
void StereoCameraView::OnShot()
{
	QString idt=QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
	m_pLImageCapture->captureToFile(ui.lineEdit_SaveTo->text() + "/L" + idt + ".jpg");
	m_pRImageCapture->captureToFile(ui.lineEdit_SaveTo->text() + "/R" + idt +".jpg");
	ui.lcdNumber->display(ui.lcdNumber->intValue() + 1);
}

void StereoCameraView::OnCloseCamera()
{
	m_pLCamera->stop();
	m_pRCamera->stop();
	ui.pushButton_Shot->setEnabled(false);
	ui.pushButton_OpenCamera->setEnabled(true);
	ui.pushButton_CloseCamera->setEnabled(false);
}

void StereoCameraView::OnOpenCamera()
{
	ui.pushButton_Shot->setEnabled(true);
	ui.pushButton_CloseCamera->setEnabled(true);
	ui.pushButton_OpenCamera->setEnabled(false);
	ui.comboBox_Lcam->setCurrentIndex(0);
	ui.comboBox_Lcam->setCurrentIndex(1);
	setLCamera(ui.comboBox_Lcam->currentData().value<QCameraDevice>());
	setRCamera(ui.comboBox_Rcam->currentData().value<QCameraDevice>());
}

void StereoCameraView::OnValueChanged_LExposureCompensation(int value)
{
	m_pLCamera->setExposureCompensation(value*0.5);
}

void StereoCameraView::OnValueChanged_RExposureCompensation(int value)
{
	m_pRCamera->setExposureCompensation(value*0.5);
}

void StereoCameraView::OnValueChanged_LQuality(int value)
{
	m_pLImageCapture->setQuality(QImageCapture::Quality(ui.horizontalSlider_LQuality->value()));
}

void StereoCameraView::OnValueChanged_RQuality(int value)
{
	m_pRImageCapture->setQuality(QImageCapture::Quality(ui.horizontalSlider_RQuality->value()));
}

void StereoCameraView::OnSelectedChanged_LCameraDevice(QString value)
{
	setLCamera(ui.comboBox_Lcam->currentData().value<QCameraDevice>());
}

void StereoCameraView::OnSelectedChanged_RCameraDevice(QString value)
{
	setRCamera(ui.comboBox_Rcam->currentData().value<QCameraDevice>());
}

void StereoCameraView::OnSelectedChanged_LResolution(QString value)
{
	m_pLImageCapture->setResolution(boxValue(ui.comboBox_Lresolution).toSize());
}

void StereoCameraView::OnSelectedChanged_RResolution(QString value)
{
	m_pRImageCapture->setResolution(boxValue(ui.comboBox_Rresolution).toSize());
}

void StereoCameraView::OnSelectedChanged_LCodec(QString value)
{
	// Qt6: QImageCapture 不再暴露编解码器 API — 槽保留为空以保持 UI 兼容
	Q_UNUSED(value);
}

void StereoCameraView::OnSelectedChanged_RCodec(QString value)
{
	// Qt6: QImageCapture 不再暴露编解码器 API — 槽保留为空以保持 UI 兼容
	Q_UNUSED(value);
}

