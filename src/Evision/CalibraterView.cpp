#include "CalibraterView.h"
#include "EvisionUtils.h"

CalibraterView::CalibraterView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_calib_entity = CalibrateParamEntity::getInstance();
	m_calib_controller = new CalibrateController();

	connect(m_calib_entity, SIGNAL(paramChanged_BoardWidth()), this, SLOT(onParamChanged_BoardWidth()));
	connect(m_calib_entity, SIGNAL(paramChanged_BoardHeight()), this, SLOT(onParamChanged_BoardHeight()));
	connect(m_calib_entity, SIGNAL(paramChanged_SquareSize()), this, SLOT(onParamChanged_SquareSize()));
	connect(m_calib_entity, SIGNAL(paramChanged_showRectified()), this, SLOT(onParamChanged_showRectified()));
	connect(m_calib_entity, SIGNAL(paramChanged_Bouguet()), this, SLOT(onParamChanged_Bouguet()));
	connect(m_calib_entity, SIGNAL(paramChanged_Hartley()), this, SLOT(onParamChanged_Hartley()));
	connect(m_calib_entity, SIGNAL(paramChanged_ImageLtoShow()), this, SLOT(onParamChanged_imgLtoShow())/*, Qt::QueuedConnection*/);
	connect(m_calib_entity, SIGNAL(paramChanged_ImageRtoShow()), this, SLOT(onParamChanged_imgRtoShow())/*, Qt::QueuedConnection*/);

}

CalibraterView::~CalibraterView()
{
}
//默认标定参数
void CalibraterView::setDefaultCalibParam()
{
	m_calib_controller->setDefaultCalibParamCommand();
}
//标定
void CalibraterView::doCalib()
{
	m_calib_controller->CalibrateCommand();
}

void CalibraterView::onValueChanged_BoardWidth(QString value)
{
	m_calib_entity->setBoardWidth(value.toInt());
}
void CalibraterView::onParamChanged_BoardWidth() const
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getBoardWidth()));
	if (tmp != ui.lineEdit_BoardWidth->text())
	{
		ui.lineEdit_BoardWidth->setText(tmp);
	}
}

void CalibraterView::onValueChanged_BoardHeight(QString value)
{
	m_calib_entity->setBoardHeight(value.toInt());
}
void CalibraterView::onParamChanged_BoardHeight()
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getBoardHeight()));
	if (tmp != ui.lineEdit_BoardHeight->text())
	{
		ui.lineEdit_BoardHeight->setText(tmp);
	}
}

void CalibraterView::onValueChanged_SquareSize(QString value)
{
	m_calib_entity->setSquareSize(value.toInt());
}

void CalibraterView::onParamChanged_SquareSize()
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getSquareSize()));
	if (tmp != ui.lineEdit_SquareSize->text())
	{
		ui.lineEdit_SquareSize->setText(tmp);
	}
}

void CalibraterView::onClicked_showRectified(bool value)
{
	m_calib_entity->setshowRectified(value);

}
void CalibraterView::onParamChanged_showRectified()
{
	ui.checkBox_showRectified->setChecked(m_calib_entity->getshowRectified());

}

void CalibraterView::onClicked_Bouguet(bool value)
{
	m_calib_entity->setBouguet(value);
}
void CalibraterView::onParamChanged_Bouguet()
{
	ui.radioButton_Bouguet->setChecked(m_calib_entity->getBouguet());
}

void CalibraterView::onClicked_Hartley(bool value)
{
	m_calib_entity->setHartley(value);
}
void CalibraterView::onParamChanged_Hartley()
{
	ui.radioButton_Hartley->setChecked(m_calib_entity->getHartley());
}

void CalibraterView::onParamChanged_imgLtoShow()
{
	QImage LQImage = EvisionUtils::cvMat2QImage(m_calib_entity->getImageLtoShow());
	QGraphicsScene *sceneL = new QGraphicsScene;
	sceneL->addPixmap(QPixmap::fromImage(LQImage));
	ui.graphicsView_L->setScene(sceneL);
	QRectF bounds = sceneL->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_L->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_L->centerOn(0, 0);
	ui.graphicsView_L->show();
	ui.graphicsView_L->update();
}

void CalibraterView::onParamChanged_imgRtoShow()
{
	QImage RQImage = EvisionUtils::cvMat2QImage(m_calib_entity->getImageRtoShow());
	QGraphicsScene *sceneR = new QGraphicsScene;
	sceneR->addPixmap(QPixmap::fromImage(RQImage));
	ui.graphicsView_R->setScene(sceneR);
	QRectF bounds = sceneR->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView_R->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView_R->centerOn(0, 0);
	ui.graphicsView_R->show();
	ui.graphicsView_R->update();
}

