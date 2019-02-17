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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatcherView
{
public:
    QGridLayout *gridLayout_2;
    QGraphicsView *graphicsView_D;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout;
    QLabel *label_40;
    QLineEdit *lineEdit_uniradio;
    QSlider *horizontalSlider_uniradio;
    QLabel *label_39;
    QLineEdit *lineEdit_prefilcap;
    QSlider *horizontalSlider_prefilcap;
    QLabel *label_36;
    QLineEdit *lineEdit_specwinsz;
    QLabel *label_37;
    QLineEdit *lineEdit_SadWinSiz;
    QSlider *horizontalSlider_SadWinSiz;
    QLabel *label_41;
    QLineEdit *lineEdit_MinDisp;
    QSlider *horizontalSlider_MinDisp;
    QLabel *label_44;
    QLineEdit *lineEdit_NumDisparities;
    QSlider *horizontalSlider_NumDisparities;
    QLabel *label_42;
    QLineEdit *lineEdit_specrange;
    QSlider *horizontalSlider_specrange;
    QLabel *label_43;
    QLineEdit *lineEdit_maxdifdisp12;
    QSlider *horizontalSlider_maxdifdisp12;
    QLabel *label_35;
    QLineEdit *lineEdit_textThread;
    QSlider *horizontalSlider_textThread;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_SGBM;
    QRadioButton *radioButton_BM;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_MODE_HH;
    QRadioButton *radioButton_MODE_3WAY;
    QRadioButton *radioButton_MODE_SGBM;
    QPushButton *pushButton_MatchDefault;
    QPushButton *pushButton_MatchChooseFiles;
    QSlider *horizontalSlider_specwinsz;
    QPushButton *pushButton_RefreshStereoMatch;

    void setupUi(QWidget *MatcherView)
    {
        if (MatcherView->objectName().isEmpty())
            MatcherView->setObjectName(QString::fromUtf8("MatcherView"));
        MatcherView->resize(1000, 574);
        gridLayout_2 = new QGridLayout(MatcherView);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphicsView_D = new QGraphicsView(MatcherView);
        graphicsView_D->setObjectName(QString::fromUtf8("graphicsView_D"));
        graphicsView_D->setMinimumSize(QSize(666, 0));

        gridLayout_2->addWidget(graphicsView_D, 0, 0, 3, 1);

        groupBox_6 = new QGroupBox(MatcherView);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(310, 16777215));
        gridLayout = new QGridLayout(groupBox_6);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_40 = new QLabel(groupBox_6);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMinimumSize(QSize(316, 29));
        label_40->setMaximumSize(QSize(316, 29));

        gridLayout->addWidget(label_40, 0, 0, 1, 6);

        lineEdit_uniradio = new QLineEdit(groupBox_6);
        lineEdit_uniradio->setObjectName(QString::fromUtf8("lineEdit_uniradio"));
        lineEdit_uniradio->setMinimumSize(QSize(35, 20));
        lineEdit_uniradio->setMaximumSize(QSize(30, 20));
        lineEdit_uniradio->setReadOnly(true);

        gridLayout->addWidget(lineEdit_uniradio, 1, 0, 1, 1);

        horizontalSlider_uniradio = new QSlider(groupBox_6);
        horizontalSlider_uniradio->setObjectName(QString::fromUtf8("horizontalSlider_uniradio"));
        horizontalSlider_uniradio->setMinimumSize(QSize(0, 20));
        horizontalSlider_uniradio->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_uniradio->setMaximum(50);
        horizontalSlider_uniradio->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_uniradio, 1, 1, 1, 5);

        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout->addWidget(label_39, 2, 0, 1, 5);

        lineEdit_prefilcap = new QLineEdit(groupBox_6);
        lineEdit_prefilcap->setObjectName(QString::fromUtf8("lineEdit_prefilcap"));
        lineEdit_prefilcap->setMinimumSize(QSize(35, 20));
        lineEdit_prefilcap->setMaximumSize(QSize(30, 20));
        lineEdit_prefilcap->setReadOnly(true);

        gridLayout->addWidget(lineEdit_prefilcap, 3, 0, 1, 1);

        horizontalSlider_prefilcap = new QSlider(groupBox_6);
        horizontalSlider_prefilcap->setObjectName(QString::fromUtf8("horizontalSlider_prefilcap"));
        horizontalSlider_prefilcap->setMinimumSize(QSize(0, 20));
        horizontalSlider_prefilcap->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_prefilcap->setMinimum(1);
        horizontalSlider_prefilcap->setMaximum(100);
        horizontalSlider_prefilcap->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_prefilcap, 3, 1, 1, 5);

        label_36 = new QLabel(groupBox_6);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(316, 29));
        label_36->setMaximumSize(QSize(316, 29));

        gridLayout->addWidget(label_36, 4, 0, 1, 6);

        lineEdit_specwinsz = new QLineEdit(groupBox_6);
        lineEdit_specwinsz->setObjectName(QString::fromUtf8("lineEdit_specwinsz"));
        lineEdit_specwinsz->setMinimumSize(QSize(35, 20));
        lineEdit_specwinsz->setMaximumSize(QSize(30, 20));
        lineEdit_specwinsz->setReadOnly(true);

        gridLayout->addWidget(lineEdit_specwinsz, 5, 0, 1, 1);

        label_37 = new QLabel(groupBox_6);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(310, 29));
        label_37->setMaximumSize(QSize(310, 29));

        gridLayout->addWidget(label_37, 6, 0, 1, 6);

        lineEdit_SadWinSiz = new QLineEdit(groupBox_6);
        lineEdit_SadWinSiz->setObjectName(QString::fromUtf8("lineEdit_SadWinSiz"));
        lineEdit_SadWinSiz->setMinimumSize(QSize(35, 20));
        lineEdit_SadWinSiz->setMaximumSize(QSize(30, 20));
        lineEdit_SadWinSiz->setReadOnly(true);

        gridLayout->addWidget(lineEdit_SadWinSiz, 7, 0, 1, 1);

        horizontalSlider_SadWinSiz = new QSlider(groupBox_6);
        horizontalSlider_SadWinSiz->setObjectName(QString::fromUtf8("horizontalSlider_SadWinSiz"));
        horizontalSlider_SadWinSiz->setMinimumSize(QSize(0, 20));
        horizontalSlider_SadWinSiz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_SadWinSiz->setMinimum(5);
        horizontalSlider_SadWinSiz->setMaximum(51);
        horizontalSlider_SadWinSiz->setSingleStep(2);
        horizontalSlider_SadWinSiz->setPageStep(2);
        horizontalSlider_SadWinSiz->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_SadWinSiz, 7, 1, 1, 5);

        label_41 = new QLabel(groupBox_6);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout->addWidget(label_41, 8, 0, 1, 4);

        lineEdit_MinDisp = new QLineEdit(groupBox_6);
        lineEdit_MinDisp->setObjectName(QString::fromUtf8("lineEdit_MinDisp"));
        lineEdit_MinDisp->setMinimumSize(QSize(35, 20));
        lineEdit_MinDisp->setMaximumSize(QSize(30, 20));
        lineEdit_MinDisp->setReadOnly(true);

        gridLayout->addWidget(lineEdit_MinDisp, 9, 0, 1, 1);

        horizontalSlider_MinDisp = new QSlider(groupBox_6);
        horizontalSlider_MinDisp->setObjectName(QString::fromUtf8("horizontalSlider_MinDisp"));
        horizontalSlider_MinDisp->setMinimumSize(QSize(0, 20));
        horizontalSlider_MinDisp->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_MinDisp->setMinimum(-64);
        horizontalSlider_MinDisp->setMaximum(16);
        horizontalSlider_MinDisp->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_MinDisp, 9, 1, 1, 5);

        label_44 = new QLabel(groupBox_6);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout->addWidget(label_44, 10, 0, 1, 5);

        lineEdit_NumDisparities = new QLineEdit(groupBox_6);
        lineEdit_NumDisparities->setObjectName(QString::fromUtf8("lineEdit_NumDisparities"));
        lineEdit_NumDisparities->setMinimumSize(QSize(35, 20));
        lineEdit_NumDisparities->setMaximumSize(QSize(30, 20));
        lineEdit_NumDisparities->setReadOnly(true);

        gridLayout->addWidget(lineEdit_NumDisparities, 11, 0, 1, 1);

        horizontalSlider_NumDisparities = new QSlider(groupBox_6);
        horizontalSlider_NumDisparities->setObjectName(QString::fromUtf8("horizontalSlider_NumDisparities"));
        horizontalSlider_NumDisparities->setMinimumSize(QSize(0, 20));
        horizontalSlider_NumDisparities->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_NumDisparities->setMinimum(16);
        horizontalSlider_NumDisparities->setMaximum(256);
        horizontalSlider_NumDisparities->setSingleStep(16);
        horizontalSlider_NumDisparities->setPageStep(16);
        horizontalSlider_NumDisparities->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_NumDisparities, 11, 1, 1, 5);

        label_42 = new QLabel(groupBox_6);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout->addWidget(label_42, 12, 0, 1, 5);

        lineEdit_specrange = new QLineEdit(groupBox_6);
        lineEdit_specrange->setObjectName(QString::fromUtf8("lineEdit_specrange"));
        lineEdit_specrange->setMinimumSize(QSize(35, 20));
        lineEdit_specrange->setMaximumSize(QSize(30, 20));
        lineEdit_specrange->setReadOnly(true);

        gridLayout->addWidget(lineEdit_specrange, 13, 0, 1, 1);

        horizontalSlider_specrange = new QSlider(groupBox_6);
        horizontalSlider_specrange->setObjectName(QString::fromUtf8("horizontalSlider_specrange"));
        horizontalSlider_specrange->setMinimumSize(QSize(0, 20));
        horizontalSlider_specrange->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specrange->setMaximum(64);
        horizontalSlider_specrange->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_specrange, 13, 1, 1, 5);

        label_43 = new QLabel(groupBox_6);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout->addWidget(label_43, 14, 0, 1, 6);

        lineEdit_maxdifdisp12 = new QLineEdit(groupBox_6);
        lineEdit_maxdifdisp12->setObjectName(QString::fromUtf8("lineEdit_maxdifdisp12"));
        lineEdit_maxdifdisp12->setMinimumSize(QSize(35, 20));
        lineEdit_maxdifdisp12->setMaximumSize(QSize(30, 20));
        lineEdit_maxdifdisp12->setReadOnly(true);

        gridLayout->addWidget(lineEdit_maxdifdisp12, 15, 0, 1, 1);

        horizontalSlider_maxdifdisp12 = new QSlider(groupBox_6);
        horizontalSlider_maxdifdisp12->setObjectName(QString::fromUtf8("horizontalSlider_maxdifdisp12"));
        horizontalSlider_maxdifdisp12->setMinimumSize(QSize(0, 20));
        horizontalSlider_maxdifdisp12->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_maxdifdisp12->setMinimum(-1);
        horizontalSlider_maxdifdisp12->setMaximum(5);
        horizontalSlider_maxdifdisp12->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_maxdifdisp12, 15, 1, 1, 5);

        label_35 = new QLabel(groupBox_6);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout->addWidget(label_35, 16, 0, 1, 6);

        lineEdit_textThread = new QLineEdit(groupBox_6);
        lineEdit_textThread->setObjectName(QString::fromUtf8("lineEdit_textThread"));
        lineEdit_textThread->setMinimumSize(QSize(35, 20));
        lineEdit_textThread->setMaximumSize(QSize(30, 20));
        lineEdit_textThread->setReadOnly(true);

        gridLayout->addWidget(lineEdit_textThread, 17, 0, 1, 1);

        horizontalSlider_textThread = new QSlider(groupBox_6);
        horizontalSlider_textThread->setObjectName(QString::fromUtf8("horizontalSlider_textThread"));
        horizontalSlider_textThread->setMinimumSize(QSize(0, 20));
        horizontalSlider_textThread->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_textThread->setMaximum(50);
        horizontalSlider_textThread->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_textThread, 17, 1, 1, 5);

        groupBox_9 = new QGroupBox(groupBox_6);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_9);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_SGBM = new QRadioButton(groupBox_9);
        radioButton_SGBM->setObjectName(QString::fromUtf8("radioButton_SGBM"));

        horizontalLayout_2->addWidget(radioButton_SGBM);

        radioButton_BM = new QRadioButton(groupBox_9);
        radioButton_BM->setObjectName(QString::fromUtf8("radioButton_BM"));

        horizontalLayout_2->addWidget(radioButton_BM);


        gridLayout->addWidget(groupBox_9, 18, 0, 1, 3);

        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        horizontalLayout = new QHBoxLayout(groupBox_8);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_MODE_HH = new QRadioButton(groupBox_8);
        radioButton_MODE_HH->setObjectName(QString::fromUtf8("radioButton_MODE_HH"));

        horizontalLayout->addWidget(radioButton_MODE_HH);

        radioButton_MODE_3WAY = new QRadioButton(groupBox_8);
        radioButton_MODE_3WAY->setObjectName(QString::fromUtf8("radioButton_MODE_3WAY"));

        horizontalLayout->addWidget(radioButton_MODE_3WAY);

        radioButton_MODE_SGBM = new QRadioButton(groupBox_8);
        radioButton_MODE_SGBM->setObjectName(QString::fromUtf8("radioButton_MODE_SGBM"));

        horizontalLayout->addWidget(radioButton_MODE_SGBM);


        gridLayout->addWidget(groupBox_8, 18, 3, 1, 3);

        pushButton_MatchDefault = new QPushButton(groupBox_6);
        pushButton_MatchDefault->setObjectName(QString::fromUtf8("pushButton_MatchDefault"));
        pushButton_MatchDefault->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(pushButton_MatchDefault, 19, 0, 1, 2);

        pushButton_MatchChooseFiles = new QPushButton(groupBox_6);
        pushButton_MatchChooseFiles->setObjectName(QString::fromUtf8("pushButton_MatchChooseFiles"));
        pushButton_MatchChooseFiles->setMinimumSize(QSize(0, 20));

        gridLayout->addWidget(pushButton_MatchChooseFiles, 19, 2, 1, 2);

        horizontalSlider_specwinsz = new QSlider(groupBox_6);
        horizontalSlider_specwinsz->setObjectName(QString::fromUtf8("horizontalSlider_specwinsz"));
        horizontalSlider_specwinsz->setMinimumSize(QSize(0, 20));
        horizontalSlider_specwinsz->setMaximumSize(QSize(16777215, 15));
        horizontalSlider_specwinsz->setMaximum(200);
        horizontalSlider_specwinsz->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_specwinsz, 5, 1, 1, 5);

        pushButton_RefreshStereoMatch = new QPushButton(groupBox_6);
        pushButton_RefreshStereoMatch->setObjectName(QString::fromUtf8("pushButton_RefreshStereoMatch"));

        gridLayout->addWidget(pushButton_RefreshStereoMatch, 19, 4, 1, 2);


        gridLayout_2->addWidget(groupBox_6, 0, 1, 3, 1);


        retranslateUi(MatcherView);
        QObject::connect(pushButton_MatchDefault, SIGNAL(clicked()), MatcherView, SLOT(setDefaultMatchParam()));
        QObject::connect(pushButton_MatchChooseFiles, SIGNAL(clicked()), MatcherView, SLOT(doMatch()));
        QObject::connect(pushButton_RefreshStereoMatch, SIGNAL(clicked()), MatcherView, SLOT(RefreshStereoMatch()));
        QObject::connect(radioButton_SGBM, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_SGBM(bool)));
        QObject::connect(radioButton_BM, SIGNAL(clicked(bool)), MatcherView, SLOT(onClicked_BM(bool)));
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

        QMetaObject::connectSlotsByName(MatcherView);
    } // setupUi

    void retranslateUi(QWidget *MatcherView)
    {
        MatcherView->setWindowTitle(QApplication::translate("MatcherView", "\345\214\271\351\205\215", nullptr));
        groupBox_6->setTitle(QApplication::translate("MatcherView", "\345\214\271\351\205\215\345\217\202\346\225\260", nullptr));
        label_40->setText(QApplication::translate("MatcherView", "uniquenessRatio(\350\247\206\345\267\256\345\224\257\344\270\200\346\200\247\347\231\276\345\210\206\346\257\224)", nullptr));
        lineEdit_uniradio->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
        label_39->setText(QApplication::translate("MatcherView", "preFilterCap(\345\211\215\347\275\256\346\273\244\346\263\242\345\231\250\346\210\252\346\226\255\345\200\274)", nullptr));
        lineEdit_prefilcap->setPlaceholderText(QApplication::translate("MatcherView", "1", nullptr));
        label_36->setText(QApplication::translate("MatcherView", "SpeckleWindowSize(\350\247\206\345\267\256\350\277\236\351\200\232\345\214\272\345\237\237\345\217\230\345\214\226\345\272\246\347\232\204\347\252\227\345\217\243\345\244\247\345\260\217)", nullptr));
        lineEdit_specwinsz->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
        label_37->setText(QApplication::translate("MatcherView", "SADWindowSize(SAD\347\252\227\345\217\243\345\244\247\345\260\217)", nullptr));
        lineEdit_SadWinSiz->setPlaceholderText(QApplication::translate("MatcherView", "5", nullptr));
        label_41->setText(QApplication::translate("MatcherView", "minDisparity(\346\234\200\345\260\217\350\247\206\345\267\256\345\200\274)", nullptr));
        lineEdit_MinDisp->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
        label_44->setText(QApplication::translate("MatcherView", "numDisparities(\350\247\206\345\267\256\347\252\227\345\217\243\345\244\247\345\260\217)", nullptr));
        lineEdit_NumDisparities->setPlaceholderText(QApplication::translate("MatcherView", "16", nullptr));
        label_42->setText(QApplication::translate("MatcherView", "speckleRange(\350\277\236\351\200\232\345\214\272\345\237\237\345\206\205\347\232\204\346\234\200\345\244\247\350\247\206\345\267\256\345\217\230\345\214\226)", nullptr));
        lineEdit_specrange->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
        label_43->setText(QApplication::translate("MatcherView", "disp12MaxDiff(\345\267\246\345\217\263\350\247\206\345\267\256\345\233\276\347\232\204\346\234\200\345\244\247\345\256\271\350\256\270\345\267\256\345\274\202)", nullptr));
        lineEdit_maxdifdisp12->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
        label_35->setText(QApplication::translate("MatcherView", "TextureThreshold(\344\275\216\347\272\271\347\220\206\345\214\272\345\237\237\347\232\204\345\210\244\346\226\255\351\230\210\345\200\274)", nullptr));
        lineEdit_textThread->setPlaceholderText(QApplication::translate("MatcherView", "0", nullptr));
        groupBox_9->setTitle(QApplication::translate("MatcherView", "Function", nullptr));
        radioButton_SGBM->setText(QApplication::translate("MatcherView", "SGBM", nullptr));
        radioButton_BM->setText(QApplication::translate("MatcherView", "BM", nullptr));
        groupBox_8->setTitle(QApplication::translate("MatcherView", "MODE", nullptr));
        radioButton_MODE_HH->setText(QApplication::translate("MatcherView", "HH", nullptr));
        radioButton_MODE_3WAY->setText(QApplication::translate("MatcherView", "3WAY", nullptr));
        radioButton_MODE_SGBM->setText(QApplication::translate("MatcherView", "SGBM", nullptr));
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
