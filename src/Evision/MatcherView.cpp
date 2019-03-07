#include "MatcherView.h"
#include "EvisionUtils.h"
#include "math.h"
#include<qDebug>
#include <QMessageBox>

MatcherView::MatcherView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_entity = StereoMatchParamEntity::getInstance();
	m_controller = new StereoMatchController();
	connect(m_entity, SIGNAL(paramChanged_MinDisp()), this, SLOT(onParamChanged_MinDisp()));
	connect(m_entity, SIGNAL(paramChanged_Uniradio()), this, SLOT(onParamChanged_uniradio()));
	connect(m_entity, SIGNAL(paramChanged_Specwinsz()), this, SLOT(onParamChanged_specwinsz()));
	connect(m_entity, SIGNAL(paramChanged_NumDisparities()), this, SLOT(onParamChanged_NumDisparities()));
	connect(m_entity, SIGNAL(paramChanged_Specrange()), this, SLOT(onParamChanged_Specrange()));
	connect(m_entity, SIGNAL(paramChanged_Prefilcap()), this, SLOT(onParamChanged_Prefilcap()));
	connect(m_entity, SIGNAL(paramChanged_SadWinsz()), this, SLOT(onParamChanged_SadWinSize()));
	connect(m_entity, SIGNAL(paramChanged_TextThread()), this, SLOT(onParamChanged_TextThread()));
	connect(m_entity, SIGNAL(paramChanged_Maxdifdisp12()), this, SLOT(onParamChanged_MaxDifdisp2()));
	connect(m_entity, SIGNAL(paramChanged_BM()), this, SLOT(onParamChanged_BM()));
	connect(m_entity, SIGNAL(paramChanged_SGBM()), this, SLOT(onParamChanged_SGBM()));
	connect(m_entity, SIGNAL(paramChanged_ELAS()), this, SLOT(onParamChanged_ELAS()));
	connect(m_entity, SIGNAL(paramChanged_ADCensus()), this, SLOT(onParamChanged_ADCensus()));
	connect(m_entity, SIGNAL(paramChanged_RectifiedInput()), this, SLOT(onParamChanged_RectifiedInput()));
	connect(m_entity, SIGNAL(paramChanged_MODE_3WAY()), this, SLOT(onParamChanged_MODE_3WAY()));
	connect(m_entity, SIGNAL(paramChanged_MODE_SGBM()), this, SLOT(onParamChanged_MODE_SGBM()));
	connect(m_entity, SIGNAL(paramChanged_MODE_HH()), this, SLOT(onParamChanged_MODE_HH()));
	connect(m_entity, SIGNAL(paramChanged_ImageDtoShow()), this, SLOT(onParamChanged_imgDtoShow())/*, Qt::QueuedConnection*/);
	connect(m_entity, SIGNAL(paramChanged_IconImgL()), this, SLOT(onParamChanged_IconImgL()));
	connect(m_entity, SIGNAL(paramChanged_IconImgR()), this, SLOT(onParamChanged_IconImgR()));
	connect(m_entity, SIGNAL(paramChanged_IconRawDisp()), this, SLOT(onParamChanged_IconRawDisp()));
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


	m_entity->setImageToShow(StereoMatchParamEntity::RAW_DISP);
}

MatcherView::~MatcherView()
{
}
//默认匹配参数
void MatcherView::setDefaultMatchParam()
{
	m_controller->setDefaultMatchParamCommand();
}
//匹配
void MatcherView::doMatch()
{
	m_controller->MatchCommand();
}
//刷新匹配结果
void MatcherView::RefreshStereoMatch()
{
	m_controller->RefreshStereoMatchCommand();
}
//保存
void MatcherView::SaveDisparities()
{
	m_controller->SaveCommand();
}
//显示帮助信息
void MatcherView::Help()
{
	QString helpMsg = QStringLiteral("\
算法选择指南\n\n\
速度:OpenCV BM>OpenCV SGBM>ELAS>ADCensus\n\
效果:ADCensus>ELAS>SGBM>BM\n\
BM和SGBM的效果和速度类似\n\
BM会只能处理灰度图,其他的能处理彩色图,ADCensus在输入彩色图时能获得额外的效果\n\
界面上显示的视差图只是示意图,为了能显示在屏幕上,进行了一些处理(例如归一化到[0,255])\n\
真实的视差数据保存在xml中,测距和三维重建是以原始视差数据为基础的.\n");
	QMessageBox::information(this, QStringLiteral("帮助"), helpMsg);
}

void MatcherView::valueChanged_MinDisp(int value)
{
	ui.lineEdit_MinDisp->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMinDisp() != value)
	{
		m_entity->setMinDisp(value);
	}
}
void MatcherView::onParamChanged_MinDisp()
{
	ui.horizontalSlider_MinDisp->setValue(m_entity->getMinDisp());
}

void MatcherView::valueChanged_uniradio(int value)
{
	ui.lineEdit_uniradio->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getUniradio() != value)
	{
		m_entity->setUniradio(value);
	}
}

void MatcherView::onParamChanged_uniradio()
{
	ui.horizontalSlider_uniradio->setValue(m_entity->getUniradio());
}

void MatcherView::valueChanged_specwinsz(int value)
{
	ui.lineEdit_specwinsz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecwinsz() != value)
	{
		m_entity->setSpecwinsz(value);
	}
}

void MatcherView::onParamChanged_specwinsz()
{
	ui.horizontalSlider_specwinsz->setValue(m_entity->getSpecwinsz());

}

void MatcherView::valueChanged_NumDisparities(int value)
{
	ui.lineEdit_NumDisparities->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getNumDisparities() != value)
	{
		m_entity->setNumDisparities(value);
	}
}

void MatcherView::onParamChanged_NumDisparities()
{
	ui.horizontalSlider_NumDisparities->setValue(m_entity->getNumDisparities());

}

void MatcherView::onReleased_NumDisparities()
{
	int oldvalue=ui.horizontalSlider_NumDisparities->value();
	if(oldvalue%16!=0)
	{
		ui.horizontalSlider_NumDisparities->setValue(oldvalue - oldvalue % 16);
	}
}

void MatcherView::valueChanged_Specrange(int value)
{
	ui.lineEdit_specrange->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecrange() != value)
	{
		m_entity->setSpecrange(value);
	}
}

void MatcherView::onParamChanged_Specrange()
{
	ui.horizontalSlider_specrange->setValue(m_entity->getSpecrange());

}

void MatcherView::valueChanged_Prefilcap(int value)
{
	ui.lineEdit_prefilcap->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getPrefilcap() != value)
	{
		m_entity->setPrefilcap(value);
	}
}

void MatcherView::onParamChanged_Prefilcap()
{
	ui.horizontalSlider_prefilcap->setValue(m_entity->getPrefilcap());

}

void MatcherView::valueChanged_SadWinSize(int value)
{
	ui.lineEdit_SadWinSiz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSadWinsz() != value)
	{
		m_entity->setSadWinsz(value);
	}
}

void MatcherView::onParamChanged_SadWinSize()
{
	ui.horizontalSlider_SadWinSiz->setValue(m_entity->getSadWinsz());

}

void MatcherView::onReleased_SadWinSize()
{
	int oldvalue = ui.horizontalSlider_SadWinSiz->value();
	if(oldvalue%2==0)
	{
		ui.horizontalSlider_SadWinSiz->setValue(max(oldvalue-1,5));
	}
}

void MatcherView::valueChanged_TextThread(int value)
{
	ui.lineEdit_textThread->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getTextThread() != value)
	{
		m_entity->setTextThread(value);
	}
}

void MatcherView::onParamChanged_TextThread()
{
	ui.horizontalSlider_textThread->setValue(m_entity->getTextThread());

}

void MatcherView::valueChanged_MaxDifdisp2(int value)
{
	ui.lineEdit_maxdifdisp12->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMaxdifdisp12() != value)
	{
		m_entity->setMaxdifdisp12(value);
	}
}

void MatcherView::onParamChanged_MaxDifdisp2()
{
	ui.horizontalSlider_maxdifdisp12->setValue(m_entity->getMaxdifdisp12());

}


//1.int
void MatcherView::valueChanged_DMin(int value) {
	if (m_entity->getDMin() != value)
		m_entity->setDMin(value);
}
void MatcherView::onParamChanged_DMin() {
	ui.spinBox_dMin->setValue(m_entity->getDMin());
}
//2.int
void MatcherView::valueChanged_DMax(int value) {
	if (m_entity->getDMax() != value)
		m_entity->setDMax(value);
}
void MatcherView::onParamChanged_DMax() {
	ui.spinBox_dMax->setValue(m_entity->getDMax());
}
//3.int
void MatcherView::valueChanged_CensusWinH(int value) {
	if (m_entity->getCensusWinH() != value)
		m_entity->setCensusWinH(value);
}
void MatcherView::onParamChanged_CensusWinH() {
	ui.spinBox_censusWinW->setValue(m_entity->getCensusWinH());
}
//4.int
void MatcherView::valueChanged_CensusWinW(int value) {
	if (m_entity->getCensusWinW() != value)
		m_entity->setCensusWinW(value);
}
void MatcherView::onParamChanged_CensusWinW() {
	ui.spinBox_censusWinH->setValue(m_entity->getCensusWinW());
}
//5.float
void MatcherView::valueChanged_DefaultBorderCost(double value) {
	if (m_entity->getDefaultBorderCost() != value)
		m_entity->setDefaultBorderCost(value);
}
void MatcherView::onParamChanged_DefaultBorderCost() {
	ui.doubleSpinBox_defaultBorderCost->setValue(m_entity->getDefaultBorderCost());
}
//6.float
void MatcherView::valueChanged_LambdaAD(double value) {
	if (m_entity->getLambdaAD() != value)
		m_entity->setLambdaAD(value);
}
void MatcherView::onParamChanged_LambdaAD() {
	ui.doubleSpinBox_lambdaAD->setValue(m_entity->getLambdaAD());
}
//7.float
void MatcherView::valueChanged_LambdaCensus(double value) {
	if (m_entity->getLambdaCensus() != value)
		m_entity->setLambdaCensus(value);
}
void MatcherView::onParamChanged_LambdaCensus() {
	ui.doubleSpinBox_lambdaCensus->setValue(m_entity->getLambdaCensus());
}
//8.int
void MatcherView::valueChanged_AggregatingIterations(int value) {
	if (m_entity->getAggregatingIterations() != value)
		m_entity->setAggregatingIterations(value);
}
void MatcherView::onParamChanged_AggregatingIterations() {
	ui.spinBox_aggregatingIterations->setValue(m_entity->getAggregatingIterations());
}
//9.int
void MatcherView::valueChanged_ColorThreshold1(int value) {
	if (m_entity->getColorThreshold1() != value)
		m_entity->setColorThreshold1(value);
}
void MatcherView::onParamChanged_ColorThreshold1() {
	ui.spinBox_colorThreshold1->setValue(m_entity->getColorThreshold1());
}
//10.int
void MatcherView::valueChanged_ColorThreshold2(int value) {
	if (m_entity->getColorThreshold2() != value)
		m_entity->setColorThreshold2(value);
}
void MatcherView::onParamChanged_ColorThreshold2() {
	ui.spinBox_colorThreshold2->setValue(m_entity->getColorThreshold2());
}
//11.int
void MatcherView::valueChanged_MaxLength1(int value) {
	if (m_entity->getMaxLength1() != value)
		m_entity->setMaxLength1(value);
}
void MatcherView::onParamChanged_MaxLength1() {
	ui.spinBox_maxLength1->setValue(m_entity->getMaxLength1());
}
//12.int
void MatcherView::valueChanged_MaxLength2(int value) {
	if (m_entity->getMaxLength2() != value)
		m_entity->setMaxLength2(value);
}
void MatcherView::onParamChanged_MaxLength2() {
	ui.spinBox_maxLength2->setValue(m_entity->getMaxLength2());
}
//13.int
void MatcherView::valueChanged_ColorDifference(int value) {
	if (m_entity->getColorDifference() != value)
		m_entity->setColorDifference(value);
}
void MatcherView::onParamChanged_ColorDifference() {
	ui.spinBox_colorDifference->setValue(m_entity->getColorDifference());
}
//14.float
void MatcherView::valueChanged_Pi1(double value) {
	if (m_entity->getPi1() != value)
		m_entity->setPi1(value);
}
void MatcherView::onParamChanged_Pi1() {
	ui.doubleSpinBox_pi1->setValue(m_entity->getPi1());
}
//15.float
void MatcherView::valueChanged_Pi2(double value) {
	if (m_entity->getPi2() != value)
		m_entity->setPi2(value);
}
void MatcherView::onParamChanged_Pi2() {
	ui.doubleSpinBox_pi2->setValue(m_entity->getPi2());
}
//16.int
void MatcherView::valueChanged_DispTolerance(int value) {
	if (m_entity->getDispTolerance() != value)
		m_entity->setDispTolerance(value);
}
void MatcherView::onParamChanged_DispTolerance() {
	ui.spinBox_dispTolerance->setValue(m_entity->getDispTolerance());
}
//17.int
void MatcherView::valueChanged_VotingThreshold(int value) {
	if (m_entity->getVotingThreshold() != value)
		m_entity->setVotingThreshold(value);
}
void MatcherView::onParamChanged_VotingThreshold() {
	ui.spinBox_votingThreshold->setValue(m_entity->getVotingThreshold());
}
//18.float
void MatcherView::valueChanged_VotingRatioThreshold(double value) {
	if (m_entity->getVotingRatioThreshold() != value)
		m_entity->setVotingRatioThreshold(value);
}
void MatcherView::onParamChanged_VotingRatioThreshold() {
	ui.doubleSpinBox_votingRatioThreshold->setValue(m_entity->getVotingRatioThreshold());
}
//19.int
void MatcherView::valueChanged_MaxSearchDepth(int value) {
	if (m_entity->getMaxSearchDepth() != value)
		m_entity->setMaxSearchDepth(value);
}
void MatcherView::onParamChanged_MaxSearchDepth() {
	ui.spinBox_maxSearchDepth->setValue(m_entity->getMaxSearchDepth());
}
//20.int
void MatcherView::valueChanged_CannyThreshold1(int value) {
	if (m_entity->getCannyThreshold1() != value)
		m_entity->setCannyThreshold1(value);
}
void MatcherView::onParamChanged_CannyThreshold1() {
	ui.spinBox_cannyThreshold1->setValue(m_entity->getCannyThreshold1());
}
//21.int
void MatcherView::valueChanged_CannyThreshold2(int value) {
	if (m_entity->getCannyThreshold2() != value)
		m_entity->setCannyThreshold2(value);
}
void MatcherView::onParamChanged_CannyThreshold2() {
	ui.spinBox_cannyThreshold2->setValue(m_entity->getCannyThreshold2());
}
//22.int
void MatcherView::valueChanged_CannyKernelSize(int value) {
	if (m_entity->getCannyKernelSize() != value)
		m_entity->setCannyKernelSize(value);
}
void MatcherView::onParamChanged_CannyKernelSize() {
	ui.spinBox_cannyKernelSize->setValue(m_entity->getCannyKernelSize());
}
//23.int
void MatcherView::valueChanged_BlurKernelSize(int value) {
	if (m_entity->getBlurKernelSize() != value)
		m_entity->setBlurKernelSize(value);
}
void MatcherView::onParamChanged_BlurKernelSize() {
	ui.spinBox_blurKernelSize->setValue(m_entity->getBlurKernelSize());
}

void MatcherView::onClicked_BM(bool value)
{
	if (m_entity->getBM() != value)
	{
		m_entity->setBM(value);
	}
	ui.stackedWidget->setCurrentIndex(0);
	ui.horizontalSlider_textThread->setEnabled(true);
	ui.radioButton_MODE_HH->setEnabled(false);
	ui.radioButton_MODE_SGBM->setEnabled(false);
	ui.radioButton_MODE_3WAY->setEnabled(false);
}

void MatcherView::onParamChanged_BM()
{
	ui.radioButton_BM->setChecked(m_entity->getBM());

}

void MatcherView::onClicked_SGBM(bool value)
{
	if (m_entity->getSGBM() != value)
	{
		m_entity->setSGBM(value);
	}
	ui.stackedWidget->setCurrentIndex(0);
	ui.horizontalSlider_textThread->setEnabled(false);
	ui.radioButton_MODE_HH->setEnabled(true);
	ui.radioButton_MODE_SGBM->setEnabled(true);
	ui.radioButton_MODE_3WAY->setEnabled(true);
}

void MatcherView::onParamChanged_SGBM()
{
	ui.radioButton_SGBM->setChecked(m_entity->getSGBM());

}

void MatcherView::onClicked_ELAS(bool value)
{
	if (m_entity->getElas() != value)
	{
		m_entity->setElas(value);
	}
	ui.stackedWidget->setCurrentIndex(1);
}

void MatcherView::onParamChanged_ELAS()
{
	ui.radioButton_ELAS->setChecked(m_entity->getElas());
}

void MatcherView::onClicked_ADCensus(bool value)
{
	if(m_entity->getADCensus()!=value)
	{
		m_entity->setADCensus(value);
	}
	ui.stackedWidget->setCurrentIndex(2);
}

void MatcherView::onParamChanged_ADCensus()
{
	ui.radioButton_ADC->setChecked(m_entity->getADCensus());
}

void MatcherView::onClicked_RectifiedInput(bool value)
{
	if(m_entity->getRectifiedInput()!=value)
	{
		m_entity->setRectifiedInput(value);
	}
}

void MatcherView::onParamChanged_RectifiedInput()
{
	ui.checkBox_RectifiedInput->setChecked(m_entity->getRectifiedInput());
}

void MatcherView::onClicked_MODE_HH(bool value)
{
	if (m_entity->getMODE_HH() != value)
	{
		m_entity->setMODE_HH(value);
	}
}

void MatcherView::onParamChanged_MODE_HH()
{
	ui.radioButton_MODE_HH->setChecked(m_entity->getMODE_HH());

}

void MatcherView::onClicked_MODE_SGBM(bool value)
{
	if (m_entity->getMODE_SGBM() != value)
	{
		m_entity->setMODE_SGBM(value);
	}
}

void MatcherView::onParamChanged_MODE_SGBM()
{
	ui.radioButton_MODE_SGBM->setChecked(m_entity->getMODE_SGBM());

}

void MatcherView::onClicked_MODE_3WAY(bool value)
{
	if (m_entity->getMODE_3WAY() != value)
	{
		m_entity->setMODE_3WAY(value);
	}
}

void MatcherView::onParamChanged_MODE_3WAY()
{
	ui.radioButton_MODE_3WAY->setChecked(m_entity->getMODE_3WAY());

}

void MatcherView::onParamChanged_imgDtoShow()
{
	QImage DQImage = EvisionUtils::cvMat2QImage(m_entity->getImageDtoShow());
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

void MatcherView::onParamChanged_IconImgL()
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

void MatcherView::onParamChanged_IconImgR()
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

void MatcherView::onParamChanged_IconRawDisp()
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


//要在中间放大显示的图片发生变更
void MatcherView::onParamChanged_ImageToShow()
{
	//根据枚举值调整单选框的状态
	ui.radioButton_ImageL->setChecked(false);
	ui.radioButton_ImageR->setChecked(false);
	ui.radioButton_RawDisp->setChecked(false);
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
	default:
		break;
	}
}

void MatcherView::onClicked_IconImgL(bool value)
{
	if(m_entity->getImageToShow()!=StereoMatchParamEntity::IMG_L)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::IMG_L);
	}
}

void MatcherView::onClicked_IconImgR(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::IMG_R)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::IMG_R);
	}
}

void MatcherView::onClicked_IconRawDisp(bool value)
{
	if (m_entity->getImageToShow() != StereoMatchParamEntity::RAW_DISP)
	{
		m_entity->setImageToShow(StereoMatchParamEntity::RAW_DISP);
	}
}
