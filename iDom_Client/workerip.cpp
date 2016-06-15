#include "workerip.h"
#include <QDebug>
#include <QTcpSocket>

WorkerIP::WorkerIP(iDom_CONFIG *config) : config(config)
{

}

void WorkerIP::run()
{
    QTcpSocket *socket;
    QByteArray buffor;
    std::string s_buffor;

    socket = new QTcpSocket(this );
    QThread::sleep(3);

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
        buffor = socket->readAll();
        qDebug() << buffor;
        s_buffor = buffor.toStdString();


        if (s_buffor[0]=='O' && s_buffor[1]=='K'){
            qDebug ()<< "Autentykacja ok";
            config->goWhile=true;
        }
        else{
            qDebug() << "Autentykacja faild";
        }

        while (config->goWhile){
            qDebug() << " before lock";
            config->IPMutex.lock();
            qDebug() << " after e lock";
            socket->write( config->command.c_str());
            config->IPMutex.unlock();

            socket->waitForBytesWritten(1000);
            while (true){


                socket->waitForReadyRead(3000);

                qDebug() << "Reading: " << socket->bytesAvailable();
                buffor = socket->readAll();

                qDebug() << buffor;
                s_buffor = buffor.toStdString();


                if (s_buffor[1]=='E' && s_buffor[2]=='N' && s_buffor[3]=='D'){
                    qDebug ()<< "koniec";
                    QThread::sleep(2);
                    break;
                }
                else{
                    qDebug() << "dalej";
                    socket->write("OK");
                }
            }

        }
        // close the connection
        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }


}
