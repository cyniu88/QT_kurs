#include "idom_client.h"
#include "variable.h"
#include <QApplication>
//#include <android/api-level.h>
#include "workerip.h"
#include "QObject"

std::string s_buffor;
int main(int argc, char *argv[])
{

    iDom_CONFIG config;


    //config.IPMutex.lock();
    WorkerIP * worker = new WorkerIP(&config);



    QApplication a(argc, argv);
    iDom_Client * w = new iDom_Client(&config);

    QObject::connect(worker,SIGNAL(sygnal(int )), w, SLOT(zmienCounter(int )));
    QObject::connect(worker,SIGNAL(sygnal2(int )), w, SLOT(zmienCounter2(int )));
    QObject::connect(worker,SIGNAL(answer(QString)),w,SLOT(odb_answer(QString)));
    QObject::connect(w,SIGNAL(sendTCP(std::string,std::string)), worker,SLOT(fromTCP(std::string,std::string)));
    QObject::connect(worker,SIGNAL(progress(int)),w,SLOT(readProgress(int)));
    QObject::connect(worker,SIGNAL(answerLED(QString)),w,SLOT(odb_answer_LED(QString))    );
    QObject::connect(worker,SIGNAL(answerMPD(QString)),w,SLOT(odb_answer_MPD(QString))  );
    QObject::connect(worker,SIGNAL(errorInfo(QString,QString)),w,SLOT(errorRead(QString,QString))  );

    worker->start();
    w->show();

    return a.exec();
}
