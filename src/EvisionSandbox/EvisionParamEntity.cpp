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

QString EvisionParamEntity::getStatusBarText()
{
	return StatusBarText;
}
void EvisionParamEntity::setStatusBarText(QString value=QStringLiteral("就绪"))
{
	StatusBarText = value;
	emit paramChanged_StatusBar();
}