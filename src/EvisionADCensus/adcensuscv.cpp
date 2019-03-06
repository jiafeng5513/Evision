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

#include "adcensuscv.h"
#include <opencv2/opencv.hpp>

ADCensusCV::ADCensusCV(const cv::Mat &leftImage, const cv::Mat &rightImage, cv::Size censusWin, float lambdaAD, float lambdaCensus)
{
    this->leftImage = leftImage;
    this->rightImage = rightImage;
    this->censusWin = censusWin;
    this->lambdaAD = lambdaAD;
    this->lambdaCensus = lambdaCensus;
}

float ADCensusCV::ad(int wL, int hL, int wR, int hR) const
{
    float dist = 0;
    const cv::Vec3b &colorLP = leftImage.at<cv::Vec3b>(hL, wL);
    const cv::Vec3b &colorRP = rightImage.at<cv::Vec3b>(hR, wR);

    for(uchar color = 0; color < 3; ++color)
    {
        dist += std::abs(colorLP[color] - colorRP[color]);
    }
    return (dist / 3);
}

float ADCensusCV::census(int wL, int hL, int wR, int hR) const
{
    float dist = 0;
    const cv::Vec3b &colorRefL = leftImage.at<cv::Vec3b>(hL, wL);
    const cv::Vec3b &colorRefR = rightImage.at<cv::Vec3b>(hR, wR);

    for(int h = -censusWin.height / 2; h <= censusWin.height / 2; ++h)
    {
        for(int w = -censusWin.width / 2; w <= censusWin.width / 2; ++w)
        {
            const cv::Vec3b &colorLP = leftImage.at<cv::Vec3b>(hL + h, wL + w);
            const cv::Vec3b &colorRP = rightImage.at<cv::Vec3b>(hR + h, wR + w);
            for(uchar color = 0; color < 3; ++color)
            {
                // bool diff = (colorLP[color] < colorRefL[color]) ^ (colorRP[color] < colorRefR[color]);
                bool diff = (colorLP[color] - colorRefL[color]) * (colorRP[color] - colorRefR[color]) < 0;
                dist += (diff)? 1: 0;
            }
        }
    }

    return dist;
}

float ADCensusCV::adCensus(int wL, int hL, int wR, int hR) const
{
    float dist;

    // compute Absolute Difference cost
    float cAD = ad(wL, hL, wR, hR);

    // compute Census cost
    float cCensus = census(wL, hL, wR, hR);

    // combine the two costs
    dist = 1 - exp(-cAD / lambdaAD);
    dist += 1 - exp(-cCensus / lambdaCensus);

    return dist;
}
