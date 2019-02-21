#pragma once

#include <QWidget>
#include "ui_StereoMatcherView.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <atlstr.h> // use STL string instead, although not as convenient...
#include <atltrace.h>
#define TRACE ATLTRACE

#include <iostream>
#include <fstream>
#include <string>
#include<time.h>

#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
// sift is 50 times slower but get 7 times more matched points
// FAST detect more points than SURF
// STAR/MSER generate very few keypoints,
#define DETECTOR_TYPE	"FAST" // FAST,SIFT,SURF,STAR,MSER,GFTT,HARRIS...see the create function
#define DESCRIPTOR_TYPE	"SIFT" // SURF,SIFT,BRIEF,...BRIEF seemed to has bug
#define MATCHER_TYPE	"FlannBased" // BruteForce,FlannBased,BruteForce-L1,...

#define MAXM_FILTER_TH	.8	// threshold used in GetPair
#define HOMO_FILTER_TH	60	// threshold used in GetPair
#define NEAR_FILTER_TH	40	// diff points should have distance more than NEAR_FILTER_TH
class StereoMatcherView : public QWidget
{
	Q_OBJECT

public:
	StereoMatcherView(QWidget *parent = Q_NULLPTR);
	~StereoMatcherView();

private:
	Ui::StereoMatcherView ui;
	enum Algorithm { FEATURE_PT, DENSE };

	//#define PARAM	// algorithm parameters that can be modified
	//PARAM
	Algorithm g_algo = DENSE;//DENSE; // 2 algorithms to select corresponding points and reconstruct 3D scene
private:
	bool LoadPtsPairs(std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR, std::string &filename);

	void SavePtsPairs(std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR, std::string &filename);

	void StereoTo3D(std::vector<cv::Point2f> ptsL, std::vector<cv::Point2f> ptsR, std::vector<cv::Point3f> &pts3D,
		float focalLenInPixel, float baselineInMM,
		cv::Mat img, cv::Point3f &center3D, cv::Vec3f &size3D);

	void GetPair(cv::Mat &imgL, cv::Mat &imgR, std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR);

	void GetPairBM(cv::Mat &imgL, cv::Mat &imgR, std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR);

	void CalcDisparity(cv::Mat &imgL, cv::Mat &imgR, cv::Mat_<float> &disp, int nod);

	bool isGoodTri(cv::Vec3i &v, std::vector<cv::Vec3i> & tri);

	void ChooseKeyPointsBM(cv::Mat_<float> &disp, int nod, int noe, int nof,
		std::vector<cv::Point2f> & ptsL, std::vector<cv::Point2f> & ptsR);

	void FixDisparity(cv::Mat_<float> & disp, int numberOfDisparities);
public slots:
	void onPush_SelectedLeftImg();
	void onPush_SelectedRightImg();
	void onPush_LinkStart();
};
