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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iDom_Client
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *wynik;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *LOGO;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *EXIT_button;
    QPushButton *disconnectButton;
    QVBoxLayout *verticalLayout;
    QPushButton *playButton;
    QPushButton *stopButton;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *titleTXT;
    QLineEdit *volumeTXT;

    void setupUi(QMainWindow *iDom_Client)
    {
        if (iDom_Client->objectName().isEmpty())
            iDom_Client->setObjectName(QStringLiteral("iDom_Client"));
        iDom_Client->resize(1280, 800);
        iDom_Client->setMinimumSize(QSize(480, 800));
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
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 350));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(160, 160));
        tabWidget->setElideMode(Qt::ElideRight);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 20, 381, 91));
        lineEdit->setClearButtonEnabled(true);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(610, 40, 361, 61));
        wynik = new QLabel(tab);
        wynik->setObjectName(QStringLiteral("wynik"));
        wynik->setGeometry(QRect(120, 190, 1111, 171));
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
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        LOGO = new QLabel(centralWidget);
        LOGO->setObjectName(QStringLiteral("LOGO"));
        LOGO->setMinimumSize(QSize(200, 150));
        LOGO->setSizeIncrement(QSize(0, 0));
        LOGO->setLayoutDirection(Qt::LeftToRight);
        LOGO->setFrameShape(QFrame::NoFrame);
        LOGO->setFrameShadow(QFrame::Sunken);
        LOGO->setPixmap(QPixmap(QString::fromUtf8("../build-iDom-cli/f/logo.png")));
        LOGO->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(LOGO, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 10, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        EXIT_button = new QPushButton(centralWidget);
        EXIT_button->setObjectName(QStringLiteral("EXIT_button"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EXIT_button->sizePolicy().hasHeightForWidth());
        EXIT_button->setSizePolicy(sizePolicy);
        EXIT_button->setMaximumSize(QSize(250, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Impact"));
        font.setPointSize(10);
        font.setItalic(true);
        EXIT_button->setFont(font);

        verticalLayout_3->addWidget(EXIT_button);

        disconnectButton = new QPushButton(centralWidget);
        disconnectButton->setObjectName(QStringLiteral("disconnectButton"));
        sizePolicy.setHeightForWidth(disconnectButton->sizePolicy().hasHeightForWidth());
        disconnectButton->setSizePolicy(sizePolicy);
        disconnectButton->setMaximumSize(QSize(250, 16777215));
        QPalette palette;
        QBrush brush(QColor(170, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush);
        QBrush brush1(QColor(0, 0, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush1);
        disconnectButton->setPalette(palette);
        disconnectButton->setFont(font);
        disconnectButton->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_3->addWidget(disconnectButton);


        gridLayout_2->addLayout(verticalLayout_3, 1, 4, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        sizePolicy.setHeightForWidth(playButton->sizePolicy().hasHeightForWidth());
        playButton->setSizePolicy(sizePolicy);
        playButton->setMaximumSize(QSize(250, 16777215));
        playButton->setFont(font);

        verticalLayout->addWidget(playButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        sizePolicy.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy);
        stopButton->setMaximumSize(QSize(250, 16777215));
        stopButton->setFont(font);

        verticalLayout->addWidget(stopButton);


        gridLayout_2->addLayout(verticalLayout, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        gridLayout_2->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        titleTXT = new QLineEdit(centralWidget);
        titleTXT->setObjectName(QStringLiteral("titleTXT"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleTXT->sizePolicy().hasHeightForWidth());
        titleTXT->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        titleTXT->setFont(font1);
        titleTXT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        titleTXT->setReadOnly(true);

        verticalLayout_4->addWidget(titleTXT);

        volumeTXT = new QLineEdit(centralWidget);
        volumeTXT->setObjectName(QStringLiteral("volumeTXT"));
        sizePolicy.setHeightForWidth(volumeTXT->sizePolicy().hasHeightForWidth());
        volumeTXT->setSizePolicy(sizePolicy);
        volumeTXT->setFont(font1);
        volumeTXT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        volumeTXT->setReadOnly(true);

        verticalLayout_4->addWidget(volumeTXT);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        iDom_Client->setCentralWidget(centralWidget);

        retranslateUi(iDom_Client);
        QObject::connect(EXIT_button, SIGNAL(clicked()), iDom_Client, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(iDom_Client);
    } // setupUi

    void retranslateUi(QMainWindow *iDom_Client)
    {
        iDom_Client->setWindowTitle(QApplication::translate("iDom_Client", "iDom_Client", 0));
        pushButton->setText(QApplication::translate("iDom_Client", "go", 0));
        wynik->setText(QApplication::translate("iDom_Client", "wynik", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("iDom_Client", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("iDom_Client", "Tab 2", 0));
        LOGO->setText(QString());
        EXIT_button->setText(QApplication::translate("iDom_Client", "EXIT", 0));
        disconnectButton->setText(QApplication::translate("iDom_Client", "DISCONNECT", 0));
        playButton->setText(QApplication::translate("iDom_Client", "PLAY", 0));
        stopButton->setText(QApplication::translate("iDom_Client", "STOP", 0));
        titleTXT->setInputMask(QApplication::translate("iDom_Client", "reerewreerereererfevfvev", 0));
        volumeTXT->setInputMask(QApplication::translate("iDom_Client", "34254545345", 0));
    } // retranslateUi

};

namespace Ui {
    class iDom_Client: public Ui_iDom_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDOM_CLIENT_H
