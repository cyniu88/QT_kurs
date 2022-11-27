#include "idom_client.h"
#include "ui_idom_client.h"
#include <QScreen>
iDom_client::iDom_client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::iDom_client)
{
    ui->setupUi(this);

    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int  height = rec.height();
    int  width  = rec.width();
    std::string s =  std::to_string(height) +" and " + std::to_string(width)  ;

    rec.setHeight(2000);
    rec.setWidth(1090);
    QGuiApplication::primaryScreen()->geometryChanged(rec);


    ui->textEdit->setText(QString::fromStdString( s));
}

iDom_client::~iDom_client()
{
    delete ui;
}

