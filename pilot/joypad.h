#ifndef JOYPAD_H
#define JOYPAD_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QTouchEvent>
#include <QDebug>
#include <QDesktopWidget>

class JoyPad: public QGraphicsEllipseItem
{
public:
    JoyPad(int posX, int posY, int circleX, int circleY, Qt::GlobalColor maxColor, Qt::GlobalColor minColor);
    ~JoyPad();
    QGraphicsEllipseItem *centralItem;
    bool sceneEvent(QEvent *event);

private:
    int posX;
    int posY;
    int circleX;
    int circleY;
};

#endif // JOYPAD_H
