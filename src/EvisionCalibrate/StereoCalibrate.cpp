#include "StereoCalibrate.h"
#include <QMessageBox>
#include "QFileDialog"
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include "EvisionUtils.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QPixmap>


StereoCalibrate::StereoCalibrate(std::vector<std::string>* imagelistL, std::vector<std::string>* imagelistR, QObject * parent)
{
	m_entity = CalibrateParamEntity::getInstance();
	this->imagelistL = imagelistL;
	this->imagelistR = imagelistR;

	QFileInfo *_fileInfo = new QFileInfo(QString::fromStdString(imagelistL->at(0)));
	this->cameraParamsFilename = _fileInfo->absolutePath().toStdString().append("/cameraParams.yml");
}

StereoCalibrate::~StereoCalibrate()
{

}
/*
 * 线程方法
 */
void StereoCalibrate::run()
{
	ready_to_save = false;
	if (imagelistL->size()!= imagelistR->size())//图片不成对
	{
		emit openMessageBox(QStringLiteral("错误"), QStringLiteral("图片不成对!"));
		return;
	}

	try
	{
		cv::Size boardSize(m_entity->getBoardWidth(), m_entity->getBoardHeight());
		float squareSize = m_entity->getSquareSize();
		int flags_1D = getCalibrate1D_flags();
		int flags_2D = getCalibrate2D_flags();


		bool showRectified = true;
		float  aspectRatio = 1;
		Pattern pattern = CHESSBOARD;
		bool showUndistorted = true;


		std::vector<std::string> *imagelist_double=new std::vector<std::string>();
		for (int i = 0; i < imagelistL->size(); ++i)
		{
			imagelist_double->push_back(imagelistL->at(i));
			imagelist_double->push_back(imagelistR->at(i));
		}

		std::cout << "标定左相机" << std::endl;
		Calib1D(boardSize, squareSize, *imagelistL, cameraMatrix_L, distCoeffs_L, aspectRatio, pattern, flags_1D, showUndistorted);
		std::cout << "标定右相机" << std::endl;
		Calib1D(boardSize, squareSize, *imagelistR, cameraMatrix_R, distCoeffs_R, aspectRatio, pattern, flags_1D, showUndistorted);
		std::cout << "标定双目系统" << std::endl;
		StereoCalib(*imagelist_double, boardSize, squareSize, cameraMatrix_L, distCoeffs_L, cameraMatrix_R, distCoeffs_R,
			R, T, E, F, R1, P1, R2, P2, Q, roi1, roi2, flags_2D, false, true, showRectified);
		ready_to_save = true;
	}
	catch (std::exception e)
	{
		std::cout << "标定出现严重错误!" <<e.what() << std::endl;

	}
}
/*
 * 把标定产生的参数保存到文件
 */
bool StereoCalibrate::SaveCameraParamsToFile()
{
	if (ready_to_save==false)
	{
		std::cout << "没有准备好保存参数!" << std::endl;
		return false;
	}
	else
	{
		// 保存参数
		bool flag = EvisionUtils::write_AllCameraParams(cameraParamsFilename, cameraMatrix_L, distCoeffs_L,
			cameraMatrix_R, distCoeffs_R, R, T, imageSize, R1, P1, R2, P2, Q, roi1, roi2);
		std::cout << "参数已经保存到:" << cameraParamsFilename << std::endl;
		if (!flag)
		{
			emit openMessageBox(QStringLiteral("文件访问错误"), QStringLiteral("无法写入:cameraParams.yml"));
			return false;
		}
	}
	return true;
}

/*
 * 计算重投影误差
 */
double StereoCalibrate::computeReprojectionErrors(const std::vector<std::vector<cv::Point3f>>& objectPoints,
	const std::vector<std::vector<cv::Point2f>>& imagePoints, const std::vector<cv::Mat>& rvecs,
	const std::vector<cv::Mat>& tvecs, const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs,
	std::vector<float>& perViewErrors)
{
	std::vector<cv::Point2f> imagePoints2;
	int i, totalPoints = 0;
	double totalErr = 0, err;
	perViewErrors.resize(objectPoints.size());

	for (i = 0; i < (int)objectPoints.size(); i++)
	{
		projectPoints(cv::Mat(objectPoints[i]), rvecs[i], tvecs[i],
			cameraMatrix, distCoeffs, imagePoints2);
		err = norm(cv::Mat(imagePoints[i]), cv::Mat(imagePoints2), cv::NORM_L2);
		int n = (int)objectPoints[i].size();
		perViewErrors[i] = (float)std::sqrt(err*err / n);
		totalErr += err * err;
		totalPoints += n;
	}

	return std::sqrt(totalErr / totalPoints);
}
/*
 * 初始化标定板corners
 */
void StereoCalibrate::calcChessboardCorners(cv::Size boardSize, float squareSize, std::vector<cv::Point3f>& corners,
	Pattern patternType)
{
	corners.resize(0);

	switch (patternType)
	{
	case CHESSBOARD:
	case CIRCLES_GRID:
		for (int i = 0; i < boardSize.height; i++)
			for (int j = 0; j < boardSize.width; j++)
				corners.push_back(cv::Point3f(float(j*squareSize),
					float(i*squareSize), 0));
		break;

	case ASYMMETRIC_CIRCLES_GRID:
		for (int i = 0; i < boardSize.height; i++)
			for (int j = 0; j < boardSize.width; j++)
				corners.push_back(cv::Point3f(float((2 * j + i % 2)*squareSize),
					float(i*squareSize), 0));
		break;

	default:
		CV_Error(cv::Error::StsBadArg, "Unknown pattern type\n");
	}
}
/*
 * 单目标定的核心代码
 */
bool StereoCalibrate::calibrate_1D_core(const std::vector<std::vector<cv::Point2f>>& imagePoints, cv::Size imageSize,
	cv::Size boardSize, float squareSize, float aspectRatio, int flags, cv::Mat& cameraMatrix, cv::Mat& distCoeffs)
{
	std::vector<cv::Mat> rvecs, tvecs;
	std::vector<float> reprojErrs;


	cameraMatrix = cv::Mat::eye(3, 3, CV_64F);
	if (flags & cv::CALIB_FIX_ASPECT_RATIO)
		cameraMatrix.at<double>(0, 0) = aspectRatio;

	distCoeffs = cv::Mat::zeros(8, 1, CV_64F);

	std::vector<std::vector<cv::Point3f> > objectPoints(1);
	calcChessboardCorners(boardSize, squareSize, objectPoints[0]);

	objectPoints.resize(imagePoints.size(), objectPoints[0]);

	double rms = calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix,
		distCoeffs, rvecs, tvecs, flags);// cv::CALIB_FIX_K3 |
	printf("RMS error reported by calibrateCamera: %g\n", rms);

	bool ok = checkRange(cameraMatrix) && checkRange(distCoeffs);

	double totalAvgErr = computeReprojectionErrors(objectPoints, imagePoints,
		rvecs, tvecs, cameraMatrix, distCoeffs, reprojErrs);

	printf("%s. avg reprojection error = %.2f\n", ok ? "Calibration succeeded" : "Calibration failed", totalAvgErr);

	return ok;
}
/*
 * 单目标定的驱动代码
 *	cv::Size		[in]	boardSize				标定板尺寸
	float			[in]	squareSize				方格尺寸
	vector<string>	[in]	imageList				标定图片文件名
	Mat&			[io]	cameraMatrix			相机矩阵
	Mat&			[io]	distCoeffs				畸变系数
	float			[in]	aspectRatio=1			宽高比,只有当flag中指定CALIB_FIX_ASPECT_RATIO时才起作用
	Pattern			[in]	pattern=CHESSBOARD		标定板模式,可选:
														CHESSBOARD				象棋盘,
														CIRCLES_GRID			圆点阵列,
														ASYMMETRIC_CIRCLES_GRID	非对称圆点阵列
	int				[in]	flags=0					标定标志位,可选
														CALIB_FIX_ASPECT_RATIO	固定宽高比
														CALIB_ZERO_TANGENT_DIST
														CALIB_FIX_PRINCIPAL_POINT
	bool			[in]	showUndistorted=true	是否显示矫正之后的情况
 */
void StereoCalibrate::Calib1D(cv::Size boardSize, float squareSize, std::vector<std::string> imageList,
	cv::Mat& cameraMatrix, cv::Mat& distCoeffs, float aspectRatio, Pattern pattern, int flags, bool showUndistorted)
{
	try
	{
		//cv::Size imageSize;//改成成员变量
		std::vector<std::vector<cv::Point2f> > imagePoints;
		int nframes = (int)imageList.size();
		//cv::namedWindow("Image View", 1);



		for (int i = 0;; i++)
		{
			cv::Mat view, viewGray;
			if (i < (int)imageList.size())
				view = cv::imread(imageList[i], 1);

			if (view.empty())//数据读完了,开始标定
			{
				if (imagePoints.size() > 0)
					std::cout << "数据读完了,开始标定" << std::endl;
					calibrate_1D_core(imagePoints, imageSize, boardSize, squareSize, aspectRatio, flags, cameraMatrix, distCoeffs);
				break;
			}

			imageSize = view.size();

			std::vector<cv::Point2f> pointbuf;
			cvtColor(view, viewGray, cv::COLOR_BGR2GRAY);

			bool found;
			switch (pattern)
			{
			case CHESSBOARD:
				found = findChessboardCorners(view, boardSize, pointbuf,
					cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_FAST_CHECK | cv::CALIB_CB_NORMALIZE_IMAGE);
				break;
			case CIRCLES_GRID:
				found = findCirclesGrid(view, boardSize, pointbuf);
				break;
			case ASYMMETRIC_CIRCLES_GRID:
				found = findCirclesGrid(view, boardSize, pointbuf, cv::CALIB_CB_ASYMMETRIC_GRID);
				break;
			default:
				return;
			}

			// improve the found corners' coordinate accuracy
			if (pattern == CHESSBOARD && found)
				cv::cornerSubPix(viewGray, pointbuf, cv::Size(11, 11), cv::Size(-1, -1),
					cv::TermCriteria(cv::TermCriteria::EPS + cv::TermCriteria::COUNT, 30, 0.1));

			if (found)
			{
				imagePoints.push_back(pointbuf);
			}

			if (found)
				drawChessboardCorners(view, boardSize, cv::Mat(pointbuf), found);

			std::string msg = "100/100";
			int baseLine = 0;
			cv::Size textSize = cv::getTextSize(msg, 1, 1, 1, &baseLine);
			cv::Point textOrigin(view.cols - 2 * textSize.width - 10, view.rows - 2 * baseLine - 10);


			msg = cv::format("%d/%d", (int)imagePoints.size(), nframes);

			putText(view, msg, textOrigin, 1, 1, cv::Scalar(0, 0, 255));

			m_entity->insertItem(view);
		}

		if (showUndistorted)
		{
			cv::Mat view, rview, map1, map2;
			cv::initUndistortRectifyMap(cameraMatrix, distCoeffs, cv::Mat(),
				getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
				imageSize, CV_16SC2, map1, map2);

			for (int i = 0; i < (int)imageList.size(); i++)
			{
				view = cv::imread(imageList[i], 1);
				if (view.empty())
					continue;
				remap(view, rview, map1, map2, cv::INTER_LINEAR);
				m_entity->insertItem(rview);
			}
			std::cout << "第一次矫正成功完成" << std::endl;
		}
	}
	catch (std::exception e)
	{
		std::cout << "Calib1D出现严重错误" << e.what() << std::endl;
	}
}
/*
 * 双目标定
 */
void StereoCalibrate::StereoCalib(
	const std::vector<std::string>& imagelist,
	cv::Size boardSize,
	float squareSize,
	cv::Mat& cameraMatrix_L, cv::Mat& distCoeffs_L,
	cv::Mat& cameraMatrix_R, cv::Mat& distCoeffs_R,
	cv::Mat& R, cv::Mat& T, cv::Mat& E, cv::Mat&F, cv::Mat& R1, cv::Mat& P1, cv::Mat&R2, cv::Mat&P2, cv::Mat&Q,
	cv::Rect &roi1, cv::Rect &roi2,
	int flags,
	bool displayCorners, bool useCalibrated, bool showRectified)
{
	try
	{


		if (imagelist.size() % 2 != 0)
		{
			std::cout << "Error: the image list contains odd (non-even) number of elements\n";
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
					std::cout << "The image " << filename << " has the size different from the first image size. Skipping the pair\n";
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
					found = findChessboardCorners(timg, boardSize, corners, cv::CALIB_CB_ADAPTIVE_THRESH | cv::CALIB_CB_NORMALIZE_IMAGE);
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
					cv::imshow("corners", cimg1);
					char c = (char)cv::waitKey(500);
					if (c == 27 || c == 'q' || c == 'Q') //Allow ESC to quit
						exit(-1);
				}
				else
					putchar('.');
				if (!found)
					break;
				cv::cornerSubPix(img, corners, cv::Size(11, 11), cv::Size(-1, -1),
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

		//Mat cameraMatrix[2], distCoeffs[2];
		//cameraMatrix[0] = initCameraMatrix2D(objectPoints, imagePoints[0], imageSize, 0);
		//cameraMatrix[1] = initCameraMatrix2D(objectPoints, imagePoints[1], imageSize, 0);

		/*
		 *CALIB_FIX_ASPECT_RATIO
		 *CALIB_ZERO_TANGENT_DIST
		 *CALIB_USE_INTRINSIC_GUESS
		 *CALIB_SAME_FOCAL_LENGTH
		 *CALIB_RATIONAL_MODEL
		 *CALIB_FIX_INTRINSIC
		 *CALIB_FIX_K3
		 *CALIB_FIX_K4
		 *CALIB_FIX_K5
		 */
		double rms = stereoCalibrate(objectPoints, imagePoints[0], imagePoints[1],
			cameraMatrix_L, distCoeffs_L,
			cameraMatrix_R, distCoeffs_R,
			imageSize, R, T, E, F,
			flags,
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

			imgpt[0] = cv::Mat(imagePoints[0][i]);
			undistortPoints(imgpt[0], imgpt[0], cameraMatrix_L, distCoeffs_L, cv::Mat(), cameraMatrix_L);
			computeCorrespondEpilines(imgpt[0], 0 + 1, F, lines[0]);

			imgpt[1] = cv::Mat(imagePoints[1][i]);
			undistortPoints(imgpt[1], imgpt[1], cameraMatrix_R, distCoeffs_R, cv::Mat(), cameraMatrix_R);
			computeCorrespondEpilines(imgpt[1], 1 + 1, F, lines[1]);

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
		//cv::FileStorage fs("intrinsics.yml", cv::FileStorage::WRITE);
		//if (fs.isOpened())
		//{
		//	fs << "M1" << cameraMatrix_L << "D1" << distCoeffs_L <<
		//		"M2" << cameraMatrix_R << "D2" << distCoeffs_R;
		//	fs.release();
		//}
		//else
		//	std::cout << "Error: can not save the intrinsic parameters\n";

		cv::Rect validRoi[2];
		cv::Size tempsize(0, 0);
		cv::stereoRectify(cameraMatrix_L, distCoeffs_L,
			cameraMatrix_R, distCoeffs_R,
			imageSize, R, T, R1, R2, P1, P2, Q,
			0, 1, tempsize, &validRoi[0], &validRoi[1]);

		//fs.open("extrinsics.yml", cv::FileStorage::WRITE);
		//if (fs.isOpened())
		//{
		//	fs << "R" << R << "T" << T << "R1" << R1 << "R2" << R2 << "P1" << P1 << "P2" << P2 << "Q" << Q;
		//	fs.release();
		//}
		//else
		//	std::cout << "Error: can not save the extrinsic parameters\n";

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
			F = findFundamentalMat(cv::Mat(allimgpt[0]), cv::Mat(allimgpt[1]), cv::FM_8POINT, 0, 0);
			cv::Mat H1, H2;
			stereoRectifyUncalibrated(cv::Mat(allimgpt[0]), cv::Mat(allimgpt[1]), F, imageSize, H1, H2, 3);

			R1 = cameraMatrix_L.inv()*H1*cameraMatrix_L;
			R2 = cameraMatrix_R.inv()*H2*cameraMatrix_R;
			P1 = cameraMatrix_L;
			P2 = cameraMatrix_R;
		}

		//Precompute maps for cv::remap()
		cv::initUndistortRectifyMap(cameraMatrix_L, distCoeffs_L, R1, P1, imageSize, CV_16SC2, rmap[0][0], rmap[0][1]);
		cv::initUndistortRectifyMap(cameraMatrix_R, distCoeffs_R, R2, P2, imageSize, CV_16SC2, rmap[1][0], rmap[1][1]);

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
			//cv::imshow("rectified", canvas);
			m_entity->insertItem(canvas);
			//char c = (char)cv::waitKey();
			//if (c == 27 || c == 'q' || c == 'Q')
				//break;
		}
		roi1 = validRoi[0];
		roi2 = validRoi[1];
	}
	catch (std::exception e)
	{
		std::cout << "StereoCalib出现严重错误" << e.what() << std::endl;
	}
}
/*
 * 获取单目标定的flags
 */
int StereoCalibrate::getCalibrate1D_flags()
{
	int flag = 0;
	if (m_entity->getCALIB_FIX_PRINCIPAL_POINT())
	{
		flag |= cv::CALIB_FIX_PRINCIPAL_POINT;
	}
	if (m_entity->getCALIB_FIX_ASPECT_RATIO())
	{
		flag |= cv::CALIB_FIX_ASPECT_RATIO;
	}
	if (m_entity->getCALIB_ZERO_TANGENT_DIST())
	{
		flag |= cv::CALIB_ZERO_TANGENT_DIST;
	}

	if (m_entity->getCALIB_FIX_K1())
	{
		flag |= cv::CALIB_FIX_K1;
	}
	if (m_entity->getCALIB_FIX_K2())
	{
		flag |= cv::CALIB_FIX_K2;
	}
	if (m_entity->getCALIB_FIX_K3())
	{
		flag |= cv::CALIB_FIX_K3;
	}
	if (m_entity->getCALIB_FIX_K4())
	{
		flag |= cv::CALIB_FIX_K4;
	}
	if (m_entity->getCALIB_FIX_K5())
	{
		flag |= cv::CALIB_FIX_K5;
	}
	if (m_entity->getCALIB_FIX_K6())
	{
		flag |= cv::CALIB_FIX_K6;
	}
	if(m_entity->getCALIB_RATIONAL_MODEL())
	{
		flag |= cv::CALIB_RATIONAL_MODEL;
	}
	if (m_entity->getCALIB_THIN_PRISM_MODEL())
	{
		flag |= cv::CALIB_THIN_PRISM_MODEL;
	}
	if (m_entity->getCALIB_FIX_S1_S2_S3_S4())
	{
		flag |= cv::CALIB_FIX_S1_S2_S3_S4;
	}
	if (m_entity->getCALIB_TILTED_MODEL())
	{
		flag |= cv::CALIB_TILTED_MODEL;
	}
	if (m_entity->getCALIB_FIX_TAUX_TAUY())
	{
		flag |= cv::CALIB_FIX_TAUX_TAUY;
	}
	return flag;
}
/*
 * 获取立体标定的flags
 */
int StereoCalibrate::getCalibrate2D_flags()
{
	int flag = 0|cv::CALIB_FIX_INTRINSIC;
	if (m_entity->getCALIB_SAME_FOCAL_LENGTH())
	{
		flag |= cv::CALIB_SAME_FOCAL_LENGTH;
	}
	if (m_entity->getCALIB_FIX_K1())
	{
		flag |= cv::CALIB_FIX_K1;
	}
	if (m_entity->getCALIB_FIX_K2())
	{
		flag |= cv::CALIB_FIX_K2;
	}
	if (m_entity->getCALIB_FIX_K3())
	{
		flag |= cv::CALIB_FIX_K3;
	}
	if (m_entity->getCALIB_FIX_K4())
	{
		flag |= cv::CALIB_FIX_K4;
	}
	if (m_entity->getCALIB_FIX_K5())
	{
		flag |= cv::CALIB_FIX_K5;
	}
	if (m_entity->getCALIB_FIX_K6())
	{
		flag |= cv::CALIB_FIX_K6;
	}
	if (m_entity->getCALIB_RATIONAL_MODEL())
	{
		flag |= cv::CALIB_RATIONAL_MODEL;
	}
	if (m_entity->getCALIB_THIN_PRISM_MODEL())
	{
		flag |= cv::CALIB_THIN_PRISM_MODEL;
	}
	if (m_entity->getCALIB_FIX_S1_S2_S3_S4())
	{
		flag |= cv::CALIB_FIX_S1_S2_S3_S4;
	}
	if (m_entity->getCALIB_TILTED_MODEL())
	{
		flag |= cv::CALIB_TILTED_MODEL;
	}
	if (m_entity->getCALIB_FIX_TAUX_TAUY())
	{
		flag |= cv::CALIB_FIX_TAUX_TAUY;
	}
	return flag;
}
