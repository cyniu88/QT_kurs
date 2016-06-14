/********************************************************************************
** Form generated from reading UI file 'idom_client.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iDom_Client
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *LOGO;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *icona;
    QWidget *tab_2;

    void setupUi(QMainWindow *iDom_Client)
    {
        if (iDom_Client->objectName().isEmpty())
            iDom_Client->setObjectName(QStringLiteral("iDom_Client"));
        iDom_Client->resize(480, 800);
        iDom_Client->setMinimumSize(QSize(480, 800));
        iDom_Client->setMouseTracking(true);
        iDom_Client->setFocusPolicy(Qt::StrongFocus);
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
        LOGO = new QLabel(centralWidget);
        LOGO->setObjectName(QStringLiteral("LOGO"));
        LOGO->setPixmap(QPixmap(QString::fromUtf8("../build-iDom-cli/f/logo.png")));

        gridLayout_2->addWidget(LOGO, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        gridLayout_2->addLayout(verticalLayout_3, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 350));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(160, 160));
        tabWidget->setElideMode(Qt::ElideRight);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 610, 93, 28));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(80, 280, 241, 131));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 129));
        icona = new QPushButton(scrollAreaWidgetContents);
        icona->setObjectName(QStringLiteral("icona"));
        icona->setGeometry(QRect(10, 0, 221, 125));
        icona->setMinimumSize(QSize(150, 125));
        icona->setMaximumSize(QSize(16777215, 16777211));
        QIcon icon;
        icon.addFile(QStringLiteral("../build-iDom-cli/f/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        icona->setIcon(icon);
        icona->setIconSize(QSize(150, 125));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        iDom_Client->setCentralWidget(centralWidget);

        retranslateUi(iDom_Client);

        QMetaObject::connectSlotsByName(iDom_Client);
    } // setupUi

    void retranslateUi(QMainWindow *iDom_Client)
    {
        iDom_Client->setWindowTitle(QApplication::translate("iDom_Client", "iDom_Client", 0));
        LOGO->setText(QString());
        pushButton_2->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("iDom_Client", "PushButton", 0));
        icona->setText(QApplication::translate("iDom_Client", "OK", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("iDom_Client", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("iDom_Client", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class iDom_Client: public Ui_iDom_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDOM_CLIENT_H
