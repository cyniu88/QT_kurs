#include <QScroller>
#include "dzien1.h"
#include "ui_dzien1.h"

dzien1::dzien1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dzien1)
{
    ui->setupUi(this);
    //QScroller::grabbedGesture(ui->scrollArea);
    QScroller::grabGesture(ui->scrollArea,QScroller::TouchGesture);
}

dzien1::~dzien1()
{
    delete ui;
}

void dzien1::on_pushButton_close_pressed()
{
   ui->lcdNumber->display(6);
}

void dzien1::on_pushButton_close_released()
{
   // ui->centralWidget->close();

}

void dzien1::on_pushButton_pressed()
{
     QGoogleSpeech mow("polish");
     mow.speech("witaj cyniu");
}
