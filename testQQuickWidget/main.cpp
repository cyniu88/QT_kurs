#include "mainwindow.h"
#include <QApplication>

#ifdef Q_OS_ANDROID
#include <QtWebView/QtWebView>
#endif
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef Q_OS_ANDROID
    QtWebView::initialize();
#endif



    MainWindow w;
    w.show();

    return a.exec();
}
