#include "StereoMatch.h"

StereoMatch::StereoMatch()
{
}


StereoMatch::~StereoMatch()
{
}


void StereoMatch::run()
{
	cv::Ptr<cv::StereoBM> bm = cv::StereoBM::create(16, 9);
	cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(0, 16, 3);

	int color_mode = alg == STEREO_BM ? 0 : -1;
	cv::Mat img1 = cv::imread(img1_filename, color_mode);
	cv::Mat img2 = cv::imread(img2_filename, color_mode);

	if (img1.empty())
	{
		printf("Command-line parameter error: could not load the first input image file\n");
		/*return -1;*/
	}
	if (img2.empty())
	{
		printf("Command-line parameter error: could not load the second input image file\n");
		//return -1;
	}

	if (scale != 1.f)
	{
		cv::Mat temp1, temp2;
		int method = scale < 1 ? cv::INTER_AREA : cv::INTER_CUBIC;
		resize(img1, temp1, cv::Size(), scale, scale, method);
		img1 = temp1;
		resize(img2, temp2, cv::Size(), scale, scale, method);
		img2 = temp2;
	}

	cv::Size img_size = img1.size();

	cv::Rect roi1, roi2;
	cv::Mat Q;

	if (!intrinsic_filename.empty())
	{
		// reading intrinsic parameters
		cv::FileStorage fs(intrinsic_filename, cv::FileStorage::READ);
		if (!fs.isOpened())
		{
			printf("Failed to open file %s\n", intrinsic_filename.c_str());
			//return -1;
		}

		cv::Mat M1, D1, M2, D2;
		fs["M1"] >> M1;
		fs["D1"] >> D1;
		fs["M2"] >> M2;
		fs["D2"] >> D2;

		M1 *= scale;
		M2 *= scale;

		fs.open(extrinsic_filename, cv::FileStorage::READ);
		if (!fs.isOpened())
		{
			printf("Failed to open file %s\n", extrinsic_filename.c_str());
			//return -1;
		}

		cv::Mat R, T, R1, P1, R2, P2;
		fs["R"] >> R;
		fs["T"] >> T;

		stereoRectify(M1, D1, M2, D2, img_size, R, T, R1, R2, P1, P2, Q, cv::CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2);

		cv::Mat map11, map12, map21, map22;
		initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
		initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);

		cv::Mat img1r, img2r;
		remap(img1, img1r, map11, map12, cv::INTER_LINEAR);
		remap(img2, img2r, map21, map22, cv::INTER_LINEAR);

		img1 = img1r;
		img2 = img2r;
	}

	numberOfDisparities = numberOfDisparities > 0 ? numberOfDisparities : ((img_size.width / 8) + 15) & -16;

	bm->setROI1(roi1);
	bm->setROI2(roi2);
	bm->setPreFilterCap(31);
	bm->setBlockSize(SADWindowSize > 0 ? SADWindowSize : 9);
	bm->setMinDisparity(0);
	bm->setNumDisparities(numberOfDisparities);
	bm->setTextureThreshold(10);
	bm->setUniquenessRatio(15);
	bm->setSpeckleWindowSize(100);
	bm->setSpeckleRange(32);
	bm->setDisp12MaxDiff(1);

	sgbm->setPreFilterCap(63);
	int sgbmWinSize = SADWindowSize > 0 ? SADWindowSize : 3;
	sgbm->setBlockSize(sgbmWinSize);

	int cn = img1.channels();

	sgbm->setP1(8 * cn*sgbmWinSize*sgbmWinSize);
	sgbm->setP2(32 * cn*sgbmWinSize*sgbmWinSize);
	sgbm->setMinDisparity(0);
	sgbm->setNumDisparities(numberOfDisparities);
	sgbm->setUniquenessRatio(10);
	sgbm->setSpeckleWindowSize(100);
	sgbm->setSpeckleRange(32);
	sgbm->setDisp12MaxDiff(1);
	if (alg == STEREO_HH)
		sgbm->setMode(cv::StereoSGBM::MODE_HH);
	else if (alg == STEREO_SGBM)
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM);
	else if (alg == STEREO_3WAY)
		sgbm->setMode(cv::StereoSGBM::MODE_SGBM_3WAY);

	cv::Mat disp, disp8;
	//Mat img1p, img2p, dispp;
	//copyMakeBorder(img1, img1p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);
	//copyMakeBorder(img2, img2p, 0, 0, numberOfDisparities, 0, IPL_BORDER_REPLICATE);

	int64 t = cv::getTickCount();
	if (alg == STEREO_BM)
		bm->compute(img1, img2, disp);
	else if (alg == STEREO_SGBM || alg == STEREO_HH || alg == STEREO_3WAY)
		sgbm->compute(img1, img2, disp);
	t = cv::getTickCount() - t;
	printf("Time elapsed: %fms\n", t * 1000 / cv::getTickFrequency());

	//disp = dispp.colRange(numberOfDisparities, img1p.cols);
	if (alg != STEREO_VAR)
		disp.convertTo(disp8, CV_8U, 255 / (numberOfDisparities*16.));
	else
		disp.convertTo(disp8, CV_8U);
	if (!no_display)
	{
		cv::namedWindow("left", 1);
		imshow("left", img1);
		cv::namedWindow("right", 1);
		imshow("right", img2);
		cv::namedWindow("disparity", 0);
		imshow("disparity", disp8);
		printf("press any key to continue...");
		fflush(stdout);
		cv::waitKey();
		printf("\n");
	}

	if (!disparity_filename.empty())
		imwrite(disparity_filename, disp8);

	if (!point_cloud_filename.empty())
	{
		printf("storing the point cloud...");
		fflush(stdout);
		cv::Mat xyz;
		reprojectImageTo3D(disp, xyz, Q, true);
		saveXYZ(point_cloud_filename.c_str(), xyz);
		printf("\n");
	}

	return ;
}

void StereoMatch::saveXYZ(const char* filename, const cv::Mat& mat)
{
	const double max_z = 1.0e4;
	FILE* fp = fopen(filename, "wt");
	for (int y = 0; y < mat.rows; y++)
	{
		for (int x = 0; x < mat.cols; x++)
		{
			cv::Vec3f point = mat.at<cv::Vec3f>(y, x);
			if (fabs(point[2] - max_z) < FLT_EPSILON || fabs(point[2]) > max_z) continue;
			fprintf(fp, "%f %f %f\n", point[0], point[1], point[2]);
		}
	}
	fclose(fp);
}
