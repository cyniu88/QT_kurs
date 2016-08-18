#ifndef TOUCHBUTTON_H
#define TOUCHBUTTON_H


#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QTouchEvent>
#include <QDebug>
#include <QDesktopWidget>

class touchButton : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    touchButton(QString _name, Qt::GlobalColor _color);
    virtual ~touchButton();
     bool sceneEvent(QEvent *event);
signals:
    void sendState(bool state);
private:
    QGraphicsRectItem *centralItem;
    QString name;
    bool isPressed = false;
    QGraphicsTextItem *text;
};

#endif // TOUCHBUTTON_H
