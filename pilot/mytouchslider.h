#ifndef MYTOUCHSLIDER_H
#define MYTOUCHSLIDER_H

#include <QSlider>
#include <QObject>
#include <QEvent>
#include <QTouchEvent>

class myTouchSlider : public QSlider
{
public:
    myTouchSlider(QObject *parent = 0);
    bool event(QEvent *e);
};

#endif // MYTOUCHSLIDER_H
