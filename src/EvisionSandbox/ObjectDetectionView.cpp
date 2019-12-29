#include "ObjectDetectionView.h"
#include <QFileDialog>
#include "EvisionUtils.h"

ObjectDetectionView::ObjectDetectionView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_engine = new ObjectDetectionEngine();
	//链接信号槽
	m_entity = ObjectDetectionEntity::getInstance();

	connect(m_entity, SIGNAL(paramChanged_DetectionPlayer()), this, SLOT(OnParamChanged_DetectionPlayer()));
	connect(m_entity, SIGNAL(paramChanged_cfgFilename()), this, SLOT(OnParamChanged_cfgFilename()));
	connect(m_entity, SIGNAL(paramChanged_weightsFilename()), this, SLOT(OnParamChanged_weightsFilename()));
	connect(m_entity, SIGNAL(paramChanged_namesFilename()), this, SLOT(OnParamChanged_namesFilename()));
}

ObjectDetectionView::~ObjectDetectionView()
{
}
//选择CFG文件
void ObjectDetectionView::OnBrowseCfg()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择CFG"));
	fileDialog->setNameFilter(QStringLiteral("CFG文件(*.cfg)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		m_entity->setCfgFilename(fileDialog->selectedFiles().at(0));
	}
}
//选择Weights文件
void ObjectDetectionView::OnBrowseWeights()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择weights文件"));
	fileDialog->setNameFilter(QStringLiteral("weighes文件(*.weights)"));
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		m_entity->setweightsFilename( fileDialog->selectedFiles().at(0));
	}
}
//选择Names文件
void ObjectDetectionView::OnBrowseNames()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择names文件"));
	fileDialog->setNameFilter(QStringLiteral("names文件(*.names)"));

	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		m_entity->setnamesFilename(fileDialog->selectedFiles().at(0));
	}
}
//Switch
void ObjectDetectionView::OnSwitch()
{
	//还没有开始运行:检查参数,启动线程
	if (m_engine->isRunning() == false)
	{
		if (!m_entity->getCfgFilename().isEmpty()&& !m_entity->getnamesFilename().isEmpty() && !m_entity->getweightsFilename().isEmpty())
		{
			m_engine->start();
		}
	}else if(m_engine->isRunning() == true)
	{
		m_entity->setRunningState(false);
	}
	
	//已经开始运行:停止运行

}
//响应帧刷新
void ObjectDetectionView::OnParamChanged_DetectionPlayer()
{
	QImage LQImage = EvisionUtils::cvMat2QImage(m_entity->getDetectionPlayer());
	QGraphicsScene *sceneL = new QGraphicsScene;
	sceneL->addPixmap(QPixmap::fromImage(LQImage));
	ui.graphicsView->setScene(sceneL);
	QRectF bounds = sceneL->itemsBoundingRect();
	bounds.setWidth(bounds.width());         // to tighten-up margins
	bounds.setHeight(bounds.height());       // same as above
	ui.graphicsView->fitInView(bounds, Qt::KeepAspectRatio);
	ui.graphicsView->centerOn(0, 0);
	ui.graphicsView->show();
	ui.graphicsView->update();
}

//响应cfgFile的更改
void ObjectDetectionView::OnParamChanged_cfgFilename()
{
	ui.lineEdit_Cfg->setText(m_entity->getCfgFilename());
}
//响应weights file的更新
void ObjectDetectionView::OnParamChanged_weightsFilename()
{
	ui.lineEdit_Weight->setText(m_entity->getweightsFilename());
}
//响应names file的更新
void ObjectDetectionView::OnParamChanged_namesFilename()
{
	ui.lineEdit_Name->setText(m_entity->getnamesFilename());
}
