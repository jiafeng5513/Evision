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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QAction *actionDebug;
    QAction *action_CameraParam;
    QAction *action_StereoMatchView;
    QAction *action_DepthMap_View;
    QAction *action_PointCloud_View;
    QAction *action_Measure_View;
    QAction *action_SFM_View;
    QAction *action_3dReconstruct_View;
    QAction *action_CalibrateView;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QPushButton *pushButton_RangeSinglePoint;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EvisionClass)
    {
        if (EvisionClass->objectName().isEmpty())
            EvisionClass->setObjectName(QString::fromUtf8("EvisionClass"));
        EvisionClass->resize(1081, 712);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EvisionClass->sizePolicy().hasHeightForWidth());
        EvisionClass->setSizePolicy(sizePolicy);
        EvisionClass->setMinimumSize(QSize(0, 0));
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
        actionDebug = new QAction(EvisionClass);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        action_CameraParam = new QAction(EvisionClass);
        action_CameraParam->setObjectName(QString::fromUtf8("action_CameraParam"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Evision/resource/params_128px_1101042_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_CameraParam->setIcon(icon4);
        action_StereoMatchView = new QAction(EvisionClass);
        action_StereoMatchView->setObjectName(QString::fromUtf8("action_StereoMatchView"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Evision/resource/networking_128px_1154117_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_StereoMatchView->setIcon(icon5);
        action_DepthMap_View = new QAction(EvisionClass);
        action_DepthMap_View->setObjectName(QString::fromUtf8("action_DepthMap_View"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Evision/resource/z_lowercase_128px_1168343_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_DepthMap_View->setIcon(icon6);
        action_PointCloud_View = new QAction(EvisionClass);
        action_PointCloud_View->setObjectName(QString::fromUtf8("action_PointCloud_View"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Evision/resource/cloud_128px_1156707_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_PointCloud_View->setIcon(icon7);
        action_Measure_View = new QAction(EvisionClass);
        action_Measure_View->setObjectName(QString::fromUtf8("action_Measure_View"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Evision/resource/measure_centimeter_76px_1116359_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Measure_View->setIcon(icon8);
        action_SFM_View = new QAction(EvisionClass);
        action_SFM_View->setObjectName(QString::fromUtf8("action_SFM_View"));
        action_3dReconstruct_View = new QAction(EvisionClass);
        action_3dReconstruct_View->setObjectName(QString::fromUtf8("action_3dReconstruct_View"));
        action_CalibrateView = new QAction(EvisionClass);
        action_CalibrateView->setObjectName(QString::fromUtf8("action_CalibrateView"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Evision/resource/checkered_128px_1155158_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_CalibrateView->setIcon(icon9);
        centralWidget = new QWidget(EvisionClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(10, 10, 661, 341));
        mdiArea->setAcceptDrops(true);
        pushButton_RangeSinglePoint = new QPushButton(centralWidget);
        pushButton_RangeSinglePoint->setObjectName(QString::fromUtf8("pushButton_RangeSinglePoint"));
        pushButton_RangeSinglePoint->setGeometry(QRect(700, 320, 71, 23));
        EvisionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EvisionClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1081, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        EvisionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EvisionClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        EvisionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EvisionClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        EvisionClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_StereoCamera);
        menu->addAction(action_Camera);
        menu->addAction(action_ShowPointCloud);
        menu->addAction(action_CameraParam);
        menu->addAction(actionDebug);
        menu_2->addAction(action_Help);
        menu_2->addAction(action_About);
        menu_3->addAction(action_CalibrateView);
        menu_3->addAction(action_StereoMatchView);
        menu_3->addAction(action_DepthMap_View);
        menu_3->addAction(action_PointCloud_View);
        menu_3->addAction(action_Measure_View);
        menu_4->addAction(action_SFM_View);
        menu_4->addAction(action_3dReconstruct_View);
        mainToolBar->addAction(action_Camera);
        mainToolBar->addAction(action_StereoCamera);
        mainToolBar->addAction(action_ShowPointCloud);
        mainToolBar->addAction(action_CameraParam);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_CalibrateView);
        mainToolBar->addAction(action_StereoMatchView);
        mainToolBar->addAction(action_DepthMap_View);
        mainToolBar->addAction(action_PointCloud_View);
        mainToolBar->addAction(action_Measure_View);
        mainToolBar->addSeparator();

        retranslateUi(EvisionClass);
        QObject::connect(pushButton_RangeSinglePoint, SIGNAL(clicked()), EvisionClass, SLOT(getDistance()));
        QObject::connect(actionDebug, SIGNAL(triggered()), EvisionClass, SLOT(onTestAlltheParam()));
        QObject::connect(action_ShowPointCloud, SIGNAL(triggered()), EvisionClass, SLOT(onShowPointCloud()));
        QObject::connect(action_StereoCamera, SIGNAL(triggered()), EvisionClass, SLOT(onStereoCamera()));
        QObject::connect(action_Camera, SIGNAL(triggered()), EvisionClass, SLOT(onCamera()));
        QObject::connect(action_CalibrateView, SIGNAL(triggered()), EvisionClass, SLOT(on_action_calibrate_view()));
        QObject::connect(action_StereoMatchView, SIGNAL(triggered()), EvisionClass, SLOT(on_action_stereoMatch_view()));

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
        actionDebug->setText(QApplication::translate("EvisionClass", "Debug", nullptr));
        action_CameraParam->setText(QApplication::translate("EvisionClass", "\347\233\270\346\234\272\345\217\257\350\247\206\345\214\226", nullptr));
        action_StereoMatchView->setText(QApplication::translate("EvisionClass", "\347\253\213\344\275\223\345\214\271\351\205\215", nullptr));
        action_DepthMap_View->setText(QApplication::translate("EvisionClass", "\347\224\237\346\210\220\346\267\261\345\272\246\345\233\276", nullptr));
        action_PointCloud_View->setText(QApplication::translate("EvisionClass", "\347\224\237\346\210\220\347\202\271\344\272\221", nullptr));
        action_Measure_View->setText(QApplication::translate("EvisionClass", "\345\217\214\347\233\256\346\265\213\350\267\235", nullptr));
        action_SFM_View->setText(QApplication::translate("EvisionClass", "SFM", nullptr));
        action_3dReconstruct_View->setText(QApplication::translate("EvisionClass", "\344\270\211\347\273\264\351\207\215\345\273\272", nullptr));
        action_CalibrateView->setText(QApplication::translate("EvisionClass", "\347\233\270\346\234\272\346\240\207\345\256\232", nullptr));
        pushButton_RangeSinglePoint->setText(QApplication::translate("EvisionClass", "\346\265\213\351\207\217", nullptr));
        menu->setTitle(QApplication::translate("EvisionClass", "\345\267\245\345\205\267", nullptr));
        menu_2->setTitle(QApplication::translate("EvisionClass", "\345\270\256\345\212\251", nullptr));
        menu_3->setTitle(QApplication::translate("EvisionClass", "\345\217\214\347\233\256\350\247\206\350\247\211", nullptr));
        menu_4->setTitle(QApplication::translate("EvisionClass", "SLAM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EvisionClass: public Ui_EvisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVISION_H
