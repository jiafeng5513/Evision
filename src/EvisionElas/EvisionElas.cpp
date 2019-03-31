#include<iostream>   
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2\opencv.hpp>
#include "elas.h"
#include "image.h"
#include "StereoEfficientLargeScale.h"

using namespace std;
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

void process2(image<uchar> *I1, image<uchar> *I2) {

	//cout << "Processing: " << file_1 << ", " << file_2 << endl;

	//// load images
	//image<uchar> *I1, *I2;
	//I1 = loadPGM(file_1);
	//I2 = loadPGM(file_2);

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
	//char output_1[1024];
	//char output_2[1024];
	//strncpy(output_1, file_1, strlen(file_1) - 4);
	//strncpy(output_2, file_2, strlen(file_2) - 4);
	//output_1[strlen(file_1) - 4] = '\0';
	//output_2[strlen(file_2) - 4] = '\0';
	//strcat(output_1, "_disp.pgm");
	//strcat(output_2, "_disp.pgm");
	savePGM(D1, "F:/disp1.pgm");
	savePGM(D2, "F:/disp2.pgm");

	// free memory
	delete I1;
	delete I2;
	delete D1;
	delete D2;
	free(D1_data);
	free(D2_data);
}

cv::Vec3b makeDepthColor(float id)
{
	if (id <= 0) return cv::Vec3b(128, 0, 0);
	if (id >= 1) return cv::Vec3b(0, 0, 128);

	int icP = (id * 8);
	float ifP = (id * 8) - icP;

	if (icP == 0) return cv::Vec3b(255 * (0.5 + 0.5*ifP), 0, 0);
	if (icP == 1) return cv::Vec3b(255, 255 * (0.5*ifP), 0);
	if (icP == 2) return cv::Vec3b(255, 255 * (0.5 + 0.5*ifP), 0);
	if (icP == 3) return cv::Vec3b(255 * (1 - 0.5*ifP), 255, 255 * (0.5*ifP));
	if (icP == 4) return cv::Vec3b(255 * (0.5 - 0.5*ifP), 255, 255 * (0.5 + 0.5*ifP));
	if (icP == 5) return cv::Vec3b(0, 255 * (1 - 0.5*ifP), 255);
	if (icP == 6) return cv::Vec3b(0, 255 * (0.5 - 0.5*ifP), 255);
	if (icP == 7) return cv::Vec3b(0, 0, 255 * (1 - 0.5*ifP));

}

void process3()
{
	cv::Mat leftImg, rightImg;


	std::stringstream leftFile_ss;
	std::stringstream rightFile_ss;
	leftFile_ss << "D:/Libraries/libelas/img/aloe_left_000.png";
	rightFile_ss << "D:/Libraries/libelas/img/aloe_right_000.png";
	//leftFile_ss<<"/home/hyj/bagfiles/stereo/new_1/left_img/"<<std::setw(6) << std::setfill('0') <<i<< ".jpg";
	//rightFile_ss<<"/home/hyj/bagfiles/stereo/new_1/right_img/"<<std::setw(6) << std::setfill('0') <<i<< ".jpg";

	std::cout << "reading image " << leftFile_ss.str() << std::endl;
	leftImg = cv::imread(leftFile_ss.str().c_str(), CV_LOAD_IMAGE_GRAYSCALE);
	rightImg = cv::imread(rightFile_ss.str().c_str(), CV_LOAD_IMAGE_GRAYSCALE);

	if (leftImg.data == NULL || rightImg.data == NULL) {
		return;
	}

	double t = (double)cvGetTickCount();

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

	cv::Mat dest;
	StereoEfficientLargeScale * stereo_ = new StereoEfficientLargeScale(0, 128);
	stereo_->operator ()(leftImg, rightImg, dest, 100, mag);

	t = (double)cvGetTickCount() - t;
	printf("used time is %gms\n", (t / (cvGetTickFrequency() * 1000)));

	cv::Mat show;
	dest.convertTo(show, CV_8U, 1.0 / 8);
	imshow("disp", show);
	imshow("left", leftImg);
	imshow("mag", mag);

	cv::Mat result;
	cv::cvtColor(leftImg, result, CV_GRAY2BGR);
	cv::Mat map = stereo_->GetDenseMap();
	for (size_t v = 2; v < map.rows - 2; v += 1)
		for (size_t u = 2; u < map.cols - 2; u += 1)
		{
			//if(mag.at<float>(v,u) < 10) continue;
			if (map.at<short>(v, u) > 0)
			{
				float z = 379.8145 / map.at<short>(v, u);
				cv::Vec3b color = makeDepthColor(1 / z);
				result.at<cv::Vec3b>(v, u)[0] = color[2];
				result.at<cv::Vec3b>(v, u)[1] = color[1];
				result.at<cv::Vec3b>(v, u)[2] = color[0];
			}

		}
	cv::imshow("result", result);




	//if(viewer_->IsFinished())
	//    std::cout<<"finished"<<std::endl;
	//usleep(500000);

}

int __declspec(dllexport)ElasMatch(cv::Mat leftImage, cv::Mat rightImage)
{
	process3();
	//process("D:/Libraries/libelas/img/im0.png", "D:/Libraries/libelas/img/im1.png");
	//process("D:/Libraries/libelas/img/cones_left.pgm", "D:/Libraries/libelas/img/cones_right.pgm");
	//process("D:/Libraries/libelas/img/aloe_left.pgm", "D:/Libraries/libelas/img/aloe_right.pgm");
	//process("D:/Libraries/libelas/img/raindeer_left.pgm", "D:/Libraries/libelas/img/raindeer_right.pgm");
	//process("D:/Libraries/libelas/img/urban1_left.pgm", "D:/Libraries/libelas/img/urban1_right.pgm");
	//process("D:/Libraries/libelas/img/urban2_left.pgm", "D:/Libraries/libelas/img/urban2_right.pgm");
	//process("D:/Libraries/libelas/img/urban3_left.pgm", "D:/Libraries/libelas/img/urban3_right.pgm");
	//process("D:/Libraries/libelas/img/urban4_left.pgm", "D:/Libraries/libelas/img/urban4_right.pgm");

	//process2(image<uchar>(leftImage.data), rightImage);
	cout << "... done!" << endl;
	//cv::Mat disp_l, disp_r, disp8u_l, disp8u_r;
	//double minVal; double maxVal; 

	//// generate disparity image using LIBELAS
	//int bd = 0;
	//const int32_t dims[3] = { leftImage.cols,leftImage.rows,leftImage.cols };
	//cv::Mat leftdpf = cv::Mat::zeros(cv::Size(leftImage.cols, leftImage.rows), CV_32F);
	//cv::Mat rightdpf = cv::Mat::zeros(cv::Size(leftImage.cols, leftImage.rows), CV_32F);
	//Elas::parameters param(Elas::MIDDLEBURY);
	//param.postprocess_only_left = false;
	//Elas elas(param);
	//elas.process(leftImage.data, rightImage.data, leftdpf.ptr<float>(0), rightdpf.ptr<float>(0), dims);

	//cv::Mat(leftdpf(cv::Rect(bd, 0, leftImage.cols, leftImage.rows))).copyTo(disp_l);
	//cv::Mat(rightdpf(cv::Rect(bd, 0, rightImage.cols, rightImage.rows))).copyTo(disp_r);

	////-- Check its extreme values
	//cv::minMaxLoc(disp_l, &minVal, &maxVal);
	//cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

	////-- Display it as a CV_8UC1 image
	//disp_l.convertTo(disp8u_l, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)

	//cv::minMaxLoc(disp_r, &minVal, &maxVal);
	//cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

	////-- Display it as a CV_8UC1 image
	//disp_r.convertTo(disp8u_r, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)

	//cv::normalize(disp8u_l, disp8u_l, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image
	//cv::normalize(disp8u_r, disp8u_r, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image

	//cv::imshow("Left", leftImage);
	//cv::imshow("Right", rightImage);

	//cv::imshow("Elas_left", disp8u_l);
	//cv::imshow("Elas_right", disp8u_r);
	////cv::imwrite("Elas_left.png", disp8u_l);
	////cv::imwrite("Elas_right.png", disp8u_r);

	//cout << endl << "Over" << endl;
	//cv::waitKey(0);

	return 0;
}

int __declspec(dllexport)ElasMatch(cv::Mat leftImage, cv::Mat rightImage, 
	Elas::parameters param,cv::Mat * rawlr, cv::Mat * rawrl, cv::Mat * seelr,cv::Mat * seerl)
{
	cv::Mat disp_l, disp_r, disp8u_l, disp8u_r;
	double minVal; double maxVal;

	int bd = 0;
	const int32_t dims[3] = { leftImage.cols,leftImage.rows,leftImage.cols };
	cv::Mat leftdpf = cv::Mat::zeros(cv::Size(leftImage.cols, leftImage.rows), CV_32F);
	cv::Mat rightdpf = cv::Mat::zeros(cv::Size(leftImage.cols, leftImage.rows), CV_32F);
	//Elas::parameters param(Elas::ROBOTICS);
	//param.postprocess_only_left = false;
	Elas elas(param);
	elas.process(leftImage.data, rightImage.data, leftdpf.ptr<float>(0), rightdpf.ptr<float>(0), dims);

	cv::Mat(leftdpf(cv::Rect(bd, 0, leftImage.cols, leftImage.rows))).copyTo(disp_l);
	cv::Mat(rightdpf(cv::Rect(bd, 0, rightImage.cols, rightImage.rows))).copyTo(disp_r);

	cv::Mat(leftdpf(cv::Rect(bd, 0, leftImage.cols, leftImage.rows))).copyTo(*rawlr);
	cv::Mat(rightdpf(cv::Rect(bd, 0, rightImage.cols, rightImage.rows))).copyTo(*rawrl);

	//-- Check its extreme values
	cv::minMaxLoc(disp_l, &minVal, &maxVal);
	cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

	//-- Display it as a CV_8UC1 image
	disp_l.convertTo(disp8u_l, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)

	cv::minMaxLoc(disp_r, &minVal, &maxVal);
	cout << "Min disp: Max value" << minVal << maxVal; //numberOfDisparities.= (maxVal - minVal)

	//-- Display it as a CV_8UC1 image
	disp_r.convertTo(disp8u_r, CV_8U, 255 / (maxVal - minVal));//(numberOfDisparities*16.)

	cv::normalize(disp8u_l, *seelr, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image
	cv::normalize(disp8u_r, *seerl, 0, 255, CV_MINMAX, CV_8UC1);    // obtain normalized image



	cout << endl << "ELAS over" << endl;
	return 0;
}

