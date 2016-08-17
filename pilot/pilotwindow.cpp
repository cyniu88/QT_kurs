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
    double i = 0.55;
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
    ui->infoTxt->setText(QString::number(QApplication::desktop()->height()      ));

    test = new double[100000];
    //this->setAttribute(Qt::WA_NativeWindow);
    qDebug()<< " wielkosc: " << ui->graphicsView_gaz->sceneRect().height()<<" & "
            << ui->graphicsView_gaz->size();
}

pilotWindow::~pilotWindow()
{
    // delete przy;
    delete joyPadGaz;
    delete joyPadSkret;
    delete test;
    delete A;
    delete B;
    delete C;
    delete D;

    delete ui;
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

