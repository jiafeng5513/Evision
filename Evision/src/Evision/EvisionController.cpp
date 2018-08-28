#include "EvisionController.h"
#include <QMessageBox>
#include "QFileDialog"
#include <imgcodecs/imgcodecs_c.h>
#include <imgproc.hpp>
#include <highgui.hpp>
#include <iostream>
#include <calib3d/calib3d.hpp>

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
	
}
/*
 *
 */
void EvisionController::StereoCalib(const std::vector<std::string>& imagelist, cv::Size boardSize, float squareSize,
	bool displayCorners = false, bool useCalibrated = true, bool showRectified = true)
{
	if (imagelist.size() % 2 != 0)//图片不成对
	{
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("图片不成对!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}

	const int maxScale = 2;
	// ARRAY AND VECTOR STORAGE:

	std::vector<std::vector<cv::Point2f> > imagePoints[2];
	std::vector<std::vector<cv::Point3f> > objectPoints;
	cv::Size imageSize;

	int i, j, k, nimages = (int)imagelist.size() / 2;

	imagePoints[0].resize(nimages);
	imagePoints[1].resize(nimages);
	std::vector<std::string> goodImageList;

	for (i = j = 0; i < nimages; i++)
	{
		for (k = 0; k < 2; k++)
		{
			const std::string& filename = imagelist[i * 2 + k];
			cv::Mat img = cv::imread(filename, 0);
			if (img.empty())
				break;
			if (imageSize == cv::Size())
				imageSize = img.size();
			else if (img.size() != imageSize)
			{
				m_entity->setStatusBarText(QString::fromStdString(filename) + "与第一张图片尺寸不同,跳过.");
				break;
			}
			bool found = false;
			std::vector<cv::Point2f>& corners = imagePoints[k][j];
			for (int scale = 1; scale <= maxScale; scale++)
			{
				cv::Mat timg;
				if (scale == 1)
					timg = img;
				else
					resize(img, timg, cv::Size(), scale, scale, cv::INTER_LINEAR_EXACT);
				found = findChessboardCorners(timg, boardSize, corners,
				                              cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_NORMALIZE_IMAGE);

				if (found)
				{
					if (scale > 1)
					{
						cv::Mat cornersMat(corners);
						cornersMat *= 1. / scale;
					}
					break;
				}
			}
			if (displayCorners)
			{
				std::cout << filename << std::endl;
				cv::Mat cimg, cimg1;
				cvtColor(img, cimg, cv::COLOR_GRAY2BGR);
				drawChessboardCorners(cimg, boardSize, corners, found);
				double sf = 640. / MAX(img.rows, img.cols);
				resize(cimg, cimg1, cv::Size(), sf, sf, cv::INTER_LINEAR_EXACT);
				imshow("corners", cimg1);
				char c = (char)cv::waitKey(500);
				if (c == 27 || c == 'q' || c == 'Q') //Allow ESC to quit
					exit(-1);
			}
			else
				putchar('.');
			if (!found)
				break;
			cornerSubPix(img, corners, cv::Size(11, 11), cv::Size(-1, -1),
			             cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS,
					30, 0.01));
		}
		if (k == 2)
		{
			goodImageList.push_back(imagelist[i * 2]);
			goodImageList.push_back(imagelist[i * 2 + 1]);
			j++;
		}
	}
	std::cout << j << " pairs have been successfully detected.\n";
	nimages = j;
	if (nimages < 2)
	{
		std::cout << "Error: too little pairs to run the calibration\n";
		return;
	}

	imagePoints[0].resize(nimages);
	imagePoints[1].resize(nimages);
	objectPoints.resize(nimages);

	for (i = 0; i < nimages; i++)
	{
		for (j = 0; j < boardSize.height; j++)
			for (k = 0; k < boardSize.width; k++)
				objectPoints[i].push_back(cv::Point3f(k*squareSize, j*squareSize, 0));
	}

	std::cout << "Running stereo calibration ...\n";

	cv::Mat cameraMatrix[2], distCoeffs[2];
	cameraMatrix[0] = initCameraMatrix2D(objectPoints, imagePoints[0], imageSize, 0);
	cameraMatrix[1] = initCameraMatrix2D(objectPoints, imagePoints[1], imageSize, 0);
	cv::Mat R, T, E, F;

	double rms = stereoCalibrate(objectPoints, imagePoints[0], imagePoints[1],
		cameraMatrix[0], distCoeffs[0],
		cameraMatrix[1], distCoeffs[1],
		imageSize, R, T, E, F,
	                             cv::CALIB_FIX_ASPECT_RATIO +
	                             cv::CALIB_ZERO_TANGENT_DIST +
	                             cv::CALIB_USE_INTRINSIC_GUESS +
	                             cv::CALIB_SAME_FOCAL_LENGTH +
	                             cv::CALIB_RATIONAL_MODEL +
	                             cv::CALIB_FIX_K3 + cv::CALIB_FIX_K4 + cv::CALIB_FIX_K5,
	                             cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 100, 1e-5));
	std::cout << "done with RMS error=" << rms << std::endl;

	// CALIBRATION QUALITY CHECK
	// because the output fundamental matrix implicitly
	// includes all the output information,
	// we can check the quality of calibration using the
	// epipolar geometry constraint: m2^t*F*m1=0
	double err = 0;
	int npoints = 0;
	std::vector<cv::Vec3f> lines[2];
	for (i = 0; i < nimages; i++)
	{
		int npt = (int)imagePoints[0][i].size();
		cv::Mat imgpt[2];
		for (k = 0; k < 2; k++)
		{
			imgpt[k] = cv::Mat(imagePoints[k][i]);
			undistortPoints(imgpt[k], imgpt[k], cameraMatrix[k], distCoeffs[k], cv::Mat(), cameraMatrix[k]);
			computeCorrespondEpilines(imgpt[k], k + 1, F, lines[k]);
		}
		for (j = 0; j < npt; j++)
		{
			double errij = fabs(imagePoints[0][i][j].x*lines[1][j][0] +
				imagePoints[0][i][j].y*lines[1][j][1] + lines[1][j][2]) +
				fabs(imagePoints[1][i][j].x*lines[0][j][0] +
					imagePoints[1][i][j].y*lines[0][j][1] + lines[0][j][2]);
			err += errij;
		}
		npoints += npt;
	}
	std::cout << "average epipolar err = " << err / npoints << std::endl;

	// save intrinsic parameters
	cv::FileStorage fs("intrinsics.yml", cv::FileStorage::WRITE);
	if (fs.isOpened())
	{
		fs << "M1" << cameraMatrix[0] << "D1" << distCoeffs[0] <<
			"M2" << cameraMatrix[1] << "D2" << distCoeffs[1];
		fs.release();
	}
	else
		std::cout << "Error: can not save the intrinsic parameters\n";

	cv::Mat R1, R2, P1, P2, Q;
	cv::Rect validRoi[2];

	stereoRectify(cameraMatrix[0], distCoeffs[0],
		cameraMatrix[1], distCoeffs[1],
		imageSize, R, T, R1, R2, P1, P2, Q,
	              cv::CALIB_ZERO_DISPARITY, 1, imageSize, &validRoi[0], &validRoi[1]);

	fs.open("extrinsics.yml", cv::FileStorage::WRITE);
	if (fs.isOpened())
	{
		fs << "R" << R << "T" << T << "R1" << R1 << "R2" << R2 << "P1" << P1 << "P2" << P2 << "Q" << Q;
		fs.release();
	}
	else
		std::cout << "Error: can not save the extrinsic parameters\n";

	// OpenCV can handle left-right
	// or up-down camera arrangements
	bool isVerticalStereo = fabs(P2.at<double>(1, 3)) > fabs(P2.at<double>(0, 3));

	// COMPUTE AND DISPLAY RECTIFICATION
	if (!showRectified)
		return;

	cv::Mat rmap[2][2];
	// IF BY CALIBRATED (BOUGUET'S METHOD)
	if (useCalibrated)
	{
		// we already computed everything
	}
	// OR ELSE HARTLEY'S METHOD
	else
		// use intrinsic parameters of each camera, but
		// compute the rectification transformation directly
		// from the fundamental matrix
	{
		std::vector<cv::Point2f> allimgpt[2];
		for (k = 0; k < 2; k++)
		{
			for (i = 0; i < nimages; i++)
				std::copy(imagePoints[k][i].begin(), imagePoints[k][i].end(), back_inserter(allimgpt[k]));
		}
		F = cv::findFundamentalMat(cv::Mat(allimgpt[0]), cv::Mat(allimgpt[1]), cv::FM_8POINT, 0, 0);
		cv::Mat H1, H2;
		stereoRectifyUncalibrated(cv::Mat(allimgpt[0]), cv::Mat(allimgpt[1]), F, imageSize, H1, H2, 3);

		R1 = cameraMatrix[0].inv()*H1*cameraMatrix[0];
		R2 = cameraMatrix[1].inv()*H2*cameraMatrix[1];
		P1 = cameraMatrix[0];
		P2 = cameraMatrix[1];
	}

	//Precompute maps for cv::remap()
	initUndistortRectifyMap(cameraMatrix[0], distCoeffs[0], R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);
	initUndistortRectifyMap(cameraMatrix[1], distCoeffs[1], R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);

	cv::Mat canvas;
	double sf;
	int w, h;
	if (!isVerticalStereo)
	{
		sf = 600. / MAX(imageSize.width, imageSize.height);
		w = cvRound(imageSize.width*sf);
		h = cvRound(imageSize.height*sf);
		canvas.create(h, w * 2, CV_8UC3);
	}
	else
	{
		sf = 300. / MAX(imageSize.width, imageSize.height);
		w = cvRound(imageSize.width*sf);
		h = cvRound(imageSize.height*sf);
		canvas.create(h * 2, w, CV_8UC3);
	}

	for (i = 0; i < nimages; i++)
	{
		for (k = 0; k < 2; k++)
		{
			cv::Mat img = cv::imread(goodImageList[i * 2 + k], 0), rimg, cimg;
			remap(img, rimg, rmap[k][0], rmap[k][1], cv::INTER_LINEAR);
			cvtColor(rimg, cimg, cv::COLOR_GRAY2BGR);
			cv::Mat canvasPart = !isVerticalStereo ? canvas(cv::Rect(w*k, 0, w, h)) : canvas(cv::Rect(0, h*k, w, h));
			resize(cimg, canvasPart, canvasPart.size(), 0, 0, cv::INTER_AREA);
			if (useCalibrated)
			{
				cv::Rect vroi(cvRound(validRoi[k].x*sf), cvRound(validRoi[k].y*sf),
					cvRound(validRoi[k].width*sf), cvRound(validRoi[k].height*sf));
				rectangle(canvasPart, vroi, cv::Scalar(0, 0, 255), 3, 8);
			}
		}

		if (!isVerticalStereo)
			for (j = 0; j < canvas.rows; j += 16)
				line(canvas, cv::Point(0, j), cv::Point(canvas.cols, j), cv::Scalar(0, 255, 0), 1, 8);
		else
			for (j = 0; j < canvas.cols; j += 16)
				line(canvas, cv::Point(j, 0), cv::Point(j, canvas.rows), cv::Scalar(0, 255, 0), 1, 8);
		imshow("rectified", canvas);
		char c = (char)cv::waitKey();
		if (c == 27 || c == 'q' || c == 'Q')
			break;
	}
}
