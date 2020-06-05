#include "TextureTrackingParams.h"

#include <QMessageBox>
#include <QFileInfo>
#include <thread>
#include "EvisionUtils.h"
// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/core/utils/filesystem.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/video/tracking.hpp>
// PnP Tutorial
#include "Mesh.h"
#include "Model.h"
#include "PnPProblem.h"
#include "RobustMatcher.h"
#include "ModelRegistration.h"
#include "Utils.h"

TextureTrackingParams::TextureTrackingParams(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    std::string datapath = EvisionUtils::pathPurify(EvisionUtils::getCurrentPath() + "\\..\\..\\..\\data\\Tracker");

    video_read_path = datapath+ "/box.mp4";
    ui.lineEdit_video_read_path->setText(QString::fromStdString(video_read_path));
    yml_read_path = datapath + "/cookies_ORB.yml";
    ui.lineEdit_yml_read_path->setText(QString::fromStdString(yml_read_path));
    ply_read_path = datapath + "/box.ply";
    ui.lineEdit_ply_read_path->setText(QString::fromStdString(ply_read_path));
    saveDirectory = datapath + "/test_reg";
    ui.lineEdit_saveDirectory->setText(QString::fromStdString(saveDirectory));
    featureName = "ORB";

    numKeyPoints = 2000;
    ui.lineEdit_numKeyPoints->setText(QString::number(numKeyPoints));
    iterationsCount = 500;
    ui.lineEdit_iterationsCount->setText(QString::number(iterationsCount));
    minInliersKalman = 30;
    ui.lineEdit_minInliersKalman->setText(QString::number(minInliersKalman));
    pnpMethod = 0;

    ratioTest = 0.70f;
    ui.lineEdit_ratioTest->setText(QString::number(ratioTest));
    reprojectionError = 6.0f;
    ui.lineEdit_reprojectionError->setText(QString::number(reprojectionError));
    confidence = 0.99f;
    ui.lineEdit_confidence->setText(QString::number(confidence));
    fast_match = true;
    ui.checkBox_fast_match->setChecked(fast_match);
    useFLANN = false;
    ui.checkBox_useFLANN->setChecked(useFLANN);
    displayFilteredPose = false;
    ui.checkBox_displayFilteredPose->setChecked(displayFilteredPose);
    // 转换为内参矩阵的四个自由变量
    fx = 1578.47533632287;
    fy = 1771.8120805369126;
    cx = 320.0;
    cy = 240.0;
    ui.lineEdit_fx->setText(QString::number(this->fx));
    ui.lineEdit_fy->setText(QString::number(this->fy));
    ui.lineEdit_cx->setText(QString::number(this->cx));
    ui.lineEdit_cy->setText(QString::number(this->cy));
}

void TextureTrackingParams::onPush_confirm()
{
    //校验->传参->开线程
    QFileInfo* fileinfo_video_read_path = new QFileInfo(ui.lineEdit_video_read_path->text());
    QFileInfo* fileinfo_yml_read_path = new QFileInfo(ui.lineEdit_yml_read_path->text());
    QFileInfo* fileinfo_ply_read_path = new QFileInfo(ui.lineEdit_ply_read_path->text());
    QFileInfo* fileinfo_saveDirectory = new QFileInfo(ui.lineEdit_saveDirectory->text());

    if ((fileinfo_video_read_path->exists() && fileinfo_video_read_path->isFile()) &&
        (fileinfo_yml_read_path->exists() && fileinfo_yml_read_path->isFile()) &&
        (fileinfo_ply_read_path->exists() && fileinfo_ply_read_path->isFile()) &&
        (fileinfo_saveDirectory->exists() && fileinfo_saveDirectory->isDir()) &&

        (numKeyPoints = ui.lineEdit_numKeyPoints->text().toInt()) > 0 &&
        (iterationsCount = ui.lineEdit_iterationsCount->text().toInt()) > 0 &&
        (minInliersKalman = ui.lineEdit_minInliersKalman->text().toInt()) > 0 &&
        (ratioTest = ui.lineEdit_ratioTest->text().toFloat()) > 0 &&
        (reprojectionError = ui.lineEdit_reprojectionError->text().toFloat()) > 0 &&
        (confidence = ui.lineEdit_confidence->text().toFloat()) > 0&&
        (this->fx = ui.lineEdit_fx->text().toDouble()) > 0 &&
        (this->fy = ui.lineEdit_fy->text().toDouble()) > 0 &&
        (this->cx = ui.lineEdit_cx->text().toDouble()) > 0 &&
        (this->cy = ui.lineEdit_cy->text().toDouble()) > 0)
    {
        this->featureName = ui.comboBox_featureName->currentText().toStdString();
        this->pnpMethod = ui.comboBox_pnpMethod->currentIndex();
        this->fast_match = ui.checkBox_fast_match->isChecked();
        this->useFLANN = ui.checkBox_useFLANN->isChecked();
        this->displayFilteredPose = ui.checkBox_displayFilteredPose->isChecked();

        this->video_read_path = ui.lineEdit_video_read_path->text().toStdString();
        this->yml_read_path= ui.lineEdit_yml_read_path->text().toStdString();
        this->ply_read_path= ui.lineEdit_ply_read_path->text().toStdString();
        this->saveDirectory= ui.lineEdit_saveDirectory->text().toStdString();

        std::thread _t(&TextureTrackingParams::TrackingThread, this);
        _t.detach();
        std::cout << "注册线程启动..." << std::endl;
    }
    else
    {
        QMessageBox::information(this, QStringLiteral("注意"), QStringLiteral("参数不完整!"));
    }
}


void TextureTrackingParams::TrackingThread()
{
    // 内参矩阵的四个自由变量
    double params_WEBCAM[4] = {this->fx,this->fy,this->cx,this->cy};

    // 颜色值定义
    cv::Scalar red(0, 0, 255);
    cv::Scalar green(0, 255, 0);
    cv::Scalar blue(255, 0, 0);
    cv::Scalar yellow(0, 255, 255);


    int frameCount = 0;


    //输出参数情况
    std::cout << "输入视频                    : " << video_read_path << std::endl;
    std::cout << "训练数据                    : " << yml_read_path << std::endl;
    std::cout << "ply网格                     : " << ply_read_path << std::endl;
    std::cout << "Ratio test threshold        : " << ratioTest << std::endl;
    std::cout << "是否使用快速匹配?           : " << (fast_match ? "YES" : "NO") << std::endl;
    std::cout << "RANSAC 迭代次数             : " << iterationsCount << std::endl;
    std::cout << "RANSAC 重投影误差           : " << reprojectionError << std::endl;
    std::cout << "RANSAC 置信度阈值           : " << confidence << std::endl;
    std::cout << "卡尔曼滤波内点数            : " << minInliersKalman << std::endl;
    std::cout << "PnP 方法                    : " << pnpMethod << std::endl;
    std::cout << "特征描述符                  : " << featureName << std::endl;
    std::cout << "ORB特征点数                 : " << numKeyPoints << std::endl;
    std::cout << "是否使用FLANN进行匹配?      : " << (useFLANN ? "YES" : "NO") << std::endl;
    std::cout << "保存路径                    : " << saveDirectory << std::endl;
    std::cout << "显示卡尔曼滤波后的匹配情况? : " << (displayFilteredPose ? "YES" : "NO") << std::endl;

    PnPProblem pnp_detection(params_WEBCAM);
    PnPProblem pnp_detection_est(params_WEBCAM);

    Model model;               // 模型
    model.load(yml_read_path); // 加载3D纹理模型(*.yml)

    Mesh mesh;                 // 网格
    mesh.load(ply_read_path);  // 加载网格(*.ply)


    cv::Ptr<cv::FeatureDetector> detector, descriptor;                                  // 初始化:特征检测器和特征描述符
    createFeatures(featureName, numKeyPoints, detector, descriptor);            // 检测特征
    RobustMatcher rmatcher;                                                     // 初始化:匹配器
    rmatcher.setFeatureDetector(detector);                                      // set feature detector
    rmatcher.setDescriptorExtractor(descriptor);                                // set descriptor extractor
    rmatcher.setDescriptorMatcher(createMatcher(featureName, useFLANN));        // set matcher
    rmatcher.setRatio(ratioTest);                                               // set ratio test parameter
    if (!model.get_trainingImagePath().empty())
    {
        cv::Mat trainingImg = cv::imread(model.get_trainingImagePath());
        rmatcher.setTrainingImage(trainingImg);
    }

    cv::KalmanFilter KF;             // 初始化:卡尔曼滤波器
    int nStates = 18;            // the number of states
    int nMeasurements = 6;       // the number of measured states
    int nInputs = 0;             // the number of control actions
    double dt = 0.125;           // time between measurements (1/FPS)

    initKalmanFilter(KF, nStates, nMeasurements, nInputs, dt);    // init function
    cv::Mat measurements(nMeasurements, 1, CV_64FC1); measurements.setTo(cv::Scalar(0));
    bool good_measurement = false;

    // Get the MODEL INFO
    std::vector<cv::Point3f> list_points3d_model = model.get_points3d();  // list with model 3D coordinates
    cv::Mat descriptors_model = model.get_descriptors();             // list with descriptors of each 3D coordinate
    std::vector<cv::KeyPoint> keypoints_model = model.get_keypoints();

    // 窗口
    cv::namedWindow("REAL TIME DEMO");//WINDOW_KEEPRATIO

    cv::VideoCapture cap;                           // 视频播放器
    cap.open(video_read_path);                  // 加载视频文件(也可以加载摄像头)

    if (!cap.isOpened())   // check if we succeeded
    {
        std::cout << "Could not open the camera device" << std::endl;
        return;
    }

    if (!saveDirectory.empty())
    {
        if (!cv::utils::fs::exists(saveDirectory))
        {
            std::cout << "Create directory: " << saveDirectory << std::endl;
            cv::utils::fs::createDirectories(saveDirectory);
        }
    }

    cv::TickMeter tm;                                     // 计时器,用于计算实时帧速率(FPS)
    cv::Mat frame, frame_vis, frame_matching;             // 视频当前帧,用于窗口显示的帧(叠绘了信息),匹配目标帧
    bool isfirstframe = true;                         // 是否为第一帧
    cv::Mat initTrans, initRot, deltaT, deltaR;           // 初始位姿
    while (cap.read(frame) && (char)cv::waitKey(30) != 27) // 按ESC键,或者视频读完退出
    {
        tm.reset();
        tm.start();
        frame_vis = frame.clone();    // refresh visualisation frame

        // -- Step 1: 匹配模型中的特征描述符和场景帧上的特征描述符
        std::vector<cv::DMatch> good_matches;       // to obtain the 3D points of the model
        std::vector<cv::KeyPoint> keypoints_scene;  // to obtain the 2D points of the scene

        if (fast_match)
        {
            rmatcher.fastRobustMatch(frame, good_matches, keypoints_scene, descriptors_model, keypoints_model);
        }
        else
        {
            rmatcher.robustMatch(frame, good_matches, keypoints_scene, descriptors_model, keypoints_model);
        }

        frame_matching = rmatcher.getImageMatching();
        if (!frame_matching.empty())
        {
            cv::imshow("Keypoints matching", frame_matching);
        }

        // -- Step 2: Find out the 2D/3D correspondences
        std::vector<cv::Point3f> list_points3d_model_match; // container for the model 3D coordinates found in the scene
        std::vector<cv::Point2f> list_points2d_scene_match; // container for the model 2D coordinates found in the scene

        for (unsigned int match_index = 0; match_index < good_matches.size(); ++match_index)
        {
            cv::Point3f point3d_model = list_points3d_model[good_matches[match_index].trainIdx];  // 3D point from model
            cv::Point2f point2d_scene = keypoints_scene[good_matches[match_index].queryIdx].pt; // 2D point from the scene
            list_points3d_model_match.push_back(point3d_model);         // add 3D point
            list_points2d_scene_match.push_back(point2d_scene);         // add 2D point
        }

        // 红点标出离群点
        draw2DPoints(frame_vis, list_points2d_scene_match, red);

        cv::Mat inliers_idx;
        std::vector<cv::Point2f> list_points2d_inliers;

        // Instantiate estimated translation and rotation
        good_measurement = false;

        if (good_matches.size() >= 4) //OpenCV的solvePnPRANSAC 至少需要4对点
        {
            // -- Step 3: 使用RANSAC方法估算位姿
            pnp_detection.estimatePoseRANSAC(list_points3d_model_match, list_points2d_scene_match,
                pnpMethod, inliers_idx,
                iterationsCount, reprojectionError, confidence);

            // -- Step 4: 抓取内点
            for (int inliers_index = 0; inliers_index < inliers_idx.rows; ++inliers_index)
            {
                int n = inliers_idx.at<int>(inliers_index);         // i-inlier
                cv::Point2f point2d = list_points2d_scene_match[n];     // i-inlier point 2D
                list_points2d_inliers.push_back(point2d);           // add i-inlier to list
            }

            //蓝点标出内点
            draw2DPoints(frame_vis, list_points2d_inliers, blue);

            // -- Step 5: 卡尔曼滤波

            // 如果捕获成功
            if (inliers_idx.rows >= minInliersKalman)
            {
                // 获取平移向量
                cv::Mat translation_measured = pnp_detection.get_t_matrix();

                // 获取旋转矩阵
                cv::Mat rotation_measured = pnp_detection.get_R_matrix();

                // 转换为绕轴旋转的角度
                cv::Mat angle = rot2angle(rotation_measured);

                if (isfirstframe) {
                    //记录初始的平移向量和旋转角度
                    initTrans = translation_measured;
                    initRot = angle;
                    isfirstframe = false;
                }
                //求变化量
                deltaT = translation_measured - initTrans;
                deltaR = angle - initRot;
                //绘制6DoF信息
                //draw6DoF(frame_vis, deltaT, deltaR);
                // 填充变换向量
                fillMeasurements(measurements, translation_measured, rotation_measured);
                good_measurement = true;
            }

            // 更新卡尔曼滤波器,如果捕获失败了就使用估计位姿
            cv::Mat translation_estimated(3, 1, CV_64FC1);
            cv::Mat rotation_estimated(3, 3, CV_64FC1);
            updateKalmanFilter(KF, measurements, translation_estimated, rotation_estimated);

            if (good_measurement)
            {
                //绘制6DoF信息
                draw6DoF(frame_vis, deltaT, deltaR, true);
            }
            else {
                deltaT = translation_estimated - initTrans;
                cv::Mat angle = rot2angle(rotation_estimated);
                deltaR = angle - initRot;
                draw6DoF(frame_vis, deltaT, deltaR, false);
            }


            //draw6DoF(frame_vis, translation_estimated, rotation_estimated, red);
            // -- Step 6: 设置投影变换矩阵
            pnp_detection_est.set_P_matrix(rotation_estimated, translation_estimated);
        }

        // -- Step 7: 画上位置和坐标系
        float l = 5;
        std::vector<cv::Point2f> pose_points2d;
        if (!good_measurement || displayFilteredPose)
        {
            drawObjectMesh(frame_vis, &mesh, &pnp_detection_est, yellow); // 估计位姿(黄的)

            pose_points2d.push_back(pnp_detection_est.backproject3DPoint(cv::Point3f(0, 0, 0)));  // axis center
            pose_points2d.push_back(pnp_detection_est.backproject3DPoint(cv::Point3f(l, 0, 0)));  // axis x
            pose_points2d.push_back(pnp_detection_est.backproject3DPoint(cv::Point3f(0, l, 0)));  // axis y
            pose_points2d.push_back(pnp_detection_est.backproject3DPoint(cv::Point3f(0, 0, l)));  // axis z
            draw3DCoordinateAxes(frame_vis, pose_points2d);           // draw axes
        }
        else
        {
            drawObjectMesh(frame_vis, &mesh, &pnp_detection, green);  // 当前位姿(绿的)

            pose_points2d.push_back(pnp_detection.backproject3DPoint(cv::Point3f(0, 0, 0)));  // axis center
            pose_points2d.push_back(pnp_detection.backproject3DPoint(cv::Point3f(l, 0, 0)));  // axis x
            pose_points2d.push_back(pnp_detection.backproject3DPoint(cv::Point3f(0, l, 0)));  // axis y
            pose_points2d.push_back(pnp_detection.backproject3DPoint(cv::Point3f(0, 0, l)));  // axis z
            draw3DCoordinateAxes(frame_vis, pose_points2d);           // draw axes
        }
        // -- Step 8: 显示文字信息
        //8.1 实时帧速率
        tm.stop();
        double fps = 1.0 / tm.getTimeSec();
        drawFPS(frame_vis, fps, yellow);
        //8.2 实时置信度
        double detection_ratio = ((double)inliers_idx.rows / (double)good_matches.size()) * 100;
        drawConfidence(frame_vis, detection_ratio, yellow);//
        //8.3 特征点匹配的数量
        int inliers_int = inliers_idx.rows;
        int outliers_int = (int)good_matches.size() - inliers_int;
        std::string inliers_str = IntToString(inliers_int);
        std::string outliers_str = IntToString(outliers_int);
        std::string n = IntToString((int)good_matches.size());
        std::string text = "Found " + inliers_str + " of " + n + " matches";
        std::string text2 = "Inliers: " + inliers_str + " - Outliers: " + outliers_str;
        drawText(frame_vis, text, green);
        drawText2(frame_vis, text2, red);

        // -- Step 9: 把绘制好的图片显示出来
        cv::imshow("REAL TIME DEMO", frame_vis);

        // -- Step 10: 保存
        if (!saveDirectory.empty())
        {
            const int widthSave = !frame_matching.empty() ? frame_matching.cols : frame_vis.cols;
            const int heightSave = !frame_matching.empty() ? frame_matching.rows + frame_vis.rows : frame_vis.rows;
            cv::Mat frameSave = cv::Mat::zeros(heightSave, widthSave, CV_8UC3);
            if (!frame_matching.empty())
            {
                int startX = (int)((widthSave - frame_vis.cols) / 2.0);
                cv::Mat roi = frameSave(cv::Rect(startX, 0, frame_vis.cols, frame_vis.rows));
                frame_vis.copyTo(roi);

                roi = frameSave(cv::Rect(0, frame_vis.rows, frame_matching.cols, frame_matching.rows));
                frame_matching.copyTo(roi);
            }
            else
            {
                frame_vis.copyTo(frameSave);
            }

            std::string saveFilename = cv::format(std::string(saveDirectory + "/image_%04d.png").c_str(), frameCount);
            cv::imwrite(saveFilename, frameSave);
            frameCount++;
        }
    }//所有帧循环完毕 or 手动退出

    // 关闭窗口
    cv::destroyWindow("REAL TIME DEMO");

    std::cout << "GOODBYE ..." << std::endl;
}

void TextureTrackingParams::initKalmanFilter(cv::KalmanFilter& KF, int nStates, int nMeasurements, int nInputs, double dt)
{
    KF.init(nStates, nMeasurements, nInputs, CV_64F);                 // init Kalman Filter

    setIdentity(KF.processNoiseCov, cv::Scalar::all(1e-5));       // set process noise
    setIdentity(KF.measurementNoiseCov, cv::Scalar::all(1e-2));   // set measurement noise
    setIdentity(KF.errorCovPost, cv::Scalar::all(1));             // error covariance

    /** DYNAMIC MODEL **/

    //  [1 0 0 dt  0  0 dt2   0   0 0 0 0  0  0  0   0   0   0]
    //  [0 1 0  0 dt  0   0 dt2   0 0 0 0  0  0  0   0   0   0]
    //  [0 0 1  0  0 dt   0   0 dt2 0 0 0  0  0  0   0   0   0]
    //  [0 0 0  1  0  0  dt   0   0 0 0 0  0  0  0   0   0   0]
    //  [0 0 0  0  1  0   0  dt   0 0 0 0  0  0  0   0   0   0]
    //  [0 0 0  0  0  1   0   0  dt 0 0 0  0  0  0   0   0   0]
    //  [0 0 0  0  0  0   1   0   0 0 0 0  0  0  0   0   0   0]
    //  [0 0 0  0  0  0   0   1   0 0 0 0  0  0  0   0   0   0]
    //  [0 0 0  0  0  0   0   0   1 0 0 0  0  0  0   0   0   0]
    //  [0 0 0  0  0  0   0   0   0 1 0 0 dt  0  0 dt2   0   0]
    //  [0 0 0  0  0  0   0   0   0 0 1 0  0 dt  0   0 dt2   0]
    //  [0 0 0  0  0  0   0   0   0 0 0 1  0  0 dt   0   0 dt2]
    //  [0 0 0  0  0  0   0   0   0 0 0 0  1  0  0  dt   0   0]
    //  [0 0 0  0  0  0   0   0   0 0 0 0  0  1  0   0  dt   0]
    //  [0 0 0  0  0  0   0   0   0 0 0 0  0  0  1   0   0  dt]
    //  [0 0 0  0  0  0   0   0   0 0 0 0  0  0  0   1   0   0]
    //  [0 0 0  0  0  0   0   0   0 0 0 0  0  0  0   0   1   0]
    //  [0 0 0  0  0  0   0   0   0 0 0 0  0  0  0   0   0   1]

    // position
    KF.transitionMatrix.at<double>(0, 3) = dt;
    KF.transitionMatrix.at<double>(1, 4) = dt;
    KF.transitionMatrix.at<double>(2, 5) = dt;
    KF.transitionMatrix.at<double>(3, 6) = dt;
    KF.transitionMatrix.at<double>(4, 7) = dt;
    KF.transitionMatrix.at<double>(5, 8) = dt;
    KF.transitionMatrix.at<double>(0, 6) = 0.5 * pow(dt, 2);
    KF.transitionMatrix.at<double>(1, 7) = 0.5 * pow(dt, 2);
    KF.transitionMatrix.at<double>(2, 8) = 0.5 * pow(dt, 2);

    // orientation
    KF.transitionMatrix.at<double>(9, 12) = dt;
    KF.transitionMatrix.at<double>(10, 13) = dt;
    KF.transitionMatrix.at<double>(11, 14) = dt;
    KF.transitionMatrix.at<double>(12, 15) = dt;
    KF.transitionMatrix.at<double>(13, 16) = dt;
    KF.transitionMatrix.at<double>(14, 17) = dt;
    KF.transitionMatrix.at<double>(9, 15) = 0.5 * pow(dt, 2);
    KF.transitionMatrix.at<double>(10, 16) = 0.5 * pow(dt, 2);
    KF.transitionMatrix.at<double>(11, 17) = 0.5 * pow(dt, 2);


    /** MEASUREMENT MODEL **/

    //  [1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
    //  [0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
    //  [0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
    //  [0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0]
    //  [0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0]
    //  [0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0]

    KF.measurementMatrix.at<double>(0, 0) = 1;  // x
    KF.measurementMatrix.at<double>(1, 1) = 1;  // y
    KF.measurementMatrix.at<double>(2, 2) = 1;  // z
    KF.measurementMatrix.at<double>(3, 9) = 1;  // roll
    KF.measurementMatrix.at<double>(4, 10) = 1; // pitch
    KF.measurementMatrix.at<double>(5, 11) = 1; // yaw
}

void TextureTrackingParams::predictKalmanFilter(cv::KalmanFilter& KF, cv::Mat& translation_predicted, cv::Mat& rotation_predicted)
{
    //TODO:黑人问号???
}

void TextureTrackingParams::updateKalmanFilter(cv::KalmanFilter& KF, cv::Mat& measurements, cv::Mat& translation_estimated, cv::Mat& rotation_estimated)
{
    // First predict, to update the internal statePre variable
    cv::Mat prediction = KF.predict();

    // The "correct" phase that is going to use the predicted value and our measurement
    cv::Mat estimated = KF.correct(measurements);

    // Estimated translation
    translation_estimated.at<double>(0) = estimated.at<double>(0);
    translation_estimated.at<double>(1) = estimated.at<double>(1);
    translation_estimated.at<double>(2) = estimated.at<double>(2);

    // Estimated euler angles
    cv::Mat eulers_estimated(3, 1, CV_64F);
    eulers_estimated.at<double>(0) = estimated.at<double>(9);
    eulers_estimated.at<double>(1) = estimated.at<double>(10);
    eulers_estimated.at<double>(2) = estimated.at<double>(11);

    // Convert estimated quaternion to rotation matrix
    rotation_estimated = euler2rot(eulers_estimated);
}

void TextureTrackingParams::fillMeasurements(cv::Mat& measurements, const cv::Mat& translation_measured, const cv::Mat& rotation_measured)
{
    // Convert rotation matrix to euler angles
    cv::Mat measured_eulers(3, 1, CV_64F);
    measured_eulers = rot2euler(rotation_measured);

    // Set measurement to predict
    measurements.at<double>(0) = translation_measured.at<double>(0); // x
    measurements.at<double>(1) = translation_measured.at<double>(1); // y
    measurements.at<double>(2) = translation_measured.at<double>(2); // z
    measurements.at<double>(3) = measured_eulers.at<double>(0);      // roll
    measurements.at<double>(4) = measured_eulers.at<double>(1);      // pitch
    measurements.at<double>(5) = measured_eulers.at<double>(2);      // yaw
}

void TextureTrackingParams::onPush_cancel()
{

}
