#ifndef PILOTWINDOW_H
#define PILOTWINDOW_H

#include <QMainWindow>
#include <QTouchEvent>
#include <QtEvents>
#include <QObject>
#include <QGraphicsView>
#include <QPushButton>
#include <QDebug>

#include "joypad.h"
#include "mybutton.h"
#include "touchbutton.h"
namespace Ui {
class pilotWindow;
}

class pilotWindow : public QMainWindow
{
    Q_OBJECT
public:
    QGraphicsScene sceneGaz, sceneSkret;
    QGraphicsScene sceneA,sceneB,sceneC,sceneD;
    JoyPad *joyPadGaz;
    JoyPad *joyPadSkret;

    touchButton *A;
    touchButton *B;
    touchButton *C;
    touchButton *D;


    bool autoReturnGaz   = true;
    bool autoReturnSkret = true;
    double *test;
    myButton *przy;
public slots:
    void getPosGaz(int x, int y);
    void getPosSkret(int x, int y);

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
