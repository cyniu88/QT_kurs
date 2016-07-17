#ifndef ANDROIDHELPER_CYNIU_H
#define ANDROIDHELPER_CYNIU_H
#include <QDebug>
#include <QtAndroidExtras/QAndroidJniObject> // For JNI, need to select Android Build
#include <QAndroidJniObject>


class AndroidHelper_cyniu
{
public:
    AndroidHelper_cyniu();
    ~AndroidHelper_cyniu();
    void vibrate(int msec);
    int fibo(int n);
    void makeToast(int text);
};

#endif // ANDROIDHELPER_CYNIU_H
