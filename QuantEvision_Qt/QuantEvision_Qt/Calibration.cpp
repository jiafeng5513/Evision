#include "Calibration.h"
#include <QFileDialog>

#include "opencv2\core\core.hpp"
#include "cv.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <math.h>
#include <vector>
#include "CommonHelper.h"

/*
 * 本类是"标定"功能的视图类,业务逻辑在...中
 */

Calibration::Calibration(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//初始化Calibrater
	Calibrater::getInstance()->initialize();
	//连接信号,使用异步模式
	imgLtoShow = *new cv::Mat();
	imgRtoShow = *new cv::Mat();
	connect(this, SIGNAL(IsTimeToShowImages()), this, SLOT(OnShowImages()));
}

Calibration::~Calibration()
{
}
//显示图片
void Calibration::ShowImage(cv::Mat imgL, cv::Mat imgR)
{
	
	//把两张Mat转换为QImage
	QImage LQImage = CommonHelper::cvMat2QImage(imgL);
	QImage RQImage = CommonHelper::cvMat2QImage(imgR);
	//显示两张QImage
	ui.Viewer_CalibrateL;

	QGraphicsScene *sceneL = new QGraphicsScene;
	sceneL->addPixmap(QPixmap::fromImage(LQImage));
	ui.Viewer_CalibrateL->setScene(sceneL);
	//ui.Viewer_CalibrateL->resize(LQImage.width() + 10, LQImage.height() + 10);
	ui.Viewer_CalibrateL->show();

	QGraphicsScene *sceneR = new QGraphicsScene;
	sceneR->addPixmap(QPixmap::fromImage(RQImage));
	ui.Viewer_CalibrateR->setScene(sceneR);
	//ui.Viewer_CalibrateR->resize(RQImage.width() + 10, RQImage.height() + 10);
	ui.Viewer_CalibrateR->show();

	ui.Viewer_CalibrateR->update();
}
//响应显示图片的信号
void Calibration::OnShowImages()
{
	ShowImage(imgLtoShow, imgRtoShow);
}

//标定板默认参数
void Calibration::OnDefaultBoardParams()
{
	ui.lineEdit_BoardWidth->setText("9");
	ui.lineEdit_BoardHeight->setText("6");
	ui.lineEdit__nBoards->setText("20");
	ui.lineEdit_SquareSize->setText("25");
	ui.lineEdit_Alpha->setText("-1");
	ui.checkBox_FPP->setChecked(true);
	ui.checkBox_UIG->setChecked(true);
	ui.checkBox_FAR->setChecked(true);
	ui.checkBox_SFL->setChecked(true);
	ui.checkBox_FI->setChecked(false);
	ui.checkBox_Bouguet->setChecked(true);
	ui.checkBox_Hartley->setChecked(false);
}
//点击"Bouguet"选项
void Calibration::OnChecked_Bouguet()
{
}
//点击"Hartley"选项
void Calibration::OnChecked_Hartley()
{
}
//点击"Fi"选项
void Calibration::OnChecked_Fi()
{
}
//点击"Uig"选项
void Calibration::OnChecked_Uig()
{
}
//点击"SFI"选项
void Calibration::OnChecked_Sfl()
{
}
//点击"FPP选项"
void Calibration::OnChecked_FPP()
{
}
//点击"FAR"选项
void Calibration::OnChecked_Far()
{
}
//选择标定图片
void Calibration::OnChooseImages()
{
	QFileDialog fileDialog(this);
	fileDialog.setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片文件序列"));
	fileDialog.setNameFilter("图片文件(*.jpg *.png *.jpeg)");
	fileDialog.setFileMode(QFileDialog::ExistingFiles);

	
	if (fileDialog.exec() == QDialog::Accepted)
	{
		ImageListL = fileDialog.selectedFiles();
		fileDialog.setWindowTitle(QStringLiteral("请选择右摄像头拍摄的图片文件序列"));
		if (fileDialog.exec() == QDialog::Accepted)
		{
			ImageListR = fileDialog.selectedFiles();
			//两个文件列表都点击了确定
			//验证数量
			if(ImageListL.size()!= ImageListR.size()|| ImageListL.size()==0|| ImageListR.size()==0)
			{
				//有一侧图像数目为0或者两侧的图像数量不一样,退出
				return;
			}
			else
			{
				/*
				 *一切正常
				 *可以进行从图片标定,现在可以将从图片标定的按钮解禁
				 */
				ui.pushButton_CalibStart->setEnabled(true);
			}
		}
		else
		{
			//选择右图的时候退出
			return;
		}
	}
	else
	{
		//选择左图的时候退出
		return;
	}
}
//从图片标定
void Calibration::OnCalibrateFromImage()
{
	//1. 尺寸归一化
	//2. 参数结合
	//3. 开线程标定,线程向缓冲区里面写入处理完的图片,主进程槽函数监听缓冲区的变化,把新进入的刷新到界面上
	cv::Mat frame0, frame1, img0, img1;
	//取左视图第一张图片问样本计算尺寸
	img0 = cvLoadImage(ImageListL.at(0).toStdString().c_str());
	if (img0.rows>1000)
	{
		cv::resize(img0, img0, cv::Size(img0.cols / 6, img0.rows / 6));
	}
	//参数结合
	//实际的迭代次数,初值为:用户设置的迭代次数/左视图图片张数/右视图图片张数,三者中的最小值
	int NumOfAvailableImages = std::min(ui.lineEdit__nBoards->text().toInt(), std::min(ImageListL.size(), ImageListR.size()));
	Calibrater::getInstance()->initCornerData(
		NumOfAvailableImages,
		img0.size(),
		cv::Size(ui.lineEdit_BoardWidth->text().toInt(), ui.lineEdit_BoardHeight->text().toInt()),
		ui.lineEdit_SquareSize->text().toDouble());

	// 开始检测角点
	int nSucceedBoard = 0;//计算成功的图片的数量
	for (int i = 0; i<NumOfAvailableImages; i++)
	{
		frame0 = cvLoadImage(ImageListL.at(i).toStdString().c_str());
		img0 = frame0.clone();
		if (img0.rows>1000)
		{
			cv::resize(img0, img0, cv::Size(img0.cols / 6, img0.rows / 6));
		}
		frame1 = cvLoadImage(ImageListR.at(i).toStdString().c_str());
		img1 = frame1.clone();
		if (img1.rows>1000)
		{
			cv::resize(img1, img1, cv::Size(img1.cols / 6, img1.rows / 6));
		}

		//if (img0.rows>1000)//???
		//{
		//	cv::resize(img0, img0, cv::Size(img0.cols / 6, img0.rows / 6));
		//	cv::resize(img1, img1, cv::Size(img1.cols / 6, img1.rows / 6));
		//}
		// 检测角点

		if (Calibrater::getInstance()->detectCorners(img0, img1, i))//如果检测成功
		{
			nSucceedBoard++;//成功的图片数量加1
			cv::bitwise_not(img0, img0);//使图像反色，表明同时找到完整的棋盘角点
			cv::bitwise_not(img1, img1);
		}
		else//如果检测失败
		{
			//PutMessage(CalibWnd, _T("此图片检测失败!\n"));
		}
		//F_ShowImage(img0, m_lfImage, IDC_PicLfCam);//向界面上刷新两张图 
		//F_ShowImage(img1, m_riImage, IDC_PicRiCam);
		//ShowImage(img0, img1);
		imgLtoShow = img0;
		imgRtoShow = img1;
		emit IsTimeToShowImages();
	}
	if (nSucceedBoard < 4)//成功的数量小于4,无法用于标定
	{
		//PutMessage(CalibWnd, _T("检测成功的棋盘图像数小于4个，标定失败!\n请重新进行标定操作.\n"));
		return;
	}
	Calibrater::getInstance()->resizeCornerData(nSucceedBoard);//调整参数存储区的大小
	// 保存角点坐标数据
	QString FileTemp= WorkPath;
	FileTemp.append("\\");
	FileTemp.append("\\DATA\\CornerData.yml");
	Calibrater::getInstance()->saveCornerData(FileTemp.toStdString().c_str());
	//PutMessage(CalibWnd, _T("棋盘角点检测结束.\n"));
	//至此,角点的数据和棋盘的数据已经获得,并保存在对应的属性中且转储为文件
	//标定参数结合
	Calibrater::getInstance()->stereoParams.flags = 0;//标志位现在shiver在Calibrater中直接给出的,应该设置到界面上从外部给出
	Calibrater::getInstance()->stereoParams.alpha = ui.lineEdit_Alpha->text().toInt();
	//标定
	Calibrater::getInstance()->calibrateStereoCamera();
	//计算标定误差
	double avgErr = 0;
	Calibrater::getInstance()->getStereoCalibrateError(avgErr);
	char info[50];
	sprintf_s(info, "标定误差 = %7.4g", avgErr);

	//PutMessage(CalibWnd, ss);//输出标定误差
	//至此标定结束

	// 执行校正
	Calibrater::getInstance()->rectifyStereoCamera((ui.checkBox_Bouguet->isChecked()==true? Calibrater::RECTIFY_BOUGUET: Calibrater::RECTIFY_HARTLEY));
	//得到重投影矩阵和校正映射矩阵
	//PutMessage(CalibWnd, _T("已完成双目校正.\n"));
	// 保存摄像头定标参数
	QString CalibParasFile= WorkPath;
	CalibParasFile.append("\\DATA\\calib_paras.xml");
	Calibrater::getInstance()->saveCalibrationDatas(
		CalibParasFile.toStdString().c_str(), 
		(ui.checkBox_Bouguet->isChecked() == true ? Calibrater::RECTIFY_BOUGUET : Calibrater::RECTIFY_HARTLEY));
	//PutMessage(CalibWnd, _T("已保存定标参数文件:\n"));
	if (avgErr > 5.0) {
		//AfxMessageBox(_T("标定误差过大!强烈建议您检查标定来源的合理性并进行调整和重试,如果您继续执行操作,将会降低结果的置信度!"));
	}
}
//变更左摄像头
void Calibration::OnChanged_LCameraComboBox()
{
}
//变更右摄像头
void Calibration::OnChanged_RChangeComboBox()
{
}
//变更分辨率
void Calibration::OnChanged_ResolutionComboBox()
{
}
//刷新摄像头
void Calibration::OnRefreshCameras()
{
}
//启动/关闭摄像头
void Calibration::OnCamerasPowerOn()
{
}
//从摄像头标定
void Calibration::OnCalibrateFromCameras()
{
}
//选择标定文件
void Calibration::OnChooseCalibrateFile()
{
}
//从文件标定
void Calibration::OnCalibrateFromFile()
{
}
//测试:显示图片
void Calibration::OnShowImg()
{
	QFileDialog fileDialog(this);
	fileDialog.setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片文件序列"));
	fileDialog.setNameFilter("图片文件(*.jpg *.png *.jpeg)");
	//fileDialog.setFileMode(QFileDialog::ExistingFiles);


	if (fileDialog.exec() == QDialog::Accepted)
	{
		//QString X = fileDialog.selectedFiles().at(0);
		//std::string  Y = X.toStdString();
		//const char * str = Y.c_str();
		//cv::Mat temp=cvLoadImage(str);

		//QByteArray ba = X.toLatin1();
		//const char *c_str2 = ba.data();

		cv::Mat img = cv::imread(fileDialog.selectedFiles().at(0).toStdString().c_str(), CV_LOAD_IMAGE_UNCHANGED);

		
		if (img.empty()==false)
		{
			cv::namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
			imshow("MyWindow", img);
			cv::waitKey(0);
			//cvReleaseImage(&temp);
			cv::destroyWindow("MyWindow");
		}
		imgLtoShow = img;
		imgRtoShow = img;
		emit IsTimeToShowImages();
		//ShowImage(img, img);
	}
}
