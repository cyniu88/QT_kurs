#include "pilotwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    my_config conf;


    QApplication a(argc, argv);


    a.setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
   // w->setAttribute(Qt::WA_AcceptTouchEvents);
     pilotWindow w(&conf);

    w.show();

    return a.exec();
}
