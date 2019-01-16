#include "EvisionView.h"
#include "QDebug"
#include "QMessageBox"
#include "EvisionUtils.h"
#include "Calibrater.h"
#include "Matcher.h"
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

	//connect(m_entity, SIGNAL(paramChanged_MinDisp()), this, SLOT(onParamChanged_MinDisp()));
	//connect(m_entity, SIGNAL(paramChanged_Uniradio()), this, SLOT(onParamChanged_uniradio()));
	//connect(m_entity, SIGNAL(paramChanged_Specwinsz()), this, SLOT(onParamChanged_specwinsz()));
	//connect(m_entity, SIGNAL(paramChanged_NumDisparities()), this, SLOT(onParamChanged_NumDisparities()));
	//connect(m_entity, SIGNAL(paramChanged_Specrange()), this, SLOT(onParamChanged_Specrange()));
	//connect(m_entity, SIGNAL(paramChanged_Prefilcap()), this, SLOT(onParamChanged_Prefilcap()));
	//connect(m_entity, SIGNAL(paramChanged_SadWinsz()), this, SLOT(onParamChanged_SadWinSize()));
	//connect(m_entity, SIGNAL(paramChanged_TextThread()), this, SLOT(onParamChanged_TextThread()));
	//connect(m_entity, SIGNAL(paramChanged_Maxdifdisp12()), this, SLOT(onParamChanged_MaxDifdisp2()));
	//connect(m_entity, SIGNAL(paramChanged_BM()), this, SLOT(onParamChanged_BM()));
	//connect(m_entity, SIGNAL(paramChanged_SGBM()), this, SLOT(onParamChanged_SGBM()));
	//connect(m_entity, SIGNAL(paramChanged_MODE_HH()), this, SLOT(onParamChanged_MODE_HH()));

	connect(m_entity, SIGNAL(paramChanged_ImageLtoShow()), this, SLOT(onParamChanged_imgLtoShow())/*, Qt::QueuedConnection*/);
	connect(m_entity, SIGNAL(paramChanged_ImageRtoShow()), this, SLOT(onParamChanged_imgRtoShow())/*, Qt::QueuedConnection*/);
	connect(m_entity, SIGNAL(paramChanged_ImageDtoShow()), this, SLOT(onParamChanged_imgDtoShow())/*, Qt::QueuedConnection*/);
	connect(m_entity, SIGNAL(paramChanged_StatusBar()), this, SLOT(onParamChanged_StatusBarText()), Qt::QueuedConnection);

}

//测距
void EvisionView::getDistance()
{
	m_controller->getDistanceCommand();
}

void EvisionView::onCamera()
{
	m_controller->openCameraCommand();
}

void EvisionView::onStereoCamera()
{
	m_controller->openStereoCameraCommand();
}

//显示点云
void EvisionView::onShowPointCloud()
{
	m_controller->ShowPointCloudCommand();
}
//显示标定视图
void EvisionView::on_action_calibrate_view()
{
	Calibrater * m_calibrate = new Calibrater();
	m_calibrate->show();
}
//显示立体匹配视图
void EvisionView::on_action_stereoMatch_view()
{
	Matcher * m_matcher = new Matcher();
	m_matcher->show();
}

void EvisionView::on_action_Measure_view()
{
	m_controller->getDistanceCommand();
}

//调试方法
void EvisionView::onTestAlltheParam()
{
	////输出所有的参数
	//qDebug() << "BoardWidth:  " << m_entity->getBoardWidth() << "\n"
	//	<< "BoardHeight:  " << m_entity->getBoardHeight() << "\n"
	//	<< "SquareSize:  " << m_entity->getSquareSize() << "\n"
	//	<< "FPP:  " << m_entity->getshowRectified() << "\n"
	//	<< "Bouguet:  " << m_entity->getBouguet() << "\n"
	//	<< "Hartley:  " << m_entity->getHartley() << "\n"
	//	<< "MinDisp:  " << m_entity->getMinDisp() << "\n"
	//	<< "Uniradio:  " << m_entity->getUniradio() << "\n"
	//	<< "Specwinsz:  " << m_entity->getSpecwinsz() << "\n"
	//	<< "MaxDisp:  " << m_entity->getNumDisparities() << "\n"
	//	<< "Specrange:  " << m_entity->getSpecrange() << "\n"
	//	<< "Prefilcap:  " << m_entity->getPrefilcap() << "\n"
	//	<< "SadWinsz:  " << m_entity->getSadWinsz() << "\n"
	//	<< "TextThread:  " << m_entity->getTextThread() << "\n"
	//	<< "Maxdifdisp12:  " << m_entity->getMaxdifdisp12() << "\n"
	//	<< "BM:  " << m_entity->getBM() << "\n"
	//	<< "SGBM:  " << m_entity->getSGBM() << "\n"
	//	<< "Mode-HH:  " << m_entity->getMODE_HH() << "\n"
	//	<< "Mode-SGBM:  " << m_entity->getMODE_SGBM() << "\n"
	//	<< "Mode-3WAY:  " << m_entity->getMODE_3WAY() << "\n"

	//	<< "Distance:  " << m_entity->getDistance();
}
//状态栏更新
void EvisionView::onParamChanged_StatusBarText()
{
	msgLabel->setText(m_entity->getStatusBarText());
}

