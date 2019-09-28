#include "EvisionController.h"
#include <QMessageBox>
#include "QFileDialog"
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/calib3d/calib3d.hpp>
#include "StereoCalibrate.h"
#include "QMessageBox"
#include "StereoMatch.h"
#include "TraceView.h"
#include "CameraView.h"
#include "StereoCameraView.h"

EvisionController::EvisionController(QObject * parent):QObject(parent)
{
	m_entity = EvisionParamEntity::getInstance();
}

EvisionController::~EvisionController()
{
}

//消息响应:弹出对话框
void EvisionController::onOpenMessageBox(QString title, QString msg)
{
	QMessageBox::information(NULL, title, msg);
}

