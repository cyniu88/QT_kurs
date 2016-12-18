#ifndef EYE_H
#define EYE_H

#include <QMainWindow>
#include <QSvgWidget>
namespace Ui {
class eye;
}

class eye : public QMainWindow
{
    Q_OBJECT

public:
    explicit eye(QWidget *parent = 0);
    ~eye();


private slots:
    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::eye *ui;
};

#endif // EYE_H
