#pragma once
#include <qimage.h>
#include "opencv2\core\core.hpp"
#include "cv.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
/*
 * 实用工具方法
 */
class EvisionUtils
{
public:
	EvisionUtils();
	~EvisionUtils();
	static QImage cvMat2QImage(const cv::Mat& mat);
	static cv::Mat QImage2cvMat(QImage image);
};

