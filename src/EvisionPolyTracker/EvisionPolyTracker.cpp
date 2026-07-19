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
    //connect(ui.xSlider, &QSlider::valueChanged, ui.openGLWidget, &TrackerGLWidget::setXRotation);
    //connect(ui.ySlider, &QSlider::valueChanged, ui.openGLWidget, &TrackerGLWidget::setYRotation);
    //connect(ui.zSlider, &QSlider::valueChanged, ui.openGLWidget, &TrackerGLWidget::setZRotation);

    //connect(ui.openGLWidget, &TrackerGLWidget::xRotationChanged, ui.xSlider, &QSlider::setValue);
    //connect(ui.openGLWidget, &TrackerGLWidget::yRotationChanged, ui.ySlider, &QSlider::setValue);
    //connect(ui.openGLWidget, &TrackerGLWidget::zRotationChanged, ui.zSlider, &QSlider::setValue);

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

