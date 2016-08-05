#ifndef PILOTWINDOW_H
#define PILOTWINDOW_H

#include <QMainWindow>
#include <QTouchEvent>
#include <QtEvents>
#include <QScroller>
#include <QGraphicsView>
#include <QPushButton>
#include "joypad.h"

namespace Ui {
class pilotWindow;
}

class pilotWindow : public QMainWindow
{
    //Q_OBJECT
private:
     QGraphicsScene sceneGaz, sceneSkret;
    JoyPad *joyPadGaz;
    JoyPad *joyPadSkret;
    bool autoReturnGaz   = true;
    bool autoReturnSkret = true;
    double *test;




  //  QTouchEvent event;
  //  bool sceneEvent(QTouchEvent *e);
protected:
bool touchEvent(QTouchEvent *ev);
public:
    explicit pilotWindow(QWidget *parent = 0);
    ~pilotWindow();

private slots:
    void on_reset_clicked();



    void on_checkBoxPower_toggled(bool checked);

    void on_checkBoxWheel_toggled(bool checked);

private:
    Ui::pilotWindow *ui;
};

#endif // PILOTWINDOW_H
