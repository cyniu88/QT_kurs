#include "idom_client.h"
#include "variable.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    iDom_CONFIG config;

    QApplication a(argc, argv);
    iDom_Client w(&config);

    w.show();

    return a.exec();
}
