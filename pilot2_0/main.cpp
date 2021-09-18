#include "pilotwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    my_config conf;

    QApplication a(argc, argv);

    pilotWindow w(&conf);
    w.show();

    return a.exec();
}
