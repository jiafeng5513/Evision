#include "extrapolate_coords_t.h"

void extrapolate_coords_t::new_result(std::vector<bbox_t> new_result_vec, float new_time)
{
	old_dx_vec = dx_vec;
	old_dy_vec = dy_vec;
	if (old_dx_vec.size() != old_result_vec.size()) std::cout << "old_dx != old_res \n";
	dx_vec = std::vector<float>(new_result_vec.size(), 0);
	dy_vec = std::vector<float>(new_result_vec.size(), 0);
	update_result(new_result_vec, new_time, false);
	old_result_vec = new_result_vec;
	time_vec = std::vector<float>(new_result_vec.size(), new_time);
}

void extrapolate_coords_t::update_result(std::vector<bbox_t> new_result_vec, float new_time, bool update)
{
	for (size_t i = 0; i < new_result_vec.size(); ++i)
	{
		for (size_t k = 0; k < old_result_vec.size(); ++k)
		{
			if (old_result_vec[k].track_id == new_result_vec[i].track_id && old_result_vec[k].obj_id == new_result_vec[i
			].obj_id)
			{
				float const delta_time = new_time - time_vec[k];
				if (abs(delta_time) < 1) break;
				size_t index = (update) ? k : i;
				float dx = ((float)new_result_vec[i].x - (float)old_result_vec[k].x) / delta_time;
				float dy = ((float)new_result_vec[i].y - (float)old_result_vec[k].y) / delta_time;
				float old_dx = dx, old_dy = dy;

				// if it's shaking
				if (update)
				{
					if (dx * dx_vec[i] < 0) dx = dx / 2;
					if (dy * dy_vec[i] < 0) dy = dy / 2;
				}
				else
				{
					if (dx * old_dx_vec[k] < 0) dx = dx / 2;
					if (dy * old_dy_vec[k] < 0) dy = dy / 2;
				}
				dx_vec[index] = dx;
				dy_vec[index] = dy;

				//if (old_dx == dx && old_dy == dy) std::cout << "not shakin \n";
				//else std::cout << "shakin \n";

				if (dx_vec[index] > 1000 || dy_vec[index] > 1000)
				{
					//std::cout << "!!! bad dx or dy, dx = " << dx_vec[index] << ", dy = " << dy_vec[index] << 
					//    ", delta_time = " << delta_time << ", update = " << update << std::endl;
					dx_vec[index] = 0;
					dy_vec[index] = 0;
				}
				old_result_vec[k].x = new_result_vec[i].x;
				old_result_vec[k].y = new_result_vec[i].y;
				time_vec[k] = new_time;
				break;
			}
		}
	}
}

std::vector<bbox_t> extrapolate_coords_t::predict(float cur_time)
{
	std::vector<bbox_t> result_vec = old_result_vec;
	for (size_t i = 0; i < old_result_vec.size(); ++i)
	{
		float const delta_time = cur_time - time_vec[i];
		auto& bbox = result_vec[i];
		float new_x = (float)bbox.x + dx_vec[i] * delta_time;
		float new_y = (float)bbox.y + dy_vec[i] * delta_time;
		if (new_x > 0) bbox.x = new_x;
		else bbox.x = 0;
		if (new_y > 0) bbox.y = new_y;
		else bbox.y = 0;
	}
	return result_vec;
}
