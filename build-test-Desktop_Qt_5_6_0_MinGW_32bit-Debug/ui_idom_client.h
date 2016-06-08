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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_iDom_client
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
    QToolButton *toolButton;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *swiatlo;
    QFrame *line;
    QScrollBar *horizontalScrollBar;

    void setupUi(QMainWindow *iDom_client)
    {
        if (iDom_client->objectName().isEmpty())
            iDom_client->setObjectName(QStringLiteral("iDom_client"));
        iDom_client->resize(800, 480);
        centralWidget = new QWidget(iDom_client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(350, 70, 131, 71));
        lcdNumber->setProperty("value", QVariant(9999));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(170, 90, 141, 111));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(500, 210, 201, 91));
        progressBar->setValue(12);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 80, 161, 71));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(210, 270, 161, 71));
        swiatlo = new QPushButton(centralWidget);
        swiatlo->setObjectName(QStringLiteral("swiatlo"));
        swiatlo->setGeometry(QRect(340, 170, 121, 61));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(360, 150, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(450, 340, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        iDom_client->setCentralWidget(centralWidget);

        retranslateUi(iDom_client);

        QMetaObject::connectSlotsByName(iDom_client);
    } // setupUi

    void retranslateUi(QMainWindow *iDom_client)
    {
        iDom_client->setWindowTitle(QApplication::translate("iDom_client", "iDom_client", 0));
        toolButton->setText(QApplication::translate("iDom_client", "...", 0));
        pushButton->setText(QApplication::translate("iDom_client", "PushButton", 0));
        lineEdit->setText(QApplication::translate("iDom_client", "wpisz komende ", 0));
        swiatlo->setText(QApplication::translate("iDom_client", "Swiatlo", 0));
    } // retranslateUi

};

namespace Ui {
    class iDom_client: public Ui_iDom_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDOM_CLIENT_H
