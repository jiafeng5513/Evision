/********************************************************************************
** Form generated from reading UI file 'Match.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCH_H
#define UI_MATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Match
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *Viewer_MatchL;
    QGraphicsView *Viewer_MatchR;
    QGraphicsView *Viewer_ParallaxDiagram;
    QTabWidget *tabWidget_3;
    QWidget *tab_8;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_MatchDefault;
    QPushButton *pushButton_MatchChooseFiles;
    QPushButton *pushButton_MatchStart;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_BM;
    QRadioButton *radioButton_SGBM;
    QRadioButton *radioButton_VAR;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_35;
    QLineEdit *lineEdit_Lstate;
    QLabel *label_36;
    QLineEdit *lineEdit_RState;
    QLabel *label_37;
    QLineEdit *lineEdit_ParallaxDiagramState;
    QWidget *tab_9;
    QGridLayout *gridLayout_11;
    QWidget *widget_2;
    QGridLayout *gridLayout_10;
    QSlider *horizontalSlider_uniradio;
    QSlider *horizontalSlider_specwinsz;
    QLineEdit *lineEdit_MaxDisp;
    QLabel *label_26;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *lineEdit_uniradio;
    QLineEdit *lineEdit_specwinsz;
    QLabel *label_30;
    QLineEdit *lineEdit_MinDisp;
    QLabel *label_25;
    QSlider *horizontalSlider_MinDisp;
    QLabel *label_24;
    QLineEdit *lineEdit_textThread;
    QLabel *label_23;
    QSlider *horizontalSlider_specrange;
    QLineEdit *lineEdit_pyrScale;
    QSlider *horizontalSlider_SadWinSiz;
    QSlider *horizontalSlider_maxdifdisp12;
    QLabel *label_33;
    QLineEdit *lineEdit_maxdifdisp12;
    QSlider *horizontalSlider_pyrScale;
    QSlider *horizontalSlider_prefilcap;
    QLineEdit *lineEdit_prefilcap;
    QLabel *label_22;
    QLineEdit *lineEdit_specrange;
    QLabel *label_31;
    QLabel *label_27;
    QLabel *label_28;
    QSlider *horizontalSlider_MaxDisp;
    QSlider *horizontalSlider_Levels;
    QLineEdit *lineEdit_SadWinSiz;
    QLineEdit *lineEdit_Levels;
    QLineEdit *lineEdit_PolyN;
    QSlider *horizontalSlider_textThread;
    QLabel *label_32;
    QSlider *horizontalSlider_PolyN;
    QLabel *label_34;
    QLineEdit *lineEdit_Lambda;
    QSlider *horizontalSlider_Fi;
    QLabel *label_29;
    QLineEdit *lineEdit_Fi;
    QSlider *horizontalSlider_PolySigma;
    QSlider *horizontalSlider_Lambda;
    QLineEdit *lineEdit_PolySigma;

    void setupUi(QWidget *Match)
    {
        if (Match->objectName().isEmpty())
            Match->setObjectName(QStringLiteral("Match"));
        Match->resize(760, 438);
        gridLayout = new QGridLayout(Match);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Viewer_MatchL = new QGraphicsView(Match);
        Viewer_MatchL->setObjectName(QStringLiteral("Viewer_MatchL"));
        Viewer_MatchL->setMinimumSize(QSize(368, 207));

        gridLayout->addWidget(Viewer_MatchL, 0, 0, 1, 1);

        Viewer_MatchR = new QGraphicsView(Match);
        Viewer_MatchR->setObjectName(QStringLiteral("Viewer_MatchR"));
        Viewer_MatchR->setMinimumSize(QSize(368, 207));

        gridLayout->addWidget(Viewer_MatchR, 0, 1, 1, 1);

        Viewer_ParallaxDiagram = new QGraphicsView(Match);
        Viewer_ParallaxDiagram->setObjectName(QStringLiteral("Viewer_ParallaxDiagram"));
        Viewer_ParallaxDiagram->setMinimumSize(QSize(368, 207));

        gridLayout->addWidget(Viewer_ParallaxDiagram, 1, 0, 1, 1);

        tabWidget_3 = new QTabWidget(Match);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setMinimumSize(QSize(368, 207));
        tabWidget_3->setMaximumSize(QSize(16777215, 16777215));
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        gridLayout_12 = new QGridLayout(tab_8);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        pushButton_MatchDefault = new QPushButton(tab_8);
        pushButton_MatchDefault->setObjectName(QStringLiteral("pushButton_MatchDefault"));
        pushButton_MatchDefault->setMinimumSize(QSize(0, 20));

        gridLayout_12->addWidget(pushButton_MatchDefault, 0, 0, 1, 1);

        pushButton_MatchChooseFiles = new QPushButton(tab_8);
        pushButton_MatchChooseFiles->setObjectName(QStringLiteral("pushButton_MatchChooseFiles"));
        pushButton_MatchChooseFiles->setMinimumSize(QSize(0, 20));

        gridLayout_12->addWidget(pushButton_MatchChooseFiles, 0, 1, 1, 1);

        pushButton_MatchStart = new QPushButton(tab_8);
        pushButton_MatchStart->setObjectName(QStringLiteral("pushButton_MatchStart"));
        pushButton_MatchStart->setMinimumSize(QSize(0, 20));

        gridLayout_12->addWidget(pushButton_MatchStart, 0, 2, 1, 1);

        groupBox_5 = new QGroupBox(tab_8);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        radioButton_BM = new QRadioButton(groupBox_5);
        radioButton_BM->setObjectName(QStringLiteral("radioButton_BM"));

        verticalLayout_2->addWidget(radioButton_BM);

        radioButton_SGBM = new QRadioButton(groupBox_5);
        radioButton_SGBM->setObjectName(QStringLiteral("radioButton_SGBM"));

        verticalLayout_2->addWidget(radioButton_SGBM);

        radioButton_VAR = new QRadioButton(groupBox_5);
        radioButton_VAR->setObjectName(QStringLiteral("radioButton_VAR"));

        verticalLayout_2->addWidget(radioButton_VAR);


        gridLayout_12->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_6 = new QGroupBox(tab_8);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        verticalLayout_3 = new QVBoxLayout(groupBox_6);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_35 = new QLabel(groupBox_6);
        label_35->setObjectName(QStringLiteral("label_35"));

        verticalLayout_3->addWidget(label_35);

        lineEdit_Lstate = new QLineEdit(groupBox_6);
        lineEdit_Lstate->setObjectName(QStringLiteral("lineEdit_Lstate"));

        verticalLayout_3->addWidget(lineEdit_Lstate);

        label_36 = new QLabel(groupBox_6);
        label_36->setObjectName(QStringLiteral("label_36"));

        verticalLayout_3->addWidget(label_36);

        lineEdit_RState = new QLineEdit(groupBox_6);
        lineEdit_RState->setObjectName(QStringLiteral("lineEdit_RState"));

        verticalLayout_3->addWidget(lineEdit_RState);

        label_37 = new QLabel(groupBox_6);
        label_37->setObjectName(QStringLiteral("label_37"));

        verticalLayout_3->addWidget(label_37);

        lineEdit_ParallaxDiagramState = new QLineEdit(groupBox_6);
        lineEdit_ParallaxDiagramState->setObjectName(QStringLiteral("lineEdit_ParallaxDiagramState"));

        verticalLayout_3->addWidget(lineEdit_ParallaxDiagramState);


        gridLayout_12->addWidget(groupBox_6, 1, 1, 1, 2);

        tabWidget_3->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        gridLayout_11 = new QGridLayout(tab_9);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        widget_2 = new QWidget(tab_9);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        gridLayout_10 = new QGridLayout(widget_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        horizontalSlider_uniradio = new QSlider(widget_2);
        horizontalSlider_uniradio->setObjectName(QStringLiteral("horizontalSlider_uniradio"));
        horizontalSlider_uniradio->setMinimumSize(QSize(0, 15));
        horizontalSlider_uniradio->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_uniradio->setMaximum(50);
        horizontalSlider_uniradio->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_uniradio, 1, 2, 1, 2);

        horizontalSlider_specwinsz = new QSlider(widget_2);
        horizontalSlider_specwinsz->setObjectName(QStringLiteral("horizontalSlider_specwinsz"));
        horizontalSlider_specwinsz->setMinimumSize(QSize(0, 15));
        horizontalSlider_specwinsz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specwinsz->setMaximum(200);
        horizontalSlider_specwinsz->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_specwinsz, 1, 4, 1, 2);

        lineEdit_MaxDisp = new QLineEdit(widget_2);
        lineEdit_MaxDisp->setObjectName(QStringLiteral("lineEdit_MaxDisp"));
        lineEdit_MaxDisp->setMinimumSize(QSize(30, 20));
        lineEdit_MaxDisp->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_MaxDisp, 2, 1, 1, 1);

        label_26 = new QLabel(widget_2);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_10->addWidget(label_26, 2, 2, 1, 1);

        label_20 = new QLabel(widget_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_10->addWidget(label_20, 0, 0, 1, 1);

        label_21 = new QLabel(widget_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_10->addWidget(label_21, 2, 0, 1, 1);

        lineEdit_uniradio = new QLineEdit(widget_2);
        lineEdit_uniradio->setObjectName(QStringLiteral("lineEdit_uniradio"));
        lineEdit_uniradio->setMinimumSize(QSize(30, 20));
        lineEdit_uniradio->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_uniradio, 0, 3, 1, 1);

        lineEdit_specwinsz = new QLineEdit(widget_2);
        lineEdit_specwinsz->setObjectName(QStringLiteral("lineEdit_specwinsz"));
        lineEdit_specwinsz->setMinimumSize(QSize(30, 20));
        lineEdit_specwinsz->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_specwinsz, 0, 5, 1, 1);

        label_30 = new QLabel(widget_2);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_10->addWidget(label_30, 0, 4, 1, 1);

        lineEdit_MinDisp = new QLineEdit(widget_2);
        lineEdit_MinDisp->setObjectName(QStringLiteral("lineEdit_MinDisp"));
        lineEdit_MinDisp->setMinimumSize(QSize(30, 20));
        lineEdit_MinDisp->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_MinDisp, 0, 1, 1, 1);

        label_25 = new QLabel(widget_2);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_10->addWidget(label_25, 0, 2, 1, 1);

        horizontalSlider_MinDisp = new QSlider(widget_2);
        horizontalSlider_MinDisp->setObjectName(QStringLiteral("horizontalSlider_MinDisp"));
        horizontalSlider_MinDisp->setMinimumSize(QSize(0, 15));
        horizontalSlider_MinDisp->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_MinDisp->setMinimum(-64);
        horizontalSlider_MinDisp->setMaximum(16);
        horizontalSlider_MinDisp->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_MinDisp, 1, 0, 1, 2);

        label_24 = new QLabel(widget_2);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_10->addWidget(label_24, 8, 0, 1, 1);

        lineEdit_textThread = new QLineEdit(widget_2);
        lineEdit_textThread->setObjectName(QStringLiteral("lineEdit_textThread"));
        lineEdit_textThread->setMinimumSize(QSize(30, 20));
        lineEdit_textThread->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_textThread, 4, 3, 1, 1);

        label_23 = new QLabel(widget_2);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_10->addWidget(label_23, 6, 0, 1, 1);

        horizontalSlider_specrange = new QSlider(widget_2);
        horizontalSlider_specrange->setObjectName(QStringLiteral("horizontalSlider_specrange"));
        horizontalSlider_specrange->setMinimumSize(QSize(0, 15));
        horizontalSlider_specrange->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specrange->setMaximum(64);
        horizontalSlider_specrange->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_specrange, 3, 2, 1, 2);

        lineEdit_pyrScale = new QLineEdit(widget_2);
        lineEdit_pyrScale->setObjectName(QStringLiteral("lineEdit_pyrScale"));
        lineEdit_pyrScale->setMinimumSize(QSize(30, 20));
        lineEdit_pyrScale->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_pyrScale, 6, 3, 1, 1);

        horizontalSlider_SadWinSiz = new QSlider(widget_2);
        horizontalSlider_SadWinSiz->setObjectName(QStringLiteral("horizontalSlider_SadWinSiz"));
        horizontalSlider_SadWinSiz->setMinimumSize(QSize(0, 15));
        horizontalSlider_SadWinSiz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_SadWinSiz->setMinimum(5);
        horizontalSlider_SadWinSiz->setMaximum(51);
        horizontalSlider_SadWinSiz->setSingleStep(2);
        horizontalSlider_SadWinSiz->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_SadWinSiz, 5, 0, 1, 2);

        horizontalSlider_maxdifdisp12 = new QSlider(widget_2);
        horizontalSlider_maxdifdisp12->setObjectName(QStringLiteral("horizontalSlider_maxdifdisp12"));
        horizontalSlider_maxdifdisp12->setMinimumSize(QSize(0, 15));
        horizontalSlider_maxdifdisp12->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_maxdifdisp12->setMinimum(-1);
        horizontalSlider_maxdifdisp12->setMaximum(5);
        horizontalSlider_maxdifdisp12->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_maxdifdisp12, 5, 4, 1, 2);

        label_33 = new QLabel(widget_2);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_10->addWidget(label_33, 6, 4, 1, 1);

        lineEdit_maxdifdisp12 = new QLineEdit(widget_2);
        lineEdit_maxdifdisp12->setObjectName(QStringLiteral("lineEdit_maxdifdisp12"));
        lineEdit_maxdifdisp12->setMinimumSize(QSize(30, 20));
        lineEdit_maxdifdisp12->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_maxdifdisp12, 4, 5, 1, 1);

        horizontalSlider_pyrScale = new QSlider(widget_2);
        horizontalSlider_pyrScale->setObjectName(QStringLiteral("horizontalSlider_pyrScale"));
        horizontalSlider_pyrScale->setMinimumSize(QSize(0, 15));
        horizontalSlider_pyrScale->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_pyrScale->setMinimum(1);
        horizontalSlider_pyrScale->setMaximum(10);
        horizontalSlider_pyrScale->setSingleStep(1);
        horizontalSlider_pyrScale->setValue(1);
        horizontalSlider_pyrScale->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_pyrScale, 7, 2, 1, 2);

        horizontalSlider_prefilcap = new QSlider(widget_2);
        horizontalSlider_prefilcap->setObjectName(QStringLiteral("horizontalSlider_prefilcap"));
        horizontalSlider_prefilcap->setMinimumSize(QSize(0, 15));
        horizontalSlider_prefilcap->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_prefilcap->setMinimum(1);
        horizontalSlider_prefilcap->setMaximum(100);
        horizontalSlider_prefilcap->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_prefilcap, 3, 4, 1, 2);

        lineEdit_prefilcap = new QLineEdit(widget_2);
        lineEdit_prefilcap->setObjectName(QStringLiteral("lineEdit_prefilcap"));
        lineEdit_prefilcap->setMinimumSize(QSize(30, 20));
        lineEdit_prefilcap->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_prefilcap, 2, 5, 1, 1);

        label_22 = new QLabel(widget_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_10->addWidget(label_22, 4, 0, 1, 1);

        lineEdit_specrange = new QLineEdit(widget_2);
        lineEdit_specrange->setObjectName(QStringLiteral("lineEdit_specrange"));
        lineEdit_specrange->setMinimumSize(QSize(30, 20));
        lineEdit_specrange->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_specrange, 2, 3, 1, 1);

        label_31 = new QLabel(widget_2);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_10->addWidget(label_31, 2, 4, 1, 1);

        label_27 = new QLabel(widget_2);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_10->addWidget(label_27, 4, 2, 1, 1);

        label_28 = new QLabel(widget_2);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_10->addWidget(label_28, 6, 2, 1, 1);

        horizontalSlider_MaxDisp = new QSlider(widget_2);
        horizontalSlider_MaxDisp->setObjectName(QStringLiteral("horizontalSlider_MaxDisp"));
        horizontalSlider_MaxDisp->setMinimumSize(QSize(0, 15));
        horizontalSlider_MaxDisp->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_MaxDisp->setMinimum(16);
        horizontalSlider_MaxDisp->setMaximum(256);
        horizontalSlider_MaxDisp->setSingleStep(16);
        horizontalSlider_MaxDisp->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_MaxDisp, 3, 0, 1, 2);

        horizontalSlider_Levels = new QSlider(widget_2);
        horizontalSlider_Levels->setObjectName(QStringLiteral("horizontalSlider_Levels"));
        horizontalSlider_Levels->setMinimumSize(QSize(0, 15));
        horizontalSlider_Levels->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Levels->setMinimum(1);
        horizontalSlider_Levels->setMaximum(10);
        horizontalSlider_Levels->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_Levels, 7, 0, 1, 2);

        lineEdit_SadWinSiz = new QLineEdit(widget_2);
        lineEdit_SadWinSiz->setObjectName(QStringLiteral("lineEdit_SadWinSiz"));
        lineEdit_SadWinSiz->setMinimumSize(QSize(30, 20));
        lineEdit_SadWinSiz->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_SadWinSiz, 4, 1, 1, 1);

        lineEdit_Levels = new QLineEdit(widget_2);
        lineEdit_Levels->setObjectName(QStringLiteral("lineEdit_Levels"));
        lineEdit_Levels->setMinimumSize(QSize(30, 20));
        lineEdit_Levels->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_Levels, 6, 1, 1, 1);

        lineEdit_PolyN = new QLineEdit(widget_2);
        lineEdit_PolyN->setObjectName(QStringLiteral("lineEdit_PolyN"));
        lineEdit_PolyN->setMinimumSize(QSize(30, 20));
        lineEdit_PolyN->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_PolyN, 6, 5, 1, 1);

        horizontalSlider_textThread = new QSlider(widget_2);
        horizontalSlider_textThread->setObjectName(QStringLiteral("horizontalSlider_textThread"));
        horizontalSlider_textThread->setMinimumSize(QSize(0, 15));
        horizontalSlider_textThread->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_textThread->setMaximum(50);
        horizontalSlider_textThread->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_textThread, 5, 2, 1, 2);

        label_32 = new QLabel(widget_2);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_10->addWidget(label_32, 4, 4, 1, 1);

        horizontalSlider_PolyN = new QSlider(widget_2);
        horizontalSlider_PolyN->setObjectName(QStringLiteral("horizontalSlider_PolyN"));
        horizontalSlider_PolyN->setMinimumSize(QSize(0, 15));
        horizontalSlider_PolyN->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_PolyN->setMinimum(3);
        horizontalSlider_PolyN->setMaximum(61);
        horizontalSlider_PolyN->setSingleStep(2);
        horizontalSlider_PolyN->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_PolyN, 7, 4, 1, 2);

        label_34 = new QLabel(widget_2);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_10->addWidget(label_34, 8, 4, 1, 1);

        lineEdit_Lambda = new QLineEdit(widget_2);
        lineEdit_Lambda->setObjectName(QStringLiteral("lineEdit_Lambda"));
        lineEdit_Lambda->setMinimumSize(QSize(30, 20));
        lineEdit_Lambda->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_Lambda, 8, 5, 1, 1);

        horizontalSlider_Fi = new QSlider(widget_2);
        horizontalSlider_Fi->setObjectName(QStringLiteral("horizontalSlider_Fi"));
        horizontalSlider_Fi->setMinimumSize(QSize(0, 15));
        horizontalSlider_Fi->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Fi->setMaximum(900);
        horizontalSlider_Fi->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_Fi, 9, 2, 1, 2);

        label_29 = new QLabel(widget_2);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_10->addWidget(label_29, 8, 2, 1, 1);

        lineEdit_Fi = new QLineEdit(widget_2);
        lineEdit_Fi->setObjectName(QStringLiteral("lineEdit_Fi"));
        lineEdit_Fi->setMinimumSize(QSize(30, 20));
        lineEdit_Fi->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_Fi, 8, 3, 1, 1);

        horizontalSlider_PolySigma = new QSlider(widget_2);
        horizontalSlider_PolySigma->setObjectName(QStringLiteral("horizontalSlider_PolySigma"));
        horizontalSlider_PolySigma->setMinimumSize(QSize(0, 15));
        horizontalSlider_PolySigma->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_PolySigma->setMaximum(1000);
        horizontalSlider_PolySigma->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_PolySigma, 9, 0, 1, 2);

        horizontalSlider_Lambda = new QSlider(widget_2);
        horizontalSlider_Lambda->setObjectName(QStringLiteral("horizontalSlider_Lambda"));
        horizontalSlider_Lambda->setMinimumSize(QSize(0, 15));
        horizontalSlider_Lambda->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_Lambda->setMaximum(100);
        horizontalSlider_Lambda->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_Lambda, 9, 4, 1, 2);

        lineEdit_PolySigma = new QLineEdit(widget_2);
        lineEdit_PolySigma->setObjectName(QStringLiteral("lineEdit_PolySigma"));
        lineEdit_PolySigma->setMinimumSize(QSize(30, 20));
        lineEdit_PolySigma->setMaximumSize(QSize(30, 20));

        gridLayout_10->addWidget(lineEdit_PolySigma, 8, 1, 1, 1);


        gridLayout_11->addWidget(widget_2, 0, 0, 1, 1);

        tabWidget_3->addTab(tab_9, QString());

        gridLayout->addWidget(tabWidget_3, 1, 1, 1, 1);


        retranslateUi(Match);

        tabWidget_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Match);
    } // setupUi

    void retranslateUi(QWidget *Match)
    {
        Match->setWindowTitle(QApplication::translate("Match", "Match", Q_NULLPTR));
        pushButton_MatchDefault->setText(QApplication::translate("Match", "\351\273\230\350\256\244\345\217\202\346\225\260", Q_NULLPTR));
        pushButton_MatchChooseFiles->setText(QApplication::translate("Match", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_MatchStart->setText(QApplication::translate("Match", "\345\274\200\345\247\213\350\256\241\347\256\227", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Match", "\345\214\271\351\205\215\347\256\227\346\263\225", Q_NULLPTR));
        radioButton_BM->setText(QApplication::translate("Match", "BM", Q_NULLPTR));
        radioButton_SGBM->setText(QApplication::translate("Match", "SGBM", Q_NULLPTR));
        radioButton_VAR->setText(QApplication::translate("Match", "VAR", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Match", "\347\212\266\346\200\201", Q_NULLPTR));
        label_35->setText(QApplication::translate("Match", "\345\267\246\350\247\206\345\233\276:", Q_NULLPTR));
        label_36->setText(QApplication::translate("Match", "\345\217\263\350\247\206\345\233\276:", Q_NULLPTR));
        label_37->setText(QApplication::translate("Match", "\350\247\206\345\267\256\345\233\276:", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("Match", "\345\237\272\346\234\254\345\212\237\350\203\275", Q_NULLPTR));
        label_26->setText(QApplication::translate("Match", "specrange", Q_NULLPTR));
        label_20->setText(QApplication::translate("Match", "MinDisp", Q_NULLPTR));
        label_21->setText(QApplication::translate("Match", "MaxDisp", Q_NULLPTR));
        label_30->setText(QApplication::translate("Match", "specwinsz", Q_NULLPTR));
        label_25->setText(QApplication::translate("Match", "uniradio", Q_NULLPTR));
        label_24->setText(QApplication::translate("Match", "PolySigma", Q_NULLPTR));
        label_23->setText(QApplication::translate("Match", "Levels", Q_NULLPTR));
        label_33->setText(QApplication::translate("Match", "PolyN", Q_NULLPTR));
        label_22->setText(QApplication::translate("Match", "SadWinSiz", Q_NULLPTR));
        label_31->setText(QApplication::translate("Match", "prefilcap", Q_NULLPTR));
        label_27->setText(QApplication::translate("Match", "textThread", Q_NULLPTR));
        label_28->setText(QApplication::translate("Match", "pyrScale", Q_NULLPTR));
        label_32->setText(QApplication::translate("Match", "maxdifdisp12", Q_NULLPTR));
        label_34->setText(QApplication::translate("Match", "Lambda", Q_NULLPTR));
        label_29->setText(QApplication::translate("Match", "Fi", Q_NULLPTR));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QApplication::translate("Match", "\345\217\202\346\225\260\345\276\256\350\260\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Match: public Ui_Match {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCH_H
