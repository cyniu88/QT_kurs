#include "idom_client.h"
#include "ui_idom_client.h"
#include <QPixmap>

iDom_Client::iDom_Client(iDom_CONFIG *config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iDom_Client)
{
    ui->setupUi(this);
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
    }
    ui->LOGO->setPixmap(pix);
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
