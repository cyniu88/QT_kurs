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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iDom_Client
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *LOGO;

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
        centralWidget->setMinimumSize(QSize(480, 800));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LOGO = new QLabel(centralWidget);
        LOGO->setObjectName(QStringLiteral("LOGO"));
        LOGO->setMinimumSize(QSize(234, 89));
        LOGO->setMaximumSize(QSize(234, 151));
        LOGO->setSizeIncrement(QSize(0, 0));
        LOGO->setPixmap(QPixmap(QString::fromUtf8("../build-iDom_Client-Desktop_Qt_5_6_0_MinGW_32bit-Release/f/logo.png")));
        LOGO->setScaledContents(true);

        gridLayout->addWidget(LOGO, 0, 0, 1, 1);

        iDom_Client->setCentralWidget(centralWidget);

        retranslateUi(iDom_Client);

        QMetaObject::connectSlotsByName(iDom_Client);
    } // setupUi

    void retranslateUi(QMainWindow *iDom_Client)
    {
        iDom_Client->setWindowTitle(QApplication::translate("iDom_Client", "iDom_Client", 0));
        LOGO->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class iDom_Client: public Ui_iDom_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDOM_CLIENT_H
