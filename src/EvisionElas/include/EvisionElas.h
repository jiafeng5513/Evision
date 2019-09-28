#pragma once
#include <opencv2\opencv.hpp>
#include "elas.h"

//interface to Original libelas,debug only!
int __declspec(dllexport)ElasMatch();
//warpped with opencv
int __declspec(dllexport)ElasMatch(Elas::parameters param, cv::Mat leftImg, cv::Mat rightImg, cv::Mat *disp_raw, cv::Mat* disp_show);