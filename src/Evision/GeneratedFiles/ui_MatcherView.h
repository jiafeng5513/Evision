/********************************************************************************
** Form generated from reading UI file 'MatcherView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHERVIEW_H
#define UI_MATCHERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatcherView
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_uniradio;
    QSlider *horizontalSlider_uniradio;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_prefilcap;
    QSlider *horizontalSlider_prefilcap;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_SadWinSiz;
    QSlider *horizontalSlider_SadWinSiz;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_specwinsz;
    QSlider *horizontalSlider_specwinsz;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_MinDisp;
    QSlider *horizontalSlider_MinDisp;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_NumDisparities;
    QSlider *horizontalSlider_NumDisparities;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_specrange;
    QSlider *horizontalSlider_specrange;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_maxdifdisp12;
    QSlider *horizontalSlider_maxdifdisp12;
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_textThread;
    QSlider *horizontalSlider_textThread;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsView_ImageL;
    QRadioButton *radioButton_ImageL;
    QGraphicsView *graphicsView_ImageR;
    QRadioButton *radioButton_ImageR;
    QGraphicsView *graphicsView_RawDisp;
    QRadioButton *radioButton_RawDisp;
    QGraphicsView *graphicsView_FixDisp;
    QRadioButton *radioButton_FixDisp;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView_D;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_12;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_BM;
    QRadioButton *radioButton_SGBM;
    QFrame *line;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_MODE_3WAY;
    QRadioButton *radioButton_MODE_SGBM;
    QRadioButton *radioButton_MODE_HH;
    QFrame *line_2;
    QCheckBox *checkBox_DoRectify;
    QFrame *line_3;
    QPushButton *pushButton_MatchDefault;
    QPushButton *pushButton_MatchChooseFiles;
    QPushButton *pushButton_RefreshStereoMatch;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MatcherView)
    {
        if (MatcherView->objectName().isEmpty())
            MatcherView->setObjectName(QString::fromUtf8("MatcherView"));
        MatcherView->resize(1000, 585);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MatcherView->sizePolicy().hasHeightForWidth());
        MatcherView->setSizePolicy(sizePolicy);
        MatcherView->setMinimumSize(QSize(1000, 585));
        gridLayout = new QGridLayout(MatcherView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_3 = new QFrame(MatcherView);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMaximumSize(QSize(240, 16777215));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_uniradio = new QLineEdit(groupBox);
        lineEdit_uniradio->setObjectName(QString::fromUtf8("lineEdit_uniradio"));
        lineEdit_uniradio->setMinimumSize(QSize(35, 20));
        lineEdit_uniradio->setMaximumSize(QSize(30, 20));
        lineEdit_uniradio->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_uniradio);

        horizontalSlider_uniradio = new QSlider(groupBox);
        horizontalSlider_uniradio->setObjectName(QString::fromUtf8("horizontalSlider_uniradio"));
        horizontalSlider_uniradio->setMinimumSize(QSize(0, 20));
        horizontalSlider_uniradio->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_uniradio->setMaximum(50);
        horizontalSlider_uniradio->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_uniradio);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit_prefilcap = new QLineEdit(groupBox_2);
        lineEdit_prefilcap->setObjectName(QString::fromUtf8("lineEdit_prefilcap"));
        lineEdit_prefilcap->setMinimumSize(QSize(35, 20));
        lineEdit_prefilcap->setMaximumSize(QSize(30, 20));
        lineEdit_prefilcap->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_prefilcap);

        horizontalSlider_prefilcap = new QSlider(groupBox_2);
        horizontalSlider_prefilcap->setObjectName(QString::fromUtf8("horizontalSlider_prefilcap"));
        horizontalSlider_prefilcap->setMinimumSize(QSize(0, 20));
        horizontalSlider_prefilcap->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_prefilcap->setMinimum(1);
        horizontalSlider_prefilcap->setMaximum(100);
        horizontalSlider_prefilcap->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_prefilcap);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_SadWinSiz = new QLineEdit(groupBox_3);
        lineEdit_SadWinSiz->setObjectName(QString::fromUtf8("lineEdit_SadWinSiz"));
        lineEdit_SadWinSiz->setMinimumSize(QSize(35, 20));
        lineEdit_SadWinSiz->setMaximumSize(QSize(30, 20));
        lineEdit_SadWinSiz->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit_SadWinSiz);

        horizontalSlider_SadWinSiz = new QSlider(groupBox_3);
        horizontalSlider_SadWinSiz->setObjectName(QString::fromUtf8("horizontalSlider_SadWinSiz"));
        horizontalSlider_SadWinSiz->setMinimumSize(QSize(0, 20));
        horizontalSlider_SadWinSiz->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_SadWinSiz->setMinimum(5);
        horizontalSlider_SadWinSiz->setMaximum(51);
        horizontalSlider_SadWinSiz->setSingleStep(2);
        horizontalSlider_SadWinSiz->setPageStep(2);
        horizontalSlider_SadWinSiz->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(horizontalSlider_SadWinSiz);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(frame_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_specwinsz = new QLineEdit(groupBox_4);
        lineEdit_specwinsz->setObjectName(QString::fromUtf8("lineEdit_specwinsz"));
        lineEdit_specwinsz->setMinimumSize(QSize(35, 20));
        lineEdit_specwinsz->setMaximumSize(QSize(30, 20));
        lineEdit_specwinsz->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEdit_specwinsz);

        horizontalSlider_specwinsz = new QSlider(groupBox_4);
        horizontalSlider_specwinsz->setObjectName(QString::fromUtf8("horizontalSlider_specwinsz"));
        horizontalSlider_specwinsz->setMinimumSize(QSize(0, 20));
        horizontalSlider_specwinsz->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_specwinsz->setMaximum(200);
        horizontalSlider_specwinsz->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(horizontalSlider_specwinsz);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(frame_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_5);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lineEdit_MinDisp = new QLineEdit(groupBox_5);
        lineEdit_MinDisp->setObjectName(QString::fromUtf8("lineEdit_MinDisp"));
        lineEdit_MinDisp->setMinimumSize(QSize(35, 20));
        lineEdit_MinDisp->setMaximumSize(QSize(30, 20));
        lineEdit_MinDisp->setReadOnly(true);

        horizontalLayout_7->addWidget(lineEdit_MinDisp);

        horizontalSlider_MinDisp = new QSlider(groupBox_5);
        horizontalSlider_MinDisp->setObjectName(QString::fromUtf8("horizontalSlider_MinDisp"));
        horizontalSlider_MinDisp->setMinimumSize(QSize(0, 20));
        horizontalSlider_MinDisp->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_MinDisp->setMinimum(-64);
        horizontalSlider_MinDisp->setMaximum(16);
        horizontalSlider_MinDisp->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_MinDisp);


        verticalLayout->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(frame_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_6);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lineEdit_NumDisparities = new QLineEdit(groupBox_6);
        lineEdit_NumDisparities->setObjectName(QString::fromUtf8("lineEdit_NumDisparities"));
        lineEdit_NumDisparities->setMinimumSize(QSize(35, 20));
        lineEdit_NumDisparities->setMaximumSize(QSize(30, 20));
        lineEdit_NumDisparities->setReadOnly(true);

        horizontalLayout_8->addWidget(lineEdit_NumDisparities);

        horizontalSlider_NumDisparities = new QSlider(groupBox_6);
        horizontalSlider_NumDisparities->setObjectName(QString::fromUtf8("horizontalSlider_NumDisparities"));
        horizontalSlider_NumDisparities->setMinimumSize(QSize(0, 20));
        horizontalSlider_NumDisparities->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_NumDisparities->setMinimum(16);
        horizontalSlider_NumDisparities->setMaximum(256);
        horizontalSlider_NumDisparities->setSingleStep(16);
        horizontalSlider_NumDisparities->setPageStep(16);
        horizontalSlider_NumDisparities->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider_NumDisparities);


        verticalLayout->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(frame_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_7);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineEdit_specrange = new QLineEdit(groupBox_7);
        lineEdit_specrange->setObjectName(QString::fromUtf8("lineEdit_specrange"));
        lineEdit_specrange->setMinimumSize(QSize(35, 20));
        lineEdit_specrange->setMaximumSize(QSize(30, 20));
        lineEdit_specrange->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEdit_specrange);

        horizontalSlider_specrange = new QSlider(groupBox_7);
        horizontalSlider_specrange->setObjectName(QString::fromUtf8("horizontalSlider_specrange"));
        horizontalSlider_specrange->setMinimumSize(QSize(0, 20));
        horizontalSlider_specrange->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_specrange->setMaximum(64);
        horizontalSlider_specrange->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_specrange);


        verticalLayout->addWidget(groupBox_7);

        groupBox_10 = new QGroupBox(frame_3);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_10);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lineEdit_maxdifdisp12 = new QLineEdit(groupBox_10);
        lineEdit_maxdifdisp12->setObjectName(QString::fromUtf8("lineEdit_maxdifdisp12"));
        lineEdit_maxdifdisp12->setMinimumSize(QSize(35, 20));
        lineEdit_maxdifdisp12->setMaximumSize(QSize(30, 20));
        lineEdit_maxdifdisp12->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_maxdifdisp12);

        horizontalSlider_maxdifdisp12 = new QSlider(groupBox_10);
        horizontalSlider_maxdifdisp12->setObjectName(QString::fromUtf8("horizontalSlider_maxdifdisp12"));
        horizontalSlider_maxdifdisp12->setMinimumSize(QSize(0, 20));
        horizontalSlider_maxdifdisp12->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_maxdifdisp12->setMinimum(-1);
        horizontalSlider_maxdifdisp12->setMaximum(5);
        horizontalSlider_maxdifdisp12->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalSlider_maxdifdisp12);


        verticalLayout->addWidget(groupBox_10);

        groupBox_11 = new QGroupBox(frame_3);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_11);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lineEdit_textThread = new QLineEdit(groupBox_11);
        lineEdit_textThread->setObjectName(QString::fromUtf8("lineEdit_textThread"));
        lineEdit_textThread->setMinimumSize(QSize(35, 20));
        lineEdit_textThread->setMaximumSize(QSize(30, 20));
        lineEdit_textThread->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEdit_textThread);

        horizontalSlider_textThread = new QSlider(groupBox_11);
        horizontalSlider_textThread->setObjectName(QString::fromUtf8("horizontalSlider_textThread"));
        horizontalSlider_textThread->setMinimumSize(QSize(0, 20));
        horizontalSlider_textThread->setMaximumSize(QSize(16777215, 20));
        horizontalSlider_textThread->setMaximum(50);
        horizontalSlider_textThread->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(horizontalSlider_textThread);


        verticalLayout->addWidget(groupBox_11);


        gridLayout->addWidget(frame_3, 1, 2, 1, 1);

        frame_2 = new QFrame(MatcherView);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setMaximumSize(QSize(141, 16777215));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        graphicsView_ImageL = new QGraphicsView(frame_2);
        graphicsView_ImageL->setObjectName(QString::fromUtf8("graphicsView_ImageL"));
        graphicsView_ImageL->setMaximumSize(QSize(133, 100));

        verticalLayout_3->addWidget(graphicsView_ImageL);

        radioButton_ImageL = new QRadioButton(frame_2);
        radioButton_ImageL->setObjectName(QString::fromUtf8("radioButton_ImageL"));
        radioButton_ImageL->setAutoExclusive(false);

        verticalLayout_3->addWidget(radioButton_ImageL);

        graphicsView_ImageR = new QGraphicsView(frame_2);
        graphicsView_ImageR->setObjectName(QString::fromUtf8("graphicsView_ImageR"));
        graphicsView_ImageR->setMaximumSize(QSize(133, 100));

        verticalLayout_3->addWidget(graphicsView_ImageR);

        radioButton_ImageR = new QRadioButton(frame_2);
        radioButton_ImageR->setObjectName(QString::fromUtf8("radioButton_ImageR"));
        radioButton_ImageR->setAutoExclusive(false);

        verticalLayout_3->addWidget(radioButton_ImageR);

        graphicsView_RawDisp = new QGraphicsView(frame_2);
        graphicsView_RawDisp->setObjectName(QString::fromUtf8("graphicsView_RawDisp"));
        graphicsView_RawDisp->setMaximumSize(QSize(133, 100));

        verticalLayout_3->addWidget(graphicsView_RawDisp);

        radioButton_RawDisp = new QRadioButton(frame_2);
        radioButton_RawDisp->setObjectName(QString::fromUtf8("radioButton_RawDisp"));
        radioButton_RawDisp->setAutoExclusive(false);

        verticalLayout_3->addWidget(radioButton_RawDisp);

        graphicsView_FixDisp = new QGraphicsView(frame_2);
        graphicsView_FixDisp->setObjectName(QString::fromUtf8("graphicsView_FixDisp"));
        graphicsView_FixDisp->setMaximumSize(QSize(133, 100));

        verticalLayout_3->addWidget(graphicsView_FixDisp);

        radioButton_FixDisp = new QRadioButton(frame_2);
        radioButton_FixDisp->setObjectName(QString::fromUtf8("radioButton_FixDisp"));
        radioButton_FixDisp->setAutoExclusive(false);

        verticalLayout_3->addWidget(radioButton_FixDisp);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addWidget(frame_2, 1, 0, 1, 1);

        graphicsView_D = new QGraphicsView(MatcherView);
        graphicsView_D->setObjectName(QString::fromUtf8("graphicsView_D"));
        graphicsView_D->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(graphicsView_D, 1, 1, 1, 1);

        frame = new QFrame(MatcherView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        frame_8 = new QFrame(frame);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        horizontalLayout = new QHBoxLayout(frame_8);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        radioButton_BM = new QRadioButton(frame_8);
        radioButton_BM->setObjectName(QString::fromUtf8("radioButton_BM"));

        horizontalLayout->addWidget(radioButton_BM);

        radioButton_SGBM = new QRadioButton(frame_8);
        radioButton_SGBM->setObjectName(QString::fromUtf8("radioButton_SGBM"));

        horizontalLayout->addWidget(radioButton_SGBM);


        horizontalLayout_12->addWidget(frame_8);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        radioButton_MODE_3WAY = new QRadioButton(frame_4);
        radioButton_MODE_3WAY->setObjectName(QString::fromUtf8("radioButton_MODE_3WAY"));

        horizontalLayout_2->addWidget(radioButton_MODE_3WAY);

        radioButton_MODE_SGBM = new QRadioButton(frame_4);
        radioButton_MODE_SGBM->setObjectName(QString::fromUtf8("radioButton_MODE_SGBM"));

        horizontalLayout_2->addWidget(radioButton_MODE_SGBM);

        radioButton_MODE_HH = new QRadioButton(frame_4);
        radioButton_MODE_HH->setObjectName(QString::fromUtf8("radioButton_MODE_HH"));

        horizontalLayout_2->addWidget(radioButton_MODE_HH);


        horizontalLayout_12->addWidget(frame_4);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_2);

        checkBox_DoRectify = new QCheckBox(frame);
        checkBox_DoRectify->setObjectName(QString::fromUtf8("checkBox_DoRectify"));

        horizontalLayout_12->addWidget(checkBox_DoRectify);

        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_3);

        pushButton_MatchDefault = new QPushButton(frame);
        pushButton_MatchDefault->setObjectName(QString::fromUtf8("pushButton_MatchDefault"));
        pushButton_MatchDefault->setMinimumSize(QSize(0, 20));

        horizontalLayout_12->addWidget(pushButton_MatchDefault);

        pushButton_MatchChooseFiles = new QPushButton(frame);
        pushButton_MatchChooseFiles->setObjectName(QString::fromUtf8("pushButton_MatchChooseFiles"));
        pushButton_MatchChooseFiles->setMinimumSize(QSize(0, 20));

        horizontalLayout_12->addWidget(pushButton_MatchChooseFiles);

        pushButton_RefreshStereoMatch = new QPushButton(frame);
        pushButton_RefreshStereoMatch->setObjectName(QString::fromUtf8("pushButton_RefreshStereoMatch"));

        horizontalLayout_12->addWidget(pushButton_RefreshStereoMatch);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        gridLayout->addWidget(frame, 0, 0, 1, 3);


        retranslateUi(MatcherView);
        QObject::connect(pushButton_MatchDefault, SIGNAL(clicked()), MatcherView, SLOT(setDefaultMatchParam()));
        QObject::connect(pushButton_MatchChooseFiles, SIGNAL(clicked()), MatcherView, SLOT(doMatch()));
        QObject::connect(pushButton_RefreshStereoMatch, SIGNAL(clicked()), MatcherView, SLOT(RefreshStereoMatch()));
        QObject::connect(radioButton_MODE_HH, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_MODE_HH(bool)));
        QObject::connect(radioButton_MODE_3WAY, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_MODE_3WAY(bool)));
        QObject::connect(radioButton_MODE_SGBM, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_MODE_SGBM(bool)));
        QObject::connect(horizontalSlider_uniradio, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_uniradio(int)));
        QObject::connect(horizontalSlider_prefilcap, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_Prefilcap(int)));
        QObject::connect(horizontalSlider_specwinsz, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_specwinsz(int)));
        QObject::connect(horizontalSlider_SadWinSiz, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SadWinSize(int)));
        QObject::connect(horizontalSlider_MinDisp, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_MinDisp(int)));
        QObject::connect(horizontalSlider_NumDisparities, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_NumDisparities(int)));
        QObject::connect(horizontalSlider_specrange, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_Specrange(int)));
        QObject::connect(horizontalSlider_maxdifdisp12, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_MaxDifdisp2(int)));
        QObject::connect(horizontalSlider_textThread, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_TextThread(int)));
        QObject::connect(horizontalSlider_NumDisparities, SIGNAL(sliderReleased()), MatcherView, SLOT(onReleased_NumDisparities()));
        QObject::connect(horizontalSlider_NumDisparities, SIGNAL(sliderPressed()), MatcherView, SLOT(onReleased_NumDisparities()));
        QObject::connect(horizontalSlider_SadWinSiz, SIGNAL(sliderPressed()), MatcherView, SLOT(onReleased_SadWinSize()));
        QObject::connect(horizontalSlider_SadWinSiz, SIGNAL(sliderReleased()), MatcherView, SLOT(onReleased_SadWinSize()));
        QObject::connect(radioButton_ImageL, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_IconImgL(bool)));
        QObject::connect(radioButton_ImageR, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_IconImgR(bool)));
        QObject::connect(radioButton_RawDisp, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_IconRawDisp(bool)));
        QObject::connect(radioButton_FixDisp, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_IconFixDisp(bool)));
        QObject::connect(radioButton_BM, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_BM(bool)));
        QObject::connect(radioButton_SGBM, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_SGBM(bool)));

        QMetaObject::connectSlotsByName(MatcherView);
    } // setupUi

    void retranslateUi(QWidget *MatcherView)
    {
        MatcherView->setWindowTitle(QApplication::translate("MatcherView", "\345\214\271\351\205\215", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QApplication::translate("MatcherView", "\350\247\206\345\267\256\345\224\257\344\270\200\346\200\247\347\231\276\345\210\206\346\257\224", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MatcherView", "uniquenessRatio", nullptr));
        lineEdit_uniradio->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_2->setToolTip(QApplication::translate("MatcherView", "\345\211\215\347\275\256\346\273\244\346\263\242\345\231\250\346\210\252\346\226\255\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("MatcherView", "preFilterCap", nullptr));
        lineEdit_prefilcap->setPlaceholderText(QApplication::translate("MatcherView", "1", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_3->setToolTip(QApplication::translate("MatcherView", "SAD\347\252\227\345\217\243\345\244\247\345\260\217", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_3->setTitle(QApplication::translate("MatcherView", "SADWindowSize", nullptr));
        lineEdit_SadWinSiz->setPlaceholderText(QApplication::translate("MatcherView", "5", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_4->setToolTip(QApplication::translate("MatcherView", "\350\247\206\345\267\256\350\277\236\351\200\232\345\214\272\345\237\237\345\217\230\345\214\226\345\272\246\347\232\204\347\252\227\345\217\243\345\244\247\345\260\217", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_4->setTitle(QApplication::translate("MatcherView", "SpeckleWindowSize", nullptr));
        lineEdit_specwinsz->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_5->setToolTip(QApplication::translate("MatcherView", "\346\234\200\345\260\217\350\247\206\345\267\256\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_5->setTitle(QApplication::translate("MatcherView", "minDisparity", nullptr));
        lineEdit_MinDisp->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_6->setToolTip(QApplication::translate("MatcherView", "\350\247\206\345\267\256\347\252\227\345\217\243\345\244\247\345\260\217", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_6->setTitle(QApplication::translate("MatcherView", "numDisparities", nullptr));
        lineEdit_NumDisparities->setPlaceholderText(QApplication::translate("MatcherView", "16", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_7->setToolTip(QApplication::translate("MatcherView", "\350\277\236\351\200\232\345\214\272\345\237\237\345\206\205\347\232\204\346\234\200\345\244\247\350\247\206\345\267\256\345\217\230\345\214\226", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_7->setTitle(QApplication::translate("MatcherView", "speckleRange", nullptr));
        lineEdit_specrange->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_10->setToolTip(QApplication::translate("MatcherView", "\345\267\246\345\217\263\350\247\206\345\267\256\345\233\276\347\232\204\346\234\200\345\244\247\345\256\271\350\256\270\345\267\256\345\274\202", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_10->setTitle(QApplication::translate("MatcherView", "disp12MaxDiff", nullptr));
        lineEdit_maxdifdisp12->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBox_11->setToolTip(QApplication::translate("MatcherView", "\344\275\216\347\272\271\347\220\206\345\214\272\345\237\237\347\232\204\345\210\244\346\226\255\351\230\210\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_11->setTitle(QApplication::translate("MatcherView", "TextureThreshold", nullptr));
        lineEdit_textThread->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
        radioButton_ImageL->setText(QApplication::translate("MatcherView", "\345\267\246\350\247\206\345\233\276", nullptr));
        radioButton_ImageR->setText(QApplication::translate("MatcherView", "\345\217\263\350\247\206\345\233\276", nullptr));
        radioButton_RawDisp->setText(QApplication::translate("MatcherView", "\345\216\237\345\247\213\350\247\206\345\267\256\345\233\276", nullptr));
        radioButton_FixDisp->setText(QApplication::translate("MatcherView", "\344\277\256\345\244\215\350\247\206\345\267\256\345\233\276", nullptr));
        radioButton_BM->setText(QApplication::translate("MatcherView", "BM", nullptr));
        radioButton_SGBM->setText(QApplication::translate("MatcherView", "SGBM", nullptr));
        radioButton_MODE_3WAY->setText(QApplication::translate("MatcherView", "3WAY", nullptr));
        radioButton_MODE_SGBM->setText(QApplication::translate("MatcherView", "SGBM", nullptr));
        radioButton_MODE_HH->setText(QApplication::translate("MatcherView", "HH", nullptr));
        checkBox_DoRectify->setText(QApplication::translate("MatcherView", "\350\277\233\350\241\214\346\240\241\346\255\243", nullptr));
        pushButton_MatchDefault->setText(QApplication::translate("MatcherView", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        pushButton_MatchChooseFiles->setText(QApplication::translate("MatcherView", "\345\217\214\347\233\256\345\214\271\351\205\215", nullptr));
        pushButton_RefreshStereoMatch->setText(QApplication::translate("MatcherView", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatcherView: public Ui_MatcherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHERVIEW_H
