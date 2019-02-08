#include "StereoCalibrate.h"
#include <QMessageBox>
#include "QFileDialog"
#include <imgcodecs/imgcodecs_c.h>
#include <imgproc.hpp>
#include <highgui.hpp>
#include <iostream>
#include <calib3d/calib3d.hpp>
#include "EvisionUtils.h"



StereoCalibrate::StereoCalibrate(std::vector<std::string>* imagelistL, std::vector<std::string>* imagelistR, cv::Size boardSize, float squareSize, bool useCalibrated, bool showRectified, QObject * parent)
{
	m_entity = CalibrateParamEntity::getInstance();
	this->imagelistL = imagelistL;
	this->imagelistR = imagelistR;
	this->boardSize = boardSize;
	this->squareSize = squareSize;
	this->useCalibrated = useCalibrated;
	this->showRectified = showRectified;

	QFileInfo *_fileInfo = new QFileInfo(QString::fromStdString(imagelistL->at(0)));
	this->cameraParamsFilename = _fileInfo->absolutePath().toStdString().append("/cameraParams.yml");
}

StereoCalibrate::~StereoCalibrate()
{

}

void StereoCalibrate::run_old()
{
	if (imagelist->size() % 2 != 0)//图片不成对
	{
		QMessageBox::information(NULL, QStringLiteral("错误"), QStringLiteral("图片不成对!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		return;
	}

	const int maxScale = 2;
	// ARRAY AND VECTOR STORAGE:

	std::vector<std::vector<cv::Point2f> > imagePoints[2];
	std::vector<std::vector<cv::Point3f> > objectPoints;
	cv::Size imageSize;

	int i, j, k, nimages = (int)imagelist->size() / 2;

	imagePoints[0].resize(nimages);
	imagePoints[1].resize(nimages);
	std::vector<std::string> goodImageList;
	//寻找交点,把能够找到交点的那些图片过滤出来用来标定
	for (i = j = 0; i < nimages; i++)
	{
		for (k = 0; k < 2; k++)
		{
			const std::string& filename = imagelist->at(i * 2 + k);
			cv::Mat img = cv::imread(filename, 0);
			if (img.empty())
				break;
			if (imageSize == cv::Size())
				imageSize = img.size();
			else if (img.size() != imageSize)
			{
				//m_entity->setmsgBuffer(QString::fromStdString(filename) + "与第一张图片尺寸不同,跳过.");
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
			//显示交点
			std::cout << filename << std::endl;
			cv::Mat cimg, cimg1;
			cvtColor(img, cimg, cv::COLOR_GRAY2BGR);
			drawChessboardCorners(cimg, boardSize, corners, found);
			double sf = 640. / MAX(img.rows, img.cols);
			resize(cimg, cimg1, cv::Size(), sf, sf, cv::INTER_LINEAR_EXACT);
			if (k==0)
			{
				m_entity->setImageLtoShow(cimg1);
			}
			else
			{
				m_entity->setImageRtoShow(cimg1);

			}

			if (!found)
				break;
			cornerSubPix(img, corners, cv::Size(11, 11), cv::Size(-1, -1),
				cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS,
					30, 0.01));
		}
		if (k == 2)
		{
			goodImageList.push_back(imagelist->at(i * 2));
			goodImageList.push_back(imagelist->at(i * 2 + 1));
			j++;
		}
	}//交点检测结束

	nimages = j;//只有找到交点的图片能用来标定,确定数量
	if (nimages < 2)
	{
		//std::cout << "Error: too little pairs to run the calibration\n";
		emit openMessageBox(QStringLiteral("错误"), QStringLiteral("可用图片太少,请选择足够的标定图片!"));
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
	//标定
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
	std::string tmp="RMS error = \n";
	tmp += std::to_string(rms);
	emit openMessageBox(QStringLiteral("标定完毕"), QString::fromStdString(tmp));
	// CALIBRATION QUALITY CHECK
	// because the output fundamental matrix implicitly
	// includes all the output information,
	// we can check the quality of calibration using the
	// epipolar geometry constraint: m2^t*F*m1=0
	/*用极线约束检查标定质量*/
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
	tmp = "average epipolar err = \n";
	tmp += std::to_string(err / npoints);
	emit openMessageBox(QStringLiteral("平均极线误差"), QString::fromStdString(tmp));

	// 保存内部参数
	cv::FileStorage fs("intrinsics.yml", cv::FileStorage::WRITE);
	if (fs.isOpened())
	{
		fs << "M1" << cameraMatrix[0] << "D1" << distCoeffs[0] <<
			"M2" << cameraMatrix[1] << "D2" << distCoeffs[1];
		fs.release();
	}
	else
		emit openMessageBox(QStringLiteral("文件访问错误"), QStringLiteral("无法写入:intrinsics.yml"));
	cv::Mat R1, R2, P1, P2, Q;
	cv::Rect validRoi[2];

	stereoRectify(cameraMatrix[0], distCoeffs[0],
		cameraMatrix[1], distCoeffs[1],
		imageSize, R, T, R1, R2, P1, P2, Q,
		cv::CALIB_ZERO_DISPARITY, 1, imageSize, &validRoi[0], &validRoi[1]);
	// 保存外部参数
	fs.open("extrinsics.yml", cv::FileStorage::WRITE);
	if (fs.isOpened())
	{
		fs << "R" << R << "T" << T << "R1" << R1 << "R2" << R2 << "P1" << P1 << "P2" << P2 << "Q" << Q;
		fs.release();
	}
	else
		emit openMessageBox(QStringLiteral("文件访问错误"), QStringLiteral("无法写入:extrinsics.yml"));
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

void StereoCalibrate::run()
{
	if (imagelistL->size()!= imagelistR->size())//图片不成对
	{
		emit openMessageBox(QStringLiteral("错误"), QStringLiteral("图片不成对!"));
		return;
	}

	const int maxScale = 2;
	// ARRAY AND VECTOR STORAGE:

	std::vector<std::vector<cv::Point2f> > imagePoints[2];
	std::vector<std::vector<cv::Point3f> > objectPoints;
	cv::Size imageSize;

	int i, j, k, nimages = (int)imagelistL->size();

	imagePoints[0].resize(nimages);
	imagePoints[1].resize(nimages);
	std::vector<std::string> goodImageList;
	//寻找交点,把能够找到交点的那些图片过滤出来用来标定
	for (i = j = 0; i < nimages; i++)
	{

		//const std::string& filename = imagelist->at(i * 2 + k);
		const std::string& filenameL = imagelistL->at(i);
		const std::string& filenameR = imagelistR->at(i);


		//cv::Mat img = cv::imread(filename, 0);
		cv::Mat imgL = cv::imread(filenameL, 0);
		cv::Mat imgR = cv::imread(filenameR, 0);

		if (imgL.empty() || imgR.empty())
			break;
		if (imageSize == cv::Size())
			imageSize = imgL.size();
		else if (imgL.size() != imageSize|| imgL.size()!=imgR.size())
		{
			//m_entity->setmsgBuffer("图片尺寸有问题,跳过");
			std::cout << "图片尺寸有问题,跳过" << std::endl;
			break;
		}
		//bool found = false;
		bool foundL = false;
		bool foundR = false;

		std::vector<cv::Point2f>& cornersL = imagePoints[0][j];
		std::vector<cv::Point2f>& cornersR = imagePoints[1][j];

		for (int scale = 1; scale <= maxScale; scale++)
		{
			cv::Mat timgL;
			if (scale == 1)
				timgL = imgL;
			else
				resize(imgL, timgL, cv::Size(), scale, scale, cv::INTER_LINEAR_EXACT);
			foundL = findChessboardCorners(timgL, boardSize, cornersL,
				cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_NORMALIZE_IMAGE);

			cv::Mat timgR;
			if (scale == 1)
				timgR = imgR;
			else
				resize(imgR, timgR, cv::Size(), scale, scale, cv::INTER_LINEAR_EXACT);
			foundR = findChessboardCorners(timgR, boardSize, cornersR,
				cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_NORMALIZE_IMAGE);

			if (foundL&&foundR)
			{
				if (scale > 1)
				{
					cv::Mat cornersMat(cornersL);
					cornersMat *= 1. / scale;
				}
				break;
			}
		}
		//显示交点
		//std::cout << filename << std::endl;
		cv::Mat cimgL, cimg1L, cimgR, cimg1R;
		cvtColor(imgL, cimgL, cv::COLOR_GRAY2BGR);
		drawChessboardCorners(cimgL, boardSize, cornersL, foundL);
		double sfL = 640. / MAX(imgL.rows, imgL.cols);
		resize(cimgL, cimg1L, cv::Size(), sfL, sfL, cv::INTER_LINEAR_EXACT);

		cvtColor(imgR, cimgR, cv::COLOR_GRAY2BGR);
		drawChessboardCorners(cimgR, boardSize, cornersR, foundR);
		double sfR = 640. / MAX(imgR.rows, imgR.cols);
		resize(cimgR, cimg1R, cv::Size(), sfR, sfR, cv::INTER_LINEAR_EXACT);
		m_entity->setImageLtoShow(cimg1L);
		m_entity->setImageRtoShow(cimg1R);


		if (!foundL || !foundR)
			break;
		cornerSubPix(imgL, cornersL, cv::Size(11, 11), cv::Size(-1, -1),
			cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS,
				30, 0.01));
		cornerSubPix(imgR, cornersR, cv::Size(11, 11), cv::Size(-1, -1),
			cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS,
				30, 0.01));


		goodImageList.push_back(imagelistL->at(i));
		goodImageList.push_back(imagelistR->at(i));
		j++;
		std::string temp = std::to_string(j);
		temp += "/"; temp += std::to_string(nimages);
		//m_entity->setmsgBuffer(QString::fromStdString(temp));
		std::cout << temp << std::endl;
	}//交点检测结束

	//std::cout << j << " pairs have been successfully detected.\n";
	//m_entity->setmsgBuffer(QStringLiteral("交点检测结束,正在标定运算..."));
	std::cout << "交点检测结束,正在标定运算..." << std::endl;
	nimages = j;//只有找到交点的图片能用来标定,确定数量
	if (nimages < 2)
	{
		emit openMessageBox(QStringLiteral("错误"), QStringLiteral("可用图片太少,请选择足够的标定图片!"));
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
	//标定
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
;
	std::cout << "RMS error = " << rms << std::endl;

	// CALIBRATION QUALITY CHECK
	// because the output fundamental matrix implicitly
	// includes all the output information,
	// we can check the quality of calibration using the
	// epipolar geometry constraint: m2^t*F*m1=0
	/*用极线约束检查标定质量*/
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

	std::cout << "平均极线误差" << "(average epipolar err) =" << std::to_string(err / npoints) <<std::endl;
	//映射计算

	cv::Mat R1, P1, R2, P2, Q;//stereoRectify的输出
	cv::Rect roi1, roi2;	  //stereoRectify的输出
	stereoRectify(cameraMatrix[0], distCoeffs[0],cameraMatrix[1], distCoeffs[1], imageSize, R, T, 
					R1, R2, P1, P2, Q, cv::CALIB_ZERO_DISPARITY, -1, imageSize, &roi1, &roi2);
	std::cout << "映射(R1,P1,R2,P2,Q)计算完毕" << std::endl;
	//计算矫正矩阵

	cv::Mat map1x, map1y, map2x, map2y;//矫正矩阵
	initUndistortRectifyMap(cameraMatrix[0], distCoeffs[0], R1, P1, imageSize, CV_16SC2, map1x, map1y);
	initUndistortRectifyMap(cameraMatrix[1], distCoeffs[1], R2, P2, imageSize, CV_16SC2, map2x, map2y);
	std::cout << "矫正矩阵(map1x, map1y, map2x, map2y)计算完毕" << std::endl;
	//至此所有的相机参数和衍生参数都计算完了

	// 保存参数
	bool flag = EvisionUtils::write_AllCameraParams(cameraParamsFilename, cameraMatrix[0], distCoeffs[0],
												cameraMatrix[1], distCoeffs[1], R, T, E, F,
												imageSize,R1,P1,R2,P2,Q,roi1,roi2);
	std::cout << "参数已经保存到:" << cameraParamsFilename << std::endl;
	if (!flag)
	{
		emit openMessageBox(QStringLiteral("文件访问错误"), QStringLiteral("无法写入:cameraParams.yml"));

	}
}
