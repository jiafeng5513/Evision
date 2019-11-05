/********************************************************************************
** Form generated from reading UI file 'Evision3dViz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVISION3DVIZ_H
#define UI_EVISION3DVIZ_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Evision3dVizClass
{
public:
    QGridLayout *gridLayout_3;
    QTreeWidget *dataTree;
    QTableWidget *propertyTable;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_1;
    QLCDNumber *rLCD;
    QSlider *rSlider;
    QLabel *label_2;
    QLCDNumber *gLCD;
    QSlider *gSlider;
    QLabel *label_3;
    QLCDNumber *bLCD;
    QSlider *bSlider;
    QLabel *label_4;
    QLCDNumber *sizeLCD;
    QSlider *pSlider;
    QFrame *frame1;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Clean;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_SaveAs;
    QPushButton *pushButton_Change;
    QPushButton *pushButton_Exit;
    QPushButton *pushButton_PointColor;
    QPushButton *pushButton_BackgroundColor;
    QPushButton *pushButton_MainView;
    QPushButton *pushButton_LeftView;
    QPushButton *pushButton_TopView;
    QPushButton *pushButton_GenCube;
    QPushButton *pushButton_GenSphere;
    QPushButton *pushButton_GenCylinder;
    QPushButton *pushButton_MeshSurface;
    QPushButton *pushButton_Wireframe;
    QPushButton *pushButton_RandomColor;
    QCheckBox *bgcCbx;
    QCheckBox *cooCbx;
    QSpacerItem *horizontalSpacer;
    QVTKWidget *screen;

    void setupUi(QWidget *Evision3dVizClass)
    {
        if (Evision3dVizClass->objectName().isEmpty())
            Evision3dVizClass->setObjectName(QString::fromUtf8("Evision3dVizClass"));
        Evision3dVizClass->resize(897, 579);
        Evision3dVizClass->setContextMenuPolicy(Qt::CustomContextMenu);
        gridLayout_3 = new QGridLayout(Evision3dVizClass);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        dataTree = new QTreeWidget(Evision3dVizClass);
        dataTree->setObjectName(QString::fromUtf8("dataTree"));
        dataTree->setMinimumSize(QSize(0, 180));
        dataTree->setMaximumSize(QSize(300, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        dataTree->setFont(font);
        dataTree->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout_3->addWidget(dataTree, 1, 0, 1, 1);

        propertyTable = new QTableWidget(Evision3dVizClass);
        if (propertyTable->columnCount() < 2)
            propertyTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        propertyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        propertyTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (propertyTable->rowCount() < 4)
            propertyTable->setRowCount(4);
        propertyTable->setObjectName(QString::fromUtf8("propertyTable"));
        propertyTable->setMinimumSize(QSize(0, 180));
        propertyTable->setMaximumSize(QSize(300, 16777215));
        QFont font1;
        font1.setPointSize(9);
        propertyTable->setFont(font1);
        propertyTable->setFrameShadow(QFrame::Sunken);
        propertyTable->setMidLineWidth(0);
        propertyTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        propertyTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        propertyTable->setAutoScroll(true);
        propertyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        propertyTable->setTabKeyNavigation(true);
        propertyTable->setProperty("showDropIndicator", QVariant(true));
        propertyTable->setDragDropOverwriteMode(true);
        propertyTable->setAlternatingRowColors(false);
        propertyTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        propertyTable->setTextElideMode(Qt::ElideLeft);
        propertyTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        propertyTable->setShowGrid(false);
        propertyTable->setWordWrap(true);
        propertyTable->setCornerButtonEnabled(true);
        propertyTable->setRowCount(4);
        propertyTable->setColumnCount(2);
        propertyTable->horizontalHeader()->setCascadingSectionResizes(false);
        propertyTable->horizontalHeader()->setDefaultSectionSize(100);
        propertyTable->horizontalHeader()->setHighlightSections(true);
        propertyTable->horizontalHeader()->setMinimumSectionSize(25);
        propertyTable->horizontalHeader()->setStretchLastSection(true);
        propertyTable->verticalHeader()->setVisible(false);
        propertyTable->verticalHeader()->setCascadingSectionResizes(false);

        gridLayout_3->addWidget(propertyTable, 2, 0, 1, 1);

        frame = new QFrame(Evision3dVizClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(300, 16777215));
        frame->setFrameShape(QFrame::Box);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_1 = new QLabel(frame);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label_1->setFont(font2);

        gridLayout_2->addWidget(label_1, 0, 0, 1, 1);

        rLCD = new QLCDNumber(frame);
        rLCD->setObjectName(QString::fromUtf8("rLCD"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rLCD->sizePolicy().hasHeightForWidth());
        rLCD->setSizePolicy(sizePolicy1);
        rLCD->setAutoFillBackground(false);
        rLCD->setInputMethodHints(Qt::ImhNone);
        rLCD->setFrameShape(QFrame::Panel);
        rLCD->setFrameShadow(QFrame::Raised);
        rLCD->setLineWidth(1);
        rLCD->setSmallDecimalPoint(false);
        rLCD->setDigitCount(3);
        rLCD->setMode(QLCDNumber::Dec);
        rLCD->setProperty("value", QVariant(255.000000000000000));
        rLCD->setProperty("intValue", QVariant(255));

        gridLayout_2->addWidget(rLCD, 0, 1, 1, 1);

        rSlider = new QSlider(frame);
        rSlider->setObjectName(QString::fromUtf8("rSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rSlider->sizePolicy().hasHeightForWidth());
        rSlider->setSizePolicy(sizePolicy2);
        rSlider->setMinimumSize(QSize(132, 0));
        rSlider->setMaximum(255);
        rSlider->setSliderPosition(255);
        rSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(rSlider, 0, 2, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font2);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        gLCD = new QLCDNumber(frame);
        gLCD->setObjectName(QString::fromUtf8("gLCD"));
        sizePolicy1.setHeightForWidth(gLCD->sizePolicy().hasHeightForWidth());
        gLCD->setSizePolicy(sizePolicy1);
        gLCD->setFrameShape(QFrame::Panel);
        gLCD->setDigitCount(3);
        gLCD->setProperty("intValue", QVariant(255));

        gridLayout_2->addWidget(gLCD, 1, 1, 1, 1);

        gSlider = new QSlider(frame);
        gSlider->setObjectName(QString::fromUtf8("gSlider"));
        sizePolicy2.setHeightForWidth(gSlider->sizePolicy().hasHeightForWidth());
        gSlider->setSizePolicy(sizePolicy2);
        gSlider->setMinimumSize(QSize(132, 0));
        gSlider->setMaximum(255);
        gSlider->setSliderPosition(255);
        gSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(gSlider, 1, 2, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font2);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        bLCD = new QLCDNumber(frame);
        bLCD->setObjectName(QString::fromUtf8("bLCD"));
        sizePolicy1.setHeightForWidth(bLCD->sizePolicy().hasHeightForWidth());
        bLCD->setSizePolicy(sizePolicy1);
        bLCD->setFrameShape(QFrame::Panel);
        bLCD->setDigitCount(3);
        bLCD->setProperty("intValue", QVariant(255));

        gridLayout_2->addWidget(bLCD, 2, 1, 1, 1);

        bSlider = new QSlider(frame);
        bSlider->setObjectName(QString::fromUtf8("bSlider"));
        sizePolicy2.setHeightForWidth(bSlider->sizePolicy().hasHeightForWidth());
        bSlider->setSizePolicy(sizePolicy2);
        bSlider->setMinimumSize(QSize(132, 0));
        bSlider->setMaximum(255);
        bSlider->setSliderPosition(255);
        bSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(bSlider, 2, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font2);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        sizeLCD = new QLCDNumber(frame);
        sizeLCD->setObjectName(QString::fromUtf8("sizeLCD"));
        sizePolicy1.setHeightForWidth(sizeLCD->sizePolicy().hasHeightForWidth());
        sizeLCD->setSizePolicy(sizePolicy1);
        sizeLCD->setDigitCount(1);
        sizeLCD->setSegmentStyle(QLCDNumber::Filled);
        sizeLCD->setProperty("intValue", QVariant(1));

        gridLayout_2->addWidget(sizeLCD, 3, 1, 1, 1);

        pSlider = new QSlider(frame);
        pSlider->setObjectName(QString::fromUtf8("pSlider"));
        sizePolicy2.setHeightForWidth(pSlider->sizePolicy().hasHeightForWidth());
        pSlider->setSizePolicy(sizePolicy2);
        pSlider->setMinimumSize(QSize(132, 0));
        pSlider->setMinimum(1);
        pSlider->setMaximum(10);
        pSlider->setSliderPosition(1);
        pSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(pSlider, 3, 2, 1, 1);


        gridLayout_3->addWidget(frame, 3, 0, 1, 1);

        frame1 = new QFrame(Evision3dVizClass);
        frame1->setObjectName(QString::fromUtf8("frame1"));
        frame1->setFrameShape(QFrame::Box);
        frame1->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Open = new QPushButton(frame1);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));
        pushButton_Open->setMaximumSize(QSize(31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/PointCloudTool/Resources/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Open->setIcon(icon);
        pushButton_Open->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_Open, 0, 0, 1, 1);

        pushButton_Add = new QPushButton(frame1);
        pushButton_Add->setObjectName(QString::fromUtf8("pushButton_Add"));
        pushButton_Add->setMaximumSize(QSize(31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/PointCloudTool/Resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Add->setIcon(icon1);
        pushButton_Add->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_Add, 0, 1, 1, 1);

        pushButton_Clean = new QPushButton(frame1);
        pushButton_Clean->setObjectName(QString::fromUtf8("pushButton_Clean"));
        pushButton_Clean->setMaximumSize(QSize(31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/PointCloudTool/Resources/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Clean->setIcon(icon2);
        pushButton_Clean->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_Clean, 0, 2, 1, 1);

        pushButton_Save = new QPushButton(frame1);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));
        pushButton_Save->setMaximumSize(QSize(31, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/PointCloudTool/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Save->setIcon(icon3);
        pushButton_Save->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_Save, 0, 3, 1, 1);

        pushButton_SaveAs = new QPushButton(frame1);
        pushButton_SaveAs->setObjectName(QString::fromUtf8("pushButton_SaveAs"));
        pushButton_SaveAs->setMaximumSize(QSize(31, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/PointCloudTool/Resources/saveBinary.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_SaveAs->setIcon(icon4);
        pushButton_SaveAs->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_SaveAs, 0, 4, 1, 1);

        pushButton_Change = new QPushButton(frame1);
        pushButton_Change->setObjectName(QString::fromUtf8("pushButton_Change"));
        pushButton_Change->setMaximumSize(QSize(31, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/PointCloudTool/Resources/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Change->setIcon(icon5);
        pushButton_Change->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_Change, 0, 5, 1, 1);

        pushButton_Exit = new QPushButton(frame1);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setMaximumSize(QSize(31, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/PointCloudTool/Resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon6);
        pushButton_Exit->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_Exit, 0, 6, 1, 1);

        pushButton_PointColor = new QPushButton(frame1);
        pushButton_PointColor->setObjectName(QString::fromUtf8("pushButton_PointColor"));
        pushButton_PointColor->setMaximumSize(QSize(31, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/PointCloudTool/Resources/pointcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_PointColor->setIcon(icon7);
        pushButton_PointColor->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_PointColor, 0, 7, 1, 1);

        pushButton_BackgroundColor = new QPushButton(frame1);
        pushButton_BackgroundColor->setObjectName(QString::fromUtf8("pushButton_BackgroundColor"));
        pushButton_BackgroundColor->setMaximumSize(QSize(31, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/PointCloudTool/Resources/bgcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_BackgroundColor->setIcon(icon8);
        pushButton_BackgroundColor->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_BackgroundColor, 0, 8, 1, 1);

        pushButton_MainView = new QPushButton(frame1);
        pushButton_MainView->setObjectName(QString::fromUtf8("pushButton_MainView"));
        pushButton_MainView->setMaximumSize(QSize(31, 31));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/PointCloudTool/Resources/zhengshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_MainView->setIcon(icon9);
        pushButton_MainView->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_MainView, 0, 9, 1, 1);

        pushButton_LeftView = new QPushButton(frame1);
        pushButton_LeftView->setObjectName(QString::fromUtf8("pushButton_LeftView"));
        pushButton_LeftView->setMaximumSize(QSize(31, 31));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/PointCloudTool/Resources/zuoshi.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_LeftView->setIcon(icon10);
        pushButton_LeftView->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_LeftView, 0, 10, 1, 1);

        pushButton_TopView = new QPushButton(frame1);
        pushButton_TopView->setObjectName(QString::fromUtf8("pushButton_TopView"));
        pushButton_TopView->setMaximumSize(QSize(31, 31));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/PointCloudTool/Resources/fushi.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_TopView->setIcon(icon11);
        pushButton_TopView->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_TopView, 0, 11, 1, 1);

        pushButton_GenCube = new QPushButton(frame1);
        pushButton_GenCube->setObjectName(QString::fromUtf8("pushButton_GenCube"));
        pushButton_GenCube->setMaximumSize(QSize(31, 31));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/PointCloudTool/Resources/cube.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_GenCube->setIcon(icon12);
        pushButton_GenCube->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_GenCube, 0, 12, 1, 1);

        pushButton_GenSphere = new QPushButton(frame1);
        pushButton_GenSphere->setObjectName(QString::fromUtf8("pushButton_GenSphere"));
        pushButton_GenSphere->setMaximumSize(QSize(31, 31));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/PointCloudTool/Resources/sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_GenSphere->setIcon(icon13);
        pushButton_GenSphere->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_GenSphere, 0, 13, 1, 1);

        pushButton_GenCylinder = new QPushButton(frame1);
        pushButton_GenCylinder->setObjectName(QString::fromUtf8("pushButton_GenCylinder"));
        pushButton_GenCylinder->setMaximumSize(QSize(31, 31));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/PointCloudTool/Resources/cylinder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_GenCylinder->setIcon(icon14);
        pushButton_GenCylinder->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_GenCylinder, 0, 14, 1, 1);

        pushButton_MeshSurface = new QPushButton(frame1);
        pushButton_MeshSurface->setObjectName(QString::fromUtf8("pushButton_MeshSurface"));
        pushButton_MeshSurface->setMaximumSize(QSize(31, 31));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/PointCloudTool/Resources/mesh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_MeshSurface->setIcon(icon15);
        pushButton_MeshSurface->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_MeshSurface, 0, 15, 1, 1);

        pushButton_Wireframe = new QPushButton(frame1);
        pushButton_Wireframe->setObjectName(QString::fromUtf8("pushButton_Wireframe"));
        pushButton_Wireframe->setMaximumSize(QSize(31, 31));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/PointCloudTool/Resources/frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Wireframe->setIcon(icon16);
        pushButton_Wireframe->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_Wireframe, 0, 16, 1, 1);

        pushButton_RandomColor = new QPushButton(frame1);
        pushButton_RandomColor->setObjectName(QString::fromUtf8("pushButton_RandomColor"));
        pushButton_RandomColor->setMaximumSize(QSize(31, 31));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/PointCloudTool/Resources/roam_color_128px_1186912_easyicon.net.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_RandomColor->setIcon(icon17);
        pushButton_RandomColor->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_RandomColor, 0, 17, 1, 1);

        bgcCbx = new QCheckBox(frame1);
        bgcCbx->setObjectName(QString::fromUtf8("bgcCbx"));
        bgcCbx->setMaximumSize(QSize(90, 16777215));
        bgcCbx->setFont(font2);

        gridLayout->addWidget(bgcCbx, 0, 18, 1, 1);

        cooCbx = new QCheckBox(frame1);
        cooCbx->setObjectName(QString::fromUtf8("cooCbx"));
        cooCbx->setMinimumSize(QSize(90, 0));
        cooCbx->setFont(font2);

        gridLayout->addWidget(cooCbx, 0, 19, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 20, 1, 1);


        gridLayout_3->addWidget(frame1, 0, 0, 1, 2);

        screen = new QVTKWidget(Evision3dVizClass);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setMinimumSize(QSize(600, 400));

        gridLayout_3->addWidget(screen, 1, 1, 3, 1);


        retranslateUi(Evision3dVizClass);
        QObject::connect(pushButton_Open, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_Open()));
        QObject::connect(pushButton_Add, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_Add()));
        QObject::connect(pushButton_Clean, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_Clean()));
        QObject::connect(pushButton_Save, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_Save()));
        QObject::connect(pushButton_SaveAs, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_SaveAs()));
        QObject::connect(pushButton_Change, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_Change()));
        QObject::connect(pushButton_Exit, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_Exit()));
        QObject::connect(pushButton_PointColor, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_PointColor()));
        QObject::connect(pushButton_BackgroundColor, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_BackgroundColor()));
        QObject::connect(pushButton_MainView, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_MainView()));
        QObject::connect(pushButton_LeftView, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_LeftView()));
        QObject::connect(pushButton_TopView, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_TopViewe()));
        QObject::connect(pushButton_GenCube, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_GenCube()));
        QObject::connect(pushButton_GenSphere, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_GenSphere()));
        QObject::connect(pushButton_GenCylinder, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_GenCylinder()));
        QObject::connect(pushButton_MeshSurface, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_MeshSurface()));
        QObject::connect(pushButton_Wireframe, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_Wireframe()));
        QObject::connect(pushButton_RandomColor, SIGNAL(clicked()), Evision3dVizClass, SLOT(onPushButton_RandomColor()));
        QObject::connect(bgcCbx, SIGNAL(stateChanged(int)), Evision3dVizClass, SLOT(onCheckboxStateChanged_DarkLight(int)));
        QObject::connect(cooCbx, SIGNAL(stateChanged(int)), Evision3dVizClass, SLOT(onCheckboxStateChanged_Coordinate(int)));
        QObject::connect(dataTree, SIGNAL(itemClicked(QTreeWidgetItem*,int)), Evision3dVizClass, SLOT(itemSelected(QTreeWidgetItem*,int)));
        QObject::connect(rSlider, SIGNAL(valueChanged(int)), Evision3dVizClass, SLOT(onValueChanged_r_Slider(int)));
        QObject::connect(gSlider, SIGNAL(valueChanged(int)), Evision3dVizClass, SLOT(onValueChanged_g_Slider(int)));
        QObject::connect(bSlider, SIGNAL(valueChanged(int)), Evision3dVizClass, SLOT(onValueChanged_b_Slider(int)));
        QObject::connect(pSlider, SIGNAL(sliderReleased()), Evision3dVizClass, SLOT(onReleased_p_Slider()));
        QObject::connect(pSlider, SIGNAL(valueChanged(int)), Evision3dVizClass, SLOT(onValueChanged_p_Slider(int)));
        QObject::connect(rSlider, SIGNAL(sliderReleased()), Evision3dVizClass, SLOT(onReleased_rgb_Slider()));
        QObject::connect(gSlider, SIGNAL(sliderReleased()), Evision3dVizClass, SLOT(onReleased_rgb_Slider()));
        QObject::connect(bSlider, SIGNAL(sliderReleased()), Evision3dVizClass, SLOT(onReleased_rgb_Slider()));

        QMetaObject::connectSlotsByName(Evision3dVizClass);
    } // setupUi

    void retranslateUi(QWidget *Evision3dVizClass)
    {
        Evision3dVizClass->setWindowTitle(QApplication::translate("Evision3dVizClass", "PointCloudTool", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = dataTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Evision3dVizClass", "Point Cloud File", nullptr));
        QTableWidgetItem *___qtablewidgetitem = propertyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Evision3dVizClass", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = propertyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Evision3dVizClass", "Value", nullptr));
        label_1->setText(QApplication::translate("Evision3dVizClass", "Red", nullptr));
        label_2->setText(QApplication::translate("Evision3dVizClass", "Green", nullptr));
        label_3->setText(QApplication::translate("Evision3dVizClass", "Blue", nullptr));
        label_4->setText(QApplication::translate("Evision3dVizClass", "Point Size", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_Open->setToolTip(QApplication::translate("Evision3dVizClass", "\346\211\223\345\274\200", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Open->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Add->setToolTip(QApplication::translate("Evision3dVizClass", "\346\267\273\345\212\240", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Add->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Clean->setToolTip(QApplication::translate("Evision3dVizClass", "\346\270\205\351\231\244", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Clean->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Save->setToolTip(QApplication::translate("Evision3dVizClass", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Save->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_SaveAs->setToolTip(QApplication::translate("Evision3dVizClass", "\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_SaveAs->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Change->setToolTip(QApplication::translate("Evision3dVizClass", "\346\233\264\346\224\271", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Change->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Exit->setToolTip(QApplication::translate("Evision3dVizClass", "\345\205\263\351\227\255", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Exit->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_PointColor->setToolTip(QApplication::translate("Evision3dVizClass", "\347\202\271\344\272\221\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_PointColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_BackgroundColor->setToolTip(QApplication::translate("Evision3dVizClass", "\350\203\214\346\231\257\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_BackgroundColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_MainView->setToolTip(QApplication::translate("Evision3dVizClass", "\344\270\273\350\247\206\345\233\276", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_MainView->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_LeftView->setToolTip(QApplication::translate("Evision3dVizClass", "\345\267\246\350\247\206\345\233\276", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_LeftView->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_TopView->setToolTip(QApplication::translate("Evision3dVizClass", "\344\277\257\350\247\206\345\233\276", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_TopView->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_GenCube->setToolTip(QApplication::translate("Evision3dVizClass", "\347\224\237\346\210\220\347\253\213\346\226\271\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_GenCube->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_GenSphere->setToolTip(QApplication::translate("Evision3dVizClass", "\347\224\237\346\210\220\347\220\203", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_GenSphere->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_GenCylinder->setToolTip(QApplication::translate("Evision3dVizClass", "\347\224\237\346\210\220\345\234\206\346\237\261\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_GenCylinder->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_MeshSurface->setToolTip(QApplication::translate("Evision3dVizClass", "Surface", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_MeshSurface->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Wireframe->setToolTip(QApplication::translate("Evision3dVizClass", "Wireframe", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_Wireframe->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_RandomColor->setToolTip(QApplication::translate("Evision3dVizClass", "\351\232\217\346\234\272\351\242\234\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_RandomColor->setText(QString());
        bgcCbx->setText(QApplication::translate("Evision3dVizClass", "Dark/Light", nullptr));
        cooCbx->setText(QApplication::translate("Evision3dVizClass", "Coordinate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Evision3dVizClass: public Ui_Evision3dVizClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVISION3DVIZ_H
