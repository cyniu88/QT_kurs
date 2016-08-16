#include "joypad.h"

JoyPad::JoyPad(int circleX, int circleY , Qt::GlobalColor maxColor, Qt::GlobalColor minColor)
    : QGraphicsEllipseItem(posX, posY, circleX,circleX)//(posX,posY, circleX,circleX)
{

    this->circleX = circleX;
    this->circleY = circleY;

    setAcceptTouchEvents(true);
    setBrush(maxColor);

    centralItem = new QGraphicsEllipseItem((circleX-circleY)/2, (circleX-circleY)/2, circleY, circleY, this);
    centralItem->setPos(0, 0);
    centralItem->setBrush(minColor);

}

JoyPad::~JoyPad()
{
    delete centralItem;
}

bool JoyPad::sceneEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:{
        qDebug("start!!! ") ;
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();
        posX = touchPoint1.scenePos().x();
        posY = touchPoint1.scenePos().y();
        delete touchEvent;
        break;
    }
    case QEvent::TouchUpdate:{
        qDebug("UPDATE!!! ") ;
        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();

        centralItem->setPos(touchPoint1.scenePos().x()-posX,touchPoint1.scenePos().y()-posY );

        emit sendPos(  touchPoint1.scenePos().x()-circleY,touchPoint1.scenePos().y()-circleY  );


        delete touchEvent;
        break;
    }
    case QEvent::TouchEnd:
    {

        centralItem->setPos(0,0 );
        emit sendPos(  0,0  );
        break;
    }

    default:
        return QGraphicsItem::sceneEvent(event);
    }

    return true;
}
