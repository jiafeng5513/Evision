#pragma once
#ifndef HTTP_STREAM_H
#define HTTP_STREAM_H
#include "darknet.h"

#ifdef OPENCV
#include "opencv2/opencv.hpp"
#endif

#ifdef __cplusplus
	extern "C" {
#endif

#include "image.h"
#include <stdint.h>

#ifdef OPENCV

	void send_json(detection *dets, int nboxes, int classes, char **names, long long int frame_id, int port, int timeout);

	void send_mjpeg(cv::Mat * ipl, int port, int timeout, int quality);

	cv::VideoCapture* get_capture_webcam(int index);

	cv::VideoCapture* get_capture_video_stream(char *path);

	cv::Mat get_webcam_frame(cv::VideoCapture*cap);

	int get_stream_fps_cpp(cv::VideoCapture*cap);

	cv::Mat image_data_augmentation(cv::Mat* mat, int w, int h, int pleft, int ptop, int swidth, int sheight, int flip, 
		float jitter, float dhue, float dsat, float dexp);

#endif  // OPENCV

#ifdef __cplusplus
	}
#endif

#endif // HTTP_STREAM_H