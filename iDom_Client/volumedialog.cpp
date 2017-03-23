#include "volumedialog.h"
#include "ui_volumedialog.h"

VolumeDialog::VolumeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VolumeDialog)
{
    ui->setupUi(this);
}

VolumeDialog::~VolumeDialog()
{
    delete ui;
}

int VolumeDialog::getVolume()
{
    return ui->dial->value();
}

void VolumeDialog::setVolume(int i)
{
    ui->dial->setValue(i);
    ui->progressBar->setValue(i);
}

void VolumeDialog::on_dial_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}

void VolumeDialog::on_dial_sliderReleased()
{
    qDebug("puszczam kolko");
    emit setVolumeSingnal(ui->dial->value());
    this->close();
}
