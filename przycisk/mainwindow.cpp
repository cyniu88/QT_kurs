#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);









    ui->lineEdit->setText("koko");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update( ){
    static int i ;
    ++i;
    QSensor sensor("QTiltSensor");
    QSensor sensor2("QMagnetometer");
    QSensor sensor3("QAccelerometer");
    sensor.start();

    sensor2.start();

    sensor3.start();

    QThread::sleep(1);

            ui->lineEdit->setText("start");

            ui->lineEdit->setText("po sleep");
//----------------------TiltSensor--------------///////

    QSensorReading *reading = sensor.reading();
    qreal xrotation = reading->property("xRotation").value<qreal>();
    qreal yrotation = reading->property("yRotation").value<qreal>();

//---------------QMagnetometer-------------------/////////


 ;
    QSensorReading *reading2 = sensor2.reading();
    qreal xmagnet = reading2->property("x").value<qreal>();
    qreal ymagnet = reading2->property("y").value<qreal>();
    qreal zmagnet = reading2->property("z").value<qreal>();

//----------------------QAccelerometer--------------------------/////



    QSensorReading *reading3 = sensor3.reading();
    qreal xAccel = reading3->property("x").value<qreal>();
    qreal yAccel = reading3->property("y").value<qreal>();
    qreal zAccel = reading3->property("z").value<qreal>();
//-----------------------------------------------------------------///




    {
    ui->lineEdit_2->setText(QString::number(xrotation));
    ui->lineEdit_3->setText(QString::number(yrotation));

    }

    {
            ui->lineEdit_4->setText(QString::number(xmagnet));
            ui->lineEdit_5->setText(QString::number(ymagnet));
            ui->lineEdit_6->setText(QString::number(zmagnet));
    }


    {
            ui->lineEdit_7->setText(QString::number(xAccel));
            ui->lineEdit_8->setText(QString::number(yAccel));
            ui->lineEdit_9->setText(QString::number(zAccel));
    }
    ui->lineEdit->setText("po wyspisaniu "+QString::number(i));
    }

void MainWindow::on_pushButton_released()
{

        update();

}
