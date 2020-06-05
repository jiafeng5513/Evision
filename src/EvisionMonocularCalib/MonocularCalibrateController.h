#pragma once

#include <QObject>
#include "MonocularCalibrateParamEntity.h"
#include "MonocularCalibrate.h"

class MonocularCalibrateController : public QObject
{
	Q_OBJECT
private:
	QStringList ImageListL;//从图片标定时需要的图片
	MonocularCalibrateParamEntity * m_calib_entity;
	QString ImageL, insFile, extFile;
	MonocularCalibrate * _stereoCalib;
public:
	MonocularCalibrateController(QObject *parent = Q_NULLPTR);
	~MonocularCalibrateController();
	void setDefaultCalibParamCommand();
	void CalibrateCommand();
	void SaveParamsToFileCommand();
public slots:
	void onOpenMessageBox(QString title, QString msg);
};
