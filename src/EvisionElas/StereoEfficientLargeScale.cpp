#include "StereoEfficientLargeScale.h"



StereoEfficientLargeScale::StereoEfficientLargeScale(Elas::parameters param) :elas(param)
{

	minDisparity = param.disp_min;
	disparityRange = param.disp_max- minDisparity;
}

void StereoEfficientLargeScale::operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, cv::Mat& rightdisp, int bd)
{
	cv::Mat l, r;
	if (leftim.channels() == 3) { cvtColor(leftim, l, CV_BGR2GRAY);
		std::cout << "convert gray" << std::endl; }
	else l = leftim;
	if (rightim.channels() == 3)cvtColor(rightim, r, CV_BGR2GRAY);
	else r = rightim;

	cv::Mat lb, rb;
	cv::copyMakeBorder(l, lb, 0, 0, bd, bd, cv::BORDER_REPLICATE);
	cv::copyMakeBorder(r, rb, 0, 0, bd, bd, cv::BORDER_REPLICATE);

	const cv::Size imsize = lb.size();
	const int32_t dims[3] = { imsize.width,imsize.height,imsize.width }; // bytes per line = width

	cv::Mat leftdpf = cv::Mat::zeros(imsize, CV_32F);
	cv::Mat rightdpf = cv::Mat::zeros(imsize, CV_32F);
	elas.process(lb.data, rb.data, leftdpf.ptr<float>(0), rightdpf.ptr<float>(0), dims);

	cv::Mat disp;
	cv::Mat(leftdpf(cv::Rect(bd, 0, leftim.cols, leftim.rows))).copyTo(disp);
	disp.convertTo(leftdisp, CV_16S, 16);

	left_dmap_ = leftdisp.clone();

	cv::Mat(rightdpf(cv::Rect(bd, 0, leftim.cols, leftim.rows))).copyTo(disp);

	disp.convertTo(rightdisp, CV_16S, 16);
}

void StereoEfficientLargeScale::operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, int bd)
{
	cv::Mat temp;
	left_img_ = leftim.clone();
	StereoEfficientLargeScale::operator()(leftim, rightim, leftdisp, temp, bd);
}

void StereoEfficientLargeScale::operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, int bd, const cv::Mat grad)
{
	cv::Mat temp;
	left_img_ = leftim.clone();
	StereoEfficientLargeScale::operator()(leftim, rightim, leftdisp, temp, bd, grad);

}
void StereoEfficientLargeScale::operator()(cv::Mat& leftim, cv::Mat& rightim, cv::Mat& leftdisp, cv::Mat& rightdisp, int bd, const cv::Mat grad)
{
	cv::Mat l, r;
	if (leftim.channels() == 3) { cvtColor(leftim, l, CV_BGR2GRAY);
		std::cout << "convert gray" << std::endl; }
	else l = leftim;
	if (rightim.channels() == 3)cvtColor(rightim, r, CV_BGR2GRAY);
	else r = rightim;

	cv::Mat lb, rb;
	cv::copyMakeBorder(l, lb, 0, 0, bd, bd, cv::BORDER_REPLICATE);
	cv::copyMakeBorder(r, rb, 0, 0, bd, bd, cv::BORDER_REPLICATE);

	const cv::Size imsize = lb.size();
	const int32_t dims[3] = { imsize.width,imsize.height,imsize.width }; // bytes per line = width

	cv::Mat leftdpf = cv::Mat::zeros(imsize, CV_32F);
	cv::Mat rightdpf = cv::Mat::zeros(imsize, CV_32F);
	elas.process(lb.data, rb.data, leftdpf.ptr<float>(0), rightdpf.ptr<float>(0), dims, grad);

	cv::Mat disp;
	cv::Mat(leftdpf(cv::Rect(bd, 0, leftim.cols, leftim.rows))).copyTo(disp);
	disp.convertTo(leftdisp, CV_16S, 16);

	left_dmap_ = leftdisp.clone();
	/*
   for(size_t v = 2; v< leftdisp.rows -2; v ++)
	 for(size_t u = 2; u< leftdisp.cols -2 ; u++)
   {
		 float a = grad.at<float>(v,u) ;
		 //if(grad.at<float>(v,u) < 10) left_dmap_.at<short>(v,u) = 0;
	 }
   */
	cv::Mat(rightdpf(cv::Rect(bd, 0, leftim.cols, leftim.rows))).copyTo(disp);

	disp.convertTo(rightdisp, CV_16S, 16);
}
