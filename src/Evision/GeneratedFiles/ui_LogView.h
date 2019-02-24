/********************************************************************************
** Form generated from reading UI file 'LogView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGVIEW_H
#define UI_LOGVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogView
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBox_StayOnTop;
    QPushButton *pushButton_delete;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;

    void setupUi(QWidget *LogView)
    {
        if (LogView->objectName().isEmpty())
            LogView->setObjectName(QString::fromUtf8("LogView"));
        LogView->resize(373, 523);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Evision/resource/Evision.ico"), QSize(), QIcon::Normal, QIcon::Off);
        LogView->setWindowIcon(icon);
        gridLayout = new QGridLayout(LogView);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_StayOnTop = new QCheckBox(LogView);
        checkBox_StayOnTop->setObjectName(QString::fromUtf8("checkBox_StayOnTop"));

        gridLayout->addWidget(checkBox_StayOnTop, 2, 0, 1, 1);

        pushButton_delete = new QPushButton(LogView);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));

        gridLayout->addWidget(pushButton_delete, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        textEdit = new QTextEdit(LogView);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 3);


        retranslateUi(LogView);
        QObject::connect(checkBox_StayOnTop, SIGNAL(clicked(bool)), LogView, SLOT(onChecked_StayOnTop(bool)));
        QObject::connect(pushButton_delete, SIGNAL(clicked()), LogView, SLOT(onPush_Delete()));

        QMetaObject::connectSlotsByName(LogView);
    } // setupUi

    void retranslateUi(QWidget *LogView)
    {
        LogView->setWindowTitle(QApplication::translate("LogView", "LogView", nullptr));
        checkBox_StayOnTop->setText(QApplication::translate("LogView", "\345\247\213\347\273\210\344\277\235\346\214\201\345\234\250\346\234\200\345\211\215", nullptr));
        pushButton_delete->setText(QApplication::translate("LogView", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogView: public Ui_LogView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEW_H
