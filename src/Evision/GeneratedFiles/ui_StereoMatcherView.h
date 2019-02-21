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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StereoMatcherView
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QListView *listView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *StereoMatcherView)
    {
        if (StereoMatcherView->objectName().isEmpty())
            StereoMatcherView->setObjectName(QString::fromUtf8("StereoMatcherView"));
        StereoMatcherView->resize(710, 425);
        gridLayout = new QGridLayout(StereoMatcherView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(StereoMatcherView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        listView = new QListView(StereoMatcherView);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout->addWidget(listView, 0, 0, 2, 1);

        pushButton_2 = new QPushButton(StereoMatcherView);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(StereoMatcherView);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 3, 1, 1);

        graphicsView = new QGraphicsView(StereoMatcherView);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 1, 1, 3);


        retranslateUi(StereoMatcherView);
        QObject::connect(pushButton_3, SIGNAL(clicked()), StereoMatcherView, SLOT(onPush_LinkStart()));

        QMetaObject::connectSlotsByName(StereoMatcherView);
    } // setupUi

    void retranslateUi(QWidget *StereoMatcherView)
    {
        StereoMatcherView->setWindowTitle(QApplication::translate("StereoMatcherView", "StereoMatcherView", nullptr));
        pushButton->setText(QApplication::translate("StereoMatcherView", "\351\200\211\346\213\251\345\267\246\350\247\206\345\233\276", nullptr));
        pushButton_2->setText(QApplication::translate("StereoMatcherView", "\351\200\211\346\213\251\345\217\263\350\247\206\345\233\276", nullptr));
        pushButton_3->setText(QApplication::translate("StereoMatcherView", "Link Start!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StereoMatcherView: public Ui_StereoMatcherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOMATCHERVIEW_H
