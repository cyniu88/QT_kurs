#ifndef DZIEN1_H
#define DZIEN1_H

#include <QMainWindow>
#include "TestAndroidClient.h"
#include "qgooglespeech.h"
namespace Ui {
class dzien1;
}

class dzien1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit dzien1(QWidget *parent = 0);
    ~dzien1();

private slots:
    void on_pushButton_close_pressed();

    void on_pushButton_close_released();

    void on_pushButton_pressed();

private:
    Ui::dzien1 *ui;
};

#endif // DZIEN1_H
