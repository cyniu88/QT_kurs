#include "joypad.h"
#include "functions.h"
JoyPad::JoyPad(int circleX, int circleY , Qt::GlobalColor maxColor, Qt::GlobalColor minColor)
    : QGraphicsEllipseItem(0, 0, circleX,circleX)//(posX,posY, circleX,circleX)
{

    this->JoyX = 0;
    this->JoyY = 0;
    this->circleX = circleX;
    this->circleY = circleY;

    setAcceptTouchEvents(true);
    setBrush(maxColor);

    centralItem = new QGraphicsEllipseItem((circleX-circleY)/2, (circleX-circleY)/2, circleY, circleY, this);
    centralItem->setPos(0, 0);
    centralItem->setBrush(minColor);
    qDebug() << circleX << circleY << "tak w konstruktorze";
}

JoyPad::~JoyPad()
{
    qDebug()<< "destruktor JoyPad";
    delete centralItem;
}

bool JoyPad::sceneEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchBegin:{

        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();
        if (resetPos == true){
            posX = touchPoint1.scenePos().x();
            posY = touchPoint1.scenePos().y();
        }
        break;
    }

    case QEvent::TouchUpdate:{

        QTouchEvent *touchEvent = static_cast<QTouchEvent *>(event);
        const QTouchEvent::TouchPoint &touchPoint1 = touchEvent->touchPoints().first();

        int i = map_f( touchPoint1.scenePos().x()-posX,-1*circleX/2,circleX/2,-100,100);
        int j = map_f( touchPoint1.scenePos().y()-posY,-1*circleX/2,circleX/2,-100,100);

        double X = touchPoint1.scenePos().x()-posX;
        double Y = touchPoint1.scenePos().y()-posY;
        if (i < 100 && i > -100){
            JoyX = X;
        }

        if (j < 100 && j > -100){
            JoyY = Y;
        }
        if (i > 100) i = 100;
        if (i <-100) i = -100;
        if (j > 100) j = 100;
        if (j <-100) j = -100;
        emit sendPos( i,j);
        centralItem->setPos(JoyX,JoyY );
        break;
    }
    case QEvent::TouchEnd:
    {
        if (resetPos == true){
            centralItem->setPos(0,0 );
            emit sendPos(  0,0  );
        }
        break;
    }
    default:
        return QGraphicsItem::sceneEvent(event);
    }
    return true;
}
#ifdef Q_OS_WIN
void JoyPad::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    qDebug() << "start " << e;
    if (resetPos == true){
        posX = QCursor::pos().rx();
        posY = QCursor::pos().ry();
    }
}

void JoyPad::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    //qDebug() << "ruszam myszka" << QCursor::pos() ;

    int i = map_f( QCursor::pos().rx()-posX,-1*circleX/2,circleX/2,-100,100);
    int j = map_f( QCursor::pos().ry()-posY,-1*circleX/2,circleX/2,-100,100);

    double X = QCursor::pos().rx()-posX;
    double Y = QCursor::pos().ry()-posY;
    if (i < 100 && i > -100){
        JoyX = X;
    }

    if (j < 100 && j > -100){
        JoyY = Y;
    }
    if (i > 100) i= 100;
    if ( i <-100) i = -100;
    if (j > 100) j= 100;
    if ( j <-100) j = -100;
    emit sendPos( i,j);
    centralItem->setPos(JoyX,JoyY );

}

void JoyPad::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    if (resetPos == true){
        centralItem->setPos(0,0 );
        emit sendPos(  0,0  );
    }
    qDebug() << " koncze" << e;
}
#endif
void JoyPad::setResetPos(bool flag)
{
    resetPos = flag;
}

void JoyPad::resetPosNOW()
{
    centralItem->setPos(0, 0);
    emit sendPos(0, 0);
}

void JoyPad::setPosNOW(int x, int y)
{
    centralItem->setPos(x, y);
}
