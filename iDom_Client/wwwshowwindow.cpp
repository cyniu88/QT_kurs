#include "wwwshowwindow.h"
#include "ui_wwwshowwindow.h"
#include <QDebug>
wwwShowWindow::wwwShowWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wwwShowWindow)
{
    ui->setupUi(this);
#ifdef Q_OS_WIN
    axWidgetTemperature.setControl("{8856f961-340a-11d0-a96b-00c04fd705a2}");
    ui->widgetWWW_temp->layout()->addWidget( axWidgetTemperaturePTR);
    axWidgetTemperature.dynamicCall("Navigate(const QString&)", "http://cyniu88.no-ip.pl/lusina2.html");
#endif
#ifdef Q_OS_ANDROID

#endif
}

wwwShowWindow::~wwwShowWindow()
{
    qDebug() << "\n\n\n destruktor!!!!!!!";
#ifdef Q_OS_ANDROID
    delete viewTemp;
#endif
    delete ui;
}

void wwwShowWindow::on_pushButton_clicked()
{
#ifdef Q_OS_WIN
    axWidgetTemperature .dynamicCall("Navigate(const QString&)", "http://cyniu88.no-ip.pl/lusina2.html");
#endif
#ifdef Q_OS_ANDROID
    if (viewTemp != NULL) {
        delete viewTemp;
    }
    viewTemp =  new QQuickWidget;
    viewTemp->setSource(QUrl::fromLocalFile(":/www/myqmlfileforwww.qml"));
    ui->widgetWWW_temp->layout()->addWidget(viewTemp);
    viewTemp->showMaximized();
#endif
}

void wwwShowWindow::on_pushButton_2_clicked()
{
#ifdef Q_OS_ANDROID
    viewTemp->hide();
    delete viewTemp;
    viewTemp = NULL;
#endif
}
