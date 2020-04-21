#include "ObjectDetectionEntity.h"



ObjectDetectionEntity::ObjectDetectionEntity()
{
	//构造函数
	cfgFilename="";
	weightsFilename="";
	namesFilename="";
	RunningState = true;
}

cv::Mat ObjectDetectionEntity::getDetectionPlayer()
{
	return DetectionPlayer;
}

void ObjectDetectionEntity::setDetectionPlayer(cv::Mat value)
{
	DetectionPlayer = value;
	emit paramChanged_DetectionPlayer();
}

QString ObjectDetectionEntity::getCfgFilename()
{
	return cfgFilename;
}

void ObjectDetectionEntity::setCfgFilename(QString value)
{
	cfgFilename = value;
	emit paramChanged_cfgFilename();
}

QString ObjectDetectionEntity::getweightsFilename()
{
	return weightsFilename;
}

void ObjectDetectionEntity::setweightsFilename(QString value)
{
	weightsFilename = value;
	emit paramChanged_weightsFilename();
}

QString ObjectDetectionEntity::getnamesFilename()
{
	return namesFilename;
}

void ObjectDetectionEntity::setnamesFilename(QString value)
{
	namesFilename = value;
	emit paramChanged_namesFilename();
}

bool ObjectDetectionEntity::getRunningState()
{
	return RunningState;
}

void ObjectDetectionEntity::setRunningState(bool value)
{
	RunningState = value;
	emit paramChanged_RunningState();
}


ObjectDetectionEntity *ObjectDetectionEntity::getInstance()
{
	static ObjectDetectionEntity *m_pInstance;
	if (m_pInstance == NULL) //判断是否第一次调用
		m_pInstance = new ObjectDetectionEntity();
	return m_pInstance;
}

ObjectDetectionEntity::~ObjectDetectionEntity()
{
}
