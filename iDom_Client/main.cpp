#include <QApplication>
#include <QDebug>
#include <QObject>
#include <QSettings>
#include <QTimer>

#ifdef Q_OS_ANDROID
#include <QtWebView>
#endif

#include "idom_client.h"
#include "variable.h"
#include "workerip.h"

//std::string buffor;

int main(int argc, char *argv[])
{
    auto *infoMPDtimer = new QTimer ();
    auto *infoTemperatureTimer = new QTimer();

    iDom_CONFIG config;
    QSettings settings("cyniu", "iDom");
    QString ip = settings.value("serverAddres").toString();
    config.serverIP = ip.toStdString();
    auto * worker = new WorkerIP(&config);
    config.worketPTR  = worker;
    QApplication a(argc, argv);

#ifdef Q_OS_ANDROID
    QtWebView::initialize();
#endif

    iDom_Client * w = new iDom_Client(&config);

    QObject::connect(w,SIGNAL(sendTCP(std::string,std::string)), worker,SLOT(fromTCP(std::string,std::string)));

    QObject::connect(worker,SIGNAL(sendActual(int )),           w,SLOT(setLcdActual(int)));
    QObject::connect(worker,SIGNAL(sendAll(int )),              w,SLOT(setLcdAll(int)));
    QObject::connect(worker,SIGNAL(answer(QString)),            w,SLOT(odb_answer(QString)));
    QObject::connect(worker,SIGNAL(progress(int)),              w,SLOT(readProgress(int)));
    QObject::connect(worker,SIGNAL(answerLED(QString)),         w,SLOT(odb_answer_LED(QString))    );
    QObject::connect(worker,SIGNAL(answerMPD(QString)),         w,SLOT(odb_answer_MPD(QString))  );
    QObject::connect(worker,SIGNAL(answerAlarm(QString)),       w,SLOT(odb_answer_alarm(QString)) );
    QObject::connect(worker,SIGNAL(mpd_title_info(QString)),    w,SLOT(odb_mpd_title(QString)) );
    QObject::connect(worker,SIGNAL(mpd_volumeInfo(QString)),    w,SLOT(odbMpdVolume(QString))  );
    QObject::connect(worker,SIGNAL(errorInfo(QString,QString)), w,SLOT(makeInfo(QString,QString))  );
    QObject::connect(worker,SIGNAL(temperature(QString)),       w,SLOT(odb_temperature(QString)) );
    QObject::connect(worker,SIGNAL(tools(QString)),             w,SLOT(odb_tools(QString))  );
    QObject::connect(worker,SIGNAL(listMPD(QString)),           w,SLOT(listMPD(QString))  );
    QObject::connect(worker,SIGNAL(signalFromTTS(QString)),     w,SLOT(textToSpeachSLOTS(QString)) );
    QObject::connect(worker,SIGNAL(serverDisconnected(bool)),   w,SLOT(connectDisconnectButtonState(bool))  );
    QObject::connect(worker,SIGNAL(pingTime(QString)),          w,SLOT(getPing(QString))    );
    QObject::connect(worker,SIGNAL(answerState(QString)),       w,SLOT(odb_answer_state(QString))   );

    QObject::connect(infoMPDtimer,SIGNAL(timeout()),            w,SLOT(updateMPDinfo()) );
    QObject::connect(infoTemperatureTimer,SIGNAL(timeout()),    w,SLOT(updateTemepretureInfo()) );
    //QObject::connect(taskHandlerTimer, SIGNAL(timeout()),       w,SLOT(taskHandler()));

    worker->start();
    w->updateMPDinfo();
    w->updateTemepretureInfo();
    w->readSettings();
    w->show();
    infoTemperatureTimer->start(60000);
    infoMPDtimer->start(10000);
    //taskHandlerTimer->start(900);

    a.exec();
    config.goWhile=false;
    int i = 0;
    while (config.goWhile==false)
    {
        qDebug() << "czekam: "+QString::number(++i) ;
        if (i>80000)
        {
            break;
        }
    }
    infoMPDtimer->stop();
    infoTemperatureTimer->stop();
   // taskHandlerTimer->stop();
    worker->terminate();
    delete infoMPDtimer;
    delete infoTemperatureTimer;
   // delete taskHandlerTimer;
    delete worker;
    delete w;

    return 0;
}
