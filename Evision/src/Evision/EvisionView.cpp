#include "EvisionView.h"
#include "QDebug"
#include "QMessageBox"
#include "EvisionUtils.h"
// 浮点数判等
// ulp: units in the last place.
template <typename T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
IsAlmostEqual(T x, T y, int ulp = 2)
{
	// the machine epsilon has to be scaled to the magnitude of the values used
	// and multiplied by the desired precision in ULPs (units in the last place)
	return std::abs(x - y) < std::numeric_limits<T>::epsilon() * std::abs(x + y) * ulp
		// unless the result is subnormal
		|| std::abs(x - y) < std::numeric_limits<T>::min();
}

//构造函数
EvisionView::EvisionView(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	msgLabel = new QLabel;
	msgLabel->setMinimumSize(msgLabel->sizeHint());
	msgLabel->setAlignment(Qt::AlignHCenter);
	msgLabel->setText(QStringLiteral("就绪"));
	statusBar()->addWidget(msgLabel);
	statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));

	m_entity = EvisionParamEntity::getInstance();
	m_controller = new EvisionController();
	connect(m_entity, SIGNAL(paramChanged_BoardWidth()), this, SLOT(onParamChanged_BoardWidth()));
	connect(m_entity, SIGNAL(paramChanged_BoardHeight()), this, SLOT(onParamChanged_BoardHeight()));
	connect(m_entity, SIGNAL(paramChanged_SquareSize()), this, SLOT(onParamChanged_SquareSize()));
	connect(m_entity, SIGNAL(paramChanged_Alpha()), this, SLOT(onParamChanged_Alpha()));
	connect(m_entity, SIGNAL(paramChanged_nBoards()), this, SLOT(onParamChanged_nBoards()));
	connect(m_entity, SIGNAL(paramChanged_FI()), this, SLOT(onParamChanged_FI()));
	connect(m_entity, SIGNAL(paramChanged_UIG()), this, SLOT(onParamChanged_UIG()));
	connect(m_entity, SIGNAL(paramChanged_SFL()), this, SLOT(onParamChanged_SFL()));
	connect(m_entity, SIGNAL(paramChanged_FPP()), this, SLOT(onParamChanged_FPP()));
	connect(m_entity, SIGNAL(paramChanged_FAR()), this, SLOT(onParamChanged_FAR()));
	connect(m_entity, SIGNAL(paramChanged_Bouguet()), this, SLOT(onParamChanged_Bouguet()));
	connect(m_entity, SIGNAL(paramChanged_Hartley()), this, SLOT(onParamChanged_Hartley()));
	connect(m_entity, SIGNAL(paramChanged_MinDisp()), this, SLOT(onParamChanged_MinDisp()));
	connect(m_entity, SIGNAL(paramChanged_Uniradio()), this, SLOT(onParamChanged_uniradio()));
	connect(m_entity, SIGNAL(paramChanged_Specwinsz()), this, SLOT(onParamChanged_specwinsz()));
	connect(m_entity, SIGNAL(paramChanged_MaxDisp()), this, SLOT(onParamChanged_MaxDisp()));
	connect(m_entity, SIGNAL(paramChanged_Specrange()), this, SLOT(onParamChanged_Specrange()));
	connect(m_entity, SIGNAL(paramChanged_Prefilcap()), this, SLOT(onParamChanged_Prefilcap()));
	connect(m_entity, SIGNAL(paramChanged_SadWinsz()), this, SLOT(onParamChanged_SadWinSize()));
	connect(m_entity, SIGNAL(paramChanged_TextThread()), this, SLOT(onParamChanged_TextThread()));
	connect(m_entity, SIGNAL(paramChanged_Maxdifdisp12()), this, SLOT(onParamChanged_MaxDifdisp2()));
	connect(m_entity, SIGNAL(paramChanged_Levels()), this, SLOT(onParamChanged_Levels()));
	connect(m_entity, SIGNAL(paramChanged_pyrScale()), this, SLOT(onParamChanged_PyrScale()));
	connect(m_entity, SIGNAL(paramChanged_PolyN()), this, SLOT(onParamChanged_PolyN()));
	connect(m_entity, SIGNAL(paramChanged_PolySigma()), this, SLOT(onParamChanged_PolySigma()));
	connect(m_entity, SIGNAL(paramChanged_Fi()), this, SLOT(onParamChanged_Fi()));
	connect(m_entity, SIGNAL(paramChanged_Lambda()), this, SLOT(onParamChanged_Lambda()));
	connect(m_entity, SIGNAL(paramChanged_BM()), this, SLOT(onParamChanged_BM()));
	connect(m_entity, SIGNAL(paramChanged_SGBM()), this, SLOT(onParamChanged_SGBM()));
	connect(m_entity, SIGNAL(paramChanged_VAR()), this, SLOT(onParamChanged_VAR()));
	connect(m_entity, SIGNAL(paramChanged_distance()), this, SLOT(onParamChanged_Distance()));

	connect(m_entity, SIGNAL(paramChanged_ImageLtoShow()), this, SLOT(onParamChanged_imgLtoShow()));
	connect(m_entity, SIGNAL(paramChanged_ImageRtoShow()), this, SLOT(onParamChanged_imgRtoShow()));
	connect(m_entity, SIGNAL(paramChanged_StatusBar()), this, SLOT(onParamChanged_StatusBarText()));

}
/*==========按钮============*/
//默认标定参数
void EvisionView::setDefaultCalibParam()
{
	m_controller->setDefaultCalibParamCommand();
}
//标定
void EvisionView::doCalib()
{
}
//默认匹配参数
void EvisionView::setDefaultMatchParam()
{
	m_controller->setDefaultMatchParamCommand();
}
//匹配
void EvisionView::doMatch()
{
}

void EvisionView::getDistance()
{
}

void EvisionView::getGap()
{
}
/*=============标定参数===============*/
void EvisionView::onValueChanged_BoardWidth(QString value)
{
	m_entity->setBoardWidth(value.toInt());
}
//参数被直接修改,更新ui使之与同步
void EvisionView::onParamChanged_BoardWidth() const
{
	QString tmp = QString::fromStdString(std::to_string(m_entity->getBoardWidth()));
	if (tmp != ui.lineEdit_BoardWidth->text())
	{
		ui.lineEdit_BoardWidth->setText(tmp);
	}
}

void EvisionView::onValueChanged_BoardHeight(QString value)
{
	m_entity->setBoardHeight(value.toInt());
}

void EvisionView::onParamChanged_BoardHeight()
{
	QString tmp = QString::fromStdString(std::to_string(m_entity->getBoardHeight()));
	if (tmp != ui.lineEdit_BoardHeight->text())
	{
		ui.lineEdit_BoardHeight->setText(tmp);
	}
}

void EvisionView::onValueChanged_SquareSize(QString value)
{
	m_entity->setSquareSize(value.toInt());
}

void EvisionView::onParamChanged_SquareSize()
{
	QString tmp = QString::fromStdString(std::to_string(m_entity->getSquareSize()));
	if (tmp != ui.lineEdit_SquareSize->text())
	{
		ui.lineEdit_SquareSize->setText(tmp);
	}
}

void EvisionView::onValueChanged_Alpha(QString value)
{
	m_entity->setAlpha(value.toInt());
}

void EvisionView::onParamChanged_Alpha()
{
	QString tmp = QString::fromStdString(std::to_string(m_entity->getAlpha()));
	if (tmp != ui.lineEdit_Alpha->text())
	{
		ui.lineEdit_Alpha->setText(tmp);
	}
}

void EvisionView::onValueChanged_nBoards(QString value)
{
	m_entity->setnBoards(value.toInt());
}

void EvisionView::onParamChanged_nBoards()
{
	QString tmp = QString::fromStdString(std::to_string(m_entity->getnBoards()));
	if (tmp != ui.lineEdit__nBoards->text())
	{
		ui.lineEdit__nBoards->setText(tmp);
	}
}

void EvisionView::onClicked_FI(bool value)
{
	m_entity->setFI(value);
}

void EvisionView::onParamChanged_FI()
{
	ui.checkBox_FI->setChecked(m_entity->getFI());
}

void EvisionView::onClicked_UIG(bool value)
{
	m_entity->setUIG(value);
}

void EvisionView::onParamChanged_UIG()
{
	ui.checkBox_UIG->setChecked(m_entity->getUIG());
}

void EvisionView::onClicked_SFL(bool value)
{
	m_entity->setSFL(value);
}

void EvisionView::onParamChanged_SFL()
{
	ui.checkBox_SFL->setChecked(m_entity->getSFL());
}

void EvisionView::onClicked_FPP(bool value)
{
	m_entity->setFPP(value);
}

void EvisionView::onParamChanged_FPP()
{
	ui.checkBox_FPP->setChecked(m_entity->getFPP());
}

void EvisionView::onClicked_FAR(bool value)
{
	m_entity->setFAR(value);
}

void EvisionView::onParamChanged_FAR()
{
	ui.checkBox_FAR->setChecked(m_entity->getFAR());
}

void EvisionView::onClicked_Bouguet(bool value)
{
	m_entity->setBouguet(value);
}

void EvisionView::onParamChanged_Bouguet()
{
	ui.radioButton_Bouguet->setChecked(m_entity->getBouguet());
}

void EvisionView::onClicked_Hartley(bool value)
{
	m_entity->setHartley(value);
}

void EvisionView::onParamChanged_Hartley()
{
	ui.radioButton_Hartley->setChecked(m_entity->getHartley());
}

void EvisionView::valueChanged_MinDisp(int value)
{
	ui.lineEdit_MinDisp->setText(QString::fromStdString(std::to_string(value)));
	if(m_entity->getMinDisp()!= value)
	{
		m_entity->setMinDisp(value);
	}
}

void EvisionView::onParamChanged_MinDisp()
{
	ui.horizontalSlider_MinDisp->setValue(m_entity->getMinDisp());
}

void EvisionView::valueChanged_uniradio(int value)
{
	ui.lineEdit_uniradio->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getUniradio()!=value)
	{
		m_entity->setUniradio(value);
	}
}

void EvisionView::onParamChanged_uniradio()
{
	ui.horizontalSlider_uniradio->setValue(m_entity->getUniradio());
}

void EvisionView::valueChanged_specwinsz(int value)
{
	ui.lineEdit_specwinsz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecwinsz()!=value)
	{
		m_entity->setSpecwinsz(value);
	}
}

void EvisionView::onParamChanged_specwinsz()
{
	ui.horizontalSlider_specwinsz->setValue(m_entity->getSpecwinsz());
}

void EvisionView::valueChanged_MaxDisp(int value)
{
	ui.lineEdit_MaxDisp->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMaxDisp()!=value)
	{
		m_entity->setMaxDisp(value);
	}
}

void EvisionView::onParamChanged_MaxDisp()
{
	ui.horizontalSlider_MaxDisp->setValue(m_entity->getMaxDisp());
}

void EvisionView::valueChanged_Specrange(int value)
{
	ui.lineEdit_specrange->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSpecrange()!=value)
	{
		m_entity->setSpecrange(value);
	}
}

void EvisionView::onParamChanged_Specrange()
{
	ui.horizontalSlider_specrange->setValue(m_entity->getSpecrange());
}

void EvisionView::valueChanged_Prefilcap(int value)
{
	ui.lineEdit_prefilcap->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getPrefilcap()!=value)
	{
		m_entity->setPrefilcap(value);
	}
}

void EvisionView::onParamChanged_Prefilcap()
{
	ui.horizontalSlider_prefilcap->setValue(m_entity->getPrefilcap());
}

void EvisionView::valueChanged_SadWinSize(int value)
{
	ui.lineEdit_SadWinSiz->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getSadWinsz()!=value)
	{
		m_entity->setSadWinsz(value);
	}
}

void EvisionView::onParamChanged_SadWinSize()
{
	ui.horizontalSlider_SadWinSiz->setValue(m_entity->getSadWinsz());
}

void EvisionView::valueChanged_TextThread(int value)
{
	ui.lineEdit_textThread->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getTextThread()!=value)
	{
		m_entity->setTextThread(value);
	}
}

void EvisionView::onParamChanged_TextThread()
{
	ui.horizontalSlider_textThread->setValue(m_entity->getTextThread());
}

void EvisionView::valueChanged_MaxDifdisp2(int value)
{
	ui.lineEdit_maxdifdisp12->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getMaxdifdisp12()!=value)
	{
		m_entity->setMaxdifdisp12(value);
	}
}

void EvisionView::onParamChanged_MaxDifdisp2()
{
	ui.horizontalSlider_maxdifdisp12->setValue(m_entity->getMaxdifdisp12());
}

void EvisionView::valueChanged_Levels(int value)
{
	ui.lineEdit_Levels->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getLevels()!=value)
	{
		m_entity->setLevels(value);
	}
}

void EvisionView::onParamChanged_Levels()
{
	ui.horizontalSlider_Levels->setValue(m_entity->getLevels());
}

void EvisionView::valueChanged_PyrScale(int value)
{
	char s[100];
	sprintf(s, "%.1f", value / 10.00f);
	ui.lineEdit_pyrScale->setText(QString::fromStdString(s));
	if (!IsAlmostEqual(m_entity->getPyrScale(),value / 10.00f))
	{
		m_entity->setPyrScale(value / 10.00f);
	}
}

void EvisionView::onParamChanged_PyrScale()
{
	ui.horizontalSlider_pyrScale->setValue(int(m_entity->getPyrScale()*10.00f));
}

void EvisionView::valueChanged_PolyN(int value)
{
	ui.lineEdit_PolyN->setText(QString::fromStdString(std::to_string(value)));
	if (m_entity->getPolyN()!=value)
	{
		m_entity->setPolyN(value);
	}
}

void EvisionView::onParamChanged_PolyN()
{
	ui.horizontalSlider_PolyN->setValue(m_entity->getPolyN());
}

void EvisionView::valueChanged_PolySigma(int value)
{
	char s[100];
	sprintf(s, "%.1f", value / 10.00f);
	ui.lineEdit_PolySigma->setText(QString::fromStdString(s));

	if (!IsAlmostEqual(m_entity->getPolySigma(),value /10.00f))
	{
		m_entity->setPolySigma(value / 10.00f);
	}
}

void EvisionView::onParamChanged_PolySigma()
{
	ui.horizontalSlider_PolySigma->setValue(int(m_entity->getPolySigma()*10));
}

void EvisionView::valueChanged_Fi(int value)
{
	char s[100];
	sprintf(s, "%.1f", value / 10.00f);
	ui.lineEdit_Fi->setText(QString::fromStdString(s));
	if (!IsAlmostEqual(m_entity->getFi(),value / 10.00f))
	{
		m_entity->setFi(value / 10.00f);
	}
}

void EvisionView::onParamChanged_Fi()
{
	ui.horizontalSlider_Fi->setValue(int(m_entity->getFi()*10.0f));
}

void EvisionView::valueChanged_Lambda(int value)
{
	char s[100];
	sprintf(s, "%.2f", value / 100.00f);
	ui.lineEdit_Lambda->setText(QString::fromStdString(s));
	if (!IsAlmostEqual(m_entity->getLambda(),value / 100.00f))
	{
		m_entity->setLambda(value / 100.00f);
	}
}

void EvisionView::onParamChanged_Lambda()
{
	ui.horizontalSlider_Lambda->setValue(int(m_entity->getLambda()*100.0f));
}

void EvisionView::onClicked_BM(bool value)
{
	if (m_entity->getBM()!=value)
	{
		m_entity->setBM(value);
	}
	ui.horizontalSlider_MinDisp->setEnabled(true);
	ui.horizontalSlider_uniradio->setEnabled(true);
	ui.horizontalSlider_specwinsz->setEnabled(true);
	ui.horizontalSlider_MaxDisp->setEnabled(true);
	ui.horizontalSlider_specrange->setEnabled(true);
	ui.horizontalSlider_prefilcap->setEnabled(true);
	ui.horizontalSlider_SadWinSiz->setEnabled(true);
	ui.horizontalSlider_textThread->setEnabled(true);
	ui.horizontalSlider_maxdifdisp12->setEnabled(true);
	ui.horizontalSlider_Levels->setEnabled(false);
	ui.horizontalSlider_pyrScale->setEnabled(false);
	ui.horizontalSlider_PolyN->setEnabled(false);
	ui.horizontalSlider_PolySigma->setEnabled(false);
	ui.horizontalSlider_Fi->setEnabled(false);
	ui.horizontalSlider_Lambda->setEnabled(false);
}

void EvisionView::onParamChanged_BM()
{
	ui.radioButton_BM->setChecked(m_entity->getBM());
}

void EvisionView::onClicked_SGBM(bool value)
{
	if (m_entity->getSGBM()!=value)
	{
		m_entity->setSGBM(value);
	}
	ui.horizontalSlider_MinDisp->setEnabled(true);
	ui.horizontalSlider_uniradio->setEnabled(true);
	ui.horizontalSlider_specwinsz->setEnabled(true);
	ui.horizontalSlider_MaxDisp->setEnabled(true);
	ui.horizontalSlider_specrange->setEnabled(true);
	ui.horizontalSlider_prefilcap->setEnabled(true);
	ui.horizontalSlider_SadWinSiz->setEnabled(true);
	ui.horizontalSlider_textThread->setEnabled(false);
	ui.horizontalSlider_maxdifdisp12->setEnabled(true);
	ui.horizontalSlider_Levels->setEnabled(false);
	ui.horizontalSlider_pyrScale->setEnabled(false);
	ui.horizontalSlider_PolyN->setEnabled(false);
	ui.horizontalSlider_PolySigma->setEnabled(false);
	ui.horizontalSlider_Fi->setEnabled(false);
	ui.horizontalSlider_Lambda->setEnabled(false);
}

void EvisionView::onParamChanged_SGBM()
{
	ui.radioButton_SGBM->setChecked(m_entity->getSGBM());
}

void EvisionView::onClicked_VAR(bool value)
{
	if (m_entity->getVAR()!=value)
	{
		m_entity->setVAR(value);
	}
	ui.horizontalSlider_MinDisp->setEnabled(true);
	ui.horizontalSlider_uniradio->setEnabled(false);
	ui.horizontalSlider_specwinsz->setEnabled(false);
	ui.horizontalSlider_MaxDisp->setEnabled(true);
	ui.horizontalSlider_specrange->setEnabled(false);
	ui.horizontalSlider_prefilcap->setEnabled(false);
	ui.horizontalSlider_SadWinSiz->setEnabled(false);
	ui.horizontalSlider_textThread->setEnabled(false);
	ui.horizontalSlider_maxdifdisp12->setEnabled(false);
	ui.horizontalSlider_Levels->setEnabled(true);
	ui.horizontalSlider_pyrScale->setEnabled(true);
	ui.horizontalSlider_PolyN->setEnabled(true);
	ui.horizontalSlider_PolySigma->setEnabled(true);
	ui.horizontalSlider_Fi->setEnabled(true);
	ui.horizontalSlider_Lambda->setEnabled(true);
}

void EvisionView::onParamChanged_VAR()
{
	ui.radioButton_VAR->setChecked(m_entity->getVAR());
}

void EvisionView::onParamChanged_Distance()
{
	ui.lineEdit_Result->setText(QString::fromStdString(std::to_string(m_entity->getDistance())));
}
void EvisionView::onParamChanged_imgLtoShow()
{
	QImage LQImage = EvisionUtils::cvMat2QImage(m_entity->getImageLtoShow());
	QGraphicsScene *sceneL = new QGraphicsScene;
	sceneL->addPixmap(QPixmap::fromImage(LQImage));
	ui.graphicsView_L->setScene(sceneL);
	//ui.Viewer_CalibrateL->resize(LQImage.width() + 10, LQImage.height() + 10);
	ui.graphicsView_L->show();
	ui.graphicsView_L->update();
}

void EvisionView::onParamChanged_imgRtoShow()
{
	QImage RQImage = EvisionUtils::cvMat2QImage(m_entity->getImageRtoShow());
	QGraphicsScene *sceneR = new QGraphicsScene;
	sceneR->addPixmap(QPixmap::fromImage(RQImage));
	ui.graphicsView_R->setScene(sceneR);
	//ui.Viewer_CalibrateR->resize(RQImage.width() + 10, RQImage.height() + 10);
	ui.graphicsView_R->show();
	ui.graphicsView_R->update();
}

//调试方法
void EvisionView::onTestAlltheParam()
{
	//输出所有的参数
	qDebug() << "BoardWidth:  " << m_entity->getBoardWidth() << "\n"
		<< "BoardHeight:  " << m_entity->getBoardHeight() << "\n"
		<< "SquareSize:  " << m_entity->getSquareSize() << "\n"
		<< "Alpha:  " << m_entity->getAlpha() << "\n"
		<< "nBoards:  " << m_entity->getnBoards() << "\n"
		<< "FI:  " << m_entity->getFI() << "\n"
		<< "UIG:  " << m_entity->getUIG() << "\n"
		<< "SFL:  " << m_entity->getSFL() << "\n"
		<< "FPP:  " << m_entity->getFPP() << "\n"
		<< "FAR:  " << m_entity->getFAR() << "\n"
		<< "Bouguet:  " << m_entity->getBouguet() << "\n"
		<< "Hartley:  " << m_entity->getHartley() << "\n"
		<< "MinDisp:  " << m_entity->getMinDisp() << "\n"
		<< "Uniradio:  " << m_entity->getUniradio() << "\n"
		<< "Specwinsz:  " << m_entity->getSpecwinsz() << "\n"
		<< "MaxDisp:  " << m_entity->getMaxDisp() << "\n"
		<< "Specrange:  " << m_entity->getSpecrange() << "\n"
		<< "Prefilcap:  " << m_entity->getPrefilcap() << "\n"
		<< "SadWinsz:  " << m_entity->getSadWinsz() << "\n"
		<< "TextThread:  " << m_entity->getTextThread() << "\n"
		<< "Maxdifdisp12:  " << m_entity->getMaxdifdisp12() << "\n"
		<< "Levels:  " << m_entity->getLevels() << "\n"
		<< "PyrScale:  " << m_entity->getPyrScale() << "\n"
		<< "PolyN:  " << m_entity->getPolyN() << "\n"
		<< "PolySigma:  " << m_entity->getPolySigma() << "\n"
		<< "Fi:  " << m_entity->getFi() << "\n"
		<< "Lambda:  " << m_entity->getLambda() << "\n"
		<< "BM:  " << m_entity->getBM() << "\n"
		<< "SGBM:  " << m_entity->getSGBM() << "\n"
		<< "VAR:  " << m_entity->getVAR() << "\n"
		<< "Distance:  " << m_entity->getDistance();
}
//状态栏更新
void EvisionView::onParamChanged_StatusBarText()
{
	msgLabel->setText(m_entity->getStatusBarText());
}
