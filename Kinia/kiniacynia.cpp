#include "kiniacynia.h"
#include"ui_kiniacynia.h"
#include <QPixmap>

KiniaCynia::KiniaCynia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KiniaCynia)
{
    ui->setupUi(this);
}

KiniaCynia::~KiniaCynia()
{
    delete ui;
}

void KiniaCynia::on_pushButton_clicked()
{
    if("Dzień dobry"== ui->odp->toPlainText() )
    {
        ui->fajorwki->setPixmap( QPixmap(":/tapety/images.jpg") );
    }
    if("Cześć"== ui->odp->toPlainText() )
    {
        ui->fajorwki->setText("Kocham męża");
    }
}
