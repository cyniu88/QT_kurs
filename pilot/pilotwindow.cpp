#include "pilotwindow.h"
#include "ui_pilotwindow.h"

#include <QInputDialog>
#include <QProcess>

#include "functions.h"

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
    ++msgCounter;
    ui->lcdMsgCounter->display(msgCounter);
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
    c->addressIpList = QString(mainConfig.readFromFile("config","ip.cfg","192.168.1.204\n192.168.43.27\ncyniu88.no-ip.pl").c_str()).split("\n");
    c->port = QString(mainConfig.readFromFile("config","port.cfg", "8833").c_str()).toInt()  ;

    t1 = new QTimer();
    tFPS = new QTimer();
    QObject::connect(tFPS,SIGNAL(timeout()),this,SLOT(display_FPS()));
    QObject::connect(t1,SIGNAL(timeout()),this,SLOT(showMessage()));
    QObject::connect( workerPTR,SIGNAL(sendResponse(QString)),this,SLOT(showServerREsponse(QString)));
    QObject::connect(workerPTR,SIGNAL(sendMSG(QString,QString)),this,SLOT(getMSG(QString,QString)) );

    t1->start(100);
    tFPS->start(1000);
    double i = 0.50;
#ifdef Q_OS_WIN
    i = 0.15;
#endif
    int w  =  static_cast<int>(QApplication::desktop()->height()*i);
    if (w > QApplication::desktop()->width()*i)
    {
        w = static_cast<int>(QApplication::desktop()->width()*i);
    }
      //joyPadDummy     = new JoyPad( w , w/4,Qt::red,Qt::yellow);
     // joyPadDummy2     = new JoyPad( w , w/4,Qt::red,Qt::yellow);
    joyPadDirection = new JoyPad( w , w/4,Qt::red,Qt::yellow);

    joyPadPower     = new JoyPad( w , w/4,Qt::red,Qt::yellow);


    QObject::connect(joyPadDirection, SIGNAL(sendPos(int,int) ),this,SLOT(getPosSkret(int,int) )  );\
    QObject::connect(joyPadPower    , SIGNAL(sendPos(int,int) ),this,SLOT(getPosGaz  (int,int) )  );
    QObject::connect(this , SIGNAL(resetPosNOW()),joyPadDirection,SLOT(resetPosNOW()));
    QObject::connect(this,SIGNAL(resetPosNOW()),joyPadPower,SLOT(resetPosNOW()));

    QObject::connect(this, SIGNAL(setPosNOW_Right(int,int)), joyPadDirection,SLOT(setPosNOW(int,int)));
    QObject::connect(this, SIGNAL(setPosNOW_Left (int,int)), joyPadPower    ,SLOT(setPosNOW(int,int)));
    //////////////////////////////////////////////////////////////////////////////////////////////////

    ui->gear->display( myGearBox.getGear() );

    QApplication::desktop()->height();
    ui->infoTxt->setText( QString::number(w) );

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

    // kolorwanie przycisku skrzyni automatycznej
//    if (myGearBox.automaticWorkFlag == true){
//        ui->buttonAutomatGearbox->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
//    }

    inputDialogStyleSheet.setStyleSheet("background-color: rgba(0, 255, 0, 50); color: rgba(255, 255, 255); font: bold 14px; font-size: 20pt; ");
    inputDialogStyleSheet.move(QApplication::desktop()->screen()->rect().center()- inputDialogStyleSheet.rect().center() );
    droid.keepScreenOn(true);
#ifdef Q_OS_ANDROID
    ui->tabWidget->tabBar()->hide();
#endif
    sceneDirection.addItem(joyPadDirection);
    scenePower.addItem(joyPadPower);

    ui->graphicsView_gaz ->setScene(&scenePower);
    ui->graphicsView_skret->setScene(&sceneDirection);
}

pilotWindow::~pilotWindow()
{
    t1->stop();
    tFPS->stop();
    droid.keepScreenOn(false);

    delete joyPadPower;
    delete joyPadDirection;
    delete t1;
    delete tFPS;
}

void pilotWindow::getAxisEvent(int deviceId, QGamepadManager::GamepadAxis axis, double value)
{
    int _value = static_cast<int>(value*100);

    if (axis == 0){
        message.leftX = _value;
        ui->gazLCD_x->display(static_cast<int>(value*100));
    }
    if (axis == 1){
        _value = static_cast<int>(value*20*myGearBox.getGear());
        //qDebug() << "vale: " << _value <<" " << 20*_value*myGearBox.getGear();
        message.leftY = _value;
        ui->gazLCD_y->display(static_cast<int>(value*100));
    }
    if (axis == 2){
        message.rightX = _value;
        ui->skretLCD_x->display(static_cast<int>(value*100));
    }
    if (axis == 3){
        message.rightY = _value;
        ui->skretLCD_y->display(static_cast<int>(value*100));
    }

    emit setPosNOW_Left(message.leftX,message.leftY);
    emit setPosNOW_Right(message.rightX, message.rightY);
}

void pilotWindow::getButtonEventPress(int deviceId, QGamepadManager::GamepadButton button, double value)
{
    if (button == QGamepadManager::GamepadButton::ButtonL1 /*|| button == 192*/ ){
        on_buttonLowBeam_clicked();
    }

    else if (button == QGamepadManager::GamepadButton::ButtonL2 /*|| button == 194*/ ) {
        on_actionON_2_triggered();
    }
    else if (button == QGamepadManager::GamepadButton::ButtonL3 /*|| button == 198*/) {
        on_actionAutomat_triggered();
    }
    //qDebug() << "Przycisk: " <<button;
    //getMSG("button",QString::number(button));
}

void pilotWindow::getButtonEventRelease(int deviceId, QGamepadManager::GamepadButton button)
{
    if (button == QGamepadManager::GamepadButton::ButtonL2 /*|| button == 194*/ ) {
        on_actionOFF_2_triggered();
    }
    else if (button == QGamepadManager::GamepadButton::ButtonR1 /*|| button == 193*/){
        on_actionUP_triggered();
    }
    else if (button == QGamepadManager::GamepadButton::ButtonR2 /*|| button == 195*/){
        on_actionDOWN_triggered();
    }
    else if (button == QGamepadManager::GamepadButton::ButtonY ){
        on_buttonTrailerMechanism_clicked();
    }
    else if (button == QGamepadManager::GamepadButton::ButtonX ){
        on_buttonHighBeam_clicked();
    }
}



void pilotWindow::on_reset_clicked()
{
    emit resetPosNOW();
    droid.vibrate(100);
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

void pilotWindow::on_actionConnect_triggered()
{
    worker.start();
    msgCounter=0;

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

void pilotWindow::on_checkBoxWheel_stateChanged()
{
    emit resetPosNOW();
}

void pilotWindow::display_FPS()
{
    ui->FPS_LCD->display(fpsCounter);

    //automat skrzyni biegow przy okazji uruchaminy co sekunde
    myGearBox.automaticGearBoxHandle(static_cast<int>(ui->gazLCD_y->value()));
    ui->gear->display(myGearBox.getGear());
    message.leftY = static_cast<int>(ui->gazLCD_y->value()*0.20*myGearBox.getGear());
    fpsCounter = 0;
}

void pilotWindow::on_actionON_triggered()
{
    if (message.lowBeam == false){
        on_buttonLowBeam_clicked();
    }
}

void pilotWindow::on_actionOFF_triggered()
{
    if (message.lowBeam == true){
        on_buttonLowBeam_clicked();
    }
}

void pilotWindow::on_push_plusGear_clicked()
{
    myGearBox.gearUP();
    ui->gear->display(myGearBox.getGear());
    message.leftY = static_cast<int>(ui->gazLCD_y->value()*0.2*myGearBox.getGear());
    droid.vibrate(100);
}

void pilotWindow::on_push_minusGear_clicked()
{
    myGearBox.gearDOWN();
    ui->gear->display(myGearBox.getGear());
    message.leftY = static_cast<int>(ui->gazLCD_y->value()*0.2*myGearBox.getGear());
    droid.vibrate(100);
}

void pilotWindow::on_buttonLowBeam_clicked()
{
    droid.vibrate(100);
    message.lowBeam = !message.lowBeam;
    if (message.lowBeam == true){
        ui->buttonLowBeam->setChecked(true);
        //ui->buttonLowBeam->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
    }
    else{
        //ui->buttonLowBeam->setStyleSheet("");
        ui->buttonLowBeam->setChecked(false);
    }
}

void pilotWindow::on_buttonHighBeam_clicked()
{
    droid.vibrate(100);
    message.highBeam = !message.highBeam;
    if (message.highBeam == true){
        ui->buttonHighBeam->setChecked(true);
    }
    else{
       // ui->buttonHighBeam->setStyleSheet("");
        ui->buttonHighBeam->setChecked(false);
    }
}

void pilotWindow::on_buttonTrailerMechanism_clicked()
{
    droid.vibrate(100);
    message.stateC = !message.stateC;
    if (message.stateC == true){
        ui->buttonTrailerMechanism->setChecked(true);
       // ui->buttonTrailerMechanism->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
    }
    else{
       // ui->buttonTrailerMechanism->setStyleSheet("");
        ui->buttonTrailerMechanism->setChecked(false);
    }
}

void pilotWindow::on_buttonReverseLight_clicked()
{
    droid.vibrate(100);
    message.stateD = !message.stateD;
    if (message.stateD == true){
        //ui->buttonReverseLight->setStyleSheet("background-color: rgba(0, 255, 0, 50);");
        ui->buttonReverseLight->setChecked(true);
        message.leftY=1;
    }
    else{
       // ui->buttonReverseLight->setStyleSheet("");
        ui->buttonReverseLight->setChecked(false);
    }
}

void pilotWindow::getMSG(QString tit, QString msg)
{
#ifdef Q_OS_WIN
    QMessageBox::information(this, tit,msg);
#endif
    droid.makeToast(msg);
}

void pilotWindow::on_horizontalSlider_sliderReleased()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->minimum());
}

void pilotWindow::on_horizontalSlider_valueChanged(int value)
{
    message.horiSlider = value;// ui->horizontalSlider->value();
}

void pilotWindow::on_buttonAutomatGearbox_clicked()
{
    myGearBox.automaticWorkFlag = !myGearBox.automaticWorkFlag;
    if (myGearBox.automaticWorkFlag == true){
        ui->buttonAutomatGearbox->setChecked(true);
    }
    else{
        ui->buttonAutomatGearbox->setChecked(false);
    }
    droid.vibrate(100);
}

void pilotWindow::on_actionON_2_triggered()
{
    if (message.highBeam == false){
        on_buttonHighBeam_clicked();
    }
}

void pilotWindow::on_actionOFF_2_triggered()
{
    if (message.highBeam == true){
        on_buttonHighBeam_clicked();
    }
}

void pilotWindow::on_lcdMsgCounter_overflow()
{
    msgCounter =0 ;
}

void pilotWindow::on_actionPORT_triggered()
{
    bool ok;
    QInputDialog myInputDialog;

    int i = myInputDialog.getInt(&inputDialogStyleSheet,"SET","SET PORT",conf->port,8000,9000,1,&ok);
    if(ok){
        conf->port = i;
        mainConfig.writeToFile("config","port.cfg", to_stringAndroid(i) );
    }
}

void pilotWindow::on_actionADDRESS_triggered()
{
    bool ok;
    conf->addressIpList = QString::fromStdString(mainConfig.readFromFile("config","ip.cfg")).split("\n");

    QInputDialog myInputDialog;
    QString id = myInputDialog.getItem(&inputDialogStyleSheet, tr("address"),
                                       tr("set IP address"),conf->addressIpList,1,false, &ok);

    if (ok && !id.isEmpty()){

        conf->addressIP = id.toStdString();
        on_actionConnect_triggered();
    }
}

void pilotWindow::on_actionAdd_address_triggered()
{
    bool ok;
    std::string t;
    QInputDialog myInputDialog;

    for (auto i : conf->addressIpList){
        t +=   i.toStdString() +"\n";
    }
    //t = myInputDialog.getMultiLineText(&inputDialogStyleSheet,"add IP","add IP", QString::fromStdString(t) ,&ok).toStdString();
    QInputDialog::InputMode zz = QInputDialog::TextInput;
    myInputDialog.setInputMode (zz   );
    myInputDialog.setOption(QInputDialog::UsePlainTextEditForTextInput);
    myInputDialog.setStyleSheet("background-color: rgba(0, 255, 0, 50); color: rgba(255, 255, 255); font: bold 14px; font-size: 20pt; ");
    myInputDialog.setLabelText("add IP");
    myInputDialog.setTextValue(QString::fromStdString(t));
    int prc =200;
#ifdef Q_OS_WIN
    prc = 800;
#endif
    myInputDialog.resize(QApplication::desktop()->screenGeometry().width()-prc-100,QApplication::desktop()->screenGeometry().height()-prc);
    ok = myInputDialog.exec();
    t = myInputDialog.textValue().toStdString();
    if(ok){
        conf->addressIpList.clear();
        conf->addressIpList = QString::fromStdString(t).split("\n");

        mainConfig.writeToFile("config","ip.cfg",t);
    }
}



void pilotWindow::on_actionShow_IP_arp_triggered()
{
    QProcess  nowy;
#ifdef Q_OS_ANDROID
    nowy.start("cat /proc/net/arp");
#endif
#ifdef Q_OS_WIN
    nowy.start("arp -a");
#endif
    nowy.waitForFinished();
    getMSG("found IP", nowy.readAllStandardOutput());
}

void pilotWindow::on_actioncamera_triggered()
{
    ui->tabWidget->setCurrentIndex(1);
}

void pilotWindow::on_actionpad_triggered()
{
    ui->tabWidget->setCurrentIndex(0);
}

void pilotWindow::on_actionUP_triggered()
{
    on_push_plusGear_clicked();
}

void pilotWindow::on_actionDOWN_triggered()
{
    on_push_minusGear_clicked();
}

void pilotWindow::on_actionAutomat_triggered()
{
    on_buttonAutomatGearbox_clicked();
}
