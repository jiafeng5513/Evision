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

#ifndef DISPARITYREFINEMENT_H
#define DISPARITYREFINEMENT_H

#include <opencv2/opencv.hpp>
#include "adcensuscv.h"
#include "common.h"
#include <libapi.h>

using namespace std;

class LIB_API DisparityRefinement
{
public:
    DisparityRefinement(uint dispTolerance, int dMin, int dMax,
                        uint votingThreshold, float votingRatioThreshold, uint maxSearchDepth,
                        uint blurKernelSize, uint cannyThreshold1, uint cannyThreshold2, uint cannyKernelSize);
	cv::Mat outlierElimination(const cv::Mat &leftDisp, const cv::Mat &rightDisp);
    void regionVoting(cv::Mat &disparity, const vector<cv::Mat> &upLimits, const vector<cv::Mat> &downLimits,
                      const vector<cv::Mat> &leftLimits, const vector<cv::Mat> &rightLimits, bool horizontalFirst);
    void properInterpolation(cv::Mat &disparity, const cv::Mat &leftImage);
    void discontinuityAdjustment(cv::Mat &disparity, const vector<vector<cv::Mat> > &costs);
    cv::Mat subpixelEnhancement(cv::Mat &disparity, const vector<vector<cv::Mat> > &costs);


    static const int DISP_OCCLUSION;
    static const int DISP_MISMATCH;
private:
    int colorDiff(const cv::Vec3b &p1, const cv::Vec3b &p2);
    cv::Mat convertDisp2Gray(const cv::Mat &disparity);

    int occlusionValue;
    int mismatchValue;
    uint dispTolerance;
    int dMin;
    int dMax;
    uint votingThreshold;
    float votingRatioThreshold;
    uint maxSearchDepth;
    uint blurKernelSize;
    uint cannyThreshold1;
    uint cannyThreshold2;
    uint cannyKernelSize;
};

#endif // DISPARITYREFINEMENT_H
