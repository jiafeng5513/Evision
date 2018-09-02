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

	int BoardWidth=0;
	int BoardHeight=0;
	int SquareSize=0;
	int Alpha=0;
	bool showRectified = false;
	bool Bouguet = false;
	bool Hartley = false;

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

	float Distance=0.0f;
	cv::Mat imgLtoShow, imgRtoShow, imgDtoShow;
	QString StatusBarText="";

	cv::Mat disparity;
	cv::Mat xyz;
	cv::Mat Q;
#pragma endregion 

	
#pragma region param_Changed_signals
signals:
	void paramChanged_BoardWidth();
	void paramChanged_BoardHeight();
	void paramChanged_SquareSize();
	void paramChanged_showRectified();
	void paramChanged_Bouguet();
	void paramChanged_Hartley();

	void paramChanged_MinDisp();
	void paramChanged_Uniradio();
	void paramChanged_Specwinsz();
	void paramChanged_NumDisparities();
	void paramChanged_Specrange();
	void paramChanged_Prefilcap();
	void paramChanged_SadWinsz();
	void paramChanged_TextThread();
	void paramChanged_Maxdifdisp12();
	void paramChanged_Levels();
	void paramChanged_pyrScale();
	void paramChanged_PolyN();
	void paramChanged_PolySigma();
	void paramChanged_Fi();
	void paramChanged_Lambda();;

	void paramChanged_BM();
	void paramChanged_SGBM();
	void paramChanged_MODE_HH();
	void paramChanged_MODE_SGBM();
	void paramChanged_MODE_3WAY();


	void paramChanged_distance();

	void paramChanged_ImageLtoShow();
	void paramChanged_ImageRtoShow();
	void paramChanged_ImageDtoShow();

	void paramChanged_StatusBar();
#pragma endregion 

public:
#pragma region getter And setter
	//void set

	int getBoardWidth();
	void setBoardWidth(int value);

	int getBoardHeight();
	void setBoardHeight(int value);

	int getSquareSize();
	void setSquareSize(int value);

	bool getshowRectified();
	void setshowRectified(bool value);

	bool getBouguet();
	void setBouguet(bool value);

	bool getHartley();
	void setHartley(bool value);

	int getMinDisp();
	void setMinDisp(int value); 

	int getUniradio();
	void setUniradio(int value);

	int getSpecwinsz();
	void setSpecwinsz(int value);

	int getNumDisparities();
	void setNumDisparities(int value);

	int getSpecrange();
	void setSpecrange(int value);

	int getPrefilcap();
	void setPrefilcap(int value);

	int getSadWinsz();
	void setSadWinsz(int value);

	int getTextThread();
	void setTextThread(int value);

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

	float getDistance();
	void setDistance(float value);

	cv::Mat getImageLtoShow();
	void setImageLtoShow(cv::Mat value);

	cv::Mat getImageRtoShow();
	void setImageRtoShow(cv::Mat value);

	cv::Mat getImageDtoShow();
	void setImageDtoShow(cv::Mat value);

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

