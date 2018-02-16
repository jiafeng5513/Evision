/********************************************************************************
** Form generated from reading UI file 'Reconstruction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONSTRUCTION_H
#define UI_RECONSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reconstruction
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_Reconstruction;
    QPushButton *pushButton_ExportPointCloud;
    QSpacerItem *horizontalSpacer_5;
    QOpenGLWidget *openGLWidget_PointCloud;

    void setupUi(QWidget *Reconstruction)
    {
        if (Reconstruction->objectName().isEmpty())
            Reconstruction->setObjectName(QStringLiteral("Reconstruction"));
        Reconstruction->resize(774, 551);
        gridLayout = new QGridLayout(Reconstruction);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Reconstruction = new QPushButton(Reconstruction);
        pushButton_Reconstruction->setObjectName(QStringLiteral("pushButton_Reconstruction"));

        gridLayout->addWidget(pushButton_Reconstruction, 0, 0, 1, 1);

        pushButton_ExportPointCloud = new QPushButton(Reconstruction);
        pushButton_ExportPointCloud->setObjectName(QStringLiteral("pushButton_ExportPointCloud"));

        gridLayout->addWidget(pushButton_ExportPointCloud, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(586, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        openGLWidget_PointCloud = new QOpenGLWidget(Reconstruction);
        openGLWidget_PointCloud->setObjectName(QStringLiteral("openGLWidget_PointCloud"));

        gridLayout->addWidget(openGLWidget_PointCloud, 1, 0, 1, 3);


        retranslateUi(Reconstruction);

        QMetaObject::connectSlotsByName(Reconstruction);
    } // setupUi

    void retranslateUi(QWidget *Reconstruction)
    {
        Reconstruction->setWindowTitle(QApplication::translate("Reconstruction", "Reconstruction", Q_NULLPTR));
        pushButton_Reconstruction->setText(QApplication::translate("Reconstruction", "\346\267\261\345\272\246\351\207\215\345\273\272", Q_NULLPTR));
        pushButton_ExportPointCloud->setText(QApplication::translate("Reconstruction", "\345\257\274\345\207\272\347\202\271\344\272\221\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Reconstruction: public Ui_Reconstruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTION_H
