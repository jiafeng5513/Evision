#include "EvisionCloudViewerFactory.h"
#include "CloudGLWidget.h"
#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/common/common.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/features/normal_3d.h>
#include <pcl/search/kdtree.h>
#include <pcl/surface/gp3.h>

EvisionCloudViewerFactory::EvisionCloudViewerFactory()
{
}

QWidget* EvisionCloudViewerFactory::CreateEvisionEvisionCloudViewer(std::string filename, QWidget* parent)
{
	if (!QGLFormat::hasOpenGL()) {
		std::cerr << "This system has no OpenGL support" << std::endl;
		return NULL;
	}

	CloudGLWidget *cube=new CloudGLWidget(filename,parent);
	cube->setWindowTitle(QObject::tr("Vowel Cube"));
	cube->setMinimumSize(200, 200);
	cube->resize(450, 450);
	return cube;
}

void EvisionCloudViewerFactory::createAndSavePointCloud(cv::Mat & disparity, cv::Mat & leftImage, cv::Mat & Q, std::string filename)
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
			if (d <= 0) continue; //Discard bad pixels

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
			pointCloud.points.push_back(point);
		}
	}

	// Resize PCL and save to file
	pointCloud.width = pointCloud.points.size();
	pointCloud.height = 1;
	pcl::io::savePCDFileASCII(filename, pointCloud);
}
