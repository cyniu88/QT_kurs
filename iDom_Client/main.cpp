#include <QTimer>
#include <QApplication>
#include <QObject>



#include "workerip.h"
#include "idom_client.h"
#include "variable.h"

std::string s_buffor;
int main(int argc, char *argv[])
{

    QTimer *infoMPDtimer = new QTimer ();
    QTimer *infoTemperatureTimer = new QTimer();
    QTimer *scroller = new QTimer ();

    iDom_CONFIG config;


    //config.IPMutex.lock();
    WorkerIP * worker = new WorkerIP(&config);


    QApplication a(argc, argv);
    a.setWindowIcon( QIcon(":/new/prefix1/iDom_client.ico"));

    iDom_Client * w = new iDom_Client(&config);

    QObject::connect(worker,SIGNAL(sygnal(int )), w, SLOT(zmienCounter(int )));
    QObject::connect(worker,SIGNAL(sygnal2(int )), w, SLOT(zmienCounter2(int )));
    QObject::connect(worker,SIGNAL(answer(QString)),w,SLOT(odb_answer(QString)));
    QObject::connect(w,SIGNAL(sendTCP(std::string,std::string)), worker,SLOT(fromTCP(std::string,std::string)));
    QObject::connect(worker,SIGNAL(progress(int)),w,SLOT(readProgress(int)));
    QObject::connect(worker,SIGNAL(answerLED(QString)),w,SLOT(odb_answer_LED(QString))    );
    QObject::connect(worker,SIGNAL(answerMPD(QString)),w,SLOT(odb_answer_MPD(QString))  );
    QObject::connect(worker,SIGNAL(mpd_title_info(QString)),w,SLOT(odb_mpd_title(QString)) );
    QObject::connect(worker,SIGNAL(mpd_volumeInfo(QString)),w,SLOT(odbMpdVolume(QString))  );
    QObject::connect(worker,SIGNAL(errorInfo(QString,QString)),w,SLOT(errorRead(QString,QString))  );
    QObject::connect(infoMPDtimer,SIGNAL(timeout()),w,SLOT(updateMPDinfo()) );
    QObject::connect(infoTemperatureTimer,SIGNAL(timeout()),w,SLOT(updateTemepretureInfo()) );
    QObject::connect(scroller, SIGNAL(timeout()),w,SLOT(scrollTitle()));
    QObject::connect(worker,SIGNAL(temperature(QString)),w,SLOT(odb_temperature(QString)) );
    worker->start();
    w->show();
    infoTemperatureTimer->start(60000);
    infoMPDtimer->start(10000);
    scroller->start(500);


     a.exec();
     config.goWhile=false;
     QThread::sleep(5);
     delete worker;
     infoMPDtimer->stop();
     infoTemperatureTimer->stop();
     scroller->stop();
     delete infoMPDtimer;
     delete infoTemperatureTimer;
     delete scroller;
     delete w;

    return 0;
}
