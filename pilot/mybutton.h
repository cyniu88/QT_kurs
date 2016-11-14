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
bool event(QEvent *e);

};

#endif // MYBUTTON_H
