#include "pilotwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pilotWindow w;

    a.setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
   // w->setAttribute(Qt::WA_AcceptTouchEvents);
   // w.
    w.show();

    return a.exec();
}
