#include "CloudAnalyzer.h"
#include <iostream>
#include <pcl/ModelCoefficients.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/project_inliers.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/segmentation/extract_clusters.h>
#include <Eigen/Core>
#include <pcl/common/transforms.h>
#include <pcl/common/common.h>
#include <pcl/common/time.h>
#include <pcl/common/angles.h>
#include <pcl/registration/transformation_estimation_svd.h>
CloudAnalyzer::CloudAnalyzer()
{
}


CloudAnalyzer::~CloudAnalyzer()
{
}

char* CloudAnalyzer::Substrend(std::string str, int n)
{
	char* substr = (char*)malloc(n + 1);
	int length = str.length();
	if (n >= length)
	{
		strcpy(substr, str.c_str());
		return substr;
	}
	int k = 0;
	for (int i = length - n; i < length; i++)
	{
		substr[k] = str[i];
		k++;
	}
	substr[k] = '\0';
	return substr;
}
//
//                
//	    V4 ---------- V6
//        |\        |\
//        | \_______|_\ V7
//        | V5      | |
//      V0|_|_ _ _ _|V2
//        \ |       \ |
//         \|________\|
//         V1         V3
/*
 * 最少6个点就能确定一个立方体
 * 上边标的是
 */
std::vector<std::vector<GLfloat>> CloudAnalyzer::bbox(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
	pcl::PointXYZ min_p, max_p;
	pcl::getMinMax3D(*cloud, min_p, max_p);//求点云在xyz方向上的最大最小值
	//Eigen::Vector3f c1 = 0.5f*(min_p->getVector3fMap() + max_p->getVector3fMap());//几何中心
	//min_p1中是xyz三个方向的最小值,max_p1中是xyz三个方向的最大值
	std::vector<std::vector<GLfloat>> result;
	result.push_back({ min_p.x,min_p.y,min_p.z });//3   //0
	result.push_back({ max_p.x,min_p.y,min_p.z });//0	//1
	result.push_back({ min_p.x,max_p.y,min_p.z });//2	//2
	result.push_back({ max_p.x,max_p.y,min_p.z });//1	//3
	result.push_back({ min_p.x,min_p.y,max_p.z });//7	//4
	result.push_back({ max_p.x,min_p.y,max_p.z });//4	//5
	result.push_back({ min_p.x,max_p.y,max_p.z });//6	//6
	result.push_back({ max_p.x,max_p.y,max_p.z });//5	//7



	return result;
}

pcl::PointCloud<pcl::PointXYZ>::Ptr CloudAnalyzer::openCloudFile(std::string filename)
{
	// load data
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
	char* fileType;
	if (!filename.empty())
	{
		fileType = Substrend(filename.data(), 3);
	}
	else
	{
		return cloud;
	}

	if (!strcmp(fileType, "pcd"))
	{
		// load pcd file
		pcl::io::loadPCDFile(filename, *cloud);
	}
	else if (!strcmp(fileType, "txt"))
	{
		// load txt data file	
		double x = 0.0, y = 0.0, z = 0.0;
		FILE *fp_txt = fopen(filename.c_str(), "r");
		int num = 0;
		if (fp_txt)
		{
			while (fscanf(fp_txt, "%lf %lf %lf", &x, &y, &z) != EOF)
			{
				cloud->points[num].x = x;
				cloud->points[num].y = y;
				cloud->points[num].z = z;
				num++;
			}
		}
		else
		{
			std::cout << "txt数据加载失败！" << std::endl;
			return cloud;
		}
	}
	else
	{
		std::cout << "please input data file name" << std::endl;
		return cloud;
	}

	return cloud;
}


