#include "setalarm.h"
#include "ui_setalarm.h"
#include <QDebug>
#include <QMessageBox>

setAlarm::setAlarm(iDom_CONFIG *config, QWidget *parent) :
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
    palette.setBrush(QPalette::Window, pix);
    this->setPalette(palette);

    //displayHour(7);
    //displayMinutes(0);
    m_config = config;
}

setAlarm::~setAlarm()
{
    delete ui;
}

QString setAlarm::getAlarmTimeQString()
{
    return QString::fromStdString(timeAlarm.getString());
}

void setAlarm::setAlarmTimeString(const Clock &alarm)
{
    qDebug() << "ustawiam alarm: " << QString::fromStdString( timeAlarm.getString());
    timeAlarm = alarm;
    qDebug() << "ustawiam alarm: " << QString::fromStdString( timeAlarm.getString());
}

void setAlarm::on_b_hourUp_clicked()
{
    int h = static_cast<int>(ui->lcd_hour->value() );
    if (h == 23){
        h = 0;
    }
    else{
        h++;
    }
    displayHour(h);
}

void setAlarm::on_b_hourDown_clicked()
{
    int h = static_cast<int>(ui->lcd_hour->value() );
    if (h == 0){
        h = 23;
    }
    else{
        h--;
    }
    displayHour(h);
}

void setAlarm::on_b_minutesUp_clicked()
{
    int m = static_cast<int>(ui->lcd_minutes->value() );
    if (m == 59){
        m = 0;
    }
    else{
        m++;
    }
    displayMinutes(m);
}

void setAlarm::on_b_minutesDown_clicked()
{
    int m = static_cast<int>(ui->lcd_minutes->value() );
    if (m == 0){
        m = 59;
    }
    else{
        m--;
    }
     displayMinutes(m);
}

void setAlarm::on_b_ok_clicked()
{
    timeAlarm.set(  static_cast<unsigned int>(ui->lcd_hour->value()),
                    static_cast<unsigned int>(ui->lcd_minutes->value())   );
    Clock timeToAlarm  = Clock::periodOfTime( Clock::getTime(), timeAlarm);
    qDebug()<<" alarm bedzie za "<<timeToAlarm.m_h<<" godzin "<< timeToAlarm.m_min << "minut";
    QString s = "Alarm jest ustawiony na ";
    if (timeToAlarm.m_h > 0){
        s += QString::number(timeToAlarm.m_h) + " godz ";
    }
    if (timeToAlarm.m_min > 0){
        s += QString::number(timeToAlarm.m_min) + " min ";
    }
    s += "od teraz";
    emit messageInfo("ALARM", s);
    emit alarmSetSignal(timeAlarm);

    if(m_config->houseLocked == true){
        QMessageBox::information(this,"ALERT","house has locked , ALARM NOT WORKING");
    }
}

void setAlarm::displayHour(int h)
{
    QString hStr;
    if (h<10) {
        hStr = "0"+QString::number(h);
    }
    else{
        hStr = QString::number(h);
    }
    ui->lcd_hour->display(hStr);
}

void setAlarm::displayMinutes(int min)
{
    QString mStr;
    if (min<10) {
        mStr = "0"+QString::number(min);
    }
    else{
        mStr = QString::number(min);
    }
    ui->lcd_minutes->display(mStr);
}
