#include "workerip.h"
#include <QDebug>
#include <QTcpSocket>
#include <QString>

WorkerIP::WorkerIP(my_config *config) : config(config)
{

}

void WorkerIP::run()
{

    config->goWhile = connectAndAuthentication();



    bool goNow = true;
    //    ////////////////////////////////////////////////////
    //    ///////////// po autentykacji //////////////////////
    //    ////////////////////////////////////////////////////
    while (goNow){


        if ( config->goWhile ==  false)
        {
            socket->write("DISCONNECT");
            waitSend(waitTime, counterWaitTime);
            break;
        }


        socket->write(config->messageS.getString().toStdString().c_str());
        // socket->write("1232434535345345#");
        waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
        waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);

        buffor = socket->readAll();
        qDebug() << buffor;


    }

    // close the connection
    disconnectFromServer();
    //    qDebug("koniec koncow workera @@@@@@@@@@@@");
    config->goWhile=true;

}

bool WorkerIP::connectAndAuthentication()
{
    socket = new QTcpSocket(this );
    qDebug()<< "mamy " << config->addressIP.c_str() << "  "<< config->port<<" polaczenie ";
    socket->connectToHost(config->addressIP.c_str(),config->port);
    QThread::sleep(3);
    qDebug()<< socket->state();

    return true;
}

bool WorkerIP::disconnectFromServer()
{

    QThread::sleep(1);
    socket->disconnect();
    socket->close();
    delete socket;
    return true;
}

void WorkerIP::waitSend(int waitTime, int counter)
{
    for (int i = 0; i< counter;++i){
        //qDebug() << "czekam na zapis "<< QString::number(i);
        if (socket->waitForBytesWritten(waitTime)==true)
        {
            return;
        }

    }

}

void WorkerIP::waitRecv(int waitTime, int counter)
{   bool temp;
    for (int i = 0; i< counter;++i){
        temp = socket->waitForReadyRead(waitTime);
        // qDebug() << "czekam na odczyt "<< QString::number(i) <<" bool:"<<temp;

        if (temp ==true)
        {
            return;
        }

    }

}




