#ifndef JOYPAD_H
#define JOYPAD_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QTouchEvent>
#include <QDebug>
#include <QDesktopWidget>


class JoyPad:  public QObject, public QGraphicsEllipseItem
{
 Q_OBJECT
public:
    JoyPad( int circleX, int circleY, Qt::GlobalColor maxColor, Qt::GlobalColor minColor);
    virtual ~JoyPad();
    QGraphicsEllipseItem *centralItem;
    bool sceneEvent(QEvent *event);
    void setResetPos(bool flag);
signals:
    void sendPos(int x , int y);
private:
    int posX;
    int posY;
    int circleX;
    int circleY;
    bool resetPos = true;

};

#endif // JOYPAD_H