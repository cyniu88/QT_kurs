
#include "knob.h"

#include <QBrush>
#include <QTouchEvent>
#include <QDebug>

Knob::Knob()
    : QGraphicsEllipseItem(0, 0, 300,300)
{
    setAcceptTouchEvents(true);
    setBrush(Qt::lightGray);

    leftItem = new QGraphicsEllipseItem(80, 80, 140, 140, this);
    leftItem->setPos(0, 0);
    leftItem->setBrush(Qt::darkGreen);


}


bool Knob::sceneEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:{
        qDebug("start!!! ") ;
       // emit startTouch();
        break;
    }
    case QEvent::TouchUpdate:{
        qDebug("UPDATE!!! ") ;
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
         const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();
         qDebug()<< touchPoint1.scenePos().x()<< "   +  " <<touchPoint1.scenePos().y();
         leftItem->setPos(touchPoint1.scenePos().x()-140,touchPoint1.scenePos().y()-140 );
       //  emit sendPos(touchPoint1.scenePos().x()-140,touchPoint1.scenePos().y()-140);
        break;
    }
    case QEvent::TouchEnd:
    {
       //  emit stopTouch();

        break;
    }

    default:
        return QGraphicsItem::sceneEvent(event);
    }

    return true;
}
