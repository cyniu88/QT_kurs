#include "idom_client.h"
#include "ui_idom_client.h"
#include "workerip.h"
#include <QPixmap>
#include <QStackedWidget>

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
    ui->tabWidget->setStyleSheet("background-color: transparent;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: beige;"
            "font: bold italic 24px;"

            "padding: 6px;"
                                   );
    /////////////////////////////  ustawianie przezroczystosci i koloru  pola tekstowego ///////////
    QPalette p;
    p.setColor(QPalette::Text,Qt::green);
    p.setColor(ui->titleTXT->backgroundRole(), Qt::transparent);

    ui->titleTXT->setPalette(p);
    ui->titleTXT->setFrame(false);
    p.setColor(ui->volumeTXT->backgroundRole(),Qt::transparent);

    ui->volumeTXT->setPalette(p);
    ui->volumeTXT->setFrame(false);

    ui->lineEdit->setStyleSheet("background:#0F0;");

    p.setColor(QPalette::Text,Qt::green);
    p.setColor(ui->wynik->backgroundRole(), Qt::transparent);
    ui->wynik->setText("co to jest ma byc tego  bardzo dzuo wiec nie wiem co powstanie ");
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
    config->IPMutex.unlock();
    QThread::sleep(1);
    config->IPMutex.lock();
    QThread::sleep(2);
    ui->wynik->setText(QString::fromStdString( s_buffor));
}
