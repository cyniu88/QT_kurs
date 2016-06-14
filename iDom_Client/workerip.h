#ifndef WORKERIP_H
#define WORKERIP_H

#include <QThread>
class WorkerIP : public QThread
{
public:
    WorkerIP();
    void run();
};

#endif // WORKERIP_H
