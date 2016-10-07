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
#include "mytouchslider.h"
#include "variable.h"
#include "workerip.h"




namespace Ui {
class pilotWindow;
}

class pilotWindow : public QMainWindow
{
    Q_OBJECT
public:
    msg_s message;
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

    QGraphicsScene sceneSliderA;
    QGraphicsScene sceneSliderB;

    myTouchslider *sliderA;
    myTouchslider *sliderB;

public slots:
    void getPosGaz(int x, int y);
    void getPosSkret(int x, int y);
    void getStateA(bool state);
    void getStateB(bool state);
    void getStateC(bool state);
    void getStateD(bool state);
    void showMessage();
    void showServerREsponse(QString s);

    //  QTouchEvent event;
    //  bool sceneEvent(QTouchEvent *e);
protected:
    bool touchEvent(QTouchEvent *ev);
public:
    explicit pilotWindow(my_config *c,  QWidget *parent = 0);
    ~pilotWindow();

private slots:
    void on_reset_clicked();



    void on_checkBoxPower_toggled(bool checked);

    void on_checkBoxWheel_toggled(bool checked);


    void on_port_editingFinished();

    void on_pushButton_pressed();

    void on_actionConnect_triggered();

    void on_actionDisconnect_triggered();

    void on_adresIP_editingFinished();

    void on_actionEXIT_triggered();

private:
    my_config *conf;
    Ui::pilotWindow *ui;
    WorkerIP   worker ;
    WorkerIP   *workerPTR ;

};

#endif // PILOTWINDOW_H
