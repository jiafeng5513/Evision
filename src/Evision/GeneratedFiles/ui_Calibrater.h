/********************************************************************************
** Form generated from reading UI file 'Calibrater.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATER_H
#define UI_CALIBRATER_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calibrater
{
public:
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QGraphicsView *graphicsView_L;
    QGraphicsView *graphicsView_R;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_BoardHeight;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineEdit_BoardWidth;
    QLineEdit *lineEdit_SquareSize;
    QLabel *label_8;
    QCheckBox *checkBox_showRectified;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_CalibDefault;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Bouguet;
    QRadioButton *radioButton_Hartley;
    QTextEdit *textEdit;

    void setupUi(QWidget *Calibrater)
    {
        if (Calibrater->objectName().isEmpty())
            Calibrater->setObjectName(QString::fromUtf8("Calibrater"));
        Calibrater->resize(891, 629);
        gridLayout_3 = new QGridLayout(Calibrater);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(Calibrater);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        graphicsView_L = new QGraphicsView(splitter);
        graphicsView_L->setObjectName(QString::fromUtf8("graphicsView_L"));
        graphicsView_L->setContextMenuPolicy(Qt::ActionsContextMenu);
        graphicsView_L->setAutoFillBackground(false);
        graphicsView_L->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView_L->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView_L->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView_L->setBackgroundBrush(brush);
        splitter->addWidget(graphicsView_L);
        graphicsView_R = new QGraphicsView(splitter);
        graphicsView_R->setObjectName(QString::fromUtf8("graphicsView_R"));
        splitter->addWidget(graphicsView_R);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);

        frame = new QFrame(Calibrater);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 180));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_BoardHeight = new QLineEdit(groupBox);
        lineEdit_BoardHeight->setObjectName(QString::fromUtf8("lineEdit_BoardHeight"));
        lineEdit_BoardHeight->setMinimumSize(QSize(50, 20));
        lineEdit_BoardHeight->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_BoardHeight, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_BoardWidth = new QLineEdit(groupBox);
        lineEdit_BoardWidth->setObjectName(QString::fromUtf8("lineEdit_BoardWidth"));
        lineEdit_BoardWidth->setMinimumSize(QSize(50, 20));
        lineEdit_BoardWidth->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_BoardWidth, 0, 2, 1, 1);

        lineEdit_SquareSize = new QLineEdit(groupBox);
        lineEdit_SquareSize->setObjectName(QString::fromUtf8("lineEdit_SquareSize"));
        lineEdit_SquareSize->setMinimumSize(QSize(50, 20));
        lineEdit_SquareSize->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_SquareSize, 2, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        checkBox_showRectified = new QCheckBox(groupBox);
        checkBox_showRectified->setObjectName(QString::fromUtf8("checkBox_showRectified"));

        gridLayout->addWidget(checkBox_showRectified, 3, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 3, 1);

        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);


        gridLayout_2->addWidget(groupBox_3, 1, 2, 1, 1);

        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_CalibDefault = new QPushButton(groupBox_4);
        pushButton_CalibDefault->setObjectName(QString::fromUtf8("pushButton_CalibDefault"));

        horizontalLayout_3->addWidget(pushButton_CalibDefault);

        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        gridLayout_2->addWidget(groupBox_4, 2, 2, 1, 1);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_Bouguet = new QRadioButton(groupBox_2);
        radioButton_Bouguet->setObjectName(QString::fromUtf8("radioButton_Bouguet"));

        horizontalLayout->addWidget(radioButton_Bouguet);

        radioButton_Hartley = new QRadioButton(groupBox_2);
        radioButton_Hartley->setObjectName(QString::fromUtf8("radioButton_Hartley"));

        horizontalLayout->addWidget(radioButton_Hartley);


        gridLayout_2->addWidget(groupBox_2, 0, 2, 1, 1);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 3, 3, 1);


        gridLayout_3->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(Calibrater);

        QMetaObject::connectSlotsByName(Calibrater);
    } // setupUi

    void retranslateUi(QWidget *Calibrater)
    {
        Calibrater->setWindowTitle(QApplication::translate("Calibrater", "\346\240\207\345\256\232", nullptr));
        groupBox->setTitle(QApplication::translate("Calibrater", "\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        label_6->setText(QApplication::translate("Calibrater", "Height:", nullptr));
        label_5->setText(QApplication::translate("Calibrater", "Width:", nullptr));
        label_8->setText(QApplication::translate("Calibrater", "Size:", nullptr));
        checkBox_showRectified->setText(QApplication::translate("Calibrater", "\346\230\276\347\244\272\347\237\253\346\255\243\347\273\223\346\236\234(By OpenCV NamedWindow)", nullptr));
        groupBox_3->setTitle(QApplication::translate("Calibrater", "\345\215\225/\345\217\214\347\233\256", nullptr));
        radioButton->setText(QApplication::translate("Calibrater", "\345\215\225\347\233\256\346\240\207\345\256\232", nullptr));
        radioButton_2->setText(QApplication::translate("Calibrater", "\345\217\214\347\233\256\346\240\207\345\256\232", nullptr));
        groupBox_4->setTitle(QApplication::translate("Calibrater", "\346\240\207\345\256\232", nullptr));
        pushButton_CalibDefault->setText(QApplication::translate("Calibrater", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        pushButton->setText(QApplication::translate("Calibrater", "\346\240\207\345\256\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("Calibrater", "Function", nullptr));
        radioButton_Bouguet->setText(QApplication::translate("Calibrater", "\344\275\277\347\224\250Bouguet\347\237\253\346\255\243\346\226\271\346\263\225", nullptr));
        radioButton_Hartley->setText(QApplication::translate("Calibrater", "\344\275\277\347\224\250Hartley\347\237\253\346\255\243\346\226\271\346\263\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calibrater: public Ui_Calibrater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATER_H
