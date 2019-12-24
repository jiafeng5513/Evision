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

#include "disparityrefinement.h"
#include <opencv2/opencv.hpp>
//#include <opencv2/core/matx.hpp>
//#include <opencv2/core/mat.hpp>
//#include <opencv2/videostab/ring_buffer.hpp>

const int DisparityRefinement::DISP_OCCLUSION = 1;
const int DisparityRefinement::DISP_MISMATCH = 2;

DisparityRefinement::DisparityRefinement(uint dispTolerance, int dMin, int dMax,
                                         uint votingThreshold, float votingRatioThreshold, uint maxSearchDepth,
                                         uint blurKernelSize, uint cannyThreshold1, uint cannyThreshold2, uint cannyKernelSize)
{
    this->occlusionValue = dMin - DISP_OCCLUSION;
    this->mismatchValue = dMin - DISP_MISMATCH;
    this->dispTolerance = dispTolerance;
    this->dMin = dMin;
    this->dMax = dMax;
    this->votingThreshold = votingThreshold;
    this->votingRatioThreshold = votingRatioThreshold;
    this->maxSearchDepth = maxSearchDepth;
    this->blurKernelSize = blurKernelSize;
    this->cannyThreshold1 = cannyThreshold1;
    this->cannyThreshold2 = cannyThreshold2;
    this->cannyKernelSize = cannyKernelSize;
}

int DisparityRefinement::colorDiff(const cv::Vec3b &p1, const cv::Vec3b &p2)
{
    int colorDiff, diff = 0;

    for(uchar color = 0; color < 3; color++)
    {
        colorDiff = std::abs(p1[color] - p2[color]);
        diff = (diff > colorDiff)? diff: colorDiff;
    }

    return diff;
}

cv::Mat DisparityRefinement::outlierElimination(const cv::Mat &leftDisp, const cv::Mat &rightDisp)
{
	cv::Size dispSize = leftDisp.size();
	cv::Mat disparityMap(dispSize, CV_32S);

    //#pragma omp parallel for
    for(int h = 0; h < dispSize.height; h++)
    {
        for(int w = 0; w < dispSize.width; w++)
        {
            int disparity = leftDisp.at<int>(h, w);

            // if the point is an outlier, differentiate it between occlusion and mismatch
            if(w - disparity < 0 || abs(disparity - rightDisp.at<int>(h, w - disparity)) > dispTolerance)
            {
                bool occlusion = true;
                for(int d = dMin; d <= dMax && occlusion; d++)
                {
                    if(w - d >= 0 && d == rightDisp.at<int>(h, w - d))
                    {
                        occlusion = false;
                    }
                }
                disparity = (occlusion)? occlusionValue: mismatchValue;
            }

            disparityMap.at<int>(h, w) = disparity;
        }
    }

    return disparityMap;
}

void DisparityRefinement::regionVoting(cv::Mat &disparity, const std::vector<cv::Mat> &upLimits, const std::vector<cv::Mat> &downLimits,
                                       const std::vector<cv::Mat> &leftLimits, const std::vector<cv::Mat> &rightLimits, bool horizontalFirst)
{
    // temporary disparity map that avoids too fast correction
	cv::Size dispSize = disparity.size();
    cv::Mat dispTemp(dispSize, CV_32S);

    // histogram for voting
    std::vector<int> hist(dMax - dMin + 1, 0);

    const cv::Mat *outerLimitsA, *outerLimitsB;
    const cv::Mat *innerLimitsA, *innerLimitsB;

    if(horizontalFirst)
    {
        outerLimitsA = &upLimits[0];
        outerLimitsB = &downLimits[0];
        innerLimitsA = &leftLimits[0];
        innerLimitsB = &rightLimits[0];
    }
    else
    {
        outerLimitsA = &leftLimits[0];
        outerLimitsB = &rightLimits[0];
        innerLimitsA = &upLimits[0];
        innerLimitsB = &downLimits[0];
    }

    // loop on the whole picture
    for(size_t h = 0; h < dispSize.height; h++)
    {
        for(size_t w = 0; w < dispSize.width; w++)
        {
            // if the pixel is not an outlier
            if(disparity.at<int>(h, w) >= dMin)
            {
                dispTemp.at<int>(h, w) = disparity.at<int>(h, w);
            }
            else
            {
                int outerLimitA = -outerLimitsA->at<int>(h, w);
                int outerLimitB = outerLimitsB->at<int>(h, w);
                int innerLimitA;
                int innerLimitB;
                int vote = 0;
                for(int outer = outerLimitA; outer <= outerLimitB; outer++)
                {
                    if(horizontalFirst)
                    {
                        innerLimitA = -innerLimitsA->at<int>(h + outer, w);
                        innerLimitB = innerLimitsB->at<int>(h + outer, w);
                    }
                    else
                    {
                        innerLimitA = -innerLimitsA->at<int>(h, w + outer);
                        innerLimitB = innerLimitsB->at<int>(h, w + outer);
                    }


                    for(int inner = innerLimitA; inner <= innerLimitB; inner++)
                    {
                        int height, width;
                        if(horizontalFirst)
                        {
                            height = h + outer;
                            width = w + inner;
                        }
                        else
                        {
                            height = h + inner;
                            width = w + outer;
                        }

                        // if the pixel is an outlier, there is no vote to take into account
                        if(disparity.at<int>(height, width) >= dMin)
                        {
                            // increase the number of votes
                            vote++;
                            // update the histogram
                            hist[disparity.at<int>(height, width) - dMin] += 1;
                        }
                    }
                }

                if(vote <= votingThreshold)
                {
                    dispTemp.at<int>(h, w) = disparity.at<int>(h, w);
                }
                else
                {
                    int disp = disparity.at<int>(h, w);
                    float voteRatio;
                    float voteRatioMax = 0;
                    for(int d = dMin; d <= dMax; d++)
                    {
                        voteRatio = hist[d - dMin] / (float)vote;
                        if(voteRatio > voteRatioMax)
                        {
                            voteRatioMax = voteRatio;
                            disp = (voteRatioMax > votingRatioThreshold)? d: disp;
                        }
                        hist[d - dMin] = 0;
                    }
                    dispTemp.at<int>(h, w) = disp;
                }
            }
        }
    }

    dispTemp.copyTo(disparity);
}

void DisparityRefinement::properInterpolation(cv::Mat &disparity, const cv::Mat &leftImage)
{
	cv::Size dispSize = disparity.size();
    cv::Mat dispTemp(dispSize, CV_32S);

    // look on the 16 different directions
    int directionsW[] = {0, 2, 2, 2, 0, -2, -2, -2, 1, 2, 2, 1, -1, -2, -2, -1};
    int directionsH[] = {2, 2, 0, -2, -2, -2, 0, 2, 2, 1, -1, -2, -2, -1, 1, 2};

    // loop on the whole picture
    for(size_t h = 0; h < dispSize.height; h++)
    {
        for(size_t w = 0; w < dispSize.width; w++)
        {
            // if the pixel is not an outlier
            if(disparity.at<int>(h, w) >= dMin)
            {
                dispTemp.at<int>(h, w) = disparity.at<int>(h, w);
            }
            else
            {
                std::vector<int> neighborDisps(16, disparity.at<int>(h, w));
                std::vector<int> neighborDiffs(16, -1);
                for(uchar direction = 0; direction < 16; direction++)
                {
                    int hD = h, wD = w;
                    bool inside = true, gotDisp = false;
                    for(uchar sD = 0; sD < maxSearchDepth && inside && !gotDisp; sD++)
                    {
                        // go one step further
                        if(sD % 2 == 0)
                        {
                            hD += directionsH[direction] / 2;
                            wD += directionsW[direction] / 2;
                        }
                        else
                        {
                            hD += directionsH[direction] - directionsH[direction] / 2;
                            wD += directionsW[direction] - directionsW[direction] / 2;
                        }
                        inside = hD >= 0 && hD < dispSize.height && wD >= 0 && wD < dispSize.width;
                        if(inside && disparity.at<int>(hD, wD) >= dMin)
                        {
                            neighborDisps[direction] = disparity.at<int>(hD, wD);
                            neighborDiffs[direction] = colorDiff(leftImage.at<cv::Vec3b>(h, w), leftImage.at<cv::Vec3b>(hD, wD));
                            gotDisp = true;
                        }
                    }

                }

                if(disparity.at<int>(h, w) == dMin - DISP_OCCLUSION)
                {
                    int minDisp = neighborDisps[0];
                    for(uchar direction = 1; direction < 16; direction++)
                    {
                        if(minDisp > neighborDisps[direction])
                            minDisp = neighborDisps[direction];
                    }
                    dispTemp.at<int>(h, w) = minDisp;
                }
                else
                {
                    int minDisp = neighborDisps[0];
                    int minDiff = neighborDiffs[0];
                    for(uchar dir = 1; dir < 16; dir++)
                    {
                        if(minDiff < 0 || (minDiff > neighborDiffs[dir] && neighborDiffs[dir] > 0))
                        {
                            minDisp = neighborDisps[dir];
                            minDiff = neighborDiffs[dir];
                        }
                    }
                    dispTemp.at<int>(h, w) = minDisp;
                }
            }
        }
    }

    dispTemp.copyTo(disparity);
}

void DisparityRefinement::discontinuityAdjustment(cv::Mat &disparity, const std::vector<std::vector<cv::Mat> > &costs)
{
	cv::Size dispSize = disparity.size();
    cv::Mat dispTemp, detectedEdges, dispGray;

    disparity.copyTo(dispTemp);

    //Edge Detection
    dispGray = convertDisp2Gray(disparity);
    blur(dispGray, detectedEdges, cv::Size(blurKernelSize, blurKernelSize));
    Canny(detectedEdges, detectedEdges, cannyThreshold1, cannyThreshold2, cannyKernelSize);

    int directionsH[] = {-1, 1, -1, 1, -1, 1, 0, 0};
    int directionsW[] = {-1, 1, 0, 0, 1, -1, -1, 1};

    for(size_t h = 1; h < dispSize.height - 1; h++)
    {
        for(size_t w = 1; w < dispSize.width - 1; w++)
        {
            // if pixel is on an edge
            if(detectedEdges.at<uchar>(h, w) != 0)
            {
                int direction = -1;
                if(detectedEdges.at<uchar>(h - 1, w - 1) != 0 && detectedEdges.at<uchar>(h + 1, w + 1) != 0)
                {
                    direction = 0;
                }
                else if(detectedEdges.at<uchar>(h - 1, w + 1) != 0 && detectedEdges.at<uchar>(h + 1, w - 1) != 0)
                {
                    direction = 4;
                }
                else if(detectedEdges.at<uchar>(h - 1, w) != 0 || detectedEdges.at<uchar>(h + 1, w) != 0)
                {
                    if(detectedEdges.at<uchar>(h - 1, w - 1) != 0 || detectedEdges.at<uchar>(h - 1, w) != 0 || detectedEdges.at<uchar>(h - 1, w + 1) != 0)
                        if(detectedEdges.at<uchar>(h + 1, w - 1) != 0 || detectedEdges.at<uchar>(h + 1, w) != 0 || detectedEdges.at<uchar>(h + 1, w + 1) != 0)
                            direction = 2;
                }
                else
                {
                    if(detectedEdges.at<uchar>(h - 1, w - 1) != 0 || detectedEdges.at<uchar>(h, w - 1) != 0 || detectedEdges.at<uchar>(h + 1, w - 1) != 0)
                        if(detectedEdges.at<uchar>(h - 1, w + 1) != 0 || detectedEdges.at<uchar>(h, w + 1) != 0 || detectedEdges.at<uchar>(h + 1, w + 1) != 0)
                            direction = 6;
                }

                if (direction != -1)
                {
                    dispTemp.at<int>(h, w) = dMin - DISP_MISMATCH;

                    int disp = disparity.at<int>(h, w);

                    // select pixels from both sides of the edge
                    direction = (direction + 4) % 8;

                    if(disp >= dMin)
                    {
                        costType cost = costs[0][disp - dMin].at<costType>(h, w);
                        int d1 = disparity.at<int>(h + directionsH[direction], w + directionsW[direction]);
                        int d2 = disparity.at<int>(h + directionsH[direction + 1], w + directionsW[direction + 1]);

                        costType cost1 = (d1 >= dMin)
                                     ? costs[0][d1 - dMin].at<costType>(h + directionsH[direction], w + directionsW[direction])
                                     : -1;

                        costType cost2 = (d2 >= dMin)
                                     ? costs[0][d2 - dMin].at<costType>(h + directionsH[direction + 1], w + directionsW[direction + 1])
                                     : -1;

                        if(cost1 != -1 && cost1 < cost)
                        {
                            disp = d1;
                            cost = cost1;
                        }

                        if(cost2 != -1 && cost2 < cost)
                        {
                            disp = d2;
                        }
                    }

                    dispTemp.at<int>(h, w) = disp;

                }
            }
        }
    }

    dispTemp.copyTo(disparity);
}

cv::Mat DisparityRefinement::subpixelEnhancement(cv::Mat &disparity, const std::vector<std::vector<cv::Mat> > &costs)
{
	cv::Size dispSize = disparity.size();
    cv::Mat dispTemp(dispSize, CV_32F);

    for(size_t h = 0; h < dispSize.height; h++)
    {
        for(size_t w = 0; w < dispSize.width; w++)
        {
            int disp = disparity.at<int>(h, w);
            float interDisp = disp;

            if(disp > dMin && disp < dMax)
            {
                float cost = costs[0][disp - dMin].at<costType>(h, w) / (float)COST_FACTOR;
                float costPlus = costs[0][disp + 1 - dMin].at<costType>(h, w) / (float)COST_FACTOR;
                float costMinus = costs[0][disp - 1 - dMin].at<costType>(h, w) / (float)COST_FACTOR;

                float diff = (costPlus - costMinus) / (2 * (costPlus + costMinus - 2 * cost));

                if(diff > -1 && diff < 1)
                    interDisp -= diff;
            }

            dispTemp.at<float>(h, w) = interDisp;
        }
    }

    medianBlur(dispTemp, dispTemp, 3);
    return dispTemp;
}



cv::Mat DisparityRefinement::convertDisp2Gray(const cv::Mat &disparity)
{
	cv::Size dispSize = disparity.size();
    cv::Mat dispU(dispSize, CV_8U);

    for(size_t h = 0; h < dispSize.height; h++)
    {
        for(size_t w = 0; w < dispSize.width; w++)
        {
            dispU.at<uchar>(h, w) = (disparity.at<int>(h, w) < 0)? 0: (uchar)disparity.at<int>(h, w);
        }
    }

    equalizeHist(dispU, dispU);
    return dispU;
}
