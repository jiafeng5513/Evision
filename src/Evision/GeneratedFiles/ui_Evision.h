/********************************************************************************
** Form generated from reading UI file 'Evision.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVISION_H
#define UI_EVISION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
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
    QAction *action_4;
    QAction *action_5;
    QAction *actionDebug;
    QWidget *centralWidget;
    QGraphicsView *graphicsView_L;
    QGraphicsView *graphicsView_R;
    QGraphicsView *graphicsView_D;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_BoardHeight;
    QLineEdit *lineEdit_BoardWidth;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_SquareSize;
    QCheckBox *checkBox_showRectified;
    QRadioButton *radioButton_Hartley;
    QRadioButton *radioButton_Bouguet;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_CalibDefault;
    QGroupBox *groupBox_6;
    QLabel *label_36;
    QLabel *label_39;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_37;
    QLabel *label_41;
    QLabel *label_35;
    QLabel *label_40;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_MODE_HH;
    QRadioButton *radioButton_MODE_3WAY;
    QRadioButton *radioButton_MODE_SGBM;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_SGBM;
    QRadioButton *radioButton_BM;
    QSlider *horizontalSlider_uniradio;
    QLineEdit *lineEdit_uniradio;
    QSlider *horizontalSlider_prefilcap;
    QLineEdit *lineEdit_prefilcap;
    QSlider *horizontalSlider_specwinsz;
    QLineEdit *lineEdit_specwinsz;
    QSlider *horizontalSlider_SadWinSiz;
    QLineEdit *lineEdit_SadWinSiz;
    QSlider *horizontalSlider_MinDisp;
    QLineEdit *lineEdit_MinDisp;
    QSlider *horizontalSlider_textThread;
    QLineEdit *lineEdit_textThread;
    QSlider *horizontalSlider_NumDisparities;
    QLineEdit *lineEdit_NumDisparities;
    QSlider *horizontalSlider_specrange;
    QLineEdit *lineEdit_specrange;
    QSlider *horizontalSlider_maxdifdisp12;
    QLineEdit *lineEdit_maxdifdisp12;
    QFrame *line;
    QPushButton *pushButton_MatchDefault;
    QPushButton *pushButton_MatchChooseFiles;
    QFrame *line_2;
    QPushButton *pushButton_RefreshStereoMatch;
    QPushButton *pushButton_RangeSinglePoint;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EvisionClass)
    {
        if (EvisionClass->objectName().isEmpty())
            EvisionClass->setObjectName(QStringLiteral("EvisionClass"));
        EvisionClass->resize(1000, 580);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EvisionClass->sizePolicy().hasHeightForWidth());
        EvisionClass->setSizePolicy(sizePolicy);
        EvisionClass->setMinimumSize(QSize(1000, 580));
        EvisionClass->setMaximumSize(QSize(1000, 580));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Evision/resource/Evision.ico"), QSize(), QIcon::Normal, QIcon::Off);
        EvisionClass->setWindowIcon(icon);
        action_StereoCamera = new QAction(EvisionClass);
        action_StereoCamera->setObjectName(QStringLiteral("action_StereoCamera"));
        action_ShowPointCloud = new QAction(EvisionClass);
        action_ShowPointCloud->setObjectName(QStringLiteral("action_ShowPointCloud"));
        action_Camera = new QAction(EvisionClass);
        action_Camera->setObjectName(QStringLiteral("action_Camera"));
        action_4 = new QAction(EvisionClass);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(EvisionClass);
        action_5->setObjectName(QStringLiteral("action_5"));
        actionDebug = new QAction(EvisionClass);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        centralWidget = new QWidget(EvisionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView_L = new QGraphicsView(centralWidget);
        graphicsView_L->setObjectName(QStringLiteral("graphicsView_L"));
        graphicsView_L->setGeometry(QRect(10, 10, 320, 240));
        graphicsView_L->setContextMenuPolicy(Qt::ActionsContextMenu);
        graphicsView_L->setAutoFillBackground(false);
        graphicsView_L->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView_L->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView_L->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView_L->setBackgroundBrush(brush);
        graphicsView_R = new QGraphicsView(centralWidget);
        graphicsView_R->setObjectName(QStringLiteral("graphicsView_R"));
        graphicsView_R->setGeometry(QRect(340, 10, 320, 240));
        graphicsView_D = new QGraphicsView(centralWidget);
        graphicsView_D->setObjectName(QStringLiteral("graphicsView_D"));
        graphicsView_D->setGeometry(QRect(670, 10, 320, 240));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 260, 321, 181));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_BoardHeight = new QLineEdit(groupBox);
        lineEdit_BoardHeight->setObjectName(QStringLiteral("lineEdit_BoardHeight"));
        lineEdit_BoardHeight->setMinimumSize(QSize(50, 20));
        lineEdit_BoardHeight->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_BoardHeight, 1, 2, 1, 1);

        lineEdit_BoardWidth = new QLineEdit(groupBox);
        lineEdit_BoardWidth->setObjectName(QStringLiteral("lineEdit_BoardWidth"));
        lineEdit_BoardWidth->setMinimumSize(QSize(50, 20));
        lineEdit_BoardWidth->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_BoardWidth, 0, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_SquareSize = new QLineEdit(groupBox);
        lineEdit_SquareSize->setObjectName(QStringLiteral("lineEdit_SquareSize"));
        lineEdit_SquareSize->setMinimumSize(QSize(50, 20));
        lineEdit_SquareSize->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(lineEdit_SquareSize, 2, 2, 1, 1);

        checkBox_showRectified = new QCheckBox(groupBox);
        checkBox_showRectified->setObjectName(QStringLiteral("checkBox_showRectified"));

        gridLayout->addWidget(checkBox_showRectified, 3, 2, 1, 1);

        radioButton_Hartley = new QRadioButton(groupBox);
        radioButton_Hartley->setObjectName(QStringLiteral("radioButton_Hartley"));

        gridLayout->addWidget(radioButton_Hartley, 4, 2, 1, 1);

        radioButton_Bouguet = new QRadioButton(groupBox);
        radioButton_Bouguet->setObjectName(QStringLiteral("radioButton_Bouguet"));

        gridLayout->addWidget(radioButton_Bouguet, 5, 2, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 440, 321, 81));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_5->addWidget(pushButton, 4, 1, 1, 1);

        pushButton_CalibDefault = new QPushButton(groupBox_4);
        pushButton_CalibDefault->setObjectName(QStringLiteral("pushButton_CalibDefault"));

        gridLayout_5->addWidget(pushButton_CalibDefault, 0, 1, 1, 1);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(340, 260, 651, 261));
        label_36 = new QLabel(groupBox_6);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(20, 110, 316, 29));
        label_36->setMinimumSize(QSize(316, 29));
        label_36->setMaximumSize(QSize(316, 29));
        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(20, 70, 180, 16));
        label_42 = new QLabel(groupBox_6);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(340, 60, 228, 16));
        label_43 = new QLabel(groupBox_6);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(340, 100, 234, 16));
        label_44 = new QLabel(groupBox_6);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(340, 20, 168, 16));
        label_37 = new QLabel(groupBox_6);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(20, 160, 310, 29));
        label_37->setMinimumSize(QSize(310, 29));
        label_37->setMaximumSize(QSize(310, 29));
        label_41 = new QLabel(groupBox_6);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(20, 210, 161, 16));
        label_35 = new QLabel(groupBox_6);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(340, 140, 241, 16));
        label_40 = new QLabel(groupBox_6);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(20, 10, 316, 29));
        label_40->setMinimumSize(QSize(316, 29));
        label_40->setMaximumSize(QSize(316, 29));
        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(460, 180, 171, 48));
        horizontalLayout = new QHBoxLayout(groupBox_8);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_MODE_HH = new QRadioButton(groupBox_8);
        radioButton_MODE_HH->setObjectName(QStringLiteral("radioButton_MODE_HH"));

        horizontalLayout->addWidget(radioButton_MODE_HH);

        radioButton_MODE_3WAY = new QRadioButton(groupBox_8);
        radioButton_MODE_3WAY->setObjectName(QStringLiteral("radioButton_MODE_3WAY"));

        horizontalLayout->addWidget(radioButton_MODE_3WAY);

        radioButton_MODE_SGBM = new QRadioButton(groupBox_8);
        radioButton_MODE_SGBM->setObjectName(QStringLiteral("radioButton_MODE_SGBM"));

        horizontalLayout->addWidget(radioButton_MODE_SGBM);

        groupBox_9 = new QGroupBox(groupBox_6);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(340, 180, 108, 48));
        horizontalLayout_2 = new QHBoxLayout(groupBox_9);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton_SGBM = new QRadioButton(groupBox_9);
        radioButton_SGBM->setObjectName(QStringLiteral("radioButton_SGBM"));

        horizontalLayout_2->addWidget(radioButton_SGBM);

        radioButton_BM = new QRadioButton(groupBox_9);
        radioButton_BM->setObjectName(QStringLiteral("radioButton_BM"));

        horizontalLayout_2->addWidget(radioButton_BM);

        horizontalSlider_uniradio = new QSlider(groupBox_6);
        horizontalSlider_uniradio->setObjectName(QStringLiteral("horizontalSlider_uniradio"));
        horizontalSlider_uniradio->setGeometry(QRect(60, 40, 231, 20));
        horizontalSlider_uniradio->setMinimumSize(QSize(0, 20));
        horizontalSlider_uniradio->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_uniradio->setMaximum(50);
        horizontalSlider_uniradio->setOrientation(Qt::Horizontal);
        lineEdit_uniradio = new QLineEdit(groupBox_6);
        lineEdit_uniradio->setObjectName(QStringLiteral("lineEdit_uniradio"));
        lineEdit_uniradio->setGeometry(QRect(20, 40, 35, 20));
        lineEdit_uniradio->setMinimumSize(QSize(35, 20));
        lineEdit_uniradio->setMaximumSize(QSize(30, 20));
        lineEdit_uniradio->setReadOnly(true);
        horizontalSlider_prefilcap = new QSlider(groupBox_6);
        horizontalSlider_prefilcap->setObjectName(QStringLiteral("horizontalSlider_prefilcap"));
        horizontalSlider_prefilcap->setGeometry(QRect(60, 90, 231, 20));
        horizontalSlider_prefilcap->setMinimumSize(QSize(0, 20));
        horizontalSlider_prefilcap->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_prefilcap->setMinimum(1);
        horizontalSlider_prefilcap->setMaximum(100);
        horizontalSlider_prefilcap->setOrientation(Qt::Horizontal);
        lineEdit_prefilcap = new QLineEdit(groupBox_6);
        lineEdit_prefilcap->setObjectName(QStringLiteral("lineEdit_prefilcap"));
        lineEdit_prefilcap->setGeometry(QRect(20, 90, 35, 20));
        lineEdit_prefilcap->setMinimumSize(QSize(35, 20));
        lineEdit_prefilcap->setMaximumSize(QSize(30, 20));
        lineEdit_prefilcap->setReadOnly(true);
        horizontalSlider_specwinsz = new QSlider(groupBox_6);
        horizontalSlider_specwinsz->setObjectName(QStringLiteral("horizontalSlider_specwinsz"));
        horizontalSlider_specwinsz->setGeometry(QRect(60, 140, 231, 20));
        horizontalSlider_specwinsz->setMinimumSize(QSize(0, 20));
        horizontalSlider_specwinsz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specwinsz->setMaximum(200);
        horizontalSlider_specwinsz->setOrientation(Qt::Horizontal);
        lineEdit_specwinsz = new QLineEdit(groupBox_6);
        lineEdit_specwinsz->setObjectName(QStringLiteral("lineEdit_specwinsz"));
        lineEdit_specwinsz->setGeometry(QRect(20, 140, 35, 20));
        lineEdit_specwinsz->setMinimumSize(QSize(35, 20));
        lineEdit_specwinsz->setMaximumSize(QSize(30, 20));
        lineEdit_specwinsz->setReadOnly(true);
        horizontalSlider_SadWinSiz = new QSlider(groupBox_6);
        horizontalSlider_SadWinSiz->setObjectName(QStringLiteral("horizontalSlider_SadWinSiz"));
        horizontalSlider_SadWinSiz->setGeometry(QRect(60, 190, 231, 20));
        horizontalSlider_SadWinSiz->setMinimumSize(QSize(0, 20));
        horizontalSlider_SadWinSiz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_SadWinSiz->setMinimum(5);
        horizontalSlider_SadWinSiz->setMaximum(51);
        horizontalSlider_SadWinSiz->setSingleStep(2);
        horizontalSlider_SadWinSiz->setOrientation(Qt::Horizontal);
        lineEdit_SadWinSiz = new QLineEdit(groupBox_6);
        lineEdit_SadWinSiz->setObjectName(QStringLiteral("lineEdit_SadWinSiz"));
        lineEdit_SadWinSiz->setGeometry(QRect(20, 190, 35, 20));
        lineEdit_SadWinSiz->setMinimumSize(QSize(35, 20));
        lineEdit_SadWinSiz->setMaximumSize(QSize(30, 20));
        lineEdit_SadWinSiz->setReadOnly(true);
        horizontalSlider_MinDisp = new QSlider(groupBox_6);
        horizontalSlider_MinDisp->setObjectName(QStringLiteral("horizontalSlider_MinDisp"));
        horizontalSlider_MinDisp->setGeometry(QRect(60, 230, 231, 20));
        horizontalSlider_MinDisp->setMinimumSize(QSize(0, 20));
        horizontalSlider_MinDisp->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_MinDisp->setMinimum(-64);
        horizontalSlider_MinDisp->setMaximum(16);
        horizontalSlider_MinDisp->setOrientation(Qt::Horizontal);
        lineEdit_MinDisp = new QLineEdit(groupBox_6);
        lineEdit_MinDisp->setObjectName(QStringLiteral("lineEdit_MinDisp"));
        lineEdit_MinDisp->setGeometry(QRect(20, 230, 35, 20));
        lineEdit_MinDisp->setMinimumSize(QSize(35, 20));
        lineEdit_MinDisp->setMaximumSize(QSize(30, 20));
        lineEdit_MinDisp->setReadOnly(true);
        horizontalSlider_textThread = new QSlider(groupBox_6);
        horizontalSlider_textThread->setObjectName(QStringLiteral("horizontalSlider_textThread"));
        horizontalSlider_textThread->setGeometry(QRect(380, 160, 251, 20));
        horizontalSlider_textThread->setMinimumSize(QSize(0, 20));
        horizontalSlider_textThread->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_textThread->setMaximum(50);
        horizontalSlider_textThread->setOrientation(Qt::Horizontal);
        lineEdit_textThread = new QLineEdit(groupBox_6);
        lineEdit_textThread->setObjectName(QStringLiteral("lineEdit_textThread"));
        lineEdit_textThread->setGeometry(QRect(340, 160, 35, 20));
        lineEdit_textThread->setMinimumSize(QSize(35, 20));
        lineEdit_textThread->setMaximumSize(QSize(30, 20));
        lineEdit_textThread->setReadOnly(true);
        horizontalSlider_NumDisparities = new QSlider(groupBox_6);
        horizontalSlider_NumDisparities->setObjectName(QStringLiteral("horizontalSlider_NumDisparities"));
        horizontalSlider_NumDisparities->setGeometry(QRect(380, 40, 251, 20));
        horizontalSlider_NumDisparities->setMinimumSize(QSize(0, 20));
        horizontalSlider_NumDisparities->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_NumDisparities->setMinimum(16);
        horizontalSlider_NumDisparities->setMaximum(256);
        horizontalSlider_NumDisparities->setSingleStep(16);
        horizontalSlider_NumDisparities->setOrientation(Qt::Horizontal);
        lineEdit_NumDisparities = new QLineEdit(groupBox_6);
        lineEdit_NumDisparities->setObjectName(QStringLiteral("lineEdit_NumDisparities"));
        lineEdit_NumDisparities->setGeometry(QRect(340, 40, 35, 20));
        lineEdit_NumDisparities->setMinimumSize(QSize(35, 20));
        lineEdit_NumDisparities->setMaximumSize(QSize(30, 20));
        lineEdit_NumDisparities->setReadOnly(true);
        horizontalSlider_specrange = new QSlider(groupBox_6);
        horizontalSlider_specrange->setObjectName(QStringLiteral("horizontalSlider_specrange"));
        horizontalSlider_specrange->setGeometry(QRect(380, 80, 251, 20));
        horizontalSlider_specrange->setMinimumSize(QSize(0, 20));
        horizontalSlider_specrange->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specrange->setMaximum(64);
        horizontalSlider_specrange->setOrientation(Qt::Horizontal);
        lineEdit_specrange = new QLineEdit(groupBox_6);
        lineEdit_specrange->setObjectName(QStringLiteral("lineEdit_specrange"));
        lineEdit_specrange->setGeometry(QRect(340, 80, 35, 20));
        lineEdit_specrange->setMinimumSize(QSize(35, 20));
        lineEdit_specrange->setMaximumSize(QSize(30, 20));
        lineEdit_specrange->setReadOnly(true);
        horizontalSlider_maxdifdisp12 = new QSlider(groupBox_6);
        horizontalSlider_maxdifdisp12->setObjectName(QStringLiteral("horizontalSlider_maxdifdisp12"));
        horizontalSlider_maxdifdisp12->setGeometry(QRect(380, 120, 251, 20));
        horizontalSlider_maxdifdisp12->setMinimumSize(QSize(0, 20));
        horizontalSlider_maxdifdisp12->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_maxdifdisp12->setMinimum(-1);
        horizontalSlider_maxdifdisp12->setMaximum(5);
        horizontalSlider_maxdifdisp12->setOrientation(Qt::Horizontal);
        lineEdit_maxdifdisp12 = new QLineEdit(groupBox_6);
        lineEdit_maxdifdisp12->setObjectName(QStringLiteral("lineEdit_maxdifdisp12"));
        lineEdit_maxdifdisp12->setGeometry(QRect(340, 120, 35, 20));
        lineEdit_maxdifdisp12->setMinimumSize(QSize(35, 20));
        lineEdit_maxdifdisp12->setMaximumSize(QSize(30, 20));
        lineEdit_maxdifdisp12->setReadOnly(true);
        line = new QFrame(groupBox_6);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(310, 20, 20, 231));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_MatchDefault = new QPushButton(groupBox_6);
        pushButton_MatchDefault->setObjectName(QStringLiteral("pushButton_MatchDefault"));
        pushButton_MatchDefault->setGeometry(QRect(340, 230, 71, 23));
        pushButton_MatchDefault->setMinimumSize(QSize(0, 20));
        pushButton_MatchChooseFiles = new QPushButton(groupBox_6);
        pushButton_MatchChooseFiles->setObjectName(QStringLiteral("pushButton_MatchChooseFiles"));
        pushButton_MatchChooseFiles->setGeometry(QRect(420, 230, 71, 23));
        pushButton_MatchChooseFiles->setMinimumSize(QSize(0, 20));
        line_2 = new QFrame(groupBox_6);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(320, 20, 20, 231));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton_RefreshStereoMatch = new QPushButton(groupBox_6);
        pushButton_RefreshStereoMatch->setObjectName(QStringLiteral("pushButton_RefreshStereoMatch"));
        pushButton_RefreshStereoMatch->setGeometry(QRect(500, 230, 61, 23));
        pushButton_RangeSinglePoint = new QPushButton(groupBox_6);
        pushButton_RangeSinglePoint->setObjectName(QStringLiteral("pushButton_RangeSinglePoint"));
        pushButton_RangeSinglePoint->setGeometry(QRect(570, 230, 71, 23));
        EvisionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EvisionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        EvisionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EvisionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EvisionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EvisionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EvisionClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_StereoCamera);
        menu->addAction(action_Camera);
        menu->addAction(action_ShowPointCloud);
        menu->addAction(actionDebug);
        menu_2->addAction(action_4);
        menu_2->addAction(action_5);

        retranslateUi(EvisionClass);
        QObject::connect(pushButton_CalibDefault, SIGNAL(clicked()), EvisionClass, SLOT(setDefaultCalibParam()));
        QObject::connect(pushButton, SIGNAL(clicked()), EvisionClass, SLOT(doCalib()));
        QObject::connect(pushButton_MatchDefault, SIGNAL(clicked()), EvisionClass, SLOT(setDefaultMatchParam()));
        QObject::connect(pushButton_MatchChooseFiles, SIGNAL(clicked()), EvisionClass, SLOT(doMatch()));
        QObject::connect(pushButton_RangeSinglePoint, SIGNAL(clicked()), EvisionClass, SLOT(getDistance()));
        QObject::connect(lineEdit_BoardWidth, SIGNAL(textChanged(QString)), EvisionClass, SLOT(onValueChanged_BoardWidth(QString)));
        QObject::connect(lineEdit_BoardHeight, SIGNAL(textChanged(QString)), EvisionClass, SLOT(onValueChanged_BoardHeight(QString)));
        QObject::connect(lineEdit_SquareSize, SIGNAL(textChanged(QString)), EvisionClass, SLOT(onValueChanged_SquareSize(QString)));
        QObject::connect(checkBox_showRectified, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_FPP(bool)));
        QObject::connect(radioButton_Bouguet, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_Bouguet(bool)));
        QObject::connect(radioButton_Hartley, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_Hartley(bool)));
        QObject::connect(horizontalSlider_MinDisp, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_MinDisp(int)));
        QObject::connect(horizontalSlider_uniradio, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_uniradio(int)));
        QObject::connect(horizontalSlider_specwinsz, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_specwinsz(int)));
        QObject::connect(horizontalSlider_NumDisparities, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_NumDisparities(int)));
        QObject::connect(horizontalSlider_specrange, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_Specrange(int)));
        QObject::connect(horizontalSlider_prefilcap, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_Prefilcap(int)));
        QObject::connect(horizontalSlider_SadWinSiz, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_SadWinSize(int)));
        QObject::connect(horizontalSlider_textThread, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_TextThread(int)));
        QObject::connect(horizontalSlider_maxdifdisp12, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_MaxDifdisp2(int)));
        QObject::connect(radioButton_BM, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_BM(bool)));
        QObject::connect(radioButton_SGBM, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_SGBM(bool)));
        QObject::connect(radioButton_MODE_HH, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_MODE_HH(bool)));
        QObject::connect(actionDebug, SIGNAL(triggered()), EvisionClass, SLOT(onTestAlltheParam()));
        QObject::connect(radioButton_MODE_SGBM, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_MODE_SGBM(bool)));
        QObject::connect(radioButton_MODE_3WAY, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_MODE_3WAY(bool)));
        QObject::connect(pushButton_RefreshStereoMatch, SIGNAL(clicked()), EvisionClass, SLOT(RefreshStereoMatch()));
        QObject::connect(action_ShowPointCloud, SIGNAL(triggered()), EvisionClass, SLOT(onShowPointCloud()));
        QObject::connect(action_StereoCamera, SIGNAL(triggered()), EvisionClass, SLOT(onStereoCamera()));
        QObject::connect(action_Camera, SIGNAL(triggered()), EvisionClass, SLOT(onCamera()));

        QMetaObject::connectSlotsByName(EvisionClass);
    } // setupUi

    void retranslateUi(QMainWindow *EvisionClass)
    {
        EvisionClass->setWindowTitle(QApplication::translate("EvisionClass", "Evision", nullptr));
        action_StereoCamera->setText(QApplication::translate("EvisionClass", "\346\213\215\346\221\204\345\217\214\351\225\234\345\244\264\347\205\247\347\211\207", nullptr));
        action_ShowPointCloud->setText(QApplication::translate("EvisionClass", "\346\230\276\347\244\272\347\202\271\344\272\221", nullptr));
        action_Camera->setText(QApplication::translate("EvisionClass", "\346\213\215\346\221\204\345\215\225\351\225\234\345\244\264\347\205\247\347\211\207", nullptr));
        action_4->setText(QApplication::translate("EvisionClass", "\345\270\256\345\212\251\344\277\241\346\201\257", nullptr));
        action_5->setText(QApplication::translate("EvisionClass", "\345\205\263\344\272\216", nullptr));
        actionDebug->setText(QApplication::translate("EvisionClass", "Debug", nullptr));
        groupBox->setTitle(QApplication::translate("EvisionClass", "\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        label_8->setText(QApplication::translate("EvisionClass", "Size:", nullptr));
        label_5->setText(QApplication::translate("EvisionClass", "Width:", nullptr));
        label_6->setText(QApplication::translate("EvisionClass", "Height:", nullptr));
        checkBox_showRectified->setText(QApplication::translate("EvisionClass", "\346\230\276\347\244\272\347\237\253\346\255\243\347\273\223\346\236\234(By OpenCV NamedWindow)", nullptr));
        radioButton_Hartley->setText(QApplication::translate("EvisionClass", "\344\275\277\347\224\250Hartley\347\237\253\346\255\243\346\226\271\346\263\225", nullptr));
        radioButton_Bouguet->setText(QApplication::translate("EvisionClass", "\344\275\277\347\224\250Bouguet\347\237\253\346\255\243\346\226\271\346\263\225", nullptr));
        groupBox_4->setTitle(QApplication::translate("EvisionClass", "\346\240\207\345\256\232", nullptr));
        pushButton->setText(QApplication::translate("EvisionClass", "\346\240\207\345\256\232", nullptr));
        pushButton_CalibDefault->setText(QApplication::translate("EvisionClass", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        groupBox_6->setTitle(QApplication::translate("EvisionClass", "\345\214\271\351\205\215\345\217\202\346\225\260", nullptr));
        label_36->setText(QApplication::translate("EvisionClass", "SpeckleWindowSize(\350\247\206\345\267\256\350\277\236\351\200\232\345\214\272\345\237\237\345\217\230\345\214\226\345\272\246\347\232\204\347\252\227\345\217\243\345\244\247\345\260\217)", nullptr));
        label_39->setText(QApplication::translate("EvisionClass", "preFilterCap(\345\211\215\347\275\256\346\273\244\346\263\242\345\231\250\346\210\252\346\226\255\345\200\274)", nullptr));
        label_42->setText(QApplication::translate("EvisionClass", "speckleRange(\350\277\236\351\200\232\345\214\272\345\237\237\345\206\205\347\232\204\346\234\200\345\244\247\350\247\206\345\267\256\345\217\230\345\214\226)", nullptr));
        label_43->setText(QApplication::translate("EvisionClass", "disp12MaxDiff(\345\267\246\345\217\263\350\247\206\345\267\256\345\233\276\347\232\204\346\234\200\345\244\247\345\256\271\350\256\270\345\267\256\345\274\202)", nullptr));
        label_44->setText(QApplication::translate("EvisionClass", "numDisparities(\350\247\206\345\267\256\347\252\227\345\217\243\345\244\247\345\260\217)", nullptr));
        label_37->setText(QApplication::translate("EvisionClass", "SADWindowSize(SAD\347\252\227\345\217\243\345\244\247\345\260\217)", nullptr));
        label_41->setText(QApplication::translate("EvisionClass", "minDisparity(\346\234\200\345\260\217\350\247\206\345\267\256\345\200\274)", nullptr));
        label_35->setText(QApplication::translate("EvisionClass", "TextureThreshold(\344\275\216\347\272\271\347\220\206\345\214\272\345\237\237\347\232\204\345\210\244\346\226\255\351\230\210\345\200\274)", nullptr));
        label_40->setText(QApplication::translate("EvisionClass", "uniquenessRatio(\350\247\206\345\267\256\345\224\257\344\270\200\346\200\247\347\231\276\345\210\206\346\257\224)", nullptr));
        groupBox_8->setTitle(QApplication::translate("EvisionClass", "MODE", nullptr));
        radioButton_MODE_HH->setText(QApplication::translate("EvisionClass", "HH", nullptr));
        radioButton_MODE_3WAY->setText(QApplication::translate("EvisionClass", "3WAY", nullptr));
        radioButton_MODE_SGBM->setText(QApplication::translate("EvisionClass", "SGBM", nullptr));
        groupBox_9->setTitle(QApplication::translate("EvisionClass", "Function", nullptr));
        radioButton_SGBM->setText(QApplication::translate("EvisionClass", "SGBM", nullptr));
        radioButton_BM->setText(QApplication::translate("EvisionClass", "BM", nullptr));
        lineEdit_uniradio->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_prefilcap->setPlaceholderText(QApplication::translate("EvisionClass", "1", nullptr));
        lineEdit_specwinsz->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_SadWinSiz->setPlaceholderText(QApplication::translate("EvisionClass", "5", nullptr));
        lineEdit_MinDisp->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_textThread->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_NumDisparities->setPlaceholderText(QApplication::translate("EvisionClass", "16", nullptr));
        lineEdit_specrange->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_maxdifdisp12->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        pushButton_MatchDefault->setText(QApplication::translate("EvisionClass", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        pushButton_MatchChooseFiles->setText(QApplication::translate("EvisionClass", "\345\217\214\347\233\256\345\214\271\351\205\215", nullptr));
        pushButton_RefreshStereoMatch->setText(QApplication::translate("EvisionClass", "\345\210\267\346\226\260", nullptr));
        pushButton_RangeSinglePoint->setText(QApplication::translate("EvisionClass", "\346\265\213\351\207\217", nullptr));
        menu->setTitle(QApplication::translate("EvisionClass", "\345\267\245\345\205\267", nullptr));
        menu_2->setTitle(QApplication::translate("EvisionClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EvisionClass: public Ui_EvisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVISION_H
