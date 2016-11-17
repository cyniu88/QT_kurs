#include "mytouchslider.h"
#include <QDebug>
#include <QTouchEvent>

myTouchSlider::myTouchSlider(QObject *parent)
{
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    //this->grabGesture(Qt::TapAndHoldGesture);
}

bool myTouchSlider::event(QEvent *e)
{
    qDebug() << "EVENT =)" << e->type();
    switch (e->type()){
    case QEvent::TouchBegin:
    {
        qDebug() << "start dotykania";
        //valueChanged(99);
        e->accept();
        return true;
        break;
    }
    case QEvent::TouchUpdate:
    {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(e);
        const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();

        qDebug() << "update !! dotykania" << touchPoint1.scenePos().x();

        return true;
    }
    case QEvent::Gesture:
    {
        qDebug() << "gest@@@ " ;
        break;
    }

    case QEvent::TouchEnd:
    {
        qDebug() << " KONIEC dotykania";
        return true;
        break;
    }
   }

    return QSlider::event(e);
}
