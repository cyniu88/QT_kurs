#ifndef TESTANDROIDCLIENT_H
#define TESTANDROIDCLIENT_H

#ifdef Q_OS_ANDROID
#include <QtAndroidExtras/QAndroidJniObject>
#endif
#include <QObject>

class TestAndroidClient: public QObject
{
    Q_OBJECT
public:
    explicit TestAndroidClient(QObject *parent = 0);
    Q_INVOKABLE void test(QString msg );

};


#endif // TESTANDROIDCLIENT_H
