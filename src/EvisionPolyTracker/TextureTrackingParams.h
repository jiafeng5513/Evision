#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include "ui_TextureTrackingParams.h"
#include <opencv2\video\tracking.hpp>

/*
 * 
 */
class TextureTrackingParams : public QDialog
{
    Q_OBJECT

public:
    TextureTrackingParams(QWidget *parent = Q_NULLPTR);

private:
    Ui::TextureTrackingParamsClass ui;
    std::string video_read_path;       // recorded video
    std::string yml_read_path; // 3dpts + descriptors
    std::string ply_read_path;         // mesh
    std::string saveDirectory;
    std::string featureName;
    int numKeyPoints;
    int iterationsCount;
    int minInliersKalman;
    int pnpMethod;
    float ratioTest;
    float reprojectionError;
    float confidence;
    bool fast_match;
    bool useFLANN;
    bool displayFilteredPose;
    double fx, fy, cx, cy;
private:
    void TrackingThread();
    void initKalmanFilter(cv::KalmanFilter& KF, int nStates, int nMeasurements, int nInputs, double dt);
    void predictKalmanFilter(cv::KalmanFilter& KF, cv::Mat& translation_predicted, cv::Mat& rotation_predicted);
    void updateKalmanFilter(cv::KalmanFilter& KF, cv::Mat& measurements, cv::Mat& translation_estimated, cv::Mat& rotation_estimated);
    void fillMeasurements(cv::Mat& measurements,const cv::Mat& translation_measured, const cv::Mat& rotation_measured);
public slots:
    void onPush_confirm();
    void onPush_cancel();
};