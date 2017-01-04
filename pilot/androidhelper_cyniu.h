#ifndef ANDROIDHELPER_CYNIU_H
#define ANDROIDHELPER_CYNIU_H
#include <memory>

#include <QDebug>
#include <QtAndroidExtras/QAndroidJniObject> // For JNI, need to select Android Build
#include <QAndroidJniObject>
#include <QAccelerometer>
#include <QProximitySensor>
#include <QProximityReading>


class AndroidHelper_cyniu
{
private:
     QProximitySensor *proximitySensor;
     QAccelerometer *accSensor;
public:
    AndroidHelper_cyniu();
    ~AndroidHelper_cyniu();
    void vibrate(int msec);
    double getProximity();
    QString getAccelerometer();
    int fibo(int n);
    void makeToast(int text);
    int updateAndroidNotification(QString msg);
    int test(int number);
    int fibonacci(int n);
};

#endif // ANDROIDHELPER_CYNIU_H