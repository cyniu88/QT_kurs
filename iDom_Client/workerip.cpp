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


        buffor = readMsgTCP();

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
        else if (addresOUT.address == "state")
        {
            emit answerState(QString::fromStdString(buffor));
        }
        else if (addresOUT.address =="TTS"){
            emit signalFromTTS(QString::fromStdString(buffor));
        }
        pingTimeMilis = pingStart.msecsTo( QDateTime::currentDateTime());

        emit pingTime(QString::number((double)(pingTimeMilis/1000) )+" sec");
     //   qDebug() << "PING " << (double)(pingTimeMilis/1000);
    }

//  }
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

            buffor = readMsgTCP();

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
    std::string buffor   = readMsgTCP();
    qDebug() << "user level "<< buffor.c_str();
}

qint64 WorkerIP::sendMsgTCP(std::string msg)
{
    crypt(msg,config->m_RSHash,config->encrypted);
    //qDebug() << "wyslano " << msg.c_str();
    //QByteArray m = QString(msg.c_str()).toLocal8Bit();
    qint64 counter =  socket->write(QByteArray(msg.c_str(), static_cast<int>(msg.length())   )  ) ;
    waitSend(waitTime, counterWaitTime); //socket->waitForBytesWritten(waitTime);
    crypt(msg,config->m_RSHash,config->encrypted);
    //    qDebug() << "dekodowanie " << msg.c_str();
    return counter;
}

std::string WorkerIP::readMsgTCP()
{
    if ( socket->state() ==  QAbstractSocket::UnconnectedState)
    {
        emit serverDisconnected();
        config->isConnectedToServer =  false;
        qDebug() << "OOOOOOOOOOOOO Cos nie dziala!";
        return "";
    }

    waitRecv(waitTime, counterWaitTime);

    std::string buf = socket->readAll().toStdString();
    crypt(buf,config->m_RSHash,config->encrypted );
    sendMsgTCP( "OK");
    waitSend(waitTime, counterWaitTime);            //socket->waitForBytesWritten(waitTime);
   // qDebug() << "odebralismy "<< buf.c_str();
    unsigned int size  = atoi(buf.c_str());
    buf.erase();
  //  qDebug() << "int do odebrania  "<< size;
    while(true){
        waitRecv(waitTime, counterWaitTime); // socket->waitForReadyRead(waitTime);

        buf.append(socket->readAll().toStdString());
        emit sendActual(static_cast<int>(buf.length()));
        emit progress(  static_cast<int>(  (100*buf.length())/size ) );
        emit sendAll(static_cast<int>(size) );
        if(buf.length()>= size){
            break;
        }

    }
    emit sendActual(static_cast<int>(buffor.length()));
    emit sendAll(static_cast<int>(size));

    crypt(buf,config->m_RSHash,config->encrypted );
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
