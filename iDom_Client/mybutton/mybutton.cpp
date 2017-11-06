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
        QPushButton::nextCheckState();
        emit released();
        emit clicked();
        return true;

    case QEvent::Resize:
    {
//        double m = 1.5 / static_cast< double> (text().length());
//        QFont f;
//        f.setPixelSize(size().width()* m);
//        setFont(f);
}
        break;
    default:
        // qDebug() << "rest event !!! " << e->type();
        break;
    }

    return  QPushButton::event(e);

}

