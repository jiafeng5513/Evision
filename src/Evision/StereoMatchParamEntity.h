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
	//BM 参数
	bool BM_preFilterType_NORMALIZED = false; //使用归一化作为前处理
	bool BM_preFilterType_XSOBEL = false;	  //使用XSOBEL作为前处理
	int BM_preFilterSize = 0;				  //归一化窗口大小,[5,255]之间的奇数
	int BM_preFilterCap = 0;				  //XSobel截断值.[1,63]
	int BM_SADWindowSize = 0;				  //SAD窗口大小,[5,255]之间的奇数且不能大于图片的宽或高
	int BM_minDisparity = 0;				  //视差搜索起点
	int BM_numDisparities = 0;				  //视差窗口,一个推荐值是((width / 8) + 15) & (~0xfl),必须能被16整除
	int BM_textureThreshold = 0;			  //低纹理区域的判断阈值. 非负数
	int BM_uniquenessRatio = 0;				  //视差唯一性百分比,非负数
	int BM_speckleRange = 0;				  //散斑窗口内允许的最大波动值
	int BM_speckleWindowSize = 0;			  //散斑滤波窗口大小,<=0时不进行散斑滤波
	int BM_disp12MaxDiff = 0;				  //左右一致性检查的最大容差,小于0时跳过

	//SGBM参数
	int SGBM_minDisparity = 0;				  //视差搜索起点
	int SGBM_numDisparities = 0;			  //视差窗口,一个推荐值是((width / 8) + 15) & (~0xfl),必须能被16整除
	int SGBM_blockSize = 0;					  //匹配块大小,一般在[3,11]
	int SGBM_P1 = 0;						  //惩罚系数P1
	int SGBM_P2 = 0;						  //惩罚系数P2,P2>P1
	int SGBM_disp12MaxDiff = 0;				  //左右一致性检查的最大容差,小于0时跳过
	int SGBM_preFilterCap = 0;				  //前处理截断值.
	int SGBM_uniquenessRatio = 0;			  //视差唯一性百分比,非负数,[5,15]	
	int SGBM_speckleWindowSize = 0;			  //散斑滤波窗口大小,<=0时不进行散斑滤波,0禁用,取值[50,200]
	int SGBM_speckleRange = 0;				  //散斑窗口内允许的最大波动值,内部乘16起效,整数,常[1,2]
	bool SGBM_MODEL_3WAY = false;			  //3Way模式
	bool SGBM_MODEL_HH4 = false;			  //HH4模式
	bool SGBM_MODEL_Default = false;		  //默认模式
	bool SGBM_MODEL_HH = false;				  //HH模式

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
	/*======================ELAS的参数==========================*/
	int disp_min;                  // min disparity
	int disp_max;                  // max disparity
	double support_threshold;      // max. uniqueness ratio (best vs. second best support match)
	int support_texture;		   // min texture for support points
	int candidate_stepsize;		   // step size of regular grid on which support points are matched
	int incon_window_size;		   // window size of inconsistent support point check
	int incon_threshold;		   // disparity similarity threshold for support point to be considered consistent
	int incon_min_support;		   // minimum number of consistent support points
	bool add_corners;              // add support points at image corners with nearest neighbor disparities
	int grid_size;                 // size of neighborhood for additional support point extrapolation
	double beta;                   // 图像似然参数
	double gamma;                  // prior constant
	double sigma;                  // prior sigma
	double sradius;                // prior sigma radius
	int match_texture;			   // min texture for dense matching
	int lr_threshold;			   // disparity threshold for left/right consistency check
	double speckle_sim_threshold;  // similarity threshold for speckle segmentation
	int speckle_size;			   // maximal size of a speckle (small speckles get removed)
	int ipol_gap_width;			   // interpolate small gaps (left<->right, top<->bottom)
	bool filter_median;			   // optional median filter (approximated)
	bool filter_adaptive_mean;	   // optional adaptive mean filter (approximated)
	bool postprocess_only_left;	   // saves time by not postprocessing the right image
	bool subsampling;			   // saves time by only computing disparities for each 2nd pixel
	// note: for this option D1 and D2 must be passed with size width/2 x height/2 (rounded towards zero)

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
	void paramChanged_BM();
	void paramChanged_SGBM();
	void paramChanged_ELAS();
	void paramChanged_RectifiedInput();
	void paramChanged_ADCensus();
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
	void paramChanged_disp_min();
	void paramChanged_disp_max();
	void paramChanged_support_threshold();
	void paramChanged_support_texture();
	void paramChanged_candidate_stepsize();
	void paramChanged_incon_window_size();
	void paramChanged_incon_threshold();
	void paramChanged_incon_min_support();
	void paramChanged_add_corners();
	void paramChanged_grid_size();
	void paramChanged_beta();
	void paramChanged_gamma();
	void paramChanged_sigma();
	void paramChanged_sradius();
	void paramChanged_match_texture();
	void paramChanged_lr_threshold();
	void paramChanged_speckle_sim_threshold();
	void paramChanged_speckle_size();
	void paramChanged_ipol_gap_width();
	void paramChanged_filter_median();
	void paramChanged_filter_adaptive_mean();
	void paramChanged_postprocess_only_left();
	void paramChanged_subsampling();

	void paramChanged_BM_preFilterType_NORMALIZED();
	void paramChanged_BM_preFilterType_XSOBEL();
	void paramChanged_BM_preFilterSize();
	void paramChanged_BM_preFilterCap();
	void paramChanged_BM_SADWindowSize();
	void paramChanged_BM_minDisparity();
	void paramChanged_BM_numDisparities();
	void paramChanged_BM_textureThreshold();
	void paramChanged_BM_uniquenessRatio();
	void paramChanged_BM_speckleRange();
	void paramChanged_BM_speckleWindowSize();
	void paramChanged_BM_disp12MaxDiff();
	void paramChanged_SGBM_minDisparity();
	void paramChanged_SGBM_numDisparities();
	void paramChanged_SGBM_blockSize();
	void paramChanged_SGBM_P1();
	void paramChanged_SGBM_P2();
	void paramChanged_SGBM_disp12MaxDiff();
	void paramChanged_SGBM_preFilterCap();
	void paramChanged_SGBM_uniquenessRatio();
	void paramChanged_SGBM_speckleWindowSize();
	void paramChanged_SGBM_speckleRange();
	void paramChanged_SGBM_MODEL_3WAY();
	void paramChanged_SGBM_MODEL_HH4();
	void paramChanged_SGBM_MODEL_Default();
	void paramChanged_SGBM_MODEL_HH();

#pragma endregion

public:
#pragma region getter And setter
	bool getBM();
	void setBM(bool value);

	bool getSGBM();
	void setSGBM(bool value);

	bool getElas();
	void setElas(bool value);

	bool getADCensus();
	void setADCensus(bool value);

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

	void setDispMin(int value);
	int getDispMin();

	void setDispMax(int value);
	int getDispMax();

	void setSupportThreshold(double value);
	double getSupportThreshold();

	void setSupportTexture(int value);
	int getSupportTexture();

	void setCandidateStepsize(int value);
	int getCandidateStepsize();

	void setInconWindowSize(int value);
	int getInconWindowSize();

	void setInconThreshold(int value);
	int getInconThreshold();

	void setInconMinSupport(int value);
	int getInconMinSupport();

	void setAddCorners(bool value);
	bool getAddCorners();

	void setGridSize(int value);
	int getGridSize();

	void setBeta(double value);
	double getBeta();

	void setGamma(double value);
	double getGamma();

	void setSigma(double value);
	double getSigma();

	void setSradius(double value);
	double getSradius();

	void setMatchTexture(int value);
	int getMatchTexture();

	void setLrThreshold(int value);
	int getLrThreshold();

	void setSpeckleSimThreshold(double value);
	double getSpeckleSimThreshold();

	void setSpeckleSize(int value);
	int getSpeckleSize();

	void setIpolGapWidth(int value);
	int getIpolGapWidth();

	void setFilterMedian(bool value);
	bool getFilterMedian();

	void setFilterAdaptiveMean(bool value);
	bool getFilterAdaptiveMean();

	void setPostprocessOnlyLeft(bool value);
	bool getPostprocessOnlyLeft();

	void setSubSampling(bool value);
	bool getSubSampling();

	void setBM_preFilterType_NORMALIZED(bool value);
	bool getBM_preFilterType_NORMALIZED();

	void setBM_preFilterType_XSOBEL(bool value);
	bool getBM_preFilterType_XSOBEL();

	void setBM_preFilterSize(int value);
	int getBM_preFilterSize();

	void setBM_preFilterCap(int value);
	int getBM_preFilterCap();

	void setBM_SADWindowSize(int value);
	int getBM_SADWindowSize();

	void setBM_minDisparity(int value);
	int getBM_minDisparity();

	void setBM_numDisparities(int value);
	int getBM_numDisparities();

	void setBM_textureThreshold(int value);
	int getBM_textureThreshold();

	void setBM_uniquenessRatio(int value);
	int getBM_uniquenessRatio();

	void setBM_speckleRange(int value);
	int getBM_speckleRange();

	void setBM_speckleWindowSize(int value);
	int getBM_speckleWindowSize();

	void setBM_disp12MaxDiff(int value);
	int getBM_disp12MaxDiff();

	void setSGBM_minDisparity(int value);
	int getSGBM_minDisparity();

	void setSGBM_numDisparities(int value);
	int getSGBM_numDisparities();

	void setSGBM_blockSize(int value);
	int getSGBM_blockSize();

	void setSGBM_P1(int value);
	int getSGBM_P1();

	void setSGBM_P2(int value);
	int getSGBM_P2();

	void setSGBM_disp12MaxDiff(int value);
	int getSGBM_disp12MaxDiff();

	void setSGBM_preFilterCap(int value);
	int getSGBM_preFilterCap();

	void setSGBM_uniquenessRatio(int value);
	int getSGBM_uniquenessRatio();

	void setSGBM_speckleWindowSize(int value);
	int getSGBM_speckleWindowSize();

	void setSGBM_speckleRange(int value);
	int getSGBM_speckleRange();

	void setSGBM_MODEL_3WAY(bool value);
	bool getSGBM_MODEL_3WAY();

	void setSGBM_MODEL_HH4(bool value);
	bool getSGBM_MODEL_HH4();

	void setSGBM_MODEL_Default(bool value);
	bool getSGBM_MODEL_Default();

	void setSGBM_MODEL_HH(bool value);
	bool getSGBM_MODEL_HH();

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
