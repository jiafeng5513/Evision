#include "RFinterface.h"
#include "EvisionUtils.h"
#include "QGraphicsScene"
#include "PointCloudUtils.h"

RFinterface::RFinterface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

RFinterface::RFinterface(cv::Mat img, cv::Mat disp, cv::Mat xyz, QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
	this->img  = img;
	this->disp = disp;
	this->xyz  = xyz;

	std::vector<cv::Mat> xyzSet;
	split(xyz, xyzSet);
	xyzSet[2].copyTo(depth);

	std::vector<PointCloudUtils::ObjectInfo> objectInfos;
	PointCloudUtils pointCloudAnalyzer;
	if (pointCloudAnalyzer.detectNearObject(disp, xyz, objectInfos) == 0)
	{
		//失败处理
		return;
	}
	pointCloudAnalyzer.showObjectInfo(objectInfos, img);//在左视图上面叠加轮廓识别的框

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
	ui.customGraphicsView_O->setScene(sceneL);
	ui.customGraphicsView_O->setMinimumSize(QImage.width(), QImage.height());
	ui.customGraphicsView_O->setMaximumSize(QImage.width(), QImage.height());
	ui.customGraphicsView_O->show();
	ui.customGraphicsView_O->update();
}
//向D窗口画图
void RFinterface::printImgToD(cv::Mat value)
{
	QImage QImage = EvisionUtils::cvMat2QImage(value);
	QGraphicsScene *sceneL = new QGraphicsScene;
	sceneL->addPixmap(QPixmap::fromImage(QImage));
	ui.customGraphicsView_D->setScene(sceneL);
	ui.customGraphicsView_D->setMinimumSize(QImage.width(), QImage.height());
	ui.customGraphicsView_D->setMaximumSize(QImage.width(), QImage.height());
	ui.customGraphicsView_D->show();
	ui.customGraphicsView_D->update();
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
	m_ObjectDistance = 16 * depth.at<float>(y,x);
	ui.lineEdit_Res->setText(QString::fromStdString(std::to_string(m_ObjectDistance)));
}
//响应鼠标右键击键
void RFinterface::onMouseRButtonDown(int x, int y)
{

}
