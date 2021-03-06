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
#ifdef Q_OS_WIN
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
#endif
    void setResetPos(bool flag);
signals:
    void sendPos(int x , int y);
private:
    int posX = 0;
    int posY = 0;
    int circleX;
    int circleY;
    bool resetPos = true;
public:
    double JoyX;
    double JoyY;
public slots:
    void resetPosNOW();
    void setPosNOW(int x , int y);
};

#endif // JOYPAD_H
