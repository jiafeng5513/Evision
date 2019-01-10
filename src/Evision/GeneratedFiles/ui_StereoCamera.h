/********************************************************************************
** Form generated from reading UI file 'StereoCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOCAMERA_H
#define UI_STEREOCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_StereoCamera
{
public:
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QFrame *frame;
    QGridLayout *gridLayout;
    QCameraViewfinder *viewfinderL;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QCameraViewfinder *viewfinder_R;
    QLabel *label_3;
    QComboBox *comboBox_Lcam;
    QLabel *label_9;
    QComboBox *comboBox_Rcam;
    QLabel *label_4;
    QComboBox *comboBox_Lresolution;
    QLabel *label_5;
    QComboBox *comboBox_LCodec;
    QLabel *label_10;
    QComboBox *comboBox_Rresolution;
    QLabel *label_12;
    QComboBox *comboBox_RCodec;
    QLabel *label_6;
    QSlider *horizontalSlider_LQuality;
    QLabel *label_7;
    QSlider *horizontalSlider_LexposureCompensation;
    QLabel *label_8;
    QSlider *horizontalSlider_RQuality;
    QLabel *label_11;
    QSlider *horizontalSlider_RexposureCompensation;
    QPushButton *pushButton_RefreshCam;
    QPushButton *pushButton_Shot;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_SaveTo;
    QPushButton *pushButton_FindSaveTo;
    QLabel *label_2;
    QLineEdit *lineEdit_Prefix;

    void setupUi(QWidget *StereoCamera)
    {
        if (StereoCamera->objectName().isEmpty())
            StereoCamera->setObjectName(QString::fromUtf8("StereoCamera"));
        StereoCamera->resize(975, 487);
        gridLayout_3 = new QGridLayout(StereoCamera);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(StereoCamera);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        viewfinderL = new QCameraViewfinder(frame);
        viewfinderL->setObjectName(QString::fromUtf8("viewfinderL"));
        viewfinderL->setAutoFillBackground(true);

        gridLayout->addWidget(viewfinderL, 0, 0, 1, 1);

        splitter->addWidget(frame);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        viewfinder_R = new QCameraViewfinder(frame_2);
        viewfinder_R->setObjectName(QString::fromUtf8("viewfinder_R"));
        viewfinder_R->setAutoFillBackground(true);

        gridLayout_2->addWidget(viewfinder_R, 0, 0, 1, 1);

        splitter->addWidget(frame_2);

        gridLayout_3->addWidget(splitter, 1, 0, 1, 9);

        label_3 = new QLabel(StereoCamera);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        comboBox_Lcam = new QComboBox(StereoCamera);
        comboBox_Lcam->setObjectName(QString::fromUtf8("comboBox_Lcam"));

        gridLayout_3->addWidget(comboBox_Lcam, 2, 1, 1, 3);

        label_9 = new QLabel(StereoCamera);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 4, 1, 1);

        comboBox_Rcam = new QComboBox(StereoCamera);
        comboBox_Rcam->setObjectName(QString::fromUtf8("comboBox_Rcam"));

        gridLayout_3->addWidget(comboBox_Rcam, 2, 5, 1, 4);

        label_4 = new QLabel(StereoCamera);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);

        comboBox_Lresolution = new QComboBox(StereoCamera);
        comboBox_Lresolution->setObjectName(QString::fromUtf8("comboBox_Lresolution"));

        gridLayout_3->addWidget(comboBox_Lresolution, 3, 1, 1, 1);

        label_5 = new QLabel(StereoCamera);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 3, 2, 1, 1);

        comboBox_LCodec = new QComboBox(StereoCamera);
        comboBox_LCodec->setObjectName(QString::fromUtf8("comboBox_LCodec"));

        gridLayout_3->addWidget(comboBox_LCodec, 3, 3, 1, 1);

        label_10 = new QLabel(StereoCamera);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 3, 4, 1, 1);

        comboBox_Rresolution = new QComboBox(StereoCamera);
        comboBox_Rresolution->setObjectName(QString::fromUtf8("comboBox_Rresolution"));

        gridLayout_3->addWidget(comboBox_Rresolution, 3, 5, 1, 1);

        label_12 = new QLabel(StereoCamera);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 3, 6, 1, 1);

        comboBox_RCodec = new QComboBox(StereoCamera);
        comboBox_RCodec->setObjectName(QString::fromUtf8("comboBox_RCodec"));

        gridLayout_3->addWidget(comboBox_RCodec, 3, 7, 1, 2);

        label_6 = new QLabel(StereoCamera);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 4, 0, 1, 1);

        horizontalSlider_LQuality = new QSlider(StereoCamera);
        horizontalSlider_LQuality->setObjectName(QString::fromUtf8("horizontalSlider_LQuality"));
        horizontalSlider_LQuality->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_LQuality, 4, 1, 1, 1);

        label_7 = new QLabel(StereoCamera);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 4, 2, 1, 1);

        horizontalSlider_LexposureCompensation = new QSlider(StereoCamera);
        horizontalSlider_LexposureCompensation->setObjectName(QString::fromUtf8("horizontalSlider_LexposureCompensation"));
        horizontalSlider_LexposureCompensation->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_LexposureCompensation, 4, 3, 1, 1);

        label_8 = new QLabel(StereoCamera);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 4, 4, 1, 1);

        horizontalSlider_RQuality = new QSlider(StereoCamera);
        horizontalSlider_RQuality->setObjectName(QString::fromUtf8("horizontalSlider_RQuality"));
        horizontalSlider_RQuality->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_RQuality, 4, 5, 1, 1);

        label_11 = new QLabel(StereoCamera);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 4, 6, 1, 1);

        horizontalSlider_RexposureCompensation = new QSlider(StereoCamera);
        horizontalSlider_RexposureCompensation->setObjectName(QString::fromUtf8("horizontalSlider_RexposureCompensation"));
        horizontalSlider_RexposureCompensation->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_RexposureCompensation, 4, 7, 1, 2);

        pushButton_RefreshCam = new QPushButton(StereoCamera);
        pushButton_RefreshCam->setObjectName(QString::fromUtf8("pushButton_RefreshCam"));

        gridLayout_3->addWidget(pushButton_RefreshCam, 5, 7, 1, 1);

        pushButton_Shot = new QPushButton(StereoCamera);
        pushButton_Shot->setObjectName(QString::fromUtf8("pushButton_Shot"));

        gridLayout_3->addWidget(pushButton_Shot, 5, 8, 1, 1);

        frame_3 = new QFrame(StereoCamera);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 43));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_SaveTo = new QLineEdit(frame_3);
        lineEdit_SaveTo->setObjectName(QString::fromUtf8("lineEdit_SaveTo"));

        horizontalLayout->addWidget(lineEdit_SaveTo);

        pushButton_FindSaveTo = new QPushButton(frame_3);
        pushButton_FindSaveTo->setObjectName(QString::fromUtf8("pushButton_FindSaveTo"));
        pushButton_FindSaveTo->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(pushButton_FindSaveTo);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_Prefix = new QLineEdit(frame_3);
        lineEdit_Prefix->setObjectName(QString::fromUtf8("lineEdit_Prefix"));

        horizontalLayout->addWidget(lineEdit_Prefix);


        gridLayout_3->addWidget(frame_3, 0, 0, 1, 9);


        retranslateUi(StereoCamera);
        QObject::connect(pushButton_FindSaveTo, SIGNAL(clicked()), StereoCamera, SLOT(OnFindSavePath()));
        QObject::connect(comboBox_Lcam, SIGNAL(currentIndexChanged(QString)), StereoCamera, SLOT(OnSelectedChanged_LCameraDevice(QString)));
        QObject::connect(comboBox_Lresolution, SIGNAL(currentIndexChanged(QString)), StereoCamera, SLOT(OnSelectedChanged_LResolution(QString)));
        QObject::connect(comboBox_LCodec, SIGNAL(currentIndexChanged(QString)), StereoCamera, SLOT(OnSelectedChanged_LCodec(QString)));
        QObject::connect(horizontalSlider_LQuality, SIGNAL(valueChanged(int)), StereoCamera, SLOT(OnChanged_LQuality(int)));
        QObject::connect(horizontalSlider_LexposureCompensation, SIGNAL(valueChanged(int)), StereoCamera, SLOT(OnChanged_LExposureCompensation(int)));
        QObject::connect(comboBox_Rcam, SIGNAL(currentIndexChanged(QString)), StereoCamera, SLOT(OnSelectedChanged_RCameraDevice(QString)));
        QObject::connect(comboBox_Rresolution, SIGNAL(currentIndexChanged(QString)), StereoCamera, SLOT(OnSelectedChanged_RResolution(QString)));
        QObject::connect(comboBox_RCodec, SIGNAL(currentIndexChanged(QString)), StereoCamera, SLOT(OnSelectedChanged_RCodec(QString)));
        QObject::connect(horizontalSlider_RQuality, SIGNAL(valueChanged(int)), StereoCamera, SLOT(OnChanged_RQuality(int)));
        QObject::connect(horizontalSlider_RexposureCompensation, SIGNAL(valueChanged(int)), StereoCamera, SLOT(OnChanged_RExposureCompensation(int)));
        QObject::connect(pushButton_Shot, SIGNAL(clicked()), StereoCamera, SLOT(OnShot()));

        QMetaObject::connectSlotsByName(StereoCamera);
    } // setupUi

    void retranslateUi(QWidget *StereoCamera)
    {
        StereoCamera->setWindowTitle(QApplication::translate("StereoCamera", "Form", nullptr));
        label_3->setText(QApplication::translate("StereoCamera", "L\346\221\204\345\203\217\345\244\264:", nullptr));
        label_9->setText(QApplication::translate("StereoCamera", "R\346\221\204\345\203\217\345\244\264:", nullptr));
        label_4->setText(QApplication::translate("StereoCamera", "L\345\210\206\350\276\250\347\216\207:", nullptr));
        label_5->setText(QApplication::translate("StereoCamera", "\345\233\276\347\211\207\346\240\274\345\274\217:", nullptr));
        label_10->setText(QApplication::translate("StereoCamera", "R\345\210\206\350\276\250\347\216\207:", nullptr));
        label_12->setText(QApplication::translate("StereoCamera", "\345\233\276\347\211\207\346\240\274\345\274\217:", nullptr));
        label_6->setText(QApplication::translate("StereoCamera", "\350\264\250\351\207\217:", nullptr));
        label_7->setText(QApplication::translate("StereoCamera", "\346\233\235\345\205\211\350\241\245\345\201\277:", nullptr));
        label_8->setText(QApplication::translate("StereoCamera", "\350\264\250\351\207\217:", nullptr));
        label_11->setText(QApplication::translate("StereoCamera", "\346\233\235\345\205\211\350\241\245\345\201\277:", nullptr));
        pushButton_RefreshCam->setText(QApplication::translate("StereoCamera", "\345\210\267\346\226\260\346\221\204\345\203\217\345\244\264", nullptr));
        pushButton_Shot->setText(QApplication::translate("StereoCamera", "\346\213\215\347\205\247", nullptr));
        label->setText(QApplication::translate("StereoCamera", "Save To:", nullptr));
        pushButton_FindSaveTo->setText(QApplication::translate("StereoCamera", "\346\265\217\350\247\210", nullptr));
        label_2->setText(QApplication::translate("StereoCamera", "Prefix:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StereoCamera: public Ui_StereoCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOCAMERA_H
