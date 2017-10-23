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

void myButton::setState(STATE s)
{
    m_state = s;
}

STATE myButton::getState()
{
    return m_state;
}

void myButton::switchState()
{
    if (m_state == STATE::ON){
        m_state = STATE::OFF;
    }
    else if (m_state == STATE::OFF){
        m_state = STATE::ON;
    }
}
