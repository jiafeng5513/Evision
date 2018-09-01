#pragma once
#include <core/types.hpp>
#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include "opencv2/highgui/highgui.hpp"
/*
 * 实现三维点云分析的相关操作
 */
class PointCloudUtils
{
public:
	PointCloudUtils();
	~PointCloudUtils();
	struct ObjectInfo
	{
		cv::Point		center;		//中心
		double			distance;	//距离
		double			area;		//面积
		cv::Rect		boundRect;	//外接矩形
		cv::RotatedRect minRect;	//最小矩形

		// 定义赋值操作
		void operator = (const ObjectInfo& rhs)
		{
			center = rhs.center;
			distance = rhs.distance;
			area = rhs.area;
			boundRect = rhs.boundRect;
			minRect = rhs.minRect;
		}

		// 按照距离定义排序规则
		bool operator < (const ObjectInfo& rhs) const   //升序排序时必须写的函数
		{
			return distance < rhs.distance;
		}
		bool operator >(const ObjectInfo& rhs) const   //降序排序时必须写的函数
		{
			return distance > rhs.distance;
		}

	};

	int detectNearObject(cv::Mat& image, cv::Mat& pointCloud, std::vector<ObjectInfo>& objectInfos);
	void showObjectInfo(std::vector<ObjectInfo>& objectInfos, cv::Mat& outImage);

private:

	void imageDenoising(cv::Mat& img, int iters);
	void parseCandidates(cv::Mat& objects, cv::Mat& depthMap, std::vector<ObjectInfo>& objectInfos);
};

