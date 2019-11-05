#pragma once
//#include <pcl/impl/point_types.hpp>
#include <pcl/point_cloud.h>
#include <pcl/common/copy_point.h>
#include <QtOpenGL>

class CloudAnalyzer
{
public:
	CloudAnalyzer();
	~CloudAnalyzer();
	char* Substrend(std::string str, int n);

	std::vector<std::vector<GLfloat>> bbox(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);

public:
	pcl::PointCloud<pcl::PointXYZ>::Ptr openCloudFile(std::string  filename);

	void analyzer(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);
};

