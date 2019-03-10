/********************************************************************************
** Form generated from reading UI file 'CreateCameraParamFile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECAMERAPARAMFILE_H
#define UI_CREATECAMERAPARAMFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCameraParamFile
{
public:
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save;
    QPushButton *pushButton_check;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_12;
    QLineEdit *lineEdit_coeffsr;
    QLineEdit *lineEdit_cyr;
    QLineEdit *lineEdit_cxr;
    QLineEdit *lineEdit_fyr;
    QLineEdit *lineEdit_fxr;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QLineEdit *lineEdit_R;
    QLabel *label_10;
    QLineEdit *lineEdit_t;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_fxl;
    QLineEdit *lineEdit_fyl;
    QLineEdit *lineEdit_cxl;
    QLineEdit *lineEdit_cyl;
    QLabel *label_11;
    QLineEdit *lineEdit_coeffsl;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *CreateCameraParamFile)
    {
        if (CreateCameraParamFile->objectName().isEmpty())
            CreateCameraParamFile->setObjectName(QString::fromUtf8("CreateCameraParamFile"));
        CreateCameraParamFile->resize(775, 518);
        gridLayout_4 = new QGridLayout(CreateCameraParamFile);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 4, 0, 1, 3);

        pushButton_save = new QPushButton(CreateCameraParamFile);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(pushButton_save, 4, 4, 1, 1);

        pushButton_check = new QPushButton(CreateCameraParamFile);
        pushButton_check->setObjectName(QString::fromUtf8("pushButton_check"));
        pushButton_check->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(pushButton_check, 4, 3, 1, 1);

        groupBox_2 = new QGroupBox(CreateCameraParamFile);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 4, 0, 1, 2);

        lineEdit_coeffsr = new QLineEdit(groupBox_2);
        lineEdit_coeffsr->setObjectName(QString::fromUtf8("lineEdit_coeffsr"));

        gridLayout_2->addWidget(lineEdit_coeffsr, 4, 2, 1, 1);

        lineEdit_cyr = new QLineEdit(groupBox_2);
        lineEdit_cyr->setObjectName(QString::fromUtf8("lineEdit_cyr"));

        gridLayout_2->addWidget(lineEdit_cyr, 3, 2, 1, 1);

        lineEdit_cxr = new QLineEdit(groupBox_2);
        lineEdit_cxr->setObjectName(QString::fromUtf8("lineEdit_cxr"));

        gridLayout_2->addWidget(lineEdit_cxr, 2, 2, 1, 1);

        lineEdit_fyr = new QLineEdit(groupBox_2);
        lineEdit_fyr->setObjectName(QString::fromUtf8("lineEdit_fyr"));

        gridLayout_2->addWidget(lineEdit_fyr, 1, 2, 1, 1);

        lineEdit_fxr = new QLineEdit(groupBox_2);
        lineEdit_fxr->setObjectName(QString::fromUtf8("lineEdit_fxr"));

        gridLayout_2->addWidget(lineEdit_fxr, 0, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 2, 1, 3);

        groupBox_3 = new QGroupBox(CreateCameraParamFile);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_R = new QLineEdit(groupBox_3);
        lineEdit_R->setObjectName(QString::fromUtf8("lineEdit_R"));

        gridLayout_3->addWidget(lineEdit_R, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        lineEdit_t = new QLineEdit(groupBox_3);
        lineEdit_t->setObjectName(QString::fromUtf8("lineEdit_t"));

        gridLayout_3->addWidget(lineEdit_t, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 3, 0, 1, 5);

        groupBox = new QGroupBox(CreateCameraParamFile);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_fxl = new QLineEdit(groupBox);
        lineEdit_fxl->setObjectName(QString::fromUtf8("lineEdit_fxl"));

        gridLayout->addWidget(lineEdit_fxl, 0, 2, 1, 1);

        lineEdit_fyl = new QLineEdit(groupBox);
        lineEdit_fyl->setObjectName(QString::fromUtf8("lineEdit_fyl"));

        gridLayout->addWidget(lineEdit_fyl, 1, 2, 1, 1);

        lineEdit_cxl = new QLineEdit(groupBox);
        lineEdit_cxl->setObjectName(QString::fromUtf8("lineEdit_cxl"));

        gridLayout->addWidget(lineEdit_cxl, 2, 2, 1, 1);

        lineEdit_cyl = new QLineEdit(groupBox);
        lineEdit_cyl->setObjectName(QString::fromUtf8("lineEdit_cyl"));

        gridLayout->addWidget(lineEdit_cyl, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 1, 1, 1);

        lineEdit_coeffsl = new QLineEdit(groupBox);
        lineEdit_coeffsl->setObjectName(QString::fromUtf8("lineEdit_coeffsl"));

        gridLayout->addWidget(lineEdit_coeffsl, 4, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 2);


        retranslateUi(CreateCameraParamFile);

        QMetaObject::connectSlotsByName(CreateCameraParamFile);
    } // setupUi

    void retranslateUi(QWidget *CreateCameraParamFile)
    {
        CreateCameraParamFile->setWindowTitle(QApplication::translate("CreateCameraParamFile", "CreateCameraParamFile", nullptr));
        pushButton_save->setText(QApplication::translate("CreateCameraParamFile", "\344\277\235\345\255\230", nullptr));
        pushButton_check->setText(QApplication::translate("CreateCameraParamFile", "\346\240\241\351\252\214", nullptr));
        groupBox_2->setTitle(QApplication::translate("CreateCameraParamFile", "Intrinsics right", nullptr));
        label_5->setText(QApplication::translate("CreateCameraParamFile", "fx", nullptr));
        label_6->setText(QApplication::translate("CreateCameraParamFile", "fy", nullptr));
        label_7->setText(QApplication::translate("CreateCameraParamFile", "cx", nullptr));
        label_8->setText(QApplication::translate("CreateCameraParamFile", "cy", nullptr));
        label_12->setText(QApplication::translate("CreateCameraParamFile", "coeffs", nullptr));
        groupBox_3->setTitle(QApplication::translate("CreateCameraParamFile", "Extrinsics right to left", nullptr));
        label_9->setText(QApplication::translate("CreateCameraParamFile", "rotation", nullptr));
        label_10->setText(QApplication::translate("CreateCameraParamFile", "translation", nullptr));
        groupBox->setTitle(QApplication::translate("CreateCameraParamFile", "Intrinsics left", nullptr));
        label_11->setText(QApplication::translate("CreateCameraParamFile", "coeffs", nullptr));
        label_4->setText(QApplication::translate("CreateCameraParamFile", "cy", nullptr));
        label_3->setText(QApplication::translate("CreateCameraParamFile", "cx", nullptr));
        label_2->setText(QApplication::translate("CreateCameraParamFile", "fy", nullptr));
        label->setText(QApplication::translate("CreateCameraParamFile", "fx", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCameraParamFile: public Ui_CreateCameraParamFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECAMERAPARAMFILE_H
