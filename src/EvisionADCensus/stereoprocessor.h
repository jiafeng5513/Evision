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

#ifndef STEREOPROCESSOR_H
#define STEREOPROCESSOR_H

#include "aggregation.h"
#include "disparityrefinement.h"
#include <opencv2/opencv.hpp>

using namespace std;

class StereoProcessor
{
public:
    StereoProcessor(float percentageOfDeletion, std::string blurMethod, int kernelSize, float alpha, float beta,
		uint dMin, uint dMax, cv::Mat leftImage, cv::Mat rightImage, cv::Size censusWin, float defaultBorderCost,
        float lambdaAD, float lambdaCensus, string savePath, uint aggregatingIterations,
        uint colorThreshold1, uint colorThreshold2, uint maxLength1, uint maxLength2, uint colorDifference,
        float pi1, float pi2, uint dispTolerance, uint votingThreshold, float votingRatioThreshold,
        uint maxSearchDepth, uint blurKernelSize, uint cannyThreshold1, uint cannyThreshold2, uint cannyKernelSize);
    ~StereoProcessor();
    bool init(string &error);
    bool compute();
	cv::Mat getDisparity();
	cv::Mat getGrayDisparity();

private:
    int dMin;
    int dMax;
	cv::Mat images[2];
	cv::Size censusWin;
    float defaultBorderCost;
    float lambdaAD;
    float lambdaCensus;
    string savePath;
    uint aggregatingIterations;
    uint colorThreshold1;
    uint colorThreshold2;
    uint maxLength1;
    uint maxLength2;
    uint colorDifference;
    float pi1;
    float pi2;
    uint dispTolerance;
    uint votingThreshold;
    float votingRatioThreshold;
    uint maxSearchDepth;
    uint blurKernelSize;
    uint cannyThreshold1;
    uint cannyThreshold2;
    uint cannyKernelSize;
    bool validParams, dispComputed;

    vector<vector<cv::Mat> > costMaps;
	cv::Size imgSize;
    ADCensusCV *adCensus;
    Aggregation *aggregation;
	cv::Mat disparityMap, floatDisparityMap;
    DisparityRefinement *dispRef;

    void costInitialization();
    void costAggregation();
    void scanlineOptimization();
    void outlierElimination();
    void regionVoting();
    void properInterpolation();
    void discontinuityAdjustment();
    void subpixelEnhancement();

	cv::Mat cost2disparity(int imageNo);

    template <typename T>
    void saveDisparity(const cv::Mat &disp, string filename, bool stretch = true);

	template <typename T>
	void convertDisparity(const cv::Mat &disp, cv::Mat &grayDisp, bool stretch);

};

#endif // STEREOPROCESSOR_H
