#pragma once

#include <QWidget>
#include "ui_StereoCameraView.h"
#include <QCamera>
#include <QImageCapture>
#include <QCameraDevice>
#include <QMediaCaptureSession>
#include <QScopedPointer>

class StereoCameraView : public QWidget
{
	Q_OBJECT

public:
	StereoCameraView(QWidget *parent = Q_NULLPTR);
	~StereoCameraView();

private:
	Ui::StereoCameraView ui;
	QScopedPointer<QCamera> m_pLCamera;
	QScopedPointer<QCamera> m_pRCamera;
	QScopedPointer<QImageCapture> m_pLImageCapture;
	QScopedPointer<QImageCapture> m_pRImageCapture;
	QScopedPointer<QMediaCaptureSession> m_pLSession;
	QScopedPointer<QMediaCaptureSession> m_pRSession;
	QString saveToHere;
private:
	void setLCamera(const QCameraDevice &cameraDevice);
	void setRCamera(const QCameraDevice &cameraDevice);
	void refreshResAndCodecListL();
	void refreshResAndCodecListR();
	QVariant boxValue(const QComboBox *box) const;
	void closeEvent(QCloseEvent * e) override;
private slots:
	void OnFindSavePath();
	void OnShot();
	void OnCloseCamera();
	void OnOpenCamera();

	void OnValueChanged_LExposureCompensation(int value);
	void OnValueChanged_LQuality(int value);
	void OnSelectedChanged_LCameraDevice(QString value);
	void OnSelectedChanged_LResolution(QString value);
	void OnSelectedChanged_LCodec(QString value);

	void OnValueChanged_RExposureCompensation(int value);
	void OnValueChanged_RQuality(int value);
	void OnSelectedChanged_RCameraDevice(QString value);
	void OnSelectedChanged_RResolution(QString value);
	void OnSelectedChanged_RCodec(QString value);
};
