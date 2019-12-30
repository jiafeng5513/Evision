#pragma once
#include <opencv2/opencv.hpp>
#ifdef LIB_EXPORTS
#if defined(_MSC_VER)
#define LIB_API __declspec(dllexport)
#else
#define LIB_API __attribute__((visibility("default")))
#endif
#else
#if defined(_MSC_VER)
#define LIB_API
#else
#define LIB_API
#endif
#endif

class LIB_API EvisionElas
{
protected:
	int32_t disp_min;               // min disparity
	int32_t disp_max;               // max disparity
	float   support_threshold;      // max. uniqueness ratio (best vs. second best support match)
	int32_t support_texture;        // min texture for support points
	int32_t candidate_stepsize;     // step size of regular grid on which support points are matched
	int32_t incon_window_size;      // window size of inconsistent support point check
	int32_t incon_threshold;        // disparity similarity threshold for support point to be considered consistent
	int32_t incon_min_support;      // minimum number of consistent support points
	bool    add_corners;            // add support points at image corners with nearest neighbor disparities
	int32_t grid_size;              // size of neighborhood for additional support point extrapolation
	float   beta;                   // image likelihood parameter
	float   gamma;                  // prior constant
	float   sigma;                  // prior sigma
	float   sradius;                // prior sigma radius
	int32_t match_texture;          // min texture for dense matching
	int32_t lr_threshold;           // disparity threshold for left/right consistency check
	float   speckle_sim_threshold;  // similarity threshold for speckle segmentation
	int32_t speckle_size;           // maximal size of a speckle (small speckles get removed)
	int32_t ipol_gap_width;         // interpolate small gaps (left<->right, top<->bottom)
	bool    filter_median;          // optional median filter (approximated)
	bool    filter_adaptive_mean;   // optional adaptive mean filter (approximated)
	bool    postprocess_only_left;  // saves time by not postprocessing the right image
	bool    subsampling;            // saves time by only computing disparities for each 2nd pixel
									// note: for this option D1 and D2 must be passed with size
									//       width/2 x height/2 (rounded towards zero)
	int border;
public:
	EvisionElas();
	EvisionElas(int32_t disp_min, int32_t disp_max, float   support_threshold, int32_t support_texture,
		int32_t candidate_stepsize,int32_t incon_window_size,int32_t incon_threshold,int32_t incon_min_support,
		bool    add_corners,int32_t grid_size,float   beta,float   gamma,float   sigma,float   sradius,
		int32_t match_texture,int32_t lr_threshold,float   speckle_sim_threshold,int32_t speckle_size,
		int32_t ipol_gap_width,bool    filter_median,bool    filter_adaptive_mean,
		bool    postprocess_only_left,bool    subsampling,int border
	);
	bool Match(cv::Mat leftImg, cv::Mat rightImg, cv::Mat *disp_raw, cv::Mat* disp_show);

};