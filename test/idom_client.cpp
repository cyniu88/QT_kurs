#include "idom_client.h"
#include "ui_idom_client.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QSensor>
#include <QLightReading>
#include <QLightSensor>
#include <QAccelerometer>
#include <QOrientationSensor>
#include <QOrientationReading>
iDom_client::iDom_client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iDom_client)
{
    ui->setupUi(this);
}

iDom_client::~iDom_client()
{
    delete ui;
}



void iDom_client::on_progressBar_valueChanged(int value)
{
qDebug("zmieniam ");

}

void iDom_client::on_pushButton_clicked()
{
    qDebug("dzis klikam");
  ui->progressBar->setValue(++i);
}

void iDom_client::on_pushButton_released()
{
    ui->lcdNumber->display(i);
}



void iDom_client::on_swiatlo_clicked()
{
    // start the sensor
      QSensor sensor("QAccelerometer");
      sensor.start();

      // later
      QSensorReading *reading = sensor.reading();
      qreal x = reading->property("x").value<qreal>();
      qreal y = reading->value(1).value<qreal>();






    ui->lcdNumber->display(  x         );
}

void iDom_client::on_lineEdit_editingFinished()
{
     QMessageBox::information(this,"Wiadomosc",ui->lineEdit->text());
}
