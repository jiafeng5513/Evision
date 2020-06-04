#pragma once

#include <QtWidgets/QWidget>
#include "ui_EvisionPolyTracker.h"
#include "TrackerGLWidget.h"
/*
 * 
 */
class EvisionPolyTracker : public QWidget
{
    Q_OBJECT

public:
    EvisionPolyTracker(QWidget *parent = Q_NULLPTR);

private:
    Ui::EvisionPolyTrackerClass ui;
public slots:
    void onButtonDown_CreatePoly();
    void onButtonDown_FeatureDetection();
    void onButtonDown_TextureTracking();

};
