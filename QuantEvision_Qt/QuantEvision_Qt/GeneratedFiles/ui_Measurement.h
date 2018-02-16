/********************************************************************************
** Form generated from reading UI file 'Measurement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEASUREMENT_H
#define UI_MEASUREMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Measurement
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_RangeSinglePoint;
    QPushButton *pushButton_RangeDualPoint;
    QLabel *label_38;
    QLineEdit *lineEdit_Result;
    QGraphicsView *graphicsView_Pointpicker;

    void setupUi(QWidget *Measurement)
    {
        if (Measurement->objectName().isEmpty())
            Measurement->setObjectName(QStringLiteral("Measurement"));
        Measurement->resize(679, 439);
        gridLayout = new QGridLayout(Measurement);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_RangeSinglePoint = new QPushButton(Measurement);
        pushButton_RangeSinglePoint->setObjectName(QStringLiteral("pushButton_RangeSinglePoint"));

        gridLayout->addWidget(pushButton_RangeSinglePoint, 0, 0, 1, 1);

        pushButton_RangeDualPoint = new QPushButton(Measurement);
        pushButton_RangeDualPoint->setObjectName(QStringLiteral("pushButton_RangeDualPoint"));

        gridLayout->addWidget(pushButton_RangeDualPoint, 0, 1, 1, 1);

        label_38 = new QLabel(Measurement);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout->addWidget(label_38, 0, 2, 1, 1);

        lineEdit_Result = new QLineEdit(Measurement);
        lineEdit_Result->setObjectName(QStringLiteral("lineEdit_Result"));

        gridLayout->addWidget(lineEdit_Result, 0, 3, 1, 1);

        graphicsView_Pointpicker = new QGraphicsView(Measurement);
        graphicsView_Pointpicker->setObjectName(QStringLiteral("graphicsView_Pointpicker"));

        gridLayout->addWidget(graphicsView_Pointpicker, 1, 0, 1, 4);


        retranslateUi(Measurement);

        QMetaObject::connectSlotsByName(Measurement);
    } // setupUi

    void retranslateUi(QWidget *Measurement)
    {
        Measurement->setWindowTitle(QApplication::translate("Measurement", "Measurement", Q_NULLPTR));
        pushButton_RangeSinglePoint->setText(QApplication::translate("Measurement", "\346\265\213\351\207\217\345\205\211\345\255\246\344\270\255\345\277\203\345\210\260\347\233\256\346\240\207\347\202\271\347\232\204\350\267\235\347\246\273", Q_NULLPTR));
        pushButton_RangeDualPoint->setText(QApplication::translate("Measurement", "\346\265\213\351\207\217\345\233\276\344\270\255\344\270\244\347\202\271\347\232\204\350\267\235\347\246\273", Q_NULLPTR));
        label_38->setText(QApplication::translate("Measurement", "\350\267\235\347\246\273\345\200\274:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Measurement: public Ui_Measurement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEASUREMENT_H
