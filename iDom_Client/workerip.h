#ifndef WORKERIP_H
#define WORKERIP_H

#include <QThread>
#include "functions.h"
#include "variable.h"
#include <QObject>
extern std::string s_buffor;
class WorkerIP : public QThread
{
  Q_OBJECT
public:
    WorkerIP(iDom_CONFIG * config);
    ~WorkerIP()= default;
    void run();
public:
    iDom_CONFIG *config;
private:
    int counter =0;
    int counter2 =0;
    int progresCounter =0;
    bool to_send= false;
    std::string msg;
signals:
    void sygnal(int c);
    void sygnal2(int c);
    void progress(int c);
    void answer(QString s);
public slots:
    void fromTCP(QString addres, std::string qmsg);

};

#endif // WORKERIP_H
