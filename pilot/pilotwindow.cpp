#include "pilotwindow.h"
#include "ui_pilotwindow.h"









pilotWindow::pilotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pilotWindow)
{

    ui->setupUi(this);
QRect n = QApplication::desktop()->screenGeometry();
int w = n.height();
joyPadGaz = new JoyPad(0,0, w-100 ,150,Qt::red,Qt::yellow);
joyPadSkret = new JoyPad(0,0,w-100  ,150,Qt::red,Qt::yellow);
sceneGaz.addItem(joyPadGaz);
sceneSkret.addItem(joyPadSkret);
ui->graphicsView_skret->setScene(&sceneSkret);
ui->graphicsView_gaz ->setScene(&sceneGaz);

    test = new double[100000];
    //this->setAttribute(Qt::WA_NativeWindow);

}

pilotWindow::~pilotWindow()
{
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
