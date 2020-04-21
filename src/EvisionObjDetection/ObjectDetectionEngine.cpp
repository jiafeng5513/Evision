#include "ObjectDetectionEngine.h"
#include <fstream>

ObjectDetectionEngine::ObjectDetectionEngine(QObject *parent)
{
	m_entity = ObjectDetectionEntity::getInstance();
	connect(m_entity, SIGNAL(paramChanged_RunningState()), this, SLOT(onChangeRunState()));
}

ObjectDetectionEngine::~ObjectDetectionEngine()
{
}

std::vector<std::string> ObjectDetectionEngine::objects_names_from_file(std::string const filename)
{
	std::ifstream file(filename);
	std::vector<std::string> file_lines;
	if (!file.is_open()) return file_lines;
	for (std::string line; getline(file, line);) file_lines.push_back(line);
	std::cout << "object names loaded \n";
	return file_lines;
}

void ObjectDetectionEngine::draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec,
                                       std::vector<std::string> obj_names, int current_det_fps, int current_cap_fps)
{
	int const colors[6][3] = {{1, 0, 1}, {0, 0, 1}, {0, 1, 1}, {0, 1, 0}, {1, 1, 0}, {1, 0, 0}};

	for (auto& i : result_vec)
	{
		cv::Scalar color = obj_id_to_color(i.obj_id);
		cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
		if (obj_names.size() > i.obj_id)
		{
			std::string obj_name = obj_names[i.obj_id];
			if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
			cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
			int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
			cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
			              cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1),
			                          std::min((int)i.y, mat_img.rows - 1)),
			              color, cv::FILLED, 8, 0);
			putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2,
			        cv::Scalar(0, 0, 0), 2);
		}
	}
	if (current_det_fps >= 0 && current_cap_fps >= 0)
	{
		std::string fps_str = "FPS detection: " + std::to_string(current_det_fps) + "   FPS capture: " + std::to_string(
			current_cap_fps);
		putText(mat_img, fps_str, cv::Point2f(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(50, 255, 0), 2);
	}
}

void ObjectDetectionEngine::show_console_result(std::vector<bbox_t> const result_vec,
                                                std::vector<std::string> const obj_names)
{
	for (auto& i : result_vec)
	{
		if (obj_names.size() > i.obj_id) std::cout << obj_names[i.obj_id] << " - ";
		std::cout << "obj_id = " << i.obj_id << ",  x = " << i.x << ", y = " << i.y
			<< ", w = " << i.w << ", h = " << i.h
			<< std::setprecision(3) << ", prob = " << i.prob << std::endl;
	}
}

//线程方法
void ObjectDetectionEngine::run()
{
	std::string  names_file = m_entity->getnamesFilename().toStdString();
	std::string  cfg_file = m_entity->getCfgFilename().toStdString();
	std::string  weights_file = m_entity->getweightsFilename().toStdString();

	auto obj_names = objects_names_from_file(names_file);

	Detector detector(cfg_file, weights_file);

	cv::VideoCapture cam(0);

	while (keepRun)
	{

		cv::Mat * mat_img = new cv::Mat();
		cam >> *mat_img;

		auto start = std::chrono::steady_clock::now();
		std::vector<bbox_t> result_vec = detector.detect(*mat_img);
		auto end = std::chrono::steady_clock::now();

		std::chrono::duration<double> spent = end - start;
		std::cout << " Time: " << spent.count() << " sec \n";

		draw_boxes(*mat_img, result_vec, obj_names);
		m_entity->setDetectionPlayer(*mat_img);
		show_console_result(result_vec, obj_names);
	}
}
//有人通过改变Entity中的运行状态标记,表达了想关闭线程的想法
void ObjectDetectionEngine::onChangeRunState()
{
	keepRun = false;
}
