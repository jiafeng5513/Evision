/********************************************************************************
** Form generated from reading UI file 'ObjectDetectionView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTDETECTIONVIEW_H
#define UI_OBJECTDETECTIONVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectDetectionView
{
public:
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_Cfg;
    QPushButton *pushButton_cfg;
    QLabel *label_2;
    QLineEdit *lineEdit_Weight;
    QPushButton *pushButton_weight;
    QLabel *label_3;
    QLineEdit *lineEdit_Name;
    QPushButton *pushButton_names;
    QLabel *label_4;
    QComboBox *comboBox_Camera;
    QPushButton *pushButton_switch;
    QTextEdit *textEdit;

    void setupUi(QWidget *ObjectDetectionView)
    {
        if (ObjectDetectionView->objectName().isEmpty())
            ObjectDetectionView->setObjectName(QString::fromUtf8("ObjectDetectionView"));
        ObjectDetectionView->resize(884, 498);
        gridLayout_2 = new QGridLayout(ObjectDetectionView);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView = new QGraphicsView(ObjectDetectionView);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(640, 480));

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);

        frame = new QFrame(ObjectDetectionView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(350, 16777215));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_Cfg = new QLineEdit(frame);
        lineEdit_Cfg->setObjectName(QString::fromUtf8("lineEdit_Cfg"));

        gridLayout->addWidget(lineEdit_Cfg, 0, 1, 1, 1);

        pushButton_cfg = new QPushButton(frame);
        pushButton_cfg->setObjectName(QString::fromUtf8("pushButton_cfg"));

        gridLayout->addWidget(pushButton_cfg, 0, 2, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_Weight = new QLineEdit(frame);
        lineEdit_Weight->setObjectName(QString::fromUtf8("lineEdit_Weight"));

        gridLayout->addWidget(lineEdit_Weight, 1, 1, 1, 1);

        pushButton_weight = new QPushButton(frame);
        pushButton_weight->setObjectName(QString::fromUtf8("pushButton_weight"));

        gridLayout->addWidget(pushButton_weight, 1, 2, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_Name = new QLineEdit(frame);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));

        gridLayout->addWidget(lineEdit_Name, 2, 1, 1, 1);

        pushButton_names = new QPushButton(frame);
        pushButton_names->setObjectName(QString::fromUtf8("pushButton_names"));

        gridLayout->addWidget(pushButton_names, 2, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBox_Camera = new QComboBox(frame);
        comboBox_Camera->setObjectName(QString::fromUtf8("comboBox_Camera"));

        gridLayout->addWidget(comboBox_Camera, 3, 1, 1, 1);

        pushButton_switch = new QPushButton(frame);
        pushButton_switch->setObjectName(QString::fromUtf8("pushButton_switch"));

        gridLayout->addWidget(pushButton_switch, 3, 2, 1, 1);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 4, 0, 1, 3);


        gridLayout_2->addWidget(frame, 0, 1, 1, 1);


        retranslateUi(ObjectDetectionView);
        QObject::connect(pushButton_cfg, SIGNAL(clicked()), ObjectDetectionView, SLOT(OnBrowseCfg()));
        QObject::connect(pushButton_weight, SIGNAL(clicked()), ObjectDetectionView, SLOT(OnBrowseWeights()));
        QObject::connect(pushButton_names, SIGNAL(clicked()), ObjectDetectionView, SLOT(OnBrowseNames()));
        QObject::connect(pushButton_switch, SIGNAL(clicked()), ObjectDetectionView, SLOT(OnSwitch()));

        QMetaObject::connectSlotsByName(ObjectDetectionView);
    } // setupUi

    void retranslateUi(QWidget *ObjectDetectionView)
    {
        ObjectDetectionView->setWindowTitle(QApplication::translate("ObjectDetectionView", "ObjectDetectionView", nullptr));
        label->setText(QApplication::translate("ObjectDetectionView", "Cfg:", nullptr));
        pushButton_cfg->setText(QApplication::translate("ObjectDetectionView", "\346\265\217\350\247\210", nullptr));
        label_2->setText(QApplication::translate("ObjectDetectionView", "Weights", nullptr));
        pushButton_weight->setText(QApplication::translate("ObjectDetectionView", "\346\265\217\350\247\210", nullptr));
        label_3->setText(QApplication::translate("ObjectDetectionView", "Names", nullptr));
        pushButton_names->setText(QApplication::translate("ObjectDetectionView", "\346\265\217\350\247\210", nullptr));
        label_4->setText(QApplication::translate("ObjectDetectionView", "Camera", nullptr));
        pushButton_switch->setText(QApplication::translate("ObjectDetectionView", "switch", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ObjectDetectionView: public Ui_ObjectDetectionView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTDETECTIONVIEW_H
