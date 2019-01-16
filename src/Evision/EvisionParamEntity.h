#pragma once
#include <qobject.h>
#include <core/core.hpp>
/*
 * 参数实体类
 * 对数值的直接更改会发出valuechanged事件,由view类接到消息,然后更新界面
 * 
 */
class EvisionParamEntity : public QObject
{
	Q_OBJECT
public:
	static EvisionParamEntity * getInstance();
	~EvisionParamEntity();
private:
	EvisionParamEntity(QObject *parent = 0);
private:
#pragma region params

	float Distance=0.0f;

	QString StatusBarText="";

	cv::Mat disparity;
	cv::Mat xyz;
	cv::Mat Q;
#pragma endregion 

	
#pragma region param_Changed_signals
signals:

	void paramChanged_distance();
	void paramChanged_StatusBar();
#pragma endregion 

public:
#pragma region getter And setter

	float getDistance();
	void setDistance(float value);

	QString getStatusBarText();
	void setStatusBarText(QString value);

	cv::Mat getDisparity();
	void setDisparity(cv::Mat value);

	cv::Mat getXYZ();
	void setXYZ(cv::Mat value);

	cv::Mat getQ();
	void setQ(cv::Mat value);

#pragma endregion 
};

