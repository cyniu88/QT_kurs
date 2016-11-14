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
#include <QGamepad>
#include <QGamepadManager>

#include "joypad.h"
#include "mybutton.h"
#include "touchbutton.h"
#include "mytouchslider.h"
#include "variable.h"
#include "workerip.h"
#include "gear_BOX/gear_box.h"

namespace Ui {
class pilotWindow;
}

class pilotWindow : public QMainWindow
{
    Q_OBJECT

public:
    msg_s message;
    QTimer *t1;
    QTimer *tFPS;

    QGraphicsScene scenePower, sceneDirection;
    QGraphicsScene sceneA,sceneB,sceneC,sceneD;
    JoyPad *joyPadPower;
    JoyPad *joyPadDummy;
    JoyPad *joyPadDirection;

    touchButton *A;
    touchButton *B;
    touchButton *C;
    touchButton *D;

    bool autoReturnPower   = true;
    bool autoReturnDirection = true;
    double *test;
    myButton *przy;

    QString msg;

    QGraphicsScene sceneSliderA;
    QGraphicsScene sceneSliderB;

    myTouchslider *sliderA;
    myTouchslider *sliderB;

signals:
    void resetPosNOW();

public slots:
    void getPosGaz(int x, int y);
    void getPosSkret(int x, int y);
    void getStateA(bool state);
    void getStateB(bool state);
    void getStateC(bool state);
    void getStateD(bool state);
    void showMessage();
    void showServerREsponse(QString s);
    void getAxisEvent(int deviceId, QGamepadManager::GamepadAxis axis, double value);
    void getButtonEventPress (int deviceId, QGamepadManager::GamepadButton button, double value);
    void getButtonEventRelease (int deviceId, QGamepadManager::GamepadButton button);


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

    void on_actionConnect_triggered();

    void on_actionDisconnect_triggered();

    void on_actionEXIT_triggered();

    void on_adresIP_currentTextChanged( );

    void on_checkBoxWheel_stateChanged();

    void display_FPS();



    void on_actionON_triggered();

    void on_actionOFF_triggered();

    void on_push_plusGear_clicked();

    void on_push_minusGear_clicked();

private:
    my_config *conf;
    Ui::pilotWindow *ui;
    WorkerIP   worker ;
    WorkerIP   *workerPTR ;
    int fpsCounter = 0;
    Gear_Box myGearBox;

};

#endif // PILOTWINDOW_H
