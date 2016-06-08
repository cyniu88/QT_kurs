#ifndef MYRECT_CPP
#define MYRECT_CPP

#include "myrect.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTouchEvent>
#include<QGraphicsItem>
#include <QGraphicsScene>
#include <bullet.h>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "przycisk";
   if (event->key()==Qt::Key_Left){
       setPos(x()-10,y());
   }
   else if (event->key()==Qt::Key_Right){
       setPos(x()+10,y() );
   }
   else if (event->key()==Qt::Key_Up){
       setPos(x(),y()-10);
   }
   else if (event->key()==Qt::Key_Down){
       setPos(x(),y()+10);
   }

    else if (event->key()== Qt::Key_Escape)
   {
       setPos(0,0);
   }
   else if (event->key()== Qt::Key_Space)
  {
      Bullet *bullet = new Bullet();
      bullet->setPos(x(),y());
        scene()->addItem(bullet);



  }
}

void MyRect::mousePressEvent(QMouseEvent *event)
{
   /* if (QGraphicsItem *item =  QGraphicsView::itemAt(event->pos())) {
            qDebug() << "You clicked on item" << item;
        } else {
            qDebug("You didn't click on an item.");
        } */
     qDebug( )<< "klik";
       setPos(0,0);
}

#endif // MYRECT_CPP
