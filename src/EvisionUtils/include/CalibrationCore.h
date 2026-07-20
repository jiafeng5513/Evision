#pragma once

#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>

/*
 * 标定核心模块导出宏(Qt-free)
 * 复用 EvisionUtils 的 EVISIONUTILS_LIB 预处理器开关,
 * 但使用 __declspec 替代 Q_DECL_EXPORT/Q_DECL_IMPORT,
 * 避免引入 Qt 头文件.
 */
#ifndef BUILD_STATIC
#  if defined(EVISIONUTILS_LIB)
#    define EVISIONUTILS_CALIB_EXPORT __declspec(dllexport)
#  else
#    define EVISIONUTILS_CALIB_EXPORT __declspec(dllimport)
#  endif
#else
#  define EVISIONUTILS_CALIB_EXPORT
#endif

/*
 * 标定板类型
 */
enum class EVISIONUTILS_CALIB_EXPORT BoardType
{
	Chessboard,            // 棋盘格
	CirclesGrid,           // 圆点阵列
	AsymmetricCirclesGrid, // 非对称圆点阵列
	Charuco                // ChArUco 板
};

/*
 * 标定板配置
 */
struct EVISIONUTILS_CALIB_EXPORT BoardConfig
{
	BoardType type = BoardType::Chessboard; // 标定板类型
	cv::Size boardSize = cv::Size(9, 6);    // 棋盘格/圆点: 内角点数量(width,height); ChArUco: 方格数量(X,Y)
	float squareSize = 25.f;                // 方格边长(单位自定,通常 mm)
	float markerSize = 18.75f;              // ChArUco 标记边长(同单位)
	int dictionaryId = cv::aruco::DICT_5X5_1000; // ChArUco 字典 ID
};

/*
 * 单张图像的标定板检测结果
 */
struct DetectionResult
{
	bool found = false;                  // 是否检测到有效标定板
	std::vector<cv::Point2f> corners;    // 图像角点/特征点,与 objects 一一对应
	std::vector<cv::Point3f> objects;    // 对应的三维板坐标(对于 ChArUco 为部分检测)
};

/*
 * 单目相机标定结果
 */
struct MonoCalibResult
{
	bool ok = false;                                // 标定是否成功
	cv::Mat cameraMatrix;                           // 相机内参矩阵
	cv::Mat distCoeffs;                             // 畸变系数
	double rms = 0;                                 // calibrateCamera 返回的 RMS
	double avgReprojErr = 0;                        // 平均重投影误差
	std::vector<float> perViewErrors;               // 逐视图重投影误差(原始索引,排除视图为 -1)
	std::vector<int> excludedViews;                 // 被排除的原始视图索引
	int usedViews = 0;                              // 最终参与标定的视图数
	cv::Size imageSize;                             // 图像尺寸
};

/*
 * 立体图像对的公共检测子集
 */
struct StereoPairDetection
{
	bool ok = false;                         // 是否构成有效立体对
	std::vector<cv::Point2f> cornersL;       // 左视图公共角点
	std::vector<cv::Point2f> cornersR;       // 右视图公共角点
	std::vector<cv::Point3f> objects;        // 公共角点对应的三维板坐标
};

/*
 * 双目相机标定结果
 */
struct StereoCalibResult
{
	bool ok = false;                         // 标定是否成功
	double rms = 0;                          // stereoCalibrate 返回的 RMS
	double avgEpipolarErr = 0;               // 平均极线误差
	std::vector<float> perViewErrors;        // 左相机逐视图重投影误差
	cv::Mat R, T, E, F;                      // 旋转、平移、本质矩阵、基本矩阵
	cv::Mat R1, R2, P1, P2, Q;               // 立体校正矩阵
	cv::Rect roi1, roi2;                     // 校正后的有效 ROI
	cv::Size imageSize;                      // 图像尺寸
};

/*
 * 纯 OpenCV 标定核心
 * 不含 Qt 依赖,供单目标定和双目标定模块共享.
 */
class EVISIONUTILS_CALIB_EXPORT CalibrationCore
{
public:
	/*
	 * 在单张图像中检测标定板.
	 * 棋盘格优先使用 findChessboardCornersSB,失败则回退到经典方法并做 cornerSubPix.
	 * 圆点/非对称圆点使用 findCirclesGrid.
	 * ChArUco 使用 cv::aruco::CharucoDetector.
	 */
	static DetectionResult detectBoard(const cv::Mat& image, const BoardConfig& cfg);

	/*
	 * 在图像副本上绘制检测结果并返回.
	 * 全板类型使用 drawChessboardCorners; ChArUco 绘制检测到的角点圆环.
	 */
	static cv::Mat drawDetection(cv::Mat image, const BoardConfig& cfg, const DetectionResult& det);

	/*
	 * 单目标定核心.
	 * 要求至少 3 个视图且每个视图不少于 4 个点.
	 * 支持按重投影误差迭代剔除异常视图.
	 */
	static MonoCalibResult calibrateMonocular(
		const std::vector<std::vector<cv::Point2f>>& imagePoints,
		const std::vector<std::vector<cv::Point3f>>& objectPoints,
		cv::Size imageSize,
		int flags,
		float aspectRatio = 1.f,
		double outlierPx = 1.5,
		int maxOutlierIters = 2);

	/*
	 * 匹配左右视图检测结果的公共子集.
	 * 全板类型要求左右均检测到完整网格; ChArUco 按三维坐标精确匹配,至少 8 个公共点才有效.
	 */
	static StereoPairDetection matchStereoPair(
		const DetectionResult& detL,
		const DetectionResult& detR,
		const BoardConfig& cfg);

	/*
	 * 双目标定核心.
	 * 要求至少 2 个视图.
	 * 内部调用 stereoCalibrate、计算平均极线误差、stereoRectify 以及左相机逐视图重投影误差.
	 */
	static StereoCalibResult calibrateStereo(
		const std::vector<std::vector<cv::Point2f>>& imagePointsL,
		const std::vector<std::vector<cv::Point2f>>& imagePointsR,
		const std::vector<std::vector<cv::Point3f>>& objectPoints,
		cv::Size imageSize,
		cv::Mat& cameraMatrix_L,
		cv::Mat& distCoeffs_L,
		cv::Mat& cameraMatrix_R,
		cv::Mat& distCoeffs_R,
		int flags);

	/*
	 * 计算重投影误差.
	 * 与现有 StereoCalibrate/MonocularCalibrate 中的实现保持一致.
	 */
	static double computeReprojectionErrors(
		const std::vector<std::vector<cv::Point3f>>& objectPoints,
		const std::vector<std::vector<cv::Point2f>>& imagePoints,
		const std::vector<cv::Mat>& rvecs,
		const std::vector<cv::Mat>& tvecs,
		const cv::Mat& cameraMatrix,
		const cv::Mat& distCoeffs,
		std::vector<float>& perViewErrors);

private:
	CalibrationCore() = delete;
	~CalibrationCore() = delete;
};
