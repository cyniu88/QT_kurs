#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QEvent>
#include <QTouchEvent>

enum class BUTTON_STATE{
    OFF = 0,
    ON = 1,
    UNKNOWN = 2
};

class myButton :    public QPushButton
{
    // Q_OBJECT
    BUTTON_STATE m_state = BUTTON_STATE::OFF;
    bool  m_checked = false;
public:

    explicit myButton(QObject *parent = 0);
    bool event(QEvent *e);

};

#endif // MYBUTTON_H
