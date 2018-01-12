#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <memory>
#include <QQuickWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QScroller>
#include <QProximitySensor>
#include <QSystemTrayIcon>
#include <QInputDialog>
#include <QDir>
#include <QtSvg/QSvgWidget>
#include <QTextToSpeech>
#include <QTime>
#include <QMenu>
#include <QTimer>

#ifdef Q_OS_WIN
#include <QAxWidget>
#endif

#include "wwwshowwindow.h"
#include "../libs/android_functions/android_interface/android_interface.h"
#include "workerip.h"
#include "variable.h"
#include "../libs/sgvTEST/thermometerSVG/thermometer.h"
#include "../libs/config_files/config_files.h"
#include "filedownloader.h"
#include "volumedialog.h"
#include "frameoptions.h"
#include "setalarm.h"

namespace Ui {
class iDom_Client;
}

class iDom_Client : public QMainWindow
{
    Q_OBJECT
public:
    explicit iDom_Client(iDom_CONFIG *config, QWidget *parent = 0);
    ~iDom_Client();
    void readSettings();

protected:
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    Ui::iDom_Client *ui;
    iDom_CONFIG *config;

    QMenu trayIconMenu;

    QTimer *taskHandlerTimer;
    /////////// okno dla www
    wwwShowWindow *wwwWindow = NULL;
    VolumeDialog vol;
    setAlarm alarmWindow;
    FrameOptions optionsWindow;
    void setCommandListInOptions();
    void sendSignalColor(int r,int g, int b, int from=0, int to=60);
    android_interface droid;
    QString temperatureString;
    QStringList mpdItems;

    Thermometer termoIN;
    Thermometer termoOUT;

    FileDownloader *m_pImgCtrl = NULL;
    bool cameraWork = false;
    QPixmap pima;
    QString cameraAddressHTTP = "";

    config_Files myConfigHandler;

    iDom_SYSTEM_INFO systemInfo;
    bool ledCamera = false;

#ifdef Q_OS_WIN
    QSystemTrayIcon  trayIcon;
    // QAxWidget  axWidgetTemperature;
    //  QAxWidget *axWidgetTemperaturePTR = NULL;
#endif

#ifdef Q_OS_ANDROID
    // QQuickWidget *viewTemp = NULL;
#endif
    QTextToSpeech *ivona;

    ////////////  volume counters
    QTime pressTime ;
    void setVolumeDial();
private slots:
    void slot_fontSize(QString s);

    void slot_getCommandList(QStringList list);

    void on_b_exit_released();

    void taskHandler();

    void on_b_sendConsole_released();

    void on_b_play_released();

    void on_b_LED_OFF_released();

    void on_b_led_2_released();

    void on_b_led_3_released();

    void on_b_led_4_released();

    void on_b_led_5_released();

    void on_b_all_led_released();

    void on_b_led_6_released();

    void on_b_led_7_released();

    void on_b_led_8_released();

    void on_b_led_9_released();

    void on_b_led_10_released();

    void on_b_led_11_released();

    void on_to_horizontalSlider_2_valueChanged();

    void on_from_horizontalSlider_valueChanged(int value);

    void on_spinBox_toLED_valueChanged(int value);

    void on_spinBox_fromLED_valueChanged(int value);

    void on_b_led_12_released();

    void on_b_led_13_released();

    void on_b_stop_released();

    void on_b_PREV_released();

    void on_b_Next_released();

    void on_b_pause_released();

    void on_b_volumeUP_released();

    void on_b_volumeDOWN_released();

    void on_b_exit_pressed();

    void on_b_led_1_released();

    void on_b_led_14_released();

    void on_b_led_15_released();

    void on_b_led_16_released();

    void on_b_led_17_released();

    void on_b_led_18_released();

    void on_b_led_19_released();

    void on_b_led_20_released();

    void on_b_led_25_released();

    void on_b_led_24_released();

    void on_b_led_23_released();

    void on_b_led_22_released();

    void on_b_led_21_released();

    void on_tabWidget_currentChanged();

    void on_b_setNumberMPD_clicked();

    void on_comboBox_currentIndexChanged(QString txt);

    void on_b_turnOnSleepMode_clicked();

    void on_b_stopServer_clicked();

    void on_b_extra_color_clicked();

    void on_b_put_temperature_clicked();

    void on_b_goodBye_clicked();

    void on_b_ttsInfo_clicked();

    void on_b_tabRight_clicked();

    void on_b_tabLeft_clicked();

    void on_horizontalSlider_tabNavigate_valueChanged(int value);

    void on_b_showTemperatureCharts_clicked();

    void loadImage(QByteArray d);

    void on_b_camera_reload_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_b_reloadCameraAddress_clicked();

    void on_b_oneShotCamera_clicked();

    void on_b_connect_dicsonnect_clicked();

    void on_b_volumeUP_pressed();

    void on_b_volumeDOWN_pressed();

    void on_b_options_clicked();

    void on_b_sms_clicked();

    void on_b_ledCamera_clicked();

    void on_b_printer_clicked();

    void on_b_setAlarm_clicked();

    void on_b_listwa_clicked();

public slots:
    void setLcdActual(int c);
    void setLcdAll(int c);
    void odb_answer(QString s);
    void readProgress(int c);
    void odb_answer_LED(QString s);
    void odb_answer_MPD(QString s);
    void odb_mpd_title (QString s);
    void odbMpdVolume(QString s);
    void makeInfo(QString tit, QString msg);
    void updateMPDinfo();
    void updateTemepretureInfo ();
    void odb_temperature (QString s);
    void odb_tools (QString s);
    void listMPD(QString s);
    void textToSpeachSLOTS(QString s);
    void connectDisconnectButtonState(bool state);
    void setVolumeValueSlot(int i);
    void getPing(QString s);
    void odb_answer_state(QString s);
    void alarmHasBeenSet(Clock c);
signals:
    void sendTCP(std::string addres, std::string s);
};

#endif // IDOM_CLIENT_H
