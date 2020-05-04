#include <Utils.h>
#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

/*
输入:左视图和原始视差数据,相机标定数据文件
操作:标点,获得相机坐标系坐标,转换为世界坐标,
     按顺序标完4个点,计算长宽高
     询问是否修正
     修正完毕,生产PLY
     这道程序的任务就完成
输出:PLY网格文件
*/ 


int main(int argc, char const *argv[])
{
    std::string cameraParamFile = "";
    std::string leftImgFile = "";
    std::string RawDispFile = "";

    //step 1 :打开文件,读取Q矩阵,左图,原始视差数据
    cv::Mat Q, img, RawDisp;
    cv::FileStorage fStorage(cameraParamFile, cv::FileStorage::READ);
    fStorage["Q"] >> Q;
    fStorage.release();
    img = cv::imread(leftImgFile);
    cv::FileStorage fStorage(RawDispFile, cv::FileStorage::READ);
    fStorage["disp"] >> RawDisp;

    //step 2: 标点,获得四个图像坐标

    //step 3: 获取四个图像坐标对应的世界坐标

    //step 4: 计算长宽高

    //step 5: 询问修正

    //step 6: 输出ply
    std::vector<float> size;
    size.push_back(5);
    size.push_back(6);
    size.push_back(7);
    createCubePly(size, "E:/VisualStudio/Tracker/VideoTracker/Data/test_reg/cube_cpp.ply");

    return 0;
}


//void EvisionCloudViewerFactory::createAndSavePointCloud(cv::Mat& disparity, cv::Mat& leftImage, cv::Mat& Q, std::string filename)
//{
//	pcl::PointCloud<pcl::PointXYZRGB> pointCloud;
//
//	// Read out Q Values for faster access
//	double Q03 = Q.at<double>(0, 3);
//	double Q13 = Q.at<double>(1, 3);
//	double Q23 = Q.at<double>(2, 3);
//	double Q32 = Q.at<double>(3, 2);
//	double Q33 = Q.at<double>(3, 3);
//
//	for (int i = 0; i < disparity.rows; i++)
//	{
//		for (int j = 0; j < disparity.cols; j++)
//		{
//			// Create a new point
//			pcl::PointXYZRGB point;
//
//			// Read disparity
//			float d = disparity.at<float>(i, j);
//			if (d <= 0) continue; //Discard bad pixels
//
//			// Read color
//			cv::Vec3b colorValue = leftImage.at<cv::Vec3b>(i, j);
//			point.r = static_cast<int>(colorValue[2]);
//			point.g = static_cast<int>(colorValue[1]);
//			point.b = static_cast<int>(colorValue[0]);
//
//			// Transform 2D -> 3D and normalise to point
//			double x = Q03 + j;
//			double y = Q13 + i;
//			double z = Q23;
//			double w = (Q32 * d) + Q33;
//			point.x = -x / w;
//			point.y = -y / w;
//			point.z = z / w;
//
//			// Put point into the cloud
//			pointCloud.points.push_back(point);
//		}
//	}
//
//	// Resize PCL and save to file
//	pointCloud.width = pointCloud.points.size();
//	pointCloud.height = 1;
//	pcl::io::savePCDFileASCII(filename, pointCloud);
//}
