#include<iostream>   
#include <opencv2/core/core.hpp>  
#include <opencv2/opencv.hpp>
#include "elas.h"
#include "image.h"
#include "StereoEfficientLargeScale.h"
#include "EvisionElas.h"

using namespace std;

EvisionElas::EvisionElas()
{
}

EvisionElas::EvisionElas(int32_t disp_min, int32_t disp_max, float support_threshold, 
	int32_t support_texture, int32_t candidate_stepsize, int32_t incon_window_size, 
	int32_t incon_threshold, int32_t incon_min_support, bool add_corners, 
	int32_t grid_size, float beta, float gamma, float sigma, float sradius, 
	int32_t match_texture, int32_t lr_threshold, float speckle_sim_threshold, 
	int32_t speckle_size, int32_t ipol_gap_width, bool filter_median, 
	bool filter_adaptive_mean, bool postprocess_only_left, bool subsampling,int border)
{
	this->disp_min=disp_min;
	this->disp_max= disp_max;
	this->support_threshold= support_threshold;
	this->support_texture= support_texture;
	this->candidate_stepsize= candidate_stepsize;
	this->incon_window_size= incon_window_size;
	this->incon_threshold= incon_threshold;
	this->incon_min_support= incon_min_support;
	this->add_corners= add_corners;
	this->grid_size= grid_size;
	this->beta= beta;
	this->gamma= gamma;
	this->sigma= sigma;
	this->sradius= sradius;
	this->match_texture= match_texture;
	this->lr_threshold= lr_threshold;
	this->speckle_sim_threshold= speckle_sim_threshold;
	this->speckle_size= speckle_size;
	this->ipol_gap_width= ipol_gap_width;
	this->filter_median= filter_median;
	this->filter_adaptive_mean= filter_adaptive_mean;
	this->postprocess_only_left= postprocess_only_left;
	this->subsampling= subsampling;
	this->border = border;
}

bool EvisionElas::Match(cv::Mat leftImg, cv::Mat rightImg, cv::Mat* disp_raw, cv::Mat* disp_show)
{
	if (leftImg.data == NULL || rightImg.data == NULL) {
		return false;
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


	Elas::parameters param;

	param.disp_min = this->disp_min;
	param.disp_max = this->disp_max;
	param.support_threshold = this->support_threshold;
	param.support_texture = this->support_texture;
	param.candidate_stepsize = this->candidate_stepsize;
	param.incon_window_size = this->incon_window_size;
	param.incon_threshold = this->incon_threshold;
	param.incon_min_support = this->incon_min_support;
	param.add_corners = this->add_corners;
	param.grid_size = this->grid_size;
	param.beta = this->beta;
	param.gamma = this->gamma;
	param.sigma = this->sigma;
	param.sradius = this->sradius;
	param.match_texture = this->match_texture;
	param.lr_threshold = this->lr_threshold;
	param.speckle_sim_threshold = this->speckle_sim_threshold;
	param.speckle_size = this->speckle_size;
	param.ipol_gap_width = this->ipol_gap_width;
	param.filter_median = this->filter_median;
	param.filter_adaptive_mean = this->filter_adaptive_mean;
	param.postprocess_only_left = this->postprocess_only_left;
	param.subsampling = this->subsampling;



	StereoEfficientLargeScale stereo_(param);
	stereo_(leftImg, rightImg, *disp_raw, border, mag);

	//cv::Mat show;
	disp_raw->convertTo(*disp_show, CV_8U, 1.0 / 16);
	disp_show->copyTo(*disp_raw);
	/*
	 *disp_raw 原始视差数据
	 *disp_show 可视化视差数据
	 *mag
	 */

	return true;
}
