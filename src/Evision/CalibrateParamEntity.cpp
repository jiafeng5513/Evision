#include "CalibrateParamEntity.h"

CalibrateParamEntity::CalibrateParamEntity(QObject *parent)
	: QObject(parent)
{
}

CalibrateParamEntity* CalibrateParamEntity::getInstance()
{
	static CalibrateParamEntity *m_pInstance;
	if (m_pInstance == NULL) //判断是否第一次调用
		m_pInstance = new CalibrateParamEntity();
	return m_pInstance;
}

CalibrateParamEntity::~CalibrateParamEntity()
{
}

int CalibrateParamEntity::getBoardWidth()
{
	return BoardWidth;
}

void CalibrateParamEntity::setBoardWidth(int value)
{
	BoardWidth = value;
	//发出值更改事件
	emit paramChanged_BoardWidth();
}

int CalibrateParamEntity::getBoardHeight()
{
	return BoardHeight;
}

void CalibrateParamEntity::setBoardHeight(int value)
{
	BoardHeight = value;
	emit paramChanged_BoardHeight();
}

int CalibrateParamEntity::getSquareSize()
{
	return SquareSize;
}

void CalibrateParamEntity::setSquareSize(int value)
{
	SquareSize = value;
	emit paramChanged_SquareSize();
}

bool CalibrateParamEntity::getshowRectified()
{
	return showRectified;
}

void CalibrateParamEntity::setshowRectified(bool value)
{
	showRectified = value;
	emit paramChanged_showRectified();
}

bool CalibrateParamEntity::getBouguet()
{
	return Bouguet;
}

void CalibrateParamEntity::setBouguet(bool value)
{
	Bouguet = value;
	if (value == true)
	{
		Hartley = false;
	}
	emit paramChanged_Bouguet();
}

bool CalibrateParamEntity::getHartley()
{
	return Hartley;
}

void CalibrateParamEntity::setHartley(bool value)
{
	Hartley = value;
	if (value)
	{
		Bouguet = false;
	}
	emit paramChanged_Hartley();
}

cv::Mat CalibrateParamEntity::getImageLtoShow()
{
	return imgLtoShow;
}

void CalibrateParamEntity::setImageLtoShow(cv::Mat value)
{
	imgLtoShow = value;
	emit paramChanged_ImageLtoShow();
}

cv::Mat CalibrateParamEntity::getImageRtoShow()
{
	return imgRtoShow;
}

void CalibrateParamEntity::setImageRtoShow(cv::Mat value)
{
	imgRtoShow = value;
	emit paramChanged_ImageRtoShow();
}

QString CalibrateParamEntity::getmsgBuffer()
{
	return msgBuffer;
}

void CalibrateParamEntity::setmsgBuffer(QString value)
{
	msgBuffer = value;
	emit paramChanged_msgBuffer();
}
