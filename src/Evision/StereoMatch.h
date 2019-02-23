#pragma once
#include <QThread>
#include <core/matx.hpp>
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "EvisionParamEntity.h"
#include "StereoMatchParamEntity.h"


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
/*
 * 
 */
class StereoMatch :public QThread
{
	Q_OBJECT
public:
	StereoMatch(std::string img1_filename, std::string img2_filename, std::string cameraParams_filename);
	~StereoMatch();
	bool init(bool needCameraParamFile=true);
	void run() override;
	void NewMatchFunc();
	void MatchFunc();
	enum { STEREO_BM = 0, STEREO_SGBM = 1, STEREO_HH = 2, STEREO_VAR = 3, STEREO_3WAY = 4 };
	void saveXYZ(const std::string& fileName, const cv::Mat& image3D);
	void customReproject(const cv::Mat& disparity, const cv::Mat& Q, cv::Mat& out3D);
private:
	enum Algorithm { FEATURE_PT, DENSE };

	//#define PARAM	// algorithm parameters that can be modified
	//PARAM
	Algorithm g_algo = DENSE;//DENSE; // 2 algorithms to select corresponding points and reconstruct 3D scene
	StereoMatchParamEntity * m_entity;
	//即将读取的文件
	std::string img1_filename = "";
	std::string img2_filename = "";
	std::string cameraParams_filename = "";
	//用于保存的文件
	std::string disparity_filename = "";//视差图
	std::string point_cloud_filename = "";//点云文件
	//
	cv::Mat img1, img2;
	cv::Size img_size;

	cv::Mat cameraMatrix1;//左相机内参
	cv::Mat distCoeffs1;//左相机畸变系数
	cv::Mat cameraMatrix2;//右相机内参
	cv::Mat distCoeffs2;//右相机畸变系数
	cv::Mat R1, P1, R2, P2,Q;//映射计算结果
	cv::Rect roi1;
	cv::Rect roi2;


	bool no_display=false;
private:
	void getColorDisparityImage(cv::Mat& disparity, cv::Mat& disparityImage, bool isColor);
	bool LoadPtsPairs(std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR, std::string &filename);

	void SavePtsPairs(std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR, std::string &filename);

	void StereoTo3D(std::vector<cv::Point2f> ptsL, std::vector<cv::Point2f> ptsR, std::vector<cv::Point3f> &pts3D,
		float focalLenInPixel, float baselineInMM,
		cv::Mat img, cv::Point3f &center3D, cv::Vec3f &size3D);

	void GetPair(cv::Mat &imgL, cv::Mat &imgR, std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR);

	void GetPairBM(cv::Mat &imgL, cv::Mat &imgR, std::vector<cv::Point2f> &ptsL, std::vector<cv::Point2f> &ptsR);

	void CalcDisparity(cv::Mat &imgL, cv::Mat &imgR, cv::Mat_<float> &disp, int nod);

	void FixDisparity(cv::Mat_<float> & disp, int numberOfDisparities);
signals:
	void openMessageBox(QString, QString);
};