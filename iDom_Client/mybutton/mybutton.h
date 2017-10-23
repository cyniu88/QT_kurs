#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QEvent>
#include <QTouchEvent>
enum class STATE{
    OFF = 0,
    ON = 1,
    UNKNOWN = 2
};

class myButton :    public QPushButton
{
    // Q_OBJECT
    STATE m_state = STATE::OFF;
public:
    explicit myButton(QObject *parent = 0);
    bool event(QEvent *e);
    void setState(STATE s);
    STATE getState();
    void switchState();
};

#endif // MYBUTTON_H
