#ifndef WORKERIP_H
#define WORKERIP_H

#include <QMessageBox>
#include <QTcpSocket>
#include <QThread>
#include "functions.h"
#include "variable.h"

#include <QObject>


extern std::string s_buffor;
class WorkerIP : public QThread
{
  Q_OBJECT
public:
    WorkerIP(my_config * config);
    ~WorkerIP()= default;
    void run();
public:
    my_config *config;
private:
    int counter = 0;
    int counter2 = 0;
    unsigned int connectionCounter = 0;
    int progresCounter =0;
    bool to_send= false;

    int waitTime = 1000;
    int counterWaitTime = 20;
    QTcpSocket *socket;
    QByteArray buffor;

    bool connectAndAuthentication();
    bool disconnectFromServer();
    void waitSend(int waitTime, int counter);
    void waitRecv(int waitTime, int counter);

 signals:
    void sendResponse(QString s);
    void sendMSG(QString tit, QString msg);

};

#endif // WORKERIP_H
