#ifndef ANDROID_INTERFACE_H
#define ANDROID_INTERFACE_H
#include <QObject>
#ifdef Q_OS_ANDROID
#include "androidhelper_cyniu.h"
#endif


class android_interface
{
public:
    android_interface();
    void vibrate(int msec);
    double getProximity();
    QString getAccelerometer();

private:
#ifdef Q_OS_ANDROID
    AndroidHelper_cyniu droid;
#endif
};

#endif // ANDROID_INTERFACE_H
