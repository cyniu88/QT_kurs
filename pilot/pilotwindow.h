#ifndef PILOTWINDOW_H
#define PILOTWINDOW_H

#include <QMainWindow>
#include <QTouchEvent>
#include <QtEvents>
#include <QObject>
#include <QGraphicsView>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QTimer>

#include "joypad.h"
#include "mybutton.h"
#include "touchbutton.h"

struct MSG {
    int leftX;
    int leftY;
    int rightX;
    int rightY;
    int stateA;
    int stateB;
    int stateC;
    int stateD;
    QString getString(){

        return QString::number(leftX)+":"+QString::number(leftY,'g',4)+":"+QString::number(rightX)+":"+QString::number(rightY)+":"+ QString::number(stateA)+":"+QString::number(stateB)+":"+QString::number(stateC)+":"+QString::number(stateD)+";";

   };


};



namespace Ui {
class pilotWindow;
}

class pilotWindow : public QMainWindow
{
    Q_OBJECT
public:
    MSG message;
    QTimer *t1;

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

    QString msg;
public slots:
    void getPosGaz(int x, int y);
    void getPosSkret(int x, int y);
    void getStateA(bool state);
    void getStateB(bool state);
    void getStateC(bool state);
    void getStateD(bool state);
    void showMessage();

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
