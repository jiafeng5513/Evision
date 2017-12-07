
#include "StdAfx.h"
#include "PointCloudAnalyzer.h"
#include "calib.h"
#include "MainFrm.h"

PointCloudAnalyzer::PointCloudAnalyzer(void)
{
}


PointCloudAnalyzer::~PointCloudAnalyzer(void)
{
}


/*----------------------------
* 功能 : 检测近距目标，输出目标信息序列
*----------------------------
* 函数 : PointCloudAnalyzer::detectNearObject
* 访问 : public
* 返回 : 是否成功
*
* 参数 : image			[io]	左摄像机视图，会进行原位操作，绘制目标尺寸位置
* 参数 : pointCloud		[in]	三维点云
* 参数 : objectInfos	[out]	目标信息序列

*/
int PointCloudAnalyzer::detectNearObject(cv::Mat& image, cv::Mat& pointCloud, vector<ObjectInfo>& objectInfos)
{
	if (image.empty() || pointCloud.empty())
	{
		return 0;
	}

	// 提取深度图像
	vector<cv::Mat> xyzSet;
	split(pointCloud, xyzSet);
	cv::Mat depth;
	xyzSet[2].copyTo(depth);
	// 根据深度阈值进行二值化处理
	double maxVal = 0, minVal = 0;
	cv::Mat depthThresh = cv::Mat::zeros(depth.rows, depth.cols, CV_8UC1);
	cv::minMaxLoc(depth, &minVal, &maxVal);//找到depth中的最小值和最大值
	threshold(depth, depthThresh, 125, 255, CV_THRESH_BINARY_INV);//  "http://baike.baidu.com/view/3586026.htm"
	//	threshold(depth, depthThresh,80, 255, CV_THRESH_BINARY_INV);
	depthThresh.convertTo(depthThresh, CV_8UC1);
	imageDenoising(depthThresh, 3);
	parseCandidates(depthThresh, depth, objectInfos);
	if (depthThresh.empty()){
		AfxMessageBox(_T("object为空!"));
		return 0;
	}
	if (objectInfos.empty()){
		AfxMessageBox(_T("objectInfos为空!"));
		return 0;
	}
	// 绘制物体分布
	showObjectInfo(objectInfos, image);
	return 1;
}


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
void PointCloudAnalyzer::imageDenoising(cv::Mat& img, int iters)
{
	cv::Mat pyr = cv::Mat(img.cols / 2, img.rows / 2, img.type());

	IplImage iplImg = img;
	cvSmooth(&iplImg, &iplImg, CV_GAUSSIAN, 3, 3);	// 平滑滤波CV_GAUSSIAN (gaussian blur) - 对图像进行核大小为 param1×param2 的高斯卷积
	GaussianBlur(img, img, Size(3, 3), 0, 0, BORDER_DEFAULT);
	pyrDown(img, pyr);	// 对平滑后的图像进行二次缩放
	pyrUp(pyr, img);

	erode(img, img, 0, cv::Point(-1, -1), iters);	// 图像腐蚀开运算，去除小明亮区域
	dilate(img, img, 0, cv::Point(-1, -1), iters);	// 图像膨胀
	/*	int dilation_type;
	int dilation_size=20;
	dilation_type = MORPH_RECT;
	Mat element = getStructuringElement( dilation_type,
	Size( 2*dilation_size + 1, 2*dilation_size+1 ),
	Point( dilation_size, dilation_size ) );
	erode(img, img,element);
	dilate(img, img,element);	// 图像膨胀*/

}


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
void PointCloudAnalyzer::parseCandidates(cv::Mat& objects, cv::Mat& depthMap, vector<ObjectInfo>& objectInfos)
{
	// 提取物体轮廓
	//	Mat canny_output;
	vector<vector<cv::Point> > contours;	// 物体轮廓点链
	//	vector<Vec4i>hierarchy;
	cv::Mat tempobjects = objects;
	/// 用Canny算子检测边缘
	//    Canny( tempobjects, canny_output, 80, 160, 3 );
	findContours(tempobjects, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	/*	Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ )
	{
	Scalar color = Scalar(0, 233, 0);
	drawContours( drawing, contours, i, color, 2, 8);
	}

	/// 在窗体中显示结果
	namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
	imshow( "Contours", drawing );*/
	//	findContours(objects, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	//	findContours(objects,contours,hierarchy,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	/*
	findContours后的轮廓信息contours可能过于复杂不平滑，可以用approxPolyDP函数对该多边形曲线做适当近似
	contourArea函数可以得到当前轮廓包含区域的大小，方便轮廓的筛选
	findContours经常与drawContours配合使用，用来将轮廓绘制出来。
	其中第一个参数image表示目标图像，第二个参数contours表示输入的轮廓组，每一组轮廓由点vector构成，
	第三个参数contourIdx指明画第几个轮廓，如果该参数为负值，则画全部轮廓，第四个参数color为轮廓的颜色，
	第五个参数thickness为轮廓的线宽，如果为负值或CV_FILLED表示填充轮廓内部，第六个参数lineType为线型，
	第七个参数为轮廓结构信息，第八个参数为maxLevel*/
	// 分析轮廓
	double areaThresh = 0.005 * depthMap.rows * depthMap.cols;
	cv::Mat mask = cv::Mat::zeros(objects.size(), CV_8UC1);////1
	bool useMeanDepth = false;
	//	CString str;
	//	str.Format(_T("%d"),contours.size());
	//			AfxMessageBox(str);
	for (UINT objID = 0; objID < contours.size(); objID++)//得出每个轮廓的信息
	{
		cv::Mat contour = cv::Mat(contours[objID]);
		double area = contourArea(contour);//计算轮廓面积
		if (area>0)
		{
			ObjectInfo object;
			// 填充物体内部轮廓作为掩码区域
			mask = cv::Scalar(0);
			drawContours(mask, contours, objID, cv::Scalar(255), -1);
			/*
			用来将轮廓绘制出来。其中第一个参数image表示目标图像，
			第二个参数contours表示输入的轮廓组，每一组轮廓由点vector构成，
			第三个参数contourIdx指明画第几个轮廓，如果该参数为负值，
			则画全部轮廓，第四个参数color为轮廓的颜色，
			第五个参数thickness为轮廓的线宽，
			如果为负值或CV_FILLED表示填充轮廓内部，
			第六个参数lineType为线型，第七个参数为轮廓结构信息，第八个参数为maxLevel
			*/
			double minVal = 0, maxVal = 0;
			cv::Point minPos;
			cv::minMaxLoc(depthMap, &minVal, &maxVal, &minPos, NULL, mask);
			object.distance = depthMap.at<float>(minPos.y, minPos.x);
			//			}
			// 计算轮廓矩形
			object.boundRect = boundingRect(contour);//计算点集的最外面（up-right）矩形边界
			object.minRect = minAreaRect(contour);
			object.center = object.minRect.center;

			// 保存物体轮廓信息
			objectInfos.push_back(object);
		}
	}

	// 按物体距离重新排序
	//std::sort( objectInfos.begin(), objectInfos.end(), std::greater<ObjectInfo>() );
}

void PointCloudAnalyzer::showObjectInfo(vector<ObjectInfo>& objectInfos, cv::Mat& outImage)
{
	int showCount = objectInfos.size() < 5 ? objectInfos.size() : 5;

	// 画出所有靠近的物体
	for (int i = 0; i < showCount; i++)
	{
		//物体中心
		circle(outImage, objectInfos[i].center, 3, CV_RGB(0, 0, 255), 2);

		//物体最小外接矩形
		cv::Point2f rect_points[4];
		//		objectInfos[i].minRect.points( rect_points );
		objectInfos[i].minRect.points(rect_points);
		//		rectangle(outImage,objectInfos[i].boundRect,CV_RGB(0,0,255),2);
		if (i == 0)
		{
			for (int j = 0; j < 4; j++)
				line(outImage, rect_points[j], rect_points[(j + 1) % 4], CV_RGB(255, 0, 0), 4);
		}
		else
		{
			for (int j = 0; j < 4; j++)
				line(outImage, rect_points[j], rect_points[(j + 1) % 4], CV_RGB(255 - i * 40, i * 40, 0), 2);
		}
	}
}