#include "pilotwindow.h"
#include "ui_pilotwindow.h"



void pilotWindow::getPosGaz(int x, int y)
{
    ui->gazLCD_x->display(x);
    ui->gazLCD_y->display(y);
    message.leftX=x;
    message.leftY=(y/myGearBox.howManyGear())*myGearBox.getGear();
}

void pilotWindow::getPosSkret(int x, int y)
{
    ui->skretLCD_x->display(x);
    ui->skretLCD_y->display(y);
    message.rightX=x;
    message.rightY=y;
}

void pilotWindow::showMessage()
{
    ui->infoTxt->setText(  message.getString()   );
    conf->messageS = message;
}

void pilotWindow::showServerREsponse(QString s)
{
    ui->responsTxt->setText(s);
    ++fpsCounter;
}
pilotWindow::pilotWindow(my_config *c, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pilotWindow),
    worker(c),
    myGearBox(5)

{


    ui->setupUi(this);
    workerPTR = &worker;
    conf = c;
    c->addressIP=ui->adresIP->currentText().toStdString();
    c->port =  ui->port->text().toInt();
    t1 = new QTimer();
    tFPS = new QTimer();
    QObject::connect(tFPS,SIGNAL(timeout()),this,SLOT(display_FPS()));

    QObject::connect(t1,SIGNAL(timeout()),this,SLOT(showMessage()));
    QObject::connect( workerPTR,SIGNAL(sendResponse(QString)),this,SLOT(showServerREsponse(QString)));

    t1->start(100);
    tFPS->start(1000);
    double i = 0.50;
    int w  =  QApplication::desktop()->height()*i;
    if (w > QApplication::desktop()->width()*i)
    {
        w= QApplication::desktop()->width()*i;
    }
    joyPadDummy     = new JoyPad( w , w/4,Qt::red,Qt::yellow);
    joyPadDirection = new JoyPad( w , w/4,Qt::red,Qt::yellow);
    joyPadPower     = new JoyPad( w , w/4,Qt::red,Qt::yellow);



    QObject::connect(joyPadDirection, SIGNAL(sendPos(int,int) ),this,SLOT(getPosSkret(int,int) )  );\
    QObject::connect(joyPadPower  , SIGNAL(sendPos(int,int) ),this,SLOT(  getPosGaz(int,int) )  );
    QObject::connect(this,SIGNAL(resetPosNOW()),joyPadDirection,SLOT(resetPosNOW()));
    QObject::connect(this,SIGNAL(resetPosNOW()),joyPadPower,SLOT(resetPosNOW()));

    sceneDirection.addItem(joyPadDirection);
    scenePower.addItem(joyPadPower);

    ui->graphicsView_gaz ->setScene(&scenePower);
    ui->graphicsView_skret->setScene(&sceneDirection);

    //////////////////////////////////////////////////////////////////////////////////////////////////


    ui->gear->display(myGearBox.getGear());

    QApplication::desktop()->height();
    ui->infoTxt->setText(QString::number(w      ));

    test = new double[100000];
    //this->setAttribute(Qt::WA_NativeWindow);
    qDebug()<< " wielkosc: " << ui->graphicsView_gaz->sceneRect().height()<<" & "
            << ui->graphicsView_gaz->size();


    connect(QGamepadManager::instance(), &QGamepadManager::connectedGamepadsChanged, this,
            []() { qDebug() << "connected gamepads changed:"; });
    connect(QGamepadManager::instance(), &QGamepadManager::gamepadConnected, this,
            [](int deviceId) { qDebug() << "gamepad connected:" << deviceId; });
    connect(QGamepadManager::instance(), &QGamepadManager::gamepadDisconnected, this,
            [](int deviceId) { qDebug() << "gamepad disconnected:" << deviceId; });


    connect(QGamepadManager::instance(), SIGNAL(gamepadButtonPressEvent(int,QGamepadManager::GamepadButton,double)), this, SLOT(getButtonEventPress(int,QGamepadManager::GamepadButton,double))     );
    connect(QGamepadManager::instance(), SIGNAL(gamepadButtonReleaseEvent(int,QGamepadManager::GamepadButton)), this, SLOT(getButtonEventRelease(int,QGamepadManager::GamepadButton))  );


    connect(QGamepadManager::instance(), SIGNAL(gamepadAxisEvent(int,QGamepadManager::GamepadAxis,double)), this, SLOT(getAxisEvent(int,QGamepadManager::GamepadAxis,double)) );


    connect(QGamepadManager::instance(), &QGamepadManager::buttonConfigured, this,
            [](int deviceId, QGamepadManager::GamepadButton button) { qDebug() << "button configured:" << deviceId << button; });
    connect(QGamepadManager::instance(), &QGamepadManager::axisConfigured, this,
            [](int deviceId, QGamepadManager::GamepadAxis axis) { qDebug() << "axis configured:" << deviceId << axis; });
    connect(QGamepadManager::instance(), &QGamepadManager::configurationCanceled, this,
            [](int deviceId) { qDebug() << "configuration canceled:" << deviceId; });

//ui->push_minusGear->grabGesture(Qt::TapAndHoldGesture);
//ui->push_plusGear->grabGesture(Qt::TapAndHoldGesture);
//ui->push_plusGear->setAttribute(Qt::WA_AcceptTouchEvents);
}

pilotWindow::~pilotWindow()
{
    t1->stop();
    tFPS->stop();
    // delete przy;
    delete joyPadPower;
    delete joyPadDirection;
    delete test;
    delete t1;
    delete tFPS;
}

void pilotWindow::getAxisEvent(int deviceId, QGamepadManager::GamepadAxis axis, double value)
{
    int _value = value*100;
    if (axis == 0){
        _value = value*20*myGearBox.getGear();
        message.leftX = _value;
        ui->gazLCD_x->display(_value);
    }
    if (axis == 1){
        _value = value*20*myGearBox.getGear();
        message.leftY = _value;
        ui->gazLCD_y->display(_value);
    }
    if (axis == 2){
        message.rightX = _value;
        ui->skretLCD_x->display(_value);
    }
    if (axis == 3){
        message.rightY = _value;
        ui->skretLCD_y->display(_value);
    }


}

void pilotWindow::getButtonEventPress(int deviceId, QGamepadManager::GamepadButton button, double value)
{
    if (button == 4){
        on_buttonLowBeam_clicked();
    }

    else if (button == 6 ) {
        on_buttonHighBeam_clicked();
    }

}

void pilotWindow::getButtonEventRelease(int deviceId, QGamepadManager::GamepadButton button)
{
    if (button == 6 ) {
        on_buttonHighBeam_clicked();
    }
    else if (button == 5){
        on_push_plusGear_clicked();
    }
    else if (button == 7){
        on_push_minusGear_clicked();
    }
}



void pilotWindow::on_reset_clicked()
{
    emit resetPosNOW();

}








void pilotWindow::on_checkBoxPower_toggled(bool checked)
{
    autoReturnPower =checked;
    joyPadPower->setResetPos(autoReturnPower);
}

void pilotWindow::on_checkBoxWheel_toggled(bool checked)
{
    autoReturnDirection = checked;
    joyPadDirection->setResetPos(autoReturnDirection);
}


void pilotWindow::on_port_editingFinished()
{
    conf->port =  ui->port->text().toInt();
}

void pilotWindow::on_actionConnect_triggered()
{
    worker.start();
}

void pilotWindow::on_actionDisconnect_triggered()
{
    conf->goWhile=false;
}

void pilotWindow::on_actionEXIT_triggered()
{
    conf->goWhile=false;
    QThread::sleep(1);
    qApp->exit();
}

void pilotWindow::on_adresIP_currentTextChanged()
{
    conf->addressIP = ui->adresIP->currentText().toStdString();
}

void pilotWindow::on_checkBoxWheel_stateChanged()
{
    emit resetPosNOW();
}

void pilotWindow::display_FPS()
{
    ui->FPS_LCD->display(fpsCounter);
    fpsCounter = 0;
}

void pilotWindow::on_actionON_triggered()
{
    message.lowBeam = 1;
}

void pilotWindow::on_actionOFF_triggered()
{
    message.lowBeam = 0;
}

void pilotWindow::on_push_plusGear_clicked()
{
    myGearBox.gearUP();
    ui->gear->display(myGearBox.getGear());
}

void pilotWindow::on_push_minusGear_clicked()
{
    myGearBox.gearDOWN();
    ui->gear->display(myGearBox.getGear());
}


void pilotWindow::on_buttonLowBeam_clicked()
{
    message.lowBeam = !message.lowBeam;
    if (message.lowBeam == true){
        ui->buttonLowBeam->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
    }
    else{
         ui->buttonLowBeam->setStyleSheet("");
    }
}

void pilotWindow::on_buttonHighBeam_clicked()
{
    message.highBeam = !message.highBeam;
    if (message.highBeam == true){
        ui->buttonHighBeam->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
    }
    else{
         ui->buttonHighBeam->setStyleSheet("");
    }
}

void pilotWindow::on_buttonHorn_clicked()
{
    message.stateC = !message.stateC;
    if (message.stateC == true){
        ui->buttonHorn->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
    }
    else{
         ui->buttonHorn->setStyleSheet("");
    }
}

void pilotWindow::on_buttonDummy_clicked()
{
    message.stateD = !message.stateD;
    if (message.stateD == true){
        ui->buttonDummy->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
    }
    else{
         ui->buttonDummy->setStyleSheet("");
    }
}
