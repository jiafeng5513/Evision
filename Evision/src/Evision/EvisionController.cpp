#include "EvisionController.h"
#include <QMessageBox>
#include "QFileDialog"
#include <imgcodecs/imgcodecs_c.h>
#include <imgproc.hpp>

EvisionController::EvisionController()
{
	m_entity = EvisionParamEntity::getInstance();
}


EvisionController::~EvisionController()
{
}
//命令:标定默认参数
void EvisionController::setDefaultCalibParamCommand()
{
	m_entity->setBoardWidth(9);
	m_entity->setBoardHeight(6);
	m_entity->setSquareSize(25);
	m_entity->setnBoards(20);
	m_entity->setAlpha(-1);
	m_entity->setFPP(true);
	m_entity->setUIG(true);
	m_entity->setFAR(true);
	m_entity->setSFL(true);
	m_entity->setFI(false);
	m_entity->setBouguet(true);
}
//命令:标定
void EvisionController::CalibrateCommand()
{
	//1.验证参数
	if (m_entity->getBoardWidth()*m_entity->getBoardHeight()*m_entity->getnBoards()*m_entity->getSquareSize()<=0)
	{
		//未通过参数完整性验证
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("参数有误!请检查!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}
	//2.选择文件
	QFileDialog * fileDialog=new QFileDialog();
	fileDialog->setWindowTitle(QStringLiteral("请选择左摄像头拍摄的图片文件序列"));
	fileDialog->setNameFilter("图片文件(*.jpg *.png *.jpeg)");
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		ImageListL = fileDialog->selectedFiles();
		fileDialog->setWindowTitle(QStringLiteral("请选择右摄像头拍摄的图片文件序列"));
		if (fileDialog->exec() == QDialog::Accepted)
		{
			ImageListR = fileDialog->selectedFiles();
			//两个文件列表都点击了确定
			//验证数量
			if (ImageListL.size() != ImageListR.size() || ImageListL.size() == 0 || ImageListR.size() == 0)
			{
				//有一侧图像数目为0或者两侧的图像数量不一样,退出
				QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("左右视图数量不相等或为空"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
				return;
			}
			else
			{
				/*
				 *3.一切正常,可以进行从图片标定
				 */
				
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

	//3.起飞
}

//命令:匹配默认参数
void EvisionController::setDefaultMatchParamCommand()
{
	if (m_entity->getBM())
	{
		m_entity->setMinDisp(0);
		m_entity->setUniradio(25);
		m_entity->setSpecwinsz(100);
		m_entity->setMaxDisp(144);
		m_entity->setSpecrange(32);
		m_entity->setPrefilcap(31);
		m_entity->setSadWinsz(51);
		m_entity->setTextThread(10);
		m_entity->setMaxdifdisp12(1);
	}
	else if (m_entity->getSGBM())
	{
		m_entity->setMinDisp(0);
		m_entity->setUniradio(20);
		m_entity->setSpecwinsz(100);
		m_entity->setMaxDisp(144);
		m_entity->setSpecrange(32);
		m_entity->setPrefilcap(63);
		m_entity->setSadWinsz(25);
		//m_entity->setTextThread(10);
		m_entity->setMaxdifdisp12(1);
	}
	else if (m_entity->getVAR())
	{
		m_entity->setMinDisp(-64);
		m_entity->setMaxDisp(64);
		m_entity->setLevels(1);
		m_entity->setPyrScale(0.1);
		m_entity->setPolyN(5);
		m_entity->setPolySigma(52.6);
		m_entity->setFi(90);
		m_entity->setLambda(0.82);
	}
	else
	{
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("没有选择匹配算法"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	}
}

//从图片标定
void EvisionController::CalibrateFromImage()
{
	//1. 尺寸归一化
	//2. 参数结合
	//3. 开线程标定,线程向缓冲区里面写入处理完的图片,主进程槽函数监听缓冲区的变化,把新进入的刷新到界面上
	//cv::Mat frame0, frame1, img0, img1;
	////取左视图第一张图片问样本计算尺寸
	//img0 = cvLoadImage(ImageListL.at(0).toStdString().c_str());
	//if (img0.rows > 1000)
	//{
	//	cv::resize(img0, img0, cv::Size(img0.cols / 6, img0.rows / 6));
	//}
	////参数结合
	////实际的迭代次数,初值为:用户设置的迭代次数/左视图图片张数/右视图图片张数,三者中的最小值
	//int NumOfAvailableImages = std::min(ui.lineEdit__nBoards->text().toInt(), std::min(ImageListL.size(), ImageListR.size()));
	//Calibrater::getInstance()->initCornerData(
	//	NumOfAvailableImages,
	//	img0.size(),
	//	cv::Size(ui.lineEdit_BoardWidth->text().toInt(), ui.lineEdit_BoardHeight->text().toInt()),
	//	ui.lineEdit_SquareSize->text().toDouble());

	//// 开始检测角点
	//int nSucceedBoard = 0;//计算成功的图片的数量
	//for (int i = 0; i < NumOfAvailableImages; i++)
	//{
	//	frame0 = cvLoadImage(ImageListL.at(i).toStdString().c_str());
	//	img0 = frame0.clone();
	//	if (img0.rows > 1000)
	//	{
	//		cv::resize(img0, img0, cv::Size(img0.cols / 6, img0.rows / 6));
	//	}
	//	frame1 = cvLoadImage(ImageListR.at(i).toStdString().c_str());
	//	img1 = frame1.clone();
	//	if (img1.rows > 1000)
	//	{
	//		cv::resize(img1, img1, cv::Size(img1.cols / 6, img1.rows / 6));
	//	}

	//	//if (img0.rows>1000)//???
	//	//{
	//	//	cv::resize(img0, img0, cv::Size(img0.cols / 6, img0.rows / 6));
	//	//	cv::resize(img1, img1, cv::Size(img1.cols / 6, img1.rows / 6));
	//	//}
	//	// 检测角点

	//	if (Calibrater::getInstance()->detectCorners(img0, img1, i))//如果检测成功
	//	{
	//		nSucceedBoard++;//成功的图片数量加1
	//		cv::bitwise_not(img0, img0);//使图像反色，表明同时找到完整的棋盘角点
	//		cv::bitwise_not(img1, img1);
	//	}
	//	else//如果检测失败
	//	{
	//		//PutMessage(CalibWnd, _T("此图片检测失败!\n"));
	//	}
	//	//F_ShowImage(img0, m_lfImage, IDC_PicLfCam);//向界面上刷新两张图 
	//	//F_ShowImage(img1, m_riImage, IDC_PicRiCam);
	//	//ShowImage(img0, img1);
	//	imgLtoShow = img0;
	//	imgRtoShow = img1;
	//	emit IsTimeToShowImages();
	//}
	//if (nSucceedBoard < 4)//成功的数量小于4,无法用于标定
	//{
	//	//PutMessage(CalibWnd, _T("检测成功的棋盘图像数小于4个，标定失败!\n请重新进行标定操作.\n"));
	//	return;
	//}
	//Calibrater::getInstance()->resizeCornerData(nSucceedBoard);//调整参数存储区的大小
	//// 保存角点坐标数据
	//QString FileTemp = WorkPath;
	//FileTemp.append("\\");
	//FileTemp.append("\\DATA\\CornerData.yml");
	//Calibrater::getInstance()->saveCornerData(FileTemp.toStdString().c_str());
	////PutMessage(CalibWnd, _T("棋盘角点检测结束.\n"));
	////至此,角点的数据和棋盘的数据已经获得,并保存在对应的属性中且转储为文件
	////标定参数结合
	//Calibrater::getInstance()->stereoParams.flags = 0;//标志位现在shiver在Calibrater中直接给出的,应该设置到界面上从外部给出
	//Calibrater::getInstance()->stereoParams.alpha = ui.lineEdit_Alpha->text().toInt();
	////标定
	//Calibrater::getInstance()->calibrateStereoCamera();
	////计算标定误差
	//double avgErr = 0;
	//Calibrater::getInstance()->getStereoCalibrateError(avgErr);
	//char info[50];
	//sprintf_s(info, "标定误差 = %7.4g", avgErr);

	////PutMessage(CalibWnd, ss);//输出标定误差
	////至此标定结束

	//// 执行校正
	//Calibrater::getInstance()->rectifyStereoCamera((ui.checkBox_Bouguet->isChecked() == true ? Calibrater::RECTIFY_BOUGUET : Calibrater::RECTIFY_HARTLEY));
	////得到重投影矩阵和校正映射矩阵
	////PutMessage(CalibWnd, _T("已完成双目校正.\n"));
	//// 保存摄像头定标参数
	//QString CalibParasFile = WorkPath;
	//CalibParasFile.append("\\DATA\\calib_paras.xml");
	//Calibrater::getInstance()->saveCalibrationDatas(
	//	CalibParasFile.toStdString().c_str(),
	//	(ui.checkBox_Bouguet->isChecked() == true ? Calibrater::RECTIFY_BOUGUET : Calibrater::RECTIFY_HARTLEY));
	////PutMessage(CalibWnd, _T("已保存定标参数文件:\n"));
	//if (avgErr > 5.0) {
	//	//AfxMessageBox(_T("标定误差过大!强烈建议您检查标定来源的合理性并进行调整和重试,如果您继续执行操作,将会降低结果的置信度!"));
	//}
}
