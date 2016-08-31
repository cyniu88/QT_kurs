#ifndef PROGRAM1_H
#define PROGRAM1_H

#include <QMainWindow>
#include <QMessageBox>
#include <QObject>

namespace Ui {
class program1;
}

class program1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit program1(QWidget *parent = 0);
    ~program1();

private slots:
    void on_pushButton_released();

    void on_pushButton_setNumber_pressed();

    void on_pushButton_setNumber_released();

private:
    Ui::program1 *ui;
};

#endif // PROGRAM1_H
