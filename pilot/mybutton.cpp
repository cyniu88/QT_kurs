#include "mybutton.h"

myButton::myButton(QObject *parent)
{
grabGesture(Qt::TapAndHoldGesture);
}

bool myButton::Event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:{
        qDebug("start!!! ") ;
        // emit startTouch();
        break;
    }
    case QEvent::TouchUpdate:{
        qDebug("UPDATE!!! ") ;

        break;
    }
    case QEvent::TouchEnd:
    {


        break;
    }

    default:
        return QPushButton::event(event);
    }

    return true;
}
