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
	//BM和SGBM的参数
	int Uniradio = 0;			//
	int Prefilcap = 0;			//
	int Specwinsz = 0;			//
	int SadWinsz = 0;			//
	int MinDisp = 0;			//
	int TextThread = 0;			//
	int NumDisparities = 0;		// numDisparities	
	int Specrange = 0;			//	
	int Maxdifdisp12 = 0;		//	
	//ADCensus的参数
	// Minimum and maximum disparity
	uint dMin = 0;
	uint dMax = 0;
	// Parameters for the cost-initialization for the ADCensus
	int censusWinH = 0;
	int censusWinW = 0;
	double defaultBorderCost = 0.0;
	double lambdaAD = 0.0;
	double lambdaCensus = 0.0;
	// Parameters for the cross-based cost aggregation
	uint aggregatingIterations = 0;
	uint colorThreshold1 = 0;
	uint colorThreshold2 = 0;
	uint maxLength1 = 0;
	uint maxLength2 = 0;
	// Parameters for the optimization of image cells
	uint colorDifference = 0;
	double pi1 = 0.1;
	double pi2 = 0.3;
	// Parameters for outlier detection
	uint dispTolerance = 0;
	// Parameters for the iterative range rating
	uint votingThreshold = 0;
	double votingRatioThreshold = 0;
	// Parameters for the proper interpolation
	uint maxSearchDepth = 0;
	// Parameters for the approximation of depths discontinuities 
	uint cannyThreshold1 = 0;
	uint cannyThreshold2 = 0;
	uint cannyKernelSize = 0;
	// Parameters for the sub-pixel enhancement
	uint blurKernelSize = 0;

	//SGBM的三种模式
	bool MODE_HH = false;
	bool MODE_SGBM = false;
	bool MODE_3WAY = false;

	//四种可选算法
	bool BM = false;
	bool SGBM = false;
	bool ELAS = false;
	bool ADCensus = false;

	bool RectifiedInput = false;//输入图像是否已经进行了校准

	cv::Mat imgDtoShow;//在中心显示的大图
	cv::Mat iconImgL, iconImgR, iconRawDisp;//缩略图
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
	void paramChanged_ELAS();
	void paramChanged_RectifiedInput();
	void paramChanged_ADCensus();
	void paramChanged_MODE_HH();
	void paramChanged_MODE_SGBM();
	void paramChanged_MODE_3WAY();
	void paramChanged_ImageDtoShow();
	void paramChanged_IconImgL();
	void paramChanged_IconImgR();
	void paramChanged_IconRawDisp();
	void paramChanged_IconFixDisp();
	void paramChanged_IconPcolorDisp();
	void paramChanged_ImageToShow();
	void paramChanged_dMin();
	void paramChanged_dMax();
	void paramChanged_censusWinH();
	void paramChanged_censusWinW();
	void paramChanged_defaultBorderCost();
	void paramChanged_lambdaAD();
	void paramChanged_lambdaCensus();
	void paramChanged_aggregatingIterations();
	void paramChanged_colorThreshold1();
	void paramChanged_colorThreshold2();
	void paramChanged_maxLength1();
	void paramChanged_maxLength2();
	void paramChanged_colorDifference();
	void paramChanged_pi1();
	void paramChanged_pi2();
	void paramChanged_dispTolerance();
	void paramChanged_votingThreshold();
	void paramChanged_votingRatioThreshold();
	void paramChanged_maxSearchDepth();
	void paramChanged_cannyThreshold1();
	void paramChanged_cannyThreshold2();
	void paramChanged_cannyKernelSize();
	void paramChanged_blurKernelSize();


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

	bool getElas();
	void setElas(bool value);

	bool getADCensus();
	void setADCensus(bool value);

	bool getMODE_HH();
	void setMODE_HH(bool value);

	bool getMODE_SGBM();
	void setMODE_SGBM(bool value);

	bool getMODE_3WAY();
	void setMODE_3WAY(bool value);

	bool getRectifiedInput();
	void setRectifiedInput(bool value);

	//1.int
	void setDMin(int value);
	int getDMin();
	//2.int
	void setDMax(int value);
	int getDMax();
	//3.int
	void setCensusWinH(int value);
	int getCensusWinH();
	//4.int
	void setCensusWinW(int value);
	int getCensusWinW();
	//5.float
	void setDefaultBorderCost(double value);
	double getDefaultBorderCost();
	//6.float
	void setLambdaAD(double value);
	double getLambdaAD();
	//7.float
	void setLambdaCensus(double value);
	double getLambdaCensus();
	//8.int
	void setAggregatingIterations(int value);
	int getAggregatingIterations();
	//9.int
	void setColorThreshold1(int value);
	int getColorThreshold1();
	//10.int
	void setColorThreshold2(int value);
	int getColorThreshold2();
	//11.int
	void setMaxLength1(int value);
	int getMaxLength1();
	//12.int
	void setMaxLength2(int value);
	int getMaxLength2();
	//13.int
	void setColorDifference(int value);
	int getColorDifference();
	//14.float
	void setPi1(double value);
	double getPi1();
	//15.float
	void setPi2(double value);
	double getPi2();
	//16.int
	void setDispTolerance(int value);
	int getDispTolerance();
	//17.int
	void setVotingThreshold(int value);
	int getVotingThreshold();
	//18.float
	void setVotingRatioThreshold(double value);
	double getVotingRatioThreshold();
	//19.int
	void setMaxSearchDepth(int value);
	int getMaxSearchDepth();
	//20.int
	void setCannyThreshold1(int value);
	int getCannyThreshold1();
	//21.int
	void setCannyThreshold2(int value);
	int getCannyThreshold2();
	//22.int
	void setCannyKernelSize(int value);
	int getCannyKernelSize();
	//23.int
	void setBlurKernelSize(int value);
	int getBlurKernelSize();

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

	IMGID getImageToShow();
	void setImageToShow(IMGID value);
#pragma endregion
};
