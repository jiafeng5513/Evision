#include "CameraView.h"
#include <librealsense2/rs.hpp>
#include <EvisionUtils.h>
#include <thread>
#include <QDir>
#include <QFileDialog>
#include <QDateTime>
CameraView::CameraView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    sceneL = new QGraphicsScene();
    sceneR = new QGraphicsScene();
    sceneRGB = new QGraphicsScene();
    sceneDepth = new QGraphicsScene();

    connect(this, SIGNAL(paramChange_ImgL()), this, SLOT(OnParamChange_ImgL()),Qt::QueuedConnection);
    connect(this, SIGNAL(paramChange_ImgR()), this, SLOT(OnParamChange_ImgR()), Qt::QueuedConnection);
    connect(this, SIGNAL(paramChange_ImgRGB()), this, SLOT(OnParamChange_ImgRGB()), Qt::QueuedConnection);
    connect(this, SIGNAL(paramChange_ImgDepth()), this, SLOT(OnParamChange_ImgDepth()), Qt::QueuedConnection);

	ui.lcdNumber->display(0);
	ui.pushButton_CameraOn->setEnabled(true);
	ui.pushButton_CameraOff->setEnabled(true);
	ui.lineEdit_SavePath->setText(QDir::currentPath());

}

CameraView::~CameraView()
{
	
}
//窗口关闭事件
void CameraView::closeEvent(QCloseEvent * e)
{
	
}
//realsense线程
void CameraView::RealSenseThread()
{
    // judge whether devices is exist or not 
    rs2::context ctx;
    auto list = ctx.query_devices(); // Get a snapshot of currently connected devices
    if (list.size() == 0)
        throw std::runtime_error("No device detected. Is it plugged in?");
    rs2::device dev = list.front();

    rs2::frameset frames;

    rs2::pipeline pipe;//创建一个通信管道

    rs2::config cfg;//创建一个以非默认配置的配置用来配置管道
    cfg.enable_stream(RS2_STREAM_COLOR, width, height, RS2_FORMAT_BGR8, fps);//向配置添加所需的流
    cfg.enable_stream(RS2_STREAM_DEPTH, width, height, RS2_FORMAT_Z16, fps);
    cfg.enable_stream(RS2_STREAM_INFRARED, 1, width, height, RS2_FORMAT_Y8, fps);
    cfg.enable_stream(RS2_STREAM_INFRARED, 2, width, height, RS2_FORMAT_Y8, fps);
    cfg.enable_stream(RS2_STREAM_ACCEL, RS2_FORMAT_MOTION_XYZ32F);
    cfg.enable_stream(RS2_STREAM_GYRO, RS2_FORMAT_MOTION_XYZ32F);

    // get depth scale 
    // float depth_scale = get_depth_scale(profile.get_device());
    // 这里dev->get_depth_scale()返回深度值和实际尺度的比例，0.001。
    //const uint16_t one_meter = static_cast<uint16_t>(1.0f / get_depth_scale());
    // start stream 
    pipe.start(cfg);//指示管道使用所请求的配置启动流

    int i = 0;
    rs2::colorizer color_map;
    rs2::hole_filling_filter hole_filling;
    while (keepRunning)
    {
        frames = pipe.wait_for_frames();//等待所有配置的流生成框架

        // Align to depth 
        /*rs2::align align_to_depth(RS2_STREAM_DEPTH);
        frames = align_to_depth.process(frames);*/

        //Get each frame
        rs2::frame color_frame = frames.get_color_frame();//RGB相机
        rs2::frame depth_frame = frames.get_depth_frame();//深度图
        //rs2::frame rainbow_depth_frame = frames.get_depth_frame().apply_filter(color_map).apply_filter(hole_filling);//彩虹深度图
        rs2::video_frame ir_frame_left = frames.get_infrared_frame(1);//红外相机1
        rs2::video_frame ir_frame_right = frames.get_infrared_frame(2);//红外相机2


        // Creating OpenCV Matrix from a color image
        color = new cv::Mat(cv::Size(width, height), CV_8UC3, (void*)color_frame.get_data(), cv::Mat::AUTO_STEP);
        emit paramChange_ImgRGB();
        pic_right = new cv::Mat(imgsize, CV_8UC1, (void*)ir_frame_right.get_data());
        emit paramChange_ImgR();
        pic_left = new cv::Mat(imgsize, CV_8UC1, (void*)ir_frame_left.get_data());
        emit paramChange_ImgL();
        pic_depth = new cv::Mat(imgsize, CV_16U, (void*)depth_frame.get_data(), cv::Mat::AUTO_STEP);
        emit paramChange_ImgDepth();
    }
}
//
void CameraView::printImgToL(cv::Mat value)
{
    sceneL->clear();
    QImage QImage = EvisionUtils::cvMat2QImage(value);
    sceneL->addPixmap(QPixmap::fromImage(QImage));
    ui.graphicsView_L->setScene(sceneL);
    //QRectF bounds = sceneL->itemsBoundingRect();
    //bounds.setWidth(bounds.width());
    //bounds.setHeight(bounds.height());
    //ui.graphicsView_L->fitInView(bounds, Qt::KeepAspectRatio);
    ui.graphicsView_L->centerOn(0, 0);
    ui.graphicsView_L->show();
    ui.graphicsView_L->update();
}
//
void CameraView::printImgToR(cv::Mat value)
{
    sceneR->clear();
    QImage QImage = EvisionUtils::cvMat2QImage(value);
    sceneR->addPixmap(QPixmap::fromImage(QImage));
    ui.graphicsView_R->setScene(sceneR);
    //QRectF bounds = sceneR->itemsBoundingRect();
    //bounds.setWidth(bounds.width());
    //bounds.setHeight(bounds.height());
    //ui.graphicsView_R->fitInView(bounds, Qt::KeepAspectRatio);
    ui.graphicsView_R->centerOn(0, 0);
    ui.graphicsView_R->show();
    ui.graphicsView_R->update();
}
//
void CameraView::printImgToRGB(cv::Mat value)
{
    sceneRGB->clear();
    QImage QImage = EvisionUtils::cvMat2QImage(value);
    sceneRGB->addPixmap(QPixmap::fromImage(QImage));
    ui.graphicsView_RGB->setScene(sceneRGB);
    //QRectF bounds = sceneRGB->itemsBoundingRect();
    //bounds.setWidth(bounds.width());
    //bounds.setHeight(bounds.height());
    //ui.graphicsView_RGB->fitInView(bounds, Qt::KeepAspectRatio);
    ui.graphicsView_RGB->centerOn(0, 0);
    ui.graphicsView_RGB->show();
    ui.graphicsView_RGB->update();
}
//
void CameraView::printImgToDepth(cv::Mat value)
{
    sceneDepth->clear();
    QImage QImage = EvisionUtils::cvMat2QImage(value);
    sceneDepth->addPixmap(QPixmap::fromImage(QImage));
    ui.graphicsView_Depth->setScene(sceneDepth);
    //QRectF bounds = sceneL->itemsBoundingRect();
    //bounds.setWidth(bounds.width());
    //bounds.setHeight(bounds.height());
    //ui.graphicsView_Depth->fitInView(bounds, Qt::KeepAspectRatio);
    ui.graphicsView_Depth->centerOn(0, 0);
    ui.graphicsView_Depth->show();
    ui.graphicsView_Depth->update();
}
//选择保存位置
void CameraView::OnFindSavePath()
{
	QFileDialog * fileDialog2 = new QFileDialog();
	fileDialog2->setWindowTitle(QStringLiteral("请选择保存位置"));
    fileDialog2->setDirectory(QString::fromStdString(EvisionUtils::pathPurify(EvisionUtils::getCurrentPath() + "\\..\\..\\..\\data")));
	fileDialog2->setFileMode(QFileDialog::DirectoryOnly);
	if (fileDialog2->exec() == QDialog::Accepted)
	{
		saveToHere = fileDialog2->selectedFiles().at(0);
		ui.lineEdit_SavePath->setText(saveToHere);
	}
}
//开机
void CameraView::OnCameraPowerOn()
{
    keepRunning = true;
    std::thread _t(&CameraView::RealSenseThread,this);
    _t.detach();
}
//关机
void CameraView::OnCameraPowerOff()
{
    keepRunning = false;
}
//拍照
void CameraView::OnShot()
{
	QString idt = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
	//m_pImageCapture->capture(ui.lineEdit_SavePath->text() + "/S" + idt + ".jpg");
	ui.lcdNumber->display(ui.lcdNumber->intValue()+1);
}

void CameraView::OnParamChange_ImgL()
{
    printImgToL(*pic_left);
}

void CameraView::OnParamChange_ImgR()
{
    printImgToR(*pic_right);
}

void CameraView::OnParamChange_ImgRGB()
{
    printImgToRGB(*color);
}

void CameraView::OnParamChange_ImgDepth()
{
    printImgToDepth((*pic_depth) * 15);
}
