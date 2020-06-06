#pragma once
#include <qimage.h>
#include "opencv2/opencv.hpp"
#include <QGraphicsView>
#include <QGraphicsScene>

#ifndef BUILD_STATIC
# if defined( EVISIONUTILS_LIB)
#  define  EVISIONUTILS_EXPORT Q_DECL_EXPORT
# else
#  define  EVISIONUTILS_EXPORT Q_DECL_IMPORT
# endif
#else
# define EVISIONUTILS_EXPORT
#endif
/*
 * 实用工具方法
 */
class EVISIONUTILS_EXPORT EvisionUtils
{
public:
	EvisionUtils();
	~EvisionUtils();
	/*
	 * 获取当前路径
	 */
	static std::string getCurrentPath();
	/*
	 * 路径整理
     */
	static std::string pathPurify(std::string& src);
	/*
	 * 获取数据文件夹
	 */
	static std::string getDataPath();
	/*
	 * cv::Mat转换为QImage
	 */
	static QImage cvMat2QImage(const cv::Mat& mat);

	/*
	 * QImage转换为cv::Mat
	 */
	static cv::Mat QImage2cvMat(QImage image);
	/*
	 * 灰度图转彩虹图
	 */
	static cv::Mat gray2rainbowcolor(cv::Mat& img);
	/*
	 * 创建并返回idle image
	 */
	static QImage getDefaultImage();
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
		cv::Mat& cameraMatrix1,cv::Mat& distCoeffs1,cv::Mat& cameraMatrix2,cv::Mat& distCoeffs2,
		cv::Mat& R,cv::Mat& T,cv::Size& imageSize,cv::Mat& R1,cv::Mat& P1,cv::Mat& R2,cv::Mat& P2,
		cv::Mat& Q,cv::Rect& roi1,cv::Rect& roi2);

	//保存单目相机标定的参数
	static bool write_MonocularCameraParams(std::string& filename,cv::Mat& cameraMatrix1, cv::Mat& distCoeffs1, cv::Size& imageSize);
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
		cv::Mat* cameraMatrix1,cv::Mat* distCoeffs1,cv::Mat* cameraMatrix2,cv::Mat* distCoeffs2,
		cv::Mat* R,cv::Mat* T,cv::Mat* E,cv::Mat* F,cv::Size* imageSize,cv::Mat* R1,cv::Mat* P1,cv::Mat* R2,cv::Mat* P2,
		cv::Mat* Q,cv::Rect* roi1,cv::Rect* roi2);
	//读取单目相机标定的参数
	static bool read_MonocularParams(std::string& filename,cv::Mat* cameraMatrix1, cv::Mat* distCoeffs1, cv::Size* imageSize);
	/*
	 * 读取匹配所需的参数
	 */
	static bool read_ParamsForStereoMatch(std::string& filename,
		cv::Mat* cameraMatrix1,cv::Mat* distCoeffs1,cv::Mat* cameraMatrix2,cv::Mat* distCoeffs2, 
		cv::Mat* R1,cv::Mat* P1,cv::Mat* R2,cv::Mat* P2,cv::Mat* Q, cv::Rect* roi1,cv::Rect* roi2);
	/*
	 * 读取校正所需的参数
	 */
	static bool read_ParamsForStereoRectify(std::string& filename,cv::Mat* cameraMatrix1,
		cv::Mat* distCoeffs1,cv::Mat* cameraMatrix2,cv::Mat* distCoeffs2,
		cv::Mat* R1,cv::Mat* P1,cv::Mat* R2,cv::Mat* P2,cv::Rect* roi1,cv::Rect* roi2);
	/*
	 *将原始视差数据转换为适合显示和存储为图片的灰度视差图
	 */
	static void getGrayDisparity(const cv::Mat& disp, cv::Mat& grayDisp, bool stretch = true);
};