#include "ParamEntity.h"

//构造函数是私有的
ParamEntity::ParamEntity()
{
}

//获取实例(单例模式)
ParamEntity * ParamEntity::getInstance()
{
     static ParamEntity *m_pInstance;
     if (m_pInstance == NULL) //判断是否第一次调用
         m_pInstance = new ParamEntity();
     return m_pInstance;
}

ParamEntity::~ParamEntity()
{
}
//
int ParamEntity::getBoardWidth()
{
	return BoardWidth;
}
void ParamEntity::setBoardWidth(int value)
{
	BoardWidth = value;
	//发出值更改事件
	emit paramChanged_BoardWidth();
}

int ParamEntity::getBoardHeight()
{
	return BoardHeight;
}
void ParamEntity::setBoardHeight(int value)
{
	BoardHeight = value;
	emit paramChanged_BoardHeight();
}

int ParamEntity::getSquareSize()
{
	return SquareSize;
}
void ParamEntity::setSquareSize(int value)
{
	SquareSize = value;
	emit paramChanged_SquareSize();
}

int ParamEntity::getAlpha()
{
	return Alpha;
}
void ParamEntity::setAlpha(int value)
{
	Alpha = value;
	emit paramChanged_Alpha();
}

int ParamEntity::getnBoards()
{
	return nBoards;
}
void ParamEntity::setnBoards(int value)
{
	nBoards = value;
	emit paramChanged_nBoards();
}

bool ParamEntity::getFI()
{
	return FI;
}
void ParamEntity::setFI(bool value)
{
	FI = value;
	emit paramChanged_FI();
}

bool ParamEntity::getUIG()
{
	return UIG;
}
void ParamEntity::setUIG(bool value)
{
	UIG = value;
	emit paramChanged_UIG();
}

bool ParamEntity::getSFL()
{
	return SFL;
}
void ParamEntity::setSFL(bool value)
{
	SFL = value;
	emit paramChanged_SFL();
}

bool ParamEntity::getFPP()
{
	return FPP;
}
void ParamEntity::setFPP(bool value)
{
	FPP = value;
	emit paramChanged_FPP();
}

bool ParamEntity::getFAR()
{
	return FAR;
}
void ParamEntity::setFAR(bool value)
{
	FAR = value;
	emit paramChanged_FAR();
}

bool ParamEntity::getBouguet()
{
	return Bouguet;
}
void ParamEntity::setBouguet(bool value)
{
	Bouguet = value;
	if (value==true)
	{
		Hartley = false;
	}
	emit paramChanged_Bouguet();
}

bool ParamEntity::getHartley()
{
	return Hartley;
}
void ParamEntity::setHartley(bool value)
{
	Hartley = value;
	if (value)
	{
		Bouguet = false;
	}
	emit paramChanged_Hartley();
}

int ParamEntity::getMinDisp()
{
	return MinDisp;
}
void ParamEntity::setMinDisp(int value)
{
	MinDisp = value;
	emit paramChanged_MinDisp();
}

int ParamEntity::getUniradio()
{
	return Uniradio;
}
void ParamEntity::setUniradio(int value)
{
	Uniradio = value;
	emit paramChanged_Uniradio();
}

int ParamEntity::getSpecwinsz()
{
	return Specwinsz;
}
void ParamEntity::setSpecwinsz(int value)
{
	Specwinsz = value;
	emit paramChanged_Specwinsz();
}

int ParamEntity::getMaxDisp()
{
	return MaxDisp;
}
void ParamEntity::setMaxDisp(int value)
{
	MaxDisp = value;
	emit paramChanged_MaxDisp();
}

int ParamEntity::getSpecrange()
{
	return Specrange;
}
void ParamEntity::setSpecrange(int value)
{
	Specrange = value;
	emit paramChanged_Specrange();
}

int ParamEntity::getPrefilcap()
{
	return Prefilcap;
}
void ParamEntity::setPrefilcap(int value)
{
	Prefilcap = value;
	emit paramChanged_Prefilcap();
}

int ParamEntity::getSadWinsz()
{
	return SadWinsz;
}
void ParamEntity::setSadWinsz(int value)
{
	SadWinsz = value;
	emit paramChanged_SadWinsz();
}

int ParamEntity::getTextThread()
{
	return TextThread;
}
void ParamEntity::setTextThread(int value)
{
	TextThread = value;
	emit paramChanged_TextThread();
}

int ParamEntity::getMaxdifdisp12()
{
	return Maxdifdisp12;
}
void ParamEntity::setMaxdifdisp12(int value)
{
	Maxdifdisp12 = value;
	emit paramChanged_Maxdifdisp12();
}

int ParamEntity::getLevels()
{
	return Levels;
}
void ParamEntity::setLevels(int value)
{
	Levels = value;
	paramChanged_Levels();
}

float ParamEntity::getPyrScale()
{
	return PyrScale;
}
void ParamEntity::setPyrScale(float value)
{
	PyrScale = value;
	emit paramChanged_pyrScale();
}

int ParamEntity::getPolyN()
{
	return PolyN;
}
void ParamEntity::setPolyN(int value)
{
	PolyN = value;
	emit paramChanged_PolyN();
}

float ParamEntity::getPolySigma()
{
	return PolySigma;
}
void ParamEntity::setPolySigma(float value)
{
	PolySigma = value;
	emit paramChanged_PolySigma();
}

float ParamEntity::getFi()
{
	return Fi;
}
void ParamEntity::setFi(float value)
{
	Fi = value;
	emit paramChanged_Fi();
}

float ParamEntity::getLambda()
{
	return Lambda;
}
void ParamEntity::setLambda(float value)
{
	Lambda = value;
	emit paramChanged_Lambda();
}

bool ParamEntity::getBM()
{
	return BM;
}
void ParamEntity::setBM(bool value)
{
	BM = value;
	if (value)
	{
		SGBM = false;
		VAR = false;
	}
	emit paramChanged_BM();
}

bool ParamEntity::getSGBM()
{
	return SGBM;
}
void ParamEntity::setSGBM(bool value)
{
	SGBM = value;
	if (value)
	{
		BM = false;
		VAR = false;
	}
	emit paramChanged_SGBM();
}

bool ParamEntity::getVAR()
{
	return VAR;
}
void ParamEntity::setVAR(bool value)
{
	VAR = value;
	if (value)
	{
		BM = false;
		SGBM = false;
	}
	emit paramChanged_VAR();
}

float ParamEntity::getDistance()
{
	return Distance;
}
void ParamEntity::setDistance(float value)
{
	Distance = value;
	emit paramChanged_distance();
}
