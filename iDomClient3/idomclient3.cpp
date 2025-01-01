#include "idomclient3.h"
#include "./ui_idomclient3.h"

iDomClient3::iDomClient3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::iDomClient3)
{
    ui->setupUi(this);
}

iDomClient3::~iDomClient3()
{
    delete ui;
}

