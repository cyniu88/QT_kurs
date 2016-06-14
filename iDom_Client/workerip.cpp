#include "workerip.h"
#include <QDebug>
#include <QTcpSocket>
WorkerIP::WorkerIP(iDom_CONFIG *config) : config(config)
{

}

void WorkerIP::run()
{
    QTcpSocket *socket;
    socket = new QTcpSocket(this );
    QThread::sleep(5);

    socket->connectToHost(config->serverIP.c_str(),config->serverPort);
    //socket->connectToHost("cyniu88.no-ip.pl",8833);

        if(socket->waitForConnected(5000))
        {
            qDebug() << "Connected!";

            // send
            socket->write(  RSHash().c_str());
            socket->waitForBytesWritten(1000);
            socket->waitForReadyRead(3000);

            qDebug() << "Reading: " << socket->bytesAvailable();

            // get the data
            qDebug() << socket->readAll();


            socket->write( " RS232 get temperature");
            socket->waitForBytesWritten(1000);
            socket->waitForReadyRead(3000);

            qDebug() << "Reading: " << socket->bytesAvailable();
             qDebug() <<"przeczytano " << socket->readAll();
            //qDebug() << wiadomosc;


            // close the connection
            socket->close();
        }
        else
        {
            qDebug() << "Not connected!";
        }

    qDebug() << "wynik polacznie to: " ;
}
