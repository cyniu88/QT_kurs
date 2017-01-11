#include "androidhelper_cyniu.h"

AndroidHelper_cyniu::AndroidHelper_cyniu()
{
    proximitySensor = new QProximitySensor();
    proximitySensor->start();
    accSensor = new QAccelerometer();
    accSensor->start();
    qDebug("konstruktor androidhelper !!!!!!!!!!!!!!\n");
}

AndroidHelper_cyniu::~AndroidHelper_cyniu()
{
    proximitySensor->stop();
    delete proximitySensor;
    accSensor->stop();
    delete accSensor;
    qDebug("\n\n\n destruktor androidhelper\n\n\n");
}

void AndroidHelper_cyniu::vibrate(int msec)
{
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/Chronometer/AndroidHelper", "vibrate", "(I)V", msec);
}

double AndroidHelper_cyniu::getProximity()
{

    QProximityReading *reading = proximitySensor->reading();
    qreal value = reading->value(0).value<qreal>();
   // qreal value = reading->property("Distance").value<qreal>();
    return value ;
}

QString AndroidHelper_cyniu::getAccelerometer()
{
    QSensorReading *reading = accSensor->reading();
     qreal x = reading->property("x").value<qreal>();
     qreal y = reading->value(1).value<qreal>();
     qreal z = reading->property("z").value<qreal>();

     return QString::number(x)+" "+QString::number(y)+" "+QString::number(z);
}

void AndroidHelper_cyniu::makeToast(QString text)
{
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/Chronometer/AndroidHelper", "makeToast",  "(Ljava/lang/String;)V",QAndroidJniObject::fromString(text).object<jstring>());
}
int AndroidHelper_cyniu::updateAndroidNotification(QString msg)
{
//    QAndroidJniObject javaNotification = QAndroidJniObject::fromString(msg);
//    return QAndroidJniObject::callStaticMethod<jint>("org/qtproject/example/Chronometer/AndroidHelper",
//                                                     "notify",
//                                                     "(Ljava/lang/String;)I",
//                                                     javaNotification.object<jstring>());
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/Chronometer/AndroidHelper", "notify",  "(Ljava/lang/String;)V",QAndroidJniObject::fromString(msg).object<jstring>());
    return 0;
}

