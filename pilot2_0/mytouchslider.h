#ifndef MYTOUCHSLIDER_H
#define MYTOUCHSLIDER_H

#include <QSlider>
#include <QObject>
#include <QEvent>
#include <QTouchEvent>

#include "functions.h"

class myTouchSlider : public QSlider
{
public:
    myTouchSlider(QObject *parent = 0);
    bool event(QEvent *e);
private:
    int xPosBegin =0;
};

#endif // MYTOUCHSLIDER_H
