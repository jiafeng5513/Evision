/********************************************************************************
** Form generated from reading UI file 'StereoCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOCAMERA_H
#define UI_STEREOCAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StereoCamera
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QGraphicsView *graphicsView_L;
    QGraphicsView *graphicsView_R;
    QComboBox *comboBox_Rresolution;
    QLabel *label_3;
    QLabel *label_6;
    QComboBox *comboBox_Lresolution;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_Lcam;
    QComboBox *comboBox_Rcam;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_ParamLock;
    QPushButton *pushButton_FindSaveTo;
    QLineEdit *lineEdit_SaveTo;
    QPushButton *pushButton_Shot;
    QLineEdit *lineEdit_Prefix;
    QLabel *label;
    QPushButton *pushButton_RefreshCam;
    QPushButton *pushButton_CamSwitch;
    QPushButton *pushButton_Rec;

    void setupUi(QWidget *StereoCamera)
    {
        if (StereoCamera->objectName().isEmpty())
            StereoCamera->setObjectName(QStringLiteral("StereoCamera"));
        StereoCamera->resize(946, 450);
        gridLayout = new QGridLayout(StereoCamera);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(StereoCamera);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        graphicsView_L = new QGraphicsView(splitter);
        graphicsView_L->setObjectName(QStringLiteral("graphicsView_L"));
        splitter->addWidget(graphicsView_L);
        graphicsView_R = new QGraphicsView(splitter);
        graphicsView_R->setObjectName(QStringLiteral("graphicsView_R"));
        splitter->addWidget(graphicsView_R);

        gridLayout->addWidget(splitter, 0, 0, 2, 4);

        comboBox_Rresolution = new QComboBox(StereoCamera);
        comboBox_Rresolution->setObjectName(QStringLiteral("comboBox_Rresolution"));

        gridLayout->addWidget(comboBox_Rresolution, 3, 3, 1, 1);

        label_3 = new QLabel(StereoCamera);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 20));
        label_3->setMaximumSize(QSize(50, 20));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_6 = new QLabel(StereoCamera);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(50, 20));
        label_6->setMaximumSize(QSize(50, 20));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        comboBox_Lresolution = new QComboBox(StereoCamera);
        comboBox_Lresolution->setObjectName(QStringLiteral("comboBox_Lresolution"));

        gridLayout->addWidget(comboBox_Lresolution, 3, 1, 1, 1);

        label_4 = new QLabel(StereoCamera);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 20));
        label_4->setMaximumSize(QSize(50, 20));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(StereoCamera);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(50, 20));
        label_5->setMaximumSize(QSize(50, 20));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        comboBox_Lcam = new QComboBox(StereoCamera);
        comboBox_Lcam->setObjectName(QStringLiteral("comboBox_Lcam"));

        gridLayout->addWidget(comboBox_Lcam, 2, 1, 1, 1);

        comboBox_Rcam = new QComboBox(StereoCamera);
        comboBox_Rcam->setObjectName(QStringLiteral("comboBox_Rcam"));

        gridLayout->addWidget(comboBox_Rcam, 2, 3, 1, 1);

        frame = new QFrame(StereoCamera);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 75));
        frame->setMaximumSize(QSize(16777215, 75));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        pushButton_ParamLock = new QPushButton(frame);
        pushButton_ParamLock->setObjectName(QStringLiteral("pushButton_ParamLock"));

        gridLayout_2->addWidget(pushButton_ParamLock, 1, 3, 1, 1);

        pushButton_FindSaveTo = new QPushButton(frame);
        pushButton_FindSaveTo->setObjectName(QStringLiteral("pushButton_FindSaveTo"));

        gridLayout_2->addWidget(pushButton_FindSaveTo, 1, 2, 1, 1);

        lineEdit_SaveTo = new QLineEdit(frame);
        lineEdit_SaveTo->setObjectName(QStringLiteral("lineEdit_SaveTo"));

        gridLayout_2->addWidget(lineEdit_SaveTo, 1, 1, 1, 1);

        pushButton_Shot = new QPushButton(frame);
        pushButton_Shot->setObjectName(QStringLiteral("pushButton_Shot"));

        gridLayout_2->addWidget(pushButton_Shot, 1, 4, 1, 1);

        lineEdit_Prefix = new QLineEdit(frame);
        lineEdit_Prefix->setObjectName(QStringLiteral("lineEdit_Prefix"));

        gridLayout_2->addWidget(lineEdit_Prefix, 0, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pushButton_RefreshCam = new QPushButton(frame);
        pushButton_RefreshCam->setObjectName(QStringLiteral("pushButton_RefreshCam"));

        gridLayout_2->addWidget(pushButton_RefreshCam, 0, 2, 1, 1);

        pushButton_CamSwitch = new QPushButton(frame);
        pushButton_CamSwitch->setObjectName(QStringLiteral("pushButton_CamSwitch"));

        gridLayout_2->addWidget(pushButton_CamSwitch, 0, 3, 1, 1);

        pushButton_Rec = new QPushButton(frame);
        pushButton_Rec->setObjectName(QStringLiteral("pushButton_Rec"));

        gridLayout_2->addWidget(pushButton_Rec, 0, 4, 1, 1);


        gridLayout->addWidget(frame, 6, 0, 1, 4);


        retranslateUi(StereoCamera);

        QMetaObject::connectSlotsByName(StereoCamera);
    } // setupUi

    void retranslateUi(QWidget *StereoCamera)
    {
        StereoCamera->setWindowTitle(QApplication::translate("StereoCamera", "StereoCamera", nullptr));
        label_3->setText(QApplication::translate("StereoCamera", "L\345\210\206\350\276\250\347\216\207:", nullptr));
        label_6->setText(QApplication::translate("StereoCamera", "R\345\210\206\350\276\250\347\216\207:", nullptr));
        label_4->setText(QApplication::translate("StereoCamera", "L\346\221\204\345\203\217\346\234\272;", nullptr));
        label_5->setText(QApplication::translate("StereoCamera", "R\346\221\204\345\203\217\346\234\272;", nullptr));
        label_2->setText(QApplication::translate("StereoCamera", "Save To:", nullptr));
        pushButton_ParamLock->setText(QApplication::translate("StereoCamera", "\351\224\201\345\256\232\350\247\243\351\224\201", nullptr));
        pushButton_FindSaveTo->setText(QApplication::translate("StereoCamera", "\346\265\217\350\247\210", nullptr));
        pushButton_Shot->setText(QApplication::translate("StereoCamera", "\346\213\215\347\205\247", nullptr));
        label->setText(QApplication::translate("StereoCamera", "Prefix:", nullptr));
        pushButton_RefreshCam->setText(QApplication::translate("StereoCamera", "\345\210\267\346\226\260\351\225\234\345\244\264", nullptr));
        pushButton_CamSwitch->setText(QApplication::translate("StereoCamera", "\345\274\200\345\205\263\351\225\234\345\244\264", nullptr));
        pushButton_Rec->setText(QApplication::translate("StereoCamera", "\345\275\225\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StereoCamera: public Ui_StereoCamera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOCAMERA_H
