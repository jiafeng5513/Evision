/********************************************************************************
** Form generated from reading UI file 'WatchImage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WATCHIMAGE_H
#define UI_WATCHIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WatchImage
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *WatchImage)
    {
        if (WatchImage->objectName().isEmpty())
            WatchImage->setObjectName(QString::fromUtf8("WatchImage"));
        WatchImage->resize(783, 578);
        gridLayout = new QGridLayout(WatchImage);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(WatchImage);

        QMetaObject::connectSlotsByName(WatchImage);
    } // setupUi

    void retranslateUi(QWidget *WatchImage)
    {
        WatchImage->setWindowTitle(QApplication::translate("WatchImage", "WatchImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WatchImage: public Ui_WatchImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATCHIMAGE_H
