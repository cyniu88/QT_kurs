#include "idom_client.h"
#include "ui_idom_client.h"
#include "workerip.h"
#include "functions.h"
#include <QPixmap>
#include <QStackedWidget>
#include <QDebug>

namespace std {

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}
}
iDom_Client::iDom_Client(iDom_CONFIG *config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iDom_Client),
    config(config)
{
    ui->setupUi(this);





    ////  //////////////////////////    Ladowanie grafiki  ////////////////////////
    QPixmap pix;

    if (pix.load(config->background_img_w.c_str()))
    {
        qDebug("udalo sie Windows");
    }
    else if ( pix.load(config->background_img_a.c_str()))
    {
        qDebug("udalo sie android");
    }


    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);



    if (pix.load(config->logo_windows.c_str()))
    {
        qDebug("udalo sie Windows");
    }
    else if ( pix.load(config->logo_android.c_str()))
    {
        qDebug("udalo sie android");
        config->isWindows = false;
    }
    ui->LOGO->setPixmap(pix);
    //ui->icona->setIcon(pix);
    /////////////////////////////   ustawienie przezroczystosci tabWidgetu /////////////
//    border-width: 2px;"
//            "border-radius: 10px;"
//            "border-color: beige;"
//            "font: bold italic 24px;"
//    ui->tabWidget->setStyleSheet("background-color: transparent;"
//            "border-style: outset;"
//            "
//            "padding: 6px;"
//                                   );
    /////////////////////////////  ustawianie przezroczystosci i koloru  pola tekstowego ///////////
    QPalette p;
    p.setColor(QPalette::Text,Qt::green);
    p.setColor(ui->titleTXT->backgroundRole(), Qt::transparent);

    ui->titleTXT->setPalette(p);
    ui->titleTXT->setFrame(false);
    p.setColor(ui->volumeTXT->backgroundRole(),Qt::transparent);

    ui->volumeTXT->setPalette(p);
    ui->volumeTXT->setFrame(false);

    ui->lineEdit->setPalette(p);
    // ui->lineEdit->setStyleSheet("background:#0F0;");

    p.setColor(QPalette::Text,Qt::green);
    p.setColor(ui->wynik->backgroundRole(), Qt::transparent);
   ui->wynik->setPalette(p);

    ui->wynik->setText("...................... ");


}

iDom_Client::~iDom_Client()
{
    delete ui;
}

void iDom_Client::on_EXITButton_released()
{
    ui->centralWidget->close();


}

void iDom_Client::on_label_linkActivated(const QString &link)
{

}

void iDom_Client::odb_answer(QString s){
    ui->wynik->setText(s);
     ui->lcdNumber_2->display(s.size());
     ui->progressBar->setValue(100);
}

void iDom_Client::readProgress(int c)
{
    ui->progressBar->setValue(c);
}

void iDom_Client::zmienCounter(int c)
{
    ui->lcdNumber->display(c);
}

void iDom_Client::zmienCounter2(int c)
{

}



void iDom_Client::on_disconnectButton_released()
{
    if (ui->disconnectButton->text()=="DISCONNECT"){
    config->goWhile = false;
    ui->disconnectButton->setText("  CONNECT  ");
    }
    else
    {
        ui->disconnectButton->setText("DISCONNECT");
        config->goWhile = true;


    }
}

void iDom_Client::on_lineEdit_editingFinished()
{
    config->command = ui->lineEdit->text().toStdString();
}

void iDom_Client::on_pushButton_released()
{
   // QString *s = (config->command);
    //QDebug() << " mamy komende: " << s;
    emit sendTCP("button",config->command);

}

void iDom_Client::sendSignalColor(int r,int g, int b, int from, int to)
{
     emit sendTCP("button",
    "RS232 send LED:["+std::to_string(from)+"-"+std::to_string(to)+"-"+std::to_string(r)+"-"+std::to_string(g)+"-"+std::to_string(b)+"];"
     );
    std::string s_buffor = "RS232 send LED:["+std::to_string(from)+"-"+std::to_string(to)+"-"+std::to_string(r)+"-"+std::to_string(g)+"-"+std::to_string(b)+"];";
    qDebug() << QString::fromStdString(s_buffor);
}


void iDom_Client::on_playButton_released()
{
}

void iDom_Client::on_LED_OFF_Button_37_released()
{

    emit sendTCP("button","RS232 send LED_STOP:2;");
}

void iDom_Client::on_redButton_22_released()
{

    sendSignalColor(255,0,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());

}

void iDom_Client::on_pushButton_2_released()
{
   // config->command="RS232 send LED:[1-60-0-0-255];";
    sendSignalColor(0,0,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());

}

void iDom_Client::on_pushButton_3_released()
{
    //config->command="RS232 send LED:[1-60-0-255-0];";
    //emit sendTCP("button",config->command);
    sendSignalColor(0,255,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_4_released()
{
//    config->command="RS232 send LED:[1-60-254-254-51];";
//    emit sendTCP("button",config->command);
    sendSignalColor(255,255,51,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_5_released()
{
    //config->command="RS232 send LED:[1-60-254-0-128];";
    sendSignalColor(255,0,128,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}


void iDom_Client::on_RESET_pushButton_released()
{
    ui->spinBox_fromLED->setValue(0);
    ui->spinBox_toLED->setValue(60);
    ui->from_horizontalSlider->setValue(0);
    ui->to_horizontalSlider_2->setValue(60);
    ui->lcdNumber_fromLED->display(0);
    ui->lcdNumber_toLED->display(60);
}

void iDom_Client::on_pushButton_23_released()
{
    sendSignalColor(255,255,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_6_released()
{
    sendSignalColor(255,128,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_7_released()
{
    sendSignalColor(0,128,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_8_released()
{
    sendSignalColor(0,255,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_9_released()
{
    sendSignalColor(204, 93, 43,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_24_released()
{
    sendSignalColor(0, 127, 255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_to_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_toLED->setValue(ui->to_horizontalSlider_2->value());

    ui->lcdNumber_toLED->display(ui->to_horizontalSlider_2->value());
}

void iDom_Client::on_from_horizontalSlider_valueChanged(int value)
{
    ui->spinBox_fromLED->setValue(ui->from_horizontalSlider->value());
    ui->lcdNumber_fromLED->display(ui->from_horizontalSlider->value());
}

void iDom_Client::on_spinBox_toLED_valueChanged(int arg1)
{
    ui->to_horizontalSlider_2->setValue(ui->spinBox_toLED->value());
    ui->lcdNumber_toLED->display(ui->to_horizontalSlider_2->value());
}

void iDom_Client::on_spinBox_fromLED_valueChanged(int arg1)
{

    ui->from_horizontalSlider->setValue(ui->spinBox_fromLED->value());
    ui->lcdNumber_fromLED->display(ui->from_horizontalSlider->value());
}

void iDom_Client::on_pushButton_10_released()
{
    sendSignalColor(255, 165, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_11_released()
{
    sendSignalColor(128, 0, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}
