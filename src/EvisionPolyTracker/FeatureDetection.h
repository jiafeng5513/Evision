#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include "ui_FeatureDetection.h"
// PnP Tutorial
#include "Mesh.h"
#include "Model.h"
#include "PnPProblem.h"
#include "RobustMatcher.h"
#include "ModelRegistration.h"
#include "Utils.h"
/*
 * 
 */
class EvisionFeatureDetection : public QDialog
{
    Q_OBJECT

public:
    EvisionFeatureDetection(QWidget *parent = Q_NULLPTR);

private:
    Ui::FeatureDetectionClass ui;
    std::string img_path;
    std::string ply_read_path;
    std::string write_path;
    int numKeyPoints;
    std::string featureName;
    // Boolean the know if the registration it's done
    static bool end_registration;

    // 相机内参
    //double f = 45; // focal length in mm
    //double sx = 22.3, sy = 14.9;
    //double width = 2592, height = 1944;
    //double params_CANON[4] = { width * f / sx,   // fx = 5230.493273542601
    //                                height * f / sy,   // fy = 5871.140939597315
    //                                width / 2,         // cx = 1296.0
    //                                height / 2 };      // cy = 972.0

    double fx,fy,cx,cy;

    // Setup the points to register in the image
    // In the order of the *.ply file and starting at 1
    const int n = 8;
    static int pts[8]; // 3 -> 4
    /*
 * CREATE MODEL REGISTRATION OBJECT
 * CREATE OBJECT MESH
 * CREATE OBJECT MODEL
 * CREATE PNP OBJECT
 */
    static ModelRegistration registration;
    static Mesh mesh;

private:
    void RegistrationThread();
    static void onMouseModelRegistration(int event, int x, int y, int, void*);
public slots:
    void onPush_confirm();
    void onPush_cancel();
};

