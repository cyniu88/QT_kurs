#include "workerip.h"
#include <QDebug>
#include <QTcpSocket>
#include <QString>
#include <QElapsedTimer>

WorkerIP::WorkerIP(iDom_CONFIG *config) : config(config)
{
}

void WorkerIP::run()
{
    QElapsedTimer timer;
    timer.start();
    qDebug ()<< "Autentykacja Start";
    config->goWhile = connectAndAuthentication();
    //socket->setParent(this);
    qDebug() << "trwala" << timer.elapsed();

    setUserLevel("ROOT");
    unsigned int len_send = 0;
    config->isConnectedToServer = true;
    bool goNow = true;
    ////////////////////////////////////////////////////
    ///////////// po autentykacji //////////////////////
    ////////////////////////////////////////////////////
    while (goNow){
        if ( config->goWhile ==  false)
        {
            break;
        }
        if ( static_cast<int> (config->workerQueue.Size()) < 1){
            QThread::usleep(10);
            continue;
        }

        addresOUT = config->workerQueue.Take();
        emit progress(0);
        if ( socket->state() ==  QAbstractSocket::UnconnectedState)
        {
            config->isConnectedToServer =  false;
            emit serverDisconnected();
            break;
        }
        qDebug() << "wyslano: "<< sendMsgTCP( addresOUT.what );

        waitSend(waitTime, counterWaitTime); //socket->waitForBytesWritten(waitTime);
        waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);

        buffor = readMsgTCP();

        len_send = atoi(buffor.c_str());
        emit sendAll(len_send);

        if ( socket->state() ==  QAbstractSocket::UnconnectedState)
        {
            emit serverDisconnected();
            config->isConnectedToServer =  false;
            break;
        }
        sendMsgTCP("OK");

        waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);

        buffor.clear();
        buffor.erase();

        while (true){
            waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);
            emit sendActual(buffor.length());
            emit progress(    (100*buffor.length())/len_send  );
            emit sendAll(len_send);
            buffor += readMsgTCP();
            //buffor += buffor.toStdString();
            if (buffor.length()>=len_send)
            {
                emit sendActual(buffor.length());
                emit sendAll(len_send);

                if (addresOUT.address == "console"){
                    emit answer( QString::fromStdString(buffor));
                }
                else if(addresOUT.address == "LED")
                {
                    emit answerLED(QString::fromStdString(buffor));
                }
                else if (addresOUT.address == "MPD")
                {
                    emit answerMPD(QString::fromStdString(buffor));
                }
                else if (addresOUT.address == "MPD_volume")
                {
                    emit mpd_volumeInfo   (QString::fromStdString(buffor));
                }
                else if (addresOUT.address == "MPD_title")
                {
                    emit mpd_title_info (QString::fromStdString(buffor));
                }
                else if (addresOUT.address == "temperature")
                {
                    emit temperature (QString::fromStdString(buffor));
                }
                else if (addresOUT.address == "tools")
                {
                    emit tools (QString::fromStdString(buffor));
                }
                else if (addresOUT.address == "listMPD")
                {
                    emit listMPD(QString::fromStdString(buffor));
                }
                else if (addresOUT.address =="TTS"){
                    emit signalFromTTS(QString::fromStdString(buffor));
                }
                pingTimeMilis = pingStart.msecsTo( QDateTime::currentDateTime());

                emit pingTime(QString::number((double)pingTimeMilis/1000)+" sec");
                break;
            }
        }
    }
    // close the connection
    config->isConnectedToServer = false;
    disconnectFromServer();
    qDebug("koniec koncow workera @@@@@@@@@@@@");
    config->goWhile=true;
}

bool WorkerIP::connectAndAuthentication()
{
    socket = new QTcpSocket( );
    QObject::connect(socket,SIGNAL(disconnected()),this,SLOT(tcpSocketDisconnected()));

    for (int i =0 ; i<3 ;++i)
    {
        config->m_RSHash = RSHash(); //generowanie klucza
        qDebug() << "RSHASH: " << config->m_RSHash.c_str();
        socket->connectToHost(config->serverIP.c_str(),config->serverPort);
        if(socket->waitForConnected())
        {
            sendMsgTCP( config->m_RSHash );
            waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
            waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);
            buffor = readMsgTCP();
            sendMsgTCP( "OK");
            waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
            waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);
            buffor = readMsgTCP();
           // buffor = buffor.toStdString();

            if (buffor[0]=='O' && buffor[1]=='K'){
                qDebug ()<< "Autentykacja ok";
                emit errorInfo ("INFO","GOTOWE DO UZYWANIA"  );
                config->goWhile =true;
                emit serverDisconnected(true);
                return true;
            }
            else{
                emit errorInfo ("INFO","Authentication failed " +QString::number(i)+" times!" );
                config->isConnectedToServer = false;
                emit serverDisconnected();
                socket->disconnectFromHost();
                QThread::sleep(3);
                buffor = "";
            }
        }
        else
        {
            emit errorInfo ("INFO","Not connected!");
            config->isConnectedToServer = false;
            emit serverDisconnected();
        }
        QThread::sleep(1);
    }//end for authentication
    return false;
}

bool WorkerIP::disconnectFromServer()
{
    socket->disconnect();
    socket->close();
    delete socket;
    return true;
}

void WorkerIP::waitSend(int waitTime, int counter)
{
    bool temp = true;
    for (int i = 0; i< counter;++i){
        if (config->isConnectedToServer == true)
        {
            temp = socket->waitForBytesWritten(waitTime);
        }
        if (temp == true)
        {
            return;
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

void WorkerIP::setUserLevel(QString levelName)
{
    sendMsgTCP( levelName.toLatin1().data());
    waitSend(waitTime, counterWaitTime); //socket->waitForBytesWritten(waitTime);
    waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);

    std::string buffor = readMsgTCP();
    sendMsgTCP( "OK");
    waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
    waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);
    buffor = readMsgTCP();
    qDebug() << "user level "<< buffor.c_str();

}

qint64 WorkerIP::sendMsgTCP(std::string msg)
{
    crypt(msg,config->m_RSHash);
    qDebug() << "wyslano " << msg.c_str();
    return socket->write(msg.c_str());
}

std::string WorkerIP::readMsgTCP()
{
    std::string buf = socket->readAll().toStdString();
    crypt(buf,config->m_RSHash);
    qDebug() << "odebrano " << buf.c_str();
    return buf;
}

void WorkerIP::fromTCP(std::string addres , std::string qmsg)
{
    pingStart = QDateTime::currentDateTime();
    to_send = true;
    addresIN.address = addres;
    if (qmsg.empty()){
        addresIN.what = "hello";
    }
    else{
        addresIN.what = qmsg ;
    }
    config->workerQueue.Put(addresIN);
}

void WorkerIP::tcpSocketDisconnected()
{
    qDebug("rozlaczony");
    config->isConnectedToServer = false;
}
