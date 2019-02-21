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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StereoMatcherView
{
public:
    QGraphicsView *graphicsView;
    QListView *listView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *StereoMatcherView)
    {
        if (StereoMatcherView->objectName().isEmpty())
            StereoMatcherView->setObjectName(QString::fromUtf8("StereoMatcherView"));
        StereoMatcherView->resize(710, 425);
        graphicsView = new QGraphicsView(StereoMatcherView);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(170, 10, 531, 261));
        listView = new QListView(StereoMatcherView);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(10, 10, 151, 401));
        pushButton = new QPushButton(StereoMatcherView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 290, 75, 23));
        pushButton_2 = new QPushButton(StereoMatcherView);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 290, 75, 23));

        retranslateUi(StereoMatcherView);

        QMetaObject::connectSlotsByName(StereoMatcherView);
    } // setupUi

    void retranslateUi(QWidget *StereoMatcherView)
    {
        StereoMatcherView->setWindowTitle(QApplication::translate("StereoMatcherView", "StereoMatcherView", nullptr));
        pushButton->setText(QApplication::translate("StereoMatcherView", "\351\200\211\346\213\251\345\267\246\350\247\206\345\233\276", nullptr));
        pushButton_2->setText(QApplication::translate("StereoMatcherView", "\351\200\211\346\213\251\345\217\263\350\247\206\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StereoMatcherView: public Ui_StereoMatcherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEREOMATCHERVIEW_H
