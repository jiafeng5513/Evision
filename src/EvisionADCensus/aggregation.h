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

#ifndef AGGREGATION_H
#define AGGREGATION_H
#include <opencv2/opencv.hpp>
#include <omp.h>
#include "common.h"
#include <libapi.h>

using namespace std;

class LIB_API Aggregation
{
public:
    Aggregation(const cv::Mat &leftImage, const cv::Mat &rightImage, uint colorThreshold1, uint colorThreshold2,
                uint maxLength1, uint maxLength2);
    void aggregation2D(cv::Mat &costMap, bool horizontalFirst, uchar imageNo);
    void getLimits(vector<cv::Mat> &upLimits, vector<cv::Mat> &downLimits, vector<cv::Mat> &leftLimits, vector<cv::Mat> &rightLimits) const;
private:
    cv::Mat images[2];
	cv::Size imgSize;
    uint colorThreshold1, colorThreshold2;
    uint maxLength1, maxLength2;
    vector<cv::Mat> upLimits;
    vector<cv::Mat> downLimits;
    vector<cv::Mat> leftLimits;
    vector<cv::Mat> rightLimits;

    int colorDiff(const cv::Vec3b &p1, const cv::Vec3b &p2);
    int computeLimit(int height, int width, int directionH, int directionW, uchar imageNo);
    cv::Mat computeLimits(int directionH, int directionW, int imageNo);

    cv::Mat aggregation1D(const cv::Mat &costMap, int directionH, int directionW, cv::Mat &windowSizes, uchar imageNo);
};

#endif // AGGREGATION_H
