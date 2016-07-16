#include "androidhelper_cyniu.h"

AndroidHelper_cyniu::AndroidHelper_cyniu()
{

}

AndroidHelper_cyniu::~AndroidHelper_cyniu()
{
 qDebug("destruktor androidhelper");
}

void AndroidHelper_cyniu::vibrate(int msec)
{
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/Chronometer/AndroidHelper", "vibrate", "(I)V", msec);
}
