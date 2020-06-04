#include "EvisionPolyTracker.h"
#include "CreateCubePoly.h"
#include "FeatureDetection.h"
#include "TextureTrackingParams.h"

EvisionPolyTracker::EvisionPolyTracker(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //this->trackerGLWidget = new TrackerGLWidget(this);

    //connections
    //connect(ui.xSlider, SIGNAL(valueChanged(int)), ui.openGLWidget, SLOT(setXRotation(int)));
    //connect(ui.ySlider, SIGNAL(valueChanged(int)), ui.openGLWidget, SLOT(setYRotation(int)));
    //connect(ui.zSlider, SIGNAL(valueChanged(int)), ui.openGLWidget, SLOT(setZRotation(int)));

    //connect(ui.openGLWidget, SIGNAL(xRotationChanged(int)), ui.xSlider, SLOT(setValue(int)));
    //connect(ui.openGLWidget, SIGNAL(yRotationChanged(int)), ui.ySlider, SLOT(setValue(int)));
    //connect(ui.openGLWidget, SIGNAL(zRotationChanged(int)), ui.zSlider, SLOT(setValue(int)));

    //ui.xSlider->setValue(15 * 16);
    //ui.ySlider->setValue(345 * 16);
    //ui.zSlider->setValue(0 * 16);
    
}
//创建盒子的ply
void EvisionPolyTracker::onButtonDown_CreatePoly() {
    auto createPolyView = new EvisionCreateCubePoly(this);
    createPolyView->show();
}
//特征检测
void EvisionPolyTracker::onButtonDown_FeatureDetection()
{
    auto featureDetectionView = new EvisionFeatureDetection(this);
    featureDetectionView->show();
}
//追踪
void EvisionPolyTracker::onButtonDown_TextureTracking()
{
    auto textureTrackingParamsView = new TextureTrackingParams(this);
    textureTrackingParamsView->show();
}

