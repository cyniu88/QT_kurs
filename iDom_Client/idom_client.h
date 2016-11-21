#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <memory>

#include <QMainWindow>
#include <QMessageBox>
#include <QScroller>
#include <QProximitySensor>
#include <QSystemTrayIcon>
#include <QInputDialog>
#include <QDir>

#ifdef Q_OS_WIN
#include <QAxWidget>
#endif
#ifdef Q_OS_ANDROID
#include <QtWebView/QtWebView>
#include <QtWebViewDepends>
#endif

#include "mainwindow.h"

#include "android_interface/android_interface.h"
#include "workerip.h"
#include "variable.h"

namespace Ui {
class iDom_Client;
}

class iDom_Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit iDom_Client(iDom_CONFIG *config, QWidget *parent = 0);
    ~iDom_Client();
private:
    Ui::iDom_Client *ui;
    iDom_CONFIG *config;

    MainWindow *okno;
    void sendSignalColor(int r,int g, int b, int from=0, int to=60);
    android_interface droid;
    QString temperatureString;
    QStringList mpdItems;

#ifdef Q_OS_WIN
    QSystemTrayIcon  trayIcon;
    QAxWidget  axWidgetTemperature;
    QAxWidget *  axWidgetTemperaturePTR = &axWidgetTemperature;
#endif
#ifdef Q_OS_ANDROID

#endif

private slots:
    void on_EXITButton_released();

    void scrollTitle();

    void on_pushButton_released();

    void on_playButton_released();

    void on_LED_OFF_Button_37_released();

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

    void on_to_horizontalSlider_2_valueChanged();

    void on_from_horizontalSlider_valueChanged(int value);

    void on_spinBox_toLED_valueChanged();

    void on_spinBox_fromLED_valueChanged( );

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

    void on_redButton_22_released();

    void on_pushButton_12_released();

    void on_pushButton_13_released();

    void on_pushButton_25_released();

    void on_pushButton_18_released();

    void on_pushButton_19_released();

    void on_pushButton_20_released();

    void on_pushButton_21_released();

    void on_pushButton_17_released();

    void on_pushButton_16_released();

    void on_pushButton_15_released();

    void on_pushButton_14_released();

    void on_pushButton_26_released();

    void on_tabWidget_currentChanged();

    void on_sendEXTRA_clicked();

    void on_setNumberMPD_clicked();

    void on_comboBox_currentIndexChanged();

    void on_setNumberMPD_pressed();

    void on_turnOnSleepModeButton_clicked();

    void on_stopServerButton_clicked();

public slots:
      void setLcdActual(int c);
      void setLcdAll(int c);
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
    void sendExtra();

};

#endif // IDOM_CLIENT_H
