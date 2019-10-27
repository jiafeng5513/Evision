#pragma once
#include <opencv2/opencv.hpp>

class StereoProcessor;

class __declspec(dllexport) EvisionADCensus
{
protected:
	StereoProcessor * processor;
public:
	EvisionADCensus(float percentageOfDeletion, std::string blurMethod, int kernelSize, float alpha, float beta,
		uint dMin, uint dMax, cv::Mat leftImage, cv::Mat rightImage, cv::Size censusWin, float defaultBorderCost,
		float lambdaAD, float lambdaCensus, std::string savePath, uint aggregatingIterations,
		uint colorThreshold1, uint colorThreshold2, uint maxLength1, uint maxLength2, uint colorDifference,
		float pi1, float pi2, uint dispTolerance, uint votingThreshold, float votingRatioThreshold,
		uint maxSearchDepth, uint blurKernelSize, uint cannyThreshold1, uint cannyThreshold2, uint cannyKernelSize);
	~EvisionADCensus();
	bool init(std::string &error);
	bool compute();
	cv::Mat getDisparity();
	cv::Mat getGrayDisparity();
};

