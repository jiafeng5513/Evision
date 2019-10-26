#pragma once

#include <QObject>
#include <QThread>
#include <iomanip>
#include "opencv2/opencv.hpp"            // C++#include "opencv2/opencv.hpp"            // C++
#include "../EvisionObjDetection/include/yolo_v2_class.hpp"
#include "ObjectDetectionEntity.h"
#ifdef _WIN32
#define OPENCV
#define GPU
#endif

#ifdef OPENCV
#include "opencv2/opencv.hpp"            // C++
#include "opencv2/core/version.hpp"
#endif
#define OPENCV_VERSION CVAUX_STR(CV_VERSION_MAJOR)"" CVAUX_STR(CV_VERSION_MINOR)"" CVAUX_STR(CV_VERSION_REVISION)
//#pragma comment(lib, "opencv_world" OPENCV_VERSION ".lib")
//#ifdef TRACK_OPTFLOW
//#pragma comment(lib, "opencv_cudaoptflow" OPENCV_VERSION ".lib")
//#pragma comment(lib, "opencv_cudaimgproc" OPENCV_VERSION ".lib")
//#pragma comment(lib, "opencv_core" OPENCV_VERSION ".lib")
//#pragma comment(lib, "opencv_imgproc" OPENCV_VERSION ".lib")
//#pragma comment(lib, "opencv_highgui" OPENCV_VERSION ".lib")
//#endif    // TRACK_OPTFLOW
class ObjectDetectionEngine : public QThread
{
	Q_OBJECT

public:
	ObjectDetectionEngine(QObject *parent=0);
	~ObjectDetectionEngine();

	std::vector<std::string> objects_names_from_file(std::string const filename);

	void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,
	                int current_det_fps = -1, int current_cap_fps = -1);

	void show_console_result(std::vector<bbox_t> const result_vec, std::vector<std::string> const obj_names);

	void run() override;
private:
	ObjectDetectionEntity * m_entity;
	bool keepRun = true;
public slots:
	void onChangeRunState();//响应运行状态改变命令
};
