#include "mytouchslider.h"
#include <QDebug>
#include <QTouchEvent>

myTouchSlider::myTouchSlider(QObject *parent)
{
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    qDebug() <<" maximum value" << maximum() << " minimum " << minimum();
}

bool myTouchSlider::event(QEvent *e)
{

    switch (e->type()){
    case QEvent::TouchBegin:
    {
        qDebug() << "start dotykania";
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(e);
        const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();
        e->accept();
        xPosBegin = touchPoint1.scenePos().x();
        return true;
        break;
    }
    case QEvent::TouchUpdate:
    {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(e);
        const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();

        qDebug() << "update !! dotykania" << touchPoint1.scenePos().x() <<" "<< touchPoint1.scenePos().y() << " "<< width();
       // valueChanged(touchPoint1.scenePos().x());

        setValue( map_f(touchPoint1.scenePos().x() - xPosBegin,xPosBegin,width(),minimum(),maximum())       );
        return true;
    }

    case QEvent::TouchEnd:
    {
        qDebug() << " KONIEC dotykania";
        setValue(0);

        return true;
        break;
    }
    default:
    {
        break;
    }
   }

    return QSlider::event(e);
}
