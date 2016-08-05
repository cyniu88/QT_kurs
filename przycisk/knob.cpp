
#include "knob.h"

#include <QBrush>
#include <QTouchEvent>
#include <QDebug>

Knob::Knob()
    : QGraphicsEllipseItem(0, 0, 100, 100)
{
    setAcceptTouchEvents(true);
    setBrush(Qt::lightGray);

    leftItem = new QGraphicsEllipseItem(35, 35, 30, 30, this);
    leftItem->setPos(0, 0);
    leftItem->setBrush(Qt::darkGreen);


}


bool Knob::sceneEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:{
        qDebug("start!!! ") ;
        break;
    }
    case QEvent::TouchUpdate:{
        qDebug("UPDATE!!! ") ;
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
         const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();
         qDebug()<< touchPoint1.scenePos().x()<< "   +  " <<touchPoint1.scenePos().y();
         leftItem->setPos(touchPoint1.scenePos().x(),touchPoint1.scenePos().y() );
        break;
    }
    case QEvent::TouchEnd:
    {
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);

        if (touchEvent->touchPoints().count() == 1) {
            const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();

            leftItem->setPos(0,0);
            qDebug("OBRACAM !!! ") ;

        }

        break;
    }

    default:
        return QGraphicsItem::sceneEvent(event);
    }

    return true;
}
