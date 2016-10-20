#include "pilotwindow.h"
#include "ui_pilotwindow.h"









void pilotWindow::getPosGaz(int x, int y)
{
    ui->gazLCD_x->display(x);
    ui->gazLCD_y->display(y);
    message.leftX=x;
    message.leftY=y;
}

void pilotWindow::getPosSkret(int x, int y)
{
    ui->skretLCD_x->display(x);
    ui->skretLCD_y->display(y);
    message.rightX=x;
    message.rightY=y;
}

void pilotWindow::getStateA(bool state)
{

    message.stateA=state;
}
void pilotWindow::getStateB(bool state)
{
    message.stateB=state;
}
void pilotWindow::getStateC(bool state)
{
    message.stateC=state;
}
void pilotWindow::getStateD(bool state)
{
    message.stateD=state;
}

void pilotWindow::showMessage()
{
    ui->infoTxt->setText(  message.getString()   );
    conf->messageS = message;
}

void pilotWindow::showServerREsponse(QString s)
{
    ui->responsTxt->setText(s);
}
pilotWindow::pilotWindow(my_config *c, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pilotWindow),
    worker(c)
{


    ui->setupUi(this);
    workerPTR = &worker;
    conf = c;
    c->addressIP=ui->adresIP->currentText().toStdString();
    c->port =  ui->port->text().toInt();
    t1 = new QTimer();

    QObject::connect(t1,SIGNAL(timeout()),this,SLOT(showMessage()));
    QObject::connect( workerPTR,SIGNAL(sendResponse(QString)),this,SLOT(showServerREsponse(QString)));

    t1->start(100);
    double i = 0.50;
    int w  =  QApplication::desktop()->height()*i;
    if (w > QApplication::desktop()->width()*i)
    {
        w= QApplication::desktop()->width()*i;
    }
    joyPadDummy   = new JoyPad( w , w/4,Qt::red,Qt::yellow);
    joyPadDirection = new JoyPad( w , w/4,Qt::red,Qt::yellow);
    joyPadPower   = new JoyPad( w , w/4,Qt::red,Qt::yellow);



    QObject::connect(joyPadDirection, SIGNAL(sendPos(int,int) ),this,SLOT(getPosSkret(int,int) )  );\
    QObject::connect(joyPadPower  , SIGNAL(sendPos(int,int) ),this,SLOT(  getPosGaz(int,int) )  );
    QObject::connect(this,SIGNAL(resetPosNOW()),joyPadDirection,SLOT(resetPosNOW()));
    QObject::connect(this,SIGNAL(resetPosNOW()),joyPadPower,SLOT(resetPosNOW()));

    sceneDirection.addItem(joyPadDirection);
    scenePower.addItem(joyPadPower);

    ui->graphicsView_gaz ->setScene(&scenePower);
    ui->graphicsView_skret->setScene(&sceneDirection);

    //////////////////////////////////////////////////////////////////////////////////////////////////

    A = new touchButton("A", Qt::red);
    B = new touchButton("B", Qt::red);
    C = new touchButton("C", Qt::red);
    D = new touchButton("D", Qt::red);

    QObject::connect( A,SIGNAL(sendState(bool)),this,SLOT(getStateA(bool)));
    QObject::connect( B,SIGNAL(sendState(bool)),this,SLOT(getStateB(bool)));
    QObject::connect( C,SIGNAL(sendState(bool)),this,SLOT(getStateC(bool)));
    QObject::connect( D,SIGNAL(sendState(bool)),this,SLOT(getStateD(bool)));

    sceneA.addItem(A);
    sceneB.addItem(B);
    sceneC.addItem(C);
    sceneD.addItem(D);

    ui->graphicsView_A->setScene(&sceneA);
    ui->graphicsView_B->setScene(&sceneB);
    ui->graphicsView_C->setScene(&sceneC);
    ui->graphicsView_D->setScene(&sceneD);


    sliderA = new myTouchslider(0,0,20,w*1.1);
    sliderB = new myTouchslider(0,0,w*1.1,10);

    sceneSliderA.addItem(sliderA);
    sceneSliderB.addItem(sliderB);

    ui->graphicsView_barV->setScene(&sceneSliderA);
    ui->graphicsView_barH->setScene(&sceneSliderB);



    QApplication::desktop()->height();
    ui->infoTxt->setText(QString::number(w      ));

    test = new double[100000];
    //this->setAttribute(Qt::WA_NativeWindow);
    qDebug()<< " wielkosc: " << ui->graphicsView_gaz->sceneRect().height()<<" & "
            << ui->graphicsView_gaz->size();
}

pilotWindow::~pilotWindow()
{
    t1->stop();
    // delete przy;
    delete joyPadPower;
    delete joyPadDirection;
    delete test;
    delete A;
    delete B;
    delete C;
    delete D;
    delete t1;
    delete sliderA;
    delete sliderB;
    /*
*/   //delete ui;
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

void pilotWindow::on_pushButton_pressed()
{
    conf->goWhile=false;
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
    qApp->exit();
}

void pilotWindow::on_adresIP_currentTextChanged()
{
    conf->addressIP = ui->adresIP->currentText().toStdString();
}
