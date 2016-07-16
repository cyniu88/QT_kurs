#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H

#include <iostream>
#include <stdlib.h>
#include <sstream>

#include <QMainWindow>
#include <QMessageBox>
#include <QScroller>

#include "workerip.h"
#include "variable.h"
#include "androidhelper_cyniu.h"
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

    void on_pushButton_23_released();

    void on_pushButton_6_released();

    void on_pushButton_7_released();

    void on_pushButton_8_released();

    void on_pushButton_9_released();

    void on_pushButton_24_released();

    void on_to_horizontalSlider_2_valueChanged(int value);

    void on_from_horizontalSlider_valueChanged(int value);

    void on_spinBox_toLED_valueChanged(int arg1);

    void on_spinBox_fromLED_valueChanged(int arg1);

    void on_pushButton_10_released();

    void on_pushButton_11_released();

    void on_stopButton_released();



    void on_pushButtonPREV_released();

    void on_pushButtonNext_released();

    void on_pushButton_pause_released();

    void on_pushButton_volumeUP_released();

    void on_pushButton_volumeDOWN_released();

    void on_exitButton_pressed();

    void on_pushButtonupdateinfo_released();

    void on_pushButton_22_released();

private:
    Ui::iDom_Client *ui;
    iDom_CONFIG *config;
    void sendSignalColor(int r,int g, int b, int from=0, int to=60);
public slots:
      void zmienCounter(int c);
      void zmienCounter2(int c);
      void odb_answer(QString s);
      void readProgress(int c);
      void odb_answer_LED(QString s);
      void odb_answer_MPD(QString s);
      void odb_mpd_title (QString s);
      void odbMpdVolume(QString s);
      void errorRead(QString tit, QString msg);
      void updateMPDinfo();
      void updateTemepretureInfo ();
      void odb_temperature (QString s);




signals:

    void sendTCP(std::string addres, std::string s);



};

#endif // IDOM_CLIENT_H
