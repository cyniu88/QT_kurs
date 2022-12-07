#ifndef IDOM_CLIENT_H
#define IDOM_CLIENT_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <memory>
//#include <QQuickWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QScroller>
//#include <QProximitySensor>
#include <QSystemTrayIcon>
#include <QInputDialog>
#include <QDir>
#include <QSvgWidget>
#include <QTextToSpeech>
#include <QTime>
#include <QMenu>
#include <QTimer>

#ifdef Q_OS_WIN
//#include <QAxWidget>
#endif

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
    VolumeDialog vol;
    setAlarm alarmWindow;
    FrameOptions optionsWindow;
    void setCommandListInOptions();
    void sendSignalColor(int r,int g, int b, int from=0, int to=60);
    android_interface droid;
    QString temperatureString;
    QStringList mpdItems;

    FileDownloader *m_pImgCtrl = nullptr;
    bool cameraWork = false;
    QPixmap pima;
    QString cameraAddressHTTP = "";

    config_Files myConfigHandler;

    iDom_SYSTEM_INFO systemInfo;
    bool ledCamera = false;

    ///  kontener do trzymana konfiguracji zarowek
    QMap<std::string, QVector<QString>> lightConf;

#ifdef Q_OS_ANDROID
    // QQuickWidget *viewTemp = NULL;
#else
    QSystemTrayIcon  trayIcon;
#endif

    QTextToSpeech *ivona;

    ////////////  volume counters
    QElapsedTimer pressTime ;
    void setVolumeDial();
private slots:
    void slot_fontSize(QString s);
    void slot_getCommandList(QStringList list);
    void taskHandler();
    void on_b_sendConsole_released();
    void on_b_play_released();
    void on_b_stop_released();
    void on_b_PREV_released();
    void on_b_Next_released();
    void on_b_pause_released();
    void on_b_volumeUP_released();
    void on_b_volumeDOWN_released();
    void on_tabWidget_currentChanged();
    void on_b_setNumberMPD_clicked();
    void on_b_turnOnSleepMode_clicked();
    void on_b_server_clicked();
    void on_b_goodBye_clicked();
    void on_b_ttsInfo_clicked();
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
    void on_b_lockUnlock_HOME_clicked();
    void on_b_fan_clicked();
    void on_b_share_fan_clicked();
    void on_b_circlePump_clicked();
    void on_b_heatingBoiler_clicked();
    void on_b_KODI_clicked();
    void on_comboBox_ROOM_currentIndexChanged(int index);

    void on_b_light_ON_clicked();

    void on_b_light_OFF_clicked();

    void on_b_exit_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

public slots:
    void setLcdActual(int c);
    void setLcdAll(int c);
    void odb_answer(QString msg);
    void odb_toast_msg(QString s);
    void odb_light_msg(QString s);
    void readProgress(int c);
    void odb_answer_MPD(QString s);
    void odb_mpd_title (QString s);
    void odb_answer_alarm(QString s);
    void odbMpdVolume(QString s);
    void odb_share_link(QString s);
    void makeInfo(QString tit, QString msg);
    void updateMPDinfo();
    void updateAlarmTime();
    void updateTemepretureInfo();
    void updateState();
    void odb_temperature (QString s);
    void odb_tools (QString s);
    void listMPD(QString s);
    void textToSpeachSLOTS(QString s);
    void connectDisconnectButtonState(bool state);
    void setVolumeValueSlot(int i);
    void getPing(QString s);
    void odb_answer_state(QString s);
    void alarmHasBeenSet(Clock c);
    void screenChanged();
signals:
    void sendTCP(std::string addres, std::string s);
};

#endif // IDOM_CLIENT_H
