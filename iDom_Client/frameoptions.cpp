#include "frameoptions.h"
#include "ui_frameoptions.h"

FrameOptions::FrameOptions(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameOptions)
{
    ui->setupUi(this);
}

FrameOptions::~FrameOptions()
{
    delete ui;
}
