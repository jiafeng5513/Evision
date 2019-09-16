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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
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
    QStackedWidget *stackedWidget;
    QWidget *page_BM;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_19;
    QHBoxLayout *horizontalLayout_20;
    QRadioButton *radioButton_BM_Prefilter_Normalzed;
    QRadioButton *radioButton_BM_Prefilter_XSobel;
    QGroupBox *groupBox_20;
    QGridLayout *gridLayout_9;
    QLabel *label_24;
    QSpinBox *spinBox_BM_preFilterSize;
    QLabel *label_25;
    QSpinBox *spinBox_BM_preFilterCap;
    QGroupBox *groupBox_21;
    QGridLayout *gridLayout_10;
    QSpinBox *spinBox_BM_minDisparity;
    QLabel *label_26;
    QLabel *label_29;
    QSpinBox *spinBox_BM_textureThreshold;
    QLabel *label_28;
    QSpinBox *spinBox_BM_numDisparities;
    QSpinBox *spinBox_BM_SADWindowSize;
    QLabel *label_27;
    QLabel *label_30;
    QSpinBox *spinBox_BM_uniquenessRatio;
    QGroupBox *groupBox_22;
    QGridLayout *gridLayout_11;
    QLabel *label_31;
    QSpinBox *spinBox_BM_speckleWindowSize;
    QLabel *label_33;
    QSpinBox *spinBox_BM_speckleRange;
    QLabel *label_34;
    QSpinBox *spinBox_BM_disp12MaxDiff;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_SGBM;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_26;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_SGBM_MODEL_3WAY;
    QRadioButton *radioButton_SGBM_MODEL_HH4;
    QRadioButton *radioButton_SGBM_MODEL_Default;
    QRadioButton *radioButton_SGBM_MODEL_HH;
    QGroupBox *groupBox_23;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_35;
    QSpinBox *spinBox_SGBM_preFilterCap;
    QGroupBox *groupBox_24;
    QGridLayout *gridLayout_8;
    QLabel *label_36;
    QSpinBox *spinBox_SGBM_minDisparity;
    QLabel *label_37;
    QSpinBox *spinBox_SGBM_numDisparities;
    QLabel *label_38;
    QSpinBox *spinBox_SGBM_blockSize;
    QLabel *label_39;
    QSpinBox *spinBox_SGBM_P1;
    QLabel *label_40;
    QSpinBox *spinBox_SGBM_P2;
    QLabel *label_41;
    QSpinBox *spinBox_SGBM_uniquenessRatio;
    QGroupBox *groupBox_25;
    QGridLayout *gridLayout_12;
    QLabel *label_42;
    QSpinBox *spinBox_SGBM_speckleWindowSize;
    QLabel *label_43;
    QSpinBox *spinBox_SGBM_speckleRange;
    QLabel *label_44;
    QSpinBox *spinBox_SGBM_disp12MaxDiff;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_ELAS;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_7;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_32;
    QLabel *label_47;
    QSpinBox *spinBox_disp_max;
    QSpinBox *spinBox_disp_min;
    QLabel *label_48;
    QDoubleSpinBox *doubleSpinBox_support_threshold;
    QSpinBox *spinBox_support_texture;
    QLabel *label_49;
    QLabel *label_50;
    QSpinBox *spinBox_candidate_stepsize;
    QLabel *label_51;
    QSpinBox *spinBox_incon_window_size;
    QLabel *label_52;
    QSpinBox *spinBox_incon_threshold;
    QLabel *label_53;
    QSpinBox *spinBox_incon_min_support;
    QLabel *label_54;
    QSpinBox *spinBox_grid_size;
    QLabel *label_55;
    QDoubleSpinBox *doubleSpinBox_beta;
    QLabel *label_56;
    QDoubleSpinBox *doubleSpinBox_gamma;
    QLabel *label_57;
    QDoubleSpinBox *doubleSpinBox_sigma;
    QLabel *label_58;
    QDoubleSpinBox *doubleSpinBox_sradius;
    QLabel *label_59;
    QSpinBox *spinBox_match_texture;
    QSpinBox *spinBox_lr_threshold;
    QLabel *label_60;
    QLabel *label_61;
    QDoubleSpinBox *doubleSpinBox_speckle_sim_threshold;
    QSpinBox *spinBox_speckle_size;
    QSpinBox *spinBox_ipol_gap_width;
    QCheckBox *checkBox_add_corners;
    QCheckBox *checkBox_subsampling;
    QCheckBox *checkBox_postprocess_only_left;
    QCheckBox *checkBox_filter_adaptive_mean;
    QCheckBox *checkBox_filter_median;
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
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGraphicsView *graphicsView_ImageL;
    QRadioButton *radioButton_ImageL;
    QGraphicsView *graphicsView_ImageR;
    QRadioButton *radioButton_ImageR;
    QGraphicsView *graphicsView_RawDisp;
    QRadioButton *radioButton_RawDisp;
    QSpacerItem *verticalSpacer;

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
        stackedWidget = new QStackedWidget(MatcherView);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(300, 16777215));
        stackedWidget->setFrameShape(QFrame::Box);
        page_BM = new QWidget();
        page_BM->setObjectName(QString::fromUtf8("page_BM"));
        verticalLayout = new QVBoxLayout(page_BM);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_19 = new QGroupBox(page_BM);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        horizontalLayout_20 = new QHBoxLayout(groupBox_19);
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        radioButton_BM_Prefilter_Normalzed = new QRadioButton(groupBox_19);
        radioButton_BM_Prefilter_Normalzed->setObjectName(QString::fromUtf8("radioButton_BM_Prefilter_Normalzed"));

        horizontalLayout_20->addWidget(radioButton_BM_Prefilter_Normalzed);

        radioButton_BM_Prefilter_XSobel = new QRadioButton(groupBox_19);
        radioButton_BM_Prefilter_XSobel->setObjectName(QString::fromUtf8("radioButton_BM_Prefilter_XSobel"));

        horizontalLayout_20->addWidget(radioButton_BM_Prefilter_XSobel);


        verticalLayout->addWidget(groupBox_19);

        groupBox_20 = new QGroupBox(page_BM);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        gridLayout_9 = new QGridLayout(groupBox_20);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_24 = new QLabel(groupBox_20);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_9->addWidget(label_24, 0, 0, 1, 1);

        spinBox_BM_preFilterSize = new QSpinBox(groupBox_20);
        spinBox_BM_preFilterSize->setObjectName(QString::fromUtf8("spinBox_BM_preFilterSize"));
        spinBox_BM_preFilterSize->setMinimum(5);
        spinBox_BM_preFilterSize->setMaximum(255);
        spinBox_BM_preFilterSize->setSingleStep(2);

        gridLayout_9->addWidget(spinBox_BM_preFilterSize, 0, 1, 1, 1);

        label_25 = new QLabel(groupBox_20);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_9->addWidget(label_25, 1, 0, 1, 1);

        spinBox_BM_preFilterCap = new QSpinBox(groupBox_20);
        spinBox_BM_preFilterCap->setObjectName(QString::fromUtf8("spinBox_BM_preFilterCap"));
        spinBox_BM_preFilterCap->setMinimum(1);
        spinBox_BM_preFilterCap->setMaximum(63);

        gridLayout_9->addWidget(spinBox_BM_preFilterCap, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_20);

        groupBox_21 = new QGroupBox(page_BM);
        groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
        gridLayout_10 = new QGridLayout(groupBox_21);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        spinBox_BM_minDisparity = new QSpinBox(groupBox_21);
        spinBox_BM_minDisparity->setObjectName(QString::fromUtf8("spinBox_BM_minDisparity"));
        spinBox_BM_minDisparity->setMinimum(-1);
        spinBox_BM_minDisparity->setMaximum(128);

        gridLayout_10->addWidget(spinBox_BM_minDisparity, 1, 1, 1, 1);

        label_26 = new QLabel(groupBox_21);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_10->addWidget(label_26, 0, 0, 1, 1);

        label_29 = new QLabel(groupBox_21);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_10->addWidget(label_29, 3, 0, 1, 1);

        spinBox_BM_textureThreshold = new QSpinBox(groupBox_21);
        spinBox_BM_textureThreshold->setObjectName(QString::fromUtf8("spinBox_BM_textureThreshold"));

        gridLayout_10->addWidget(spinBox_BM_textureThreshold, 3, 1, 1, 1);

        label_28 = new QLabel(groupBox_21);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_10->addWidget(label_28, 2, 0, 1, 1);

        spinBox_BM_numDisparities = new QSpinBox(groupBox_21);
        spinBox_BM_numDisparities->setObjectName(QString::fromUtf8("spinBox_BM_numDisparities"));
        spinBox_BM_numDisparities->setMinimum(16);
        spinBox_BM_numDisparities->setMaximum(256);
        spinBox_BM_numDisparities->setSingleStep(16);

        gridLayout_10->addWidget(spinBox_BM_numDisparities, 2, 1, 1, 1);

        spinBox_BM_SADWindowSize = new QSpinBox(groupBox_21);
        spinBox_BM_SADWindowSize->setObjectName(QString::fromUtf8("spinBox_BM_SADWindowSize"));
        spinBox_BM_SADWindowSize->setMinimum(5);
        spinBox_BM_SADWindowSize->setMaximum(255);
        spinBox_BM_SADWindowSize->setSingleStep(2);

        gridLayout_10->addWidget(spinBox_BM_SADWindowSize, 0, 1, 1, 1);

        label_27 = new QLabel(groupBox_21);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_10->addWidget(label_27, 1, 0, 1, 1);

        label_30 = new QLabel(groupBox_21);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_10->addWidget(label_30, 4, 0, 1, 1);

        spinBox_BM_uniquenessRatio = new QSpinBox(groupBox_21);
        spinBox_BM_uniquenessRatio->setObjectName(QString::fromUtf8("spinBox_BM_uniquenessRatio"));

        gridLayout_10->addWidget(spinBox_BM_uniquenessRatio, 4, 1, 1, 1);


        verticalLayout->addWidget(groupBox_21);

        groupBox_22 = new QGroupBox(page_BM);
        groupBox_22->setObjectName(QString::fromUtf8("groupBox_22"));
        gridLayout_11 = new QGridLayout(groupBox_22);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_31 = new QLabel(groupBox_22);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_11->addWidget(label_31, 0, 0, 1, 1);

        spinBox_BM_speckleWindowSize = new QSpinBox(groupBox_22);
        spinBox_BM_speckleWindowSize->setObjectName(QString::fromUtf8("spinBox_BM_speckleWindowSize"));

        gridLayout_11->addWidget(spinBox_BM_speckleWindowSize, 0, 1, 1, 1);

        label_33 = new QLabel(groupBox_22);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_11->addWidget(label_33, 1, 0, 1, 1);

        spinBox_BM_speckleRange = new QSpinBox(groupBox_22);
        spinBox_BM_speckleRange->setObjectName(QString::fromUtf8("spinBox_BM_speckleRange"));

        gridLayout_11->addWidget(spinBox_BM_speckleRange, 1, 1, 1, 1);

        label_34 = new QLabel(groupBox_22);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_11->addWidget(label_34, 2, 0, 1, 1);

        spinBox_BM_disp12MaxDiff = new QSpinBox(groupBox_22);
        spinBox_BM_disp12MaxDiff->setObjectName(QString::fromUtf8("spinBox_BM_disp12MaxDiff"));
        spinBox_BM_disp12MaxDiff->setMinimum(-1);

        gridLayout_11->addWidget(spinBox_BM_disp12MaxDiff, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_22);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page_BM);
        page_SGBM = new QWidget();
        page_SGBM->setObjectName(QString::fromUtf8("page_SGBM"));
        verticalLayout_4 = new QVBoxLayout(page_SGBM);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_26 = new QGroupBox(page_SGBM);
        groupBox_26->setObjectName(QString::fromUtf8("groupBox_26"));
        verticalLayout_2 = new QVBoxLayout(groupBox_26);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton_SGBM_MODEL_3WAY = new QRadioButton(groupBox_26);
        radioButton_SGBM_MODEL_3WAY->setObjectName(QString::fromUtf8("radioButton_SGBM_MODEL_3WAY"));

        verticalLayout_2->addWidget(radioButton_SGBM_MODEL_3WAY);

        radioButton_SGBM_MODEL_HH4 = new QRadioButton(groupBox_26);
        radioButton_SGBM_MODEL_HH4->setObjectName(QString::fromUtf8("radioButton_SGBM_MODEL_HH4"));

        verticalLayout_2->addWidget(radioButton_SGBM_MODEL_HH4);

        radioButton_SGBM_MODEL_Default = new QRadioButton(groupBox_26);
        radioButton_SGBM_MODEL_Default->setObjectName(QString::fromUtf8("radioButton_SGBM_MODEL_Default"));

        verticalLayout_2->addWidget(radioButton_SGBM_MODEL_Default);

        radioButton_SGBM_MODEL_HH = new QRadioButton(groupBox_26);
        radioButton_SGBM_MODEL_HH->setObjectName(QString::fromUtf8("radioButton_SGBM_MODEL_HH"));

        verticalLayout_2->addWidget(radioButton_SGBM_MODEL_HH);


        verticalLayout_4->addWidget(groupBox_26);

        groupBox_23 = new QGroupBox(page_SGBM);
        groupBox_23->setObjectName(QString::fromUtf8("groupBox_23"));
        horizontalLayout_21 = new QHBoxLayout(groupBox_23);
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_35 = new QLabel(groupBox_23);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_21->addWidget(label_35);

        spinBox_SGBM_preFilterCap = new QSpinBox(groupBox_23);
        spinBox_SGBM_preFilterCap->setObjectName(QString::fromUtf8("spinBox_SGBM_preFilterCap"));

        horizontalLayout_21->addWidget(spinBox_SGBM_preFilterCap);


        verticalLayout_4->addWidget(groupBox_23);

        groupBox_24 = new QGroupBox(page_SGBM);
        groupBox_24->setObjectName(QString::fromUtf8("groupBox_24"));
        gridLayout_8 = new QGridLayout(groupBox_24);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_36 = new QLabel(groupBox_24);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_8->addWidget(label_36, 0, 0, 1, 1);

        spinBox_SGBM_minDisparity = new QSpinBox(groupBox_24);
        spinBox_SGBM_minDisparity->setObjectName(QString::fromUtf8("spinBox_SGBM_minDisparity"));

        gridLayout_8->addWidget(spinBox_SGBM_minDisparity, 0, 1, 1, 1);

        label_37 = new QLabel(groupBox_24);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_8->addWidget(label_37, 1, 0, 1, 1);

        spinBox_SGBM_numDisparities = new QSpinBox(groupBox_24);
        spinBox_SGBM_numDisparities->setObjectName(QString::fromUtf8("spinBox_SGBM_numDisparities"));
        spinBox_SGBM_numDisparities->setMinimum(1);
        spinBox_SGBM_numDisparities->setMaximum(256);

        gridLayout_8->addWidget(spinBox_SGBM_numDisparities, 1, 1, 1, 1);

        label_38 = new QLabel(groupBox_24);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_8->addWidget(label_38, 2, 0, 1, 1);

        spinBox_SGBM_blockSize = new QSpinBox(groupBox_24);
        spinBox_SGBM_blockSize->setObjectName(QString::fromUtf8("spinBox_SGBM_blockSize"));
        spinBox_SGBM_blockSize->setMinimum(1);
        spinBox_SGBM_blockSize->setSingleStep(2);

        gridLayout_8->addWidget(spinBox_SGBM_blockSize, 2, 1, 1, 1);

        label_39 = new QLabel(groupBox_24);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_8->addWidget(label_39, 3, 0, 1, 1);

        spinBox_SGBM_P1 = new QSpinBox(groupBox_24);
        spinBox_SGBM_P1->setObjectName(QString::fromUtf8("spinBox_SGBM_P1"));

        gridLayout_8->addWidget(spinBox_SGBM_P1, 3, 1, 1, 1);

        label_40 = new QLabel(groupBox_24);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_8->addWidget(label_40, 4, 0, 1, 1);

        spinBox_SGBM_P2 = new QSpinBox(groupBox_24);
        spinBox_SGBM_P2->setObjectName(QString::fromUtf8("spinBox_SGBM_P2"));

        gridLayout_8->addWidget(spinBox_SGBM_P2, 4, 1, 1, 1);

        label_41 = new QLabel(groupBox_24);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_8->addWidget(label_41, 5, 0, 1, 1);

        spinBox_SGBM_uniquenessRatio = new QSpinBox(groupBox_24);
        spinBox_SGBM_uniquenessRatio->setObjectName(QString::fromUtf8("spinBox_SGBM_uniquenessRatio"));

        gridLayout_8->addWidget(spinBox_SGBM_uniquenessRatio, 5, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_24);

        groupBox_25 = new QGroupBox(page_SGBM);
        groupBox_25->setObjectName(QString::fromUtf8("groupBox_25"));
        gridLayout_12 = new QGridLayout(groupBox_25);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_42 = new QLabel(groupBox_25);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_12->addWidget(label_42, 0, 0, 1, 1);

        spinBox_SGBM_speckleWindowSize = new QSpinBox(groupBox_25);
        spinBox_SGBM_speckleWindowSize->setObjectName(QString::fromUtf8("spinBox_SGBM_speckleWindowSize"));
        spinBox_SGBM_speckleWindowSize->setMinimum(50);
        spinBox_SGBM_speckleWindowSize->setMaximum(200);

        gridLayout_12->addWidget(spinBox_SGBM_speckleWindowSize, 0, 1, 1, 1);

        label_43 = new QLabel(groupBox_25);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_12->addWidget(label_43, 1, 0, 1, 1);

        spinBox_SGBM_speckleRange = new QSpinBox(groupBox_25);
        spinBox_SGBM_speckleRange->setObjectName(QString::fromUtf8("spinBox_SGBM_speckleRange"));

        gridLayout_12->addWidget(spinBox_SGBM_speckleRange, 1, 1, 1, 1);

        label_44 = new QLabel(groupBox_25);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_12->addWidget(label_44, 2, 0, 1, 1);

        spinBox_SGBM_disp12MaxDiff = new QSpinBox(groupBox_25);
        spinBox_SGBM_disp12MaxDiff->setObjectName(QString::fromUtf8("spinBox_SGBM_disp12MaxDiff"));

        gridLayout_12->addWidget(spinBox_SGBM_disp12MaxDiff, 2, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_25);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page_SGBM);
        page_ELAS = new QWidget();
        page_ELAS->setObjectName(QString::fromUtf8("page_ELAS"));
        gridLayout_6 = new QGridLayout(page_ELAS);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        scrollArea_2 = new QScrollArea(page_ELAS);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 261, 590));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_62 = new QLabel(scrollAreaWidgetContents_2);
        label_62->setObjectName(QString::fromUtf8("label_62"));

        gridLayout_7->addWidget(label_62, 32, 0, 1, 1);

        label_63 = new QLabel(scrollAreaWidgetContents_2);
        label_63->setObjectName(QString::fromUtf8("label_63"));

        gridLayout_7->addWidget(label_63, 33, 0, 1, 1);

        label_32 = new QLabel(scrollAreaWidgetContents_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_7->addWidget(label_32, 0, 0, 1, 1);

        label_47 = new QLabel(scrollAreaWidgetContents_2);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_7->addWidget(label_47, 1, 0, 1, 1);

        spinBox_disp_max = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_disp_max->setObjectName(QString::fromUtf8("spinBox_disp_max"));
        spinBox_disp_max->setMaximum(255);

        gridLayout_7->addWidget(spinBox_disp_max, 1, 1, 1, 1);

        spinBox_disp_min = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_disp_min->setObjectName(QString::fromUtf8("spinBox_disp_min"));
        spinBox_disp_min->setMaximum(255);

        gridLayout_7->addWidget(spinBox_disp_min, 0, 1, 1, 1);

        label_48 = new QLabel(scrollAreaWidgetContents_2);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_7->addWidget(label_48, 2, 0, 1, 1);

        doubleSpinBox_support_threshold = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_support_threshold->setObjectName(QString::fromUtf8("doubleSpinBox_support_threshold"));
        doubleSpinBox_support_threshold->setMaximum(10.000000000000000);
        doubleSpinBox_support_threshold->setSingleStep(0.010000000000000);

        gridLayout_7->addWidget(doubleSpinBox_support_threshold, 2, 1, 1, 1);

        spinBox_support_texture = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_support_texture->setObjectName(QString::fromUtf8("spinBox_support_texture"));

        gridLayout_7->addWidget(spinBox_support_texture, 3, 1, 1, 1);

        label_49 = new QLabel(scrollAreaWidgetContents_2);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_7->addWidget(label_49, 3, 0, 1, 1);

        label_50 = new QLabel(scrollAreaWidgetContents_2);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout_7->addWidget(label_50, 7, 0, 1, 1);

        spinBox_candidate_stepsize = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_candidate_stepsize->setObjectName(QString::fromUtf8("spinBox_candidate_stepsize"));

        gridLayout_7->addWidget(spinBox_candidate_stepsize, 7, 1, 1, 1);

        label_51 = new QLabel(scrollAreaWidgetContents_2);
        label_51->setObjectName(QString::fromUtf8("label_51"));

        gridLayout_7->addWidget(label_51, 9, 0, 1, 1);

        spinBox_incon_window_size = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_incon_window_size->setObjectName(QString::fromUtf8("spinBox_incon_window_size"));

        gridLayout_7->addWidget(spinBox_incon_window_size, 9, 1, 1, 1);

        label_52 = new QLabel(scrollAreaWidgetContents_2);
        label_52->setObjectName(QString::fromUtf8("label_52"));

        gridLayout_7->addWidget(label_52, 11, 0, 1, 1);

        spinBox_incon_threshold = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_incon_threshold->setObjectName(QString::fromUtf8("spinBox_incon_threshold"));

        gridLayout_7->addWidget(spinBox_incon_threshold, 11, 1, 1, 1);

        label_53 = new QLabel(scrollAreaWidgetContents_2);
        label_53->setObjectName(QString::fromUtf8("label_53"));

        gridLayout_7->addWidget(label_53, 13, 0, 1, 1);

        spinBox_incon_min_support = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_incon_min_support->setObjectName(QString::fromUtf8("spinBox_incon_min_support"));

        gridLayout_7->addWidget(spinBox_incon_min_support, 13, 1, 1, 1);

        label_54 = new QLabel(scrollAreaWidgetContents_2);
        label_54->setObjectName(QString::fromUtf8("label_54"));

        gridLayout_7->addWidget(label_54, 15, 0, 1, 1);

        spinBox_grid_size = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_grid_size->setObjectName(QString::fromUtf8("spinBox_grid_size"));

        gridLayout_7->addWidget(spinBox_grid_size, 15, 1, 1, 1);

        label_55 = new QLabel(scrollAreaWidgetContents_2);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        gridLayout_7->addWidget(label_55, 16, 0, 1, 1);

        doubleSpinBox_beta = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_beta->setObjectName(QString::fromUtf8("doubleSpinBox_beta"));
        doubleSpinBox_beta->setMaximum(10.000000000000000);
        doubleSpinBox_beta->setSingleStep(0.010000000000000);

        gridLayout_7->addWidget(doubleSpinBox_beta, 16, 1, 1, 1);

        label_56 = new QLabel(scrollAreaWidgetContents_2);
        label_56->setObjectName(QString::fromUtf8("label_56"));

        gridLayout_7->addWidget(label_56, 17, 0, 1, 1);

        doubleSpinBox_gamma = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_gamma->setObjectName(QString::fromUtf8("doubleSpinBox_gamma"));

        gridLayout_7->addWidget(doubleSpinBox_gamma, 17, 1, 1, 1);

        label_57 = new QLabel(scrollAreaWidgetContents_2);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        gridLayout_7->addWidget(label_57, 18, 0, 1, 1);

        doubleSpinBox_sigma = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_sigma->setObjectName(QString::fromUtf8("doubleSpinBox_sigma"));
        doubleSpinBox_sigma->setMaximum(10.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_sigma, 18, 1, 1, 1);

        label_58 = new QLabel(scrollAreaWidgetContents_2);
        label_58->setObjectName(QString::fromUtf8("label_58"));

        gridLayout_7->addWidget(label_58, 19, 0, 1, 1);

        doubleSpinBox_sradius = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_sradius->setObjectName(QString::fromUtf8("doubleSpinBox_sradius"));
        doubleSpinBox_sradius->setMaximum(10.000000000000000);

        gridLayout_7->addWidget(doubleSpinBox_sradius, 19, 1, 1, 1);

        label_59 = new QLabel(scrollAreaWidgetContents_2);
        label_59->setObjectName(QString::fromUtf8("label_59"));

        gridLayout_7->addWidget(label_59, 20, 0, 1, 1);

        spinBox_match_texture = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_match_texture->setObjectName(QString::fromUtf8("spinBox_match_texture"));

        gridLayout_7->addWidget(spinBox_match_texture, 20, 1, 1, 1);

        spinBox_lr_threshold = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_lr_threshold->setObjectName(QString::fromUtf8("spinBox_lr_threshold"));

        gridLayout_7->addWidget(spinBox_lr_threshold, 21, 1, 1, 1);

        label_60 = new QLabel(scrollAreaWidgetContents_2);
        label_60->setObjectName(QString::fromUtf8("label_60"));

        gridLayout_7->addWidget(label_60, 21, 0, 1, 1);

        label_61 = new QLabel(scrollAreaWidgetContents_2);
        label_61->setObjectName(QString::fromUtf8("label_61"));

        gridLayout_7->addWidget(label_61, 28, 0, 1, 1);

        doubleSpinBox_speckle_sim_threshold = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        doubleSpinBox_speckle_sim_threshold->setObjectName(QString::fromUtf8("doubleSpinBox_speckle_sim_threshold"));

        gridLayout_7->addWidget(doubleSpinBox_speckle_sim_threshold, 28, 1, 1, 1);

        spinBox_speckle_size = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_speckle_size->setObjectName(QString::fromUtf8("spinBox_speckle_size"));
        spinBox_speckle_size->setMaximum(1000);

        gridLayout_7->addWidget(spinBox_speckle_size, 32, 1, 1, 1);

        spinBox_ipol_gap_width = new QSpinBox(scrollAreaWidgetContents_2);
        spinBox_ipol_gap_width->setObjectName(QString::fromUtf8("spinBox_ipol_gap_width"));
        spinBox_ipol_gap_width->setMaximum(10000);

        gridLayout_7->addWidget(spinBox_ipol_gap_width, 33, 1, 1, 1);

        checkBox_add_corners = new QCheckBox(scrollAreaWidgetContents_2);
        checkBox_add_corners->setObjectName(QString::fromUtf8("checkBox_add_corners"));

        gridLayout_7->addWidget(checkBox_add_corners, 34, 0, 1, 1);

        checkBox_subsampling = new QCheckBox(scrollAreaWidgetContents_2);
        checkBox_subsampling->setObjectName(QString::fromUtf8("checkBox_subsampling"));

        gridLayout_7->addWidget(checkBox_subsampling, 35, 0, 1, 1);

        checkBox_postprocess_only_left = new QCheckBox(scrollAreaWidgetContents_2);
        checkBox_postprocess_only_left->setObjectName(QString::fromUtf8("checkBox_postprocess_only_left"));

        gridLayout_7->addWidget(checkBox_postprocess_only_left, 36, 0, 1, 1);

        checkBox_filter_adaptive_mean = new QCheckBox(scrollAreaWidgetContents_2);
        checkBox_filter_adaptive_mean->setObjectName(QString::fromUtf8("checkBox_filter_adaptive_mean"));

        gridLayout_7->addWidget(checkBox_filter_adaptive_mean, 37, 0, 1, 1);

        checkBox_filter_median = new QCheckBox(scrollAreaWidgetContents_2);
        checkBox_filter_median->setObjectName(QString::fromUtf8("checkBox_filter_median"));

        gridLayout_7->addWidget(checkBox_filter_median, 38, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_6->addWidget(scrollArea_2, 0, 0, 1, 1);

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

        gridLayout_2->addWidget(stackedWidget, 2, 2, 1, 1);

        graphicsView_D = new QGraphicsView(MatcherView);
        graphicsView_D->setObjectName(QString::fromUtf8("graphicsView_D"));
        graphicsView_D->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(graphicsView_D, 2, 1, 1, 1);

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


        gridLayout_2->addWidget(frame_2, 0, 0, 3, 1);


        retranslateUi(MatcherView);
        QObject::connect(pushButton_MatchDefault, SIGNAL(clicked()), MatcherView, SLOT(setDefaultMatchParam()));
        QObject::connect(pushButton_MatchChooseFiles, SIGNAL(clicked()), MatcherView, SLOT(doMatch()));
        QObject::connect(pushButton_RefreshStereoMatch, SIGNAL(clicked()), MatcherView, SLOT(RefreshStereoMatch()));
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
        QObject::connect(spinBox_disp_min, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_DMin(int)));
        QObject::connect(spinBox_disp_max, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_DMax(int)));
        QObject::connect(doubleSpinBox_support_threshold, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_SupportThreshold(double)));
        QObject::connect(spinBox_support_texture, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SupportTexture(int)));
        QObject::connect(spinBox_candidate_stepsize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_CandidateStepsize(int)));
        QObject::connect(spinBox_incon_window_size, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_InconWindowSize(int)));
        QObject::connect(spinBox_incon_threshold, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_InconThreshold(int)));
        QObject::connect(spinBox_incon_min_support, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_InconMinSupport(int)));
        QObject::connect(spinBox_grid_size, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_GridSize(int)));
        QObject::connect(doubleSpinBox_beta, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_Beta(double)));
        QObject::connect(doubleSpinBox_gamma, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_Gamma(double)));
        QObject::connect(doubleSpinBox_sigma, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_Sigma(double)));
        QObject::connect(doubleSpinBox_sradius, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_Sradius(double)));
        QObject::connect(spinBox_match_texture, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_MatchTexture(int)));
        QObject::connect(spinBox_lr_threshold, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_LrThreshold(int)));
        QObject::connect(doubleSpinBox_speckle_sim_threshold, SIGNAL(valueChanged(double)), MatcherView, SLOT(valueChanged_SpeckleSimThreshold(double)));
        QObject::connect(spinBox_speckle_size, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SpeckleSize(int)));
        QObject::connect(spinBox_ipol_gap_width, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_IpolGapWidth(int)));
        QObject::connect(checkBox_add_corners, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_AddCorners(bool)));
        QObject::connect(checkBox_subsampling, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_SubSampling(bool)));
        QObject::connect(checkBox_postprocess_only_left, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_PostprocessOnlyLeft(bool)));
        QObject::connect(checkBox_filter_adaptive_mean, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_FilterAdaptiveMean(bool)));
        QObject::connect(checkBox_filter_median, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_FilterMedian(bool)));
        QObject::connect(radioButton_BM_Prefilter_Normalzed, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_BM_preFilterType_NORMALIZED(bool)));
        QObject::connect(radioButton_BM_Prefilter_XSobel, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_BM_preFilterType_XSOBEL(bool)));
        QObject::connect(spinBox_BM_preFilterSize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_preFilterSize(int)));
        QObject::connect(spinBox_BM_preFilterCap, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_preFilterCap(int)));
        QObject::connect(spinBox_BM_SADWindowSize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_SADWindowSize(int)));
        QObject::connect(spinBox_BM_minDisparity, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_minDisparity(int)));
        QObject::connect(spinBox_BM_numDisparities, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_numDisparities(int)));
        QObject::connect(spinBox_BM_textureThreshold, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_textureThreshold(int)));
        QObject::connect(spinBox_BM_uniquenessRatio, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_uniquenessRatio(int)));
        QObject::connect(spinBox_BM_speckleWindowSize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_speckleWindowSize(int)));
        QObject::connect(spinBox_BM_speckleRange, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_speckleRange(int)));
        QObject::connect(spinBox_BM_disp12MaxDiff, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_BM_disp12MaxDiff(int)));
        QObject::connect(radioButton_SGBM_MODEL_3WAY, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_SGBM_MODEL_3WAY(bool)));
        QObject::connect(radioButton_SGBM_MODEL_HH4, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_SGBM_MODEL_HH4(bool)));
        QObject::connect(radioButton_SGBM_MODEL_Default, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_SGBM_MODEL_Default(bool)));
        QObject::connect(spinBox_SGBM_preFilterCap, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_preFilterCap(int)));
        QObject::connect(spinBox_SGBM_minDisparity, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_minDisparity(int)));
        QObject::connect(spinBox_SGBM_numDisparities, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_numDisparities(int)));
        QObject::connect(spinBox_SGBM_blockSize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_blockSize(int)));
        QObject::connect(spinBox_SGBM_P1, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_P1(int)));
        QObject::connect(spinBox_SGBM_P2, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_P2(int)));
        QObject::connect(spinBox_SGBM_uniquenessRatio, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_uniquenessRatio(int)));
        QObject::connect(spinBox_SGBM_speckleWindowSize, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_speckleWindowSize(int)));
        QObject::connect(spinBox_SGBM_speckleRange, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_speckleRange(int)));
        QObject::connect(spinBox_SGBM_disp12MaxDiff, SIGNAL(valueChanged(int)), MatcherView, SLOT(valueChanged_SGBM_disp12MaxDiff(int)));
        QObject::connect(radioButton_SGBM_MODEL_HH, SIGNAL(clicked(bool)), MatcherView, SLOT(valueChanged_SGBM_MODEL_HH(bool)));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MatcherView);
    } // setupUi

    void retranslateUi(QWidget *MatcherView)
    {
        MatcherView->setWindowTitle(QApplication::translate("MatcherView", "\345\214\271\351\205\215", nullptr));
        groupBox_19->setTitle(QApplication::translate("MatcherView", "\345\211\215\345\244\204\347\220\206", nullptr));
        radioButton_BM_Prefilter_Normalzed->setText(QApplication::translate("MatcherView", "\345\275\222\344\270\200\345\214\226", nullptr));
        radioButton_BM_Prefilter_XSobel->setText(QApplication::translate("MatcherView", "X\346\226\271\345\220\221SOBEL", nullptr));
        groupBox_20->setTitle(QApplication::translate("MatcherView", "\345\211\215\345\244\204\347\220\206\345\217\202\346\225\260", nullptr));
        label_24->setText(QApplication::translate("MatcherView", "\345\275\222\344\270\200\345\214\226\347\252\227\345\217\243\345\244\247\345\260\217:", nullptr));
        label_25->setText(QApplication::translate("MatcherView", "XSOBEL\346\210\252\346\226\255\345\200\274", nullptr));
        groupBox_21->setTitle(QApplication::translate("MatcherView", "BM", nullptr));
        label_26->setText(QApplication::translate("MatcherView", "SAD\344\273\243\344\273\267\347\252\227\345\217\243\345\244\247\345\260\217", nullptr));
        label_29->setText(QApplication::translate("MatcherView", "\344\275\216\347\272\271\347\220\206\345\210\244\346\226\255\351\230\210\345\200\274", nullptr));
        label_28->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\347\252\227\345\217\243", nullptr));
        label_27->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\346\220\234\347\264\242\350\265\267\347\202\271", nullptr));
        label_30->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\345\224\257\344\270\200\345\272\246", nullptr));
        groupBox_22->setTitle(QApplication::translate("MatcherView", "\345\220\216\345\244\204\347\220\206", nullptr));
        label_31->setText(QApplication::translate("MatcherView", "\346\225\243\346\226\221\346\273\244\346\263\242\347\252\227\345\217\243\345\244\247\345\260\217", nullptr));
        label_33->setText(QApplication::translate("MatcherView", "\346\225\243\346\226\221\347\252\227\345\217\243\345\206\205\347\232\204\346\234\200\345\244\247\345\256\271\345\267\256", nullptr));
        label_34->setText(QApplication::translate("MatcherView", "\345\267\246\345\217\263\344\270\200\350\207\264\346\200\247\346\243\200\346\237\245\347\232\204\346\234\200\345\244\247\345\256\271\345\267\256", nullptr));
        groupBox_26->setTitle(QApplication::translate("MatcherView", "\346\250\241\345\274\217", nullptr));
        radioButton_SGBM_MODEL_3WAY->setText(QApplication::translate("MatcherView", "SGBM_3WAY", nullptr));
        radioButton_SGBM_MODEL_HH4->setText(QApplication::translate("MatcherView", "HH4", nullptr));
        radioButton_SGBM_MODEL_Default->setText(QApplication::translate("MatcherView", "Default_SGBM", nullptr));
        radioButton_SGBM_MODEL_HH->setText(QApplication::translate("MatcherView", "HH", nullptr));
        groupBox_23->setTitle(QApplication::translate("MatcherView", "\345\211\215\345\244\204\347\220\206\345\217\202\346\225\260", nullptr));
        label_35->setText(QApplication::translate("MatcherView", "\351\242\204\345\244\204\347\220\206\346\210\252\346\226\255\345\200\274", nullptr));
        groupBox_24->setTitle(QApplication::translate("MatcherView", "SGBM", nullptr));
        label_36->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\346\220\234\347\264\242\350\265\267\347\202\271", nullptr));
        label_37->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\347\252\227\345\217\243", nullptr));
        label_38->setText(QApplication::translate("MatcherView", "\345\214\271\351\205\215\345\235\227\345\244\247\345\260\217", nullptr));
        label_39->setText(QApplication::translate("MatcherView", "\346\203\251\347\275\232\351\241\271P1", nullptr));
        label_40->setText(QApplication::translate("MatcherView", "\346\203\251\347\275\232\351\241\271P2", nullptr));
        label_41->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\345\224\257\344\270\200\345\272\246", nullptr));
        groupBox_25->setTitle(QApplication::translate("MatcherView", "\345\220\216\345\244\204\347\220\206\345\217\202\346\225\260", nullptr));
        label_42->setText(QApplication::translate("MatcherView", "\346\225\243\346\226\221\346\273\244\346\263\242\347\252\227\345\217\243\345\244\247\345\260\217", nullptr));
        label_43->setText(QApplication::translate("MatcherView", "\346\225\243\346\226\221\347\252\227\345\217\243\345\206\205\347\232\204\346\234\200\345\244\247\345\256\271\345\267\256", nullptr));
        label_44->setText(QApplication::translate("MatcherView", "\345\267\246\345\217\263\344\270\200\350\207\264\346\200\247\346\243\200\346\237\245\347\232\204\346\234\200\345\244\247\345\256\271\345\267\256", nullptr));
        label_62->setText(QApplication::translate("MatcherView", "speckle_size", nullptr));
        label_63->setText(QApplication::translate("MatcherView", "ipol_gap_width", nullptr));
        label_32->setText(QApplication::translate("MatcherView", "disp_min", nullptr));
        label_47->setText(QApplication::translate("MatcherView", "disp_max", nullptr));
        label_48->setText(QApplication::translate("MatcherView", "support_threshold", nullptr));
        label_49->setText(QApplication::translate("MatcherView", "support_texture", nullptr));
        label_50->setText(QApplication::translate("MatcherView", "candidate_stepsize", nullptr));
        label_51->setText(QApplication::translate("MatcherView", "incon_window_size", nullptr));
        label_52->setText(QApplication::translate("MatcherView", "incon_threshold", nullptr));
        label_53->setText(QApplication::translate("MatcherView", "incon_min_support", nullptr));
        label_54->setText(QApplication::translate("MatcherView", "grid_size", nullptr));
        label_55->setText(QApplication::translate("MatcherView", "beta", nullptr));
        label_56->setText(QApplication::translate("MatcherView", "gamma", nullptr));
        label_57->setText(QApplication::translate("MatcherView", "sigma", nullptr));
        label_58->setText(QApplication::translate("MatcherView", "sradius", nullptr));
        label_59->setText(QApplication::translate("MatcherView", "match_texture", nullptr));
        label_60->setText(QApplication::translate("MatcherView", "lr_threshold", nullptr));
        label_61->setText(QApplication::translate("MatcherView", "speckle_sim_threshold", nullptr));
        checkBox_add_corners->setText(QApplication::translate("MatcherView", "add_corners", nullptr));
        checkBox_subsampling->setText(QApplication::translate("MatcherView", "subsampling", nullptr));
        checkBox_postprocess_only_left->setText(QApplication::translate("MatcherView", "postprocess_only_left", nullptr));
        checkBox_filter_adaptive_mean->setText(QApplication::translate("MatcherView", "filter_adaptive_mean", nullptr));
        checkBox_filter_median->setText(QApplication::translate("MatcherView", "filter_median", nullptr));
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
        radioButton_ImageL->setText(QApplication::translate("MatcherView", "\345\267\246\350\247\206\345\233\276", nullptr));
        radioButton_ImageR->setText(QApplication::translate("MatcherView", "\345\217\263\350\247\206\345\233\276", nullptr));
        radioButton_RawDisp->setText(QApplication::translate("MatcherView", "\350\247\206\345\267\256\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatcherView: public Ui_MatcherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHERVIEW_H
