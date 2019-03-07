#pragma once
#include <opencv2\opencv.hpp>
#include "elas.h"
int __declspec(dllexport)ElasMatch(cv::Mat leftImage, cv::Mat rightImage);

int __declspec(dllexport)ElasMatch(cv::Mat leftImage, cv::Mat rightImage,
	Elas::parameters param, cv::Mat * rawlr, cv::Mat * rawrl, cv::Mat * seelr, cv::Mat * seerl);