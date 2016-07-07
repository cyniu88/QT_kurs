#include "workerip.h"
#include <QDebug>
#include <QTcpSocket>
#include <QString>

WorkerIP::WorkerIP(iDom_CONFIG *config) : config(config)
{

}

void WorkerIP::run()
{
    QTcpSocket *socket;
    QByteArray buffor;

    socket = new QTcpSocket(this );
    QThread::sleep(3);

    socket->connectToHost(config->serverIP.c_str(),config->serverPort);
    //socket->connectToHost("cyniu88.no-ip.pl",8833);

    if(socket->waitForConnected(500))
    {
        qDebug() << "Connected!";

        // send
        socket->write(  RSHash().c_str());
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);

        qDebug() << "Reading ready : " << socket->bytesAvailable();

        // get the data
        buffor = socket->readAll();
        socket->waitForReadyRead(3000);
        socket->write("OK");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading2: " << socket->bytesAvailable();

        // get the data
        buffor = socket->readAll();
        qDebug() << "wiadomosc2"<<buffor;
        s_buffor = buffor.toStdString();


        if (s_buffor[0]=='O' && s_buffor[1]=='K'){
            qDebug ()<< "Autentykacja ok";
            config->goWhile=true;
        }
        else{
            qDebug() << "Autentykacja faild";
        }
        unsigned int len_send = 0;
        unsigned int len_temp = 0;
        while (config->goWhile){
            //qDebug() << " before lock";

            if (to_send == false){
                QThread::usleep(100);
                continue;
            }
            emit progress(0);
            socket->write( msg.c_str());
            to_send = false;
            //config->IPMutex.unlock();

            socket->waitForBytesWritten(1000);
            socket->waitForReadyRead(3000);

            qDebug() << "Reading: " << socket->bytesAvailable();
            buffor = socket->readAll();
            //socket->waitForBytesWritten(1000);
            //socket->waitForReadyRead(3000);
            socket->write("OK");
            qDebug() << buffor;
            s_buffor = buffor.toStdString();
            len_send = atoi (s_buffor.c_str());


            emit sygnal2(len_send);
            buffor.clear();
            s_buffor.erase();
            while (true){
                socket->waitForReadyRead(3000);
                /////////////

                emit sygnal(++counter);


                emit progress(    (100*s_buffor.length())/len_send          );



                qDebug() << "Reading: " << socket->bytesAvailable();
                buffor = socket->readAll();
                s_buffor += buffor.toStdString();
                if (s_buffor.length()==len_send){


                    emit sygnal(s_buffor.length());
                    qDebug("mam wsztstko!");
                    qDebug() << QString::fromStdString(s_buffor);


                    if (what == "console"){
                        emit answer( QString::fromStdString(s_buffor));
                    }
                    else if(what == "LED")
                    {
                        emit answerLED(QString::fromStdString(s_buffor));
                    }

                    break;
                }


            }


        }
        // close the connection
        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
        emit errorInfo ("INFO","Not connected!");
    }


}

void WorkerIP::fromTCP(std::string addres , std::string qmsg)
{
    to_send = true;
    what = addres;
    msg = qmsg ;
    qDebug("przyzedl sygnal");
}
