
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connect_Button_clicked()
{
    if (isConnected == false){
        mySocket.connectToHost(ui->ipadress->text(),8833);
        ui->connect_Button->setText("DISCONNECT");
        isConnected = true;
    }
    else
    {
        ui->connect_Button->setText("CONNECT");
        mySocket.write("DISCONNECT");
        waitSend(100,20);
        mySocket.disconnect();
        isConnected= false;
    }

}
void MainWindow::waitSend(int waitTime, int counter)
{
    for (int i = 0; i< counter;++i){
        //qDebug() << "czekam na zapis "<< QString::number(i);
        if (mySocket.waitForBytesWritten(waitTime)==true)
        {
           return;
        }

    }

}

void  MainWindow::waitRecv(int waitTime, int counter)
{   bool temp;
    for (int i = 0; i< counter;++i){
        temp =  mySocket.waitForReadyRead(waitTime);

        if (temp ==true)
        {
            return;
        }

    }

}
void MainWindow::on_send_Button_clicked()
{
    QString buffor;
    int waitTime = 100;
    int counterWaitTime = 20;
    mySocket.write(  ui->to_send->text().toStdString().c_str());
    waitSend(waitTime, counterWaitTime);             //socket->waitForBytesWritten(waitTime);
    waitRecv(waitTime, counterWaitTime);             // socket->waitForReadyRead(waitTime);
    buffor = mySocket.readAll();

    ui->response->setText(buffor);
}
