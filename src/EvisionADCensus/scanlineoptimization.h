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

#ifndef SCANLINEOPTIMIZATION_H
#define SCANLINEOPTIMIZATION_H

#include <opencv2/opencv.hpp>
#include <omp.h>
#include "common.h"
#include <libapi.h>

using namespace std;

class LIB_API ScanlineOptimization
{
public:
    ScanlineOptimization(const cv::Mat &leftImage, const cv::Mat &rightImage, int dMin, int dMax,
                         uint colorDifference, float pi1, float pi2);
    void optimization(vector<cv::Mat> *costMaps, bool rightFirst);
private:
    cv::Mat images[2];
	cv::Size imgSize;
    int dMin;
    int dMax;
    uint colorDifference;
    float pi1;
    float pi2;

    void verticalComputation(int height, int direction, vector<cv::Mat> *costMaps, bool rightFirst);
    void verticalOptimization(int height1, int height2, vector<cv::Mat> *costMaps, bool rightFirst);

    void horizontalComputation(int width, int direction, vector<cv::Mat> *costMaps, bool rightFirst);
    void horizontalOptimization(int width1, int width2, vector<cv::Mat> *costMaps, bool rightFirst);

    void partialOptimization(int height1, int height2, int width1, int width2, vector<cv::Mat> *costMaps, bool rightFirst);

    void computeP1P2(int height1, int height2, int width1, int width2, int disparity, float &p1, float &p2, bool rightFirst);

    int colorDiff(const cv::Vec3b &p1, const cv::Vec3b &p2) const;
};

#endif // SCANLINEOPTIMIZATION_H
