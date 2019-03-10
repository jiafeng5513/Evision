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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCameraParamFile
{
public:
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_check;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QLineEdit *lineEdit_R;
    QLabel *label_10;
    QLineEdit *lineEdit_t;
    QPushButton *pushButton_save;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_fyl;
    QLineEdit *lineEdit_cyl;
    QLabel *label_2;
    QLabel *label_11;
    QLineEdit *lineEdit_coeffsl;
    QLineEdit *lineEdit_fxl;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_cxl;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_fxr;
    QLineEdit *lineEdit_fyr;
    QLineEdit *lineEdit_cxr;
    QLabel *label_12;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_cyr;
    QLabel *label_8;
    QLineEdit *lineEdit_coeffsr;
    QLineEdit *lineEdit_H;
    QLineEdit *lineEdit_W;
    QLabel *label_14;
    QLabel *label_15;

    void setupUi(QWidget *CreateCameraParamFile)
    {
        if (CreateCameraParamFile->objectName().isEmpty())
            CreateCameraParamFile->setObjectName(QString::fromUtf8("CreateCameraParamFile"));
        CreateCameraParamFile->resize(450, 403);
        gridLayout_4 = new QGridLayout(CreateCameraParamFile);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_check = new QPushButton(CreateCameraParamFile);
        pushButton_check->setObjectName(QString::fromUtf8("pushButton_check"));
        pushButton_check->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(pushButton_check, 3, 6, 1, 1);

        label_13 = new QLabel(CreateCameraParamFile);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_13, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 3, 5, 1, 1);

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


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 8);

        pushButton_save = new QPushButton(CreateCameraParamFile);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setMaximumSize(QSize(75, 16777215));

        gridLayout_4->addWidget(pushButton_save, 3, 7, 1, 1);

        splitter = new QSplitter(CreateCameraParamFile);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_fyl = new QLineEdit(groupBox);
        lineEdit_fyl->setObjectName(QString::fromUtf8("lineEdit_fyl"));

        gridLayout->addWidget(lineEdit_fyl, 1, 2, 1, 1);

        lineEdit_cyl = new QLineEdit(groupBox);
        lineEdit_cyl->setObjectName(QString::fromUtf8("lineEdit_cyl"));

        gridLayout->addWidget(lineEdit_cyl, 3, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 1, 1, 1);

        lineEdit_coeffsl = new QLineEdit(groupBox);
        lineEdit_coeffsl->setObjectName(QString::fromUtf8("lineEdit_coeffsl"));

        gridLayout->addWidget(lineEdit_coeffsl, 4, 2, 1, 1);

        lineEdit_fxl = new QLineEdit(groupBox);
        lineEdit_fxl->setObjectName(QString::fromUtf8("lineEdit_fxl"));

        gridLayout->addWidget(lineEdit_fxl, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        lineEdit_cxl = new QLineEdit(groupBox);
        lineEdit_cxl->setObjectName(QString::fromUtf8("lineEdit_cxl"));

        gridLayout->addWidget(lineEdit_cxl, 2, 2, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_fxr = new QLineEdit(groupBox_2);
        lineEdit_fxr->setObjectName(QString::fromUtf8("lineEdit_fxr"));

        gridLayout_2->addWidget(lineEdit_fxr, 0, 2, 1, 1);

        lineEdit_fyr = new QLineEdit(groupBox_2);
        lineEdit_fyr->setObjectName(QString::fromUtf8("lineEdit_fyr"));

        gridLayout_2->addWidget(lineEdit_fyr, 1, 2, 1, 1);

        lineEdit_cxr = new QLineEdit(groupBox_2);
        lineEdit_cxr->setObjectName(QString::fromUtf8("lineEdit_cxr"));

        gridLayout_2->addWidget(lineEdit_cxr, 2, 2, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 4, 0, 1, 2);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_cyr = new QLineEdit(groupBox_2);
        lineEdit_cyr->setObjectName(QString::fromUtf8("lineEdit_cyr"));

        gridLayout_2->addWidget(lineEdit_cyr, 3, 2, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        lineEdit_coeffsr = new QLineEdit(groupBox_2);
        lineEdit_coeffsr->setObjectName(QString::fromUtf8("lineEdit_coeffsr"));

        gridLayout_2->addWidget(lineEdit_coeffsr, 4, 2, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_4->addWidget(splitter, 1, 0, 1, 8);

        lineEdit_H = new QLineEdit(CreateCameraParamFile);
        lineEdit_H->setObjectName(QString::fromUtf8("lineEdit_H"));
        lineEdit_H->setMaximumSize(QSize(70, 16777215));

        gridLayout_4->addWidget(lineEdit_H, 3, 4, 1, 1);

        lineEdit_W = new QLineEdit(CreateCameraParamFile);
        lineEdit_W->setObjectName(QString::fromUtf8("lineEdit_W"));
        lineEdit_W->setMaximumSize(QSize(70, 16777215));

        gridLayout_4->addWidget(lineEdit_W, 3, 1, 1, 1);

        label_14 = new QLabel(CreateCameraParamFile);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(20, 16777215));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_14, 3, 2, 1, 1);

        label_15 = new QLabel(CreateCameraParamFile);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 0, 0, 1, 8);


        retranslateUi(CreateCameraParamFile);
        QObject::connect(pushButton_check, SIGNAL(clicked()), CreateCameraParamFile, SLOT(onPush_check()));
        QObject::connect(pushButton_save, SIGNAL(clicked()), CreateCameraParamFile, SLOT(onPush_save()));

        QMetaObject::connectSlotsByName(CreateCameraParamFile);
    } // setupUi

    void retranslateUi(QWidget *CreateCameraParamFile)
    {
        CreateCameraParamFile->setWindowTitle(QApplication::translate("CreateCameraParamFile", "CreateCameraParamFile", nullptr));
        pushButton_check->setText(QApplication::translate("CreateCameraParamFile", "\346\240\241\351\252\214", nullptr));
        label_13->setText(QApplication::translate("CreateCameraParamFile", "Size", nullptr));
        groupBox_3->setTitle(QApplication::translate("CreateCameraParamFile", "Extrinsics right to left", nullptr));
        label_9->setText(QApplication::translate("CreateCameraParamFile", "rotation", nullptr));
        lineEdit_R->setText(QApplication::translate("CreateCameraParamFile", "0.99970392236773942, -0.00099717419622094, 0.02431199798822164, 0.00081158461267936, 0.99997046758904728, 0.00764233473217429, -0.02431890073529978, -0.00762034076433111, 0.99967520799190679", nullptr));
        label_10->setText(QApplication::translate("CreateCameraParamFile", "translation", nullptr));
        lineEdit_t->setText(QApplication::translate("CreateCameraParamFile", "-120.53692550716567666, 0.20663185043340576, 1.50931374558159193", nullptr));
        pushButton_save->setText(QApplication::translate("CreateCameraParamFile", "\344\277\235\345\255\230", nullptr));
        groupBox->setTitle(QApplication::translate("CreateCameraParamFile", "Intrinsics left", nullptr));
        lineEdit_fyl->setText(QApplication::translate("CreateCameraParamFile", "360.66307482249675331", nullptr));
        lineEdit_cyl->setText(QApplication::translate("CreateCameraParamFile", "241.28155681229438301", nullptr));
        label_2->setText(QApplication::translate("CreateCameraParamFile", "fy", nullptr));
        label_11->setText(QApplication::translate("CreateCameraParamFile", "coeffs", nullptr));
        lineEdit_coeffsl->setText(QApplication::translate("CreateCameraParamFile", "-0.27325783486024036,0.05839269546925033,-0.00063147476946172,-0.00078944284175937,0.00000000000000000", nullptr));
        lineEdit_fxl->setText(QApplication::translate("CreateCameraParamFile", "359.53540708423275873", nullptr));
        label_4->setText(QApplication::translate("CreateCameraParamFile", "cy", nullptr));
        label->setText(QApplication::translate("CreateCameraParamFile", "fx", nullptr));
        label_3->setText(QApplication::translate("CreateCameraParamFile", "cx", nullptr));
        lineEdit_cxl->setText(QApplication::translate("CreateCameraParamFile", "375.20924285484744587", nullptr));
        groupBox_2->setTitle(QApplication::translate("CreateCameraParamFile", "Intrinsics right", nullptr));
        lineEdit_fxr->setText(QApplication::translate("CreateCameraParamFile", "363.61112395441432454", nullptr));
        lineEdit_fyr->setText(QApplication::translate("CreateCameraParamFile", "363.81186815047794880", nullptr));
        lineEdit_cxr->setText(QApplication::translate("CreateCameraParamFile", "360.90385993307830859", nullptr));
        label_12->setText(QApplication::translate("CreateCameraParamFile", "coeffs", nullptr));
        label_7->setText(QApplication::translate("CreateCameraParamFile", "cx", nullptr));
        label_5->setText(QApplication::translate("CreateCameraParamFile", "fx", nullptr));
        label_6->setText(QApplication::translate("CreateCameraParamFile", "fy", nullptr));
        lineEdit_cyr->setText(QApplication::translate("CreateCameraParamFile", "242.03655046527234163", nullptr));
        label_8->setText(QApplication::translate("CreateCameraParamFile", "cy", nullptr));
        lineEdit_coeffsr->setText(QApplication::translate("CreateCameraParamFile", "-0.30777940482497357, 0.08601316053877246, -0.00038514931477825, -0.00007709156114081, 0.00000000000000000", nullptr));
        lineEdit_H->setText(QApplication::translate("CreateCameraParamFile", "480", nullptr));
        lineEdit_W->setText(QApplication::translate("CreateCameraParamFile", "752", nullptr));
        label_14->setText(QApplication::translate("CreateCameraParamFile", "\303\227", nullptr));
        label_15->setText(QApplication::translate("CreateCameraParamFile", "\350\257\245\345\212\237\350\203\275\347\224\250\344\272\216\346\211\213\345\212\250\347\224\237\346\210\220\345\217\257\344\273\245\344\276\233\346\234\254\347\250\213\345\272\217\350\257\273\345\217\226\347\232\204\347\233\270\346\234\272\345\217\202\346\225\260\346\226\207\344\273\266\n"
"\345\234\250fx,fy,cx,cx\344\270\255\345\241\253\345\205\245\346\265\256\347\202\271\346\225\260,\350\277\231\345\233\233\344\270\252\346\225\260\346\230\257\347\233\270\346\234\272\345\206\205\345\217\202\347\237\251\351\230\265\344\270\255\347\232\204\345\233\233\344\270\252\346\234\211\346\225\210\346\225\260\345\255\227\n"
"\345\234\250coeffs\344\270\255\345\241\253\345\205\245\347\225\270\345\217\230\347\263\273\346\225\260,\347\225\270\345\217\230\347\263\273\346\225\260\345\217\257\344\273\245\345\220\253\346\234\2114\344\270\252\345\210\26014\344\270\252\345\210\206\351\207\217,\344\273\245\345\256\236\351\231\205\346\203\205\345\206\265\344\270\272\345\207\206.\n"
"\346\257\217\344\270\252\345\210\206\351\207\217\351"
                        "\203\275\346\230\257\344\270\200\344\270\252\346\265\256\347\202\271\346\225\260,\345\210\206\351\207\217\344\271\213\351\227\264\344\273\245\350\213\261\346\226\207\351\200\227\345\217\267\351\232\224\345\274\200.\n"
"rotation \346\230\2573x3\346\227\213\350\275\254\347\237\251\351\230\265,\344\276\235\346\254\241\345\241\253\345\205\245,\344\273\245\351\200\227\345\217\267\345\210\206\345\211\262\346\257\217\344\270\252\345\210\206\351\207\217.\n"
"translation \346\230\2573x1\345\271\263\347\247\273\345\220\221\351\207\217,\344\273\245\351\200\227\345\217\267\345\210\206\345\211\262\346\257\217\344\270\252\345\210\206\351\207\217.\n"
"\346\211\200\346\234\211\347\232\204\346\265\256\347\202\271\346\225\260\351\203\275\350\246\201\344\273\245\345\215\201\350\277\233\345\210\266\350\207\252\347\204\266\346\240\207\350\257\206\346\263\225\345\241\253\345\206\231,\344\276\213\345\246\2023.1415926,\344\270\215\350\203\275\344\275\277\347\224\250\347\247\221\345\255\246\350\256\241\346\225\260\346\263\225.\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCameraParamFile: public Ui_CreateCameraParamFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECAMERAPARAMFILE_H
