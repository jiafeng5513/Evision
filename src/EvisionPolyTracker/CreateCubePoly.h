#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include "ui_CreateCubePoly.h"
/*
 * 
 */
class EvisionCreateCubePoly : public QDialog
{
    Q_OBJECT

public:
    EvisionCreateCubePoly(QWidget *parent = Q_NULLPTR);

private:
    Ui::EvisionCreateCubePolyClass ui;
    std::string save_path;
    double length = 0.0;
    double width = 0.0;
    double height = 0.0;

public slots:
    void onPush_confirm();
    void onPush_cancel();
};