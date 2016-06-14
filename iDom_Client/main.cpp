#include "idom_client.h"
#include "variable.h"
#include <QApplication>

#include "workerip.h"


int main(int argc, char *argv[])
{
    iDom_CONFIG config;
    WorkerIP worker(&config);
    worker.start();
    QApplication a(argc, argv);
    iDom_Client w(&config);

    w.show();

    return a.exec();
}
