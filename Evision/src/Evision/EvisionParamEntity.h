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

	int MinDisp = 0;
	int Uniradio = 0;
	int Specwinsz = 0;
	int MaxDisp = 0;
	int Specrange = 0;
	int Prefilcap = 0;
	int SadWinsz = 0;
	int TextThread = 0;
	int Maxdifdisp12 = 0;
	int Levels = 0;
	float PyrScale = 0;
	int PolyN = 0;
	float PolySigma = 0;
	float Fi = 0;
	float Lambda = 0;

	bool BM = false;
	bool SGBM = false;
	bool VAR = false;

	float Distance=0.0f;
	cv::Mat imgLtoShow, imgRtoShow;
	QString StatusBarText="";
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
	void paramChanged_MaxDisp();
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
	void paramChanged_VAR();

	void paramChanged_distance();

	void paramChanged_ImageLtoShow();
	void paramChanged_ImageRtoShow();

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

	int getMaxDisp();
	void setMaxDisp(int value);

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

	int getLevels();
	void setLevels(int value);

	float getPyrScale();
	void setPyrScale(float value);

	int getPolyN();
	void setPolyN(int value);

	float getPolySigma();
	void setPolySigma(float value);

	float getFi();
	void setFi(float value);

	float getLambda();
	void setLambda(float value);

	bool getBM();
	void setBM(bool value);

	bool getSGBM();
	void setSGBM(bool value);

	bool getVAR();
	void setVAR(bool value);

	float getDistance();
	void setDistance(float value);

	cv::Mat getImageLtoShow();
	void setImageLtoShow(cv::Mat value);

	cv::Mat getImageRtoShow();
	void setImageRtoShow(cv::Mat value);

	QString getStatusBarText();
	void setStatusBarText(QString value);
#pragma endregion 
};

