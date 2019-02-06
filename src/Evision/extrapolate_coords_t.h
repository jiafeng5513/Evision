#pragma once
#include "../yolo/include/yolo_v2_class.hpp"
#include <iostream>
class extrapolate_coords_t 
{
public:
	std::vector<bbox_t> old_result_vec;
	std::vector<float> dx_vec, dy_vec, time_vec;
	std::vector<float> old_dx_vec, old_dy_vec;

	void new_result(std::vector<bbox_t> new_result_vec, float new_time);

	void update_result(std::vector<bbox_t> new_result_vec, float new_time, bool update = true);

	std::vector<bbox_t> predict(float cur_time);
};

