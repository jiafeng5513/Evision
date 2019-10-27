#include "EvisionADCensus.h"
#include "stereoprocessor.h"


EvisionADCensus::EvisionADCensus(float percentageOfDeletion, std::string blurMethod, int kernelSize, float alpha, float beta, uint dMin, uint dMax, cv::Mat leftImage, cv::Mat rightImage, cv::Size censusWin, float defaultBorderCost, float lambdaAD, float lambdaCensus, std::string savePath, uint aggregatingIterations, uint colorThreshold1, uint colorThreshold2, uint maxLength1, uint maxLength2, uint colorDifference, float pi1, float pi2, uint dispTolerance, uint votingThreshold, float votingRatioThreshold, uint maxSearchDepth, uint blurKernelSize, uint cannyThreshold1, uint cannyThreshold2, uint cannyKernelSize)
{
	processor=new StereoProcessor(percentageOfDeletion,  blurMethod, kernelSize, alpha,  beta,
		 dMin, dMax, leftImage, rightImage, censusWin, defaultBorderCost,
		 lambdaAD, lambdaCensus, savePath, aggregatingIterations,
		 colorThreshold1, colorThreshold2, maxLength1, maxLength2, colorDifference,
		 pi1, pi2, dispTolerance, votingThreshold, votingRatioThreshold,
		 maxSearchDepth, blurKernelSize, cannyThreshold1, cannyThreshold2, cannyKernelSize);
}

EvisionADCensus::~EvisionADCensus()
{
	delete processor;
}

bool EvisionADCensus::init(std::string & error)
{
	return processor->init(error);
}

bool EvisionADCensus::compute()
{
	return processor->compute();
}

cv::Mat EvisionADCensus::getDisparity()
{
	return processor->getDisparity();
}

cv::Mat EvisionADCensus::getGrayDisparity()
{
	return processor->getGrayDisparity();
}
