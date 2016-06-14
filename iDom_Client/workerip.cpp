#include "workerip.h"
#include <QDebug>

WorkerIP::WorkerIP()
{

}

void WorkerIP::run()
{
    for (unsigned int i = 0 ; i < 100; ++i)
    {
        qDebug()<< "iteracja watku " << i ;
        QThread::sleep(5);

    }
}
