#include "setalarm.h"
#include "ui_setalarm.h"

setAlarm::setAlarm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setAlarm)
{
    ui->setupUi(this);

    ////  //////////////////////////    Ladowanie grafiki  ////////////////////////
    QPixmap pix;

    if (pix.load( ":/new/prefix1/files/background.png"   ))
    {

    }
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);
}

setAlarm::~setAlarm()
{
    delete ui;
}

void setAlarm::on_b_hourUp_clicked()
{
    int h = ui->lcd_hour->value();
    if (h == 23){
        h = 0;
    }
    else{
        h++;
    }
    ui->lcd_hour->display(h);
}

void setAlarm::on_b_hourDown_clicked()
{
    int h = ui->lcd_hour->value();
    if (h == 0){
        h = 23;
    }
    else{
        h--;
    }
    ui->lcd_hour->display(h);
}

void setAlarm::on_b_minutesUp_clicked()
{
    int m = ui->lcd_minutes->value();
    if (m == 59){
        m = 0;
    }
    else{
        m++;
    }
    ui->lcd_minutes->display(m);
}

void setAlarm::on_b_minutesDown_clicked()
{
    int m = ui->lcd_minutes->value();
    if (m == 0){
        m = 59;
    }
    else{
        m--;
    }
    ui->lcd_minutes->display(m);

}

void setAlarm::on_buttonBox_accepted()
{
    timeAlarm.set(  static_cast<unsigned int> (ui->lcd_hour->value()),
                    static_cast<unsigned int> (ui->lcd_minutes->value())   );
    emit alarmSetSignal(timeAlarm);
}
