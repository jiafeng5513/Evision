/********************************************************************************
** Form generated from reading UI file 'StereoCameraView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOCAMERAVIEW_H
#define UI_STEREOCAMERAVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_StereoCameraView
{
public:
    QGridLayout *gridLayout_5;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_SaveTo;
    QPushButton *pushButton_FindSaveTo;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QSplitter *splitter;
    QFrame *frame;
    QGridLayout *gridLayout;
    QCameraViewfinder *viewfinderL;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QCameraViewfinder *viewfinder_R;
    QSplitter *splitter_2;
    QFrame *frame_5;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_Lresolution;
    QLabel *label_5;
    QComboBox *comboBox_LCodec;
    QLabel *label_6;
    QSlider *horizontalSlider_LQuality;
    QLabel *label_7;
    QSlider *horizontalSlider_LexposureCompensation;
    QComboBox *comboBox_Lcam;
    QFrame *frame_6;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *comboBox_Rresolution;
    QLabel *label_12;
    QComboBox *comboBox_RCodec;
    QLabel *label_8;
    QSlider *horizontalSlider_RQuality;
    QLabel *label_11;
    QSlider *horizontalSlider_RexposureCompensation;
    QComboBox *comboBox_Rcam;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_OpenCamera;
    QPushButton *pushButton_CloseCamera;
    QPushButton *pushButton_RefreshCam;
    QPushButton *pushButton_Shot;

    void setupUi(QWidget *StereoCameraView)
    {
        if (StereoCameraView->objectName().isEmpty())
            StereoCameraView->setObjectName(QString::fromUtf8("StereoCameraView"));
        StereoCameraView->resize(671, 442);
        gridLayout_5 = new QGridLayout(StereoCameraView);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        frame_3 = new QFrame(StereoCameraView);
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

        lcdNumber = new QLCDNumber(frame_3);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(12);
        lcdNumber->setFont(font);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setLineWidth(1);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(6);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setProperty("value", QVariant(1.000000000000000));

        horizontalLayout->addWidget(lcdNumber);


        gridLayout_5->addWidget(frame_3, 0, 0, 1, 2);

        splitter = new QSplitter(StereoCameraView);
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
        viewfinderL->setMinimumSize(QSize(320, 240));
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
        viewfinder_R->setMinimumSize(QSize(320, 240));
        viewfinder_R->setAutoFillBackground(true);

        gridLayout_2->addWidget(viewfinder_R, 0, 0, 1, 1);

        splitter->addWidget(frame_2);

        gridLayout_5->addWidget(splitter, 1, 0, 1, 2);

        splitter_2 = new QSplitter(StereoCameraView);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setMaximumSize(QSize(16777215, 130));
        splitter_2->setOrientation(Qt::Horizontal);
        frame_5 = new QFrame(splitter_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMaximumSize(QSize(16777215, 130));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        comboBox_Lresolution = new QComboBox(frame_5);
        comboBox_Lresolution->setObjectName(QString::fromUtf8("comboBox_Lresolution"));

        gridLayout_3->addWidget(comboBox_Lresolution, 1, 1, 1, 1);

        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 2, 1, 1);

        comboBox_LCodec = new QComboBox(frame_5);
        comboBox_LCodec->setObjectName(QString::fromUtf8("comboBox_LCodec"));

        gridLayout_3->addWidget(comboBox_LCodec, 1, 3, 1, 1);

        label_6 = new QLabel(frame_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        horizontalSlider_LQuality = new QSlider(frame_5);
        horizontalSlider_LQuality->setObjectName(QString::fromUtf8("horizontalSlider_LQuality"));
        horizontalSlider_LQuality->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_LQuality, 2, 1, 1, 1);

        label_7 = new QLabel(frame_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 2, 2, 1, 1);

        horizontalSlider_LexposureCompensation = new QSlider(frame_5);
        horizontalSlider_LexposureCompensation->setObjectName(QString::fromUtf8("horizontalSlider_LexposureCompensation"));
        horizontalSlider_LexposureCompensation->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_LexposureCompensation, 2, 3, 1, 1);

        comboBox_Lcam = new QComboBox(frame_5);
        comboBox_Lcam->setObjectName(QString::fromUtf8("comboBox_Lcam"));

        gridLayout_3->addWidget(comboBox_Lcam, 0, 1, 1, 3);

        splitter_2->addWidget(frame_5);
        frame_6 = new QFrame(splitter_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMaximumSize(QSize(16777215, 130));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_9 = new QLabel(frame_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(frame_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        comboBox_Rresolution = new QComboBox(frame_6);
        comboBox_Rresolution->setObjectName(QString::fromUtf8("comboBox_Rresolution"));

        gridLayout_4->addWidget(comboBox_Rresolution, 1, 1, 1, 1);

        label_12 = new QLabel(frame_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 1, 2, 1, 1);

        comboBox_RCodec = new QComboBox(frame_6);
        comboBox_RCodec->setObjectName(QString::fromUtf8("comboBox_RCodec"));

        gridLayout_4->addWidget(comboBox_RCodec, 1, 3, 1, 1);

        label_8 = new QLabel(frame_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        horizontalSlider_RQuality = new QSlider(frame_6);
        horizontalSlider_RQuality->setObjectName(QString::fromUtf8("horizontalSlider_RQuality"));
        horizontalSlider_RQuality->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_RQuality, 2, 1, 1, 1);

        label_11 = new QLabel(frame_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 2, 2, 1, 1);

        horizontalSlider_RexposureCompensation = new QSlider(frame_6);
        horizontalSlider_RexposureCompensation->setObjectName(QString::fromUtf8("horizontalSlider_RexposureCompensation"));
        horizontalSlider_RexposureCompensation->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_RexposureCompensation, 2, 3, 1, 1);

        comboBox_Rcam = new QComboBox(frame_6);
        comboBox_Rcam->setObjectName(QString::fromUtf8("comboBox_Rcam"));

        gridLayout_4->addWidget(comboBox_Rcam, 0, 1, 1, 3);

        splitter_2->addWidget(frame_6);

        gridLayout_5->addWidget(splitter_2, 2, 0, 1, 1);

        frame_4 = new QFrame(StereoCameraView);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMaximumSize(QSize(16777215, 25));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_OpenCamera = new QPushButton(frame_4);
        pushButton_OpenCamera->setObjectName(QString::fromUtf8("pushButton_OpenCamera"));

        horizontalLayout_2->addWidget(pushButton_OpenCamera);

        pushButton_CloseCamera = new QPushButton(frame_4);
        pushButton_CloseCamera->setObjectName(QString::fromUtf8("pushButton_CloseCamera"));

        horizontalLayout_2->addWidget(pushButton_CloseCamera);

        pushButton_RefreshCam = new QPushButton(frame_4);
        pushButton_RefreshCam->setObjectName(QString::fromUtf8("pushButton_RefreshCam"));

        horizontalLayout_2->addWidget(pushButton_RefreshCam);

        pushButton_Shot = new QPushButton(frame_4);
        pushButton_Shot->setObjectName(QString::fromUtf8("pushButton_Shot"));

        horizontalLayout_2->addWidget(pushButton_Shot);


        gridLayout_5->addWidget(frame_4, 3, 0, 1, 1);


        retranslateUi(StereoCameraView);
        QObject::connect(pushButton_FindSaveTo, SIGNAL(clicked()), StereoCameraView, SLOT(OnFindSavePath()));
        QObject::connect(comboBox_Lcam, SIGNAL(currentIndexChanged(QString)), StereoCameraView, SLOT(OnSelectedChanged_LCameraDevice(QString)));
        QObject::connect(comboBox_Lresolution, SIGNAL(currentIndexChanged(QString)), StereoCameraView, SLOT(OnSelectedChanged_LResolution(QString)));
        QObject::connect(comboBox_LCodec, SIGNAL(currentIndexChanged(QString)), StereoCameraView, SLOT(OnSelectedChanged_LCodec(QString)));
        QObject::connect(horizontalSlider_LQuality, SIGNAL(valueChanged(int)), StereoCameraView, SLOT(OnChanged_LQuality(int)));
        QObject::connect(horizontalSlider_LexposureCompensation, SIGNAL(valueChanged(int)), StereoCameraView, SLOT(OnChanged_LExposureCompensation(int)));
        QObject::connect(comboBox_Rcam, SIGNAL(currentIndexChanged(QString)), StereoCameraView, SLOT(OnSelectedChanged_RCameraDevice(QString)));
        QObject::connect(comboBox_Rresolution, SIGNAL(currentIndexChanged(QString)), StereoCameraView, SLOT(OnSelectedChanged_RResolution(QString)));
        QObject::connect(comboBox_RCodec, SIGNAL(currentIndexChanged(QString)), StereoCameraView, SLOT(OnSelectedChanged_RCodec(QString)));
        QObject::connect(horizontalSlider_RQuality, SIGNAL(valueChanged(int)), StereoCameraView, SLOT(OnChanged_RQuality(int)));
        QObject::connect(horizontalSlider_RexposureCompensation, SIGNAL(valueChanged(int)), StereoCameraView, SLOT(OnChanged_RExposureCompensation(int)));
        QObject::connect(pushButton_Shot, SIGNAL(clicked()), StereoCameraView, SLOT(OnShot()));
        QObject::connect(pushButton_CloseCamera, SIGNAL(clicked()), StereoCameraView, SLOT(OnCloseCamera()));
        QObject::connect(pushButton_OpenCamera, SIGNAL(clicked()), StereoCameraView, SLOT(OnOpenCamera()));

        QMetaObject::connectSlotsByName(StereoCameraView);
    } // setupUi

    void retranslateUi(QWidget *StereoCameraView)
    {
        StereoCameraView->setWindowTitle(QApplication::translate("StereoCameraView", "\345\217\214\347\233\256\347\233\270\346\234\272", nullptr));
        label->setText(QApplication::translate("StereoCameraView", "Save To:", nullptr));
        pushButton_FindSaveTo->setText(QApplication::translate("StereoCameraView", "\346\265\217\350\247\210", nullptr));
        label_2->setText(QApplication::translate("StereoCameraView", "\350\256\241\346\225\260\345\231\250:", nullptr));
        label_3->setText(QApplication::translate("StereoCameraView", "L\346\221\204\345\203\217\345\244\264:", nullptr));
        label_4->setText(QApplication::translate("StereoCameraView", "L\345\210\206\350\276\250\347\216\207:", nullptr));
        label_5->setText(QApplication::translate("StereoCameraView", "\345\233\276\347\211\207\346\240\274\345\274\217:", nullptr));
        label_6->setText(QApplication::translate("StereoCameraView", "\350\264\250\351\207\217:", nullptr));
        label_7->setText(QApplication::translate("StereoCameraView", "\346\233\235\345\205\211\350\241\245\345\201\277:", nullptr));
        label_9->setText(QApplication::translate("StereoCameraView", "R\346\221\204\345\203\217\345\244\264:", nullptr));
        label_10->setText(QApplication::translate("StereoCameraView", "R\345\210\206\350\276\250\347\216\207:", nullptr));
        label_12->setText(QApplication::translate("StereoCameraView", "\345\233\276\347\211\207\346\240\274\345\274\217:", nullptr));
        label_8->setText(QApplication::translate("StereoCameraView", "\350\264\250\351\207\217:", nullptr));
        label_11->setText(QApplication::translate("StereoCameraView", "\346\233\235\345\205\211\350\241\245\345\201\277:", nullptr));
        pushButton_OpenCamera->setText(QApplication::translate("StereoCameraView", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", nullptr));
        pushButton_CloseCamera->setText(QApplication::translate("StereoCameraView", "\345\205\263\351\227\255\346\221\204\345\203\217\345\244\264", nullptr));
        pushButton_RefreshCam->setText(QApplication::translate("StereoCameraView", "\345\210\267\346\226\260\346\221\204\345\203\217\345\244\264", nullptr));
        pushButton_Shot->setText(QApplication::translate("StereoCameraView", "\346\213\215\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StereoCameraView: public Ui_StereoCameraView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOCAMERAVIEW_H
