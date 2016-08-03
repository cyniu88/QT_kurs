#include "dials.h"
#include "ui_dials.h"

dials::dials(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dials)
{
    ui->setupUi(this);
}

dials::~dials()
{
    delete ui;
}
