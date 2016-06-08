#include "bullet.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsScene>
Bullet::Bullet()
{
    setRect(0,0,10,50);
    qDebug() << "mamy pociska";
    QTimer *timer  = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void Bullet::move()
{
    setPos(x(),y()-10);
    if (pos().y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug("sksowany");
    }
}
