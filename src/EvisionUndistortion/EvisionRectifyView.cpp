#include "EvisionRectifyView.h"
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMessageBox>
#include "rectify.h"
#include "EvisionUtils.h"

EvisionRectifyView::EvisionRectifyView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.progressBar->setValue(0);
	ui.pushButton_Start->setEnabled(true);
}

EvisionRectifyView::~EvisionRectifyView()
{
}
/*
 * 初始化
 */
void EvisionRectifyView::init()
{

}

void EvisionRectifyView::onPush_SelectSrcFolder()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	fileDialog->setWindowTitle("Please select the folder of the pictures to be rectified");
	fileDialog->setFileMode(QFileDialog::Directory);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		QString srcpath=fileDialog->selectedFiles()[0];
		ui.lineEdit_src->setText(srcpath);
		QFileInfoList fil=GetFileList(srcpath);
		//fil[0].

		for (int i = 0; i < fil.size(); ++i)
		{
			QListWidgetItem*item = new QListWidgetItem;
			item->setText(fil[i].fileName());
			ui.listWidget_Src->addItem(item);
			filesMap.insert(std::pair<QString, QString>(fil[i].fileName(), fil[i].absoluteFilePath()));
		}

	}
}

void EvisionRectifyView::onPush_SelectTargetFolder()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	fileDialog->setWindowTitle("Please choose where to save the rectified pictures");
	fileDialog->setFileMode(QFileDialog::Directory);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		target_path = fileDialog->selectedFiles()[0];
		ui.lineEdit_target->setText(target_path);
	}
}

void EvisionRectifyView::onPush_SelectCameraParamFile()
{
	QFileDialog * fileDialog = new QFileDialog();
	fileDialog->setDirectory(QString::fromStdString(EvisionUtils::getDataPath()));
	fileDialog->setWindowTitle("Please select camera parameter file");
	fileDialog->setNameFilter("camera parameter file(*.yml)");
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	if (fileDialog->exec() == QDialog::Accepted)
	{
		camera_param_file = fileDialog->selectedFiles()[0].toStdString();
	}
}

void EvisionRectifyView::onAddToTargetList()
{
	auto itemlist = ui.listWidget_Src->selectedItems();

	for (int i = 0; i < itemlist.size(); ++i)
	{
		ui.listWidget_Target->addItem(itemlist[i]->clone());
	}
}

void EvisionRectifyView::onDeleteFromTargetList()
{
	auto itemlist = ui.listWidget_Target->selectedItems();
	for (int i = 0; i < itemlist.size(); ++i)
	{
		ui.listWidget_Target->takeItem(ui.listWidget_Target->row(itemlist[i]));
	}
}
//开始校准
void EvisionRectifyView::onStart()
{
	if(ui.listWidget_Target->count()<=0|| camera_param_file.empty()|| target_path.isEmpty())
	{
		QMessageBox::information(this, "Warning", "Check the completeness of parameters");
		return;
	}
	ui.progressBar->setValue(0);
	ui.progressBar->setRange(0, ui.listWidget_Target->count() + 5);
	//1.遍历出全部的target image
	for (int i = 0; i < ui.listWidget_Target->count(); ++i)
	{
		QString itemText = ui.listWidget_Target->item(i)->text();
		images.push_back(cv::imread(filesMap.at(itemText).toStdString()));
	}
	ui.progressBar->setValue(ui.progressBar->value() + 1);
	cv::Size imageSize;
	imageSize.height = ((cv::Mat)images.at(0)).rows;
	imageSize.width = ((cv::Mat)images.at(0)).cols;
	//TODO:读取相机参数文件,获取相机矩阵和畸变参数,p1 p2 r1 r2,roi1,roi2
	bool ok=EvisionUtils::read_ParamsForStereoRectify(camera_param_file,&cameraMatrix1,&distCoeffs1,&cameraMatrix2,&distCoeffs2,&R1,&P1,&R2,&P2,&roi1,&roi2);
	if(!ok)
	{
		std::cout << "read params failed" << std::endl;
		return;
	}
	ui.progressBar->setValue(ui.progressBar->value() + 1);
	//先把两侧的图片利用畸变矩阵分别消除畸变
	intrinsicExtrinsic::undistortStereoImages(images, undistortedImages, cameraMatrix1, cameraMatrix2, distCoeffs1, distCoeffs2);
	ui.progressBar->setValue(ui.progressBar->value() + 1);
	//这一步计算极线矫正矩阵,畸变已经消除了所以畸变参数设置为了0
	cv::Mat rmap[2][2];
	cv::Mat noDist = cv::Mat::zeros(5, 1, CV_32F);
	initUndistortRectifyMap(cameraMatrix1, noDist, R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);
	initUndistortRectifyMap(cameraMatrix2, noDist, R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);
	int imgCount = undistortedImages.size() / 2;
	ui.progressBar->setValue(ui.progressBar->value() + 1);
	//计算ROI
	cv::Point2i rectCorner1(std::max(roi1.x, roi2.x), std::max(roi1.y, roi2.y));
	cv::Point2i rectCorner2(std::min(roi1.x + roi1.width, roi2.x + roi2.width),
		std::min(roi1.y + roi1.height, roi2.y + roi2.height));
	cv::Rect validRoi = cv::Rect(rectCorner1.x, rectCorner1.y,rectCorner2.x - rectCorner1.x, rectCorner2.y - rectCorner1.y);

	std::string saveDir = target_path.toStdString();
	ui.progressBar->setValue(ui.progressBar->value() + 1);
	for (int i = 0; i < imgCount; i++)
	{
		std::cout << "[ImageRectify] rectify image " << (i + 1) << " of " << imgCount << std::endl;

		for (int k = 0; k < 2; k++)
		{
			cv::Mat img = undistortedImages[i * 2 + k], remapImg, rectImg;
			remap(img, remapImg, rmap[k][0], rmap[k][1], cv::INTER_LINEAR);

			std::stringstream filename;

			filename << saveDir << "/image" << i << "_" << ((k == 0) ? "1" : "2") << ".jpg";

			rectImg = remapImg(validRoi);
			imwrite(filename.str(), rectImg);
			ui.progressBar->setValue(ui.progressBar->value() + 1);
		}
	}
	ui.pushButton_Start->setEnabled(false);
}


QFileInfoList EvisionRectifyView::GetFileList(QString path)
{
	QDir dir(path);
	QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

	for (int i = 0; i != folder_list.size(); i++)
	{
		QString name = folder_list.at(i).absoluteFilePath();
		QFileInfoList child_file_list = GetFileList(name);
		file_list.append(child_file_list);
	}

	return file_list;
}