#ifndef ANDROID_INTERFACE_H
#define ANDROID_INTERFACE_H

#ifdef Q_OS_ANDROID
#include "androidhelper_cyniu.h"
#endif


class android_interface
{
public:
    android_interface();
    void vibrate(int msec);

};

#endif // ANDROID_INTERFACE_H
