#include "mytouchslider.h"
#include <QDebug>

myTouchSlider::myTouchSlider(QObject *parent)
{
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->grabGesture(Qt::TapAndHoldGesture);
}

bool myTouchSlider::event(QEvent *e)
{
    qDebug() << "EVENT =)" << e->type();
    switch (e->type()){
    case QEvent::TouchBegin:
        qDebug() << "start dotykania";
        valueChanged(99);
        break;
    case QEvent::TouchUpdate:
        qDebug() << "update !! dotykania";
        break;
    case QEvent::TouchCancel:
        qDebug() << "CANCEL!! !! dotykania";
        break;
    case QEvent::TouchEnd:
        qDebug() << " KONIEC dotykania";
        break;
    }

    return QSlider::event(e);
}
