/********************************************************************************
** Form generated from reading UI file 'Evision.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVISION_H
#define UI_EVISION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EvisionClass
{
public:
    QAction *action_StereoCamera;
    QAction *action_ShowPointCloud;
    QAction *action_Camera;
    QAction *action_Help;
    QAction *action_About;
    QAction *action_StereoMatchView;
    QAction *action_Measure_View;
    QAction *action_CalibrateView;
    QAction *action_ObjectDetection;
    QAction *action_LogView;
    QAction *actio_Rectify;
    QAction *action_dispToPCD;
    QAction *action_CreateParamFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menuAi;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EvisionClass)
    {
        if (EvisionClass->objectName().isEmpty())
            EvisionClass->setObjectName(QString::fromUtf8("EvisionClass"));
        EvisionClass->resize(1024, 710);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EvisionClass->sizePolicy().hasHeightForWidth());
        EvisionClass->setSizePolicy(sizePolicy);
        EvisionClass->setMinimumSize(QSize(1024, 710));
        EvisionClass->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Evision/resource/Evision.ico"), QSize(), QIcon::Normal, QIcon::Off);
        EvisionClass->setWindowIcon(icon);
        action_StereoCamera = new QAction(EvisionClass);
        action_StereoCamera->setObjectName(QString::fromUtf8("action_StereoCamera"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Evision/resource/dualshot.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_StereoCamera->setIcon(icon1);
        action_ShowPointCloud = new QAction(EvisionClass);
        action_ShowPointCloud->setObjectName(QString::fromUtf8("action_ShowPointCloud"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Evision/resource/cloud_128px_1156740_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_ShowPointCloud->setIcon(icon2);
        action_Camera = new QAction(EvisionClass);
        action_Camera->setObjectName(QString::fromUtf8("action_Camera"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Evision/resource/shot2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Camera->setIcon(icon3);
        action_Help = new QAction(EvisionClass);
        action_Help->setObjectName(QString::fromUtf8("action_Help"));
        action_About = new QAction(EvisionClass);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        action_StereoMatchView = new QAction(EvisionClass);
        action_StereoMatchView->setObjectName(QString::fromUtf8("action_StereoMatchView"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Evision/resource/networking_128px_1154117_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_StereoMatchView->setIcon(icon4);
        action_Measure_View = new QAction(EvisionClass);
        action_Measure_View->setObjectName(QString::fromUtf8("action_Measure_View"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Evision/resource/measure_centimeter_76px_1116359_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Measure_View->setIcon(icon5);
        action_CalibrateView = new QAction(EvisionClass);
        action_CalibrateView->setObjectName(QString::fromUtf8("action_CalibrateView"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Evision/resource/checkered_128px_1155158_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_CalibrateView->setIcon(icon6);
        action_ObjectDetection = new QAction(EvisionClass);
        action_ObjectDetection->setObjectName(QString::fromUtf8("action_ObjectDetection"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Evision/resource/face_detection_128px_1218199_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_ObjectDetection->setIcon(icon7);
        action_LogView = new QAction(EvisionClass);
        action_LogView->setObjectName(QString::fromUtf8("action_LogView"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Evision/resource/log_128px_1160546_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_LogView->setIcon(icon8);
        actio_Rectify = new QAction(EvisionClass);
        actio_Rectify->setObjectName(QString::fromUtf8("actio_Rectify"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Evision/resource/focusing_128px_1162023_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actio_Rectify->setIcon(icon9);
        action_dispToPCD = new QAction(EvisionClass);
        action_dispToPCD->setObjectName(QString::fromUtf8("action_dispToPCD"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Evision/resource/cloud_refresh_128px_1182773_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_dispToPCD->setIcon(icon10);
        action_CreateParamFile = new QAction(EvisionClass);
        action_CreateParamFile->setObjectName(QString::fromUtf8("action_CreateParamFile"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Evision/resource/params_128px_1101042_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_CreateParamFile->setIcon(icon11);
        centralWidget = new QWidget(EvisionClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setAcceptDrops(false);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        EvisionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EvisionClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menuAi = new QMenu(menuBar);
        menuAi->setObjectName(QString::fromUtf8("menuAi"));
        EvisionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EvisionClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAcceptDrops(true);
        EvisionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EvisionClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EvisionClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menuAi->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_StereoCamera);
        menu->addAction(action_Camera);
        menu->addAction(action_ShowPointCloud);
        menu->addAction(action_CreateParamFile);
        menu_2->addAction(action_Help);
        menu_2->addAction(action_About);
        menu_2->addAction(action_LogView);
        menu_3->addAction(action_CalibrateView);
        menu_3->addAction(actio_Rectify);
        menu_3->addAction(action_StereoMatchView);
        menu_3->addAction(action_Measure_View);
        menu_3->addAction(action_dispToPCD);
        menuAi->addAction(action_ObjectDetection);
        mainToolBar->addAction(action_Camera);
        mainToolBar->addAction(action_StereoCamera);
        mainToolBar->addAction(action_ShowPointCloud);
        mainToolBar->addAction(action_CreateParamFile);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_CalibrateView);
        mainToolBar->addAction(actio_Rectify);
        mainToolBar->addAction(action_StereoMatchView);
        mainToolBar->addAction(action_Measure_View);
        mainToolBar->addAction(action_dispToPCD);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_ObjectDetection);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_LogView);

        retranslateUi(EvisionClass);
        QObject::connect(action_ShowPointCloud, SIGNAL(triggered()), EvisionClass, SLOT(onShowPointCloud()));
        QObject::connect(action_StereoCamera, SIGNAL(triggered()), EvisionClass, SLOT(onStereoCamera()));
        QObject::connect(action_Camera, SIGNAL(triggered()), EvisionClass, SLOT(onCamera()));
        QObject::connect(action_CalibrateView, SIGNAL(triggered()), EvisionClass, SLOT(on_action_calibrate_view()));
        QObject::connect(action_StereoMatchView, SIGNAL(triggered()), EvisionClass, SLOT(on_action_stereoMatch_view()));
        QObject::connect(action_Measure_View, SIGNAL(triggered()), EvisionClass, SLOT(on_action_Measure_view()));
        QObject::connect(action_ObjectDetection, SIGNAL(triggered()), EvisionClass, SLOT(on_action_ObjectDetection_view()));
        QObject::connect(action_LogView, SIGNAL(triggered()), EvisionClass, SLOT(on_action_LogViewSwitch()));
        QObject::connect(actio_Rectify, SIGNAL(triggered()), EvisionClass, SLOT(on_action_rectify()));
        QObject::connect(action_dispToPCD, SIGNAL(triggered()), EvisionClass, SLOT(on_action_disp_to_pcd()));
        QObject::connect(action_CreateParamFile, SIGNAL(triggered()), EvisionClass, SLOT(on_action_create_param()));

        QMetaObject::connectSlotsByName(EvisionClass);
    } // setupUi

    void retranslateUi(QMainWindow *EvisionClass)
    {
        EvisionClass->setWindowTitle(QApplication::translate("EvisionClass", "Evision", nullptr));
        action_StereoCamera->setText(QApplication::translate("EvisionClass", "\346\213\215\346\221\204\345\217\214\351\225\234\345\244\264\347\205\247\347\211\207", nullptr));
        action_ShowPointCloud->setText(QApplication::translate("EvisionClass", "\347\202\271\344\272\221\345\217\257\350\247\206\345\214\226", nullptr));
        action_Camera->setText(QApplication::translate("EvisionClass", "\346\213\215\346\221\204\345\215\225\351\225\234\345\244\264\347\205\247\347\211\207", nullptr));
        action_Help->setText(QApplication::translate("EvisionClass", "\345\270\256\345\212\251\344\277\241\346\201\257", nullptr));
        action_About->setText(QApplication::translate("EvisionClass", "\345\205\263\344\272\216", nullptr));
        action_StereoMatchView->setText(QApplication::translate("EvisionClass", "\347\253\213\344\275\223\345\214\271\351\205\215", nullptr));
        action_Measure_View->setText(QApplication::translate("EvisionClass", "\345\217\214\347\233\256\346\265\213\350\267\235", nullptr));
        action_CalibrateView->setText(QApplication::translate("EvisionClass", "\347\233\270\346\234\272\346\240\207\345\256\232", nullptr));
        action_ObjectDetection->setText(QApplication::translate("EvisionClass", "\347\233\256\346\240\207\346\243\200\346\265\213", nullptr));
        action_LogView->setText(QApplication::translate("EvisionClass", "LogView", nullptr));
#ifndef QT_NO_TOOLTIP
        action_LogView->setToolTip(QApplication::translate("EvisionClass", "\345\210\207\346\215\242LogView\347\232\204\346\230\276\347\244\272\347\212\266\346\200\201", nullptr));
#endif // QT_NO_TOOLTIP
        actio_Rectify->setText(QApplication::translate("EvisionClass", "\347\253\213\344\275\223\346\240\241\346\255\243", nullptr));
        action_dispToPCD->setText(QApplication::translate("EvisionClass", "\350\247\206\345\267\256\350\275\254\347\202\271\344\272\221", nullptr));
        action_CreateParamFile->setText(QApplication::translate("EvisionClass", "\346\236\204\351\200\240\345\217\202\346\225\260\346\226\207\344\273\266", nullptr));
        menu->setTitle(QApplication::translate("EvisionClass", "\345\267\245\345\205\267", nullptr));
        menu_2->setTitle(QApplication::translate("EvisionClass", "\345\270\256\345\212\251", nullptr));
        menu_3->setTitle(QApplication::translate("EvisionClass", "\345\217\214\347\233\256\350\247\206\350\247\211", nullptr));
        menuAi->setTitle(QApplication::translate("EvisionClass", "Ai", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EvisionClass: public Ui_EvisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVISION_H
