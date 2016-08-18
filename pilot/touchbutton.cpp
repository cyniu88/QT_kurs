#include "touchbutton.h"

touchButton::touchButton(QString _name, Qt::GlobalColor _color): name(_name) ,QGraphicsRectItem(0,0,400,400)
{
    setAcceptTouchEvents(true);
    setBrush(_color);
    text = new QGraphicsTextItem(name,this);

    text->setPos(50,50);


}

touchButton::~touchButton()
{
    delete text;
}

bool touchButton::sceneEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:{
        qDebug("start!!! ") ;
        if (isPressed == false){
            isPressed = true;

        }
        else{
            isPressed= false;
        }
        break;
    }
    case QEvent::TouchUpdate:{
        qDebug("UPDATE!!! ") ;

        break;
    }
    case QEvent::TouchEnd:
    {
        if (isPressed == true)
        {
            setBrush(Qt::yellow);
        }
        else {
            setBrush((Qt::red));
        }
        qDebug("stop ") ;
        emit sendState(isPressed);
        break;
    }

    default:
        return QGraphicsItem::sceneEvent(event);
    }

    return true;
}
