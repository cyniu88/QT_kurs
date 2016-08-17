#include "touchbutton.h"

touchButton::touchButton(QString _name, Qt::GlobalColor _color): name(_name) ,QGraphicsRectItem(0,0,400,400)
{
    setAcceptTouchEvents(true);
    setBrush(_color);

}

touchButton::~touchButton()
{
    delete centralItem;
}
