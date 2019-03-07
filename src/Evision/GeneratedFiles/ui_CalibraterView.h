/********************************************************************************
** Form generated from reading UI file 'CalibraterView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATERVIEW_H
#define UI_CALIBRATERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibraterView
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_CALIB_FIX_PRINCIPAL_POINT;
    QFrame *line;
    QCheckBox *checkBox_CALIB_RATIONAL_MODEL;
    QFrame *line_2;
    QCheckBox *checkBox_CALIB_TILTED_MODEL;
    QCheckBox *checkBox_CALIB_FIX_ASPECT_RATIO;
    QCheckBox *checkBox_CALIB_THIN_PRISM_MODEL;
    QCheckBox *checkBox_CALIB_FIX_TAUX_TAUY;
    QCheckBox *checkBox_CALIB_ZERO_TANGENT_DIST;
    QCheckBox *checkBox_CALIB_FIX_S1_S2_S3_S4;
    QCheckBox *checkBox_CALIB_SAME_FOCAL_LENGTH;
    QCheckBox *checkBox_CALIB_FIX_K1;
    QCheckBox *checkBox_CALIB_FIX_K3;
    QCheckBox *checkBox_CALIB_FIX_K5;
    QCheckBox *checkBox_CALIB_FIX_K2;
    QCheckBox *checkBox_CALIB_FIX_K4;
    QCheckBox *checkBox_CALIB_FIX_K6;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QLineEdit *lineEdit_BoardWidth;
    QLabel *label_6;
    QLineEdit *lineEdit_BoardHeight;
    QLabel *label_8;
    QLineEdit *lineEdit_SquareSize;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_CalibDefault;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *CalibraterView)
    {
        if (CalibraterView->objectName().isEmpty())
            CalibraterView->setObjectName(QString::fromUtf8("CalibraterView"));
        CalibraterView->resize(1004, 589);
        gridLayout_2 = new QGridLayout(CalibraterView);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(CalibraterView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 210));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkBox_CALIB_FIX_PRINCIPAL_POINT = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_PRINCIPAL_POINT->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_PRINCIPAL_POINT"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_PRINCIPAL_POINT, 0, 0, 1, 1);

        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 1, 5, 1);

        checkBox_CALIB_RATIONAL_MODEL = new QCheckBox(groupBox_3);
        checkBox_CALIB_RATIONAL_MODEL->setObjectName(QString::fromUtf8("checkBox_CALIB_RATIONAL_MODEL"));

        gridLayout_3->addWidget(checkBox_CALIB_RATIONAL_MODEL, 0, 2, 1, 1);

        line_2 = new QFrame(groupBox_3);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 0, 3, 5, 1);

        checkBox_CALIB_TILTED_MODEL = new QCheckBox(groupBox_3);
        checkBox_CALIB_TILTED_MODEL->setObjectName(QString::fromUtf8("checkBox_CALIB_TILTED_MODEL"));

        gridLayout_3->addWidget(checkBox_CALIB_TILTED_MODEL, 0, 4, 1, 1);

        checkBox_CALIB_FIX_ASPECT_RATIO = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_ASPECT_RATIO->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_ASPECT_RATIO"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_ASPECT_RATIO, 1, 0, 1, 1);

        checkBox_CALIB_THIN_PRISM_MODEL = new QCheckBox(groupBox_3);
        checkBox_CALIB_THIN_PRISM_MODEL->setObjectName(QString::fromUtf8("checkBox_CALIB_THIN_PRISM_MODEL"));

        gridLayout_3->addWidget(checkBox_CALIB_THIN_PRISM_MODEL, 1, 2, 1, 1);

        checkBox_CALIB_FIX_TAUX_TAUY = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_TAUX_TAUY->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_TAUX_TAUY"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_TAUX_TAUY, 1, 4, 1, 1);

        checkBox_CALIB_ZERO_TANGENT_DIST = new QCheckBox(groupBox_3);
        checkBox_CALIB_ZERO_TANGENT_DIST->setObjectName(QString::fromUtf8("checkBox_CALIB_ZERO_TANGENT_DIST"));

        gridLayout_3->addWidget(checkBox_CALIB_ZERO_TANGENT_DIST, 2, 0, 1, 1);

        checkBox_CALIB_FIX_S1_S2_S3_S4 = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_S1_S2_S3_S4->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_S1_S2_S3_S4"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_S1_S2_S3_S4, 2, 2, 1, 1);

        checkBox_CALIB_SAME_FOCAL_LENGTH = new QCheckBox(groupBox_3);
        checkBox_CALIB_SAME_FOCAL_LENGTH->setObjectName(QString::fromUtf8("checkBox_CALIB_SAME_FOCAL_LENGTH"));

        gridLayout_3->addWidget(checkBox_CALIB_SAME_FOCAL_LENGTH, 2, 4, 1, 1);

        checkBox_CALIB_FIX_K1 = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_K1->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_K1"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_K1, 3, 0, 1, 1);

        checkBox_CALIB_FIX_K3 = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_K3->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_K3"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_K3, 3, 2, 1, 1);

        checkBox_CALIB_FIX_K5 = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_K5->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_K5"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_K5, 3, 4, 1, 1);

        checkBox_CALIB_FIX_K2 = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_K2->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_K2"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_K2, 4, 0, 1, 1);

        checkBox_CALIB_FIX_K4 = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_K4->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_K4"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_K4, 4, 2, 1, 1);

        checkBox_CALIB_FIX_K6 = new QCheckBox(groupBox_3);
        checkBox_CALIB_FIX_K6->setObjectName(QString::fromUtf8("checkBox_CALIB_FIX_K6"));

        gridLayout_3->addWidget(checkBox_CALIB_FIX_K6, 4, 4, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 2);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_BoardWidth = new QLineEdit(groupBox);
        lineEdit_BoardWidth->setObjectName(QString::fromUtf8("lineEdit_BoardWidth"));
        lineEdit_BoardWidth->setMinimumSize(QSize(50, 20));
        lineEdit_BoardWidth->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(lineEdit_BoardWidth);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_BoardHeight = new QLineEdit(groupBox);
        lineEdit_BoardHeight->setObjectName(QString::fromUtf8("lineEdit_BoardHeight"));
        lineEdit_BoardHeight->setMinimumSize(QSize(50, 20));
        lineEdit_BoardHeight->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(lineEdit_BoardHeight);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);

        lineEdit_SquareSize = new QLineEdit(groupBox);
        lineEdit_SquareSize->setObjectName(QString::fromUtf8("lineEdit_SquareSize"));
        lineEdit_SquareSize->setMinimumSize(QSize(50, 20));
        lineEdit_SquareSize->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(lineEdit_SquareSize);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(4, 4, 4, 4);
        pushButton_CalibDefault = new QPushButton(groupBox_4);
        pushButton_CalibDefault->setObjectName(QString::fromUtf8("pushButton_CalibDefault"));

        horizontalLayout_3->addWidget(pushButton_CalibDefault);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        gridLayout->addWidget(groupBox_4, 1, 1, 1, 1);


        gridLayout_2->addWidget(frame, 1, 1, 1, 1);

        listWidget = new QListWidget(CalibraterView);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(220, 16777215));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(129, 129, 129);"));
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setIconSize(QSize(60, 60));
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setModelColumn(0);

        gridLayout_2->addWidget(listWidget, 0, 0, 2, 1);

        scrollArea = new QScrollArea(CalibraterView);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 758, 359));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        graphicsView = new QGraphicsView(scrollAreaWidgetContents);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(181, 181, 181);"));

        gridLayout_4->addWidget(graphicsView, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 1, 1, 2);


        retranslateUi(CalibraterView);
        QObject::connect(lineEdit_BoardWidth, SIGNAL(textChanged(QString)), CalibraterView, SLOT(onValueChanged_BoardWidth(QString)));
        QObject::connect(lineEdit_BoardHeight, SIGNAL(textChanged(QString)), CalibraterView, SLOT(onValueChanged_BoardHeight(QString)));
        QObject::connect(lineEdit_SquareSize, SIGNAL(textChanged(QString)), CalibraterView, SLOT(onValueChanged_SquareSize(QString)));
        QObject::connect(pushButton_CalibDefault, SIGNAL(clicked()), CalibraterView, SLOT(setDefaultCalibParam()));
        QObject::connect(pushButton, SIGNAL(clicked()), CalibraterView, SLOT(doCalib()));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), CalibraterView, SLOT(onItemClicked(QListWidgetItem*)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), CalibraterView, SLOT(onPush_saveParamsToFile()));
        QObject::connect(checkBox_CALIB_FIX_PRINCIPAL_POINT, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_PRINCIPAL_POINT(bool)));
        QObject::connect(checkBox_CALIB_RATIONAL_MODEL, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_RATIONAL_MODEL(bool)));
        QObject::connect(checkBox_CALIB_TILTED_MODEL, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_TILTED_MODEL(bool)));
        QObject::connect(checkBox_CALIB_FIX_ASPECT_RATIO, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_ASPECT_RATIO(bool)));
        QObject::connect(checkBox_CALIB_ZERO_TANGENT_DIST, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_ZERO_TANGENT_DIST(bool)));
        QObject::connect(checkBox_CALIB_FIX_K1, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_K1(bool)));
        QObject::connect(checkBox_CALIB_FIX_K2, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_K2(bool)));
        QObject::connect(checkBox_CALIB_THIN_PRISM_MODEL, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_THIN_PRISM_MODEL(bool)));
        QObject::connect(checkBox_CALIB_FIX_S1_S2_S3_S4, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_S1_S2_S3_S4(bool)));
        QObject::connect(checkBox_CALIB_FIX_K3, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_K3(bool)));
        QObject::connect(checkBox_CALIB_FIX_K4, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_K4(bool)));
        QObject::connect(checkBox_CALIB_FIX_TAUX_TAUY, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_TAUX_TAUY(bool)));
        QObject::connect(checkBox_CALIB_SAME_FOCAL_LENGTH, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_SAME_FOCAL_LENGTH(bool)));
        QObject::connect(checkBox_CALIB_FIX_K5, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_K5(bool)));
        QObject::connect(checkBox_CALIB_FIX_K6, SIGNAL(clicked(bool)), CalibraterView, SLOT(onValueChanged_FIX_K6(bool)));

        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(CalibraterView);
    } // setupUi

    void retranslateUi(QWidget *CalibraterView)
    {
        CalibraterView->setWindowTitle(QApplication::translate("CalibraterView", "\346\240\207\345\256\232", nullptr));
        groupBox_3->setTitle(QApplication::translate("CalibraterView", "\346\240\207\345\256\232\350\256\276\347\275\256", nullptr));
        checkBox_CALIB_FIX_PRINCIPAL_POINT->setText(QApplication::translate("CalibraterView", "\344\270\215\344\274\230\345\214\226\344\270\273\347\202\271\344\275\215\347\275\256", nullptr));
        checkBox_CALIB_RATIONAL_MODEL->setText(QApplication::translate("CalibraterView", "\344\275\277\347\224\250\347\220\206\346\203\263\346\250\241\345\236\213(8\345\217\202\346\225\260)", nullptr));
        checkBox_CALIB_TILTED_MODEL->setText(QApplication::translate("CalibraterView", "\344\275\277\347\224\250\345\200\276\346\226\234\344\274\240\346\204\237\345\231\250\346\250\241\345\236\213(14\345\217\202\346\225\260)", nullptr));
        checkBox_CALIB_FIX_ASPECT_RATIO->setText(QApplication::translate("CalibraterView", "\345\233\272\345\256\232\345\256\275\351\253\230\346\257\224", nullptr));
        checkBox_CALIB_THIN_PRISM_MODEL->setText(QApplication::translate("CalibraterView", "\344\275\277\347\224\250\350\226\204\346\243\261\351\225\234\346\250\241\345\236\213(12\345\217\202\346\225\260)", nullptr));
        checkBox_CALIB_FIX_TAUX_TAUY->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\200\276\346\226\234\344\274\240\346\204\237\345\231\250\345\217\202\346\225\260TauX\345\222\214TauY", nullptr));
        checkBox_CALIB_ZERO_TANGENT_DIST->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\210\207\345\220\221\347\225\270\345\217\230\347\263\273\346\225\260(P1,P2)", nullptr));
        checkBox_CALIB_FIX_S1_S2_S3_S4->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\350\226\204\346\243\261\351\225\234\345\217\202\346\225\260S1-S4", nullptr));
        checkBox_CALIB_SAME_FOCAL_LENGTH->setText(QApplication::translate("CalibraterView", "\345\274\272\345\210\266\344\270\244\344\276\247\347\233\270\346\234\272\347\204\246\350\267\235\347\233\270\347\255\211", nullptr));
        checkBox_CALIB_FIX_K1->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\276\204\345\220\221\347\225\270\345\217\230\347\263\273\346\225\260K1", nullptr));
        checkBox_CALIB_FIX_K3->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\276\204\345\220\221\347\225\270\345\217\230\347\263\273\346\225\260K3", nullptr));
        checkBox_CALIB_FIX_K5->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\276\204\345\220\221\347\225\270\345\217\230\347\263\273\346\225\260K5", nullptr));
        checkBox_CALIB_FIX_K2->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\276\204\345\220\221\347\225\270\345\217\230\347\263\273\346\225\260K2", nullptr));
        checkBox_CALIB_FIX_K4->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\276\204\345\220\221\347\225\270\345\217\230\347\263\273\346\225\260K4", nullptr));
        checkBox_CALIB_FIX_K6->setText(QApplication::translate("CalibraterView", "\345\277\275\347\225\245\345\276\204\345\220\221\347\225\270\345\217\230\347\263\273\346\225\260K6", nullptr));
        groupBox->setTitle(QApplication::translate("CalibraterView", "\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        label_5->setText(QApplication::translate("CalibraterView", "Width:", nullptr));
        label_6->setText(QApplication::translate("CalibraterView", "Height:", nullptr));
        label_8->setText(QApplication::translate("CalibraterView", "Size:", nullptr));
        groupBox_4->setTitle(QApplication::translate("CalibraterView", "\346\240\207\345\256\232", nullptr));
        pushButton_CalibDefault->setText(QApplication::translate("CalibraterView", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        pushButton->setText(QApplication::translate("CalibraterView", "\346\240\207\345\256\232", nullptr));
        pushButton_2->setText(QApplication::translate("CalibraterView", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalibraterView: public Ui_CalibraterView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATERVIEW_H
