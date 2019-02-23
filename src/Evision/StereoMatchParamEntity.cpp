#include "StereoMatchParamEntity.h"

StereoMatchParamEntity::StereoMatchParamEntity(QObject *parent)
	: QObject(parent)
{
}

StereoMatchParamEntity* StereoMatchParamEntity::getInstance()
{
	static StereoMatchParamEntity * m_pInstance;
	if (m_pInstance == NULL) //判断是否第一次调用
		m_pInstance = new StereoMatchParamEntity();
	return m_pInstance;
}

StereoMatchParamEntity::~StereoMatchParamEntity()
{
}

int StereoMatchParamEntity::getUniradio()
{
	return Uniradio;
}
void StereoMatchParamEntity::setUniradio(int value)
{
	Uniradio = value;
	emit paramChanged_Uniradio();
}

int StereoMatchParamEntity::getPrefilcap()
{
	return Prefilcap;
}
void StereoMatchParamEntity::setPrefilcap(int value)
{
	Prefilcap = value;
	emit paramChanged_Prefilcap();
}

int StereoMatchParamEntity::getSpecwinsz()
{
	return Specwinsz;
}
void StereoMatchParamEntity::setSpecwinsz(int value)
{
	Specwinsz = value;
	emit paramChanged_Specwinsz();
}

int StereoMatchParamEntity::getSadWinsz()
{
	return SadWinsz;
}
void StereoMatchParamEntity::setSadWinsz(int value)
{
	SadWinsz = value;
	emit paramChanged_SadWinsz();
}

int StereoMatchParamEntity::getMinDisp()
{
	return MinDisp;
}
void StereoMatchParamEntity::setMinDisp(int value)
{
	MinDisp = value;
	emit paramChanged_MinDisp();
}

int StereoMatchParamEntity::getTextThread()
{
	return TextThread;
}
void StereoMatchParamEntity::setTextThread(int value)
{
	TextThread = value;
	emit paramChanged_TextThread();
}

int StereoMatchParamEntity::getNumDisparities()
{
	return NumDisparities;
}
void StereoMatchParamEntity::setNumDisparities(int value)
{
	NumDisparities = value;
	emit paramChanged_NumDisparities();
}

int StereoMatchParamEntity::getSpecrange()
{
	return Specrange;
}
void StereoMatchParamEntity::setSpecrange(int value)
{
	Specrange = value;
	emit paramChanged_Specrange();
}

int StereoMatchParamEntity::getMaxdifdisp12()
{
	return Maxdifdisp12;
}
void StereoMatchParamEntity::setMaxdifdisp12(int value)
{
	Maxdifdisp12 = value;
	emit paramChanged_Maxdifdisp12();
}

bool StereoMatchParamEntity::getBM()
{
	return BM;
}
void StereoMatchParamEntity::setBM(bool value)
{
	BM = value;
	if (value)
	{
		SGBM = false;
	}
	emit paramChanged_BM();
}

bool StereoMatchParamEntity::getSGBM()
{
	return SGBM;
}
void StereoMatchParamEntity::setSGBM(bool value)
{
	SGBM = value;
	if (value)
	{
		BM = false;
	}
	emit paramChanged_SGBM();
}

bool StereoMatchParamEntity::getMODE_HH()
{
	return MODE_HH;
}
void StereoMatchParamEntity::setMODE_HH(bool value)
{
	MODE_HH = value;
	if (value)
	{
		MODE_SGBM = false;
		MODE_3WAY = false;
	}
	emit paramChanged_MODE_HH();
}

bool StereoMatchParamEntity::getMODE_SGBM()
{
	return MODE_SGBM;
}
void StereoMatchParamEntity::setMODE_SGBM(bool value)
{
	MODE_SGBM = value;
	if (value)
	{
		MODE_HH = false;
		MODE_3WAY = false;
	}
	emit paramChanged_MODE_SGBM();
}

bool StereoMatchParamEntity::getMODE_3WAY()
{
	return MODE_3WAY;
}
void StereoMatchParamEntity::setMODE_3WAY(bool value)
{
	MODE_3WAY = value;
	if (value)
	{
		MODE_HH = false;
		MODE_SGBM = false;
	}
	emit paramChanged_MODE_3WAY();
}

bool StereoMatchParamEntity::getDoRectify()
{
	return DoRectify;
}

void StereoMatchParamEntity::setDoRectify(bool value)
{
	DoRectify = value;
	emit paramChanged_DoRectify();
}

bool StereoMatchParamEntity::getUseExpeModule()
{
	return UseExpeModule;
}

void StereoMatchParamEntity::setUseExpeModule(bool value)
{
	UseExpeModule = value;
	emit paramChanged_UseExpeModule();
}

cv::Mat StereoMatchParamEntity::getImageDtoShow()
{
	return imgDtoShow;
}
void StereoMatchParamEntity::setImageDtoShow(cv::Mat value)
{
	imgDtoShow = value;
	emit paramChanged_ImageDtoShow();
}

cv::Mat StereoMatchParamEntity::getDisparity()
{
	return disparity;
}
void StereoMatchParamEntity::setDisparity(cv::Mat value)
{
	disparity = value;
}

cv::Mat StereoMatchParamEntity::getXYZ()
{
	return xyz;
}
void StereoMatchParamEntity::setXYZ(cv::Mat value)
{
	xyz = value;
}

cv::Mat StereoMatchParamEntity::getQ()
{
	return Q;
}
void StereoMatchParamEntity::setQ(cv::Mat value)
{
	Q = value;
}

cv::Mat StereoMatchParamEntity::getIconImgL()
{
	return iconImgL;
}
void StereoMatchParamEntity::setIconImgL(cv::Mat value)
{
	iconImgL = value;
	emit paramChanged_IconImgL();
}

cv::Mat StereoMatchParamEntity::getIconImgR()
{
	return iconImgR;
}
void StereoMatchParamEntity::setIconImgR(cv::Mat value)
{
	iconImgR = value;
	emit paramChanged_IconImgR();
}

cv::Mat StereoMatchParamEntity::getIconRawDisp()
{
	return iconRawDisp;
}
void StereoMatchParamEntity::setIconRawDisp(cv::Mat value)
{
	iconRawDisp = value;
	emit paramChanged_IconRawDisp();
}

cv::Mat StereoMatchParamEntity::getIconFixDisp()
{
	return iconFixDisp;
}
void StereoMatchParamEntity::setIconFixDisp(cv::Mat value)
{
	iconFixDisp = value;
	emit paramChanged_IconFixDisp();
}

cv::Mat StereoMatchParamEntity::getIconPcolorDisp()
{
	return iconPcolorDisp;
}

void StereoMatchParamEntity::setIconPcolorDisp(cv::Mat value)
{
	iconPcolorDisp = value;
	emit paramChanged_IconPcolorDisp();
}

StereoMatchParamEntity::IMGID StereoMatchParamEntity::getImageToShow()
{
	return ImageToShow;
}

void StereoMatchParamEntity::setImageToShow(StereoMatchParamEntity::IMGID value)
{
	ImageToShow = value;
	emit paramChanged_ImageToShow();
}
