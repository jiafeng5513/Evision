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
//
int EvisionParamEntity::getBoardWidth()
{
	return BoardWidth;
}
void EvisionParamEntity::setBoardWidth(int value)
{
	BoardWidth = value;
	//发出值更改事件
	emit paramChanged_BoardWidth();
}

int EvisionParamEntity::getBoardHeight()
{
	return BoardHeight;
}
void EvisionParamEntity::setBoardHeight(int value)
{
	BoardHeight = value;
	emit paramChanged_BoardHeight();
}

int EvisionParamEntity::getSquareSize()
{
	return SquareSize;
}
void EvisionParamEntity::setSquareSize(int value)
{
	SquareSize = value;
	emit paramChanged_SquareSize();
}

bool EvisionParamEntity::getshowRectified()
{
	return showRectified;
}
void EvisionParamEntity::setshowRectified(bool value)
{
	showRectified = value;
	emit paramChanged_showRectified();
}

bool EvisionParamEntity::getBouguet()
{
	return Bouguet;
}
void EvisionParamEntity::setBouguet(bool value)
{
	Bouguet = value;
	if (value==true)
	{
		Hartley = false;
	}
	emit paramChanged_Bouguet();
}

bool EvisionParamEntity::getHartley()
{
	return Hartley;
}
void EvisionParamEntity::setHartley(bool value)
{
	Hartley = value;
	if (value)
	{
		Bouguet = false;
	}
	emit paramChanged_Hartley();
}

int EvisionParamEntity::getMinDisp()
{
	return MinDisp;
}
void EvisionParamEntity::setMinDisp(int value)
{
	MinDisp = value;
	emit paramChanged_MinDisp();
}

int EvisionParamEntity::getUniradio()
{
	return Uniradio;
}
void EvisionParamEntity::setUniradio(int value)
{
	Uniradio = value;
	emit paramChanged_Uniradio();
}

int EvisionParamEntity::getSpecwinsz()
{
	return Specwinsz;
}
void EvisionParamEntity::setSpecwinsz(int value)
{
	Specwinsz = value;
	emit paramChanged_Specwinsz();
}

int EvisionParamEntity::getMaxDisp()
{
	return MaxDisp;
}
void EvisionParamEntity::setMaxDisp(int value)
{
	MaxDisp = value;
	emit paramChanged_MaxDisp();
}

int EvisionParamEntity::getSpecrange()
{
	return Specrange;
}
void EvisionParamEntity::setSpecrange(int value)
{
	Specrange = value;
	emit paramChanged_Specrange();
}

int EvisionParamEntity::getPrefilcap()
{
	return Prefilcap;
}
void EvisionParamEntity::setPrefilcap(int value)
{
	Prefilcap = value;
	emit paramChanged_Prefilcap();
}

int EvisionParamEntity::getSadWinsz()
{
	return SadWinsz;
}
void EvisionParamEntity::setSadWinsz(int value)
{
	SadWinsz = value;
	emit paramChanged_SadWinsz();
}

int EvisionParamEntity::getTextThread()
{
	return TextThread;
}
void EvisionParamEntity::setTextThread(int value)
{
	TextThread = value;
	emit paramChanged_TextThread();
}

int EvisionParamEntity::getMaxdifdisp12()
{
	return Maxdifdisp12;
}
void EvisionParamEntity::setMaxdifdisp12(int value)
{
	Maxdifdisp12 = value;
	emit paramChanged_Maxdifdisp12();
}

bool EvisionParamEntity::getBM()
{
	return BM;
}
void EvisionParamEntity::setBM(bool value)
{
	BM = value;
	if (value)
	{
		SGBM = false;
		VAR = false;
	}
	emit paramChanged_BM();
}

bool EvisionParamEntity::getSGBM()
{
	return SGBM;
}
void EvisionParamEntity::setSGBM(bool value)
{
	SGBM = value;
	if (value)
	{
		BM = false;
		VAR = false;
	}
	emit paramChanged_SGBM();
}

bool EvisionParamEntity::getVAR()
{
	return VAR;
}
void EvisionParamEntity::setVAR(bool value)
{
	VAR = value;
	if (value)
	{
		BM = false;
		SGBM = false;
	}
	emit paramChanged_VAR();
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

cv::Mat EvisionParamEntity::getImageLtoShow()
{
	return imgLtoShow;
}
void EvisionParamEntity::setImageLtoShow(cv::Mat value)
{
	imgLtoShow = value;
	emit paramChanged_ImageLtoShow();
}

cv::Mat EvisionParamEntity::getImageRtoShow()
{
	return imgRtoShow;
}
void EvisionParamEntity::setImageRtoShow(cv::Mat value)
{
	imgRtoShow = value;
	emit paramChanged_ImageRtoShow();
}

cv::Mat EvisionParamEntity::getImageDtoShow()
{
	return imgDtoShow;
}

void EvisionParamEntity::setImageDtoShow(cv::Mat value)
{
	imgDtoShow = value;
	emit paramChanged_ImageDtoShow();
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
