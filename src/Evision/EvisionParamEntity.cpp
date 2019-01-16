#include "EvisionParamEntity.h"

//构造函数是私有的
EvisionParamEntity::EvisionParamEntity(QObject * parent) : QObject(parent)
{ 
}

//获取实例(单例模式)
EvisionParamEntity * EvisionParamEntity::getInstance()
{
     static EvisionParamEntity *m_pInstance;
     if (m_pInstance == NULL) //判断是否第一次调用
         m_pInstance = new EvisionParamEntity();
     return m_pInstance;
}

EvisionParamEntity::~EvisionParamEntity()
{
}

float EvisionParamEntity::getDistance()
{
	return Distance;
}
void EvisionParamEntity::setDistance(float value)
{
	Distance = value;
	emit paramChanged_distance();
}

//cv::Mat EvisionParamEntity::getImageLtoShow()
//{
//	return imgLtoShow;
//}
//void EvisionParamEntity::setImageLtoShow(cv::Mat value)
//{
//	imgLtoShow = value;
//	emit paramChanged_ImageLtoShow();
//}

//cv::Mat EvisionParamEntity::getImageRtoShow()
//{
//	return imgRtoShow;
//}
//void EvisionParamEntity::setImageRtoShow(cv::Mat value)
//{
//	imgRtoShow = value;
//	emit paramChanged_ImageRtoShow();
//}

//cv::Mat EvisionParamEntity::getImageDtoShow()
//{
//	return imgDtoShow;
//}
//
//void EvisionParamEntity::setImageDtoShow(cv::Mat value)
//{
//	imgDtoShow = value;
//	emit paramChanged_ImageDtoShow();
//}

QString EvisionParamEntity::getStatusBarText()
{
	return StatusBarText;
}
void EvisionParamEntity::setStatusBarText(QString value=QStringLiteral("就绪"))
{
	StatusBarText = value;
	emit paramChanged_StatusBar();
}

cv::Mat EvisionParamEntity::getDisparity()
{
	return disparity;
}

void EvisionParamEntity::setDisparity(cv::Mat value)
{
	disparity = value;
}

cv::Mat EvisionParamEntity::getXYZ()
{
	return xyz;
}

void EvisionParamEntity::setXYZ(cv::Mat value)
{
	xyz = value;
}

cv::Mat EvisionParamEntity::getQ()
{
	return Q;
}

void EvisionParamEntity::setQ(cv::Mat value)
{
	Q = value;
}
