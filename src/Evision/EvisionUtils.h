#pragma once
#include <qimage.h>
#include "opencv2\core\core.hpp"
#include "cv.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QGraphicsView>
#include <QGraphicsScene>

/*
 * 实用工具方法
 */
class EvisionUtils
{
public:
	EvisionUtils();
	~EvisionUtils();
	/*
	 * cv::Mat转换为QImage
	 */
	static QImage cvMat2QImage(const cv::Mat& mat);

	/*
	 * QImage转换为cv::Mat
	 */
	static cv::Mat QImage2cvMat(QImage image);

	/*
	 * 把img显示在view上
	 */
	static void ShowImageOnUi(cv::Mat& img, QGraphicsScene*sense, QGraphicsView* view);
	/*
	 * 把双目标定得到的所有参数写入文件
	 * 1.文件名							std::string filename
	 * 2.相机矩阵1(相对焦距和主点坐标)	cv::Mat& cameraMatrix1
	 * 3.畸变系数1						cv::Mat& distCoeffs1
	 * 4.相机矩阵2						cv::Mat& cameraMatrix2
	 * 5.畸变系数2						cv::Mat& distCoeffs2
	 * 6.两个相机之间的旋转				cv::Mat& R
	 * 7.两个相机之间的平移				cv::Mat& T
	 * 8.本质矩阵						cv::Mat& E
	 * 9.基本矩阵						cv::Mat& F
	 * 10.图片尺寸						cv::Size& imageSize,
	 * 11.旋转映射矩阵1                 cv::Mat& R1,
	 * 12.投影映射矩阵1                 cv::Mat& P1,
	 * 13.旋转映射矩阵2                 cv::Mat& R2,
	 * 14.投影映射矩阵2                 cv::Mat& P2,
	 * 15.三维映射矩阵                  cv::Mat& Q,
	 * 16.矫正后的roi1                  cv::Rect& roi1,
	 * 17.矫正后的roi2                  cv::Rect& roi2
	 * 返回值:
	 *	成功:true,失败和出错:false
	 */
	static bool write_AllCameraParams(std::string& filename,
		cv::Mat& cameraMatrix1,
		cv::Mat& distCoeffs1,
		cv::Mat& cameraMatrix2,
		cv::Mat& distCoeffs2,
		cv::Mat& R,
		cv::Mat& T,
		cv::Mat& E,
		cv::Mat& F,
		cv::Size& imageSize,
		cv::Mat& R1,
		cv::Mat& P1,
		cv::Mat& R2,
		cv::Mat& P2,
		cv::Mat& Q,
		cv::Rect& roi1,
		cv::Rect& roi2);

	/*
	 * 从文件中读取双目标定得到的参数
	 * 1.文件名							std::string filename
	 * 2.相机矩阵1(相对焦距和主点坐标)	cv::Mat* cameraMatrix1
	 * 3.畸变系数1						cv::Mat* distCoeffs1
	 * 4.相机矩阵2						cv::Mat* cameraMatrix2
	 * 5.畸变系数2						cv::Mat* distCoeffs2
	 * 6.两个相机之间的旋转				cv::Mat* R
	 * 7.两个相机之间的平移				cv::Mat* T
	 * 8.本质矩阵						cv::Mat* E
	 * 9.基本矩阵						cv::Mat* F
	 * 10.图片尺寸						cv::Size* imageSize,
	 * 11.旋转映射矩阵1                 cv::Mat* R1,
	 * 12.投影映射矩阵1                 cv::Mat* P1,
	 * 13.旋转映射矩阵2                 cv::Mat* R2,
	 * 14.投影映射矩阵2                 cv::Mat* P2,
	 * 15.三维映射矩阵                  cv::Mat* Q,
	 * 16.矫正后的roi1                  cv::Rect* roi1,
	 * 17.矫正后的roi2                  cv::Rect* roi2
	 * 返回值:
	 *	成功:true,失败和出错:false
	 */
	static bool read_AllCameraParams(std::string& filename,
		cv::Mat* cameraMatrix1,
		cv::Mat* distCoeffs1,
		cv::Mat* cameraMatrix2,
		cv::Mat* distCoeffs2,
		cv::Mat* R,
		cv::Mat* T,
		cv::Mat* E,
		cv::Mat* F,
		cv::Size* imageSize,
		cv::Mat* R1,
		cv::Mat* P1,
		cv::Mat* R2,
		cv::Mat* P2,
		cv::Mat* Q,
		cv::Rect* roi1,
		cv::Rect* roi2);

	/*
	 * 读取匹配所需的参数
	 */
	static bool read_ParamsForStereoMatch(std::string& filename,
		cv::Mat* cameraMatrix1,
		cv::Mat* distCoeffs1,
		cv::Mat* cameraMatrix2,
		cv::Mat* distCoeffs2, 
		cv::Mat* R1,
		cv::Mat* P1,
		cv::Mat* R2,
		cv::Mat* P2,
		cv::Mat* Q, 
		cv::Rect* roi1,
		cv::Rect* roi2);
	/*
	 * 读取校正所需的参数
	 */
	static bool read_ParamsForStereoRectify(std::string& filename,
		cv::Mat* cameraMatrix1,
		cv::Mat* distCoeffs1,
		cv::Mat* cameraMatrix2,
		cv::Mat* distCoeffs2,
		cv::Mat* R1,
		cv::Mat* P1,
		cv::Mat* R2,
		cv::Mat* P2,
		cv::Rect* roi1,
		cv::Rect* roi2);
	/*
	 * 把点云保存在文件中
	 */
	static bool write_PointCloud(std::string&filename, cv::Mat&PointCloudMatrix);
	/*
	 * 从文件中读取点云
	 */
	static bool read_PointCloud(std::string&filename, cv::Mat*PointCloudMatrix);
#ifdef WITH_PCL
	/*
	 * 保存PCD点云
	 */
	static void createAndSavePointCloud(cv::Mat &disparity, cv::Mat &leftImage, cv::Mat &Q, std::string filename);
#endif
};

