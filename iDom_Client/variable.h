#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <string>
#include <QMutex>
#include <QString>
#include "blocking_queue/blocking_queue.h"

class WorkerIP;

struct ADRESS_WHAT{
    std::string address;
    std::string what;
};

struct iDom_CONFIG {
   // std::string logo_windows = "f/logo.png";
    std::string logo_android = "/storage/emulated/0/f/logo.png";
    //std::string background_img_w = "background.png";
    std::string background_img_a = "/storage/emulated/0/f/background.png";
    std::string serverIP = "cyniu88.no-ip.pl";
   // std::string serverIP="192.168.1.144";
    quint16 serverPort = 8833;
    bool goWhile = false;
    std::string command = "OK";
    bool isWindows = true;
    QMutex IPMutex;
    BlockingQueue<ADRESS_WHAT> workerQueue;
    WorkerIP* worketPTR  ;
    bool isConnectedToServer = false;
};
struct iDom_SYSTEM_INFO{
    QString currentCpuArchitecture = "NULL" ;
    QString kernelType = "NULL";
    QString machineHostName = "NULL";
    QString productVersion = "NULL";
    QString getSystemInfo() {
        return  " | HostName "+ machineHostName+"| CPU Architecture: "+currentCpuArchitecture  + " | OS "+ productVersion+" | kernelType "+ kernelType;
    }
};
#endif // VARIABLE_H
