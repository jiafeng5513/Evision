#include "StereoMatchView.h"
#include "EvisionUtils.h"
#include "math.h"
//#include<qDebug>
#include <QMessageBox>

StereoMatchView::StereoMatchView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_entity = StereoMatchParamEntity::getInstance();
	m_controller = new StereoMatchController();
	connect(m_entity, SIGNAL(paramChanged_BM()), this, SLOT(onParamChanged_BM()));
	connect(m_entity, SIGNAL(paramChanged_SGBM()), this, SLOT(onParamChanged_SGBM()));
	connect(m_entity, SIGNAL(paramChanged_ELAS()), this, SLOT(onParamChanged_ELAS()));
	connect(m_entity, SIGNAL(paramChanged_ADCensus()), this, SLOT(onParamChanged_ADCensus()));
	connect(m_entity, SIGNAL(paramChanged_ImageDtoShow()), this, SLOT(onParamChanged_imgDtoShow()));
	connect(m_entity, SIGNAL(paramChanged_IconImgL()), this, SLOT(onParamChanged_IconImgL()));
	connect(m_entity, SIGNAL(paramChanged_IconImgR()), this, SLOT(onParamChanged_IconImgR()));
	connect(m_entity, SIGNAL(paramChanged_IconRawDisp()), this, SLOT(onParamChanged_IconRawDisp()));
	connect(m_entity, SIGNAL(paramChanged_IconRainbow()), this, SLOT(onParamChanged_IconRainbow()));
	connect(m_entity, SIGNAL(paramChanged_ImageToShow()), this, SLOT(onParamChanged_ImageToShow()));
	connect(m_entity, SIGNAL(paramChanged_dMin()), this, SLOT(onParamChanged_DMin()));
	connect(m_entity, SIGNAL(paramChanged_dMax()), this, SLOT(onParamChanged_DMax()));
	connect(m_entity, SIGNAL(paramChanged_censusWinH()), this, SLOT(onParamChanged_CensusWinH()));
	connect(m_entity, SIGNAL(paramChanged_censusWinW()), this, SLOT(onParamChanged_CensusWinW()));
	connect(m_entity, SIGNAL(paramChanged_defaultBorderCost()), this, SLOT(onParamChanged_DefaultBorderCost()));
	connect(m_entity, SIGNAL(paramChanged_lambdaAD()), this, SLOT(onParamChanged_LambdaAD()));
	connect(m_entity, SIGNAL(paramChanged_lambdaCensus()), this, SLOT(onParamChanged_LambdaCensus()));
	connect(m_entity, SIGNAL(paramChanged_aggregatingIterations()), this, SLOT(onParamChanged_AggregatingIterations()));
	connect(m_entity, SIGNAL(paramChanged_colorThreshold1()), this, SLOT(onParamChanged_ColorThreshold1()));
	connect(m_entity, SIGNAL(paramChanged_colorThreshold2()), this, SLOT(onParamChanged_ColorThreshold2()));
	connect(m_entity, SIGNAL(paramChanged_maxLength1()), this, SLOT(onParamChanged_MaxLength1()));
	connect(m_entity, SIGNAL(paramChanged_maxLength2()), this, SLOT(onParamChanged_MaxLength2()));
	connect(m_entity, SIGNAL(paramChanged_colorDifference()), this, SLOT(onParamChanged_ColorDifference()));
	connect(m_entity, SIGNAL(paramChanged_pi1()), this, SLOT(onParamChanged_Pi1()));
	connect(m_entity, SIGNAL(paramChanged_pi2()), this, SLOT(onParamChanged_Pi2()));
	connect(m_entity, SIGNAL(paramChanged_dispTolerance()), this, SLOT(onParamChanged_DispTolerance()));
	connect(m_entity, SIGNAL(paramChanged_votingThreshold()), this, SLOT(onParamChanged_VotingThreshold()));
	connect(m_entity, SIGNAL(paramChanged_votingRatioThreshold()), this, SLOT(onParamChanged_VotingRatioThreshold()));
	connect(m_entity, SIGNAL(paramChanged_maxSearchDepth()), this, SLOT(onParamChanged_MaxSearchDepth()));
	connect(m_entity, SIGNAL(paramChanged_cannyThreshold1()), this, SLOT(onParamChanged_CannyThreshold1()));
	connect(m_entity, SIGNAL(paramChanged_cannyThreshold2()), this, SLOT(onParamChanged_CannyThreshold2()));
	connect(m_entity, SIGNAL(paramChanged_cannyKernelSize()), this, SLOT(onParamChanged_CannyKernelSize()));
	connect(m_entity, SIGNAL(paramChanged_blurKernelSize()), this, SLOT(onParamChanged_BlurKernelSize()));
	connect(m_entity, SIGNAL(paramChanged_disp_min()), this, SLOT(onParamChanged_DispMin()));
	connect(m_entity, SIGNAL(paramChanged_disp_max()), this, SLOT(onParamChanged_DispMax()));
	connect(m_entity, SIGNAL(paramChanged_support_threshold()), this, SLOT(onParamChanged_SupportThreshold()));
	connect(m_entity, SIGNAL(paramChanged_support_texture()), this, SLOT(onParamChanged_SupportTexture()));
	connect(m_entity, SIGNAL(paramChanged_candidate_stepsize()), this, SLOT(onParamChanged_CandidateStepsize()));
	connect(m_entity, SIGNAL(paramChanged_incon_window_size()), this, SLOT(onParamChanged_InconWindowSize()));
	connect(m_entity, SIGNAL(paramChanged_incon_threshold()), this, SLOT(onParamChanged_InconThreshold()));
	connect(m_entity, SIGNAL(paramChanged_incon_min_support()), this, SLOT(onParamChanged_InconMinSupport()));
	connect(m_entity, SIGNAL(paramChanged_add_corners()), this, SLOT(onParamChanged_AddCorners()));
	connect(m_entity, SIGNAL(paramChanged_grid_size()), this, SLOT(onParamChanged_GridSize()));
	connect(m_entity, SIGNAL(paramChanged_beta()), this, SLOT(onParamChanged_Beta()));
	connect(m_entity, SIGNAL(paramChanged_gamma()), this, SLOT(onParamChanged_Gamma()));
	connect(m_entity, SIGNAL(paramChanged_sigma()), this, SLOT(onParamChanged_Sigma()));
	connect(m_entity, SIGNAL(paramChanged_sradius()), this, SLOT(onParamChanged_Sradius()));
	connect(m_entity, SIGNAL(paramChanged_match_texture()), this, SLOT(onParamChanged_MatchTexture()));
	connect(m_entity, SIGNAL(paramChanged_lr_threshold()), this, SLOT(onParamChanged_LrThreshold()));
	connect(m_entity, SIGNAL(paramChanged_speckle_sim_threshold()), this, SLOT(onParamChanged_SpeckleSimThreshold()));
	connect(m_entity, SIGNAL(paramChanged_speckle_size()), this, SLOT(onParamChanged_SpeckleSize()));
	connect(m_entity, SIGNAL(paramChanged_ipol_gap_width()), this, SLOT(onParamChanged_IpolGapWidth()));
	connect(m_entity, SIGNAL(paramChanged_filter_median()), this, SLOT(onParamChanged_FilterMedian()));
	connect(m_entity, SIGNAL(paramChanged_filter_adaptive_mean()), this, SLOT(onParamChanged_FilterAdaptiveMean()));
	connect(m_entity, SIGNAL(paramChanged_postprocess_only_left()), this, SLOT(onParamChanged_PostprocessOnlyLeft()));
	connect(m_entity, SIGNAL(paramChanged_subsampling()), this, SLOT(onParamChanged_SubSampling()));

	connect(m_entity, SIGNAL(paramChanged_BM_preFilterType_NORMALIZED()), this, SLOT(onParamChanged_BM_preFilterType_NORMALIZED()));
	connect(m_entity, SIGNAL(paramChanged_BM_preFilterType_XSOBEL()), this, SLOT(onParamChanged_BM_preFilterType_XSOBEL()));
	connect(m_entity, SIGNAL(paramChanged_BM_preFilterSize()), this, SLOT(onParamChanged_BM_preFilterSize()));
	connect(m_entity, SIGNAL(paramChanged_BM_preFilterCap()), this, SLOT(onParamChanged_BM_preFilterCap()));
	connect(m_entity, SIGNAL(paramChanged_BM_SADWindowSize()), this, SLOT(onParamChanged_BM_SADWindowSize()));
	connect(m_entity, SIGNAL(paramChanged_BM_minDisparity()), this, SLOT(onParamChanged_BM_minDisparity()));
	connect(m_entity, SIGNAL(paramChanged_BM_numDisparities()), this, SLOT(onParamChanged_BM_numDisparities()));
	connect(m_entity, SIGNAL(paramChanged_BM_textureThreshold()), this, SLOT(onParamChanged_BM_textureThreshold()));
	connect(m_entity, SIGNAL(paramChanged_BM_uniquenessRatio()), this, SLOT(onParamChanged_BM_uniquenessRatio()));
	connect(m_entity, SIGNAL(paramChanged_BM_speckleRange()), this, SLOT(onParamChanged_BM_speckleRange()));
	connect(m_entity, SIGNAL(paramChanged_BM_speckleWindowSize()), this, SLOT(onParamChanged_BM_speckleWindowSize()));
	connect(m_entity, SIGNAL(paramChanged_BM_disp12MaxDiff()), this, SLOT(onParamChanged_BM_disp12MaxDiff()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_minDisparity()), this, SLOT(onParamChanged_SGBM_minDisparity()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_numDisparities()), this, SLOT(onParamChanged_SGBM_numDisparities()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_blockSize()), this, SLOT(onParamChanged_SGBM_blockSize()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_P1()), this, SLOT(onParamChanged_SGBM_P1()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_P2()), this, SLOT(onParamChanged_SGBM_P2()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_disp12MaxDiff()), this, SLOT(onParamChanged_SGBM_disp12MaxDiff()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_preFilterCap()), this, SLOT(onParamChanged_SGBM_preFilterCap()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_uniquenessRatio()), this, SLOT(onParamChanged_SGBM_uniquenessRatio()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_speckleWindowSize()), this, SLOT(onParamChanged_SGBM_speckleWindowSize()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_speckleRange()), this, SLOT(onParamChanged_SGBM_speckleRange()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_MODEL_3WAY()), this, SLOT(onParamChanged_SGBM_MODEL_3WAY()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_MODEL_HH4()), this, SLOT(onParamChanged_SGBM_MODEL_HH4()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_MODEL_Default()), this, SLOT(onParamChanged_SGBM_MODEL_Default()));
	connect(m_entity, SIGNAL(paramChanged_SGBM_MODEL_HH()), this, SLOT(onParamChanged_SGBM_MODEL_HH()));

	m_entity->setImageToShow(StereoMatchParamEntity::RAW_DISP);
}

StereoMatchView::~StereoMatchView()
{
}
//默认匹配参数
void StereoMatchView::setDefaultMatchParam()
{
	m_controller->setDefaultMatchParamCommand();
}
//匹配
void StereoMatchView::doMatch()
{
	m_controller->MatchCommand();
}
//刷新匹配结果
void StereoMatchView::RefreshStereoMatch()
{
	m_controller->RefreshStereoMatchCommand();
}
//保存
void StereoMatchView::SaveDisparities()
{
	m_controller->SaveCommand();
}
//显示帮助信息
void StereoMatchView::Help()
{
	QString helpMsg = QStringLiteral("\
算法选择指南\n\n\
1.速度:OpenCV BM>OpenCV SGBM>ELAS>ADCensus\n\
2.效果:ADCensus>ELAS>SGBM>BM\n\
  BM和SGBM的效果和速度类似\n\
3.BM会只能处理灰度图,其他的能处理彩色图,ADCensus在输入彩色图时能获得额外的效果\n\
4.界面上显示的视差图只是示意图,为了能显示在屏幕上,进行了一些处理(例如归一化到[0,255])\n\
  真实的视差数据保存在xml中,测距和三维重建是以原始视差数据为基础的.\n\
5.ADCensus算法在Debug模式下运行速度会非常慢,这是为了便于调试使用多线程模式的方法导致的,\n\
  在Release模式下会表现出正常速度.");
	QMessageBox::information(this, QStringLiteral("帮助"), helpMsg);
}

//1.int
void StereoMatchView::valueChanged_DMin(int value) {
	if (m_entity->getDMin() != value)
		m_entity->setDMin(value);
}
void StereoMatchView::onParamChanged_DMin() {
	ui.spinBox_dMin->setValue(m_entity->getDMin());
}
//2.int
void StereoMatchView::valueChanged_DMax(int value) {
	if (m_entity->getDMax() != value)
		m_entity->setDMax(value);
}
void StereoMatchView::onParamChanged_DMax() {
	ui.spinBox_dMax->setValue(m_entity->getDMax());
}
//3.int
void StereoMatchView::valueChanged_CensusWinH(int value) {
	if (m_entity->getCensusWinH() != value)
		m_entity->setCensusWinH(value);
}
void StereoMatchView::onParamChanged_CensusWinH() {
	ui.spinBox_censusWinW->setValue(m_entity->getCensusWinH());
}
//4.int
void StereoMatchView::valueChanged_CensusWinW(int value) {
	if (m_entity->getCensusWinW() != value)
		m_entity->setCensusWinW(value);
}
void StereoMatchView::onParamChanged_CensusWinW() {
	ui.spinBox_censusWinH->setValue(m_entity->getCensusWinW());
}
//5.float
void StereoMatchView::valueChanged_DefaultBorderCost(double value) {
	if (m_entity->getDefaultBorderCost() != value)
		m_entity->setDefaultBorderCost(value);
}
void StereoMatchView::onParamChanged_DefaultBorderCost() {
	ui.doubleSpinBox_defaultBorderCost->setValue(m_entity->getDefaultBorderCost());
}
//6.float
void StereoMatchView::valueChanged_LambdaAD(double value) {
	if (m_entity->getLambdaAD() != value)
		m_entity->setLambdaAD(value);
}
void StereoMatchView::onParamChanged_LambdaAD() {
	ui.doubleSpinBox_lambdaAD->setValue(m_entity->getLambdaAD());
}
//7.float
void StereoMatchView::valueChanged_LambdaCensus(double value) {
	if (m_entity->getLambdaCensus() != value)
		m_entity->setLambdaCensus(value);
}
void StereoMatchView::onParamChanged_LambdaCensus() {
	ui.doubleSpinBox_lambdaCensus->setValue(m_entity->getLambdaCensus());
}
//8.int
void StereoMatchView::valueChanged_AggregatingIterations(int value) {
	if (m_entity->getAggregatingIterations() != value)
		m_entity->setAggregatingIterations(value);
}
void StereoMatchView::onParamChanged_AggregatingIterations() {
	ui.spinBox_aggregatingIterations->setValue(m_entity->getAggregatingIterations());
}
//9.int
void StereoMatchView::valueChanged_ColorThreshold1(int value) {
	if (m_entity->getColorThreshold1() != value)
		m_entity->setColorThreshold1(value);
}
void StereoMatchView::onParamChanged_ColorThreshold1() {
	ui.spinBox_colorThreshold1->setValue(m_entity->getColorThreshold1());
}
//10.int
void StereoMatchView::valueChanged_ColorThreshold2(int value) {
	if (m_entity->getColorThreshold2() != value)
		m_entity->setColorThreshold2(value);
}
void StereoMatchView::onParamChanged_ColorThreshold2() {
	ui.spinBox_colorThreshold2->setValue(m_entity->getColorThreshold2());
}
//11.int
void StereoMatchView::valueChanged_MaxLength1(int value) {
	if (m_entity->getMaxLength1() != value)
		m_entity->setMaxLength1(value);
}
void StereoMatchView::onParamChanged_MaxLength1() {
	ui.spinBox_maxLength1->setValue(m_entity->getMaxLength1());
}
//12.int
void StereoMatchView::valueChanged_MaxLength2(int value) {
	if (m_entity->getMaxLength2() != value)
		m_entity->setMaxLength2(value);
}
void StereoMatchView::onParamChanged_MaxLength2() {
	ui.spinBox_maxLength2->setValue(m_entity->getMaxLength2());
}
//13.int
void StereoMatchView::valueChanged_ColorDifference(int value) {
	if (m_entity->getColorDifference() != value)
		m_entity->setColorDifference(value);
}
void StereoMatchView::onParamChanged_ColorDifference() {
	ui.spinBox_colorDifference->setValue(m_entity->getColorDifference());
}
//14.float
void StereoMatchView::valueChanged_Pi1(double value) {
	if (m_entity->getPi1() != value)
		m_entity->setPi1(value);
}
void StereoMatchView::onParamChanged_Pi1() {
	ui.doubleSpinBox_pi1->setValue(m_entity->getPi1());
}
//15.float
void StereoMatchView::valueChanged_Pi2(double value) {
	if (m_entity->getPi2() != value)
		m_entity->setPi2(value);
}
void StereoMatchView::onParamChanged_Pi2() {
	ui.doubleSpinBox_pi2->setValue(m_entity->getPi2());
}
//16.int
void StereoMatchView::valueChanged_DispTolerance(int value) {
	if (m_entity->getDispTolerance() != value)
		m_entity->setDispTolerance(value);
}
void StereoMatchView::onParamChanged_DispTolerance() {
	ui.spinBox_dispTolerance->setValue(m_entity->getDispTolerance());
}
//17.int
void StereoMatchView::valueChanged_VotingThreshold(int value) {
	if (m_entity->getVotingThreshold() != value)
		m_entity->setVotingThreshold(value);
}
void StereoMatchView::onParamChanged_VotingThreshold() {
	ui.spinBox_votingThreshold->setValue(m_entity->getVotingThreshold());
}
//18.float
void StereoMatchView::valueChanged_VotingRatioThreshold(double value) {
	if (m_entity->getVotingRatioThreshold() != value)
		m_entity->setVotingRatioThreshold(value);
}
void StereoMatchView::onParamChanged_VotingRatioThreshold() {
	ui.doubleSpinBox_votingRatioThreshold->setValue(m_entity->getVotingRatioThreshold());
}
//19.int
void StereoMatchView::valueChanged_MaxSearchDepth(int value) {
	if (m_entity->getMaxSearchDepth() != value)
		m_entity->setMaxSearchDepth(value);
}
void StereoMatchView::onParamChanged_MaxSearchDepth() {
	ui.spinBox_maxSearchDepth->setValue(m_entity->getMaxSearchDepth());
}
//20.int
void StereoMatchView::valueChanged_CannyThreshold1(int value) {
	if (m_entity->getCannyThreshold1() != value)
		m_entity->setCannyThreshold1(value);
}
void StereoMatchView::onParamChanged_CannyThreshold1() {
	ui.spinBox_cannyThreshold1->setValue(m_entity->getCannyThreshold1());
}
//21.int
void StereoMatchView::valueChanged_CannyThreshold2(int value) {
	if (m_entity->getCannyThreshold2() != value)
		m_entity->setCannyThreshold2(value);
}
void StereoMatchView::onParamChanged_CannyThreshold2() {
	ui.spinBox_cannyThreshold2->setValue(m_entity->getCannyThreshold2());
}
//22.int
void StereoMatchView::valueChanged_CannyKernelSize(int value) {
	if (m_entity->getCannyKernelSize() != value)
		m_entity->setCannyKernelSize(value);
}
void StereoMatchView::onParamChanged_CannyKernelSize() {
	ui.spinBox_cannyKernelSize->setValue(m_entity->getCannyKernelSize());
}
//23.int
void StereoMatchView::valueChanged_BlurKernelSize(int value) {
	if (m_entity->getBlurKernelSize() != value)
		m_entity->setBlurKernelSize(value);
}
void StereoMatchView::onParamChanged_BlurKernelSize() {
	ui.spinBox_blurKernelSize->setValue(m_entity->getBlurKernelSize());
}

void StereoMatchView::valueChanged_DispMin(int value) {
	if (m_entity->getDispMin() != value)
	{
		m_entity->setDispMin(value);
	}
}
void StereoMatchView::onParamChanged_DispMin() {
	ui.spinBox_disp_min->setValue(m_entity->getDispMin());
}
void StereoMatchView::valueChanged_DispMax(int value) {
	if (m_entity->getDispMax() != value)
	{
		m_entity->setDispMax(value);
	}
}
void StereoMatchView::onParamChanged_DispMax() {
	ui.spinBox_disp_max->setValue(m_entity->getDispMax());
}
void StereoMatchView::valueChanged_SupportThreshold(double value) {
	if (m_entity->getSupportThreshold() != value)
	{
		m_entity->setSupportThreshold(value);
	}
}
void StereoMatchView::onParamChanged_SupportThreshold() {
	ui.doubleSpinBox_support_threshold->setValue(m_entity->getSupportThreshold());
}
void StereoMatchView::valueChanged_SupportTexture(int value) {
	if (m_entity->getSupportTexture() != value)
	{
		m_entity->setSupportTexture(value);
	}
}
void StereoMatchView::onParamChanged_SupportTexture() {
	ui.spinBox_support_texture->setValue(m_entity->getSupportTexture());
}
void StereoMatchView::valueChanged_CandidateStepsize(int value) {
	if (m_entity->getCandidateStepsize() != value)
	{
		m_entity->setCandidateStepsize(value);
	}
}
void StereoMatchView::onParamChanged_CandidateStepsize() {
	ui.spinBox_candidate_stepsize->setValue(m_entity->getCandidateStepsize());
}
void StereoMatchView::valueChanged_InconWindowSize(int value) {
	if (m_entity->getInconWindowSize() != value)
	{
		m_entity->setInconWindowSize(value);
	}
}
void StereoMatchView::onParamChanged_InconWindowSize() {
	ui.spinBox_incon_window_size->setValue(m_entity->getInconWindowSize());
}
void StereoMatchView::valueChanged_InconThreshold(int value) {
	if (m_entity->getInconThreshold() != value)
	{
		m_entity->setInconThreshold(value);
	}
}
void StereoMatchView::onParamChanged_InconThreshold() {
	ui.spinBox_incon_threshold->setValue(m_entity->getInconThreshold());
}
void StereoMatchView::valueChanged_InconMinSupport(int value) {
	if (m_entity->getInconMinSupport() != value)
	{
		m_entity->setInconMinSupport(value);
	}
}
void StereoMatchView::onParamChanged_InconMinSupport() {
	ui.spinBox_incon_min_support->setValue(m_entity->getInconMinSupport());
}
void StereoMatchView::valueChanged_AddCorners(bool value) {
	if (m_entity->getAddCorners() != value)
	{
		m_entity->setAddCorners(value);
	}
}
void StereoMatchView::onParamChanged_AddCorners() {
	ui.checkBox_add_corners->setChecked(m_entity->getAddCorners());
}
void StereoMatchView::valueChanged_GridSize(int value) {
	if (m_entity->getGridSize() != value)
	{
		m_entity->setGridSize(value);
	}
}
void StereoMatchView::onParamChanged_GridSize() {
	ui.spinBox_grid_size->setValue(m_entity->getGridSize());
}
void StereoMatchView::valueChanged_Beta(double value) {
	if (m_entity->getBeta() != value)
	{
		m_entity->setBeta(value);
	}
}
void StereoMatchView::onParamChanged_Beta() {
	ui.doubleSpinBox_beta->setValue(m_entity->getBeta());
}
void StereoMatchView::valueChanged_Gamma(double value) {
	if (m_entity->getGamma() != value)
	{
		m_entity->setGamma(value);
	}
}
void StereoMatchView::onParamChanged_Gamma() {
	ui.doubleSpinBox_gamma->setValue(m_entity->getGamma());
}
void StereoMatchView::valueChanged_Sigma(double value) {
	if (m_entity->getSigma() != value)
	{
		m_entity->setSigma(value);
	}
}
void StereoMatchView::onParamChanged_Sigma() {
	ui.doubleSpinBox_sigma->setValue(m_entity->getSigma());
}
void StereoMatchView::valueChanged_Sradius(double value) {
	if (m_entity->getSradius() != value)
	{
		m_entity->setSradius(value);
	}
}
void StereoMatchView::onParamChanged_Sradius() {
	ui.doubleSpinBox_sradius->setValue(m_entity->getSradius());
}
void StereoMatchView::valueChanged_MatchTexture(int value) {
	if (m_entity->getMatchTexture() != value)
	{
		m_entity->setMatchTexture(value);
	}
}
void StereoMatchView::onParamChanged_MatchTexture() {
	ui.spinBox_match_texture->setValue(m_entity->getMatchTexture());
}
void StereoMatchView::valueChanged_LrThreshold(int value) {
	if (m_entity->getLrThreshold() != value)
	{
		m_entity->setLrThreshold(value);
	}
}
void StereoMatchView::onParamChanged_LrThreshold() {
	ui.spinBox_lr_threshold->setValue(m_entity->getLrThreshold());
}
void StereoMatchView::valueChanged_SpeckleSimThreshold(double value) {
	if (m_entity->getSpeckleSimThreshold() != value)
	{
		m_entity->setSpeckleSimThreshold(value);
	}
}
void StereoMatchView::onParamChanged_SpeckleSimThreshold() {
	ui.doubleSpinBox_speckle_sim_threshold->setValue(m_entity->getSpeckleSimThreshold());
}
void StereoMatchView::valueChanged_SpeckleSize(int value) {
	if (m_entity->getSpeckleSize() != value)
	{
		m_entity->setSpeckleSize(value);
	}
}
void StereoMatchView::onParamChanged_SpeckleSize() {
	ui.spinBox_speckle_size->setValue(m_entity->getSpeckleSize());
}
void StereoMatchView::valueChanged_IpolGapWidth(int value) {
	if (m_entity->getIpolGapWidth() != value)
	{
		m_entity->setIpolGapWidth(value);
	}
}
void StereoMatchView::onParamChanged_IpolGapWidth() {
	ui.spinBox_ipol_gap_width->setValue(m_entity->getIpolGapWidth());
}
void StereoMatchView::valueChanged_FilterMedian(bool value) {
	if (m_entity->getFilterMedian() != value)
	{
		m_entity->setFilterMedian(value);
	}
}
void StereoMatchView::onParamChanged_FilterMedian() {
	ui.checkBox_filter_median->setChecked(m_entity->getFilterMedian());
}
void StereoMatchView::valueChanged_FilterAdaptiveMean(bool value) {
	if (m_entity->getFilterAdaptiveMean() != value)
	{
		m_entity->setFilterAdaptiveMean(value);
	}
}
void StereoMatchView::onParamChanged_FilterAdaptiveMean() {
	ui.checkBox_filter_adaptive_mean->setChecked(m_entity->getFilterAdaptiveMean());
}
void StereoMatchView::valueChanged_PostprocessOnlyLeft(bool value) {
	if (m_entity->getPostprocessOnlyLeft() != value)
	{
		m_entity->setPostprocessOnlyLeft(value);
	}
}
void StereoMatchView::onParamChanged_PostprocessOnlyLeft() {
	ui.checkBox_postprocess_only_left->setChecked(m_entity->getPostprocessOnlyLeft());
}
void StereoMatchView::valueChanged_SubSampling(bool value) {
	if (m_entity->getSubSampling() != value)
	{
		m_entity->setSubSampling(value);
	}
}
void StereoMatchView::onParamChanged_SubSampling() {
	ui.checkBox_subsampling->setChecked(m_entity->getSubSampling());
}


void StereoMatchView::onClicked_BM(bool value)
{
	if (m_entity->getBM() != value)
	{
		m_entity->setBM(value);
	}
	ui.stackedWidget->setCurrentIndex(0);
}

void StereoMatchView::onParamChanged_BM()
{
	ui.radioButton_BM->setChecked(m_entity->getBM());

}

void StereoMatchView::onClicked_SGBM(bool value)
{
	if (m_entity->getSGBM() != value)
	{
		m_entity->setSGBM(value);
	}
	ui.stackedWidget->setCurrentIndex(1);
}

void StereoMatchView::onParamChanged_SGBM()
{
	ui.radioButton_SGBM->setChecked(m_entity->getSGBM());

}

void StereoMatchView::onClicked_ELAS(bool value)
{
	if (m_entity->getElas() != value)
	{
		m_entity->setElas(value);
	}
	ui.stackedWidget->setCurrentIndex(2);
}

void StereoMatchView::onParamChanged_ELAS()
{
	ui.radioButton_ELAS->setChecked(m_entity->getElas());
}

void StereoMatchView::onClicked_ADCensus(bool value)
{
	if(m_entity->getADCensus()!=value)
	{
		m_entity->setADCensus(value);
	}
	ui.stackedWidget->setCurrentIndex(3);
}

void StereoMatchView::onParamChanged_ADCensus()
{
	ui.radioButton_ADC->setChecked(m_entity->getADCensus());
}

void StereoMatchView::valueChanged_BM_preFilterType_NORMALIZED(bool value) {
	if (m_entity->getBM_preFilterType_NORMALIZED() != value)
	{
		m_entity->setBM_preFilterType_NORMALIZED(value);
	}
}
void StereoMatchView::onParamChanged_BM_preFilterType_NORMALIZED() {
	ui.radioButton_BM_Prefilter_Normalzed->setChecked(m_entity->getBM_preFilterType_NORMALIZED());
}
void StereoMatchView::valueChanged_BM_preFilterType_XSOBEL(bool value) {
	if (m_entity->getBM_preFilterType_XSOBEL() != value)
	{
		m_entity->setBM_preFilterType_XSOBEL(value);
	}
}
void StereoMatchView::onParamChanged_BM_preFilterType_XSOBEL() {
	ui.radioButton_BM_Prefilter_XSobel->setChecked(m_entity->getBM_preFilterType_XSOBEL());
}
void StereoMatchView::valueChanged_BM_preFilterSize(int value) {
	if (m_entity->getBM_preFilterSize() != value)
	{
		m_entity->setBM_preFilterSize(value);
	}
}
void StereoMatchView::onParamChanged_BM_preFilterSize() {
	ui.spinBox_BM_preFilterSize->setValue(m_entity->getBM_preFilterSize());
}
void StereoMatchView::valueChanged_BM_preFilterCap(int value) {
	if (m_entity->getBM_preFilterCap() != value)
	{
		m_entity->setBM_preFilterCap(value);
	}
}
void StereoMatchView::onParamChanged_BM_preFilterCap() {
	ui.spinBox_BM_preFilterCap->setValue(m_entity->getBM_preFilterCap());
}
void StereoMatchView::valueChanged_BM_SADWindowSize(int value) {
	if (m_entity->getBM_SADWindowSize() != value)
	{
		m_entity->setBM_SADWindowSize(value);
	}
}
void StereoMatchView::onParamChanged_BM_SADWindowSize() {
	ui.spinBox_BM_SADWindowSize->setValue(m_entity->getBM_SADWindowSize());
}
void StereoMatchView::valueChanged_BM_minDisparity(int value) {
	if (m_entity->getBM_minDisparity() != value)
	{
		m_entity->setBM_minDisparity(value);
	}
}
void StereoMatchView::onParamChanged_BM_minDisparity() {
	ui.spinBox_BM_minDisparity->setValue(m_entity->getBM_minDisparity());
}
void StereoMatchView::valueChanged_BM_numDisparities(int value) {
	if (m_entity->getBM_numDisparities() != value)
	{
		m_entity->setBM_numDisparities(value);
	}
}
void StereoMatchView::onParamChanged_BM_numDisparities() {
	ui.spinBox_BM_numDisparities->setValue(m_entity->getBM_numDisparities());
}
void StereoMatchView::valueChanged_BM_textureThreshold(int value) {
	if (m_entity->getBM_textureThreshold() != value)
	{
		m_entity->setBM_textureThreshold(value);
	}
}
void StereoMatchView::onParamChanged_BM_textureThreshold() {
	ui.spinBox_BM_textureThreshold->setValue(m_entity->getBM_textureThreshold());
}
void StereoMatchView::valueChanged_BM_uniquenessRatio(int value) {
	if (m_entity->getBM_uniquenessRatio() != value)
	{
		m_entity->setBM_uniquenessRatio(value);
	}
}
void StereoMatchView::onParamChanged_BM_uniquenessRatio() {
	ui.spinBox_BM_uniquenessRatio->setValue(m_entity->getBM_uniquenessRatio());
}
void StereoMatchView::valueChanged_BM_speckleRange(int value) {
	if (m_entity->getBM_speckleRange() != value)
	{
		m_entity->setBM_speckleRange(value);
	}
}
void StereoMatchView::onParamChanged_BM_speckleRange() {
	ui.spinBox_BM_speckleRange->setValue(m_entity->getBM_speckleRange());
}
void StereoMatchView::valueChanged_BM_speckleWindowSize(int value) {
	if (m_entity->getBM_speckleWindowSize() != value)
	{
		m_entity->setBM_speckleWindowSize(value);
	}
}
void StereoMatchView::onParamChanged_BM_speckleWindowSize() {
	ui.spinBox_BM_speckleWindowSize->setValue(m_entity->getBM_speckleWindowSize());
}
void StereoMatchView::valueChanged_BM_disp12MaxDiff(int value) {
	if (m_entity->getBM_disp12MaxDiff() != value)
	{
		m_entity->setBM_disp12MaxDiff(value);
	}
}
void StereoMatchView::onParamChanged_BM_disp12MaxDiff() {
	ui.spinBox_BM_disp12MaxDiff->setValue(m_entity->getBM_disp12MaxDiff());
}
void StereoMatchView::valueChanged_SGBM_minDisparity(int value) {
	if (m_entity->getSGBM_minDisparity() != value)
	{
		m_entity->setSGBM_minDisparity(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_minDisparity() {
	ui.spinBox_SGBM_minDisparity->setValue(m_entity->getSGBM_minDisparity());
}
void StereoMatchView::valueChanged_SGBM_numDisparities(int value) {
	if (m_entity->getSGBM_numDisparities() != value)
	{
		m_entity->setSGBM_numDisparities(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_numDisparities() {
	ui.spinBox_SGBM_numDisparities->setValue(m_entity->getSGBM_numDisparities());
}
void StereoMatchView::valueChanged_SGBM_blockSize(int value) {
	if (m_entity->getSGBM_blockSize() != value)
	{
		m_entity->setSGBM_blockSize(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_blockSize() {
	ui.spinBox_SGBM_blockSize->setValue(m_entity->getSGBM_blockSize());
}
void StereoMatchView::valueChanged_SGBM_P1(int value) {
	if (m_entity->getSGBM_P1() != value)
	{
		m_entity->setSGBM_P1(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_P1() {
	ui.spinBox_SGBM_P1->setValue(m_entity->getSGBM_P1());
}
void StereoMatchView::valueChanged_SGBM_P2(int value) {
	if (m_entity->getSGBM_P2() != value)
	{
		m_entity->setSGBM_P2(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_P2() {
	ui.spinBox_SGBM_P2->setValue(m_entity->getSGBM_P2());
}
void StereoMatchView::valueChanged_SGBM_disp12MaxDiff(int value) {
	if (m_entity->getSGBM_disp12MaxDiff() != value)
	{
		m_entity->setSGBM_disp12MaxDiff(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_disp12MaxDiff() {
	ui.spinBox_SGBM_disp12MaxDiff->setValue(m_entity->getSGBM_disp12MaxDiff());
}
void StereoMatchView::valueChanged_SGBM_preFilterCap(int value) {
	if (m_entity->getSGBM_preFilterCap() != value)
	{
		m_entity->setSGBM_preFilterCap(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_preFilterCap() {
	ui.spinBox_SGBM_preFilterCap->setValue(m_entity->getSGBM_preFilterCap());
}
void StereoMatchView::valueChanged_SGBM_uniquenessRatio(int value) {
	if (m_entity->getSGBM_uniquenessRatio() != value)
	{
		m_entity->setSGBM_uniquenessRatio(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_uniquenessRatio() {
	ui.spinBox_SGBM_uniquenessRatio->setValue(m_entity->getSGBM_uniquenessRatio());
}
void StereoMatchView::valueChanged_SGBM_speckleWindowSize(int value) {
	if (m_entity->getSGBM_speckleWindowSize() != value)
	{
		m_entity->setSGBM_speckleWindowSize(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_speckleWindowSize() {
	ui.spinBox_SGBM_speckleWindowSize->setValue(m_entity->getSGBM_speckleWindowSize());
}
void StereoMatchView::valueChanged_SGBM_speckleRange(int value) {
	if (m_entity->getSGBM_speckleRange() != value)
	{
		m_entity->setSGBM_speckleRange(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_speckleRange() {
	ui.spinBox_SGBM_speckleRange->setValue(m_entity->getSGBM_speckleRange());
}
void StereoMatchView::valueChanged_SGBM_MODEL_3WAY(bool value) {
	if (m_entity->getSGBM_MODEL_3WAY() != value)
	{
		m_entity->setSGBM_MODEL_3WAY(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_MODEL_3WAY() {
	ui.radioButton_SGBM_MODEL_3WAY->setChecked(m_entity->getSGBM_MODEL_3WAY());
}
void StereoMatchView::valueChanged_SGBM_MODEL_HH4(bool value) {
	if (m_entity->getSGBM_MODEL_HH4() != value)
	{
		m_entity->setSGBM_MODEL_HH4(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_MODEL_HH4() {
	ui.radioButton_SGBM_MODEL_HH4->setChecked(m_entity->getSGBM_MODEL_HH4());
}
void StereoMatchView::valueChanged_SGBM_MODEL_Default(bool value) {
	if (m_entity->getSGBM_MODEL_Default() != value)
	{
		m_entity->setSGBM_MODEL_Default(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_MODEL_Default() {
	ui.radioButton_SGBM_MODEL_Default->setChecked(m_entity->getSGBM_MODEL_Default());
}

void StereoMatchView::valueChanged_SGBM_MODEL_HH(bool value)
{
	if (m_entity->getSGBM_MODEL_HH4() != value)
	{
		m_entity->setSGBM_MODEL_HH4(value);
	}
}
void StereoMatchView::onParamChanged_SGBM_MODEL_HH()
{
	ui.radioButton_SGBM_MODEL_HH->setChecked(m_entity->getSGBM_MODEL_HH());
}

void StereoMatchView::onParamChanged_imgDtoShow()
{
	QImage DQImage = (m_entity->getImageDtoShow().empty()?EvisionUtils::getDefaultImage():EvisionUtils::cvMat2QImage(m_entity->getImageDtoShow()));
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_D->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_D->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_D->centerOn(0, 0);
	ui.graphicsView_D->show();
	ui.graphicsView_D->update();
}

void StereoMatchView::onParamChanged_IconImgL()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconImgL());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_ImageL->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_ImageL->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_ImageL->centerOn(0, 0);
	ui.graphicsView_ImageL->show();
	ui.graphicsView_ImageL->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::IMG_L)
	{
		m_entity->setImageDtoShow(m_entity->getIconImgL());
	}
}

void StereoMatchView::onParamChanged_IconImgR()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconImgR());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_ImageR->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_ImageR->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_ImageR->centerOn(0, 0);
	ui.graphicsView_ImageR->show();
	ui.graphicsView_ImageR->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::IMG_R)
	{
		m_entity->setImageDtoShow(m_entity->getIconImgR());
	}
}

void StereoMatchView::onParamChanged_IconRawDisp()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconRawDisp());
	QGraphicsScene *sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_RawDisp->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_RawDisp->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_RawDisp->centerOn(0, 0);
	ui.graphicsView_RawDisp->show();
	ui.graphicsView_RawDisp->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::RAW_DISP)
	{
		m_entity->setImageDtoShow(m_entity->getIconRawDisp());
	}
}

void StereoMatchView::onParamChanged_IconRainbow()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getIconRainbow());
	QGraphicsScene* sceneD = new QGraphicsScene;
	sceneD->addPixmap(QPixmap::fromImage(DQImage));
	ui.graphicsView_Rainbow->setScene(sceneD);
	QRectF bounds = sceneD->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_Rainbow->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_Rainbow->centerOn(0, 0);
	ui.graphicsView_Rainbow->show();
	ui.graphicsView_Rainbow->update();
	if (m_entity->getImageToShow() == StereoMatchParamEntity::RAINBOW)
	{
		m_entity->setImageDtoShow(m_entity->getIconRainbow());
	}
}


//要在中间放大显示的图片发生变更
void StereoMatchView::onParamChanged_ImageToShow()
{
	//根据枚举值调整单选框的状态
	ui.radioButton_ImageL->setChecked(false);
	ui.radioButton_ImageR->setChecked(false);
	ui.radioButton_RawDisp->setChecked(false);
	ui.radioButton_Rainbow->setChecked(false);
	switch (m_entity->getImageToShow())
	{
	case StereoMatchParamEntity::IMG_L:
		ui.radioButton_ImageL->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconImgL());
		break;
	case StereoMatchParamEntity::IMG_R:
		ui.radioButton_ImageR->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconImgR());
		break;
	case StereoMatchParamEntity::RAW_DISP:
		ui.radioButton_RawDisp->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconRawDisp());
		break;
	case StereoMatchParamEntity::RAINBOW:
		ui.radioButton_Rainbow->setChecked(true);
		m_entity->setImageDtoShow(m_entity->getIconRainbow());
		break;
	default:
		break;
	}
}

void StereoMatchView::onClicked_IconImgL(bool value)
{
	if(m_entity->getImageToShow()!=StereoMatchParamEntity::IMG_L)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::IMG_L);
	}
}

void StereoMatchView::onClicked_IconImgR(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::IMG_R)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::IMG_R);
	}
}

void StereoMatchView::onClicked_IconRawDisp(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::RAW_DISP)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::RAW_DISP);
	}
}

void StereoMatchView::onClicked_IconRainbow(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::RAINBOW)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::RAINBOW);
	}
}
