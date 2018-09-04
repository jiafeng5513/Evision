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

	//QActionGroup *videoDevicesGroup = new QActionGroup(this);
	//videoDevicesGroup->setExclusive(true);
	//const QList<QCameraInfo> availableCameras = QCameraInfo::availableCameras();
	//for (const QCameraInfo &cameraInfo : availableCameras) {
	//	QAction *videoDeviceAction = new QAction(cameraInfo.description(), videoDevicesGroup);
	//	videoDeviceAction->setCheckable(true);
	//	videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
	//	if (cameraInfo == QCameraInfo::defaultCamera())
	//		videoDeviceAction->setChecked(true);

	//	ui->menuDevices->addAction(videoDeviceAction);
	//}

	//connect(videoDevicesGroup, &QActionGroup::triggered, this, &Camera::updateCameraDevice);
	//connect(ui->captureWidget, &QTabWidget::currentChanged, this, &Camera::updateCaptureMode);

	//setCamera(QCameraInfo::defaultCamera());
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



