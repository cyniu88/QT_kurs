#include "android_interface.h"

android_interface::android_interface()
{

}

void android_interface::vibrate(int msec)
{
#ifdef Q_OS_ANDROID

    droid.vibrate(msec);
    //AndroidHelper_cyniu *android = new AndroidHelper_cyniu();
    //android->vibrate(msec);

    // delete android;
#endif
}

double android_interface::getProximity()
{
    double value = -1.1;
#ifdef Q_OS_ANDROID

    value = droid.getProximity();

#endif
    return value;
}

QString android_interface::getAccelerometer()
{
    QString value =" ";
#ifdef Q_OS_ANDROID
    value = droid.getAccelerometer();
#endif
    return value;
}
