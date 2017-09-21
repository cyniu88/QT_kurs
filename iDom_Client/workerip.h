#ifndef WORKERIP_H
#define WORKERIP_H

#include <QMessageBox>
#include <QTcpSocket>
#include <QThread>
#include <QObject>
#include <QTime>
#include "functions.h"
#include "variable.h"
#include "blocking_queue/blocking_queue.h"

extern std::string s_buffor;
class WorkerIP : public QThread
{
  Q_OBJECT
public:
    WorkerIP(iDom_CONFIG * config);
    ~WorkerIP()= default;
    void run();
    iDom_CONFIG *config;

private:
    int counter = 0;
    int counter2 = 0;
    int progresCounter = 0;
    bool to_send= false;
    ADRESS_WHAT addresIN;
    ADRESS_WHAT addresOUT;
    int waitTime = 1000;
    int counterWaitTime = 20;
    QDateTime pingStart;
    qint64 pingTimeMilis;
    QTcpSocket *socket;
    QByteArray buffor;
    bool connectAndAuthentication();
    bool disconnectFromServer();
    void waitSend(int waitTime, int counter);
    void waitRecv(int waitTime, int counter);
    void setUserLevel(QString levelName);
    qint64 sendMsgTCP(std::string msg);
    QByteArray readMsgTCP();

signals:
    void sendActual(int c);
    void sendAll(int c);
    void progress(int c);
    void answer(QString s);
    void answerLED(QString s);
    void answerMPD(QString s);
    void errorInfo(QString tit, QString msg);
    void mpd_title_info(QString s);
    void mpd_volumeInfo(QString s);
    void temperature (QString s);
    void tools (QString s);
    void listMPD(QString s);
    void signalFromTTS(QString s);
    void serverDisconnected(bool state = false);
    void pingTime(QString s);

public slots:
    void fromTCP(std::string addres, std::string qmsg);
    void tcpSocketDisconnected();
};

#endif // WORKERIP_H
