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
    //ui->quickWidget->setLayout(ui->widgetWWW->layout());


    axWidgetTemperature.dynamicCall("Navigate(const QString&)","http://cyniu88.no-ip.pl/wykres.html");

#endif
}

wwwShowWindow::~wwwShowWindow()
{
    qDebug() << "\n\n\n destruktor!!!!!!!";
    delete ui;
}

void wwwShowWindow::on_pushButton_clicked()
{
#ifdef Q_OS_WIN
        axWidgetTemperature .dynamicCall("Navigate(const QString&)","http://cyniu88.no-ip.pl/wykres.html");
#endif
}
