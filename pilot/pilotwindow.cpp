#include "pilotwindow.h"
#include "ui_pilotwindow.h"









void pilotWindow::getPosGaz(int x, int y)
{
    ui->gazLCD_x->display(x);
    ui->gazLCD_y->display(y);
}

void pilotWindow::getPosSkret(int x, int y)
{
    ui->skretLCD_x->display(x);
    ui->skretLCD_y->display(y);
}

pilotWindow::pilotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pilotWindow)
{

    ui->setupUi(this);



    joyPadGaz   = new JoyPad( 500 , 150,Qt::red,Qt::yellow);
    joyPadSkret = new JoyPad( 500 , 150,Qt::red,Qt::yellow);

    QObject::connect(joyPadGaz  , SIGNAL(sendPos(int,int) ),this,SLOT(  getPosGaz(int,int) )  );
    QObject::connect(joyPadSkret, SIGNAL(sendPos(int,int) ),this,SLOT(getPosSkret(int,int) )  );\


    sceneGaz.addItem(joyPadGaz);
    sceneSkret.addItem(joyPadSkret);
    ui->graphicsView_skret->setScene(&sceneSkret);
    ui->graphicsView_gaz ->setScene(&sceneGaz);

przy = new myButton();
przy->setText("dodo");
ui->gridLayout->addWidget(przy);

    test = new double[100000];
    //this->setAttribute(Qt::WA_NativeWindow);
    qDebug()<< " wielkosc: " << ui->graphicsView_gaz->sceneRect().height()<<" & "
            << ui->graphicsView_gaz->size();
}

pilotWindow::~pilotWindow()
{
    delete przy;
    delete joyPadGaz;
    delete joyPadSkret;
    delete test;
    delete ui;
}

void pilotWindow::on_reset_clicked()
{


}








void pilotWindow::on_checkBoxPower_toggled(bool checked)
{
    autoReturnGaz =checked;
}

void pilotWindow::on_checkBoxWheel_toggled(bool checked)
{
    autoReturnSkret = checked;
}
