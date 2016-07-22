#include "android_interface.h"

android_interface::android_interface()
{

}

void android_interface::vibrate(int msec)
{
#ifdef Q_OS_ANDROID

    AndroidHelper_cyniu *android = new AndroidHelper_cyniu();
    android->vibrate(msec);

    delete android;
#endif
}
