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
    case QEvent::TouchEnd:
        emit released();
        emit clicked();
        //qDebug() << "END event !!! " << e->type();
        return true;
    default:
        // qDebug() << "rest event !!! " << e->type();
        break;
    }

    return  QPushButton::event(e);

}

void myButton::setState(BUTTON_STATE s)
{
    m_state = s;
}

BUTTON_STATE myButton::getState()
{
    return m_state;
}

void myButton::switchState()
{
    if (m_state == BUTTON_STATE::ON){
        m_state = BUTTON_STATE::OFF;
    }
    else if (m_state == BUTTON_STATE::OFF){
        m_state = BUTTON_STATE::ON;
    }
}
