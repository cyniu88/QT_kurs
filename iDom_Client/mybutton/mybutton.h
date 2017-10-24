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

public:
    QIcon onIcon;
    QIcon offIcon;

    explicit myButton(QIcon on, QIcon off, QObject *parent = 0);
    //explicit myButton( QObject *parent = 0);
    bool event(QEvent *e);
    void setState(BUTTON_STATE s);
    BUTTON_STATE getState();
    void switchState();
};

#endif // MYBUTTON_H
