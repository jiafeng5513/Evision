/********************************************************************************
** Form generated from reading UI file 'TraceView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACEVIEW_H
#define UI_TRACEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RulerView
{
public:
    QGridLayout *gridLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_selectOrigin;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_RawDispOK;
    QCheckBox *checkBox_OriginOK;
    QCheckBox *checkBox_CameraParamOK;
    QPushButton *pushButton_selectCameraParam;
    QPushButton *pushButton_selectRawDisp;
    QPushButton *pushButton_start;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSlider *horizontalSlider_scale;
    QPushButton *pushButton_ImgSwitch;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_ImgX;
    QLineEdit *lineEdit_ImgY;
    QLabel *label_4;
    QLineEdit *lineEdit_Res;
    QLabel *label;
    QLabel *label_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QGridLayout *TraceLayout;

    void setupUi(QWidget *RulerView)
    {
        if (RulerView->objectName().isEmpty())
            RulerView->setObjectName(QString::fromUtf8("RulerView"));
        RulerView->resize(848, 483);
        gridLayout_3 = new QGridLayout(RulerView);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_2 = new QFrame(RulerView);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(300, 16777215));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(frame_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 2, -1, 2);
        pushButton_selectOrigin = new QPushButton(groupBox_2);
        pushButton_selectOrigin->setObjectName(QString::fromUtf8("pushButton_selectOrigin"));

        gridLayout_2->addWidget(pushButton_selectOrigin, 1, 2, 1, 1);

        frame = new QFrame(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 2, -1, 2);
        checkBox_RawDispOK = new QCheckBox(frame);
        checkBox_RawDispOK->setObjectName(QString::fromUtf8("checkBox_RawDispOK"));
        checkBox_RawDispOK->setCheckable(true);

        verticalLayout->addWidget(checkBox_RawDispOK);

        checkBox_OriginOK = new QCheckBox(frame);
        checkBox_OriginOK->setObjectName(QString::fromUtf8("checkBox_OriginOK"));
        checkBox_OriginOK->setCheckable(true);

        verticalLayout->addWidget(checkBox_OriginOK);

        checkBox_CameraParamOK = new QCheckBox(frame);
        checkBox_CameraParamOK->setObjectName(QString::fromUtf8("checkBox_CameraParamOK"));
        checkBox_CameraParamOK->setCheckable(true);

        verticalLayout->addWidget(checkBox_CameraParamOK);


        gridLayout_2->addWidget(frame, 0, 0, 4, 2);

        pushButton_selectCameraParam = new QPushButton(groupBox_2);
        pushButton_selectCameraParam->setObjectName(QString::fromUtf8("pushButton_selectCameraParam"));

        gridLayout_2->addWidget(pushButton_selectCameraParam, 2, 2, 1, 1);

        pushButton_selectRawDisp = new QPushButton(groupBox_2);
        pushButton_selectRawDisp->setObjectName(QString::fromUtf8("pushButton_selectRawDisp"));

        gridLayout_2->addWidget(pushButton_selectRawDisp, 0, 2, 1, 1);

        pushButton_start = new QPushButton(groupBox_2);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        gridLayout_2->addWidget(pushButton_start, 3, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 2, -1, 2);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        horizontalSlider_scale = new QSlider(groupBox_3);
        horizontalSlider_scale->setObjectName(QString::fromUtf8("horizontalSlider_scale"));
        horizontalSlider_scale->setMaximum(10);
        horizontalSlider_scale->setValue(10);
        horizontalSlider_scale->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_scale);

        pushButton_ImgSwitch = new QPushButton(groupBox_3);
        pushButton_ImgSwitch->setObjectName(QString::fromUtf8("pushButton_ImgSwitch"));

        horizontalLayout->addWidget(pushButton_ImgSwitch);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 110));
        groupBox->setMaximumSize(QSize(16777215, 110));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 2, -1, 2);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        lineEdit_ImgX = new QLineEdit(groupBox);
        lineEdit_ImgX->setObjectName(QString::fromUtf8("lineEdit_ImgX"));

        gridLayout->addWidget(lineEdit_ImgX, 1, 2, 1, 1);

        lineEdit_ImgY = new QLineEdit(groupBox);
        lineEdit_ImgY->setObjectName(QString::fromUtf8("lineEdit_ImgY"));

        gridLayout->addWidget(lineEdit_ImgY, 2, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_Res = new QLineEdit(groupBox);
        lineEdit_Res->setObjectName(QString::fromUtf8("lineEdit_Res"));

        gridLayout->addWidget(lineEdit_Res, 3, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_4 = new QGroupBox(frame_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 2, -1, 2);
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);


        verticalLayout_3->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 33, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout_3->addWidget(frame_2, 1, 1, 1, 1);

        scrollArea = new QScrollArea(RulerView);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 520, 461));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        TraceLayout = new QGridLayout();
        TraceLayout->setSpacing(0);
        TraceLayout->setObjectName(QString::fromUtf8("TraceLayout"));

        gridLayout_4->addLayout(TraceLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 2, 1);


        retranslateUi(RulerView);
        QObject::connect(pushButton_start, SIGNAL(clicked()), RulerView, SLOT(onStart()));
        QObject::connect(pushButton_selectRawDisp, SIGNAL(clicked()), RulerView, SLOT(onSelectRawDispFile()));
        QObject::connect(pushButton_selectOrigin, SIGNAL(clicked()), RulerView, SLOT(onSelectOriginImg()));
        QObject::connect(pushButton_selectCameraParam, SIGNAL(clicked()), RulerView, SLOT(onSelectCameraParamFile()));
        QObject::connect(pushButton_ImgSwitch, SIGNAL(clicked()), RulerView, SLOT(onSwitchImageToShow()));

        QMetaObject::connectSlotsByName(RulerView);
    } // setupUi

    void retranslateUi(QWidget *RulerView)
    {
        RulerView->setWindowTitle(QApplication::translate("RulerView", "\344\272\244\344\272\222\346\265\213\351\207\217", nullptr));
        groupBox_2->setTitle(QApplication::translate("RulerView", "\350\276\223\345\205\245", nullptr));
        pushButton_selectOrigin->setText(QApplication::translate("RulerView", "\345\216\237\345\233\276", nullptr));
        checkBox_RawDispOK->setText(QApplication::translate("RulerView", "\345\216\237\345\247\213\350\247\206\345\267\256\346\226\207\344\273\266", nullptr));
        checkBox_OriginOK->setText(QApplication::translate("RulerView", "\345\216\237\345\233\276", nullptr));
        checkBox_CameraParamOK->setText(QApplication::translate("RulerView", "\347\233\270\346\234\272\345\217\202\346\225\260\346\226\207\344\273\266", nullptr));
        pushButton_selectCameraParam->setText(QApplication::translate("RulerView", "\347\233\270\346\234\272\345\217\202\346\225\260\346\226\207\344\273\266", nullptr));
        pushButton_selectRawDisp->setText(QApplication::translate("RulerView", "\345\216\237\345\247\213\350\247\206\345\267\256\346\226\207\344\273\266", nullptr));
        pushButton_start->setText(QApplication::translate("RulerView", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        groupBox_3->setTitle(QApplication::translate("RulerView", "\346\230\276\347\244\272", nullptr));
        label_5->setText(QApplication::translate("RulerView", "\347\274\251\346\224\276:", nullptr));
        pushButton_ImgSwitch->setText(QApplication::translate("RulerView", "\345\210\207\346\215\242\347\224\273\351\235\242", nullptr));
        groupBox->setTitle(QApplication::translate("RulerView", "\347\273\223\346\236\234", nullptr));
        label_2->setText(QApplication::translate("RulerView", "X=", nullptr));
        label_4->setText(QApplication::translate("RulerView", "\350\267\235\347\246\273:", nullptr));
        label->setText(QApplication::translate("RulerView", "\345\233\276\345\203\217\347\251\272\351\227\264\345\235\220\346\240\207:", nullptr));
        label_3->setText(QApplication::translate("RulerView", "Y=", nullptr));
        groupBox_4->setTitle(QApplication::translate("RulerView", "\350\257\264\346\230\216", nullptr));
        label_6->setText(QApplication::translate("RulerView", "1.\351\274\240\346\240\207\347\202\271\345\207\273\346\265\213\350\267\235", nullptr));
        label_7->setText(QApplication::translate("RulerView", "2.[\345\210\207\346\215\242\347\224\273\351\235\242]\345\217\257\344\273\245\345\234\250\350\247\206\345\267\256\345\233\276\345\222\214\345\216\237\345\233\276\347\233\264\346\216\245\345\210\207\346\215\242\346\230\276\347\244\272", nullptr));
        label_8->setText(QApplication::translate("RulerView", "3.\350\267\235\347\246\273\345\200\274\347\232\204\345\215\225\344\275\215\345\217\226\345\206\263\344\272\216\346\240\207\345\256\232\346\227\266\350\276\223\345\205\245\347\232\204\346\240\207\345\256\232\346\235\277\345\260\272\345\257\270.", nullptr));
        label_9->setText(QApplication::translate("RulerView", "\344\276\213\345\246\202\344\275\277\347\224\250\346\226\271\346\240\274\350\276\271\351\225\277\344\270\27225mm\347\232\204\346\240\207\345\256\232\346\235\277,\350\276\223\345\205\245\345\260\272\345\257\270\344\270\27225,\n"
"\345\210\231\350\267\235\347\246\273\347\232\204\345\215\225\344\275\215\344\270\272mm,\n"
"\345\246\202\346\236\234\350\276\223\345\205\2452.5,\345\210\231\350\267\235\347\246\273\347\232\204\345\215\225\344\275\215\344\270\272cm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RulerView: public Ui_RulerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACEVIEW_H
