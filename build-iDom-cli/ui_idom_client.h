/********************************************************************************
** Form generated from reading UI file 'idom_client.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDOM_CLIENT_H
#define UI_IDOM_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iDom_Client
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *titleTXT;
    QLineEdit *volumeTXT;
    QVBoxLayout *verticalLayout_2;
    QLabel *LOGO;
    QGridLayout *gridLayout_4;
    QPushButton *playButton;
    QPushButton *exitButton;
    QPushButton *stopButton;
    QPushButton *disconnectButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QTextEdit *wynik;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_36;
    QPushButton *pushButton_35;
    QPushButton *pushButton_34;
    QPushButton *pushButton_33;
    QPushButton *pushButton_32;
    QPushButton *pushButton_31;
    QPushButton *pushButton_30;
    QPushButton *pushButton_29;
    QPushButton *pushButton_28;
    QPushButton *pushButton_27;
    QPushButton *pushButton_26;
    QPushButton *pushButton_25;
    QPushButton *pushButton_24;
    QPushButton *pushButton_23;
    QPushButton *redButton_22;
    QPushButton *pushButton_17;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_21;
    QPushButton *pushButton_20;
    QPushButton *pushButton_19;
    QPushButton *pushButton_18;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *LED_OFF_Button_37;

    void setupUi(QMainWindow *iDom_Client)
    {
        if (iDom_Client->objectName().isEmpty())
            iDom_Client->setObjectName(QStringLiteral("iDom_Client"));
        iDom_Client->resize(598, 912);
        iDom_Client->setMinimumSize(QSize(550, 900));
        iDom_Client->setMaximumSize(QSize(1080, 1920));
        iDom_Client->setMouseTracking(true);
        iDom_Client->setFocusPolicy(Qt::StrongFocus);
        iDom_Client->setWindowOpacity(3);
        iDom_Client->setLayoutDirection(Qt::LeftToRight);
        iDom_Client->setAutoFillBackground(true);
        iDom_Client->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        iDom_Client->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::VerticalTabs);
        centralWidget = new QWidget(iDom_Client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(480, 480));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout_2->addLayout(verticalLayout, 1, 3, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        gridLayout_2->addLayout(verticalLayout_3, 1, 5, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        titleTXT = new QLineEdit(centralWidget);
        titleTXT->setObjectName(QStringLiteral("titleTXT"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleTXT->sizePolicy().hasHeightForWidth());
        titleTXT->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        titleTXT->setFont(font);
        titleTXT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        titleTXT->setReadOnly(true);

        verticalLayout_4->addWidget(titleTXT);

        volumeTXT = new QLineEdit(centralWidget);
        volumeTXT->setObjectName(QStringLiteral("volumeTXT"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(volumeTXT->sizePolicy().hasHeightForWidth());
        volumeTXT->setSizePolicy(sizePolicy1);
        volumeTXT->setFont(font);
        volumeTXT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        volumeTXT->setReadOnly(true);

        verticalLayout_4->addWidget(volumeTXT);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

        LOGO = new QLabel(centralWidget);
        LOGO->setObjectName(QStringLiteral("LOGO"));
        LOGO->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(9);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LOGO->sizePolicy().hasHeightForWidth());
        LOGO->setSizePolicy(sizePolicy2);
        LOGO->setMinimumSize(QSize(0, 0));
        LOGO->setMaximumSize(QSize(234, 89));
        LOGO->setSizeIncrement(QSize(0, 0));
        LOGO->setLayoutDirection(Qt::LeftToRight);
        LOGO->setFrameShape(QFrame::NoFrame);
        LOGO->setFrameShadow(QFrame::Sunken);
        LOGO->setPixmap(QPixmap(QString::fromUtf8("../build-iDom-cli/f/logo.png")));
        LOGO->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(LOGO, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setMinimumSize(QSize(0, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Impact"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        playButton->setFont(font1);
        playButton->setStyleSheet(QLatin1String("font: 12pt \"Impact\";\n"
" \n"
"color: rgb(170, 255, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));

        gridLayout_4->addWidget(playButton, 0, 0, 1, 1);

        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setMinimumSize(QSize(0, 50));
        exitButton->setStyleSheet(QLatin1String("font: 12pt \"Impact\";\n"
" \n"
"color: rgb(170, 255, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));

        gridLayout_4->addWidget(exitButton, 0, 1, 1, 1);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setMinimumSize(QSize(0, 50));
        stopButton->setStyleSheet(QLatin1String("font: 12pt \"Impact\";\n"
" \n"
"color: rgb(170, 255, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));

        gridLayout_4->addWidget(stopButton, 1, 0, 1, 1);

        disconnectButton = new QPushButton(centralWidget);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        disconnectButton->setMinimumSize(QSize(0, 50));
        disconnectButton->setStyleSheet(QLatin1String("font: 10pt \"Impact\";\n"
" \n"
"color: rgb(170, 255, 0);\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 235, 235, 206), stop:0.35 rgba(255, 188, 188, 80), stop:0.4 rgba(255, 162, 162, 80), stop:0.425 rgba(255, 132, 132, 156), stop:0.44 rgba(252, 128, 128, 80), stop:1 rgba(255, 255, 255, 0));"));

        gridLayout_4->addWidget(disconnectButton, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 1, 4, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(0, 350));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(10, 25));
        tabWidget->setElideMode(Qt::ElideRight);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setAutoFillBackground(true);
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        wynik = new QTextEdit(tab);
        wynik->setObjectName(QStringLiteral("wynik"));
        wynik->setStyleSheet(QStringLiteral("background-color: transparent;"));
        wynik->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        wynik->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        wynik->setReadOnly(true);

        gridLayout_3->addWidget(wynik, 1, 0, 1, 3);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 50));
        lineEdit->setFont(font);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QLatin1String(" \n"
"color: rgb(85, 85, 0);\n"
"background-color: rgb(170, 0, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0.113636, y1:0.875, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:0.556818 rgba(61, 66, 235, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        lineEdit->setClearButtonEnabled(true);

        gridLayout_3->addWidget(lineEdit, 0, 0, 1, 2);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(75, 50));
        pushButton->setStyleSheet(QLatin1String(" \n"
"color: rgb(0, 0, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"font: 18pt \"Impact\";\n"
" \n"
"background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(205, 94, 230, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

        gridLayout_3->addWidget(pushButton, 0, 2, 1, 1);

        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(0, 50));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 2, 0, 1, 3);

        lcdNumber_2 = new QLCDNumber(tab);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));

        gridLayout_3->addWidget(lcdNumber_2, 3, 2, 1, 1);

        lcdNumber = new QLCDNumber(tab);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(0, 100));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lcdNumber->setFont(font2);
        lcdNumber->setLayoutDirection(Qt::RightToLeft);
        lcdNumber->setAutoFillBackground(true);
        lcdNumber->setStyleSheet(QStringLiteral(""));
        lcdNumber->setFrameShape(QFrame::StyledPanel);
        lcdNumber->setSegmentStyle(QLCDNumber::Outline);

        gridLayout_3->addWidget(lcdNumber, 3, 0, 1, 2);


        verticalLayout_5->addLayout(gridLayout_3);

        QIcon icon;
        QString iconThemeName = QStringLiteral("black");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setAutoFillBackground(true);
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_36 = new QPushButton(tab_2);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));

        gridLayout_5->addWidget(pushButton_36, 6, 4, 1, 1);

        pushButton_35 = new QPushButton(tab_2);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));

        gridLayout_5->addWidget(pushButton_35, 6, 3, 1, 1);

        pushButton_34 = new QPushButton(tab_2);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));

        gridLayout_5->addWidget(pushButton_34, 6, 2, 1, 1);

        pushButton_33 = new QPushButton(tab_2);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));

        gridLayout_5->addWidget(pushButton_33, 6, 1, 1, 1);

        pushButton_32 = new QPushButton(tab_2);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));

        gridLayout_5->addWidget(pushButton_32, 6, 0, 1, 1);

        pushButton_31 = new QPushButton(tab_2);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));

        gridLayout_5->addWidget(pushButton_31, 5, 4, 1, 1);

        pushButton_30 = new QPushButton(tab_2);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));

        gridLayout_5->addWidget(pushButton_30, 5, 3, 1, 1);

        pushButton_29 = new QPushButton(tab_2);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));

        gridLayout_5->addWidget(pushButton_29, 5, 2, 1, 1);

        pushButton_28 = new QPushButton(tab_2);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));

        gridLayout_5->addWidget(pushButton_28, 5, 1, 1, 1);

        pushButton_27 = new QPushButton(tab_2);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));

        gridLayout_5->addWidget(pushButton_27, 5, 0, 1, 1);

        pushButton_26 = new QPushButton(tab_2);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));

        gridLayout_5->addWidget(pushButton_26, 4, 0, 1, 1);

        pushButton_25 = new QPushButton(tab_2);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));

        gridLayout_5->addWidget(pushButton_25, 3, 0, 1, 1);

        pushButton_24 = new QPushButton(tab_2);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));

        gridLayout_5->addWidget(pushButton_24, 2, 0, 1, 1);

        pushButton_23 = new QPushButton(tab_2);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));

        gridLayout_5->addWidget(pushButton_23, 1, 0, 1, 1);

        redButton_22 = new QPushButton(tab_2);
        redButton_22->setObjectName(QStringLiteral("redButton_22"));
        redButton_22->setMinimumSize(QSize(0, 0));
        redButton_22->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        gridLayout_5->addWidget(redButton_22, 0, 0, 1, 1);

        pushButton_17 = new QPushButton(tab_2);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));

        gridLayout_5->addWidget(pushButton_17, 4, 4, 1, 1);

        pushButton_16 = new QPushButton(tab_2);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout_5->addWidget(pushButton_16, 4, 3, 1, 1);

        pushButton_15 = new QPushButton(tab_2);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout_5->addWidget(pushButton_15, 4, 2, 1, 1);

        pushButton_14 = new QPushButton(tab_2);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout_5->addWidget(pushButton_14, 4, 1, 1, 1);

        pushButton_21 = new QPushButton(tab_2);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));

        gridLayout_5->addWidget(pushButton_21, 3, 4, 1, 1);

        pushButton_20 = new QPushButton(tab_2);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));

        gridLayout_5->addWidget(pushButton_20, 3, 3, 1, 1);

        pushButton_19 = new QPushButton(tab_2);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));

        gridLayout_5->addWidget(pushButton_19, 3, 2, 1, 1);

        pushButton_18 = new QPushButton(tab_2);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));

        gridLayout_5->addWidget(pushButton_18, 3, 1, 1, 1);

        pushButton_13 = new QPushButton(tab_2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout_5->addWidget(pushButton_13, 2, 4, 1, 1);

        pushButton_12 = new QPushButton(tab_2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout_5->addWidget(pushButton_12, 2, 3, 1, 1);

        pushButton_11 = new QPushButton(tab_2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout_5->addWidget(pushButton_11, 2, 2, 1, 1);

        pushButton_10 = new QPushButton(tab_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_5->addWidget(pushButton_10, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_5->addWidget(pushButton_9, 1, 4, 1, 1);

        pushButton_8 = new QPushButton(tab_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout_5->addWidget(pushButton_8, 1, 3, 1, 1);

        pushButton_7 = new QPushButton(tab_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_5->addWidget(pushButton_7, 1, 2, 1, 1);

        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_5->addWidget(pushButton_6, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_5->addWidget(pushButton_5, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_5->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 0));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));

        gridLayout_5->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 0));
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));

        gridLayout_5->addWidget(pushButton_2, 0, 1, 1, 1);

        LED_OFF_Button_37 = new QPushButton(tab_2);
        LED_OFF_Button_37->setObjectName(QStringLiteral("LED_OFF_Button_37"));

        gridLayout_5->addWidget(LED_OFF_Button_37, 7, 0, 1, 5);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        iDom_Client->setCentralWidget(centralWidget);

        retranslateUi(iDom_Client);
        QObject::connect(exitButton, SIGNAL(released()), iDom_Client, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(iDom_Client);
    } // setupUi

    void retranslateUi(QMainWindow *iDom_Client)
    {
        iDom_Client->setWindowTitle(QApplication::translate("iDom_Client", "iDom_Client", 0));
        titleTXT->setInputMask(QApplication::translate("iDom_Client", "reerewreerereererfevfvev", 0));
        volumeTXT->setInputMask(QApplication::translate("iDom_Client", "34254545345", 0));
        LOGO->setText(QString());
        playButton->setText(QApplication::translate("iDom_Client", "PLAY", 0));
        exitButton->setText(QApplication::translate("iDom_Client", "EXIT", 0));
#ifndef QT_NO_TOOLTIP
        stopButton->setToolTip(QApplication::translate("iDom_Client", "<html><head/><body><p>stop play music</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        stopButton->setText(QApplication::translate("iDom_Client", "STOP", 0));
        disconnectButton->setText(QApplication::translate("iDom_Client", "DISCONNECT", 0));
        wynik->setHtml(QApplication::translate("iDom_Client", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">tu beda wyniki</p></body></html>", 0));
        pushButton->setText(QApplication::translate("iDom_Client", "SEND", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("iDom_Client", "CONSOLE", 0));
        pushButton_36->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_35->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_34->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_33->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_32->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_31->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_30->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_29->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_28->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_27->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_26->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_25->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_24->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_23->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        redButton_22->setText(QString());
        pushButton_17->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_16->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_15->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_14->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_21->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_20->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_19->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_18->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_13->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_12->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_11->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_10->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_9->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_8->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_7->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_6->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        LED_OFF_Button_37->setText(QApplication::translate("iDom_Client", "LED OFF", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("iDom_Client", "INFO", 0));
    } // retranslateUi

};

namespace Ui {
    class iDom_Client: public Ui_iDom_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDOM_CLIENT_H
