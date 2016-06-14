#ifndef WORKERIP_H
#define WORKERIP_H

#include <QThread>
#include "functions.h"
#include "variable.h"
class WorkerIP : public QThread
{
public:
    WorkerIP(iDom_CONFIG * config);
    void run();
public:
    iDom_CONFIG *config;
};

#endif // WORKERIP_H
