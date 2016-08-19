#include "mytouchslider.h"

myTouchslider::myTouchslider(int _x,int _y, int _H, int _W) : QGraphicsRectItem(_x,_y,_H,_W )
{
    setBrush(Qt::green);

    mainSlider = new QGraphicsRectItem(0,0,50,40,this);
    mainSlider->setBrush(Qt::yellow);
}

myTouchslider::~myTouchslider()
{
    delete mainSlider;
}

bool myTouchslider::sceneEvent(QEvent *event)
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

        break;
    }

    default:
        return QGraphicsItem::sceneEvent(event);
    }

    return true;
}
