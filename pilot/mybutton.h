#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QEvent>
#include <QTouchEvent>
class myButton :    public QPushButton
{
   // Q_OBJECT
public:
    explicit myButton(QObject *parent = 0);
bool  Event(QEvent *event);
signals:

public slots:
};

#endif // MYBUTTON_H
