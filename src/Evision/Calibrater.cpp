#include "Calibrater.h"
#include "EvisionUtils.h"

Calibrater::Calibrater(QWidget *parent)
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
	connect(m_calib_entity, SIGNAL(paramChanged_msgBuffer()), this, SLOT(onParamChanged_msgBuffer()));

}

Calibrater::~Calibrater()
{
}
//默认标定参数
void Calibrater::setDefaultCalibParam()
{
	m_calib_controller->setDefaultCalibParamCommand();
}
//标定
void Calibrater::doCalib()
{
	m_calib_controller->CalibrateCommand();
}

void Calibrater::onValueChanged_BoardWidth(QString value)
{
	m_calib_entity->setBoardWidth(value.toInt());
}
void Calibrater::onParamChanged_BoardWidth() const
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getBoardWidth()));
	if (tmp != ui.lineEdit_BoardWidth->text())
	{
		ui.lineEdit_BoardWidth->setText(tmp);
	}
}

void Calibrater::onValueChanged_BoardHeight(QString value)
{
	m_calib_entity->setBoardHeight(value.toInt());
}
void Calibrater::onParamChanged_BoardHeight()
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getBoardHeight()));
	if (tmp != ui.lineEdit_BoardHeight->text())
	{
		ui.lineEdit_BoardHeight->setText(tmp);
	}
}

void Calibrater::onValueChanged_SquareSize(QString value)
{
	m_calib_entity->setSquareSize(value.toInt());
}

void Calibrater::onParamChanged_SquareSize()
{
	QString tmp = QString::fromStdString(std::to_string(m_calib_entity->getSquareSize()));
	if (tmp != ui.lineEdit_SquareSize->text())
	{
		ui.lineEdit_SquareSize->setText(tmp);
	}
}

void Calibrater::onClicked_showRectified(bool value)
{
	m_calib_entity->setshowRectified(value);

}
void Calibrater::onParamChanged_showRectified()
{
	ui.checkBox_showRectified->setChecked(m_calib_entity->getshowRectified());

}

void Calibrater::onClicked_Bouguet(bool value)
{
	m_calib_entity->setBouguet(value);
}
void Calibrater::onParamChanged_Bouguet()
{
	ui.radioButton_Bouguet->setChecked(m_calib_entity->getBouguet());
}

void Calibrater::onClicked_Hartley(bool value)
{
	m_calib_entity->setHartley(value);
}
void Calibrater::onParamChanged_Hartley()
{
	ui.radioButton_Hartley->setChecked(m_calib_entity->getHartley());
}

void Calibrater::onParamChanged_imgLtoShow()
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

void Calibrater::onParamChanged_imgRtoShow()
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
//消息缓存更新
void Calibrater::onParamChanged_msgBuffer()
{
	ui.textEdit->append(m_calib_entity->getmsgBuffer());
}
