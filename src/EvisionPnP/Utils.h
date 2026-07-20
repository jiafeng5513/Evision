/*
 * Utils.h
 *
 *  Created on: 2020-05-01
 *      Author: AnnaSkyWalker
 */

#ifndef UTILS_H_
#define UTILS_H_
#include "EvisionPnPExport.h"

#include <opencv2/features2d.hpp>
#include "PnPProblem.h"

// Draw a text with the question point
void EVISION_PNP_EXPORT drawQuestion(cv::Mat image, cv::Point3f point, cv::Scalar color);

// Draw a text with the number of entered points
void EVISION_PNP_EXPORT drawText(cv::Mat image, std::string text, cv::Scalar color);

// Draw a text with the number of entered points
void EVISION_PNP_EXPORT drawText2(cv::Mat image, std::string text, cv::Scalar color);

// Draw a text with the frame ratio
void EVISION_PNP_EXPORT drawFPS(cv::Mat image, double fps, cv::Scalar color);

// Draw a text with the frame ratio
void EVISION_PNP_EXPORT drawConfidence(cv::Mat image, double confidence, cv::Scalar color);

// Draw a text with the number of entered points
void EVISION_PNP_EXPORT drawCounter(cv::Mat image, int n, int n_max, cv::Scalar color);

// Draw 6Dof
void EVISION_PNP_EXPORT draw6DoF(cv::Mat image, cv::Mat trans, cv::Mat angle, bool good_measurement=true);

// Draw the points and the coordinates
void EVISION_PNP_EXPORT drawPoints(cv::Mat image, std::vector<cv::Point2f> &list_points_2d, std::vector<cv::Point3f> &list_points_3d, cv::Scalar color);

// Draw only the 2D points
void EVISION_PNP_EXPORT draw2DPoints(cv::Mat image, std::vector<cv::Point2f> &list_points, cv::Scalar color);

// Draw an arrow into the image
void EVISION_PNP_EXPORT drawArrow(cv::Mat image, cv::Point2i p, cv::Point2i q, cv::Scalar color, int arrowMagnitude = 9, int thickness=1, int line_type=8, int shift=0);

// Draw the 3D coordinate axes
void EVISION_PNP_EXPORT draw3DCoordinateAxes(cv::Mat image, const std::vector<cv::Point2f> &list_points2d);

// Draw the object mesh
void EVISION_PNP_EXPORT drawObjectMesh(cv::Mat image, const Mesh *mesh, PnPProblem *pnpProblem, cv::Scalar color);

// Computes the norm of the translation error
double EVISION_PNP_EXPORT get_translation_error(const cv::Mat &t_true, const cv::Mat &t);

// Computes the norm of the rotation error
double EVISION_PNP_EXPORT get_rotation_error(const cv::Mat &R_true, const cv::Mat &R);

// Converts a given Rotation Matrix to Euler angles
cv::Mat EVISION_PNP_EXPORT rot2euler(const cv::Mat & rotationMatrix);

// Converts a given Euler angles to Rotation Matrix
cv::Mat EVISION_PNP_EXPORT euler2rot(const cv::Mat & euler);

// Converts a Rotation Matrix to angles along three axises
cv::Mat EVISION_PNP_EXPORT rot2angle(const cv::Mat& rotationMatrix);

// Converts a given string to an integer
int EVISION_PNP_EXPORT StringToInt ( const std::string &Text );

// Converts a given float to a string
std::string EVISION_PNP_EXPORT FloatToString ( float Number );

// Converts a given integer to a string
std::string EVISION_PNP_EXPORT IntToString ( int Number );

void EVISION_PNP_EXPORT createFeatures(const std::string &featureName, int numKeypoints, cv::Ptr<cv::Feature2D> &detector, cv::Ptr<cv::Feature2D> &descriptor);

cv::Ptr<cv::DescriptorMatcher> EVISION_PNP_EXPORT createMatcher(const std::string &featureName, bool useFLANN);

//Create a cube ply file
void EVISION_PNP_EXPORT createCubePly(const std::vector<float> size, const std::string filename);

#endif /* UTILS_H_ */
