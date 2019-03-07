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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatcherView
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsView_ImageL;
    QRadioButton *radioButton_ImageL;
    QGraphicsView *graphicsView_ImageR;
    QRadioButton *radioButton_ImageR;
    QGraphicsView *graphicsView_RawDisp;
    QRadioButton *radioButton_RawDisp;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView_D;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_12;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_BM;
    QRadioButton *radioButton_SGBM;
    QRadioButton *radioButton_ELAS;
    QRadioButton *radioButton_ADC;
    QFrame *line;
    QCheckBox *checkBox_RectifiedInput;
    QFrame *line_3;
    QPushButton *pushButton_MatchDefault;
    QPushButton *pushButton_MatchChooseFiles;
    QPushButton *pushButton_RefreshStereoMatch;
    QPushButton *pushButton_Save;
    QPushButton *pushButton_Help;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page_opencv;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_uniradio;
    QSlider *horizontalSlider_uniradio;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_prefilcap;
    QSlider *horizontalSlider_prefilcap;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_maxdifdisp12;
    QSlider *horizontalSlider_maxdifdisp12;
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
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_textThread;
    QSlider *horizontalSlider_textThread;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *lineEdit_NumDisparities;
    QSlider *horizontalSlider_NumDisparities;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_specrange;
    QSlider *horizontalSlider_specrange;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_MODE_3WAY;
    QRadioButton *radioButton_MODE_SGBM;
    QRadioButton *radioButton_MODE_HH;
    QWidget *page_ELAS;
    QLabel *label_24;
    QWidget *page_ADCensus;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_18;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label;
    QSpinBox *spinBox_dMin;
    QLabel *label_2;
    QSpinBox *spinBox_dMax;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_4;
    QLabel *label_11;
    QLabel *label_8;
    QSpinBox *spinBox_aggregatingIterations;
    QSpinBox *spinBox_maxLength2;
    QLabel *label_9;
    QLabel *label_12;
    QSpinBox *spinBox_colorThreshold1;
    QSpinBox *spinBox_maxLength1;
    QLabel *label_10;
    QSpinBox *spinBox_colorThreshold2;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QSpinBox *spinBox_colorDifference;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_pi1;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_pi2;
    QGroupBox *groupBox_14;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_16;
    QSpinBox *spinBox_dispTolerance;
    QGroupBox *groupBox_15;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_19;
    QSpinBox *spinBox_maxSearchDepth;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_17;
    QSpinBox *spinBox_votingThreshold;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_votingRatioThreshold;
    QGroupBox *groupBox_16;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_22;
    QSpinBox *spinBox_cannyKernelSize;
    QLabel *label_20;
    QSpinBox *spinBox_cannyThreshold1;
    QLabel *label_21;
    QSpinBox *spinBox_cannyThreshold2;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_3;
    QDoubleSpinBox *doubleSpinBox_lambdaAD;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_defaultBorderCost;
    QSpinBox *spinBox_censusWinW;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_lambdaCensus;
    QSpinBox *spinBox_censusWinH;
    QGroupBox *groupBox_17;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_23;
    QSpinBox *spinBox_blurKernelSize;

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
        gridLayout_2 = new QGridLayout(MatcherView);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
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
        radioButton_ImageL->setAutoExclusive(true);

        verticalLayout_3->addWidget(radioButton_ImageL);

        graphicsView_ImageR = new QGraphicsView(frame_2);
        graphicsView_ImageR->setObjectName(QString::fromUtf8("graphicsView_ImageR"));
        graphicsView_ImageR->setMaximumSize(QSize(133, 100));

        verticalLayout_3->addWidget(graphicsView_ImageR);

        radioButton_ImageR = new QRadioButton(frame_2);
        radioButton_ImageR->setObjectName(QString::fromUtf8("radioButton_ImageR"));
        radioButton_ImageR->setAutoExclusive(true);

        verticalLayout_3->addWidget(radioButton_ImageR);

        graphicsView_RawDisp = new QGraphicsView(frame_2);
        graphicsView_RawDisp->setObjectName(QString::fromUtf8("graphicsView_RawDisp"));
        graphicsView_RawDisp->setMaximumSize(QSize(133, 100));

        verticalLayout_3->addWidget(graphicsView_RawDisp);

        radioButton_RawDisp = new QRadioButton(frame_2);
        radioButton_RawDisp->setObjectName(QString::fromUtf8("radioButton_RawDisp"));
        radioButton_RawDisp->setAutoExclusive(true);

        verticalLayout_3->addWidget(radioButton_RawDisp);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout_2->addWidget(frame_2, 0, 0, 2, 1);

        graphicsView_D = new QGraphicsView(MatcherView);
        graphicsView_D->setObjectName(QString::fromUtf8("graphicsView_D"));
        graphicsView_D->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(graphicsView_D, 1, 1, 1, 1);

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

        radioButton_ELAS = new QRadioButton(frame_8);
        radioButton_ELAS->setObjectName(QString::fromUtf8("radioButton_ELAS"));

        horizontalLayout->addWidget(radioButton_ELAS);

        radioButton_ADC = new QRadioButton(frame_8);
        radioButton_ADC->setObjectName(QString::fromUtf8("radioButton_ADC"));

        horizontalLayout->addWidget(radioButton_ADC);


        horizontalLayout_12->addWidget(frame_8);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line);

        checkBox_RectifiedInput = new QCheckBox(frame);
        checkBox_RectifiedInput->setObjectName(QString::fromUtf8("checkBox_RectifiedInput"));

        horizontalLayout_12->addWidget(checkBox_RectifiedInput);

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

        pushButton_Save = new QPushButton(frame);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        horizontalLayout_12->addWidget(pushButton_Save);

        pushButton_Help = new QPushButton(frame);
        pushButton_Help->setObjectName(QString::fromUtf8("pushButton_Help"));

        horizontalLayout_12->addWidget(pushButton_Help);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        gridLayout_2->addWidget(frame, 0, 1, 1, 2);

        stackedWidget = new QStackedWidget(MatcherView);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(300, 16777215));
        stackedWidget->setFrameShape(QFrame::Box);
        page_opencv = new QWidget();
        page_opencv->setObjectName(QString::fromUtf8("page_opencv"));
        gridLayout = new QGridLayout(page_opencv);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 1);

        groupBox_10 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_10, 8, 0, 1, 1);

        groupBox_3 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_3, 3, 0, 1, 1);

        groupBox_4 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_4, 4, 0, 1, 1);

        groupBox_5 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_5, 5, 0, 1, 1);

        groupBox_11 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_11, 9, 0, 1, 1);

        groupBox_6 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_6, 6, 0, 1, 1);

        groupBox_7 = new QGroupBox(page_opencv);
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


        gridLayout->addWidget(groupBox_7, 7, 0, 1, 1);

        frame_4 = new QFrame(page_opencv);
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


        gridLayout->addWidget(frame_4, 0, 0, 1, 1);

        stackedWidget->addWidget(page_opencv);
        page_ELAS = new QWidget();
        page_ELAS->setObjectName(QString::fromUtf8("page_ELAS"));
        label_24 = new QLabel(page_ELAS);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(120, 0, 48, 16));
        stackedWidget->addWidget(page_ELAS);
        page_ADCensus = new QWidget();
        page_ADCensus->setObjectName(QString::fromUtf8("page_ADCensus"));
        gridLayout_5 = new QGridLayout(page_ADCensus);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_18 = new QGroupBox(page_ADCensus);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        horizontalLayout_19 = new QHBoxLayout(groupBox_18);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(-1, 3, -1, 3);
        label = new QLabel(groupBox_18);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_19->addWidget(label);

        spinBox_dMin = new QSpinBox(groupBox_18);
        spinBox_dMin->setObjectName(QString::fromUtf8("spinBox_dMin"));
        spinBox_dMin->setMaximum(100);

        horizontalLayout_19->addWidget(spinBox_dMin);

        label_2 = new QLabel(groupBox_18);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_19->addWidget(label_2);

        spinBox_dMax = new QSpinBox(groupBox_18);
        spinBox_dMax->setObjectName(QString::fromUtf8("spinBox_dMax"));
        spinBox_dMax->setMaximum(100);

        horizontalLayout_19->addWidget(spinBox_dMax);


        gridLayout_5->addWidget(groupBox_18, 0, 0, 1, 2);

        groupBox_9 = new QGroupBox(page_ADCensus);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_4 = new QGridLayout(groupBox_9);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 3, -1, 3);
        label_11 = new QLabel(groupBox_9);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 0, 0, 1, 2);

        label_8 = new QLabel(groupBox_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 5, 0, 1, 1);

        spinBox_aggregatingIterations = new QSpinBox(groupBox_9);
        spinBox_aggregatingIterations->setObjectName(QString::fromUtf8("spinBox_aggregatingIterations"));

        gridLayout_4->addWidget(spinBox_aggregatingIterations, 5, 2, 1, 1);

        spinBox_maxLength2 = new QSpinBox(groupBox_9);
        spinBox_maxLength2->setObjectName(QString::fromUtf8("spinBox_maxLength2"));

        gridLayout_4->addWidget(spinBox_maxLength2, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 3, 1, 2);

        label_12 = new QLabel(groupBox_9);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 1, 0, 1, 2);

        spinBox_colorThreshold1 = new QSpinBox(groupBox_9);
        spinBox_colorThreshold1->setObjectName(QString::fromUtf8("spinBox_colorThreshold1"));

        gridLayout_4->addWidget(spinBox_colorThreshold1, 0, 6, 1, 1);

        spinBox_maxLength1 = new QSpinBox(groupBox_9);
        spinBox_maxLength1->setObjectName(QString::fromUtf8("spinBox_maxLength1"));

        gridLayout_4->addWidget(spinBox_maxLength1, 0, 2, 1, 1);

        label_10 = new QLabel(groupBox_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 3, 1, 3);

        spinBox_colorThreshold2 = new QSpinBox(groupBox_9);
        spinBox_colorThreshold2->setObjectName(QString::fromUtf8("spinBox_colorThreshold2"));

        gridLayout_4->addWidget(spinBox_colorThreshold2, 1, 6, 1, 1);


        gridLayout_5->addWidget(groupBox_9, 2, 0, 1, 2);

        groupBox_12 = new QGroupBox(page_ADCensus);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_12);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, 3, -1, 3);
        label_13 = new QLabel(groupBox_12);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_13->addWidget(label_13);

        spinBox_colorDifference = new QSpinBox(groupBox_12);
        spinBox_colorDifference->setObjectName(QString::fromUtf8("spinBox_colorDifference"));

        horizontalLayout_13->addWidget(spinBox_colorDifference);

        label_15 = new QLabel(groupBox_12);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_13->addWidget(label_15);

        doubleSpinBox_pi1 = new QDoubleSpinBox(groupBox_12);
        doubleSpinBox_pi1->setObjectName(QString::fromUtf8("doubleSpinBox_pi1"));

        horizontalLayout_13->addWidget(doubleSpinBox_pi1);

        label_14 = new QLabel(groupBox_12);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_13->addWidget(label_14);

        doubleSpinBox_pi2 = new QDoubleSpinBox(groupBox_12);
        doubleSpinBox_pi2->setObjectName(QString::fromUtf8("doubleSpinBox_pi2"));

        horizontalLayout_13->addWidget(doubleSpinBox_pi2);


        gridLayout_5->addWidget(groupBox_12, 3, 0, 1, 2);

        groupBox_14 = new QGroupBox(page_ADCensus);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        horizontalLayout_15 = new QHBoxLayout(groupBox_14);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(-1, 3, -1, 3);
        label_16 = new QLabel(groupBox_14);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_15->addWidget(label_16);

        spinBox_dispTolerance = new QSpinBox(groupBox_14);
        spinBox_dispTolerance->setObjectName(QString::fromUtf8("spinBox_dispTolerance"));

        horizontalLayout_15->addWidget(spinBox_dispTolerance);


        gridLayout_5->addWidget(groupBox_14, 4, 0, 1, 1);

        groupBox_15 = new QGroupBox(page_ADCensus);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        horizontalLayout_16 = new QHBoxLayout(groupBox_15);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(-1, 3, -1, 3);
        label_19 = new QLabel(groupBox_15);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_16->addWidget(label_19);

        spinBox_maxSearchDepth = new QSpinBox(groupBox_15);
        spinBox_maxSearchDepth->setObjectName(QString::fromUtf8("spinBox_maxSearchDepth"));

        horizontalLayout_16->addWidget(spinBox_maxSearchDepth);


        gridLayout_5->addWidget(groupBox_15, 4, 1, 1, 1);

        groupBox_13 = new QGroupBox(page_ADCensus);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        horizontalLayout_14 = new QHBoxLayout(groupBox_13);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(-1, 3, -1, 3);
        label_17 = new QLabel(groupBox_13);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_14->addWidget(label_17);

        spinBox_votingThreshold = new QSpinBox(groupBox_13);
        spinBox_votingThreshold->setObjectName(QString::fromUtf8("spinBox_votingThreshold"));

        horizontalLayout_14->addWidget(spinBox_votingThreshold);

        label_18 = new QLabel(groupBox_13);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_14->addWidget(label_18);

        doubleSpinBox_votingRatioThreshold = new QDoubleSpinBox(groupBox_13);
        doubleSpinBox_votingRatioThreshold->setObjectName(QString::fromUtf8("doubleSpinBox_votingRatioThreshold"));

        horizontalLayout_14->addWidget(doubleSpinBox_votingRatioThreshold);


        gridLayout_5->addWidget(groupBox_13, 5, 0, 1, 2);

        groupBox_16 = new QGroupBox(page_ADCensus);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        horizontalLayout_17 = new QHBoxLayout(groupBox_16);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(-1, 3, -1, 3);
        label_22 = new QLabel(groupBox_16);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_17->addWidget(label_22);

        spinBox_cannyKernelSize = new QSpinBox(groupBox_16);
        spinBox_cannyKernelSize->setObjectName(QString::fromUtf8("spinBox_cannyKernelSize"));

        horizontalLayout_17->addWidget(spinBox_cannyKernelSize);

        label_20 = new QLabel(groupBox_16);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_17->addWidget(label_20);

        spinBox_cannyThreshold1 = new QSpinBox(groupBox_16);
        spinBox_cannyThreshold1->setObjectName(QString::fromUtf8("spinBox_cannyThreshold1"));

        horizontalLayout_17->addWidget(spinBox_cannyThreshold1);

        label_21 = new QLabel(groupBox_16);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_17->addWidget(label_21);

        spinBox_cannyThreshold2 = new QSpinBox(groupBox_16);
        spinBox_cannyThreshold2->setObjectName(QString::fromUtf8("spinBox_cannyThreshold2"));

        horizontalLayout_17->addWidget(spinBox_cannyThreshold2);


        gridLayout_5->addWidget(groupBox_16, 6, 0, 1, 2);

        groupBox_8 = new QGroupBox(page_ADCensus);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_3 = new QGridLayout(groupBox_8);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 3, -1, 3);
        doubleSpinBox_lambdaAD = new QDoubleSpinBox(groupBox_8);
        doubleSpinBox_lambdaAD->setObjectName(QString::fromUtf8("doubleSpinBox_lambdaAD"));

        gridLayout_3->addWidget(doubleSpinBox_lambdaAD, 1, 3, 1, 1);

        label_6 = new QLabel(groupBox_8);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 2, 1, 1);

        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 2);

        label_3 = new QLabel(groupBox_8);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        doubleSpinBox_defaultBorderCost = new QDoubleSpinBox(groupBox_8);
        doubleSpinBox_defaultBorderCost->setObjectName(QString::fromUtf8("doubleSpinBox_defaultBorderCost"));
        doubleSpinBox_defaultBorderCost->setDecimals(3);
        doubleSpinBox_defaultBorderCost->setMaximum(9.999000000000001);
        doubleSpinBox_defaultBorderCost->setSingleStep(0.001000000000000);

        gridLayout_3->addWidget(doubleSpinBox_defaultBorderCost, 3, 2, 1, 2);

        spinBox_censusWinW = new QSpinBox(groupBox_8);
        spinBox_censusWinW->setObjectName(QString::fromUtf8("spinBox_censusWinW"));

        gridLayout_3->addWidget(spinBox_censusWinW, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBox_lambdaCensus = new QDoubleSpinBox(groupBox_8);
        doubleSpinBox_lambdaCensus->setObjectName(QString::fromUtf8("doubleSpinBox_lambdaCensus"));

        gridLayout_3->addWidget(doubleSpinBox_lambdaCensus, 0, 3, 1, 1);

        spinBox_censusWinH = new QSpinBox(groupBox_8);
        spinBox_censusWinH->setObjectName(QString::fromUtf8("spinBox_censusWinH"));

        gridLayout_3->addWidget(spinBox_censusWinH, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_8, 1, 0, 1, 2);

        groupBox_17 = new QGroupBox(page_ADCensus);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        horizontalLayout_18 = new QHBoxLayout(groupBox_17);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(-1, 3, -1, 3);
        label_23 = new QLabel(groupBox_17);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_18->addWidget(label_23);

        spinBox_blurKernelSize = new QSpinBox(groupBox_17);
        spinBox_blurKernelSize->setObjectName(QString::fromUtf8("spinBox_blurKernelSize"));

        horizontalLayout_18->addWidget(spinBox_blurKernelSize);


        gridLayout_5->addWidget(groupBox_17, 7, 0, 1, 2);

        stackedWidget->addWidget(page_ADCensus);

        gridLayout_2->addWidget(stackedWidget, 1, 2, 1, 1);


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
        QObject::connect(radioButton_BM, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_BM(bool)));
        QObject::connect(radioButton_SGBM, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_SGBM(bool)));
        QObject::connect(radioButton_ELAS, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_ELAS(bool)));
        QObject::connect(radioButton_ADC, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_ADCensus(bool)));
        QObject::connect(checkBox_RectifiedInput, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_RectifiedInput(bool)));
        QObject::connect(pushButton_Save, SIGNAL(clicked()), MatcherView, SLOT(SaveDisparities()));
        QObject::connect(pushButton_Help, SIGNAL(clicked()), MatcherView, SLOT(Help()));
        QObject::connect(spinBox_dMin, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_DMin(int)));
        QObject::connect(spinBox_dMax, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_DMax(int)));
        QObject::connect(spinBox_censusWinW, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_CensusWinW(int)));
        QObject::connect(spinBox_censusWinH, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_CensusWinH(int)));
        QObject::connect(doubleSpinBox_lambdaCensus, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_LambdaCensus(double)));
        QObject::connect(doubleSpinBox_lambdaAD, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_LambdaAD(double)));
        QObject::connect(doubleSpinBox_defaultBorderCost, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_DefaultBorderCost(double)));
        QObject::connect(spinBox_maxLength1, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_MaxLength1(int)));
        QObject::connect(spinBox_maxLength2, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_MaxLength2(int)));
        QObject::connect(spinBox_aggregatingIterations, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_AggregatingIterations(int)));
        QObject::connect(spinBox_colorThreshold1, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_ColorThreshold1(int)));
        QObject::connect(spinBox_colorThreshold2, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_ColorThreshold2(int)));
        QObject::connect(spinBox_colorDifference, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_ColorDifference(int)));
        QObject::connect(doubleSpinBox_pi1, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_Pi1(double)));
        QObject::connect(doubleSpinBox_pi2, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_Pi2(double)));
        QObject::connect(spinBox_dispTolerance, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_DispTolerance(int)));
        QObject::connect(spinBox_maxSearchDepth, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_MaxSearchDepth(int)));
        QObject::connect(spinBox_votingThreshold, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_VotingThreshold(int)));
        QObject::connect(doubleSpinBox_votingRatioThreshold, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_VotingRatioThreshold(double)));
        QObject::connect(spinBox_cannyKernelSize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_CannyKernelSize(int)));
        QObject::connect(spinBox_cannyThreshold1, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_CannyThreshold1(int)));
        QObject::connect(spinBox_cannyThreshold2, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_CannyThreshold2(int)));
        QObject::connect(spinBox_blurKernelSize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BlurKernelSize(int)));

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MatcherView);
    } // setupUi

    void retranslateUi(QWidget *MatcherView)
    {
        MatcherView->setWindowTitle(QApplication::translate("MatcherView", "\345\214\271\351\205\215", nullptr));
        radioButton_ImageL->setText(QApplication::translate("MatcherView", "\345\267\246\350\247\206\345\233\276", nullptr));
        radioButton_ImageR->setText(QApplication::translate("MatcherView", "\345\217\263\350\247\206\345\233\276", nullptr));
        radioButton_RawDisp->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\345\233\276", nullptr));
        radioButton_BM->setText(QApplication::translate("MatcherView", "BM", nullptr));
        radioButton_SGBM->setText(QApplication::translate("MatcherView", "SGBM", nullptr));
        radioButton_ELAS->setText(QApplication::translate("MatcherView", "ELAS", nullptr));
        radioButton_ADC->setText(QApplication::translate("MatcherView", "ADCensus", nullptr));
        checkBox_RectifiedInput->setText(QApplication::translate("MatcherView", "\350\276\223\345\205\245\346\240\241\346\255\243\345\245\275\347\232\204\345\233\276\347\211\207", nullptr));
        pushButton_MatchDefault->setText(QApplication::translate("MatcherView", "\351\273\230\350\256\244\345\217\202\346\225\260", nullptr));
        pushButton_MatchChooseFiles->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\350\256\241\347\256\227", nullptr));
        pushButton_RefreshStereoMatch->setText(QApplication::translate("MatcherView", "\345\210\267\346\226\260", nullptr));
        pushButton_Save->setText(QApplication::translate("MatcherView", "\344\277\235\345\255\230\350\247\206\345\267\256\346\225\260\346\215\256\345\222\214\350\247\206\345\267\256\347\244\272\346\204\217\345\233\276", nullptr));
        pushButton_Help->setText(QApplication::translate("MatcherView", "\345\270\256\345\212\251\344\277\241\346\201\257", nullptr));
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
        groupBox_10->setToolTip(QApplication::translate("MatcherView", "\345\267\246\345\217\263\350\247\206\345\267\256\345\233\276\347\232\204\346\234\200\345\244\247\345\256\271\350\256\270\345\267\256\345\274\202", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_10->setTitle(QApplication::translate("MatcherView", "disp12MaxDiff", nullptr));
        lineEdit_maxdifdisp12->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
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
        groupBox_11->setToolTip(QApplication::translate("MatcherView", "\344\275\216\347\272\271\347\220\206\345\214\272\345\237\237\347\232\204\345\210\244\346\226\255\351\230\210\345\200\274", nullptr));
#endif // QT_NO_TOOLTIP
        groupBox_11->setTitle(QApplication::translate("MatcherView", "TextureThreshold", nullptr));
        lineEdit_textThread->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
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
        radioButton_MODE_3WAY->setText(QApplication::translate("MatcherView", "3WAY", nullptr));
        radioButton_MODE_SGBM->setText(QApplication::translate("MatcherView", "SGBM", nullptr));
        radioButton_MODE_HH->setText(QApplication::translate("MatcherView", "HH", nullptr));
        label_24->setText(QApplication::translate("MatcherView", "\346\225\254\350\257\267\346\234\237\345\276\205", nullptr));
        groupBox_18->setTitle(QApplication::translate("MatcherView", "\350\247\206\345\267\256", nullptr));
        label->setText(QApplication::translate("MatcherView", "\346\234\200\345\260\217\350\247\206\345\267\256", nullptr));
        label_2->setText(QApplication::translate("MatcherView", "\346\234\200\345\244\247\350\247\206\345\267\256", nullptr));
        groupBox_9->setTitle(QApplication::translate("MatcherView", "Cross-based\344\273\243\344\273\267\350\201\232\345\220\210", nullptr));
        label_11->setText(QApplication::translate("MatcherView", "\346\234\200\345\244\247\351\225\277\345\272\2461", nullptr));
        label_8->setText(QApplication::translate("MatcherView", "\350\201\232\345\220\210\350\277\255\344\273\243\346\225\260", nullptr));
        label_9->setText(QApplication::translate("MatcherView", "\351\242\234\350\211\262\351\230\210\345\200\2742", nullptr));
        label_12->setText(QApplication::translate("MatcherView", "\346\234\200\345\244\247\351\225\277\345\272\2462", nullptr));
        label_10->setText(QApplication::translate("MatcherView", "\351\242\234\350\211\262\351\230\210\345\200\2741", nullptr));
        groupBox_12->setTitle(QApplication::translate("MatcherView", "\345\233\276\345\203\217\345\215\225\345\205\203\344\274\230\345\214\226", nullptr));
        label_13->setText(QApplication::translate("MatcherView", "\350\211\262\345\267\256", nullptr));
        label_15->setText(QApplication::translate("MatcherView", "pi1", nullptr));
        label_14->setText(QApplication::translate("MatcherView", "pi2", nullptr));
        groupBox_14->setTitle(QApplication::translate("MatcherView", "\347\246\273\347\276\244\347\202\271\346\243\200\346\265\213", nullptr));
        label_16->setText(QApplication::translate("MatcherView", "dispTolerance", nullptr));
        groupBox_15->setTitle(QApplication::translate("MatcherView", "\346\217\222\345\200\274", nullptr));
        label_19->setText(QApplication::translate("MatcherView", "\346\220\234\347\264\242\346\267\261\345\272\246", nullptr));
        groupBox_13->setTitle(QApplication::translate("MatcherView", "\350\277\255\344\273\243\345\214\272\345\237\237\346\212\225\347\245\250", nullptr));
        label_17->setText(QApplication::translate("MatcherView", "\346\212\225\347\245\250\351\230\210\345\200\274", nullptr));
        label_18->setText(QApplication::translate("MatcherView", "\346\212\225\347\245\250\347\216\207\351\230\210\345\200\274", nullptr));
        groupBox_16->setTitle(QApplication::translate("MatcherView", "\346\267\261\345\272\246\344\270\215\350\277\236\347\273\255\346\200\247", nullptr));
        label_22->setText(QApplication::translate("MatcherView", "canny\346\240\270", nullptr));
        label_20->setText(QApplication::translate("MatcherView", "\351\230\210\345\200\2741", nullptr));
        label_21->setText(QApplication::translate("MatcherView", "\351\230\210\345\200\2742", nullptr));
        groupBox_8->setTitle(QApplication::translate("MatcherView", "\344\273\243\344\273\267\345\210\235\345\247\213\345\214\226", nullptr));
        label_6->setText(QApplication::translate("MatcherView", "AD\346\235\203\351\207\215", nullptr));
        label_7->setText(QApplication::translate("MatcherView", "Census\346\235\203\351\207\215", nullptr));
        label_5->setText(QApplication::translate("MatcherView", "defaultBorderCost", nullptr));
        label_3->setText(QApplication::translate("MatcherView", "census\347\252\227\345\256\275", nullptr));
        label_4->setText(QApplication::translate("MatcherView", "census\347\252\227\351\253\230", nullptr));
        groupBox_17->setTitle(QApplication::translate("MatcherView", "\344\272\232\345\203\217\347\264\240\345\242\236\345\274\272", nullptr));
        label_23->setText(QApplication::translate("MatcherView", "blurKernelSize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatcherView: public Ui_MatcherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHERVIEW_H
