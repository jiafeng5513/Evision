#pragma once
#include "EvisionParamEntity.h"
#include <qstringlist.h>

class EvisionController: public QObject
{
	Q_OBJECT
private:
	EvisionParamEntity * m_entity;
	QStringList ImageListL, ImageListR;//从图片标定时需要的两组图片
public:
	EvisionController(QObject *parent = Q_NULLPTR);
	~EvisionController();
	void setDefaultCalibParamCommand();
	void CalibrateCommand();
	void setDefaultMatchParamCommand();
	void MatchCommand();
public slots:
	void onOpenMessageBox(QString title, QString msg);
};

