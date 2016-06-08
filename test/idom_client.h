#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H

#include <QMainWindow>
#include <QObject>
#include <QSensorReading>


namespace Ui {
class iDom_client;
}

class iDom_client : public QMainWindow
{
    Q_OBJECT

public:
    explicit iDom_client(QWidget *parent = 0);
    ~iDom_client();

private slots:
    void on_progressBar_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_released();



    void on_swiatlo_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::iDom_client *ui;
    int i = 0;
};

#endif // IDOM_CLIENT_H
