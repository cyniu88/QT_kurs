#include "pilotwindow.h"
#include <QApplication>
#include "workerip.h"


int main(int argc, char *argv[])
{
    my_config conf;
    WorkerIP * worker = new WorkerIP(&conf);

    QApplication a(argc, argv);


    a.setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
   // w->setAttribute(Qt::WA_AcceptTouchEvents);
     pilotWindow w(&conf);
 worker->start();
    w.show();

    return a.exec();
}
