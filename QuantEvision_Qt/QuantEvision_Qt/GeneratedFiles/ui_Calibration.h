/********************************************************************************
** Form generated from reading UI file 'Calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_H
#define UI_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calibration
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QGraphicsView *Viewer_CalibrateL;
    QGraphicsView *Viewer_CalibrateR;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit__nBoards;
    QLabel *label_8;
    QCheckBox *checkBox_UIG;
    QLabel *label_9;
    QPushButton *pushButton_CalibDefault;
    QLabel *label_10;
    QCheckBox *checkBox_FAR;
    QLineEdit *lineEdit_SquareSize;
    QLineEdit *lineEdit_Alpha;
    QCheckBox *checkBox_SFL;
    QLineEdit *lineEdit_BoardWidth;
    QLabel *label_7;
    QLineEdit *lineEdit_BoardHeight;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *checkBox_FPP;
    QCheckBox *checkBox_FI;
    QCheckBox *checkBox_Bouguet;
    QCheckBox *checkBox_Hartley;
    QTabWidget *tabWidget_2;
    QWidget *tab_1;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_CalibChooseImages;
    QPushButton *pushButton_CalibStart;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_ShowImg;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_CameraRefresh;
    QPushButton *pushButton_CameraCalibStart;
    QPushButton *pushButton_CameraOnOff;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_12;
    QComboBox *comboBox_CameraR;
    QComboBox *comboBox_CameraL;
    QComboBox *comboBox_Resolution;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_CalibChooseXml;
    QPushButton *pushButton_FileCalib;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Calibration)
    {
        if (Calibration->objectName().isEmpty())
            Calibration->setObjectName(QStringLiteral("Calibration"));
        Calibration->resize(759, 423);
        Calibration->setMinimumSize(QSize(759, 423));
        gridLayout = new QGridLayout(Calibration);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(Calibration);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        Viewer_CalibrateL = new QGraphicsView(splitter);
        Viewer_CalibrateL->setObjectName(QStringLiteral("Viewer_CalibrateL"));
        Viewer_CalibrateL->setMinimumSize(QSize(368, 207));
        splitter->addWidget(Viewer_CalibrateL);
        Viewer_CalibrateR = new QGraphicsView(splitter);
        Viewer_CalibrateR->setObjectName(QStringLiteral("Viewer_CalibrateR"));
        Viewer_CalibrateR->setMinimumSize(QSize(368, 207));
        splitter->addWidget(Viewer_CalibrateR);

        gridLayout->addWidget(splitter, 0, 0, 1, 2);

        groupBox = new QGroupBox(Calibration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lineEdit__nBoards = new QLineEdit(groupBox);
        lineEdit__nBoards->setObjectName(QStringLiteral("lineEdit__nBoards"));
        lineEdit__nBoards->setMinimumSize(QSize(50, 20));
        lineEdit__nBoards->setMaximumSize(QSize(50, 20));

        gridLayout_4->addWidget(lineEdit__nBoards, 7, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_4->addWidget(label_8, 4, 0, 1, 1);

        checkBox_UIG = new QCheckBox(groupBox);
        checkBox_UIG->setObjectName(QStringLiteral("checkBox_UIG"));

        gridLayout_4->addWidget(checkBox_UIG, 0, 11, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_4->addWidget(label_9, 7, 0, 1, 1);

        pushButton_CalibDefault = new QPushButton(groupBox);
        pushButton_CalibDefault->setObjectName(QStringLiteral("pushButton_CalibDefault"));

        gridLayout_4->addWidget(pushButton_CalibDefault, 9, 0, 1, 2);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_10, 4, 2, 1, 1);

        checkBox_FAR = new QCheckBox(groupBox);
        checkBox_FAR->setObjectName(QStringLiteral("checkBox_FAR"));

        gridLayout_4->addWidget(checkBox_FAR, 7, 5, 1, 1);

        lineEdit_SquareSize = new QLineEdit(groupBox);
        lineEdit_SquareSize->setObjectName(QStringLiteral("lineEdit_SquareSize"));
        lineEdit_SquareSize->setMinimumSize(QSize(50, 20));
        lineEdit_SquareSize->setMaximumSize(QSize(50, 20));

        gridLayout_4->addWidget(lineEdit_SquareSize, 4, 1, 1, 1);

        lineEdit_Alpha = new QLineEdit(groupBox);
        lineEdit_Alpha->setObjectName(QStringLiteral("lineEdit_Alpha"));
        lineEdit_Alpha->setMinimumSize(QSize(50, 20));
        lineEdit_Alpha->setMaximumSize(QSize(50, 20));

        gridLayout_4->addWidget(lineEdit_Alpha, 4, 3, 1, 1);

        checkBox_SFL = new QCheckBox(groupBox);
        checkBox_SFL->setObjectName(QStringLiteral("checkBox_SFL"));

        gridLayout_4->addWidget(checkBox_SFL, 4, 5, 1, 1);

        lineEdit_BoardWidth = new QLineEdit(groupBox);
        lineEdit_BoardWidth->setObjectName(QStringLiteral("lineEdit_BoardWidth"));
        lineEdit_BoardWidth->setMinimumSize(QSize(50, 20));
        lineEdit_BoardWidth->setMaximumSize(QSize(50, 20));

        gridLayout_4->addWidget(lineEdit_BoardWidth, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 0, 4, 1, 1);

        lineEdit_BoardHeight = new QLineEdit(groupBox);
        lineEdit_BoardHeight->setObjectName(QStringLiteral("lineEdit_BoardHeight"));
        lineEdit_BoardHeight->setMinimumSize(QSize(50, 20));
        lineEdit_BoardHeight->setMaximumSize(QSize(50, 20));

        gridLayout_4->addWidget(lineEdit_BoardHeight, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 0, 2, 1, 1);

        checkBox_FPP = new QCheckBox(groupBox);
        checkBox_FPP->setObjectName(QStringLiteral("checkBox_FPP"));

        gridLayout_4->addWidget(checkBox_FPP, 4, 11, 1, 1);

        checkBox_FI = new QCheckBox(groupBox);
        checkBox_FI->setObjectName(QStringLiteral("checkBox_FI"));

        gridLayout_4->addWidget(checkBox_FI, 0, 5, 1, 1);

        checkBox_Bouguet = new QCheckBox(groupBox);
        checkBox_Bouguet->setObjectName(QStringLiteral("checkBox_Bouguet"));

        gridLayout_4->addWidget(checkBox_Bouguet, 8, 5, 1, 1);

        checkBox_Hartley = new QCheckBox(groupBox);
        checkBox_Hartley->setObjectName(QStringLiteral("checkBox_Hartley"));

        gridLayout_4->addWidget(checkBox_Hartley, 9, 5, 1, 1);


        gridLayout->addWidget(groupBox, 1, 1, 1, 1);

        tabWidget_2 = new QTabWidget(Calibration);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setMinimumSize(QSize(0, 192));
        tabWidget_2->setMaximumSize(QSize(16777215, 192));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        gridLayout_3 = new QGridLayout(tab_1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_CalibChooseImages = new QPushButton(tab_1);
        pushButton_CalibChooseImages->setObjectName(QStringLiteral("pushButton_CalibChooseImages"));

        gridLayout_3->addWidget(pushButton_CalibChooseImages, 1, 1, 1, 1);

        pushButton_CalibStart = new QPushButton(tab_1);
        pushButton_CalibStart->setObjectName(QStringLiteral("pushButton_CalibStart"));

        gridLayout_3->addWidget(pushButton_CalibStart, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 1, 1, 1);

        pushButton_ShowImg = new QPushButton(tab_1);
        pushButton_ShowImg->setObjectName(QStringLiteral("pushButton_ShowImg"));

        gridLayout_3->addWidget(pushButton_ShowImg, 1, 3, 1, 1);

        tabWidget_2->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_CameraRefresh = new QPushButton(tab_2);
        pushButton_CameraRefresh->setObjectName(QStringLiteral("pushButton_CameraRefresh"));

        gridLayout_6->addWidget(pushButton_CameraRefresh, 1, 0, 1, 1);

        pushButton_CameraCalibStart = new QPushButton(tab_2);
        pushButton_CameraCalibStart->setObjectName(QStringLiteral("pushButton_CameraCalibStart"));

        gridLayout_6->addWidget(pushButton_CameraCalibStart, 1, 2, 1, 1);

        pushButton_CameraOnOff = new QPushButton(tab_2);
        pushButton_CameraOnOff->setObjectName(QStringLiteral("pushButton_CameraOnOff"));

        gridLayout_6->addWidget(pushButton_CameraOnOff, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 0, 0, 1, 1);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_5->addWidget(label_13, 4, 0, 1, 1);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 3, 0, 1, 1);

        comboBox_CameraR = new QComboBox(groupBox_4);
        comboBox_CameraR->setObjectName(QStringLiteral("comboBox_CameraR"));

        gridLayout_5->addWidget(comboBox_CameraR, 3, 1, 1, 2);

        comboBox_CameraL = new QComboBox(groupBox_4);
        comboBox_CameraL->setObjectName(QStringLiteral("comboBox_CameraL"));

        gridLayout_5->addWidget(comboBox_CameraL, 0, 1, 1, 2);

        comboBox_Resolution = new QComboBox(groupBox_4);
        comboBox_Resolution->setObjectName(QStringLiteral("comboBox_Resolution"));

        gridLayout_5->addWidget(comboBox_Resolution, 4, 1, 1, 2);


        gridLayout_6->addWidget(groupBox_4, 0, 0, 1, 3);

        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        pushButton_CalibChooseXml = new QPushButton(tab_3);
        pushButton_CalibChooseXml->setObjectName(QStringLiteral("pushButton_CalibChooseXml"));

        gridLayout_9->addWidget(pushButton_CalibChooseXml, 0, 0, 1, 1);

        pushButton_FileCalib = new QPushButton(tab_3);
        pushButton_FileCalib->setObjectName(QStringLiteral("pushButton_FileCalib"));

        gridLayout_9->addWidget(pushButton_FileCalib, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 1, 0, 1, 1);

        tabWidget_2->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget_2, 1, 0, 1, 1);


        retranslateUi(Calibration);
        QObject::connect(pushButton_CalibDefault, SIGNAL(clicked()), Calibration, SLOT(OnDefaultBoardParams()));
        QObject::connect(checkBox_Bouguet, SIGNAL(clicked()), Calibration, SLOT(OnChecked_Bouguet()));
        QObject::connect(checkBox_Hartley, SIGNAL(clicked()), Calibration, SLOT(OnChecked_Hartley()));
        QObject::connect(checkBox_FI, SIGNAL(clicked()), Calibration, SLOT(OnChecked_Fi()));
        QObject::connect(checkBox_UIG, SIGNAL(clicked()), Calibration, SLOT(OnChecked_Uig()));
        QObject::connect(checkBox_SFL, SIGNAL(clicked()), Calibration, SLOT(OnChecked_Sfl()));
        QObject::connect(checkBox_FPP, SIGNAL(clicked()), Calibration, SLOT(OnChecked_FPP()));
        QObject::connect(checkBox_FAR, SIGNAL(clicked()), Calibration, SLOT(OnChecked_Far()));
        QObject::connect(pushButton_CalibChooseImages, SIGNAL(clicked()), Calibration, SLOT(OnChooseImages()));
        QObject::connect(pushButton_CalibStart, SIGNAL(clicked()), Calibration, SLOT(OnCalibrateFromImage()));
        QObject::connect(comboBox_CameraL, SIGNAL(currentIndexChanged(QString)), Calibration, SLOT(OnChanged_LCameraComboBox()));
        QObject::connect(comboBox_CameraR, SIGNAL(currentIndexChanged(QString)), Calibration, SLOT(OnChanged_RChangeComboBox()));
        QObject::connect(comboBox_Resolution, SIGNAL(currentIndexChanged(QString)), Calibration, SLOT(OnChanged_ResolutionComboBox()));
        QObject::connect(pushButton_CameraRefresh, SIGNAL(clicked()), Calibration, SLOT(OnRefreshCameras()));
        QObject::connect(pushButton_CameraOnOff, SIGNAL(clicked()), Calibration, SLOT(OnCamerasPowerOn()));
        QObject::connect(pushButton_CameraCalibStart, SIGNAL(clicked()), Calibration, SLOT(OnCalibrateFromCameras()));
        QObject::connect(pushButton_CalibChooseXml, SIGNAL(clicked()), Calibration, SLOT(OnChooseCalibrateFile()));
        QObject::connect(pushButton_FileCalib, SIGNAL(clicked()), Calibration, SLOT(OnCalibrateFromFile()));
        QObject::connect(pushButton_ShowImg, SIGNAL(clicked()), Calibration, SLOT(OnShowImg()));

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Calibration);
    } // setupUi

    void retranslateUi(QWidget *Calibration)
    {
        Calibration->setWindowTitle(QApplication::translate("Calibration", "\346\240\207\345\256\232", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Calibration", "\346\240\207\345\256\232\346\235\277\345\217\202\346\225\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("Calibration", "\346\226\271\346\240\274\350\276\271\351\225\277:", Q_NULLPTR));
        checkBox_UIG->setText(QApplication::translate("Calibration", "UIG", Q_NULLPTR));
        label_9->setText(QApplication::translate("Calibration", "\350\277\255\344\273\243\346\254\241\346\225\260:", Q_NULLPTR));
        pushButton_CalibDefault->setText(QApplication::translate("Calibration", "\351\273\230\350\256\244\345\217\202\346\225\260", Q_NULLPTR));
        label_10->setText(QApplication::translate("Calibration", "\316\261:", Q_NULLPTR));
        checkBox_FAR->setText(QApplication::translate("Calibration", "FAR", Q_NULLPTR));
        checkBox_SFL->setText(QApplication::translate("Calibration", "SFL", Q_NULLPTR));
        label_7->setText(QApplication::translate("Calibration", "\345\210\227", Q_NULLPTR));
        label_5->setText(QApplication::translate("Calibration", "\350\247\222\347\202\271\346\225\260\351\207\217:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Calibration", "\350\241\214", Q_NULLPTR));
        checkBox_FPP->setText(QApplication::translate("Calibration", "FPP", Q_NULLPTR));
        checkBox_FI->setText(QApplication::translate("Calibration", "FI", Q_NULLPTR));
        checkBox_Bouguet->setText(QApplication::translate("Calibration", "Bouguet", Q_NULLPTR));
        checkBox_Hartley->setText(QApplication::translate("Calibration", "Hartley", Q_NULLPTR));
        pushButton_CalibChooseImages->setText(QApplication::translate("Calibration", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_CalibStart->setText(QApplication::translate("Calibration", "\345\274\200\345\247\213\346\240\207\345\256\232", Q_NULLPTR));
        pushButton_ShowImg->setText(QApplication::translate("Calibration", "\346\230\276\347\244\272\345\233\276\347\211\207", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_1), QApplication::translate("Calibration", "\344\275\277\347\224\250\347\205\247\347\211\207\346\240\207\345\256\232", Q_NULLPTR));
        pushButton_CameraRefresh->setText(QApplication::translate("Calibration", "\345\210\267\346\226\260", Q_NULLPTR));
        pushButton_CameraCalibStart->setText(QApplication::translate("Calibration", "\345\274\200\345\247\213\346\240\207\345\256\232", Q_NULLPTR));
        pushButton_CameraOnOff->setText(QApplication::translate("Calibration", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Calibration", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        label_11->setText(QApplication::translate("Calibration", "\345\267\246\346\221\204\345\203\217\345\244\264:", Q_NULLPTR));
        label_13->setText(QApplication::translate("Calibration", "\345\210\206\350\276\250\347\216\207:", Q_NULLPTR));
        label_12->setText(QApplication::translate("Calibration", "\345\217\263\346\221\204\345\203\217\345\244\264:", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("Calibration", "\345\274\200\345\220\257\346\221\204\345\203\217\345\244\264\346\240\207\345\256\232", Q_NULLPTR));
        pushButton_CalibChooseXml->setText(QApplication::translate("Calibration", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_FileCalib->setText(QApplication::translate("Calibration", "\346\240\207\345\256\232", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("Calibration", "\350\257\273\345\217\226\346\240\207\345\256\232\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Calibration: public Ui_Calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_H
