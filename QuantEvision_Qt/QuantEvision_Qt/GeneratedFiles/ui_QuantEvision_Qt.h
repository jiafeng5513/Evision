/********************************************************************************
** Form generated from reading UI file 'QuantEvision_Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUANTEVISION_QT_H
#define UI_QUANTEVISION_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuantEvision_QtClass
{
public:
    QAction *action_RangerStart;
    QAction *action_RangeFinderStart;
    QAction *action_RangeGuide;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_FileView;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QTreeView *treeView;
    QDockWidget *dockWidget_Console;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit_Console;
    QDockWidget *dockWidget_RangeGuide;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_Reconstruct;
    QCheckBox *checkBox_Match;
    QCheckBox *checkBox_Calibrate;
    QLabel *label;
    QCheckBox *checkBox_Range;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Calibrate;
    QPushButton *pushButton_Reconstruct;
    QPushButton *pushButton_Match;
    QPushButton *pushButton_Range;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *QuantEvision_QtClass)
    {
        if (QuantEvision_QtClass->objectName().isEmpty())
            QuantEvision_QtClass->setObjectName(QStringLiteral("QuantEvision_QtClass"));
        QuantEvision_QtClass->resize(1125, 671);
        action_RangerStart = new QAction(QuantEvision_QtClass);
        action_RangerStart->setObjectName(QStringLiteral("action_RangerStart"));
        action_RangeFinderStart = new QAction(QuantEvision_QtClass);
        action_RangeFinderStart->setObjectName(QStringLiteral("action_RangeFinderStart"));
        action_RangeGuide = new QAction(QuantEvision_QtClass);
        action_RangeGuide->setObjectName(QStringLiteral("action_RangeGuide"));
        centralWidget = new QWidget(QuantEvision_QtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 6, 6, 0);
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setMinimumSize(QSize(765, 430));
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);
        mdiArea->setTabShape(QTabWidget::Triangular);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        QuantEvision_QtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QuantEvision_QtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1125, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        QuantEvision_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QuantEvision_QtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QuantEvision_QtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QuantEvision_QtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QuantEvision_QtClass->setStatusBar(statusBar);
        dockWidget_FileView = new QDockWidget(QuantEvision_QtClass);
        dockWidget_FileView->setObjectName(QStringLiteral("dockWidget_FileView"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidgetContents->setSizeIncrement(QSize(0, 0));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setEnabled(true);

        gridLayout_2->addWidget(treeView, 0, 0, 1, 1);

        dockWidget_FileView->setWidget(dockWidgetContents);
        QuantEvision_QtClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_FileView);
        dockWidget_Console = new QDockWidget(QuantEvision_QtClass);
        dockWidget_Console->setObjectName(QStringLiteral("dockWidget_Console"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        plainTextEdit_Console = new QPlainTextEdit(dockWidgetContents_2);
        plainTextEdit_Console->setObjectName(QStringLiteral("plainTextEdit_Console"));

        gridLayout_3->addWidget(plainTextEdit_Console, 0, 0, 1, 1);

        dockWidget_Console->setWidget(dockWidgetContents_2);
        QuantEvision_QtClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_Console);
        dockWidget_RangeGuide = new QDockWidget(QuantEvision_QtClass);
        dockWidget_RangeGuide->setObjectName(QStringLiteral("dockWidget_RangeGuide"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        gridLayout_4 = new QGridLayout(dockWidgetContents_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        checkBox_Reconstruct = new QCheckBox(dockWidgetContents_3);
        checkBox_Reconstruct->setObjectName(QStringLiteral("checkBox_Reconstruct"));

        gridLayout_4->addWidget(checkBox_Reconstruct, 5, 0, 1, 1);

        checkBox_Match = new QCheckBox(dockWidgetContents_3);
        checkBox_Match->setObjectName(QStringLiteral("checkBox_Match"));

        gridLayout_4->addWidget(checkBox_Match, 4, 0, 1, 1);

        checkBox_Calibrate = new QCheckBox(dockWidgetContents_3);
        checkBox_Calibrate->setObjectName(QStringLiteral("checkBox_Calibrate"));

        gridLayout_4->addWidget(checkBox_Calibrate, 3, 0, 1, 1);

        label = new QLabel(dockWidgetContents_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        checkBox_Range = new QCheckBox(dockWidgetContents_3);
        checkBox_Range->setObjectName(QStringLiteral("checkBox_Range"));

        gridLayout_4->addWidget(checkBox_Range, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 7, 0, 1, 1);

        pushButton_Calibrate = new QPushButton(dockWidgetContents_3);
        pushButton_Calibrate->setObjectName(QStringLiteral("pushButton_Calibrate"));

        gridLayout_4->addWidget(pushButton_Calibrate, 3, 1, 1, 1);

        pushButton_Reconstruct = new QPushButton(dockWidgetContents_3);
        pushButton_Reconstruct->setObjectName(QStringLiteral("pushButton_Reconstruct"));

        gridLayout_4->addWidget(pushButton_Reconstruct, 5, 1, 1, 1);

        pushButton_Match = new QPushButton(dockWidgetContents_3);
        pushButton_Match->setObjectName(QStringLiteral("pushButton_Match"));

        gridLayout_4->addWidget(pushButton_Match, 4, 1, 1, 1);

        pushButton_Range = new QPushButton(dockWidgetContents_3);
        pushButton_Range->setObjectName(QStringLiteral("pushButton_Range"));

        gridLayout_4->addWidget(pushButton_Range, 6, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 4, 2, 1, 1);

        dockWidget_RangeGuide->setWidget(dockWidgetContents_3);
        QuantEvision_QtClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_RangeGuide);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu_2->addAction(action_RangeGuide);

        retranslateUi(QuantEvision_QtClass);
        QObject::connect(action_RangeGuide, SIGNAL(triggered()), QuantEvision_QtClass, SLOT(RangeGuide()));
        QObject::connect(pushButton_Calibrate, SIGNAL(clicked()), QuantEvision_QtClass, SLOT(ShowCalibrate()));
        QObject::connect(pushButton_Match, SIGNAL(clicked()), QuantEvision_QtClass, SLOT(ShowMatch()));
        QObject::connect(pushButton_Reconstruct, SIGNAL(clicked()), QuantEvision_QtClass, SLOT(ShowReconstruct()));
        QObject::connect(pushButton_Range, SIGNAL(clicked()), QuantEvision_QtClass, SLOT(ShowRange()));

        QMetaObject::connectSlotsByName(QuantEvision_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *QuantEvision_QtClass)
    {
        QuantEvision_QtClass->setWindowTitle(QApplication::translate("QuantEvision_QtClass", "QuantEvision_Qt", Q_NULLPTR));
        action_RangerStart->setText(QApplication::translate("QuantEvision_QtClass", "\346\265\213\350\267\235", Q_NULLPTR));
        action_RangeFinderStart->setText(QApplication::translate("QuantEvision_QtClass", "\346\265\213\350\267\235", Q_NULLPTR));
        action_RangeGuide->setText(QApplication::translate("QuantEvision_QtClass", "\346\265\213\350\267\235", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QuantEvision_QtClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("QuantEvision_QtClass", "\345\212\237\350\203\275", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("QuantEvision_QtClass", "\346\265\213\350\257\225", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        dockWidget_FileView->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        dockWidget_FileView->setWindowTitle(QApplication::translate("QuantEvision_QtClass", "\346\226\207\344\273\266", Q_NULLPTR));
        dockWidget_Console->setWindowTitle(QApplication::translate("QuantEvision_QtClass", "\346\216\247\345\210\266\345\217\260", Q_NULLPTR));
        dockWidget_RangeGuide->setWindowTitle(QApplication::translate("QuantEvision_QtClass", "\346\265\213\350\267\235\345\220\221\345\257\274", Q_NULLPTR));
        checkBox_Reconstruct->setText(QApplication::translate("QuantEvision_QtClass", "\344\270\211\347\273\264\351\207\215\345\273\272", Q_NULLPTR));
        checkBox_Match->setText(QApplication::translate("QuantEvision_QtClass", "\345\214\271\351\205\215", Q_NULLPTR));
        checkBox_Calibrate->setText(QApplication::translate("QuantEvision_QtClass", "\346\240\207\345\256\232", Q_NULLPTR));
        label->setText(QApplication::translate("QuantEvision_QtClass", "\350\257\267\346\240\271\346\215\256\345\220\221\345\257\274\344\275\277\347\224\250\346\265\213\350\267\235\345\212\237\350\203\275", Q_NULLPTR));
        checkBox_Range->setText(QApplication::translate("QuantEvision_QtClass", "\346\265\213\350\267\235", Q_NULLPTR));
        pushButton_Calibrate->setText(QApplication::translate("QuantEvision_QtClass", "\346\240\207\345\256\232", Q_NULLPTR));
        pushButton_Reconstruct->setText(QApplication::translate("QuantEvision_QtClass", "\344\270\211\347\273\264\351\207\215\345\273\272", Q_NULLPTR));
        pushButton_Match->setText(QApplication::translate("QuantEvision_QtClass", "\345\214\271\351\205\215", Q_NULLPTR));
        pushButton_Range->setText(QApplication::translate("QuantEvision_QtClass", "\346\265\213\350\267\235", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QuantEvision_QtClass: public Ui_QuantEvision_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUANTEVISION_QT_H
