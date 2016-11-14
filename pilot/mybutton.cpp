#include "mybutton.h"
#include <QDebug>
myButton::myButton(QObject *parent)
{
   this->setAttribute(Qt::WA_AcceptTouchEvents);
}

bool myButton::event(QEvent *e)
{

  switch (e->type()) {
  case QEvent::TouchBegin :
      emit pressed();
      //qDebug() << "begin event !!! " << e->type();
      return true;
      break;
  case QEvent::TouchEnd:
      emit released();
      emit clicked();
      //qDebug() << "END event !!! " << e->type();
      return true;
      break;
  default:
       // qDebug() << "rest event !!! " << e->type();
      break;
  }

 return  QPushButton::event(e);

}

