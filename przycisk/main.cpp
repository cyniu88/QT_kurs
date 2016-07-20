#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();


    QTimer *timer= new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),   w,SLOT(update()));
    timer->start(1500);
    w->show();

    return a.exec();
}
