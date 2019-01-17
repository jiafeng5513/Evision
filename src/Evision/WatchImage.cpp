#include "WatchImage.h"
#include"QWheelEvent"
#include "qDebug"
void MyGraphicsView::wheelEvent(QWheelEvent * event)
{
	emit mouseWheelZoom( event->delta());
}


WatchImage::WatchImage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
//带参数直接打开
WatchImage::WatchImage(QString filename, QWidget* parent)
{
	ui.setupUi(this);
	m_GraphicsView = new MyGraphicsView();
	//.a
	ui.gridLayout->addWidget(m_GraphicsView);
	connect(m_GraphicsView, SIGNAL(mouseWheelZoom(int)), this, SLOT(onMouseWheelZoom(int)));

	image = new QImage(filename);

	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap::fromImage(*image));
	m_GraphicsView->setScene(scene);
	//ui.graphicsView->resize(image->width() + 10, image->height() + 10);
	m_GraphicsView->show();
	this->setWindowTitle("WatchImage-"+filename);
}

WatchImage::~WatchImage()
{
}
//响应鼠标滚轮的动作
void WatchImage::onMouseWheelZoom(int delta)
{
	qDebug() << QString::fromStdString(std::to_string(delta));
	if (delta > 0 && scaleFactor >= 0)
	{
		scaleFactor += 5;
		QMatrix old_matrix;
		old_matrix = m_GraphicsView->matrix();
		m_GraphicsView->resetMatrix();
		m_GraphicsView->translate(old_matrix.dx(), old_matrix.dy());
		m_GraphicsView->scale(scaleFactor / 100.0, scaleFactor / 100.0);
	}
	else if (delta < 0 && scaleFactor >= 0)
	{
		scaleFactor -= 5;
		QMatrix old_matrix;
		old_matrix = m_GraphicsView->matrix();
		m_GraphicsView->resetMatrix();
		m_GraphicsView->translate(old_matrix.dx(), old_matrix.dy());
		m_GraphicsView->scale(scaleFactor / 100.0, scaleFactor / 100.0);
	}
	else if (scaleFactor < 0) {
		scaleFactor = 0.0;
	}
}

