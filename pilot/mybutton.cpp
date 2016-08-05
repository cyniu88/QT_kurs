#include "mybutton.h"

mybutton::mybutton(QWidget *parent) : QPushButton(parent)
{

}

bool mybutton::touchEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:{
        qDebug("start!!! ") ;

        break;
    }
    case QEvent::TouchUpdate:{
        qDebug("UPDATE!!! ") ;

        break;
    }
    case QEvent::TouchEnd:
    {
        qDebug("END!!! ") ;
        break;
    }



    }

    return true;
}
