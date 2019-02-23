#pragma once

#include <QObject>
#include <opencv.hpp>

class StereoMatchParamEntity : public QObject
{
	Q_OBJECT

public:
	static StereoMatchParamEntity* getInstance();
	~StereoMatchParamEntity();
	enum IMGID { NONE,IMG_L, IMG_R, RAW_DISP, FIX_DISP, PCOLOR_DISP };
private:
	StereoMatchParamEntity(QObject *parent = 0);
private:
#pragma region params
	int Uniradio = 0;//
	int Prefilcap = 0;//
	int Specwinsz = 0;//
	int SadWinsz = 0;//
	int MinDisp = 0;//
	int TextThread = 0;//
	int NumDisparities = 0;// numDisparities	
	int Specrange = 0;//	
	int Maxdifdisp12 = 0;//	

	bool BM = false;
	bool SGBM = false;

	bool MODE_HH = false;
	bool MODE_SGBM = false;
	bool MODE_3WAY = false;

	bool DoRectify = false;
	bool UseExpeModule = false;

	cv::Mat imgDtoShow;//在中心显示的大图
	cv::Mat iconImgL, iconImgR, iconRawDisp, iconFixDisp,iconPcolorDisp;//缩略图
	IMGID ImageToShow = NONE;//默认情况下,中心大图什么也不显示

	cv::Mat disparity;
	cv::Mat xyz;
	cv::Mat Q;
#pragma endregion

signals:
#pragma region param_Changed_signals
	void paramChanged_Uniradio();
	void paramChanged_Prefilcap();
	void paramChanged_Specwinsz();
	void paramChanged_SadWinsz();
	void paramChanged_MinDisp();
	void paramChanged_TextThread();
	void paramChanged_NumDisparities();
	void paramChanged_Specrange();
	void paramChanged_Maxdifdisp12();
	void paramChanged_BM();
	void paramChanged_SGBM();
	void paramChanged_MODE_HH();
	void paramChanged_MODE_SGBM();
	void paramChanged_MODE_3WAY();
	void paramChanged_ImageDtoShow();
	void paramChanged_UseExpeModule();
	void paramChanged_DoRectify();
	void paramChanged_IconImgL();
	void paramChanged_IconImgR();
	void paramChanged_IconRawDisp();
	void paramChanged_IconFixDisp();
	void paramChanged_IconPcolorDisp();
	void paramChanged_ImageToShow();


#pragma endregion

public:
#pragma region getter And setter
	int getUniradio();
	void setUniradio(int value);

	int getPrefilcap();
	void setPrefilcap(int value);

	int getSpecwinsz();
	void setSpecwinsz(int value);

	int getSadWinsz();
	void setSadWinsz(int value);

	int getMinDisp();
	void setMinDisp(int value);

	int getTextThread();
	void setTextThread(int value);

	int getNumDisparities();
	void setNumDisparities(int value);

	int getSpecrange();
	void setSpecrange(int value);

	int getMaxdifdisp12();
	void setMaxdifdisp12(int value);

	bool getBM();
	void setBM(bool value);

	bool getSGBM();
	void setSGBM(bool value);

	bool getMODE_HH();
	void setMODE_HH(bool value);

	bool getMODE_SGBM();
	void setMODE_SGBM(bool value);

	bool getMODE_3WAY();
	void setMODE_3WAY(bool value);

	bool getDoRectify();
	void setDoRectify(bool value);

	bool getUseExpeModule();
	void setUseExpeModule(bool value);

	cv::Mat getImageDtoShow();
	void setImageDtoShow(cv::Mat value);

	cv::Mat getDisparity();
	void setDisparity(cv::Mat value);

	cv::Mat getXYZ();
	void setXYZ(cv::Mat value);

	cv::Mat getQ();
	void setQ(cv::Mat value);

	cv::Mat getIconImgL();
	void setIconImgL(cv::Mat value);

	cv::Mat getIconImgR();
	void setIconImgR(cv::Mat value);

	cv::Mat getIconRawDisp();
	void setIconRawDisp(cv::Mat value);

	cv::Mat getIconFixDisp();
	void setIconFixDisp(cv::Mat value);

	cv::Mat getIconPcolorDisp();
	void setIconPcolorDisp(cv::Mat value);

	IMGID getImageToShow();
	void setImageToShow(IMGID value);
#pragma endregion
};
