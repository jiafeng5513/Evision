#include "FeatureDetection.h"
#include "EvisionUtils.h"
#include <QDateTime>
#include <QMessageBox>
#include <thread>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/features2d.hpp>
#include <QFileInfo>
//静态变量初始化

bool EvisionFeatureDetection::end_registration = false;
int EvisionFeatureDetection::pts[8] = { 1,2,3,4,5,6,7,8 };
ModelRegistration EvisionFeatureDetection::registration = ModelRegistration();
Mesh EvisionFeatureDetection::mesh = Mesh();
EvisionFeatureDetection::EvisionFeatureDetection(QWidget* parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    std::string datapath = EvisionUtils::pathPurify(EvisionUtils::getCurrentPath() + "\\..\\..\\..\\data\\Tracker");

    this->img_path = datapath + "/object.jpg";
    this->ply_read_path = datapath + "/box.ply";
    this->write_path = datapath + "/test_reg";
    this->numKeyPoints = 2000;
    this->featureName = "ORB";
    this->fx = 5230.493273542601;
    this->fy = 5871.140939597315;
    this->cx = 1296.0;
    this->cy = 972.0;
    ui.lineEdit_fx->setText(QString::number(this->fx));
    ui.lineEdit_fy->setText(QString::number(this->fy));
    ui.lineEdit_cx->setText(QString::number(this->cx));
    ui.lineEdit_cy->setText(QString::number(this->cy));

    ui.lineEdit_img_path->setText(QString::fromStdString(this->img_path));
    ui.lineEdit_ply_read_path->setText(QString::fromStdString(this->ply_read_path));
    ui.lineEdit_write_path->setText(QString::fromStdString(this->write_path));

    ui.lineEdit_numKeyPoints->setText(QString::number(numKeyPoints, 10));
    //ui.comboBox_featureName->
}

//确认,启动后台线程
void EvisionFeatureDetection::onPush_confirm() 
{
    QFileInfo* fileinfo_img_path = new QFileInfo(ui.lineEdit_img_path->text());
    QFileInfo* fileinfo_ply_read_path = new QFileInfo(ui.lineEdit_ply_read_path->text());
    QFileInfo* fileinfo_write_path = new QFileInfo(ui.lineEdit_write_path->text());

    if ((fileinfo_img_path->exists()&& fileinfo_img_path->isFile()) &&
        (fileinfo_ply_read_path->exists() && fileinfo_ply_read_path->isFile()) &&
        (fileinfo_write_path->exists() && fileinfo_write_path->isDir()) &&
        (this->numKeyPoints = ui.lineEdit_numKeyPoints->text().toInt())>0 &&
        (this->fx = ui.lineEdit_fx->text().toDouble()) > 0 &&
        (this->fy = ui.lineEdit_fy->text().toDouble()) > 0 &&
        (this->cx = ui.lineEdit_cx->text().toDouble()) > 0 &&
        (this->cy = ui.lineEdit_cy->text().toDouble()) > 0 )
    {
        //参数传递
        this->featureName = ui.comboBox_featureName->currentText().toStdString();
        this->img_path = ui.lineEdit_img_path->text().toStdString();
        this->ply_read_path = ui.lineEdit_ply_read_path->text().toStdString();
        this->write_path = ui.lineEdit_write_path->text().toStdString();

        std::thread _t(&EvisionFeatureDetection::RegistrationThread, this);
        _t.detach();
        std::cout << "注册线程启动..." << std::endl;
    }
    else
    {
        QMessageBox::information(this, QStringLiteral("注意"), QStringLiteral("参数不完整!"));
    }
}
// 线程方法:执行执行特征工程
void EvisionFeatureDetection::RegistrationThread()
{
    Model model;
    double params_CANON[4] = {this->fx,this->fy,this->cx,this->cy};
    PnPProblem pnp_registration(params_CANON);


    std::cout << "Input image: " << img_path << std::endl;
    std::cout << "CAD model: " << ply_read_path << std::endl;
    std::cout << "Output training file: " << write_path << std::endl;
    std::cout << "Feature: " << featureName << std::endl;
    std::cout << "Number of keypoints for ORB: " << numKeyPoints << std::endl;

    // load a mesh given the *.ply file path
    mesh.load(ply_read_path);

    //Instantiate robust matcher: detector, extractor, matcher
    RobustMatcher rmatcher;
    cv::Ptr<cv::Feature2D> detector, descriptor;
    createFeatures(featureName, numKeyPoints, detector, descriptor);
    rmatcher.setFeatureDetector(detector);
    rmatcher.setDescriptorExtractor(descriptor);


    /**  GROUND TRUTH OF THE FIRST IMAGE  **/

    // Create & Open Window
    cv::namedWindow("MODEL REGISTRATION", cv::WINDOW_KEEPRATIO);

    // Set up the mouse events
    cv::setMouseCallback("MODEL REGISTRATION", EvisionFeatureDetection::onMouseModelRegistration, 0);

    // Open the image to register
    cv::Mat img_in = cv::imread(img_path, cv::IMREAD_COLOR);
    cv::Mat img_vis;

    if (img_in.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return ;
    }

    // Set the number of points to register
    int num_registrations = n;
    registration.setNumMax(num_registrations);

    std::cout << "Click the box corners ..." << std::endl;
    std::cout << "Waiting ..." << std::endl;

    // Some basic colors
    const cv::Scalar red(0, 0, 255);
    const cv::Scalar green(0, 255, 0);
    const cv::Scalar blue(255, 0, 0);
    const cv::Scalar yellow(0, 255, 255);

    // Loop until all the points are registered
    while (cv::waitKey(30) < 0)
    {
        // Refresh debug image
        img_vis = img_in.clone();

        // Current registered points
        std::vector<cv::Point2f> list_points2d = registration.get_points2d();
        std::vector<cv::Point3f> list_points3d = registration.get_points3d();

        // Draw current registered points
        drawPoints(img_vis, list_points2d, list_points3d, red);

        // If the registration is not finished, draw which 3D point we have to register.
        // If the registration is finished, breaks the loop.
        if (!end_registration)
        {
            // Draw debug text
            int n_regist = registration.getNumRegist();
            int n_vertex = pts[n_regist];
            cv::Point3f current_poin3d = mesh.getVertex(n_vertex - 1);

            drawQuestion(img_vis, current_poin3d, green);
            drawCounter(img_vis, registration.getNumRegist(), registration.getNumMax(), red);
        }
        else
        {
            // Draw debug text
            drawText(img_vis, "END REGISTRATION", green);
            drawCounter(img_vis, registration.getNumRegist(), registration.getNumMax(), green);
            break;
        }

        // Show the image
        imshow("MODEL REGISTRATION", img_vis);
    }

    /** COMPUTE CAMERA POSE **/

    std::cout << "COMPUTING POSE ..." << std::endl;

    // The list of registered points
    std::vector<cv::Point2f> list_points2d = registration.get_points2d();
    std::vector<cv::Point3f> list_points3d = registration.get_points3d();

    // Estimate pose given the registered points
    bool is_correspondence = pnp_registration.estimatePose(list_points3d, list_points2d, cv::SOLVEPNP_ITERATIVE);
    if (is_correspondence)
    {
        std::cout << "Correspondence found" << std::endl;

        // Compute all the 2D points of the mesh to verify the algorithm and draw it
        std::vector<cv::Point2f> list_points2d_mesh = pnp_registration.verify_points(&mesh);
        draw2DPoints(img_vis, list_points2d_mesh, green);
    }
    else {
        std::cout << "Correspondence not found" << std::endl << std::endl;
    }

    // Show the image
    cv::imshow("MODEL REGISTRATION", img_vis);

    // Show image until ESC pressed
    cv::waitKey(0);


    /** COMPUTE 3D of the image Keypoints **/

    // Containers for keypoints and descriptors of the model
    std::vector<cv::KeyPoint> keypoints_model;
    cv::Mat descriptors;

    // Compute keypoints and descriptors
    rmatcher.computeKeyPoints(img_in, keypoints_model);
    rmatcher.computeDescriptors(img_in, keypoints_model, descriptors);

    // Check if keypoints are on the surface of the registration image and add to the model
    for (unsigned int i = 0; i < keypoints_model.size(); ++i) {
        cv::Point2f point2d(keypoints_model[i].pt);
        cv::Point3f point3d;
        bool on_surface = pnp_registration.backproject2DPoint(&mesh, point2d, point3d);
        if (on_surface)
        {
            model.add_correspondence(point2d, point3d);
            model.add_descriptor(descriptors.row(i));
            model.add_keypoint(keypoints_model[i]);
        }
        else
        {
            model.add_outlier(point2d);
        }
    }

    model.set_trainingImagePath(img_path);
    // save the model into a *.yaml file
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyyMMddhhmmss");
    std::string yamlFileName = this->write_path + "/cookie_" + current_date.toStdString() + ".yaml";

    model.save(yamlFileName);
    std::cout << "已经保存到:" << yamlFileName << std::endl;
    // Out image
    img_vis = img_in.clone();

    // The list of the points2d of the model
    std::vector<cv::Point2f> list_points_in = model.get_points2d_in();
    std::vector<cv::Point2f> list_points_out = model.get_points2d_out();

    // Draw some debug text
    std::string num = IntToString((int)list_points_in.size());
    std::string text = "There are " + num + " inliers";
    drawText(img_vis, text, green);

    // Draw some debug text
    num = IntToString((int)list_points_out.size());
    text = "There are " + num + " outliers";
    drawText2(img_vis, text, red);

    // Draw the object mesh
    drawObjectMesh(img_vis, &mesh, &pnp_registration, blue);

    // Draw found keypoints depending on if are or not on the surface
    draw2DPoints(img_vis, list_points_in, green);
    draw2DPoints(img_vis, list_points_out, red);

    // Show the image
    imshow("MODEL REGISTRATION", img_vis);

    // Wait until ESC pressed
    cv::waitKey(0);

    // Close and Destroy Window
    cv::destroyWindow("MODEL REGISTRATION");

    std::cout << "GOODBYE" << std::endl;
}

void EvisionFeatureDetection::onMouseModelRegistration(int event, int x, int y, int, void*)
{
    if (event == cv::EVENT_LBUTTONUP)
    {
        bool is_registrable = registration.is_registrable();
        if (is_registrable)
        {
            int n_regist = registration.getNumRegist();
            int n_vertex = pts[n_regist];

            cv::Point2f point_2d = cv::Point2f((float)x, (float)y);
            cv::Point3f point_3d = mesh.getVertex(n_vertex - 1);

            registration.registerPoint(point_2d, point_3d);
            if (registration.getNumRegist() == registration.getNumMax()) 
                end_registration = true;
        }
    }
}

void EvisionFeatureDetection::onPush_cancel()
{
    this->close();
}
