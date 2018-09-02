/********************************************************************************
** Form generated from reading UI file 'RFinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RFINTERFACE_H
#define UI_RFINTERFACE_H

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

class Ui_RFinterface
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_ImgY;
    QLineEdit *lineEdit_ImgX;
    QLineEdit *lineEdit_Res;
    QPushButton *pushButton_getDis;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_getGap;
    QPushButton *pushButton_ShowCursor;
    QSplitter *splitter;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_O;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_D;

    void setupUi(QWidget *RFinterface)
    {
        if (RFinterface->objectName().isEmpty())
            RFinterface->setObjectName(QStringLiteral("RFinterface"));
        RFinterface->resize(498, 374);
        gridLayout_4 = new QGridLayout(RFinterface);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(RFinterface);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 110));
        groupBox->setMaximumSize(QSize(16777215, 110));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        lineEdit_ImgY = new QLineEdit(groupBox);
        lineEdit_ImgY->setObjectName(QStringLiteral("lineEdit_ImgY"));

        gridLayout->addWidget(lineEdit_ImgY, 1, 2, 1, 1);

        lineEdit_ImgX = new QLineEdit(groupBox);
        lineEdit_ImgX->setObjectName(QStringLiteral("lineEdit_ImgX"));

        gridLayout->addWidget(lineEdit_ImgX, 0, 2, 1, 1);

        lineEdit_Res = new QLineEdit(groupBox);
        lineEdit_Res->setObjectName(QStringLiteral("lineEdit_Res"));

        gridLayout->addWidget(lineEdit_Res, 2, 2, 1, 1);

        pushButton_getDis = new QPushButton(groupBox);
        pushButton_getDis->setObjectName(QStringLiteral("pushButton_getDis"));
        pushButton_getDis->setCheckable(true);

        gridLayout->addWidget(pushButton_getDis, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        pushButton_getGap = new QPushButton(groupBox);
        pushButton_getGap->setObjectName(QStringLiteral("pushButton_getGap"));
        pushButton_getGap->setCheckable(true);

        gridLayout->addWidget(pushButton_getGap, 1, 5, 1, 1);

        pushButton_ShowCursor = new QPushButton(groupBox);
        pushButton_ShowCursor->setObjectName(QStringLiteral("pushButton_ShowCursor"));

        gridLayout->addWidget(pushButton_ShowCursor, 2, 5, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        splitter = new QSplitter(RFinterface);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setMinimumSize(QSize(480, 240));
        splitter->setOrientation(Qt::Horizontal);
        gridLayoutWidget = new QWidget(splitter);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayout_O = new QGridLayout(gridLayoutWidget);
        gridLayout_O->setSpacing(6);
        gridLayout_O->setContentsMargins(11, 11, 11, 11);
        gridLayout_O->setObjectName(QStringLiteral("gridLayout_O"));
        gridLayout_O->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(gridLayoutWidget);
        gridLayoutWidget_2 = new QWidget(splitter);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayout_D = new QGridLayout(gridLayoutWidget_2);
        gridLayout_D->setSpacing(6);
        gridLayout_D->setContentsMargins(11, 11, 11, 11);
        gridLayout_D->setObjectName(QStringLiteral("gridLayout_D"));
        gridLayout_D->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(gridLayoutWidget_2);

        gridLayout_4->addWidget(splitter, 1, 0, 1, 1);


        retranslateUi(RFinterface);

        QMetaObject::connectSlotsByName(RFinterface);
    } // setupUi

    void retranslateUi(QWidget *RFinterface)
    {
        RFinterface->setWindowTitle(QApplication::translate("RFinterface", "\344\272\244\344\272\222\346\265\213\351\207\217", nullptr));
        groupBox->setTitle(QApplication::translate("RFinterface", "Function and Result", nullptr));
        label_4->setText(QApplication::translate("RFinterface", "\350\256\241\347\256\227\347\273\223\346\236\234:", nullptr));
        label->setText(QApplication::translate("RFinterface", "\345\233\276\345\203\217\347\251\272\351\227\264\345\235\220\346\240\207:", nullptr));
        label_3->setText(QApplication::translate("RFinterface", "Y=", nullptr));
        label_2->setText(QApplication::translate("RFinterface", "X=", nullptr));
        pushButton_getDis->setText(QApplication::translate("RFinterface", "\346\265\213\351\207\217\345\205\211\345\255\246\344\270\255\345\277\203\345\210\260\347\233\256\346\240\207\347\202\271\347\232\204\350\267\235\347\246\273", nullptr));
        pushButton_getGap->setText(QApplication::translate("RFinterface", "\346\265\213\351\207\217\347\233\256\346\240\207\347\202\271\344\271\213\351\227\264\347\232\204\350\267\235\347\246\273", nullptr));
        pushButton_ShowCursor->setText(QApplication::translate("RFinterface", "\346\230\276\347\244\272\346\270\270\346\240\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RFinterface: public Ui_RFinterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RFINTERFACE_H
