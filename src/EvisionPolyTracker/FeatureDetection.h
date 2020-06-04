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
    const double f = 45; // focal length in mm
    const double sx = 22.3, sy = 14.9;
    const double width = 2592, height = 1944;
    const double params_CANON[4] = { width * f / sx,   // fx
                                    height * f / sy,  // fy
                                    width / 2,      // cx
                                    height / 2 };    // cy

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

