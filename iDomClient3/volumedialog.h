#ifndef VOLUMEDIALOG_H
#define VOLUMEDIALOG_H

#include <QDialog>
#include <QObject>

namespace Ui {
class VolumeDialog;
}

class VolumeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VolumeDialog(QWidget *parent = 0);
    ~VolumeDialog();

    int getVolume();
    void setVolume(int i);

private slots:
    void on_dial_valueChanged(int value);

    void on_dial_sliderReleased();

private:
    Ui::VolumeDialog *ui;
signals:
    void setVolumeSingnal(int i);
};

#endif // VOLUMEDIALOG_H
