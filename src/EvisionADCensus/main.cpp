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

#include <iostream>
#include "stereoprocessor.h"
//#include <libconfig.h++>
#include "imageprocessor.h"
#include <cstdlib>
#include <boost/filesystem.hpp>
#include <boost/date_time.hpp>
#include <iomanip>

#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>

using namespace std;

bool loadImageList(string file, vector<string> &list)
{
    bool loadSuccess = false;
	cv::FileNode fNode;
	cv::FileStorage fStorage(file, cv::FileStorage::READ);

    if (fStorage.isOpened())
    {
        fNode = fStorage.getFirstTopLevelNode();

        if (fNode.type() == cv::FileNode::SEQ)
        {
            for(cv::FileNodeIterator iterator = fNode.begin(); iterator != fNode.end(); ++iterator)
            {
                list.push_back((string) *iterator);
            }

            loadSuccess = true;
        }
    }

    return loadSuccess;
}

bool loadImages(vector<string> fileList, vector<cv::Mat> &images)
{
    bool emptyImage = false;
    for (int i = 0; i < fileList.size() && !emptyImage; ++i)
    {
        cv::Mat curImg = cv::imread(fileList[i]);
        if (!curImg.empty())
        {
            images.push_back(curImg);
        }
        else
        {
            emptyImage = true;
        }
    }

    return (!emptyImage && images.size() > 0);
}

bool loadQMatrix(string file, cv::Mat &Q)
{
    bool success = false;
    try
    {
		cv::FileStorage fStorage(file.c_str(), cv::FileStorage::READ);
        fStorage["Q"] >> Q;
        fStorage.release();
        success = true;
    }
    catch(cv::Exception ex)
    {
    }

    return success;
}

void createAndSavePointCloud(cv::Mat &disparity, cv::Mat &leftImage, cv::Mat &Q, string filename)
{
    pcl::PointCloud<pcl::PointXYZRGB> pointCloud;

    // Read out Q Values for faster access
    double Q03 = Q.at<double>(0, 3);
    double Q13 = Q.at<double>(1, 3);
    double Q23 = Q.at<double>(2, 3);
    double Q32 = Q.at<double>(3, 2);
    double Q33 = Q.at<double>(3, 3);

    for (int i = 0; i < disparity.rows; i++)
    {
        for (int j = 0; j < disparity.cols; j++)
        {
            // Create a new point
            pcl::PointXYZRGB point;

            // Read disparity
            float d = disparity.at<float>(i, j);
            if ( d <= 0 ) continue; //Discard bad pixels

            // Read color
			cv::Vec3b colorValue = leftImage.at<cv::Vec3b>(i, j);
            point.r = static_cast<int>(colorValue[2]);
            point.g = static_cast<int>(colorValue[1]);
            point.b = static_cast<int>(colorValue[0]);

            // Transform 2D -> 3D and normalise to point
            double x = Q03 + j;
            double y = Q13 + i;
            double z = Q23;
            double w = (Q32 * d) + Q33;
            point.x = -x / w;
            point.y = -y / w;
            point.z = z / w;

            // Put point into the cloud
            pointCloud.points.push_back (point);
        }
    }

    // Resize PCL and save to file
    pointCloud.width = pointCloud.points.size();
    pointCloud.height = 1;
    pcl::io::savePCDFileASCII(filename, pointCloud);
}

//int main(int argc, char *argv[])
//{
//	bool success = false;
//
//	string xmlImages = "E:/VisualStudio/ADCensusBM/test/images_ADCensusBM.xml";
//	string ymlExtrinsic = "E:/VisualStudio/ADCensusBM/test//extrinsics.yml";
//	string savePath = "E:/VisualStudio/ADCensusBM/test/results/";
//
//	// Minimum and maximum disparity
//	uint dMin = 0;
//	uint dMax = 60;
//
//	// Parameters for the cost-initialization for the ADCensus
//	cv::Size censusWin;
//	censusWin.height = 9;
//	censusWin.width = 7;
//	float defaultBorderCost = 0.999;
//	float lambdaAD = 10.0; // TODO Namen anpassen
//	float lambdaCensus = 30.0;
//
//	
//	// Parameters for the cross-based cost aggregation
//	uint aggregatingIterations = 4;
//	uint colorThreshold1 = 20;
//	uint colorThreshold2 = 6;
//	uint maxLength1 = 34;
//	uint maxLength2 = 17;
//
//	// Parameters for the optimization of image cells
//	uint colorDifference = 15;
//	float pi1 = 0.1;
//	float pi2 = 0.3;
//
//	// Parameters for outlier detection
//	uint dispTolerance = 0;
//	// Parameters for the iterative range rating
//	uint votingThreshold = 20;
//	float votingRatioThreshold = 4;
//
//	// Parameters for the proper interpolation
//	uint maxSearchDepth = 20;
//
//	// Parameters for the approximation of depths discontinuities 
//	uint cannyThreshold1 = 20;
//	uint cannyThreshold2 = 60;
//	uint cannyKernelSize = 3;
//
//	// Parameters for the sub-pixel enhancement
//	uint blurKernelSize = 3;
//
//	vector<string> fileList;
//	vector<cv::Mat> images;
//	cv::Mat Q(4, 4, CV_64F);
//
//	boost::filesystem::path dir(savePath);
//	boost::filesystem::create_directories(dir);
//
//	bool gotExtrinsic = loadQMatrix(ymlExtrinsic, Q);
//	if (loadImageList(xmlImages, fileList))
//	{
//		if (loadImages(fileList, images))
//		{
//			if (images.size() % 2 == 0)
//			{
//				bool error = false;
//				for (int i = 0; i < (images.size() / 2) && !error; ++i)
//				{
//					stringstream file;
//					file << savePath << i;
//					boost::posix_time::ptime start = boost::posix_time::second_clock::local_time();
//					boost::posix_time::ptime end;
//					boost::posix_time::time_duration diff;
//
//					ImageProcessor iP(0.1);
//					cv::Mat eLeft, eRight;
//					eLeft = iP.unsharpMasking(images[i * 2], "gauss", 3, 1.9, -1);
//					eRight = iP.unsharpMasking(images[i * 2 + 1], "gauss", 3, 1.9, -1);
//
//					StereoProcessor sP(dMin, dMax, images[i * 2], images[i * 2 + 1], censusWin, defaultBorderCost, lambdaAD, lambdaCensus, file.str(),
//						aggregatingIterations, colorThreshold1, colorThreshold2, maxLength1, maxLength2,
//						colorDifference, pi1, pi2, dispTolerance, votingThreshold, votingRatioThreshold,
//						maxSearchDepth, blurKernelSize, cannyThreshold1, cannyThreshold2, cannyKernelSize);
//					string errorMsg;
//					error = !sP.init(errorMsg);
//
//					if (!error && sP.compute())
//					{
//						success = true;
//						if (gotExtrinsic)
//						{
//							cv::Mat disp = sP.getDisparity();
//
//							string dispFile = file.str();
//							dispFile += "_disp.yml";
//							cv::FileStorage fs(dispFile, cv::FileStorage::WRITE);
//							fs << "disp" << disp;
//							fs.release();
//
//							file << "_cloud.pcd";
//							createAndSavePointCloud(disp, images[i * 2], Q, file.str());
//						}
//						else
//						{
//							cerr << "[ADCensusCV] Could not create point cloud (no extrinsic)!" << endl;
//						}
//					}
//					else
//					{
//						cerr << "[ADCensusCV] " << errorMsg << endl;
//					}
//
//					end = boost::posix_time::second_clock::local_time();
//
//					diff = end - start;
//
//					cout << "Finished computation after " << setw(2) << right << setfill('0') << ((int)(diff.total_seconds() / 3600)) << ":"
//						<< setw(2) << right << setfill('0') << ((int)((diff.total_seconds() / 60) % 60)) << ":"
//						<< setw(2) << right << setfill('0') << (diff.total_seconds() % 60) << " (" << diff.total_seconds() << "s) !" << endl;
//
//				}
//			}
//			else
//			{
//				cerr << "[ADCensusCV] Not an even image number!" << endl;
//			}
//		}
//		else
//		{
//			cerr << "[ADCensusCV] Could not read images!" << endl;
//		}
//	}
//	else
//	{
//		cerr << "[ADCensusCV] Could not read image list!" << endl;
//	}
//
//
//
//	return (success) ? EXIT_SUCCESS : EXIT_FAILURE;
//}

