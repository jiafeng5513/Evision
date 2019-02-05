/********************************************************************************
** Form generated from reading UI file 'WatchImageView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHIMAGEVIEW_H
#define UI_WATCHIMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WatchImageView
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *WatchImageView)
    {
        if (WatchImageView->objectName().isEmpty())
            WatchImageView->setObjectName(QString::fromUtf8("WatchImageView"));
        WatchImageView->resize(783, 578);
        gridLayout = new QGridLayout(WatchImageView);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(WatchImageView);

        QMetaObject::connectSlotsByName(WatchImageView);
    } // setupUi

    void retranslateUi(QWidget *WatchImageView)
    {
        WatchImageView->setWindowTitle(QApplication::translate("WatchImageView", "WatchImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WatchImageView: public Ui_WatchImageView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHIMAGEVIEW_H
