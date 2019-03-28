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
		ELAS = false;
		ADCensus = false;
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
		ELAS = false;
		ADCensus = false;
	}
	emit paramChanged_SGBM();
}

bool StereoMatchParamEntity::getElas()
{
	return ELAS;
}
void StereoMatchParamEntity::setElas(bool value)
{
	ELAS = value;
	if(value)
	{
		BM = false;
		SGBM = false;
		ADCensus = false;
	}
	emit paramChanged_ELAS();
}

bool StereoMatchParamEntity::getADCensus()
{
	return ADCensus;
}
void StereoMatchParamEntity::setADCensus(bool value)
{
	ADCensus = value;
	if(value)
	{
		BM = false;
		SGBM = false;
		ELAS = false;
	}
	emit paramChanged_ADCensus();
}

bool StereoMatchParamEntity::getRectifiedInput()
{
	return RectifiedInput;
}

void StereoMatchParamEntity::setRectifiedInput(bool value)
{
	RectifiedInput = value;
	emit paramChanged_RectifiedInput();
}

int StereoMatchParamEntity::getDMin() {
	return dMin;
}
void StereoMatchParamEntity::setDMin(int value) {
	dMin = value;
	emit paramChanged_dMin();
}

int StereoMatchParamEntity::getDMax() {
	return dMax;
}
void StereoMatchParamEntity::setDMax(int value) {
	dMax = value;
	emit paramChanged_dMax();
}

int StereoMatchParamEntity::getCensusWinH() {
	return censusWinH;
}
void StereoMatchParamEntity::setCensusWinH(int value) {
	censusWinH = value;
	emit paramChanged_censusWinH();
}

int StereoMatchParamEntity::getCensusWinW() {
	return censusWinW;
}
void StereoMatchParamEntity::setCensusWinW(int value) {
	censusWinW = value;
	emit paramChanged_censusWinW();
}

double StereoMatchParamEntity::getDefaultBorderCost() {
	return defaultBorderCost;
}
void StereoMatchParamEntity::setDefaultBorderCost(double value) {
	defaultBorderCost = value;
	emit paramChanged_defaultBorderCost();
}

double StereoMatchParamEntity::getLambdaAD() {
	return lambdaAD;
}
void StereoMatchParamEntity::setLambdaAD(double value) {
	lambdaAD = value;
	emit paramChanged_lambdaAD();
}

double StereoMatchParamEntity::getLambdaCensus() {
	return lambdaCensus;
}
void StereoMatchParamEntity::setLambdaCensus(double value) {
	lambdaCensus = value;
	emit paramChanged_lambdaCensus();
}

int StereoMatchParamEntity::getAggregatingIterations() {
	return aggregatingIterations;
}
void StereoMatchParamEntity::setAggregatingIterations(int value) {
	aggregatingIterations = value;
	emit paramChanged_aggregatingIterations();
}

int StereoMatchParamEntity::getColorThreshold1() {
	return colorThreshold1;
}
void StereoMatchParamEntity::setColorThreshold1(int value) {
	colorThreshold1 = value;
	emit paramChanged_colorThreshold1();
}

int StereoMatchParamEntity::getColorThreshold2() {
	return colorThreshold2;
}
void StereoMatchParamEntity::setColorThreshold2(int value) {
	colorThreshold2 = value;
	emit paramChanged_colorThreshold2();
}

int StereoMatchParamEntity::getMaxLength1() {
	return maxLength1;
}
void StereoMatchParamEntity::setMaxLength1(int value) {
	maxLength1 = value;
	emit paramChanged_maxLength1();
}

int StereoMatchParamEntity::getMaxLength2() {
	return maxLength2;
}
void StereoMatchParamEntity::setMaxLength2(int value) {
	maxLength2 = value;
	emit paramChanged_maxLength2();
}

int StereoMatchParamEntity::getColorDifference() {
	return colorDifference;
}
void StereoMatchParamEntity::setColorDifference(int value) {
	colorDifference = value;
	emit paramChanged_colorDifference();
}

double StereoMatchParamEntity::getPi1() {
	return pi1;
}
void StereoMatchParamEntity::setPi1(double value) {
	pi1 = value;
	emit paramChanged_pi1();
}

double StereoMatchParamEntity::getPi2() {
	return pi2;
}
void StereoMatchParamEntity::setPi2(double value) {
	pi2 = value;
	emit paramChanged_pi2();
}

int StereoMatchParamEntity::getDispTolerance() {
	return dispTolerance;
}
void StereoMatchParamEntity::setDispTolerance(int value) {
	dispTolerance = value;
	emit paramChanged_dispTolerance();
}

int StereoMatchParamEntity::getVotingThreshold() {
	return votingThreshold;
}
void StereoMatchParamEntity::setVotingThreshold(int value) {
	votingThreshold = value;
	emit paramChanged_votingThreshold();
}

double StereoMatchParamEntity::getVotingRatioThreshold() {
	return votingRatioThreshold;
}
void StereoMatchParamEntity::setVotingRatioThreshold(double value) {
	votingRatioThreshold = value;
	emit paramChanged_votingRatioThreshold();
}

int StereoMatchParamEntity::getMaxSearchDepth() {
	return maxSearchDepth;
}
void StereoMatchParamEntity::setMaxSearchDepth(int value) {
	maxSearchDepth = value;
	emit paramChanged_maxSearchDepth();
}

int StereoMatchParamEntity::getCannyThreshold1() {
	return cannyThreshold1;
}
void StereoMatchParamEntity::setCannyThreshold1(int value) {
	cannyThreshold1 = value;
	emit paramChanged_cannyThreshold1();
}

int StereoMatchParamEntity::getCannyThreshold2() {
	return cannyThreshold2;
}
void StereoMatchParamEntity::setCannyThreshold2(int value) {
	cannyThreshold2 = value;
	emit paramChanged_cannyThreshold2();
}

int StereoMatchParamEntity::getCannyKernelSize() {
	return cannyKernelSize;
}
void StereoMatchParamEntity::setCannyKernelSize(int value) {
	cannyKernelSize = value;
	emit paramChanged_cannyKernelSize();
}

int StereoMatchParamEntity::getBlurKernelSize() {
	return blurKernelSize;
}
void StereoMatchParamEntity::setBlurKernelSize(int value) {
	blurKernelSize = value;
	emit paramChanged_blurKernelSize();
}

void StereoMatchParamEntity::setDispMin(int value) {
	disp_min = value;
	emit paramChanged_disp_min();
}
int StereoMatchParamEntity::getDispMin() {
	return disp_min;
}
void StereoMatchParamEntity::setDispMax(int value) {
	disp_max = value;
	emit paramChanged_disp_max();
}
int StereoMatchParamEntity::getDispMax() {
	return disp_max;
}
void StereoMatchParamEntity::setSupportThreshold(double value) {
	support_threshold = value;
	emit paramChanged_support_threshold();
}
double StereoMatchParamEntity::getSupportThreshold() {
	return support_threshold;
}
void StereoMatchParamEntity::setSupportTexture(int value) {
	support_texture = value;
	emit paramChanged_support_texture();
}
int StereoMatchParamEntity::getSupportTexture() {
	return support_texture;
}
void StereoMatchParamEntity::setCandidateStepsize(int value) {
	candidate_stepsize = value;
	emit paramChanged_candidate_stepsize();
}
int StereoMatchParamEntity::getCandidateStepsize() {
	return candidate_stepsize;
}
void StereoMatchParamEntity::setInconWindowSize(int value) {
	incon_window_size = value;
	emit paramChanged_incon_window_size();
}
int StereoMatchParamEntity::getInconWindowSize() {
	return incon_window_size;
}
void StereoMatchParamEntity::setInconThreshold(int value) {
	incon_threshold = value;
	emit paramChanged_incon_threshold();
}
int StereoMatchParamEntity::getInconThreshold() {
	return incon_threshold;
}
void StereoMatchParamEntity::setInconMinSupport(int value) {
	incon_min_support = value;
	emit paramChanged_incon_min_support();
}
int StereoMatchParamEntity::getInconMinSupport() {
	return incon_min_support;
}
void StereoMatchParamEntity::setAddCorners(bool value) {
	add_corners = value;
	emit paramChanged_add_corners();
}
bool StereoMatchParamEntity::getAddCorners() {
	return add_corners;
}
void StereoMatchParamEntity::setGridSize(int value) {
	grid_size = value;
	emit paramChanged_grid_size();
}
int StereoMatchParamEntity::getGridSize() {
	return grid_size;
}
void StereoMatchParamEntity::setBeta(double value) {
	beta = value;
	emit paramChanged_beta();
}
double StereoMatchParamEntity::getBeta() {
	return beta;
}
void StereoMatchParamEntity::setGamma(double value) {
	gamma = value;
	emit paramChanged_gamma();
}
double StereoMatchParamEntity::getGamma() {
	return gamma;
}
void StereoMatchParamEntity::setSigma(double value) {
	sigma = value;
	emit paramChanged_sigma();
}
double StereoMatchParamEntity::getSigma() {
	return sigma;
}
void StereoMatchParamEntity::setSradius(double value) {
	sradius = value;
	emit paramChanged_sradius();
}
double StereoMatchParamEntity::getSradius() {
	return sradius;
}
void StereoMatchParamEntity::setMatchTexture(int value) {
	match_texture = value;
	emit paramChanged_match_texture();
}
int StereoMatchParamEntity::getMatchTexture() {
	return match_texture;
}
void StereoMatchParamEntity::setLrThreshold(int value) {
	lr_threshold = value;
	emit paramChanged_lr_threshold();
}
int StereoMatchParamEntity::getLrThreshold() {
	return lr_threshold;
}
void StereoMatchParamEntity::setSpeckleSimThreshold(double value) {
	speckle_sim_threshold = value;
	emit paramChanged_speckle_sim_threshold();
}
double StereoMatchParamEntity::getSpeckleSimThreshold() {
	return speckle_sim_threshold;
}
void StereoMatchParamEntity::setSpeckleSize(int value) {
	speckle_size = value;
	emit paramChanged_speckle_size();
}
int StereoMatchParamEntity::getSpeckleSize() {
	return speckle_size;
}
void StereoMatchParamEntity::setIpolGapWidth(int value) {
	ipol_gap_width = value;
	emit paramChanged_ipol_gap_width();
}
int StereoMatchParamEntity::getIpolGapWidth() {
	return ipol_gap_width;
}
void StereoMatchParamEntity::setFilterMedian(bool value) {
	filter_median = value;
	emit paramChanged_filter_median();
}
bool StereoMatchParamEntity::getFilterMedian() {
	return filter_median;
}
void StereoMatchParamEntity::setFilterAdaptiveMean(bool value) {
	filter_adaptive_mean = value;
	emit paramChanged_filter_adaptive_mean();
}
bool StereoMatchParamEntity::getFilterAdaptiveMean() {
	return filter_adaptive_mean;
}
void StereoMatchParamEntity::setPostprocessOnlyLeft(bool value) {
	postprocess_only_left = value;
	emit paramChanged_postprocess_only_left();
}
bool StereoMatchParamEntity::getPostprocessOnlyLeft() {
	return postprocess_only_left;
}
void StereoMatchParamEntity::setSubSampling(bool value) {
	subsampling = value;
	emit paramChanged_subsampling();
}
bool StereoMatchParamEntity::getSubSampling() {
	return subsampling;
}

void StereoMatchParamEntity::setBM_preFilterType_NORMALIZED(bool value) {
	BM_preFilterType_NORMALIZED = value;
	emit paramChanged_BM_preFilterType_NORMALIZED();
}
bool StereoMatchParamEntity::getBM_preFilterType_NORMALIZED() {
	return BM_preFilterType_NORMALIZED;
}

void StereoMatchParamEntity::setBM_preFilterType_XSOBEL(bool value) {
	BM_preFilterType_XSOBEL = value;
	emit paramChanged_BM_preFilterType_XSOBEL();
}
bool StereoMatchParamEntity::getBM_preFilterType_XSOBEL() {
	return BM_preFilterType_XSOBEL;
}

void StereoMatchParamEntity::setBM_preFilterSize(int value) {
	BM_preFilterSize = value;
	emit paramChanged_BM_preFilterSize();
}
int StereoMatchParamEntity::getBM_preFilterSize() {
	return BM_preFilterSize;
}

void StereoMatchParamEntity::setBM_preFilterCap(int value) {
	BM_preFilterCap = value;
	emit paramChanged_BM_preFilterCap();
}
int StereoMatchParamEntity::getBM_preFilterCap() {
	return BM_preFilterCap;
}

void StereoMatchParamEntity::setBM_SADWindowSize(int value) {
	BM_SADWindowSize = value;
	emit paramChanged_BM_SADWindowSize();
}
int StereoMatchParamEntity::getBM_SADWindowSize() {
	return BM_SADWindowSize;
}

void StereoMatchParamEntity::setBM_minDisparity(int value) {
	BM_minDisparity = value;
	emit paramChanged_BM_minDisparity();
}
int StereoMatchParamEntity::getBM_minDisparity() {
	return BM_minDisparity;
}

void StereoMatchParamEntity::setBM_numDisparities(int value) {
	BM_numDisparities = value;
	emit paramChanged_BM_numDisparities();
}
int StereoMatchParamEntity::getBM_numDisparities() {
	return BM_numDisparities;
}

void StereoMatchParamEntity::setBM_textureThreshold(int value) {
	BM_textureThreshold = value;
	emit paramChanged_BM_textureThreshold();
}
int StereoMatchParamEntity::getBM_textureThreshold() {
	return BM_textureThreshold;
}

void StereoMatchParamEntity::setBM_uniquenessRatio(int value) {
	BM_uniquenessRatio = value;
	emit paramChanged_BM_uniquenessRatio();
}
int StereoMatchParamEntity::getBM_uniquenessRatio() {
	return BM_uniquenessRatio;
}

void StereoMatchParamEntity::setBM_speckleRange(int value) {
	BM_speckleRange = value;
	emit paramChanged_BM_speckleRange();
}
int StereoMatchParamEntity::getBM_speckleRange() {
	return BM_speckleRange;
}

void StereoMatchParamEntity::setBM_speckleWindowSize(int value) {
	BM_speckleWindowSize = value;
	emit paramChanged_BM_speckleWindowSize();
}
int StereoMatchParamEntity::getBM_speckleWindowSize() {
	return BM_speckleWindowSize;
}

void StereoMatchParamEntity::setBM_disp12MaxDiff(int value) {
	BM_disp12MaxDiff = value;
	emit paramChanged_BM_disp12MaxDiff();
}
int StereoMatchParamEntity::getBM_disp12MaxDiff() {
	return BM_disp12MaxDiff;
}

void StereoMatchParamEntity::setSGBM_minDisparity(int value) {
	SGBM_minDisparity = value;
	emit paramChanged_SGBM_minDisparity();
}
int StereoMatchParamEntity::getSGBM_minDisparity() {
	return SGBM_minDisparity;
}

void StereoMatchParamEntity::setSGBM_numDisparities(int value) {
	SGBM_numDisparities = value;
	emit paramChanged_SGBM_numDisparities();
}
int StereoMatchParamEntity::getSGBM_numDisparities() {
	return SGBM_numDisparities;
}

void StereoMatchParamEntity::setSGBM_blockSize(int value) {
	SGBM_blockSize = value;
	emit paramChanged_SGBM_blockSize();
}
int StereoMatchParamEntity::getSGBM_blockSize() {
	return SGBM_blockSize;
}

void StereoMatchParamEntity::setSGBM_P1(int value) {
	SGBM_P1 = value;
	emit paramChanged_SGBM_P1();
}
int StereoMatchParamEntity::getSGBM_P1() {
	return SGBM_P1;
}

void StereoMatchParamEntity::setSGBM_P2(int value) {
	SGBM_P2 = value;
	emit paramChanged_SGBM_P2();
}
int StereoMatchParamEntity::getSGBM_P2() {
	return SGBM_P2;
}

void StereoMatchParamEntity::setSGBM_disp12MaxDiff(int value) {
	SGBM_disp12MaxDiff = value;
	emit paramChanged_SGBM_disp12MaxDiff();
}
int StereoMatchParamEntity::getSGBM_disp12MaxDiff() {
	return SGBM_disp12MaxDiff;
}

void StereoMatchParamEntity::setSGBM_preFilterCap(int value) {
	SGBM_preFilterCap = value;
	emit paramChanged_SGBM_preFilterCap();
}
int StereoMatchParamEntity::getSGBM_preFilterCap() {
	return SGBM_preFilterCap;
}

void StereoMatchParamEntity::setSGBM_uniquenessRatio(int value) {
	SGBM_uniquenessRatio = value;
	emit paramChanged_SGBM_uniquenessRatio();
}
int StereoMatchParamEntity::getSGBM_uniquenessRatio() {
	return SGBM_uniquenessRatio;
}

void StereoMatchParamEntity::setSGBM_speckleWindowSize(int value) {
	SGBM_speckleWindowSize = value;
	emit paramChanged_SGBM_speckleWindowSize();
}
int StereoMatchParamEntity::getSGBM_speckleWindowSize() {
	return SGBM_speckleWindowSize;
}

void StereoMatchParamEntity::setSGBM_speckleRange(int value) {
	SGBM_speckleRange = value;
	emit paramChanged_SGBM_speckleRange();
}
int StereoMatchParamEntity::getSGBM_speckleRange() {
	return SGBM_speckleRange;
}

void StereoMatchParamEntity::setSGBM_MODEL_3WAY(bool value) {
	SGBM_MODEL_3WAY = value;
	emit paramChanged_SGBM_MODEL_3WAY();
}
bool StereoMatchParamEntity::getSGBM_MODEL_3WAY() {
	return SGBM_MODEL_3WAY;
}

void StereoMatchParamEntity::setSGBM_MODEL_HH4(bool value) {
	SGBM_MODEL_HH4 = value;
	emit paramChanged_SGBM_MODEL_HH4();
}
bool StereoMatchParamEntity::getSGBM_MODEL_HH4() {
	return SGBM_MODEL_HH4;
}

void StereoMatchParamEntity::setSGBM_MODEL_Default(bool value) {
	SGBM_MODEL_Default = value;
	emit paramChanged_SGBM_MODEL_Default();
}
bool StereoMatchParamEntity::getSGBM_MODEL_Default() {
	return SGBM_MODEL_Default;
}

void StereoMatchParamEntity::setSGBM_MODEL_HH(bool value)
{
	SGBM_MODEL_HH = value;
	emit paramChanged_SGBM_MODEL_HH();
}

bool StereoMatchParamEntity::getSGBM_MODEL_HH()
{
	return SGBM_MODEL_HH;
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

StereoMatchParamEntity::IMGID StereoMatchParamEntity::getImageToShow()
{
	return ImageToShow;
}

void StereoMatchParamEntity::setImageToShow(StereoMatchParamEntity::IMGID value)
{
	ImageToShow = value;
	emit paramChanged_ImageToShow();
}
