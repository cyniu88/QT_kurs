#include "idomclient2.h"
#include "./ui_idomclient2.h"

iDomClient2::iDomClient2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::iDomClient2)
{
    ui->setupUi(this);
}

iDomClient2::~iDomClient2()
{
    delete ui;
}

