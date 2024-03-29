#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <string>
#include <QMutex>
#include <QString>
#include <QList>
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
    std::string serverIP = "";

    quint16 serverPort = 48833;
    bool goWhile = false;
    std::string command = "OK";
    QList<QString> grepWords = {};
    bool isWindows = true;
    QMutex IPMutex;
    BlockingQueue<ADRESS_WHAT> workerQueue;
    WorkerIP* worketPTR  ;
    bool isConnectedToServer = false;
    std::string m_RSHash = "";
    bool encrypted = true;
    bool houseLocked = false;
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
