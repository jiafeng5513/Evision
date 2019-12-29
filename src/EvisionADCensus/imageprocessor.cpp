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

#include "imageprocessor.h"
#include <limits>
#include <opencv2/opencv.hpp>

ImageProcessor::ImageProcessor(float percentageOfDeletion)
{
    this->percentageOfDeletion = percentageOfDeletion;
}

cv::Mat ImageProcessor::stretchHistogram(cv::Mat image)
{
	cv::Size imgSize = image.size();
    std::vector<cv::Mat> channels;
	cv::Mat output(imgSize, CV_8UC3);
    uint pixelThres = percentageOfDeletion * imgSize.height * imgSize.width;
    std::vector<uint> hist;
    hist.resize(std::numeric_limits<uchar>::max() + 1);


    cvtColor(image, output, cv::COLOR_BGR2YCrCb); //change the color image from BGR to YCrCb format
    split(output, channels); //split the image into channels

    uchar min = std::numeric_limits<uchar>::max();
    uchar max = 0;

    for(size_t h = 0; h < imgSize.height; h++)
    {
        for(size_t w = 0; w < imgSize.width; w++)
        {
            uchar intensity = channels[0].at<uchar>(h, w);

            if(intensity < min)
                min = intensity;
            else if(intensity > max)
                max = intensity;

            hist[intensity]++;
        }
    }

    //update minimum
    bool foundMin = false;
    uint pixels = 0;
    for(size_t i = 0; i < hist.size() && !foundMin; i++)
    {
        pixels += hist[i];
        if(pixels <= pixelThres)
            min = i;
        else
            foundMin = true;
    }

    //update maximum
    bool foundMax = false;
    pixels = 0;
    for(size_t i = hist.size() - 1; i > 0 && !foundMax; i--)
    {
        pixels += hist[i];
        if(pixels <= pixelThres)
            max = i;
        else
            foundMax = true;
    }

    for(size_t h = 0; h < imgSize.height; h++)
    {
        for(size_t w = 0; w < imgSize.width; w++)
        {
            uchar intensity = channels[0].at<uchar>(h, w);
            uchar newIntensity;

            newIntensity = (intensity <= min)
                           ? 0
                           : (intensity >= max)
                             ? std::numeric_limits<uchar>::max()
                             : (std::numeric_limits<uchar>::max() / (float)(max - min)) * (intensity - min);

            channels[0].at<uchar>(h, w) = newIntensity;
        }
    }

    merge(channels,output); //merge 3 channels including the modified 1st channel into one image
    cvtColor(output, output, cv::COLOR_YCrCb2BGR); //change the color image from YCrCb to BGR format (to display image properly)

    return output;
}

cv::Mat ImageProcessor::unsharpMasking(cv::Mat image, std::string blurMethod, int kernelSize, float alpha, float beta)
{
	cv::Mat tempImage, output;
    float gamma = 0.0;
    float gaussianDevX = 0.0;
    float gaussianDevY = 0.0;

    if (blurMethod == "gauss")
    {
        GaussianBlur(image, tempImage, cv::Size(kernelSize, kernelSize), gaussianDevX, gaussianDevY);
        addWeighted(image, alpha, tempImage, beta, gamma, output);
    }
    else if (blurMethod == "median")
    {
        medianBlur(image, tempImage, kernelSize);
        addWeighted(image, alpha, tempImage, beta, gamma, output);
    }

    return output;
}

cv::Mat ImageProcessor::laplacianSharpening(cv::Mat image, int kernelSize, float alpha, float beta)
{
	cv::Mat laplacianRes, abs_dst, output;
    int scale = 0;
    int delta = 0;
    float gamma = 0.0;

    Laplacian(image, laplacianRes, CV_8UC3, kernelSize, scale, delta, cv::BORDER_DEFAULT);
    convertScaleAbs(laplacianRes, abs_dst);
    addWeighted(image, alpha, abs_dst, beta, gamma, output);

    return output;
}
