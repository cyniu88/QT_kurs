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

    /////////// okno dla www
    wwwShowWindow *wwwWindow = NULL;
    VolumeDialog vol;
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

    void on_exitButton_released();

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

    void on_spinBox_toLED_valueChanged(int value);

    void on_spinBox_fromLED_valueChanged(int value);

    void on_pushButton_10_released();

    void on_pushButton_11_released();

    void on_stopButton_released();

    void on_pushButtonPREV_released();

    void on_pushButtonNext_released();

    void on_pushButton_pause_released();

    void on_pushButton_volumeUP_released();

    void on_pushButton_volumeDOWN_released();

    void on_exitButton_pressed();

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

    void on_setNumberMPD_clicked();

    void on_comboBox_currentIndexChanged(QString txt);

    void on_turnOnSleepModeButton_clicked();

    void on_stopServerButton_clicked();

    void on_pushButton_extra_clicked();

    void on_pushButton_put_temperature_clicked();

    void on_pushButton_goodBye_clicked();

    void on_pushButton_ttsInfo_clicked();

    void on_tabRightButton_clicked();

    void on_tabLeftButton_clicked();

    void on_horizontalSlider_tabNavigate_valueChanged(int value);

    void on_pushButton_showTemperatureCharts_clicked();

    void loadImage(QByteArray d);

    void on_camera_button_reload_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_reloadCameraAddressButton_clicked();

    void on_oneShotCameraButton_clicked();

    void on_connectdicsonnectButton_clicked();

    void on_pushButton_volumeUP_pressed();

    void on_pushButton_volumeDOWN_pressed();

    void on_optionsButton_clicked();

    void on_smsButton_clicked();

    void on_On230vButton_clicked();

    void on_Off230vButton_clicked();

    void on_ledCameraButton_clicked();

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
signals:
    void sendTCP(std::string addres, std::string s);
};

#endif // IDOM_CLIENT_H
