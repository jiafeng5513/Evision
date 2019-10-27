/* ----------------------------------------------------------------------------
 * Robotics Laboratory, Westphalian University of Applied Science
 * ----------------------------------------------------------------------------
 * Project			: 	Stereo Vision Project
 * Revision			: 	1.0
 * Recent changes	: 	18.06.2014	 
 * ----------------------------------------------------------------------------
 * LOG:
 * ----------------------------------------------------------------------------
 * Developer		: 	Dennis Luensch 		(dennis.luensch@gmail.com)
						Tom Marvin Liebelt	(fh@tom-liebelt.de)
						Christian Blesing	(christian.blesing@gmail.com)
 * License 			: 	BSD 
 *
 * Copyright (c) 2014, Dennis Lünsch, Tom Marvin Liebelt, Christian Blesing
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * # Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * # Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * 
 * # Neither the name of the {organization} nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------- */

#include "stereoprocessor.h"
#include <limits>
#include "imageprocessor.h"
#include <omp.h>
#include "common.h"
#include "adcensuscv.h"
#include "scanlineoptimization.h"
//#define DEBUG

StereoProcessor::StereoProcessor(float percentageOfDeletion, std::string blurMethod, int kernelSize, float alpha, float beta,
	uint dMin, uint dMax, cv::Mat leftImage, cv::Mat rightImage, cv::Size censusWin, float defaultBorderCost,
                                 float lambdaAD, float lambdaCensus, string savePath, uint aggregatingIterations,
                                 uint colorThreshold1, uint colorThreshold2, uint maxLength1, uint maxLength2, uint colorDifference,
                                 float pi1, float pi2, uint dispTolerance, uint votingThreshold, float votingRatioThreshold,
                                 uint maxSearchDepth, uint blurKernelSize, uint cannyThreshold1, uint cannyThreshold2, uint cannyKernelSize)
{
    this->dMin = dMin;
    this->dMax = dMax;

	//float percentageOfDeletion = 0.1;
	//std::string blurMethod = "gauss";//"median"
	//int kernelSize = 3;
	//float alpha = 1.9;
	//float beta = -1;
	ImageProcessor iP(percentageOfDeletion);
	this->images[0] = iP.unsharpMasking(leftImage, blurMethod, kernelSize, alpha, beta);
	this->images[1] = iP.unsharpMasking(rightImage, blurMethod, kernelSize, alpha, beta);

    this->censusWin = censusWin;
    this->defaultBorderCost = defaultBorderCost;
    this->lambdaAD = lambdaAD;
    this->lambdaCensus = lambdaCensus;
    this->savePath = savePath;
    this->aggregatingIterations = aggregatingIterations;
    this->colorThreshold1 = colorThreshold1;
    this->colorThreshold2 = colorThreshold2;
    this->maxLength1 = maxLength1;
    this->maxLength2 = maxLength2;
    this->colorDifference = colorDifference;
    this->pi1 = pi1;
    this->pi2 = pi2;
    this->dispTolerance = dispTolerance;
    this->votingThreshold = votingThreshold;
    this->votingRatioThreshold = votingRatioThreshold;
    this->maxSearchDepth = maxSearchDepth;
    this->blurKernelSize = blurKernelSize;
    this->cannyThreshold1 = cannyThreshold1;
    this->cannyThreshold2 = cannyThreshold2;
    this->cannyKernelSize = cannyKernelSize;
    this->validParams = false;
    this->dispComputed = false;
}

StereoProcessor::~StereoProcessor()
{
    delete adCensus;
    delete aggregation;
    delete dispRef;
}

bool StereoProcessor::init(string &error)
{
    bool valid = true;

    valid &= dMin < dMax;

    valid &= images[0].size().height == images[1].size().height && images[0].size().width == images[1].size().width
                   && images[0].size().height > 2 && images[0].size().width > 2;

    valid &= censusWin.height > 2 && censusWin.width > 2 && censusWin.height % 2 != 0 && censusWin.width % 2 != 0;

    valid &= defaultBorderCost >= 0 && defaultBorderCost < 1 && lambdaAD >= 0 && lambdaCensus >= 0 && aggregatingIterations > 0;

    valid &= colorThreshold1 > colorThreshold2 && colorThreshold2 > 0;

    valid &= maxLength1 > maxLength2 && maxLength2 > 0;

    valid &= colorDifference > 0 && pi1 > 0 && pi2 > 0;

    valid &= votingThreshold > 0 && votingRatioThreshold > 0 && maxSearchDepth > 0;

    valid &= blurKernelSize > 2 && blurKernelSize % 2 != 0;

    valid &= cannyThreshold1 < cannyThreshold2;

    valid &= cannyKernelSize > 2 && cannyKernelSize % 2 != 0;

    if(!valid)
    {
        error = "StereoProcessor needs the following parameters: \n"
                "dMin(uint)                       [dMin(uint) < dMax(uint)]\n"
                "leftImage(string)                [path to image file]\n"
                "rightImage(string)               [path to image file]\n"
                "censusWinH(uint)                 [censusWinH > 2 and odd]\n"
                "censusWinW(uint)                 [censusWinW > 2 and odd]\n"
                "defaultBorderCost(float)        [0 <= defaultBorderCost < 1]\n"
                "lambdaAD(float)                 [lambdaAD >= 0]\n"
                "lambdaCensus(float)             [lambdaCensus >= 0]\n"
                "savePath(string)                 [:-)]\n"
                "aggregatingIterations(uint)      [aggregatingIterations > 0]\n"
                "colorThreshold1(uint)            [colorThreshold1 > colorThreshold2]\n"
                "colorThreshold2(uint)            [colorThreshold2 > 0]\n"
                "maxLength1(uint)                 [maxLength1 > 0]\n"
                "maxLength2(uint)                 [maxLength2 > 0]\n"
                "colorDifference(uint)            [colorDifference > 0]\n"
                "pi1(float)                      [pi1 > 0]\n"
                "pi2(float)                      [pi2 > 0]\n"
                "dispTolerance(uint)              [;-)]\n"
                "votingThreshold(uint)            [votingThreshold > 0]\n"
                "votingRatioThreshold(float)     [votingRatioThreshold > 0]\n"
                "maxSearchDepth(uint)             [maxSearchDepth > 0]\n"
                "blurKernelSize(uint)             [blurKernelSize > 2 and odd]\n"
                "cannyThreshold1(uint)            [cannyThreshold1 < cannyThreshold2]\n"
                "cannyThreshold2(uint)            [:-)]\n"
                "cannyKernelSize(uint)            [cannyKernelSize > 2 and odd]\n";
    }
    else
    {
        error = "";

        this->imgSize = images[0].size();
        costMaps.resize(2);
        for (size_t i = 0; i < 2; i++)
        {
            costMaps[i].resize(abs(dMax - dMin) + 1);
            for(size_t j = 0; j < costMaps[i].size(); j++)
            {
                costMaps[i][j].create(imgSize, COST_MAP_TYPE);
            }
        }

        adCensus = new ADCensusCV(images[0], images[1], censusWin, lambdaAD, lambdaCensus);
        aggregation = new Aggregation(images[0], images[1], colorThreshold1, colorThreshold2, maxLength1, maxLength2);
        dispRef = new DisparityRefinement(dispTolerance, dMin, dMax, votingThreshold, votingRatioThreshold, maxSearchDepth,
                                          blurKernelSize, cannyThreshold1, cannyThreshold2, cannyKernelSize);
    }

    validParams = valid;
    return valid;
}

bool StereoProcessor::compute()
{
    if(validParams)
    {
        costInitialization();
        costAggregation();
        scanlineOptimization();
        outlierElimination();
        regionVoting();
        properInterpolation();
        discontinuityAdjustment();
        subpixelEnhancement();
        dispComputed = true;
    }

    return validParams;
}

cv::Mat StereoProcessor::getDisparity()
{
	if(dispComputed)
	{
		//saveDisparity<float>(floatDisparityMap, "Raw_DisparityMap.png");
		//cv::Mat * gray_mat = new cv::Mat();
		//convertDisparity<float>(floatDisparityMap, *gray_mat, true);
		//saveDisparity<float>(*gray_mat, "_Gary_DisparityMap.png");
		//delete gray_mat;
		return floatDisparityMap;
	}else
	{
		return cv::Mat();
	}
    //return (dispComputed)? floatDisparityMap: cv::Mat();
}

cv::Mat StereoProcessor::getGrayDisparity()
{
	if (dispComputed)
	{
		cv::Mat * gray_mat = new cv::Mat();
		convertDisparity<float>(floatDisparityMap, *gray_mat, true);
		return *gray_mat;
	}
	else
	{
		return cv::Mat();
	}
}

void StereoProcessor::costInitialization()
{
	cv::Size halfCensusWin(censusWin.width / 2, censusWin.height / 2);
    bool out;
    int d, h, w, wL, wR;
    size_t imageNo;

    cout << "[StereoProcessor] started cost initialization!" << endl;


    for(imageNo = 0; imageNo < 2; ++imageNo)
    {
        #pragma omp parallel default (shared) private(d, h, w, wL, wR, out) num_threads(omp_get_max_threads())
        #pragma omp for schedule(static)
        for(d = 0; d <= dMax - dMin; d++)
        {
            for(h = 0; h < imgSize.height; h++)
            {
                for(w = 0; w < imgSize.width; w++)
                {
                    wL = w;
                    wR = w;

                    if(imageNo == 0)
                        wR = w - d;
                    else
                        wL = w + d;

                    out = wL - halfCensusWin.width < 0 || wL + halfCensusWin.width >= imgSize.width
                           || wR - halfCensusWin.width < 0 || wR + halfCensusWin.width >= imgSize.width
                           || h - halfCensusWin.height < 0 || h + halfCensusWin.height >= imgSize.height;

                    costMaps[imageNo][d].at<costType>(h, w) = out
                                                            ? defaultBorderCost * COST_FACTOR
                                                            : adCensus->adCensus(wL, h, wR, h) / 2 * COST_FACTOR;
                }
            }
            cout << "[StereoProcessor] created disparity no. " << d << " for image no. " << imageNo << endl;
        }
        cout << "[StereoProcessor] created cost maps for image no. " << imageNo << endl;
    }

#ifdef DEBUG
	cv::Mat disp = cost2disparity(0);
    saveDisparity<int>(disp, "01_dispLR.png");

    disp = cost2disparity(1);
    saveDisparity<int>(disp, "01_dispRL.png");
#endif

    cout << "[StereoProcessor] finished cost initialization!" << endl;

}

void StereoProcessor::costAggregation()
{
    size_t imageNo, i;
    int d;

    cout << "[StereoProcessor] started cost aggregation!" << endl;

    for(imageNo = 0; imageNo < 2; ++imageNo)
    {
#if COST_TYPE_NOT_FLOAT
        #pragma omp parallel default (shared) private(d, i) num_threads(omp_get_max_threads())
        #pragma omp for schedule(static)
        for(d = 0; d <= dMax - dMin; d++)
        {
			cv::Mat currCostMap(imgSize, CV_32F);

            for(int h = 0; h < imgSize.height; h++)
            {
                for(int w = 0; w < imgSize.width; w++)
                {
                    currCostMap.at<float>(h, w) = (float)costMaps[imageNo][d].at<costType>(h, w) / COST_FACTOR;
                }
            }

            bool horizontalFirst = true;
            for(i = 0; i < aggregatingIterations; i++)
            {
                aggregation->aggregation2D(currCostMap, horizontalFirst, imageNo);
                horizontalFirst = !horizontalFirst;
                cout << "[StereoProcessor] aggregation iteration no. " << i << ", disparity no. " << d << " for image no. " << imageNo << endl;
            }

            for(int h = 0; h < imgSize.height; h++)
            {
                for(int w = 0; w < imgSize.width; w++)
                {
                    costMaps[imageNo][d].at<costType>(h, w) = (costType)(currCostMap.at<float>(h, w) * COST_FACTOR);
                }
            }
        }
#else
        #pragma omp parallel default (shared) private(d, i) num_threads(omp_get_max_threads())
        #pragma omp for schedule(static)
        for(d = 0; d <= dMax - dMin; d++)
        {
            bool horizontalFirst = true;
            for(i = 0; i < aggregatingIterations; i++)
            {
                aggregation->aggregation2D(costMaps[imageNo][d], horizontalFirst, imageNo);
                horizontalFirst = !horizontalFirst;
                cout << "[StereoProcessor] aggregation iteration no. " << i << ", disparity no. " << d << " for image no. " << imageNo << endl;
            }
        }
#endif
    }

#ifdef DEBUG
	cv::Mat disp = cost2disparity(0);
    saveDisparity<int>(disp, "02_dispLR_agg.png");

    disp = cost2disparity(1);
    saveDisparity<int>(disp, "02_dispRL_agg.png");
#endif

    cout << "[StereoProcessor] finished cost aggregation!" << endl;
}

void StereoProcessor::scanlineOptimization()
{
    ScanlineOptimization sO(images[0], images[1], dMin, dMax, colorDifference, pi1, pi2);
    int imageNo;

    cout << "[StereoProcessor] started scanline optimization!" << endl;

    #pragma omp parallel default (shared) private(imageNo) num_threads(omp_get_max_threads())
    #pragma omp for schedule(static)
    for(imageNo = 0; imageNo < 2; ++imageNo)
    {
        sO.optimization(&costMaps[imageNo], (imageNo == 1));
    }

#ifdef DEBUG
	cv::Mat disp = cost2disparity(0);
    saveDisparity<int>(disp, "03_dispLR_so.png");

    disp = cost2disparity(1);
    saveDisparity<int>(disp, "03_dispRL_so.png");
#endif

    cout << "[StereoProcessor] finished scanline optimization!" << endl;
}

void StereoProcessor::outlierElimination()
{
    cout << "[StereoProcessor] started outlier elimination!" << endl;

    cv::Mat disp0 = cost2disparity(0);
    cv::Mat disp1 = cost2disparity(1);

    disparityMap = dispRef->outlierElimination(disp0, disp1);

#ifdef DEBUG
    saveDisparity<int>(disparityMap, "04_dispBoth_oe.png");
#endif

    cout << "[StereoProcessor] finished outlier elimination!" << endl;
}

void StereoProcessor::regionVoting()
{
    vector<cv::Mat> upLimits, downLimits, leftLimits, rightLimits;

    cout << "[StereoProcessor] started region voting!" << endl;

    aggregation->getLimits(upLimits, downLimits, leftLimits, rightLimits);

    bool horizontalFirst = false;
    for(int i = 0; i < 5; i++)
    {
        cout << "[StereoProcessor] region voting iteration no. " << i << endl;
        dispRef->regionVoting(disparityMap, upLimits, downLimits, leftLimits, rightLimits, horizontalFirst);
        horizontalFirst = ~horizontalFirst;
    }

#ifdef DEBUG
    saveDisparity<int>(disparityMap, "05_dispBoth_rv.png");
#endif

    cout << "[StereoProcessor] finished region voting!" << endl;
}

void StereoProcessor::properInterpolation()
{
    cout << "[StereoProcessor] started proper interpolation!" << endl;
    dispRef->properInterpolation(disparityMap, images[0]);

#ifdef DEBUG
    saveDisparity<int>(disparityMap, "06_dispBoth_pi.png");
#endif

    cout << "[StereoProcessor] finished proper interpolation!" << endl;
}

void StereoProcessor::discontinuityAdjustment()
{
    cout << "[StereoProcessor] started discontinuity adjustment!" << endl;
    dispRef->discontinuityAdjustment(disparityMap, costMaps);

#ifdef DEBUG
    saveDisparity<int>(disparityMap, "07_dispBoth_da.png");
#endif

    cout << "[StereoProcessor] finished discontinuity adjustment!" << endl;
}

void StereoProcessor::subpixelEnhancement()
{
    cout << "[StereoProcessor] started subpixel enhancement!" << endl;
    floatDisparityMap = dispRef->subpixelEnhancement(disparityMap, costMaps);

#ifdef DEBUG
    saveDisparity<float>(floatDisparityMap, "08_dispBoth_se.png");
#endif

    cout << "[StereoProcessor] finished subpixel enhancement!" << endl;
}

cv::Mat StereoProcessor::cost2disparity(int imageNo)
{
    cv::Mat disp(imgSize, CV_32S);
    cv::Mat lowCost(imgSize, COST_MAP_TYPE, cv::Scalar(std::numeric_limits<costType>::max()));

    for(int d = 0; d <= dMax - dMin; d++)
    {
        for(size_t h = 0; h < imgSize.height; h++)
        {
            for(size_t w = 0; w < imgSize.width; w++)
            {
                if (lowCost.at<costType>(h, w) > costMaps[imageNo][d].at<costType>(h, w))
                {
                    lowCost.at<costType>(h, w) = costMaps[imageNo][d].at<costType>(h, w);
                    disp.at<int>(h, w) = d + dMin;
                }
            }
        }
    }

    return disp;
}

template <typename T>
void StereoProcessor::saveDisparity(const cv::Mat &disp, string filename, bool stretch)
{
    cv::Mat output(imgSize, CV_8UC3);
    cv::String path(savePath);
    T min, max;

    if(stretch)
    {
        min = std::numeric_limits<T>::max();
        max = 0;
        for(size_t h = 0; h < imgSize.height; h++)
        {
            for(size_t w = 0; w < imgSize.width; w++)
            {
                T disparity = disp.at<T>(h, w);

                if(disparity < min && disparity >= 0)
                    min = disparity;
                else if(disparity > max)
                    max = disparity;
            }
        }
    }

    for(size_t h = 0; h < imgSize.height; h++)
    {
        for(size_t w = 0; w < imgSize.width; w++)
        {
            cv::Vec3b color;
            T disparity = disp.at<T>(h, w);

            if (disparity >= dMin)
            {
                if(stretch)
                    disparity = (255 / (max - min)) * (disparity - min);

                color[0] = (uchar)disparity;
                color[1] = (uchar)disparity;
                color[2] = (uchar)disparity;

            }
            else if(disparity == dMin - DisparityRefinement::DISP_OCCLUSION)
            {
                color[0] = 255;
                color[1] = 0;
                color[2] = 0;
            }
            else
            {
                color[0] = 0;
                color[1] = 0;
                color[2] = 255;
            }

            output.at<cv::Vec3b>(h, w) = color;
        }
    }

    path += filename;
    imwrite(path, output);
}

template <typename T>
void StereoProcessor::convertDisparity(const cv::Mat& disp, cv::Mat& grayDisp, bool stretch)
{
	cv::Size imgSize = disp.size();
	cv::Mat output(imgSize, CV_8UC3);
	T min, max;

	if (stretch)
	{
		min = std::numeric_limits<T>::max();
		max = 0;
		for (size_t h = 0; h < imgSize.height; h++)
		{
			for (size_t w = 0; w < imgSize.width; w++)
			{
				T disparity = disp.at<T>(h, w);

				if (disparity < min && disparity >= 0)
					min = disparity;
				else if (disparity > max)
					max = disparity;
			}
		}
	}

	for (size_t h = 0; h < imgSize.height; h++)
	{
		for (size_t w = 0; w < imgSize.width; w++)
		{
			cv::Vec3b color;
			T disparity = disp.at<T>(h, w);

			if (disparity >= 0)
			{
				if (stretch)
					disparity = (255 / (max - min)) * (disparity - min);

				color[0] = (uchar)disparity;
				color[1] = (uchar)disparity;
				color[2] = (uchar)disparity;

			}
			else
			{
				color[0] = 0;
				color[1] = 0;
				color[2] = 0;
			}

			output.at<cv::Vec3b>(h, w) = color;
		}
	}

	grayDisp = output.clone();
}
