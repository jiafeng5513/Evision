#include "Camera.h"
#include <QMessageBox>
#include <QPalette>
#include <QMediaMetaData>
#include <QtWidgets>


Camera::Camera(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//Camera devices:



	const QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();
	for (const QCameraInfo &cameraInfo : availableCameras) {
		ui.comboBox_CameraDevice->addItem(cameraInfo.description(),QVariant::fromValue(cameraInfo));
	}



	connect(videoDevicesGroup, &QActionGroup::triggered, this, &Camera::updateCameraDevice);
	connect(ui->captureWidget, &QTabWidget::currentChanged, this, &Camera::updateCaptureMode);

	setCamera(QCameraInfo::defaultCamera());
}

Camera::~Camera()
{
}

void Camera::OnFindSavePath()
{
}

void Camera::OnCameraPowerOn()
{
}

void Camera::OnCameraPowerOff()
{
}

void Camera::OnFocus()
{
}

void Camera::OnShot()
{
}

void Camera::OnValueChanged_ExposureCompensation(int value)
{
}

void Camera::OnValueChanged_Quality(int value)
{
}

void Camera::OnSelectedChanged_CameraDevice(QString value)
{
}

void Camera::OnSelectedChanged_Resolution(QString value)
{
}

void Camera::OnSelectedChanged_Codec(QString value)
{
}



