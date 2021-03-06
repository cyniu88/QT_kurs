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
#include <QMessageBox>


#include "joypad.h"
#include "../iDom_Client/mybutton/mybutton.h"
#include "variable.h"
#include "workerip.h"
#include "gear_BOX/gear_box.h"
#include "../libs/android_functions/android_interface/android_interface.h"
#include "../libs/config_files/config_files.h"

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
    //JoyPad *joyPadDummy ,*joyPadDummy2;
    JoyPad *joyPadDirection;

    bool autoReturnPower   = true;
    bool autoReturnDirection = true;
    myButton *przy;

    QString msg;

    QGraphicsScene sceneSliderA;
    QGraphicsScene sceneSliderB;

signals:
    void resetPosNOW();
    void setPosNOW_Left(int x , int y);
    void setPosNOW_Right(int x , int y);

public slots:
    void getPosGaz(int x, int y);
    void getPosSkret(int x, int y);
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

    void on_actionConnect_triggered();

    void on_actionDisconnect_triggered();

    void on_actionEXIT_triggered();

    void on_checkBoxWheel_stateChanged();

    void display_FPS();

    void on_actionON_triggered();

    void on_actionOFF_triggered();

    void on_push_plusGear_clicked();

    void on_push_minusGear_clicked();

    void on_buttonLowBeam_clicked();

    void on_buttonHighBeam_clicked();

    void on_buttonTrailerMechanism_clicked();

    void on_buttonReverseLight_clicked();

    void getMSG(QString tit, QString msg);

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_valueChanged(int value);

    void on_buttonAutomatGearbox_clicked();

    void on_actionON_2_triggered();

    void on_actionOFF_2_triggered();

    void on_lcdMsgCounter_overflow();

    void on_actionPORT_triggered();

    void on_actionADDRESS_triggered();

    void on_actionAdd_address_triggered();

    void on_actionShow_IP_arp_triggered();

    void on_actioncamera_triggered();

    void on_actionpad_triggered();

    void on_actionUP_triggered();

    void on_actionDOWN_triggered();

    void on_actionAutomat_triggered();

    void on_actionPAUSE_triggered();

private:
    my_config *conf;
    Ui::pilotWindow *ui;
    WorkerIP worker ;
    WorkerIP *workerPTR ;
    int fpsCounter = 0;
    int msgCounter = 0;
    Gear_Box myGearBox;
    android_interface droid;
    config_Files mainConfig;
    QWidget inputDialogStyleSheet;

};

#endif // PILOTWINDOW_H
