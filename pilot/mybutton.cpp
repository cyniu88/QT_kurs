#include "mybutton.h"
#include <QDebug>
myButton::myButton(QObject *parent)
{

}

bool myButton::event(QEvent *e)
{

  switch (e->type()) {
  case QEvent::TouchBegin :
      emit pressed();
      return true;
      break;
  case QEvent::TouchEnd:
      emit released();
      emit clicked();
      return true;
      break;
  default:

      break;
  }

 return  QPushButton::event(e);

}

