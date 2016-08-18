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
}
pilotWindow::pilotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pilotWindow)
{

    ui->setupUi(this);
    t1 = new QTimer();

    QObject::connect(t1,SIGNAL(timeout()),this,SLOT(showMessage()));

    t1->start(100);
    double i = 0.50;
    int w  =  QApplication::desktop()->height()*i;
    if (w > QApplication::desktop()->width()*i){
        w= QApplication::desktop()->width()*i;
    }
    joyPadGaz   = new JoyPad( w , w/4,Qt::red,Qt::yellow);
    joyPadSkret = new JoyPad( w , w/4,Qt::red,Qt::yellow);

    QObject::connect(joyPadGaz  , SIGNAL(sendPos(int,int) ),this,SLOT(  getPosGaz(int,int) )  );
    QObject::connect(joyPadSkret, SIGNAL(sendPos(int,int) ),this,SLOT(getPosSkret(int,int) )  );\


    sceneGaz.addItem(joyPadGaz);
    sceneSkret.addItem(joyPadSkret);
    ui->graphicsView_skret->setScene(&sceneSkret);
    ui->graphicsView_gaz ->setScene(&sceneGaz);

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

    /*przy = new myButton();
przy->setText("dodo");
ui->gridLayout->addWidget(przy);
*/
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
    delete joyPadGaz;
    delete joyPadSkret;
    delete test;
    delete A;
    delete B;
    delete C;
    delete D;
    delete t1;
    /*
*/   //delete ui;
}

void pilotWindow::on_reset_clicked()
{


}








void pilotWindow::on_checkBoxPower_toggled(bool checked)
{
    autoReturnGaz =checked;
    joyPadGaz->setResetPos(autoReturnGaz);
}

void pilotWindow::on_checkBoxWheel_toggled(bool checked)
{
    autoReturnSkret = checked;
    joyPadSkret->setResetPos(autoReturnSkret);
}

