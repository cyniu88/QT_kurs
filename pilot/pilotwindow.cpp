#include "pilotwindow.h"
#include "ui_pilotwindow.h"





void pilotWindow::touchEvent(QTouchEvent *ev)
{
    switch (ev->type())
      {
        case QEvent::TouchBegin:
            qDebug("Event began.");
            break;
        case QEvent::TouchEnd:
            qDebug("Event ended.");
            break;
        case QEvent::TouchUpdate:
        {
            qDebug("Event updated.");
            break;
        }
      }
}

pilotWindow::pilotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pilotWindow)
{
    ui->setupUi(this);
    test = new double[100000];
    //this->setAttribute(Qt::WA_NativeWindow);
    QScroller::grabGesture(ui->gaz,QScroller::TouchGesture);
    QScroller::grabGesture(ui->skret,QScroller::TouchGesture);
    setAttribute(Qt::WA_AcceptTouchEvents);
    ui->skret->setAttribute(Qt::WA_AcceptTouchEvents);
    ui->gaz->setAttribute(Qt::WA_AcceptTouchEvents);
    ui->horizontalScrollBar->setAttribute(Qt::WA_AcceptTouchEvents);
    ui->horizontalScrollBar_2->setAttribute(Qt::WA_AcceptTouchEvents);
}

pilotWindow::~pilotWindow()
{
    delete test;
    delete ui;
}

void pilotWindow::on_reset_clicked()
{
    ui->gaz->setValue(50);
    ui->skret->setValue(50);
}

void pilotWindow::on_gaz_valueChanged(int value)
{
    ui->gazLCD->display(ui->gaz->value());
}



void pilotWindow::on_skret_valueChanged(int value)
{
    ui->skretLCD->display(ui->skret->value());
}

void pilotWindow::on_skret_sliderReleased()
{
    if (autoReturnSkret == true)
    {
        ui->skret->setValue(50);
    }
}

void pilotWindow::on_gaz_sliderReleased()
{
    if (autoReturnGaz == true)
    {
        ui->gaz->setValue(50);
    }
}

void pilotWindow::on_checkBoxPower_toggled(bool checked)
{
    autoReturnGaz =checked;
}

void pilotWindow::on_checkBoxWheel_toggled(bool checked)
{
    autoReturnSkret = checked;
}
