/********************************************************************************
** Form generated from reading UI file 'RulerView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULERVIEW_H
#define UI_RULERVIEW_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "CustomGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_RulerView
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_selectDisp;
    QPushButton *pushButton_selectLeft;
    QPushButton *pushButton_selectPointCloud;
    QPushButton *pushButton_start;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_dispOK;
    QCheckBox *checkBox_leftOK;
    QCheckBox *checkBox_pointcloudOK;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_ImgX;
    QLineEdit *lineEdit_ImgY;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit_Res;
    QSplitter *splitter;
    CustomGraphicsView *customGraphicsView_O;
    CustomGraphicsView *customGraphicsView_D;

    void setupUi(QWidget *RulerView)
    {
        if (RulerView->objectName().isEmpty())
            RulerView->setObjectName(QString::fromUtf8("RulerView"));
        RulerView->resize(663, 374);
        gridLayout_3 = new QGridLayout(RulerView);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_2 = new QGroupBox(RulerView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_selectDisp = new QPushButton(groupBox_2);
        pushButton_selectDisp->setObjectName(QString::fromUtf8("pushButton_selectDisp"));

        gridLayout_2->addWidget(pushButton_selectDisp, 1, 0, 1, 1);

        pushButton_selectLeft = new QPushButton(groupBox_2);
        pushButton_selectLeft->setObjectName(QString::fromUtf8("pushButton_selectLeft"));

        gridLayout_2->addWidget(pushButton_selectLeft, 1, 1, 1, 1);

        pushButton_selectPointCloud = new QPushButton(groupBox_2);
        pushButton_selectPointCloud->setObjectName(QString::fromUtf8("pushButton_selectPointCloud"));

        gridLayout_2->addWidget(pushButton_selectPointCloud, 1, 2, 1, 1);

        pushButton_start = new QPushButton(groupBox_2);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));

        gridLayout_2->addWidget(pushButton_start, 1, 3, 1, 1);

        frame = new QFrame(groupBox_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_dispOK = new QCheckBox(frame);
        checkBox_dispOK->setObjectName(QString::fromUtf8("checkBox_dispOK"));
        checkBox_dispOK->setCheckable(true);

        horizontalLayout->addWidget(checkBox_dispOK);

        checkBox_leftOK = new QCheckBox(frame);
        checkBox_leftOK->setObjectName(QString::fromUtf8("checkBox_leftOK"));
        checkBox_leftOK->setCheckable(true);

        horizontalLayout->addWidget(checkBox_leftOK);

        checkBox_pointcloudOK = new QCheckBox(frame);
        checkBox_pointcloudOK->setObjectName(QString::fromUtf8("checkBox_pointcloudOK"));
        checkBox_pointcloudOK->setCheckable(true);

        horizontalLayout->addWidget(checkBox_pointcloudOK);


        gridLayout_2->addWidget(frame, 0, 0, 1, 4);


        gridLayout_3->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(RulerView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 110));
        groupBox->setMaximumSize(QSize(16777215, 110));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        lineEdit_ImgX = new QLineEdit(groupBox);
        lineEdit_ImgX->setObjectName(QString::fromUtf8("lineEdit_ImgX"));

        gridLayout->addWidget(lineEdit_ImgX, 0, 2, 1, 1);

        lineEdit_ImgY = new QLineEdit(groupBox);
        lineEdit_ImgY->setObjectName(QString::fromUtf8("lineEdit_ImgY"));

        gridLayout->addWidget(lineEdit_ImgY, 1, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        lineEdit_Res = new QLineEdit(groupBox);
        lineEdit_Res->setObjectName(QString::fromUtf8("lineEdit_Res"));

        gridLayout->addWidget(lineEdit_Res, 2, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 1, 1, 1);

        splitter = new QSplitter(RulerView);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        customGraphicsView_O = new CustomGraphicsView(splitter);
        customGraphicsView_O->setObjectName(QString::fromUtf8("customGraphicsView_O"));
        customGraphicsView_O->setMinimumSize(QSize(320, 240));
        customGraphicsView_O->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        customGraphicsView_O->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        customGraphicsView_O->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        splitter->addWidget(customGraphicsView_O);
        customGraphicsView_D = new CustomGraphicsView(splitter);
        customGraphicsView_D->setObjectName(QString::fromUtf8("customGraphicsView_D"));
        customGraphicsView_D->setMinimumSize(QSize(320, 240));
        customGraphicsView_D->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        customGraphicsView_D->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        customGraphicsView_D->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        splitter->addWidget(customGraphicsView_D);

        gridLayout_3->addWidget(splitter, 1, 0, 1, 2);


        retranslateUi(RulerView);
        QObject::connect(customGraphicsView_O, SIGNAL(mouseMove(int,int)), RulerView, SLOT(onMouseMove(int,int)));
        QObject::connect(customGraphicsView_O, SIGNAL(mouseLDown(int,int)), RulerView, SLOT(onMouseLButtonDown(int,int)));
        QObject::connect(customGraphicsView_O, SIGNAL(mouseRDown(int,int)), RulerView, SLOT(onMouseRButtonDown(int,int)));
        QObject::connect(customGraphicsView_D, SIGNAL(mouseLDown(int,int)), RulerView, SLOT(onMouseLButtonDown(int,int)));
        QObject::connect(customGraphicsView_D, SIGNAL(mouseMove(int,int)), RulerView, SLOT(onMouseMove(int,int)));
        QObject::connect(customGraphicsView_D, SIGNAL(mouseRDown(int,int)), RulerView, SLOT(onMouseRButtonDown(int,int)));
        QObject::connect(pushButton_selectDisp, SIGNAL(clicked()), RulerView, SLOT(onSelectDisparityMap()));
        QObject::connect(pushButton_selectLeft, SIGNAL(clicked()), RulerView, SLOT(onSelectleftMap()));
        QObject::connect(pushButton_selectPointCloud, SIGNAL(clicked()), RulerView, SLOT(onSelectPointcloudFile()));
        QObject::connect(pushButton_start, SIGNAL(clicked()), RulerView, SLOT(onStart()));

        QMetaObject::connectSlotsByName(RulerView);
    } // setupUi

    void retranslateUi(QWidget *RulerView)
    {
        RulerView->setWindowTitle(QApplication::translate("RulerView", "\344\272\244\344\272\222\346\265\213\351\207\217", nullptr));
        groupBox_2->setTitle(QApplication::translate("RulerView", "\350\276\223\345\205\245", nullptr));
        pushButton_selectDisp->setText(QApplication::translate("RulerView", "\350\247\206\345\267\256\345\233\276", nullptr));
        pushButton_selectLeft->setText(QApplication::translate("RulerView", "\345\267\246\350\247\206\345\233\276", nullptr));
        pushButton_selectPointCloud->setText(QApplication::translate("RulerView", "\347\202\271\344\272\221", nullptr));
        pushButton_start->setText(QApplication::translate("RulerView", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        checkBox_dispOK->setText(QApplication::translate("RulerView", "\350\247\206\345\267\256\345\233\276", nullptr));
        checkBox_leftOK->setText(QApplication::translate("RulerView", "\345\267\246\350\247\206\345\233\276", nullptr));
        checkBox_pointcloudOK->setText(QApplication::translate("RulerView", "\347\202\271\344\272\221\346\226\207\344\273\266", nullptr));
        groupBox->setTitle(QApplication::translate("RulerView", "Function and Result", nullptr));
        label_3->setText(QApplication::translate("RulerView", "Y=", nullptr));
        label->setText(QApplication::translate("RulerView", "\345\233\276\345\203\217\347\251\272\351\227\264\345\235\220\346\240\207:", nullptr));
        label_4->setText(QApplication::translate("RulerView", "\350\256\241\347\256\227\347\273\223\346\236\234:", nullptr));
        label_2->setText(QApplication::translate("RulerView", "X=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RulerView: public Ui_RulerView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULERVIEW_H
