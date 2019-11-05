#include "Evision3dVizFactory.h"
#include "Evision3dViz.h"


Evision3dVizFactory::Evision3dVizFactory()
{
}


Evision3dVizFactory::~Evision3dVizFactory()
{
}

QWidget* Evision3dVizFactory::CreateEvision3dViz(QWidget* parent)
{
	return new Evision3dViz(parent);
}

void Evision3dVizFactory::createAndSavePointCloud(cv::Mat& disparity, cv::Mat& leftImage, cv::Mat& Q,
	std::string filename)
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