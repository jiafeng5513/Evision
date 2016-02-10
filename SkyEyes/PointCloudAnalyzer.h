#ifndef _POINT_CLOUD_ANALYZER_H_
#define _POINT_CLOUD_ANALYZER_H_

#pragma once

#include <vector>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include "opencv2/highgui/highgui.hpp"

using namespace std;


class PointCloudAnalyzer
{
public:
	PointCloudAnalyzer(void);
	~PointCloudAnalyzer(void);

	// 物体信息 结构体
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

	/*----------------------------
	* 功能 : 检测近距目标，输出目标信息序列
	*----------------------------
	* 函数 : PointCloudAnalyzer::detectNearObject
	* 访问 : public
	* 返回 : void
	*
	* 参数 : image			[io]	左摄像机视图，会进行原位操作，绘制目标尺寸位置
	* 参数 : pointCloud		[in]	三维点云
	* 参数 : objectInfos	[out]	目标信息序列
	*/
	void detectNearObject(cv::Mat& image, cv::Mat& pointCloud, vector<ObjectInfo>& objectInfos);
	/*----------------------------
	* 功能 : 绘制近距物体尺寸和位置
	*----------------------------
	* 函数 : PointCloudAnalyzer::showObjectInfo
	* 访问 : private
	* 返回 : void
	*
	* 参数 : objectInfos	[in]	近距物体信息序列
	* 参数 : outImage		[io]	左摄像头图像，在该图像上绘制近距物体信息
	*/
	void showObjectInfo(vector<ObjectInfo>& objectInfos, cv::Mat& outImage);

private:

	/*----------------------------
	* 功能 : 图像去噪
	*----------------------------
	* 函数 : PointCloudAnalyzer::imageDenoising
	* 访问 : private
	* 返回 : void
	*
	* 参数 : img	[in]	待处理图像，原位操作
	* 参数 : iters	[in]	形态学处理次数
	*/
	void imageDenoising(cv::Mat& img, int iters);

	/*----------------------------
	* 功能 : 生成近距物体信息序列
	*----------------------------
	* 函数 : PointCloudAnalyzer::parseCandidates
	* 访问 : private
	* 返回 : void
	*
	* 参数 : objects		[in]	深度阈值化后的二值图像，显示了近距物体的分布
	* 参数 : depthMap		[in]	从三维点云矩阵中抽取的深度数据矩阵
	* 参数 : objectInfos	[out]	目标信息序列
	*/
	void parseCandidates(cv::Mat& objects, cv::Mat& depthMap, vector<ObjectInfo>& objectInfos);



};

#endif