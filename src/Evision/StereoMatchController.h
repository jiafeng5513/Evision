#pragma once

#include <QObject>
#include "StereoMatchParamEntity.h"
#include "StereoMatch.h"

class StereoMatchController : public QObject
{
	Q_OBJECT

private:
	StereoMatchParamEntity * m_entity;
	StereoMatch *_stereoMatch;
	QString ImageL, ImageR, paramsFile;
public:
	StereoMatchController(QObject *parent=0);
	~StereoMatchController();

	void setDefaultMatchParamCommand();
	void MatchCommand();
	void RefreshStereoMatchCommand();
	void SaveCommand();
public slots:
	void onOpenMessageBox(QString title, QString msg);
};
