#include "RFinterface.h"
#include "EvisionUtils.h"

RFinterface::RFinterface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_graphicsViewOrigin = new RFScene();
	m_graphicsViewDisparity = new RFScene();
	ui.gridLayout_O->addWidget(m_graphicsViewOrigin);
	ui.gridLayout_D->addWidget(m_graphicsViewDisparity);

	connect(m_graphicsViewOrigin, SIGNAL(mouseMove(int,int)), this, SLOT(onMouseMove(int, int)));
	connect(m_graphicsViewOrigin, SIGNAL(mouseLDown(int, int)), this, SLOT(onMouseLButtonDown(int, int)));
	connect(m_graphicsViewOrigin, SIGNAL(mouseRDown(int, int)), this, SLOT(onMouseRButtonDown(int, int)));

	connect(m_graphicsViewDisparity, SIGNAL(mouseMove(int, int)), this, SLOT(onMouseMove(int, int)));
	connect(m_graphicsViewDisparity, SIGNAL(mouseLDown(int, int)), this, SLOT(onMouseLButtonDown(int, int)));
	connect(m_graphicsViewDisparity, SIGNAL(mouseRDown(int, int)), this, SLOT(onMouseRButtonDown(int, int)));

}

RFinterface::RFinterface(cv::Mat img, cv::Mat disp, cv::Mat xyz, QWidget* parent)
{
	ui.setupUi(this);
	m_graphicsViewOrigin = new RFScene();
	m_graphicsViewDisparity = new RFScene();
	ui.gridLayout_O->addWidget(m_graphicsViewOrigin);
	ui.gridLayout_D->addWidget(m_graphicsViewDisparity);

	connect(m_graphicsViewOrigin, SIGNAL(mouseMove(int, int)), this, SLOT(onMouseMove(int, int)));
	connect(m_graphicsViewOrigin, SIGNAL(mouseLDown(int, int)), this, SLOT(onMouseLButtonDown(int, int)));
	connect(m_graphicsViewOrigin, SIGNAL(mouseRDown(int, int)), this, SLOT(onMouseRButtonDown(int, int)));

	connect(m_graphicsViewDisparity, SIGNAL(mouseMove(int, int)), this, SLOT(onMouseMove(int, int)));
	connect(m_graphicsViewDisparity, SIGNAL(mouseLDown(int, int)), this, SLOT(onMouseLButtonDown(int, int)));
	connect(m_graphicsViewDisparity, SIGNAL(mouseRDown(int, int)), this, SLOT(onMouseRButtonDown(int, int)));

	this->img  = img;
	this->disp = disp;
	this->xyz  = xyz;

	std::vector<cv::Mat> xyzSet;
	split(xyz, xyzSet);
	xyzSet[2].copyTo(depth);

	printImgToD(disp);
	printImgToO(img);
}

RFinterface::~RFinterface()
{
}
//向O窗口画图
void RFinterface::printImgToO(cv::Mat value)
{
	QImage QImage = EvisionUtils::cvMat2QImage(value);
	QGraphicsScene *sceneL = new QGraphicsScene;
	sceneL->addPixmap(QPixmap::fromImage(QImage));
	m_graphicsViewOrigin->setScene(sceneL);

	//QRectF bounds = sceneL->itemsBoundingRect();
	//bounds.setWidth(bounds.width());         // to tighten-up margins
	//bounds.setHeight(bounds.height());       // same as above
	//m_graphicsViewOrigin->fitInView(bounds, Qt::KeepAspectRatio);
	//m_graphicsViewOrigin->centerOn(0, 0);
	m_graphicsViewOrigin->resize(QImage.width(), QImage.height());

	m_graphicsViewOrigin->show();
	m_graphicsViewOrigin->update();
}
//向D窗口画图
void RFinterface::printImgToD(cv::Mat value)
{
	QImage QImage = EvisionUtils::cvMat2QImage(value);
	QGraphicsScene *sceneL = new QGraphicsScene;
	sceneL->addPixmap(QPixmap::fromImage(QImage));
	m_graphicsViewDisparity->setScene(sceneL);

	//QRectF bounds = sceneL->itemsBoundingRect();
	//bounds.setWidth(bounds.width());         // to tighten-up margins
	//bounds.setHeight(bounds.height());       // same as above
	//m_graphicsViewDisparity->fitInView(bounds, Qt::KeepAspectRatio);
	//m_graphicsViewDisparity->centerOn(0, 0);
	m_graphicsViewDisparity->resize(QImage.width(), QImage.height());

	m_graphicsViewDisparity->show();
	m_graphicsViewDisparity->update();
}

//响应鼠标移动
void RFinterface::onMouseMove(int x, int y)
{
	ui.lineEdit_ImgX->setText(QString::fromStdString(std::to_string(x)));
	ui.lineEdit_ImgY->setText(QString::fromStdString(std::to_string(y)));

}
//响应鼠标左键击键
void RFinterface::onMouseLButtonDown(int x, int y)
{
}
//响应鼠标右键击键
void RFinterface::onMouseRButtonDown(int x, int y)
{
}
