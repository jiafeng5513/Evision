#pragma once

#include <QObject>
#include <core/affine.hpp>
#include <QThread>
/*
 *1.这个类应该是个单例类
 *2.存储标定和矫正所需的输入和输出参数
 *3.其他类不应该持有这个类的实例和除枚举类型外的内部类型的实例
 *
 *4.不必要的返回类型应当删除
 *5.注释要注明输入还是输出
 */

class Calibrater : public QThread
{
	Q_OBJECT

public:
	static Calibrater* getInstance();
	~Calibrater();
	void initialize();
private:
	Calibrater(QObject *parent = Q_NULLPTR);
	//棋盘角点数据 结构体
	struct CornerDatas
	{
		int nPoints;			// 棋盘角点总数
		int nImages;			// 棋盘图像数
		int	nPointsPerImage;	// 每幅棋盘的角点数
		cv::Size	imageSize;			// 图像分辨率
		cv::Size	boardSize;			// 棋盘尺寸
		std::vector<std::vector<cv::Point3f> >	objectPoints;	// 棋盘角点世界坐标序列
		std::vector<std::vector<cv::Point2f> >	imagePoints1;	// 左视图的棋盘角点像素坐标序列
		std::vector<std::vector<cv::Point2f> >	imagePoints2;	// 右视图的棋盘角点像素坐标序列
		CornerDatas()
		{
			nPoints=0;			
			nImages=0;			
			nPointsPerImage=0;	
			imageSize.height=0;
			imageSize.width = 0;
			boardSize.height = 0;
			boardSize.width = 0;
			objectPoints=*new std::vector<std::vector<cv::Point3f> >;	
			imagePoints1=*new std::vector<std::vector<cv::Point2f> >;	
			imagePoints2=*new std::vector<std::vector<cv::Point2f> >;	
		}
	};
	//单目标定的输出参数
	struct CameraParams
	{
		cv::Size		imageSize;				// 图像分辨率
		cv::Mat			cameraMatrix;			// 摄像机矩阵
		cv::Mat			distortionCoefficients;	// 摄像机畸变参数
		std::vector<cv::Mat> rotations;				// 棋盘图片的旋转矩阵
		std::vector<cv::Mat> translations;			// 棋盘图片的平移向量
		int				flags;					// 单目标定所用的标志位
	};
	//双目标定的输出参数
	struct StereoParams
	{
		cv::Size		imageSize;		// 图像分辨率
		CameraParams	cameraParams1;	// 左摄像机标定参数
		CameraParams	cameraParams2;	// 右摄像机标定参数
		cv::Mat			rotation;		// 旋转矩阵
		cv::Mat			translation;	// 平移向量
		cv::Mat			essential;		// 本质矩阵
		cv::Mat			foundational;	// 基础矩阵
		int				flags;			// 双目标定所用的标志位
		double          alpha;
	};
	//双目校正的输出参数
	struct RemapMatrixs
	{
		cv::Mat		mX1;	// 左视图 X 方向像素映射矩阵
		cv::Mat		mY1;	// 左视图 Y 方向像素映射矩阵
		cv::Mat		mX2;	// 右视图 X 方向像素映射矩阵
		cv::Mat		mY2;	// 右视图 Y 方向像素映射矩阵
		cv::Mat		Q;		// 用于计算三维点云的 Q 矩阵
		cv::Rect	roi1;	// 左视图有效区域的矩形
		cv::Rect	roi2;	// 右视图有效区域的矩形
	};
public:
	CornerDatas cornerDatas;
	StereoParams stereoParams;
	RemapMatrixs remapMatrixs;
	//双目校正方法
	enum RECTIFYMETHOD { RECTIFY_BOUGUET, RECTIFY_HARTLEY };

	/*----------------------------
	* 功能 : 初始化棋盘角点数据信息
	*----------------------------
	* 函数 : calib::initCornerData
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : nImages		[in]	棋盘图像数
	* 参数 : imageSize		[in]	图像分辨率
	* 参数 : boardSize		[in]	棋盘角点数
	* 参数 : squareWidth	[in]	棋盘方块宽度
	*/
	int initCornerData(int nImages, cv::Size imageSize, cv::Size boardSize, float squareWidth);

	/*----------------------------
	* 功能 : 根据成功检测的棋盘数目修改棋盘角点数据
	*----------------------------
	* 函数 : calib::resizeCornerData
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : nImages		[in]	棋盘图像数
	*/
	int resizeCornerData(int nImages);

	/*----------------------------
	* 功能 : 载入棋盘角点数据信息
	*----------------------------
	* 函数 : calib::loadCornerData
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : filename		[in]	本地文件路径/文件名
	* 参数 : cornerDatas	[out]	导入的棋盘角点数据
	*/
	int loadCornerData(const char* filename, CornerDatas& cornerDatas);

	/*----------------------------
	* 功能 : 保存棋盘角点数据信息
	*----------------------------
	* 函数 : calib::saveCornerData
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : filename		[in]	本地文件路径/文件名
	*/
	int saveCornerData(const char* filename);

	/*----------------------------
	* 功能 : 检测棋盘角点
	*----------------------------
	* 函数 : calib::detectCorners
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : img1			[in]	左视图
	* 参数 : img2			[in]	右视图
	* 参数 : imageCount		[in]	当前棋盘角点检测的成功次数
	*/
	int detectCorners(cv::Mat& img1, cv::Mat& img2,  int imageCount);

	/*----------------------------
	* 功能 : 载入已标定好的摄像机内部参数
	*----------------------------
	* 函数 : calib::loadCameraParams
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : filename		[in]	参数文件路径/文件名
	* 参数 : cameraParams	[out]	读入的摄像机参数
	*/
	int loadCameraParams(const char* filename, CameraParams& cameraParams);

	/*----------------------------
	* 功能 : 保存已标定好的摄像机内部参数
	*----------------------------
	* 函数 : calib::saveCameraParams
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : cameraParams	[in]	已标定的摄像机参数
	* 参数 : filename		[in]	参数文件路径/文件名
	*/
	int saveCameraParams(const CameraParams& cameraParams, const char* filename = "cameraParams.yml");

	/*----------------------------
	* 功能 : 执行单目摄像机标定
	*----------------------------
	* 函数 : calib::calibrateSingleCamera
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : cornerDatas			[in]	棋盘角点数据
	* 参数 : cameraParams			[out]	双目标定数据
	*/
	int calibrateSingleCamera(CornerDatas& cornerDatas, CameraParams& cameraParams);

	/*----------------------------
	* 功能 : 执行双目摄像机标定
	*		 若每个摄像机尚未标定，则首先进行单目标定，再进行双目标定
	*----------------------------
	* 函数 : calib::calibrateStereoCamera
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	*/
	int calibrateStereoCamera();

	/*----------------------------
	* 功能 : 计算单目标定误差
	*----------------------------
	* 函数 : calib::getCameraCalibrateError
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : _objectPoints	[in]	棋盘角点的世界坐标
	* 参数 : _imagePoints	[in]	棋盘角点的图像坐标
	* 参数 : cameraParams	[in]	标定的摄像机参数
	* 参数 : err			[out]	单目标定误差
	*/
	int getCameraCalibrateError(std::vector<std::vector<cv::Point3f> >& objectPoints, std::vector<std::vector<cv::Point2f> >& imagePoints, CameraParams& cameraParams, double err);

	/*----------------------------
	* 功能 : 计算双目标定误差
	*----------------------------
	* 函数 : calib::getStereoCalibrateError
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : err			[out]	双目标定误差
	*/
	int getStereoCalibrateError(double& err);

	/*----------------------------------
	* 功能 : 生成单个摄像头的校正矩阵
	*----------------------------------
	* 函数 : calib::rectifySingleCamera
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : cameraParams	[in]	标定的摄像机参数
	* 参数 : remapMatrixs	[out]	单目校正结果
	*/
	int rectifySingleCamera(CameraParams& cameraParams, RemapMatrixs& remapMatrixs);

	/*----------------------------
	* 功能 : 执行双目摄像机校正
	*----------------------------
	* 函数 : calib::rectifyStereoCamera
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : method			[in]	双目校正方法
	*/
	int rectifyStereoCamera(RECTIFYMETHOD method);

	/*----------------------------
	* 功能 : 保存双目校正参数
	*----------------------------
	* 函数 : calib::saveCalibrationDatas
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : filename		[in]	保存路径/文件名
	* 参数 : method			[in]	双目校正方法
	*/
	int saveCalibrationDatas(const char* filename, RECTIFYMETHOD method);

	/*----------------------------------
	* 功能 : 对图像进行校正
	*----------------------------------
	* 函数 : calib::remapImage
	* 访问 : public
	* 返回 : 0 - 操作失败，1 - 操作成功
	*
	* 参数 : img1			[in]	输入图像1
	* 参数 : img2			[in]	输入图像2
	* 参数 : img1r			[out]	校正图像1
	* 参数 : img2r			[out]	校正图像2
	* 参数 : remapMatrixs	[in]	图像校正结果数据，需包含像素坐标映射矩阵
	*/
	int remapImage(cv::Mat& img1, cv::Mat& img2, cv::Mat& img1r, cv::Mat& img2r, RemapMatrixs& remapMatrixs);
	
private:

	/*----------------------------
	* 功能 : 在图像右下角显示指定文字信息
	*----------------------------
	* 函数 : calib::showText
	* 访问 : private
	* 返回 : void
	*
	* 参数 : img	[in]	图像
	* 参数 : text	[in]	文字信息
	*/
	void showText(cv::Mat& img, std::string text);
};
