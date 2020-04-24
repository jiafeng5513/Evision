#pragma once
#include <qobject.h>
/*
 * 参数实体类
 * 对数值的直接更改会发出valuechanged事件,由view类接到消息,然后更新界面
 * 
 */
class EvisionParamEntity : public QObject
{
	Q_OBJECT
	
private:
	EvisionParamEntity(QObject *parent = 0);
	QString StatusBarText="";

public:
	static EvisionParamEntity * getInstance();
	~EvisionParamEntity();
	QString getStatusBarText();
	void setStatusBarText(QString value);

signals:
	void paramChanged_StatusBar();
};

