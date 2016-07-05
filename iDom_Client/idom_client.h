#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H
#include <variable.h>
#include <QMainWindow>
#include "workerip.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
namespace Ui {
class iDom_Client;
}

class iDom_Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit iDom_Client(iDom_CONFIG *config, QWidget *parent = 0);
    ~iDom_Client();

private slots:
    void on_EXITButton_released();

    void on_label_linkActivated(const QString &link);



    void on_disconnectButton_released();

    void on_lineEdit_editingFinished();

    void on_pushButton_released();



    void on_playButton_released();

    void on_LED_OFF_Button_37_released();

    void on_redButton_22_released();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_4_released();

    void on_pushButton_5_released();

    void on_RESET_pushButton_released();

private:
    Ui::iDom_Client *ui;
    iDom_CONFIG *config;
    void sendSignalColor(int r,int g, int b, int from=0, int to=60);
public slots:
      void zmienCounter(int c);
      void zmienCounter2(int c);
      void odb_answer(QString s);
      void readProgress(int c);

signals:

    void sendTCP(QString addres, std::string s);



};

#endif // IDOM_CLIENT_H
