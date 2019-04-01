#include<iostream>   
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2\opencv.hpp>
#include "elas.h"
#include "image.h"
#include "StereoEfficientLargeScale.h"

using namespace std;


/*
 * interface to Original libelas
 */
void process(const char* file_1, const char* file_2) {

	cout << "Processing: " << file_1 << ", " << file_2 << endl;

	// load images
	image<uchar> *I1, *I2;
	I1 = loadPGM(file_1);
	I2 = loadPGM(file_2);

	// check for correct size
	if (I1->width() <= 0 || I1->height() <= 0 || I2->width() <= 0 || I2->height() <= 0 ||
		I1->width() != I2->width() || I1->height() != I2->height()) {
		cout << "ERROR: Images must be of same size, but" << endl;
		cout << "       I1: " << I1->width() << " x " << I1->height() <<
			", I2: " << I2->width() << " x " << I2->height() << endl;
		delete I1;
		delete I2;
		return;
	}

	// get image width and height
	int32_t width = I1->width();
	int32_t height = I1->height();

	// allocate memory for disparity images
	const int32_t dims[3] = { width,height,width }; // bytes per line = width
	float* D1_data = (float*)malloc(width*height * sizeof(float));
	float* D2_data = (float*)malloc(width*height * sizeof(float));

	// process
	Elas::parameters param;
	param.postprocess_only_left = false;
	Elas elas(param);
	elas.process(I1->data, I2->data, D1_data, D2_data, dims);

	// find maximum disparity for scaling output disparity images to [0..255]
	float disp_max = 0;
	for (int32_t i = 0; i < width*height; i++) {
		if (D1_data[i] > disp_max) disp_max = D1_data[i];
		if (D2_data[i] > disp_max) disp_max = D2_data[i];
	}

	// copy float to uchar
	image<uchar> *D1 = new image<uchar>(width, height);
	image<uchar> *D2 = new image<uchar>(width, height);
	for (int32_t i = 0; i < width*height; i++) {
		D1->data[i] = (uint8_t)max(255.0*D1_data[i] / disp_max, 0.0);
		D2->data[i] = (uint8_t)max(255.0*D2_data[i] / disp_max, 0.0);
	}

	// save disparity images
	char output_1[1024];
	char output_2[1024];
	strncpy(output_1, file_1, strlen(file_1) - 4);
	strncpy(output_2, file_2, strlen(file_2) - 4);
	output_1[strlen(file_1) - 4] = '\0';
	output_2[strlen(file_2) - 4] = '\0';
	strcat(output_1, "_disp.pgm");
	strcat(output_2, "_disp.pgm");
	savePGM(D1, output_1);
	savePGM(D2, output_2);

	// free memory
	delete I1;
	delete I2;
	delete D1;
	delete D2;
	free(D1_data);
	free(D2_data);
}
int __declspec(dllexport)ElasMatch()
{
	process("D:/Libraries/libelas/img/im0.png", "D:/Libraries/libelas/img/im1.png");
	process("D:/Libraries/libelas/img/cones_left.pgm", "D:/Libraries/libelas/img/cones_right.pgm");
	process("D:/Libraries/libelas/img/aloe_left.pgm", "D:/Libraries/libelas/img/aloe_right.pgm");
	process("D:/Libraries/libelas/img/raindeer_left.pgm", "D:/Libraries/libelas/img/raindeer_right.pgm");
	process("D:/Libraries/libelas/img/urban1_left.pgm", "D:/Libraries/libelas/img/urban1_right.pgm");
	process("D:/Libraries/libelas/img/urban2_left.pgm", "D:/Libraries/libelas/img/urban2_right.pgm");
	process("D:/Libraries/libelas/img/urban3_left.pgm", "D:/Libraries/libelas/img/urban3_right.pgm");
	process("D:/Libraries/libelas/img/urban4_left.pgm", "D:/Libraries/libelas/img/urban4_right.pgm");

	cout << "... done!" << endl;
	return 0;
}

/*
 * warpped with opencv
 */
int __declspec(dllexport)ElasMatch(Elas::parameters param,cv::Mat leftImg,cv::Mat rightImg,cv::Mat *disp_raw,cv::Mat* disp_show)
{

	if (leftImg.data == NULL || rightImg.data == NULL) {
		return 0;
	}
	cv::Mat gradx = cv::Mat::zeros(leftImg.rows, leftImg.cols, CV_32F);
	cv::Mat grady = cv::Mat::zeros(leftImg.rows, leftImg.cols, CV_32F);
	cv::Mat mag = cv::Mat::zeros(leftImg.rows, leftImg.cols, CV_32F);
	cv::Mat img;
	cv::GaussianBlur(leftImg, img, cv::Size(3, 3), 0, 0);
	cv::Scharr(img, gradx, CV_32F, 1, 0, 1 / 32.0);
	cv::Scharr(img, grady, CV_32F, 0, 1, 1 / 32.0);
	cv::magnitude(gradx, grady, mag);
	cv::Mat ipOut;
	cv::threshold(mag, ipOut, 15, 0, cv::THRESH_TOZERO);

	StereoEfficientLargeScale * stereo_ = new StereoEfficientLargeScale(param);
	stereo_->operator ()(leftImg, rightImg, *disp_raw, 100, mag);

	//cv::Mat show;
	disp_raw->convertTo(*disp_show, CV_8U, 1.0 / 16);
	disp_show->copyTo(*disp_raw);
	/*
	 *disp_raw 原始视差数据
	 *disp_show 可视化视差数据
	 *mag
	 */

	return 0;
}

