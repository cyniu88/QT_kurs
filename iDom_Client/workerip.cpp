#include "workerip.h"
#include <QDebug>
#include <QTcpSocket>
#include <QString>

WorkerIP::WorkerIP(iDom_CONFIG *config) : config(config)
{

}

void WorkerIP::run()
{
    // int counter = 100;
    config->goWhile = connectAndAuthentication();

    unsigned int len_send = 0;

    bool goNow = true;
    ////////////////////////////////////////////////////
    ///////////// po autentykacji //////////////////////
    ////////////////////////////////////////////////////
    while (goNow){
        if ( config->goWhile ==  false)
        {
            break;
        }
        if (config->workerQueue.Size()<1  ){
            QThread::usleep(10);
            continue;
        }

        addresOUT = config->workerQueue.Take();

        emit progress(0);

        qDebug() << "wyslano: "<<socket->write( addresOUT.what.c_str());
        waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
        waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);

        buffor = socket->readAll();
        s_buffor = buffor.toStdString();
        len_send = atoi (s_buffor.c_str());
        emit sendAll(len_send);

        socket->write("OK");
        waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);

        buffor.clear();
        s_buffor.erase();

        while (true){
            waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);
            emit sendActual(s_buffor.length());
            emit progress(    (100*s_buffor.length())/len_send  );
            emit sendAll(len_send);
            buffor = socket->readAll();
            s_buffor += buffor.toStdString();
            if (s_buffor.length()>=len_send)
            {
                emit sendActual(s_buffor.length());
                emit sendAll(len_send);

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
                else if (addresOUT.address == "tools")
                {
                    emit tools (QString::fromStdString(s_buffor));
                }

                else if (addresOUT.address == "listMPD")
                {
                    emit listMPD(QString::fromStdString(s_buffor));
                }
                else if (addresOUT.address =="TTS"){
                    emit signalFromTTS(QString::fromStdString(s_buffor));
                }
                break;
            }
        }
    }
    // close the connection
    disconnectFromServer();
    qDebug("koniec koncow workera @@@@@@@@@@@@");
    config->goWhile=true;
}

bool WorkerIP::connectAndAuthentication()
{
    socket = new QTcpSocket(this );

    for (int i =1 ; i<4 ;++i)
    {
        socket->connectToHost(config->serverIP.c_str(),config->serverPort);
        if(socket->waitForConnected())
        {
            socket->write(  RSHash().c_str());
            waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
            waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);
            buffor = socket->readAll();
            socket->write( "OK");
            waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
            waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);
            buffor = socket->readAll();
            s_buffor = buffor.toStdString();

            if (s_buffor[0]=='O' && s_buffor[1]=='K'){
                qDebug ()<< "Autentykacja ok";
                emit errorInfo ("INFO","GOTOWE DO UZYWANIA"  );
                return true;
            }
            else{
                qDebug() << "Autentykacja faild";
                emit errorInfo ("INFO","Authentication failed " +QString::number(i)+" times!" );
                socket->disconnect();
                QThread::sleep(1);
            }
        }
        else
        {
            qDebug() << "Not connected!";
            emit errorInfo ("INFO","Not connected!");
        }
        QThread::sleep(1);
    }//end for authentication
    delete socket;
    return false;
}

bool WorkerIP::disconnectFromServer()
{
    socket->disconnect();
    socket->close();
    delete socket;
    return true;
}
//TODO
void WorkerIP::waitSend(int waitTime, int counter)
{
    for (int i = 0; i< counter;++i){
        try{
            if (socket->waitForBytesWritten(waitTime)==true)
            {
                return;
            }
        }
        catch (...){
            qDebug() << "MAM ZLAPALEM WYJATEK!!";
        }
    }
}

void WorkerIP::waitRecv(int waitTime, int counter)
{
    bool temp;
    for (int i = 0; i< counter;++i){
        temp = socket->waitForReadyRead(waitTime);
        if (temp ==true)
        {
            return;
        }
    }
}

void WorkerIP::fromTCP(std::string addres , std::string qmsg)
{
    to_send = true;
    addresIN.address = addres;
    addresIN.what = qmsg ;
    config->workerQueue.Put(addresIN);
}

