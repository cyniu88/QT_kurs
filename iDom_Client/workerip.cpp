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
    //QThread::sleep(3);
    for (int i =0 ; i<3 ;++i)
    {
        socket->connectToHost(config->serverIP.c_str(),config->serverPort);


        if(socket->waitForConnected())
        {
            qDebug() << "Connected!";

            // send
            socket->write(  RSHash().c_str());
            while (socket->waitForBytesWritten(1000)){
                qDebug() << "czekam na zapis : ";
            }
            while (true){
                qDebug() << "czekam na ODCZYT : ";
                if (socket->waitForReadyRead(100)==true)
                {
                    break;
                }

            }

            qDebug() << "Reading ready : " << socket->bytesAvailable();

            // get the data
            buffor = socket->readAll();


            socket->write("OK");
            socket->waitForBytesWritten(1000);
            while (true){
                qDebug() << "czekam na ODCZYT 2 : ";
                if (socket->waitForReadyRead(100)==true)
                {
                    break;
                }

            }
            qDebug() << "Reading2: " << socket->bytesAvailable();

            // get the data
            buffor = socket->readAll();
            qDebug() << "wiadomosc2"<<buffor;
            s_buffor = buffor.toStdString();


            if (s_buffor[0]=='O' && s_buffor[1]=='K'){
                qDebug ()<< "Autentykacja ok";
                config->goWhile=true;
                emit errorInfo ("INFO","GOTOWE DO UZYWANIA");
                break;
            }
            else{
                qDebug() << "Autentykacja faild";
                emit errorInfo ("INFO","Authentication failed " +QString::number(i)+" times!");
                socket->disconnect();
            }

        }
        else
        {
            qDebug() << "Not connected!";
            emit errorInfo ("INFO","Not connected!");
        }
    }//end for authentication

    unsigned int len_send = 0;
    unsigned int len_temp = 0;
    while (config->goWhile){


        if ( config->goWhile == false)
        {
            ADRESS_WHAT temp;
            temp.address="console";
            temp.what="exit";
            config->workerQueue.Put(temp);
            socket->close();
        }
        if (config->workerQueue.Size()<1  ){
            QThread::usleep(100);
            continue;
        }


        addresOUT = config->workerQueue.Take();
        emit progress(0);
        socket->write( addresOUT.what.c_str());
        to_send = false;
        //config->IPMutex.unlock();

        socket->waitForBytesWritten(1000);
        while (true){
            qDebug() << "czekam na ODCZYT 2 : ";
            if (socket->waitForReadyRead(100)==true)
            {
                break;
            }

        }

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
            while (true){
                qDebug() << "czekam na ODCZYT 2 : ";
                if (socket->waitForReadyRead(100)==true)
                {
                    break;
                }

            }
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


                if (addresOUT.address == "console"){
                    emit answer( QString::fromStdString(s_buffor));
                }
                else if(addresOUT.address == "LED")
                {
                    emit answerLED(QString::fromStdString(s_buffor));
                }
                else if (addresOUT.address == "MPD")
                {
                    emit answerMPD(QString::fromStdString(s_buffor));
                }
                else if (addresOUT.address == "MPD_volume")
                {
                    emit mpd_volumeInfo   (QString::fromStdString(s_buffor));
                }
                else if (addresOUT.address == "MPD_title")
                {
                    emit mpd_title_info (QString::fromStdString(s_buffor));
                }
                else if (addresOUT.address == "temperature")
                {
                    emit temperature (QString::fromStdString(s_buffor));
                }

                break;
            }


        }


    }
    // close the connection
    socket->close();




}

void WorkerIP::fromTCP(std::string addres , std::string qmsg)
{
    to_send = true;
    addresIN.address = addres;
    addresIN.what = qmsg ;

    config->workerQueue.Put(addresIN);

    qDebug()<< "przyzedl sygnal " << QString::number(config->workerQueue.Size()) ;
}
