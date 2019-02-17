/********************************************************************************
** Form generated from reading UI file 'CameraView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAVIEW_H
#define UI_CAMERAVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_CameraView
{
public:
    QGridLayout *gridLayout_6;
    QFrame *frame;
    QGridLayout *gridLayout;
    QPushButton *pushButton_CameraOn;
    QPushButton *pushButton_CameraOff;
    QPushButton *pushButton_Focus;
    QPushButton *pushButton_Shot;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider_exposureCompensation;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider_Quality;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_CameraDevice;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_Resolution;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QComboBox *comboBox_Codec;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QGridLayout *gridLayout_5;
    QCameraViewfinder *viewfinder;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_FindSavePath;
    QLineEdit *lineEdit_SavePath;
    QLabel *label;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *CameraView)
    {
        if (CameraView->objectName().isEmpty())
            CameraView->setObjectName(QString::fromUtf8("CameraView"));
        CameraView->resize(858, 553);
        gridLayout_6 = new QGridLayout(CameraView);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frame = new QFrame(CameraView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_CameraOn = new QPushButton(frame);
        pushButton_CameraOn->setObjectName(QString::fromUtf8("pushButton_CameraOn"));
        pushButton_CameraOn->setMinimumSize(QSize(0, 0));
        pushButton_CameraOn->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_CameraOn, 0, 0, 1, 1);

        pushButton_CameraOff = new QPushButton(frame);
        pushButton_CameraOff->setObjectName(QString::fromUtf8("pushButton_CameraOff"));
        pushButton_CameraOff->setEnabled(true);
        pushButton_CameraOff->setMinimumSize(QSize(0, 0));
        pushButton_CameraOff->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_CameraOff, 0, 1, 1, 1);

        pushButton_Focus = new QPushButton(frame);
        pushButton_Focus->setObjectName(QString::fromUtf8("pushButton_Focus"));
        pushButton_Focus->setEnabled(true);
        pushButton_Focus->setMinimumSize(QSize(0, 0));
        pushButton_Focus->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_Focus, 1, 0, 1, 1);

        pushButton_Shot = new QPushButton(frame);
        pushButton_Shot->setObjectName(QString::fromUtf8("pushButton_Shot"));
        pushButton_Shot->setEnabled(true);
        pushButton_Shot->setMinimumSize(QSize(0, 0));
        pushButton_Shot->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(pushButton_Shot, 1, 1, 1, 1);


        gridLayout_6->addWidget(frame, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(CameraView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(200, 16777215));
        groupBox_2->setFlat(true);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSlider_exposureCompensation = new QSlider(groupBox_2);
        horizontalSlider_exposureCompensation->setObjectName(QString::fromUtf8("horizontalSlider_exposureCompensation"));
        horizontalSlider_exposureCompensation->setEnabled(true);
        horizontalSlider_exposureCompensation->setMinimumSize(QSize(170, 0));
        horizontalSlider_exposureCompensation->setMaximumSize(QSize(170, 16777215));
        horizontalSlider_exposureCompensation->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalSlider_exposureCompensation->setMinimum(-4);
        horizontalSlider_exposureCompensation->setMaximum(4);
        horizontalSlider_exposureCompensation->setPageStep(2);
        horizontalSlider_exposureCompensation->setOrientation(Qt::Horizontal);
        horizontalSlider_exposureCompensation->setTickPosition(QSlider::TicksAbove);

        horizontalLayout->addWidget(horizontalSlider_exposureCompensation);


        gridLayout_6->addWidget(groupBox_2, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(CameraView);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(200, 16777215));
        groupBox_3->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSlider_Quality = new QSlider(groupBox_3);
        horizontalSlider_Quality->setObjectName(QString::fromUtf8("horizontalSlider_Quality"));
        horizontalSlider_Quality->setEnabled(true);
        horizontalSlider_Quality->setMinimumSize(QSize(170, 0));
        horizontalSlider_Quality->setMaximumSize(QSize(170, 16777215));
        horizontalSlider_Quality->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalSlider_Quality->setOrientation(Qt::Horizontal);
        horizontalSlider_Quality->setTickPosition(QSlider::TicksAbove);

        horizontalLayout_2->addWidget(horizontalSlider_Quality);


        gridLayout_6->addWidget(groupBox_3, 3, 1, 1, 1);

        groupBox = new QGroupBox(CameraView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        groupBox->setFlat(true);
        groupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox_CameraDevice = new QComboBox(groupBox);
        comboBox_CameraDevice->setObjectName(QString::fromUtf8("comboBox_CameraDevice"));
        comboBox_CameraDevice->setMinimumSize(QSize(170, 0));
        comboBox_CameraDevice->setMaximumSize(QSize(170, 16777215));

        gridLayout_2->addWidget(comboBox_CameraDevice, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox, 4, 1, 1, 1);

        groupBox_4 = new QGroupBox(CameraView);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(200, 16777215));
        groupBox_4->setFlat(true);
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        comboBox_Resolution = new QComboBox(groupBox_4);
        comboBox_Resolution->setObjectName(QString::fromUtf8("comboBox_Resolution"));
        comboBox_Resolution->setMinimumSize(QSize(170, 0));
        comboBox_Resolution->setMaximumSize(QSize(170, 16777215));

        gridLayout_3->addWidget(comboBox_Resolution, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_4, 5, 1, 1, 1);

        groupBox_5 = new QGroupBox(CameraView);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(200, 16777215));
        groupBox_5->setFlat(true);
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        comboBox_Codec = new QComboBox(groupBox_5);
        comboBox_Codec->setObjectName(QString::fromUtf8("comboBox_Codec"));
        comboBox_Codec->setMinimumSize(QSize(170, 0));
        comboBox_Codec->setMaximumSize(QSize(170, 16777215));

        gridLayout_4->addWidget(comboBox_Codec, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_5, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 7, 1, 1, 1);

        frame_2 = new QFrame(CameraView);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        viewfinder = new QCameraViewfinder(frame_2);
        viewfinder->setObjectName(QString::fromUtf8("viewfinder"));
        viewfinder->setMinimumSize(QSize(640, 480));
        viewfinder->setAutoFillBackground(true);

        gridLayout_5->addWidget(viewfinder, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_2, 1, 0, 7, 1);

        frame_4 = new QFrame(CameraView);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMaximumSize(QSize(16777215, 16777215));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_FindSavePath = new QPushButton(frame_4);
        pushButton_FindSavePath->setObjectName(QString::fromUtf8("pushButton_FindSavePath"));

        horizontalLayout_3->addWidget(pushButton_FindSavePath);

        lineEdit_SavePath = new QLineEdit(frame_4);
        lineEdit_SavePath->setObjectName(QString::fromUtf8("lineEdit_SavePath"));
        lineEdit_SavePath->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_SavePath);

        label = new QLabel(frame_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lcdNumber = new QLCDNumber(frame_4);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout_3->addWidget(lcdNumber);


        gridLayout_6->addWidget(frame_4, 0, 0, 1, 2);


        retranslateUi(CameraView);
        QObject::connect(pushButton_FindSavePath, SIGNAL(clicked()), CameraView, SLOT(OnFindSavePath()));
        QObject::connect(pushButton_CameraOn, SIGNAL(clicked()), CameraView, SLOT(OnCameraPowerOn()));
        QObject::connect(pushButton_CameraOff, SIGNAL(clicked()), CameraView, SLOT(OnCameraPowerOff()));
        QObject::connect(pushButton_Focus, SIGNAL(clicked()), CameraView, SLOT(OnFocus()));
        QObject::connect(pushButton_Shot, SIGNAL(clicked()), CameraView, SLOT(OnShot()));
        QObject::connect(horizontalSlider_exposureCompensation, SIGNAL(valueChanged(int)), CameraView, SLOT(OnValueChanged_ExposureCompensation(int)));
        QObject::connect(horizontalSlider_Quality, SIGNAL(valueChanged(int)), CameraView, SLOT(OnValueChanged_Quality(int)));
        QObject::connect(comboBox_CameraDevice, SIGNAL(currentIndexChanged(QString)), CameraView, SLOT(OnSelectedChanged_CameraDevice(QString)));
        QObject::connect(comboBox_Resolution, SIGNAL(currentIndexChanged(QString)), CameraView, SLOT(OnSelectedChanged_Resolution(QString)));
        QObject::connect(comboBox_Codec, SIGNAL(currentIndexChanged(QString)), CameraView, SLOT(OnSelectedChanged_Codec(QString)));

        QMetaObject::connectSlotsByName(CameraView);
    } // setupUi

    void retranslateUi(QWidget *CameraView)
    {
        CameraView->setWindowTitle(QApplication::translate("CameraView", "\347\233\270\346\234\272", nullptr));
        pushButton_CameraOn->setText(QApplication::translate("CameraView", "\346\221\204\345\203\217\346\234\272\345\274\200", nullptr));
        pushButton_CameraOff->setText(QApplication::translate("CameraView", "\346\221\204\345\203\217\346\234\272\345\205\263", nullptr));
        pushButton_Focus->setText(QApplication::translate("CameraView", "Focus", nullptr));
        pushButton_Shot->setText(QApplication::translate("CameraView", "\346\213\215\347\205\247", nullptr));
        groupBox_2->setTitle(QApplication::translate("CameraView", "\346\233\235\345\205\211\350\241\245\345\201\277", nullptr));
        groupBox_3->setTitle(QApplication::translate("CameraView", "\345\233\276\347\211\207\350\264\250\351\207\217", nullptr));
        groupBox->setTitle(QApplication::translate("CameraView", "\346\221\204\345\203\217\345\244\264", nullptr));
        groupBox_4->setTitle(QApplication::translate("CameraView", "\345\210\206\350\276\250\347\216\207", nullptr));
        groupBox_5->setTitle(QApplication::translate("CameraView", "\345\233\276\347\211\207\346\240\274\345\274\217", nullptr));
        pushButton_FindSavePath->setText(QApplication::translate("CameraView", "\344\277\235\345\255\230\345\210\260", nullptr));
        label->setText(QApplication::translate("CameraView", "\350\256\241\346\225\260\345\231\250:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraView: public Ui_CameraView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAVIEW_H
