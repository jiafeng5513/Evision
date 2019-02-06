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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogView
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *LogView)
    {
        if (LogView->objectName().isEmpty())
            LogView->setObjectName(QString::fromUtf8("LogView"));
        LogView->resize(373, 523);
        gridLayout = new QGridLayout(LogView);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(LogView);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(LogView);

        QMetaObject::connectSlotsByName(LogView);
    } // setupUi

    void retranslateUi(QWidget *LogView)
    {
        LogView->setWindowTitle(QApplication::translate("LogView", "LogView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogView: public Ui_LogView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEW_H
