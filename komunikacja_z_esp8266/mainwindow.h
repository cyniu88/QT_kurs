#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connect_Button_clicked();

    void on_send_Button_clicked();

private:
    Ui::MainWindow *ui;

    QTcpSocket mySocket;
    bool isConnected = false;

    void waitSend(int waitTime, int counter);
    void waitRecv(int waitTime, int counter);
};

#endif // MAINWINDOW_H
