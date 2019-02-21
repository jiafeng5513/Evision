/********************************************************************************
** Form generated from reading UI file 'StereoMatcherView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEREOMATCHERVIEW_H
#define UI_STEREOMATCHERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StereoMatcherView
{
public:
    QGraphicsView *graphicsView;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView_FixDisp;
    QLabel *label_4;
    QGraphicsView *graphicsView_PointDisp;
    QLabel *label_5;
    QGraphicsView *graphicsView_PointImageL;
    QLabel *label_6;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsView_ImageL;
    QLabel *label;
    QGraphicsView *graphicsView_ImageR;
    QLabel *label_2;
    QGraphicsView *graphicsView_RawDisp;
    QLabel *label_3;
    QFrame *frame_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *StereoMatcherView)
    {
        if (StereoMatcherView->objectName().isEmpty())
            StereoMatcherView->setObjectName(QString::fromUtf8("StereoMatcherView"));
        StereoMatcherView->resize(1015, 592);
        graphicsView = new QGraphicsView(StereoMatcherView);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(200, 0, 611, 411));
        frame = new QFrame(StereoMatcherView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(810, 0, 201, 411));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        graphicsView_FixDisp = new QGraphicsView(frame);
        graphicsView_FixDisp->setObjectName(QString::fromUtf8("graphicsView_FixDisp"));

        verticalLayout->addWidget(graphicsView_FixDisp);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        graphicsView_PointDisp = new QGraphicsView(frame);
        graphicsView_PointDisp->setObjectName(QString::fromUtf8("graphicsView_PointDisp"));

        verticalLayout->addWidget(graphicsView_PointDisp);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        graphicsView_PointImageL = new QGraphicsView(frame);
        graphicsView_PointImageL->setObjectName(QString::fromUtf8("graphicsView_PointImageL"));

        verticalLayout->addWidget(graphicsView_PointImageL);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        frame_2 = new QFrame(StereoMatcherView);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 201, 411));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        graphicsView_ImageL = new QGraphicsView(frame_2);
        graphicsView_ImageL->setObjectName(QString::fromUtf8("graphicsView_ImageL"));

        verticalLayout_3->addWidget(graphicsView_ImageL);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        graphicsView_ImageR = new QGraphicsView(frame_2);
        graphicsView_ImageR->setObjectName(QString::fromUtf8("graphicsView_ImageR"));

        verticalLayout_3->addWidget(graphicsView_ImageR);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        graphicsView_RawDisp = new QGraphicsView(frame_2);
        graphicsView_RawDisp->setObjectName(QString::fromUtf8("graphicsView_RawDisp"));

        verticalLayout_3->addWidget(graphicsView_RawDisp);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        frame_3 = new QFrame(StereoMatcherView);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 420, 1011, 171));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 90, 75, 23));
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 10, 75, 23));
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 50, 75, 23));

        retranslateUi(StereoMatcherView);
        QObject::connect(pushButton_3, SIGNAL(clicked()), StereoMatcherView, SLOT(onPush_LinkStart()));

        QMetaObject::connectSlotsByName(StereoMatcherView);
    } // setupUi

    void retranslateUi(QWidget *StereoMatcherView)
    {
        StereoMatcherView->setWindowTitle(QApplication::translate("StereoMatcherView", "StereoMatcherView", nullptr));
        label_4->setText(QApplication::translate("StereoMatcherView", "\344\277\256\345\244\215\350\247\206\345\267\256\345\233\276", nullptr));
        label_5->setText(QApplication::translate("StereoMatcherView", "\346\240\207\347\202\271\350\247\206\345\267\256\345\233\276", nullptr));
        label_6->setText(QApplication::translate("StereoMatcherView", "\346\240\207\347\202\271\345\267\246\350\247\206\345\233\276", nullptr));
        label->setText(QApplication::translate("StereoMatcherView", "\345\267\246\350\247\206\345\233\276", nullptr));
        label_2->setText(QApplication::translate("StereoMatcherView", "\345\217\263\350\247\206\345\233\276", nullptr));
        label_3->setText(QApplication::translate("StereoMatcherView", "\345\216\237\345\247\213\350\247\206\345\267\256\345\233\276", nullptr));
        pushButton_3->setText(QApplication::translate("StereoMatcherView", "Link Start!", nullptr));
        pushButton->setText(QApplication::translate("StereoMatcherView", "\351\200\211\346\213\251\345\267\246\350\247\206\345\233\276", nullptr));
        pushButton_2->setText(QApplication::translate("StereoMatcherView", "\351\200\211\346\213\251\345\217\263\350\247\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StereoMatcherView: public Ui_StereoMatcherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOMATCHERVIEW_H
