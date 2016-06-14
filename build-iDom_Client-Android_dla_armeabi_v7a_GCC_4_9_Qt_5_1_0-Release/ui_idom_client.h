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
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QGroupBox *groupBox;
    QSpinBox *spinBox;
    QLCDNumber *lcdNumber;
    QDial *dial;
    QProgressBar *progressBar;

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

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(60, 120, 121, 61));
        QFont font;
        font.setPointSize(25);
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox->setMaximum(9999);
        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(70, 60, 121, 51));
        dial = new QDial(groupBox);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(320, 120, 101, 101));
        dial->setValue(5);
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(70, 300, 261, 71));
        progressBar->setValue(24);

        gridLayout_2->addWidget(groupBox, 1, 0, 1, 2);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        iDom_Client->setCentralWidget(centralWidget);

        retranslateUi(iDom_Client);

        QMetaObject::connectSlotsByName(iDom_Client);
    } // setupUi

    void retranslateUi(QMainWindow *iDom_Client)
    {
        iDom_Client->setWindowTitle(QApplication::translate("iDom_Client", "iDom_Client", 0));
        LOGO->setText(QString());
        pushButton_2->setText(QApplication::translate("iDom_Client", "EXIT", 0));
        pushButton->setText(QApplication::translate("iDom_Client", "CONNECT", 0));
        groupBox->setTitle(QApplication::translate("iDom_Client", "GroupBox", 0));
    } // retranslateUi

};

namespace Ui {
    class iDom_Client: public Ui_iDom_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDOM_CLIENT_H
