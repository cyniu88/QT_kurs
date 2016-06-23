#include "idom_client.h"
#include "variable.h"
#include <QApplication>
//#include <android/api-level.h>
#include "workerip.h"


std::string s_buffor;
int main(int argc, char *argv[])
{
    iDom_CONFIG config;


    config.IPMutex.lock();
    WorkerIP worker(&config);
    worker.start();
    QApplication a(argc, argv);
    iDom_Client w(&config);





     w.show();

    return a.exec();
}
