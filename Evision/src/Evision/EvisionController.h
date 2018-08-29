#pragma once
#include "EvisionParamEntity.h"
#include <qstringlist.h>

class EvisionController
{
private:
	EvisionParamEntity * m_entity;
	QStringList ImageListL, ImageListR;//从图片标定时需要的两组图片
public:
	EvisionController();
	~EvisionController();
	void setDefaultCalibParamCommand();
	void CalibrateCommand();
	void setDefaultMatchParamCommand();
	void MatchCommand();
};

