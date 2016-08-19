#ifndef MYTOUCHSLIDER_H
#define MYTOUCHSLIDER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QTouchEvent>
#include <QDebug>
#include <QDesktopWidget>


class myTouchslider : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    myTouchslider(int _x, int _y, int _H, int _W);
    virtual ~myTouchslider();
    bool sceneEvent(QEvent *event);
    QGraphicsRectItem *mainSlider;
};

#endif // MYTOUCHSLIDER_H
