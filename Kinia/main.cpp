#include "kiniacynia.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KiniaCynia w;
    w.show();

    return a.exec();
}
