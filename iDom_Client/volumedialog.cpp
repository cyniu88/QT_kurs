#include "volumedialog.h"
#include "ui_volumedialog.h"

VolumeDialog::VolumeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VolumeDialog)
{
    ui->setupUi(this);
    QPixmap pix;

    if (pix.load( ":/new/prefix1/files/background.png"   ))
    {

    }
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);


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
