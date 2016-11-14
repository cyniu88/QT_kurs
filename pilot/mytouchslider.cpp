#include "mytouchslider.h"
#include <QDebug>

myTouchSlider::myTouchSlider(QObject *parent)
{
    this->setAttribute(Qt::WA_AcceptTouchEvents);
}

bool myTouchSlider::event(QEvent *e)
{
    qDebug() << "EVENT =)" << e->type();
    QSlider::event(e);
}
