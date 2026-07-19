#pragma once

#include <QWidget>
#include "ui_CameraView.h"
#include <QCamera>
#include <QImageCapture>
#include <QCameraDevice>
#include <QMediaCaptureSession>
#include <QScopedPointer>
class CameraView : public QWidget
{
	Q_OBJECT

public:
	CameraView(QWidget *parent = Q_NULLPTR);
	~CameraView();

private:
	Ui::CameraView ui;
	QScopedPointer<QCamera> m_pCamera;
	QScopedPointer<QImageCapture> m_pImageCapture;
	QScopedPointer<QMediaCaptureSession> m_pSession;
	QString saveToHere;
private:
	void setCamera(const QCameraDevice &cameraDevice);
	void refreshResAndCodecList();
	QVariant boxValue(const QComboBox *box) const;
	void closeEvent(QCloseEvent * e) override;
private slots:
	void OnFindSavePath();
	void OnCameraPowerOn();
	void OnCameraPowerOff();
	void OnFocus();
	void OnShot();
	void OnValueChanged_ExposureCompensation(int value);
	void OnValueChanged_Quality(int value);
	void OnSelectedChanged_CameraDevice(QString value);
	void OnSelectedChanged_Resolution(QString value);
	void OnSelectedChanged_Codec(QString value);


};
