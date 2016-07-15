#include <QDebug>

#include "TestAndroidClient.h"



TestAndroidClient::TestAndroidClient(QObject *parent)
    : QObject(parent)
{

}

void TestAndroidClient::test(QString msg ){
#ifdef Q_OS_ANDROID
    QAndroidJniObject javaMessage = QAndroidJniObject::fromString(msg);
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/testandroidextras/TestAndroidClient",
                                              "test",
                                              "(Ljava/lang/String;)V",
                                              javaMessage.object<jstring>());
#endif
}
