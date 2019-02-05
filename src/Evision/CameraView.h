#pragma once

#include <QWidget>
#include "ui_CameraView.h"
#include <QtMultimedia/QCamera>
#include <QtMultimedia/QCameraImageCapture>
#include <QtMultimedia/QMediaRecorder>
#include <QtMultimedia/QCameraInfo>
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
	QScopedPointer<QCameraImageCapture> m_pImageCapture;
	QString saveToHere;
private:
	void setCamera(QCameraInfo *cameraInfo);
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
