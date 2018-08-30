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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *actionDebug;
    QWidget *centralWidget;
    QGraphicsView *graphicsView_L;
    QGraphicsView *graphicsView_R;
    QGraphicsView *graphicsView_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_BoardWidth;
    QCheckBox *checkBox_showRectified;
    QLabel *label_6;
    QLineEdit *lineEdit_SquareSize;
    QLineEdit *lineEdit_BoardHeight;
    QLabel *label_8;
    QRadioButton *radioButton_Hartley;
    QRadioButton *radioButton_Bouguet;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSlider *horizontalSlider_PolyN;
    QLabel *label_20;
    QLabel *label_26;
    QLineEdit *lineEdit_uniradio;
    QLineEdit *lineEdit_specwinsz;
    QLineEdit *lineEdit_MinDisp;
    QLineEdit *lineEdit_PolySigma;
    QSlider *horizontalSlider_uniradio;
    QLineEdit *lineEdit_PolyN;
    QLineEdit *lineEdit_textThread;
    QLineEdit *lineEdit_MaxDisp;
    QSlider *horizontalSlider_prefilcap;
    QSlider *horizontalSlider_Fi;
    QLineEdit *lineEdit_specrange;
    QLabel *label_24;
    QLabel *label_30;
    QLineEdit *lineEdit_SadWinSiz;
    QSlider *horizontalSlider_MinDisp;
    QSlider *horizontalSlider_MaxDisp;
    QSlider *horizontalSlider_specrange;
    QLabel *label_32;
    QLineEdit *lineEdit_maxdifdisp12;
    QLineEdit *lineEdit_Fi;
    QLabel *label_22;
    QSlider *horizontalSlider_textThread;
    QLabel *label_31;
    QLabel *label_27;
    QSlider *horizontalSlider_specwinsz;
    QSlider *horizontalSlider_Lambda;
    QLabel *label_25;
    QLabel *label_29;
    QLabel *label_34;
    QLabel *label_21;
    QLabel *label_33;
    QLineEdit *lineEdit_prefilcap;
    QSlider *horizontalSlider_SadWinSiz;
    QLineEdit *lineEdit_Levels;
    QLabel *label_23;
    QLabel *label_28;
    QSlider *horizontalSlider_maxdifdisp12;
    QLineEdit *lineEdit_Lambda;
    QSlider *horizontalSlider_PolySigma;
    QLineEdit *lineEdit_pyrScale;
    QSlider *horizontalSlider_Levels;
    QSlider *horizontalSlider_pyrScale;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_RangeSinglePoint;
    QPushButton *pushButton_RangeDualPoint;
    QLabel *label_38;
    QLineEdit *lineEdit_Result;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_BM;
    QRadioButton *radioButton_VAR;
    QPushButton *pushButton_MatchDefault;
    QPushButton *pushButton_MatchChooseFiles;
    QRadioButton *radioButton_SGBM;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QPushButton *pushButton_CalibDefault;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EvisionClass)
    {
        if (EvisionClass->objectName().isEmpty())
            EvisionClass->setObjectName(QStringLiteral("EvisionClass"));
        EvisionClass->resize(1000, 590);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EvisionClass->sizePolicy().hasHeightForWidth());
        EvisionClass->setSizePolicy(sizePolicy);
        EvisionClass->setMinimumSize(QSize(1000, 590));
        EvisionClass->setMaximumSize(QSize(1000, 590));
        action = new QAction(EvisionClass);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(EvisionClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_3 = new QAction(EvisionClass);
        action_3->setObjectName(QStringLiteral("action_3"));
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
        graphicsView_3 = new QGraphicsView(centralWidget);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(670, 10, 320, 240));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 260, 321, 161));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_BoardWidth = new QLineEdit(groupBox);
        lineEdit_BoardWidth->setObjectName(QStringLiteral("lineEdit_BoardWidth"));
        lineEdit_BoardWidth->setMinimumSize(QSize(50, 20));
        lineEdit_BoardWidth->setMaximumSize(QSize(50, 20));

        gridLayout->addWidget(lineEdit_BoardWidth, 0, 1, 1, 1);

        checkBox_showRectified = new QCheckBox(groupBox);
        checkBox_showRectified->setObjectName(QStringLiteral("checkBox_showRectified"));

        gridLayout->addWidget(checkBox_showRectified, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_SquareSize = new QLineEdit(groupBox);
        lineEdit_SquareSize->setObjectName(QStringLiteral("lineEdit_SquareSize"));
        lineEdit_SquareSize->setMinimumSize(QSize(50, 20));
        lineEdit_SquareSize->setMaximumSize(QSize(50, 20));

        gridLayout->addWidget(lineEdit_SquareSize, 2, 1, 1, 1);

        lineEdit_BoardHeight = new QLineEdit(groupBox);
        lineEdit_BoardHeight->setObjectName(QStringLiteral("lineEdit_BoardHeight"));
        lineEdit_BoardHeight->setMinimumSize(QSize(50, 20));
        lineEdit_BoardHeight->setMaximumSize(QSize(50, 20));

        gridLayout->addWidget(lineEdit_BoardHeight, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        radioButton_Hartley = new QRadioButton(groupBox);
        radioButton_Hartley->setObjectName(QStringLiteral("radioButton_Hartley"));

        gridLayout->addWidget(radioButton_Hartley, 2, 2, 1, 1);

        radioButton_Bouguet = new QRadioButton(groupBox);
        radioButton_Bouguet->setObjectName(QStringLiteral("radioButton_Bouguet"));

        gridLayout->addWidget(radioButton_Bouguet, 1, 2, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(340, 260, 401, 261));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSlider_PolyN = new QSlider(groupBox_2);
        horizontalSlider_PolyN->setObjectName(QStringLiteral("horizontalSlider_PolyN"));
        horizontalSlider_PolyN->setMinimumSize(QSize(0, 15));
        horizontalSlider_PolyN->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_PolyN->setMinimum(3);
        horizontalSlider_PolyN->setMaximum(61);
        horizontalSlider_PolyN->setSingleStep(2);
        horizontalSlider_PolyN->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_PolyN, 8, 4, 1, 2);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_2->addWidget(label_20, 0, 0, 1, 1);

        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_2->addWidget(label_26, 2, 2, 1, 1);

        lineEdit_uniradio = new QLineEdit(groupBox_2);
        lineEdit_uniradio->setObjectName(QStringLiteral("lineEdit_uniradio"));
        lineEdit_uniradio->setMinimumSize(QSize(35, 20));
        lineEdit_uniradio->setMaximumSize(QSize(30, 20));
        lineEdit_uniradio->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_uniradio, 0, 3, 1, 1);

        lineEdit_specwinsz = new QLineEdit(groupBox_2);
        lineEdit_specwinsz->setObjectName(QStringLiteral("lineEdit_specwinsz"));
        lineEdit_specwinsz->setMinimumSize(QSize(35, 20));
        lineEdit_specwinsz->setMaximumSize(QSize(30, 20));
        lineEdit_specwinsz->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_specwinsz, 0, 5, 1, 1);

        lineEdit_MinDisp = new QLineEdit(groupBox_2);
        lineEdit_MinDisp->setObjectName(QStringLiteral("lineEdit_MinDisp"));
        lineEdit_MinDisp->setMinimumSize(QSize(35, 20));
        lineEdit_MinDisp->setMaximumSize(QSize(30, 20));
        lineEdit_MinDisp->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_MinDisp, 0, 1, 1, 1);

        lineEdit_PolySigma = new QLineEdit(groupBox_2);
        lineEdit_PolySigma->setObjectName(QStringLiteral("lineEdit_PolySigma"));
        lineEdit_PolySigma->setMinimumSize(QSize(35, 20));
        lineEdit_PolySigma->setMaximumSize(QSize(30, 20));
        lineEdit_PolySigma->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_PolySigma, 11, 1, 1, 1);

        horizontalSlider_uniradio = new QSlider(groupBox_2);
        horizontalSlider_uniradio->setObjectName(QStringLiteral("horizontalSlider_uniradio"));
        horizontalSlider_uniradio->setMinimumSize(QSize(0, 15));
        horizontalSlider_uniradio->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_uniradio->setMaximum(50);
        horizontalSlider_uniradio->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_uniradio, 1, 2, 1, 2);

        lineEdit_PolyN = new QLineEdit(groupBox_2);
        lineEdit_PolyN->setObjectName(QStringLiteral("lineEdit_PolyN"));
        lineEdit_PolyN->setMinimumSize(QSize(35, 20));
        lineEdit_PolyN->setMaximumSize(QSize(30, 20));
        lineEdit_PolyN->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_PolyN, 6, 5, 1, 1);

        lineEdit_textThread = new QLineEdit(groupBox_2);
        lineEdit_textThread->setObjectName(QStringLiteral("lineEdit_textThread"));
        lineEdit_textThread->setMinimumSize(QSize(35, 20));
        lineEdit_textThread->setMaximumSize(QSize(30, 20));
        lineEdit_textThread->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_textThread, 4, 3, 1, 1);

        lineEdit_MaxDisp = new QLineEdit(groupBox_2);
        lineEdit_MaxDisp->setObjectName(QStringLiteral("lineEdit_MaxDisp"));
        lineEdit_MaxDisp->setMinimumSize(QSize(35, 20));
        lineEdit_MaxDisp->setMaximumSize(QSize(30, 20));
        lineEdit_MaxDisp->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_MaxDisp, 2, 1, 1, 1);

        horizontalSlider_prefilcap = new QSlider(groupBox_2);
        horizontalSlider_prefilcap->setObjectName(QStringLiteral("horizontalSlider_prefilcap"));
        horizontalSlider_prefilcap->setMinimumSize(QSize(0, 15));
        horizontalSlider_prefilcap->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_prefilcap->setMinimum(1);
        horizontalSlider_prefilcap->setMaximum(100);
        horizontalSlider_prefilcap->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_prefilcap, 3, 4, 1, 2);

        horizontalSlider_Fi = new QSlider(groupBox_2);
        horizontalSlider_Fi->setObjectName(QStringLiteral("horizontalSlider_Fi"));
        horizontalSlider_Fi->setMinimumSize(QSize(0, 15));
        horizontalSlider_Fi->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Fi->setMaximum(900);
        horizontalSlider_Fi->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Fi, 12, 2, 1, 2);

        lineEdit_specrange = new QLineEdit(groupBox_2);
        lineEdit_specrange->setObjectName(QStringLiteral("lineEdit_specrange"));
        lineEdit_specrange->setMinimumSize(QSize(35, 20));
        lineEdit_specrange->setMaximumSize(QSize(30, 20));
        lineEdit_specrange->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_specrange, 2, 3, 1, 1);

        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_2->addWidget(label_24, 11, 0, 1, 1);

        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_2->addWidget(label_30, 0, 4, 1, 1);

        lineEdit_SadWinSiz = new QLineEdit(groupBox_2);
        lineEdit_SadWinSiz->setObjectName(QStringLiteral("lineEdit_SadWinSiz"));
        lineEdit_SadWinSiz->setMinimumSize(QSize(35, 20));
        lineEdit_SadWinSiz->setMaximumSize(QSize(30, 20));
        lineEdit_SadWinSiz->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_SadWinSiz, 4, 1, 1, 1);

        horizontalSlider_MinDisp = new QSlider(groupBox_2);
        horizontalSlider_MinDisp->setObjectName(QStringLiteral("horizontalSlider_MinDisp"));
        horizontalSlider_MinDisp->setMinimumSize(QSize(0, 15));
        horizontalSlider_MinDisp->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_MinDisp->setMinimum(-64);
        horizontalSlider_MinDisp->setMaximum(16);
        horizontalSlider_MinDisp->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_MinDisp, 1, 0, 1, 2);

        horizontalSlider_MaxDisp = new QSlider(groupBox_2);
        horizontalSlider_MaxDisp->setObjectName(QStringLiteral("horizontalSlider_MaxDisp"));
        horizontalSlider_MaxDisp->setMinimumSize(QSize(0, 15));
        horizontalSlider_MaxDisp->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_MaxDisp->setMinimum(16);
        horizontalSlider_MaxDisp->setMaximum(256);
        horizontalSlider_MaxDisp->setSingleStep(16);
        horizontalSlider_MaxDisp->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_MaxDisp, 3, 0, 1, 2);

        horizontalSlider_specrange = new QSlider(groupBox_2);
        horizontalSlider_specrange->setObjectName(QStringLiteral("horizontalSlider_specrange"));
        horizontalSlider_specrange->setMinimumSize(QSize(0, 15));
        horizontalSlider_specrange->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specrange->setMaximum(64);
        horizontalSlider_specrange->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_specrange, 3, 2, 1, 2);

        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_2->addWidget(label_32, 4, 4, 1, 1);

        lineEdit_maxdifdisp12 = new QLineEdit(groupBox_2);
        lineEdit_maxdifdisp12->setObjectName(QStringLiteral("lineEdit_maxdifdisp12"));
        lineEdit_maxdifdisp12->setMinimumSize(QSize(35, 20));
        lineEdit_maxdifdisp12->setMaximumSize(QSize(30, 20));
        lineEdit_maxdifdisp12->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_maxdifdisp12, 4, 5, 1, 1);

        lineEdit_Fi = new QLineEdit(groupBox_2);
        lineEdit_Fi->setObjectName(QStringLiteral("lineEdit_Fi"));
        lineEdit_Fi->setMinimumSize(QSize(35, 20));
        lineEdit_Fi->setMaximumSize(QSize(30, 20));
        lineEdit_Fi->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Fi, 11, 3, 1, 1);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_2->addWidget(label_22, 4, 0, 1, 1);

        horizontalSlider_textThread = new QSlider(groupBox_2);
        horizontalSlider_textThread->setObjectName(QStringLiteral("horizontalSlider_textThread"));
        horizontalSlider_textThread->setMinimumSize(QSize(0, 15));
        horizontalSlider_textThread->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_textThread->setMaximum(50);
        horizontalSlider_textThread->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_textThread, 5, 2, 1, 2);

        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_2->addWidget(label_31, 2, 4, 1, 1);

        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_2->addWidget(label_27, 4, 2, 1, 1);

        horizontalSlider_specwinsz = new QSlider(groupBox_2);
        horizontalSlider_specwinsz->setObjectName(QStringLiteral("horizontalSlider_specwinsz"));
        horizontalSlider_specwinsz->setMinimumSize(QSize(0, 15));
        horizontalSlider_specwinsz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specwinsz->setMaximum(200);
        horizontalSlider_specwinsz->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_specwinsz, 1, 4, 1, 2);

        horizontalSlider_Lambda = new QSlider(groupBox_2);
        horizontalSlider_Lambda->setObjectName(QStringLiteral("horizontalSlider_Lambda"));
        horizontalSlider_Lambda->setMinimumSize(QSize(0, 15));
        horizontalSlider_Lambda->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Lambda->setMaximum(100);
        horizontalSlider_Lambda->setSingleStep(1);
        horizontalSlider_Lambda->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Lambda, 12, 4, 1, 2);

        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_2->addWidget(label_25, 0, 2, 1, 1);

        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_2->addWidget(label_29, 11, 2, 1, 1);

        label_34 = new QLabel(groupBox_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_2->addWidget(label_34, 11, 4, 1, 1);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_2->addWidget(label_21, 2, 0, 1, 1);

        label_33 = new QLabel(groupBox_2);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_2->addWidget(label_33, 6, 4, 1, 1);

        lineEdit_prefilcap = new QLineEdit(groupBox_2);
        lineEdit_prefilcap->setObjectName(QStringLiteral("lineEdit_prefilcap"));
        lineEdit_prefilcap->setMinimumSize(QSize(35, 20));
        lineEdit_prefilcap->setMaximumSize(QSize(30, 20));
        lineEdit_prefilcap->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_prefilcap, 2, 5, 1, 1);

        horizontalSlider_SadWinSiz = new QSlider(groupBox_2);
        horizontalSlider_SadWinSiz->setObjectName(QStringLiteral("horizontalSlider_SadWinSiz"));
        horizontalSlider_SadWinSiz->setMinimumSize(QSize(0, 15));
        horizontalSlider_SadWinSiz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_SadWinSiz->setMinimum(5);
        horizontalSlider_SadWinSiz->setMaximum(51);
        horizontalSlider_SadWinSiz->setSingleStep(2);
        horizontalSlider_SadWinSiz->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_SadWinSiz, 5, 0, 1, 2);

        lineEdit_Levels = new QLineEdit(groupBox_2);
        lineEdit_Levels->setObjectName(QStringLiteral("lineEdit_Levels"));
        lineEdit_Levels->setMinimumSize(QSize(35, 20));
        lineEdit_Levels->setMaximumSize(QSize(30, 20));
        lineEdit_Levels->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Levels, 6, 1, 1, 1);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 6, 0, 1, 1);

        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_2->addWidget(label_28, 6, 2, 1, 1);

        horizontalSlider_maxdifdisp12 = new QSlider(groupBox_2);
        horizontalSlider_maxdifdisp12->setObjectName(QStringLiteral("horizontalSlider_maxdifdisp12"));
        horizontalSlider_maxdifdisp12->setMinimumSize(QSize(0, 15));
        horizontalSlider_maxdifdisp12->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_maxdifdisp12->setMinimum(-1);
        horizontalSlider_maxdifdisp12->setMaximum(5);
        horizontalSlider_maxdifdisp12->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_maxdifdisp12, 5, 4, 1, 2);

        lineEdit_Lambda = new QLineEdit(groupBox_2);
        lineEdit_Lambda->setObjectName(QStringLiteral("lineEdit_Lambda"));
        lineEdit_Lambda->setMinimumSize(QSize(35, 20));
        lineEdit_Lambda->setMaximumSize(QSize(30, 20));
        lineEdit_Lambda->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_Lambda, 11, 5, 1, 1);

        horizontalSlider_PolySigma = new QSlider(groupBox_2);
        horizontalSlider_PolySigma->setObjectName(QStringLiteral("horizontalSlider_PolySigma"));
        horizontalSlider_PolySigma->setMinimumSize(QSize(0, 15));
        horizontalSlider_PolySigma->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_PolySigma->setMaximum(1000);
        horizontalSlider_PolySigma->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_PolySigma, 12, 0, 1, 2);

        lineEdit_pyrScale = new QLineEdit(groupBox_2);
        lineEdit_pyrScale->setObjectName(QStringLiteral("lineEdit_pyrScale"));
        lineEdit_pyrScale->setMinimumSize(QSize(35, 20));
        lineEdit_pyrScale->setMaximumSize(QSize(30, 20));
        lineEdit_pyrScale->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_pyrScale, 6, 3, 1, 1);

        horizontalSlider_Levels = new QSlider(groupBox_2);
        horizontalSlider_Levels->setObjectName(QStringLiteral("horizontalSlider_Levels"));
        horizontalSlider_Levels->setMinimumSize(QSize(0, 15));
        horizontalSlider_Levels->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Levels->setMinimum(1);
        horizontalSlider_Levels->setMaximum(10);
        horizontalSlider_Levels->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_Levels, 8, 0, 1, 2);

        horizontalSlider_pyrScale = new QSlider(groupBox_2);
        horizontalSlider_pyrScale->setObjectName(QStringLiteral("horizontalSlider_pyrScale"));
        horizontalSlider_pyrScale->setMinimumSize(QSize(0, 15));
        horizontalSlider_pyrScale->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_pyrScale->setMinimum(1);
        horizontalSlider_pyrScale->setMaximum(10);
        horizontalSlider_pyrScale->setSingleStep(1);
        horizontalSlider_pyrScale->setValue(1);
        horizontalSlider_pyrScale->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_pyrScale, 8, 2, 1, 2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(750, 399, 232, 121));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_RangeSinglePoint = new QPushButton(groupBox_3);
        pushButton_RangeSinglePoint->setObjectName(QStringLiteral("pushButton_RangeSinglePoint"));

        gridLayout_3->addWidget(pushButton_RangeSinglePoint, 0, 1, 1, 1);

        pushButton_RangeDualPoint = new QPushButton(groupBox_3);
        pushButton_RangeDualPoint->setObjectName(QStringLiteral("pushButton_RangeDualPoint"));

        gridLayout_3->addWidget(pushButton_RangeDualPoint, 1, 1, 1, 1);

        label_38 = new QLabel(groupBox_3);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout_3->addWidget(label_38, 2, 0, 1, 1);

        lineEdit_Result = new QLineEdit(groupBox_3);
        lineEdit_Result->setObjectName(QStringLiteral("lineEdit_Result"));
        lineEdit_Result->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit_Result, 2, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(750, 260, 231, 131));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        radioButton_BM = new QRadioButton(groupBox_5);
        radioButton_BM->setObjectName(QStringLiteral("radioButton_BM"));

        gridLayout_4->addWidget(radioButton_BM, 0, 0, 1, 1);

        radioButton_VAR = new QRadioButton(groupBox_5);
        radioButton_VAR->setObjectName(QStringLiteral("radioButton_VAR"));

        gridLayout_4->addWidget(radioButton_VAR, 4, 0, 1, 1);

        pushButton_MatchDefault = new QPushButton(groupBox_5);
        pushButton_MatchDefault->setObjectName(QStringLiteral("pushButton_MatchDefault"));
        pushButton_MatchDefault->setMinimumSize(QSize(0, 20));

        gridLayout_4->addWidget(pushButton_MatchDefault, 0, 1, 1, 1);

        pushButton_MatchChooseFiles = new QPushButton(groupBox_5);
        pushButton_MatchChooseFiles->setObjectName(QStringLiteral("pushButton_MatchChooseFiles"));
        pushButton_MatchChooseFiles->setMinimumSize(QSize(0, 20));

        gridLayout_4->addWidget(pushButton_MatchChooseFiles, 1, 1, 1, 1);

        radioButton_SGBM = new QRadioButton(groupBox_5);
        radioButton_SGBM->setObjectName(QStringLiteral("radioButton_SGBM"));

        gridLayout_4->addWidget(radioButton_SGBM, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 430, 321, 91));
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
        menu->addAction(action);
        menu->addAction(action_3);
        menu->addAction(action_2);
        menu->addAction(actionDebug);
        menu_2->addAction(action_4);
        menu_2->addAction(action_5);

        retranslateUi(EvisionClass);
        QObject::connect(pushButton_CalibDefault, SIGNAL(clicked()), EvisionClass, SLOT(setDefaultCalibParam()));
        QObject::connect(pushButton, SIGNAL(clicked()), EvisionClass, SLOT(doCalib()));
        QObject::connect(pushButton_MatchDefault, SIGNAL(clicked()), EvisionClass, SLOT(setDefaultMatchParam()));
        QObject::connect(pushButton_MatchChooseFiles, SIGNAL(clicked()), EvisionClass, SLOT(doMatch()));
        QObject::connect(pushButton_RangeSinglePoint, SIGNAL(clicked()), EvisionClass, SLOT(getDistance()));
        QObject::connect(pushButton_RangeDualPoint, SIGNAL(clicked()), EvisionClass, SLOT(getGap()));
        QObject::connect(lineEdit_BoardWidth, SIGNAL(textChanged(QString)), EvisionClass, SLOT(onValueChanged_BoardWidth(QString)));
        QObject::connect(lineEdit_BoardHeight, SIGNAL(textChanged(QString)), EvisionClass, SLOT(onValueChanged_BoardHeight(QString)));
        QObject::connect(lineEdit_SquareSize, SIGNAL(textChanged(QString)), EvisionClass, SLOT(onValueChanged_SquareSize(QString)));
        QObject::connect(checkBox_showRectified, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_FPP(bool)));
        QObject::connect(radioButton_Bouguet, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_Bouguet(bool)));
        QObject::connect(radioButton_Hartley, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_Hartley(bool)));
        QObject::connect(horizontalSlider_MinDisp, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_MinDisp(int)));
        QObject::connect(horizontalSlider_uniradio, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_uniradio(int)));
        QObject::connect(horizontalSlider_specwinsz, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_specwinsz(int)));
        QObject::connect(horizontalSlider_MaxDisp, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_MaxDisp(int)));
        QObject::connect(horizontalSlider_specrange, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_Specrange(int)));
        QObject::connect(horizontalSlider_prefilcap, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_Prefilcap(int)));
        QObject::connect(horizontalSlider_SadWinSiz, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_SadWinSize(int)));
        QObject::connect(horizontalSlider_textThread, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_TextThread(int)));
        QObject::connect(horizontalSlider_maxdifdisp12, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_MaxDifdisp2(int)));
        QObject::connect(horizontalSlider_pyrScale, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_PyrScale(int)));
        QObject::connect(horizontalSlider_Levels, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_Levels(int)));
        QObject::connect(horizontalSlider_PolyN, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_PolyN(int)));
        QObject::connect(horizontalSlider_PolySigma, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_PolySigma(int)));
        QObject::connect(horizontalSlider_Fi, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_Fi(int)));
        QObject::connect(horizontalSlider_Lambda, SIGNAL(valueChanged(int)), EvisionClass, SLOT(valueChanged_Lambda(int)));
        QObject::connect(radioButton_BM, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_BM(bool)));
        QObject::connect(radioButton_SGBM, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_SGBM(bool)));
        QObject::connect(radioButton_VAR, SIGNAL(clicked(bool)), EvisionClass, SLOT(onClicked_VAR(bool)));
        QObject::connect(actionDebug, SIGNAL(triggered()), EvisionClass, SLOT(onTestAlltheParam()));

        QMetaObject::connectSlotsByName(EvisionClass);
    } // setupUi

    void retranslateUi(QMainWindow *EvisionClass)
    {
        EvisionClass->setWindowTitle(QApplication::translate("EvisionClass", "Evision", nullptr));
        action->setText(QApplication::translate("EvisionClass", "\346\213\215\346\221\204\345\217\214\351\225\234\345\244\264\347\205\247\347\211\207", nullptr));
        action_2->setText(QApplication::translate("EvisionClass", "\346\230\276\347\244\272\347\202\271\344\272\221", nullptr));
        action_3->setText(QApplication::translate("EvisionClass", "\346\213\215\346\221\204\345\215\225\351\225\234\346\212\225\347\205\247\347\211\207", nullptr));
        action_4->setText(QApplication::translate("EvisionClass", "\345\270\256\345\212\251\344\277\241\346\201\257", nullptr));
        action_5->setText(QApplication::translate("EvisionClass", "\345\205\263\344\272\216", nullptr));
        actionDebug->setText(QApplication::translate("EvisionClass", "Debug", nullptr));
        groupBox->setTitle(QApplication::translate("EvisionClass", "\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        label_5->setText(QApplication::translate("EvisionClass", "Width:", nullptr));
        checkBox_showRectified->setText(QApplication::translate("EvisionClass", "\346\230\276\347\244\272\347\237\253\346\255\243\347\273\223\346\236\234", nullptr));
        label_6->setText(QApplication::translate("EvisionClass", "Height:", nullptr));
        label_8->setText(QApplication::translate("EvisionClass", "Size:", nullptr));
        radioButton_Hartley->setText(QApplication::translate("EvisionClass", "\344\275\277\347\224\250Hartley\347\237\253\346\255\243\346\226\271\346\263\225", nullptr));
        radioButton_Bouguet->setText(QApplication::translate("EvisionClass", "\344\275\277\347\224\250Bouguet\347\237\253\346\255\243\346\226\271\346\263\225", nullptr));
        groupBox_2->setTitle(QApplication::translate("EvisionClass", "\345\214\271\351\205\215\345\217\202\346\225\260", nullptr));
        label_20->setText(QApplication::translate("EvisionClass", "MinDisp", nullptr));
        label_26->setText(QApplication::translate("EvisionClass", "specrange", nullptr));
        lineEdit_uniradio->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_specwinsz->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_MinDisp->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_PolySigma->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_PolyN->setPlaceholderText(QApplication::translate("EvisionClass", "3", nullptr));
        lineEdit_textThread->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_MaxDisp->setPlaceholderText(QApplication::translate("EvisionClass", "16", nullptr));
        lineEdit_specrange->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        label_24->setText(QApplication::translate("EvisionClass", "PolySigma", nullptr));
        label_30->setText(QApplication::translate("EvisionClass", "specwinsz", nullptr));
        lineEdit_SadWinSiz->setPlaceholderText(QApplication::translate("EvisionClass", "5", nullptr));
        label_32->setText(QApplication::translate("EvisionClass", "maxdifdisp12", nullptr));
        lineEdit_maxdifdisp12->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_Fi->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        label_22->setText(QApplication::translate("EvisionClass", "SadWinSiz", nullptr));
        label_31->setText(QApplication::translate("EvisionClass", "prefilcap", nullptr));
        label_27->setText(QApplication::translate("EvisionClass", "textThread", nullptr));
        label_25->setText(QApplication::translate("EvisionClass", "uniradio", nullptr));
        label_29->setText(QApplication::translate("EvisionClass", "Fi", nullptr));
        label_34->setText(QApplication::translate("EvisionClass", "Lambda", nullptr));
        label_21->setText(QApplication::translate("EvisionClass", "MaxDisp", nullptr));
        label_33->setText(QApplication::translate("EvisionClass", "PolyN", nullptr));
        lineEdit_prefilcap->setPlaceholderText(QApplication::translate("EvisionClass", "1", nullptr));
        lineEdit_Levels->setPlaceholderText(QApplication::translate("EvisionClass", "1", nullptr));
        label_23->setText(QApplication::translate("EvisionClass", "Levels", nullptr));
        label_28->setText(QApplication::translate("EvisionClass", "pyrScale", nullptr));
        lineEdit_Lambda->setPlaceholderText(QApplication::translate("EvisionClass", "0", nullptr));
        lineEdit_pyrScale->setPlaceholderText(QApplication::translate("EvisionClass", "1", nullptr));
        groupBox_3->setTitle(QApplication::translate("EvisionClass", "\346\265\213\350\267\235", nullptr));
        pushButton_RangeSinglePoint->setText(QApplication::translate("EvisionClass", "\346\265\213\351\207\217\345\205\211\345\255\246\344\270\255\345\277\203\345\210\260\347\233\256\346\240\207\347\202\271\347\232\204\350\267\235\347\246\273", nullptr));
        pushButton_RangeDualPoint->setText(QApplication::translate("EvisionClass", "\346\265\213\351\207\217\345\233\276\344\270\255\344\270\244\347\202\271\347\232\204\350\267\235\347\246\273", nullptr));
        label_38->setText(QApplication::translate("EvisionClass", "\350\267\235\347\246\273\345\200\274:", nullptr));
        groupBox_5->setTitle(QApplication::translate("EvisionClass", "\345\214\271\351\205\215\347\256\227\346\263\225", nullptr));
        radioButton_BM->setText(QApplication::translate("EvisionClass", "BM", nullptr));
        radioButton_VAR->setText(QApplication::translate("EvisionClass", "VAR", nullptr));
        pushButton_MatchDefault->setText(QApplication::translate("EvisionClass", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        pushButton_MatchChooseFiles->setText(QApplication::translate("EvisionClass", "\345\217\214\347\233\256\345\214\271\351\205\215", nullptr));
        radioButton_SGBM->setText(QApplication::translate("EvisionClass", "SGBM", nullptr));
        groupBox_4->setTitle(QApplication::translate("EvisionClass", "\346\240\207\345\256\232", nullptr));
        pushButton->setText(QApplication::translate("EvisionClass", "\346\240\207\345\256\232", nullptr));
        pushButton_CalibDefault->setText(QApplication::translate("EvisionClass", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        menu->setTitle(QApplication::translate("EvisionClass", "\345\267\245\345\205\267", nullptr));
        menu_2->setTitle(QApplication::translate("EvisionClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EvisionClass: public Ui_EvisionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVISION_H
