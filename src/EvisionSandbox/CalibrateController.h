#pragma once

#include <QObject>
#include "CalibrateParamEntity.h"
#include "StereoCalibrate.h"

class CalibrateController : public QObject
{
	Q_OBJECT
private:
	QStringList ImageListL, ImageListR;//从图片标定时需要的两组图片
	CalibrateParamEntity * m_calib_entity;
	QString ImageL, ImageR, insFile, extFile;
	StereoCalibrate * _stereoCalib;
public:
	CalibrateController(QObject *parent = Q_NULLPTR);
	~CalibrateController();
	void setDefaultCalibParamCommand();
	void CalibrateCommand();
	void SaveParamsToFileCommand();
public slots:
	void onOpenMessageBox(QString title, QString msg);
};
