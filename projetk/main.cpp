#include "program1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    program1 w;
    w.show();

    return a.exec();
}
