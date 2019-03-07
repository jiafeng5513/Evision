#pragma once

#include <QWidget>
#include "ui_MatcherView.h"
#include "StereoMatch.h"
#include "StereoMatchParamEntity.h"
#include "StereoMatchController.h"

class MatcherView : public QWidget
{
	Q_OBJECT

public:
	MatcherView(QWidget *parent = Q_NULLPTR);
	~MatcherView();

private:
	Ui::MatcherView ui;
	StereoMatchParamEntity * m_entity;
	StereoMatchController * m_controller;
public slots:
	void setDefaultMatchParam();
	void doMatch();
	void RefreshStereoMatch();
	void SaveDisparities();
	void Help();
	//匹配参数
	void valueChanged_MinDisp(int value);
	void onParamChanged_MinDisp();

	void valueChanged_uniradio(int value);
	void onParamChanged_uniradio();

	void valueChanged_specwinsz(int value);
	void onParamChanged_specwinsz();

	void valueChanged_NumDisparities(int value);
	void onParamChanged_NumDisparities();
	void onReleased_NumDisparities();//约束:被16 整除

	void valueChanged_Specrange(int value);
	void onParamChanged_Specrange();

	void valueChanged_Prefilcap(int value);
	void onParamChanged_Prefilcap();

	void valueChanged_SadWinSize(int value);
	void onParamChanged_SadWinSize();
	void onReleased_SadWinSize();//约束:奇数

	void valueChanged_TextThread(int value);
	void onParamChanged_TextThread();

	void valueChanged_MaxDifdisp2(int value);
	void onParamChanged_MaxDifdisp2();

	//1.int
	void valueChanged_DMin(int value);
	void onParamChanged_DMin();
	//2.int
	void valueChanged_DMax(int value);
	void onParamChanged_DMax();
	//3.int
	void valueChanged_CensusWinH(int value);
	void onParamChanged_CensusWinH();
	//4.int
	void valueChanged_CensusWinW(int value);
	void onParamChanged_CensusWinW();
	//5.float
	void valueChanged_DefaultBorderCost(double value);
	void onParamChanged_DefaultBorderCost();
	//6.float
	void valueChanged_LambdaAD(double value);
	void onParamChanged_LambdaAD();
	//7.float
	void valueChanged_LambdaCensus(double value);
	void onParamChanged_LambdaCensus();
	//8.int
	void valueChanged_AggregatingIterations(int value);
	void onParamChanged_AggregatingIterations();
	//9.int
	void valueChanged_ColorThreshold1(int value);
	void onParamChanged_ColorThreshold1();
	//10.int
	void valueChanged_ColorThreshold2(int value);
	void onParamChanged_ColorThreshold2();
	//11.int
	void valueChanged_MaxLength1(int value);
	void onParamChanged_MaxLength1();
	//12.int
	void valueChanged_MaxLength2(int value);
	void onParamChanged_MaxLength2();
	//13.int
	void valueChanged_ColorDifference(int value);
	void onParamChanged_ColorDifference();
	//14.float
	void valueChanged_Pi1(double value);
	void onParamChanged_Pi1();
	//15.float
	void valueChanged_Pi2(double value);
	void onParamChanged_Pi2();
	//16.int
	void valueChanged_DispTolerance(int value);
	void onParamChanged_DispTolerance();
	//17.int
	void valueChanged_VotingThreshold(int value);
	void onParamChanged_VotingThreshold();
	//18.float
	void valueChanged_VotingRatioThreshold(double value);
	void onParamChanged_VotingRatioThreshold();
	//19.int
	void valueChanged_MaxSearchDepth(int value);
	void onParamChanged_MaxSearchDepth();
	//20.int
	void valueChanged_CannyThreshold1(int value);
	void onParamChanged_CannyThreshold1();
	//21.int
	void valueChanged_CannyThreshold2(int value);
	void onParamChanged_CannyThreshold2();
	//22.int
	void valueChanged_CannyKernelSize(int value);
	void onParamChanged_CannyKernelSize();
	//23.int
	void valueChanged_BlurKernelSize(int value);
	void onParamChanged_BlurKernelSize();

	void valueChanged_DispMin(int value);
	void onParamChanged_DispMin();

	void valueChanged_DispMax(int value);
	void onParamChanged_DispMax();

	void valueChanged_SupportThreshold(double value);
	void onParamChanged_SupportThreshold();

	void valueChanged_SupportTexture(int value);
	void onParamChanged_SupportTexture();

	void valueChanged_CandidateStepsize(int value);
	void onParamChanged_CandidateStepsize();

	void valueChanged_InconWindowSize(int value);
	void onParamChanged_InconWindowSize();

	void valueChanged_InconThreshold(int value);
	void onParamChanged_InconThreshold();

	void valueChanged_InconMinSupport(int value);
	void onParamChanged_InconMinSupport();

	void valueChanged_AddCorners(bool value);
	void onParamChanged_AddCorners();

	void valueChanged_GridSize(int value);
	void onParamChanged_GridSize();

	void valueChanged_Beta(double value);
	void onParamChanged_Beta();

	void valueChanged_Gamma(double value);
	void onParamChanged_Gamma();

	void valueChanged_Sigma(double value);
	void onParamChanged_Sigma();

	void valueChanged_Sradius(double value);
	void onParamChanged_Sradius();

	void valueChanged_MatchTexture(int value);
	void onParamChanged_MatchTexture();

	void valueChanged_LrThreshold(int value);
	void onParamChanged_LrThreshold();

	void valueChanged_SpeckleSimThreshold(double value);
	void onParamChanged_SpeckleSimThreshold();

	void valueChanged_SpeckleSize(int value);
	void onParamChanged_SpeckleSize();

	void valueChanged_IpolGapWidth(int value);
	void onParamChanged_IpolGapWidth();

	void valueChanged_FilterMedian(bool value);
	void onParamChanged_FilterMedian();

	void valueChanged_FilterAdaptiveMean(bool value);
	void onParamChanged_FilterAdaptiveMean();

	void valueChanged_PostprocessOnlyLeft(bool value);
	void onParamChanged_PostprocessOnlyLeft();

	void valueChanged_SubSampling(bool value);
	void onParamChanged_SubSampling();
	//匹配算法
	void onClicked_BM(bool value);
	void onParamChanged_BM();

	void onClicked_SGBM(bool value);
	void onParamChanged_SGBM();

	void onClicked_ELAS(bool value);
	void onParamChanged_ELAS();

	void onClicked_ADCensus(bool value);
	void onParamChanged_ADCensus();

	void onClicked_RectifiedInput(bool value);
	void onParamChanged_RectifiedInput();
	//SGBM_MODE
	void onClicked_MODE_HH(bool value);
	void onParamChanged_MODE_HH();
	void onClicked_MODE_SGBM(bool value);
	void onParamChanged_MODE_SGBM();
	void onClicked_MODE_3WAY(bool value);
	void onParamChanged_MODE_3WAY();
	//图片显示
	void onParamChanged_imgDtoShow();
	void onParamChanged_IconImgL();
	void onParamChanged_IconImgR();
	void onParamChanged_IconRawDisp();
	void onParamChanged_ImageToShow();

	void onClicked_IconImgL(bool value);
	void onClicked_IconImgR(bool value);
	void onClicked_IconRawDisp(bool value);
};
