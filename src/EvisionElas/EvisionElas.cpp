#include<iostream>   
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2\opencv.hpp>
#include "elas.h"

using namespace std;

//int ElasMatch(cv::Mat leftImage, cv::Mat rightImage);
//
//
//int main(int argc, char* argv[]) {
//
//	cout << argv[1] << argv[2] << endl;
//	cv::Mat left = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
//	cv::Mat right = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
//
//	ElasMatch(left, right);
//	cv::Mat left_disp = cv::imread("1L_disp.pgm");
//	imshow("left",left_disp);
//
//	cvWaitKey(0);
//	return 0;
//}

int __declspec(dllexport)ElasMatch(cv::Mat leftImage, cv::Mat rightImage)
{
	cv::Mat disp_l, disp_r, disp8u_l, disp8u_r;
	double minVal; double maxVal; 

	// generate disparity image using LIBELAS
	int bd = 0;
	const int32_t dims[3] = { leftImage.cols,leftImage.rows,leftImage.cols };
	cv::Mat leftdpf = cv::Mat::zeros(cv::Size(leftImage.cols, leftImage.rows), CV_32F);
	cv::Mat rightdpf = cv::Mat::zeros(cv::Size(leftImage.cols, leftImage.rows), CV_32F);
	Elas::parameters param(Elas::ROBOTICS);
	param.postprocess_only_left = false;
	Elas elas(param);
	elas.process(leftImage.data, rightImage.data, leftdpf.ptr<float>(0), rightdpf.ptr<float>(0), dims);

	cv::Mat(leftdpf(cv::Rect(bd, 0, leftImage.cols, leftImage.rows))).copyTo(disp_l);
	cv::Mat(rightdpf(cv::Rect(bd, 0, rightImage.cols, rightImage.rows))).copyTo(disp_r);

	//-- Check its extreme values
	cv::minMaxLoc(disp_l, &minVal, &maxVal);
	cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

	//-- Display it as a CV_8UC1 image
	disp_l.convertTo(disp8u_l, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)

	cv::minMaxLoc(disp_r, &minVal, &maxVal);
	cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

	//-- Display it as a CV_8UC1 image
	disp_r.convertTo(disp8u_r, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)

	cv::normalize(disp8u_l, disp8u_l, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image
	cv::normalize(disp8u_r, disp8u_r, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image

	cv::imshow("Left", leftImage);
	cv::imshow("Right", rightImage);

	cv::imshow("Elas_left", disp8u_l);
	cv::imshow("Elas_right", disp8u_r);
	//cv::imwrite("Elas_left.png", disp8u_l);
	//cv::imwrite("Elas_right.png", disp8u_r);

	cout << endl << "Over" << endl;
	cv::waitKey(0);

	return 0;
}
