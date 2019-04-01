#pragma once
#include "opencv2/opencv.hpp"
#include "EvisionElas.h"

class StereoEfficientLargeScale
{
protected:
	//Elas::parameters param(Elas::MIDDLEBURY);

	int minDisparity;
	int disparityRange;

private:
	cv::Mat left_dmap_;
	cv::Mat left_img_;

public:
	Elas elas;
	StereoEfficientLargeScale(Elas::parameters param);
	void operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, cv::Mat& rightdisp, int border);
	void operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, int border);

	void operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, int border, const cv::Mat grad);
	void operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, cv::Mat& rightdisp, int border, const cv::Mat grad);

	cv::Mat GetDenseMap() { return left_dmap_.clone(); }
	cv::Mat GetImg() { return left_img_.clone(); }
	//	void check(Mat& leftim, Mat& rightim, Mat& disp, StereoEval& eval);
};

