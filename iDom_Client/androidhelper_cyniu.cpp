#include "androidhelper_cyniu.h"

AndroidHelper_cyniu::AndroidHelper_cyniu()
{
qDebug("konstruktor androidhelper !!!!!!!!!!!!!!\n");
}

AndroidHelper_cyniu::~AndroidHelper_cyniu()
{
 qDebug("\n\n\n destruktor androidhelper\n\n\n");
}

void AndroidHelper_cyniu::vibrate(int msec)
{
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/Chronometer/AndroidHelper", "vibrate", "(I)V", msec);
}

int AndroidHelper_cyniu::fibo(int n)
{
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/Chronometer/AndroidHelper", "fibonacci", "(I)V", n);
}

void AndroidHelper_cyniu::makeToast(int text)
{
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/Chronometer/AndroidHelper", "makeToast", "(I)V", text);
}
int AndroidHelper_cyniu::updateAndroidNotification(QString msg)
{
    QAndroidJniObject javaNotification = QAndroidJniObject::fromString(msg);
   return QAndroidJniObject::callStaticMethod<jint>("org/qtproject/example/Chronometer/AndroidHelper",
                                       "notify",
                                       "(Ljava/lang/String;)I",
                                              javaNotification.object<jstring>());
}

int AndroidHelper_cyniu::fibonacci(int n)
 {
    return QAndroidJniObject::callStaticMethod<jint>
                        ("org/qtproject/example/Chronometer/AndroidHelper" // java class name
                        , "fibonacci" // method name
                         , "(I)I" // signature
                         , n);
 }

int AndroidHelper_cyniu::test(int number)
{
    int i = QAndroidJniObject::callStaticMethod<jint>("org/qtproject/example/Chronometer/AndroidHelper", "test", "(I)I", number);
    return i;
}
