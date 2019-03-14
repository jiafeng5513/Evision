/********************************************************************************
** Form generated from reading UI file 'EvisionRectify.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVISIONRECTIFY_H
#define UI_EVISIONRECTIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EvisionRectify
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_src;
    QPushButton *pushButton_addTotargetList;
    QPushButton *pushButton_Start;
    QListWidget *listWidget_Target;
    QLabel *label_2;
    QListWidget *listWidget_Src;
    QPushButton *pushButton_RemoveFromTarget;
    QPushButton *pushButton_SelectSrc;
    QLineEdit *lineEdit_target;
    QPushButton *pushButton_SelectTarget;
    QLabel *label;
    QPushButton *pushButton_SelectCameraParams;
    QProgressBar *progressBar;
    QLabel *label_3;

    void setupUi(QWidget *EvisionRectify)
    {
        if (EvisionRectify->objectName().isEmpty())
            EvisionRectify->setObjectName(QString::fromUtf8("EvisionRectify"));
        EvisionRectify->resize(901, 479);
        gridLayout = new QGridLayout(EvisionRectify);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_src = new QLineEdit(EvisionRectify);
        lineEdit_src->setObjectName(QString::fromUtf8("lineEdit_src"));

        gridLayout->addWidget(lineEdit_src, 1, 1, 1, 1);

        pushButton_addTotargetList = new QPushButton(EvisionRectify);
        pushButton_addTotargetList->setObjectName(QString::fromUtf8("pushButton_addTotargetList"));

        gridLayout->addWidget(pushButton_addTotargetList, 2, 4, 1, 1);

        pushButton_Start = new QPushButton(EvisionRectify);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));

        gridLayout->addWidget(pushButton_Start, 5, 4, 1, 1);

        listWidget_Target = new QListWidget(EvisionRectify);
        listWidget_Target->setObjectName(QString::fromUtf8("listWidget_Target"));

        gridLayout->addWidget(listWidget_Target, 2, 5, 4, 4);

        label_2 = new QLabel(EvisionRectify);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        listWidget_Src = new QListWidget(EvisionRectify);
        listWidget_Src->setObjectName(QString::fromUtf8("listWidget_Src"));
        listWidget_Src->setSelectionRectVisible(true);

        gridLayout->addWidget(listWidget_Src, 2, 0, 4, 4);

        pushButton_RemoveFromTarget = new QPushButton(EvisionRectify);
        pushButton_RemoveFromTarget->setObjectName(QString::fromUtf8("pushButton_RemoveFromTarget"));

        gridLayout->addWidget(pushButton_RemoveFromTarget, 3, 4, 1, 1);

        pushButton_SelectSrc = new QPushButton(EvisionRectify);
        pushButton_SelectSrc->setObjectName(QString::fromUtf8("pushButton_SelectSrc"));

        gridLayout->addWidget(pushButton_SelectSrc, 1, 2, 1, 1);

        lineEdit_target = new QLineEdit(EvisionRectify);
        lineEdit_target->setObjectName(QString::fromUtf8("lineEdit_target"));

        gridLayout->addWidget(lineEdit_target, 1, 7, 1, 1);

        pushButton_SelectTarget = new QPushButton(EvisionRectify);
        pushButton_SelectTarget->setObjectName(QString::fromUtf8("pushButton_SelectTarget"));

        gridLayout->addWidget(pushButton_SelectTarget, 1, 8, 1, 1);

        label = new QLabel(EvisionRectify);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 50));

        gridLayout->addWidget(label, 1, 6, 1, 1);

        pushButton_SelectCameraParams = new QPushButton(EvisionRectify);
        pushButton_SelectCameraParams->setObjectName(QString::fromUtf8("pushButton_SelectCameraParams"));

        gridLayout->addWidget(pushButton_SelectCameraParams, 1, 3, 1, 3);

        progressBar = new QProgressBar(EvisionRectify);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 6, 0, 1, 9);

        label_3 = new QLabel(EvisionRectify);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(label_3, 7, 0, 1, 9);


        retranslateUi(EvisionRectify);
        QObject::connect(pushButton_SelectSrc, SIGNAL(clicked()), EvisionRectify, SLOT(onPush_SelectSrcFolder()));
        QObject::connect(pushButton_SelectTarget, SIGNAL(clicked()), EvisionRectify, SLOT(onPush_SelectTargetFolder()));
        QObject::connect(pushButton_SelectCameraParams, SIGNAL(clicked()), EvisionRectify, SLOT(onPush_SelectCameraParamFile()));
        QObject::connect(pushButton_addTotargetList, SIGNAL(clicked()), EvisionRectify, SLOT(onAddToTargetList()));
        QObject::connect(pushButton_RemoveFromTarget, SIGNAL(clicked()), EvisionRectify, SLOT(onDeleteFromTargetList()));
        QObject::connect(pushButton_Start, SIGNAL(clicked()), EvisionRectify, SLOT(onStart()));

        QMetaObject::connectSlotsByName(EvisionRectify);
    } // setupUi

    void retranslateUi(QWidget *EvisionRectify)
    {
        EvisionRectify->setWindowTitle(QApplication::translate("EvisionRectify", "EvisionRectify", nullptr));
        pushButton_addTotargetList->setText(QApplication::translate("EvisionRectify", ">>", nullptr));
        pushButton_Start->setText(QApplication::translate("EvisionRectify", "Start", nullptr));
        label_2->setText(QApplication::translate("EvisionRectify", "\346\272\220\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_RemoveFromTarget->setText(QApplication::translate("EvisionRectify", "<<", nullptr));
        pushButton_SelectSrc->setText(QApplication::translate("EvisionRectify", "...", nullptr));
        pushButton_SelectTarget->setText(QApplication::translate("EvisionRectify", "...", nullptr));
        label->setText(QApplication::translate("EvisionRectify", "\344\277\235\345\255\230\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton_SelectCameraParams->setText(QApplication::translate("EvisionRectify", "\345\212\240\350\275\275\347\233\270\346\234\272\345\217\202\346\225\260\346\226\207\344\273\266", nullptr));
        label_3->setText(QApplication::translate("EvisionRectify", "\351\200\211\346\213\251\345\220\253\346\234\211\345\276\205\346\240\241\345\207\206\345\233\276\347\211\207\346\211\200\345\234\250\347\232\204\346\226\207\344\273\266\345\244\271\344\270\272\346\272\220\346\226\207\344\273\266\345\244\271,\350\256\276\347\275\256\344\277\235\345\255\230\346\226\207\344\273\266\345\244\271,\347\202\271\345\207\273\345\212\240\350\275\275\347\233\270\346\234\272\345\217\202\346\225\260\346\226\207\344\273\266\346\214\211\351\222\256\346\235\245\345\212\240\350\275\275\347\233\270\346\234\272\345\217\202\346\225\260,\n"
"\346\212\212\345\267\246\344\276\247\346\240\217\344\270\255\347\232\204\345\233\276\347\211\207\346\214\211\347\205\247\"\345\267\246\345\233\276/\345\217\263\345\233\276\"\347\232\204\351\241\272\345\272\217\346\267\273\345\212\240\345\210\260\345\217\263\344\276\247\346\240\217,\347\204\266\345\220\216\347\202\271\345\207\273Start.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EvisionRectify: public Ui_EvisionRectify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVISIONRECTIFY_H
