/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Open;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_Smog;
    QPushButton *defaultRange;
    QDateTimeEdit *dateTime_to;
    QPushButton *Clear_Button;
    QPushButton *Draw_Button;
    QDateTimeEdit *dateTime_from;
    QCheckBox *checkBox_O;
    QCheckBox *checkBox_I;
    QGridLayout *gridLayout_2;
    QLabel *median_Label;
    QLabel *mean_Label;
    QPushButton *statsdegreesO_Button;
    QPushButton *statsdegreesI_Button;
    QPushButton *statssmog_Button;
    QLabel *deviation_Label;
    QLabel *meanvalue_Label;
    QLabel *medianvalue_Label;
    QLabel *deviationvalue_Label;
    QCustomPlot *customPlot;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1089, 689);
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QStringLiteral("action_Open"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        checkBox_Smog = new QCheckBox(centralWidget);
        checkBox_Smog->setObjectName(QStringLiteral("checkBox_Smog"));
        checkBox_Smog->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_Smog->sizePolicy().hasHeightForWidth());
        checkBox_Smog->setSizePolicy(sizePolicy);
        checkBox_Smog->setMinimumSize(QSize(100, 100));
        checkBox_Smog->setCheckable(true);
        checkBox_Smog->setChecked(true);
        checkBox_Smog->setTristate(false);

        gridLayout->addWidget(checkBox_Smog, 2, 0, 1, 1);

        defaultRange = new QPushButton(centralWidget);
        defaultRange->setObjectName(QStringLiteral("defaultRange"));
        defaultRange->setEnabled(false);
        sizePolicy.setHeightForWidth(defaultRange->sizePolicy().hasHeightForWidth());
        defaultRange->setSizePolicy(sizePolicy);
        defaultRange->setMaximumSize(QSize(100, 20));

        gridLayout->addWidget(defaultRange, 2, 1, 1, 1);

        dateTime_to = new QDateTimeEdit(centralWidget);
        dateTime_to->setObjectName(QStringLiteral("dateTime_to"));
        dateTime_to->setMinimumSize(QSize(0, 35));
        dateTime_to->setDateTime(QDateTime(QDate(2016, 8, 8), QTime(13, 15, 0)));
        dateTime_to->setDate(QDate(2016, 8, 8));
        dateTime_to->setTime(QTime(13, 15, 0));
        dateTime_to->setMaximumDateTime(QDateTime(QDate(2020, 12, 31), QTime(23, 59, 59)));
        dateTime_to->setMinimumDateTime(QDateTime(QDate(2016, 5, 14), QTime(0, 0, 0)));
        dateTime_to->setCalendarPopup(true);

        gridLayout->addWidget(dateTime_to, 6, 0, 1, 2);

        Clear_Button = new QPushButton(centralWidget);
        Clear_Button->setObjectName(QStringLiteral("Clear_Button"));
        Clear_Button->setEnabled(false);
        sizePolicy.setHeightForWidth(Clear_Button->sizePolicy().hasHeightForWidth());
        Clear_Button->setSizePolicy(sizePolicy);
        Clear_Button->setMaximumSize(QSize(100, 20));

        gridLayout->addWidget(Clear_Button, 1, 1, 1, 1);

        Draw_Button = new QPushButton(centralWidget);
        Draw_Button->setObjectName(QStringLiteral("Draw_Button"));
        Draw_Button->setEnabled(false);
        sizePolicy.setHeightForWidth(Draw_Button->sizePolicy().hasHeightForWidth());
        Draw_Button->setSizePolicy(sizePolicy);
        Draw_Button->setMaximumSize(QSize(100, 20));

        gridLayout->addWidget(Draw_Button, 0, 1, 1, 1);

        dateTime_from = new QDateTimeEdit(centralWidget);
        dateTime_from->setObjectName(QStringLiteral("dateTime_from"));
        dateTime_from->setMinimumSize(QSize(0, 35));
        dateTime_from->setDateTime(QDateTime(QDate(2016, 5, 14), QTime(14, 45, 0)));
        dateTime_from->setDate(QDate(2016, 5, 14));
        dateTime_from->setTime(QTime(14, 45, 0));
        dateTime_from->setMaximumDateTime(QDateTime(QDate(2020, 12, 31), QTime(23, 59, 59)));
        dateTime_from->setMinimumDateTime(QDateTime(QDate(2016, 5, 14), QTime(0, 0, 0)));
        dateTime_from->setCalendarPopup(true);

        gridLayout->addWidget(dateTime_from, 5, 0, 1, 2);

        checkBox_O = new QCheckBox(centralWidget);
        checkBox_O->setObjectName(QStringLiteral("checkBox_O"));
        checkBox_O->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_O->sizePolicy().hasHeightForWidth());
        checkBox_O->setSizePolicy(sizePolicy);
        checkBox_O->setMinimumSize(QSize(100, 100));
        checkBox_O->setCheckable(true);
        checkBox_O->setChecked(true);

        gridLayout->addWidget(checkBox_O, 1, 0, 1, 1);

        checkBox_I = new QCheckBox(centralWidget);
        checkBox_I->setObjectName(QStringLiteral("checkBox_I"));
        checkBox_I->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_I->sizePolicy().hasHeightForWidth());
        checkBox_I->setSizePolicy(sizePolicy);
        checkBox_I->setMinimumSize(QSize(100, 100));
        checkBox_I->setCheckable(true);
        checkBox_I->setChecked(true);

        gridLayout->addWidget(checkBox_I, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        median_Label = new QLabel(centralWidget);
        median_Label->setObjectName(QStringLiteral("median_Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(median_Label->sizePolicy().hasHeightForWidth());
        median_Label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(median_Label, 1, 1, 1, 1);

        mean_Label = new QLabel(centralWidget);
        mean_Label->setObjectName(QStringLiteral("mean_Label"));
        sizePolicy1.setHeightForWidth(mean_Label->sizePolicy().hasHeightForWidth());
        mean_Label->setSizePolicy(sizePolicy1);
        mean_Label->setTextFormat(Qt::AutoText);
        mean_Label->setScaledContents(false);
        mean_Label->setWordWrap(false);

        gridLayout_2->addWidget(mean_Label, 1, 0, 1, 1);

        statsdegreesO_Button = new QPushButton(centralWidget);
        statsdegreesO_Button->setObjectName(QStringLiteral("statsdegreesO_Button"));
        statsdegreesO_Button->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(statsdegreesO_Button->sizePolicy().hasHeightForWidth());
        statsdegreesO_Button->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(statsdegreesO_Button, 0, 1, 1, 1);

        statsdegreesI_Button = new QPushButton(centralWidget);
        statsdegreesI_Button->setObjectName(QStringLiteral("statsdegreesI_Button"));
        statsdegreesI_Button->setEnabled(false);
        sizePolicy2.setHeightForWidth(statsdegreesI_Button->sizePolicy().hasHeightForWidth());
        statsdegreesI_Button->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(statsdegreesI_Button, 0, 0, 1, 1);

        statssmog_Button = new QPushButton(centralWidget);
        statssmog_Button->setObjectName(QStringLiteral("statssmog_Button"));
        statssmog_Button->setEnabled(false);
        sizePolicy2.setHeightForWidth(statssmog_Button->sizePolicy().hasHeightForWidth());
        statssmog_Button->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(statssmog_Button, 0, 2, 1, 1);

        deviation_Label = new QLabel(centralWidget);
        deviation_Label->setObjectName(QStringLiteral("deviation_Label"));
        sizePolicy1.setHeightForWidth(deviation_Label->sizePolicy().hasHeightForWidth());
        deviation_Label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(deviation_Label, 1, 2, 1, 1);

        meanvalue_Label = new QLabel(centralWidget);
        meanvalue_Label->setObjectName(QStringLiteral("meanvalue_Label"));
        sizePolicy1.setHeightForWidth(meanvalue_Label->sizePolicy().hasHeightForWidth());
        meanvalue_Label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(meanvalue_Label, 2, 0, 1, 1);

        medianvalue_Label = new QLabel(centralWidget);
        medianvalue_Label->setObjectName(QStringLiteral("medianvalue_Label"));
        sizePolicy1.setHeightForWidth(medianvalue_Label->sizePolicy().hasHeightForWidth());
        medianvalue_Label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(medianvalue_Label, 2, 1, 1, 1);

        deviationvalue_Label = new QLabel(centralWidget);
        deviationvalue_Label->setObjectName(QStringLiteral("deviationvalue_Label"));
        sizePolicy1.setHeightForWidth(deviationvalue_Label->sizePolicy().hasHeightForWidth());
        deviationvalue_Label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(deviationvalue_Label, 2, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);

        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(customPlot);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(label);


        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1089, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(action_Open);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Open->setText(QApplication::translate("MainWindow", "&Open", 0));
        checkBox_Smog->setText(QApplication::translate("MainWindow", "Smog", 0));
        defaultRange->setText(QApplication::translate("MainWindow", "Default Range", 0));
        dateTime_to->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd  HH:mm", 0));
        Clear_Button->setText(QApplication::translate("MainWindow", "Clear", 0));
        Draw_Button->setText(QApplication::translate("MainWindow", "Draw", 0));
        dateTime_from->setDisplayFormat(QApplication::translate("MainWindow", "yyyy-MM-dd  HH:mm", 0));
        checkBox_O->setText(QApplication::translate("MainWindow", "DegreesO", 0));
        checkBox_I->setText(QApplication::translate("MainWindow", "DegreesI", 0));
        median_Label->setText(QApplication::translate("MainWindow", "Median", 0));
        mean_Label->setText(QApplication::translate("MainWindow", "Mean", 0));
        statsdegreesO_Button->setText(QApplication::translate("MainWindow", "DegreesO", 0));
        statsdegreesI_Button->setText(QApplication::translate("MainWindow", "DegreesI", 0));
        statssmog_Button->setText(QApplication::translate("MainWindow", "Smog", 0));
        deviation_Label->setText(QApplication::translate("MainWindow", "Deviation", 0));
        meanvalue_Label->setText(QString());
        medianvalue_Label->setText(QString());
        deviationvalue_Label->setText(QString());
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
