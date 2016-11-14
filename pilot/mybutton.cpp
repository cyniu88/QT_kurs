#include "mybutton.h"
#include <QDebug>
myButton::myButton(QObject *parent)
{

}

bool myButton::event(QEvent *e)
{
  qDebug() << " EEWENET !! " << e->type();
    return true;
}

