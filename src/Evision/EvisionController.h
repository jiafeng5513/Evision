#pragma once
#include "EvisionParamEntity.h"
#include <qstringlist.h>

class EvisionController: public QObject
{
	Q_OBJECT
private:
	EvisionParamEntity * m_entity;
	QStringList ImageListL, ImageListR;//从图片标定时需要的两组图片
	QString ImageL, ImageR, insFile, extFile;
	cv::Mat depth;
public:
	EvisionController(QObject *parent = Q_NULLPTR);
	~EvisionController();
	void setDefaultCalibParamCommand();
	void CalibrateCommand();
	void setDefaultMatchParamCommand();
	void MatchCommand();
	void RefreshStereoMatchCommand();
	void getDistanceCommand();
	void ShowPointCloudCommand();
	void openCameraCommand();
	void openStereoCameraCommand();
public slots:
	void onOpenMessageBox(QString title, QString msg);
};

