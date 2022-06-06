#include <QColorDialog>
#include <QDateTime>
#include <QDebug>
//#include <QDesktopWidget>
#include <QDial>
#include <QPixmap>
#include <QSettings>
#include <QStackedWidget>
#include <QSysInfo>
#include <QScrollBar>
#include <QApplication>
#include <QClipboard>
#include <QScreen>

#include "json.hpp"

#ifdef Q_OS_ANDROID

#endif

#include "functions.h"
#include "idom_client.h"
#include "ui_idom_client.h"
#include "workerip.h"

iDom_Client::iDom_Client(iDom_CONFIG *config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iDom_Client),
    config(config),
    alarmWindow(config)
{
    ui->setupUi(this);

    taskHandlerTimer = new QTimer ();
    QObject::connect(taskHandlerTimer, SIGNAL(timeout()), this, SLOT(taskHandler()));
    taskHandlerTimer->start(900);
#ifndef Q_OS_ANDROID
    if(QSystemTrayIcon::isSystemTrayAvailable() == false)
    {
        QMessageBox::critical(this,":(","Ninja Mode is not available on this computer. Try again later :P");
    }
    else
    {
        trayIcon.setIcon(QIcon(":/new/prefix1/iDom_client.ico"));

        trayIconMenu.addAction(ui->actionStop_Server);
        trayIconMenu.addAction(ui->actionDisconnect);
        trayIconMenu.addAction(ui->actionCloseApp);

        trayIcon.setContextMenu(&trayIconMenu);
        trayIcon.show();
    }
#endif
    // dodajemy scrolla area  ajki widget  i czym scrolujemy
    QScroller::grabGesture(ui->txtAnswer,       QScroller::TouchGesture);
    QScroller::grabGesture(ui->scrollArea,      QScroller::TouchGesture);
    QScroller::grabGesture(ui->scrollArea_HOME, QScroller::TouchGesture);

    ui->txtAnswer->setAttribute(Qt::WA_AcceptTouchEvents);

    ////  //////////////////////////    Ladowanie grafiki  ////////////////////////
    /*  QPixmap pix;

    if (pix.load( ":/new/prefix1/files/background.png"   ))
    {

    }
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, pix);
    this->setPalette(palette);
*/
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int  height = rec.height();
    int  width  = rec.width();
    std::string s =  std::to_string(height) +" and " + std::to_string(width)  ;
    ui->txtAnswer->setLineWrapMode(QPlainTextEdit::NoWrap);
    ui->txtAnswer->setPlainText(QString::fromStdString( s));

    termoIN.setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Fixed);
    termoOUT.setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Fixed);
    termoFloor.setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Fixed);
    termoBoiler.setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Fixed);
    termoIN.setBackgroundColor(Qt::green);
    termoOUT.setBackgroundColor(Qt::green);
    termoFloor.setBackgroundColor(Qt::green);
    termoBoiler.setBackgroundColor(Qt::green);
    ui->werIN->addWidget(&termoIN);
    ui->werOUT->addWidget(&termoOUT);
    ui->werFloor->addWidget(&termoFloor);
    ui->werBoiler->addWidget(&termoBoiler);

    /// nawigate bar
    ///
    ui->lineEdit_tabName->setText(   ui->tabWidget->tabText(ui->tabWidget->currentIndex())  );
    ui->horizontalSlider_tabNavigate->setMaximum(ui->tabWidget->tabBar()->count()-1 );
    ui->horizontalSlider_tabNavigate->setValue(ui->tabWidget->currentIndex());
    ui->tabWidget->tabBar()->hide();

    ui->b_connect_dicsonnect->setText("Disconnect from iDom");

    ///////////////////////////// camera part ///////////////////////////////////////
    QSettings settings("cyniu", "iDom");
    cameraAddressHTTP = settings.value("cameraAddres").toString();
    m_pImgCtrl = new FileDownloader( QUrl(cameraAddressHTTP));
    QObject::connect( m_pImgCtrl, SIGNAL(downloaded(QByteArray)), this, SLOT(loadImage(QByteArray))   );

    //////////////////////////////  tts part ////////////////////////////////////////
#ifndef Q_OS_ANDROID
    ivona = new QTextToSpeech(this);

    QVector <QVoice> voi = ivona->availableVoices();
    if (!voi.isEmpty() ){
        // qDebug() << "vector ivona !!!!!!!!!!!!!!!@@@@@@@@@@@@@@@@@@2 ma " << voi.size();
        // ivona->setVoice( voi[1]);
        // qDebug()<<voi[0].name()<< voi.size();
        // QVector<QLocale> locales = ivona->availableLocales();
        // ivona->setLocale(locales[1]);
    }
    else{
        qDebug()<< "JEEEST PUSTY !!!!!!!!!!!!!!!!!!!!!!!!!!!!";
    }
#endif

    QObject::connect(&vol ,SIGNAL(setVolumeSingnal(int) ), this, SLOT(setVolumeValueSlot(int) ));

    QObject::connect(&alarmWindow, SIGNAL(alarmSetSignal(Clock)), this, SLOT(alarmHasBeenSet(Clock) ));
    QObject::connect(&alarmWindow, SIGNAL(messageInfo(QString, QString)),
                     this, SLOT(makeInfo(QString, QString)  ));

    QObject::connect(&optionsWindow, SIGNAL(s_sendCommandList(QStringList )) ,this,SLOT(slot_getCommandList(QStringList))   );
    QObject::connect(&optionsWindow, SIGNAL(s_fontSize(QString))             ,this,SLOT(slot_fontSize(QString))             );


    //////////////////////////////// config part ////////////////////////////////////

    QString commandString;
    for( auto i = 0; i < ui->comboBox->count(); i++ )
    {
        commandString += ui->comboBox->itemText( i );
        commandString += "\n";
    }
    std::string tempCommand;
    tempCommand = myConfigHandler.readFromFile("config","command.cfg",commandString.toStdString());
    ui->comboBox->clear();
    ui->comboBox->addItems(QString::fromStdString(tempCommand).split("\n"));
    setCommandListInOptions();

    systemInfo.currentCpuArchitecture = QSysInfo::currentCpuArchitecture();
    systemInfo.kernelType = QSysInfo::kernelType();
    systemInfo.machineHostName = QSysInfo::machineHostName();
    systemInfo.productVersion = QSysInfo::productVersion();
}

iDom_Client::~iDom_Client()
{
    taskHandlerTimer->stop();
    delete taskHandlerTimer;
    delete m_pImgCtrl;
    delete wwwWindow;
#ifndef Q_OS_ANDROID
    delete ivona;
#endif
    delete ui;
}

void iDom_Client::closeEvent(QCloseEvent *event)
{
    QSettings settings("cyniu", "iDom");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);
}

void iDom_Client::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    screenChanged();
}

void iDom_Client::readSettings()
{
    QSettings settings("cyniu", "iDom");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    config->encrypted=settings.value("encrypted").toBool();
}

void iDom_Client::setCommandListInOptions()
{
    QString commandString;
    for( auto i = 0; i < ui->comboBox->count(); i++ )
    {
        commandString += ui->comboBox->itemText( i );
        commandString += "*";
    }
    QStringList sList = commandString.split("*");
    optionsWindow.setCommandList(sList);
}

void iDom_Client::on_b_exit_released()
{
    ui->centralWidget->close();
}

void iDom_Client::taskHandler()
{
    ////////////////////////////// scroll song title //////////////////////////
    QString temp = ui->titleTXT->text();
    temp.push_back(temp[0]);
    temp.remove(0,1);
    ui->titleTXT->setText(temp);
    ///////////////////////////// check state ///////////////////////////////////

    switch(ui->tabWidget->currentIndex())
    {
    case 0:
        //case 4:
    case 6:
        updateAlarmTime();
        emit sendTCP("state", "state all");
        qDebug() << "aktualny case:"<<ui->tabWidget->currentIndex();
        break;

    default:
        break;
    }
}

void iDom_Client::odb_answer(QString msg)
{ 
    //TODO dodaj filtrowanie po kilku wyrazach
    QString s;
    auto tempList = msg.split('\n');

    if(config->grepWords.empty()){
        for(auto  &i : tempList){
            s.append(i);
            s.append('\n');
        }
    }
    else
    {
        for(auto  &i : tempList){
            for(auto &word : config->grepWords){
                if( i.contains(word)){
                    s.append(i);
                    s.append('\n');
                }
            }
        }
        config->grepWords.clear();
    }

    ui->txtAnswer->setPlainText(s);
    ui->txtAnswer->moveCursor(QTextCursor::End);
    ui->lcdNumberActual ->display(static_cast<int>(s.size()));
    //ui->lcdNumberActual->display(10);
    ui->progressBar->setValue(100);
    droid.vibrate(100);

    ui->txtAnswer->verticalScrollBar()->setValue(ui->txtAnswer->verticalScrollBar()->maximum());
}

void iDom_Client::odb_toast_msg(QString s)
{
    droid.makeToast(s);
#ifdef Q_OS_WIN
    trayIcon.showMessage("info",s);
#endif
}

void iDom_Client::odb_light_msg(QString s)
{
    //TODO
    nlohmann::json jj = nlohmann::json::parse(s.toStdString());

    for(const auto& data : jj){
        auto name = data.at("room").get<std::string>();
        //auto bulbPair = QString(,);
        QString bulbString;
        bulbString = QString::number(data.at("bulb ID").get<int>() ) + " "  + QString::fromStdString(data.at("bulb name").get<std::string>());
        lightConf[name].push_back(bulbString);
    }

    for (auto it = lightConf.begin(); it != lightConf.end(); ++it) {
        ui->comboBox_ROOM->addItem(QString::fromStdString(it.key()));
        qDebug() << QString::fromStdString(it.key()) << " I " << it.value() ;
    }
}

void iDom_Client::readProgress(int c)
{
    ui->progressBar->setValue(c);
}

void iDom_Client::odb_answer_LED(QString s)
{
    ui->lineEditLED->setText(s);
    makeInfo("LED",s);
}

void iDom_Client::odb_answer_MPD(QString s)
{
    ui->lineEdit_MPD_ACK->setText(s);
}

void iDom_Client::odb_mpd_title(QString s)
{
    ui->titleTXT->setText(s + "     ");
}

void iDom_Client::odb_answer_alarm(QString s)
{
    qDebug()<<"iDom_Client::odb_answer_alarm(QString s)";
    Clock c(s.toStdString());
    alarmWindow.setAlarmTimeString(c);
    alarmWindow.displayHour(static_cast<int>(c.m_h));
    alarmWindow.displayMinutes(static_cast<int>(c.m_min));
}

void iDom_Client::odbMpdVolume(QString s)
{
    ui->volumeTXT->setText("| volume: " +s+"%");
    ui->volumeBar->setValue(s.toInt());
}

void iDom_Client::odb_share_link(QString s)
{
    QClipboard* clip = QApplication::clipboard();
    clip->setText(s);
    droid.share(s);
}

void iDom_Client::makeInfo(QString tit, QString msg)
{
    droid.vibrate(300);
    droid.makeToast(msg);
#ifdef Q_OS_WIN
    trayIcon.showMessage(tit, msg);
#endif
}

void iDom_Client::updateMPDinfo()
{
    emit sendTCP("MPD_title","MPD get info");
    emit sendTCP("MPD_volume","MPD get volume");
}

void iDom_Client::updateAlarmTime()
{
    emit sendTCP("alarm","iDom alarm GET");
}

void iDom_Client::updateTemepretureInfo()
{
    updateAlarmTime();
    emit sendTCP("temperature","iDom temperature");
    emit sendTCP("listMPD", "MPD list");
    emit sendTCP("light", "light info");
}

void iDom_Client::updateState()
{
    emit sendTCP("state", "state all");
}

void iDom_Client::odb_temperature(QString s)
{
    auto data = s.split(":");
    if(data.size() < 4){
        QString msg("problem z pobraniem temperatury");
        msg.append(" pobrano parametrow:  ");
        msg.append(QString::number(data.size()));
        ui->temperatureTXT->setText(msg);
        return;
    }
    QString in = data.at(0);
    QString out = data.at(1);
    QString boiler = data.at(2);
    QString floor = data.at(3);

    out = out.split("\r")[0];
    temperatureString = "Temperature Inside: " + in +"\u2103"+ " Outside: "+ out+ "\u2103"+ " ";
    ui->temperatureTXT->setText(temperatureString);
    ui->InsideLCD_2->display(in);
    ui->OutsideLCD_2->display(out);
    ui->boilerLCD->display(boiler);
    ui->floorLCD->display(floor);
    termoIN.setTemperature(in.toDouble());
    termoOUT.setTemperature(out.toDouble());
    termoFloor.setTemperature(floor.toDouble());
    termoBoiler.setTemperature(boiler.toDouble());
}

void iDom_Client::odb_tools(QString s)
{
    QMessageBox::information(this,"from tools",s);
}

void iDom_Client::listMPD(QString s){
    mpdItems = s.split("\n");
}

void iDom_Client::textToSpeachSLOTS(QString s)
{
    qDebug() << "from TTS: "<< s;
#ifndef Q_OS_ANDROID
    ivona->say(s);
#endif
}

void iDom_Client::connectDisconnectButtonState(bool state)
{
    if (state == false){
        ui->b_connect_dicsonnect->setText("Connect to iDom");
        ui->titleTXT->setText("DISCONNECTED   ");
    }
    else{
        ui->b_connect_dicsonnect->setText("Disconnect from iDom");
        emit sendTCP("console","log INFO - client: "+systemInfo.getSystemInfo().toStdString() );
    }
}

void iDom_Client::on_b_sendConsole_released()
{

     config->command.clear();

    bool mainCommand = true;
    //  config->command = ui->comboBox->currentText().toStdString();

    QList<QString> commandList = ui->comboBox->currentText().split(" ");

    for(auto &word : commandList){

        qDebug() << "command list  |grep" <<word ;
        if(word.contains("|grep") ){
            mainCommand = false;
            qDebug() << "CYNIU jest |grep" ;
        }
        else if(mainCommand == false){
            config->grepWords.push_back(word);
            qDebug() << "CYNIU wstawiam do listy |grep" << word ;
        }
        else{
            config->command.append(word.toStdString());
            config->command.append(" ");
        }
    }

    if (config->command.size() != 0)
        emit sendTCP("console",config->command);
    else {
        ui->txtAnswer->verticalScrollBar()->setValue(ui->txtAnswer->verticalScrollBar()->maximum());
    }
}

void iDom_Client::sendSignalColor(int r,int g, int b, int from, int to)
{
    emit sendTCP("LED",
                 "iDom LED "+std::to_string(from)+" "+std::to_string(to)+" "+std::to_string(r)+" "+std::to_string(g)+" "+std::to_string(b)
                 );
}

void iDom_Client::setVolumeDial()
{
    vol.setVolume(ui->volumeBar->value());

#ifdef Q_OS_ANDROID
    vol.showMaximized();
#else
    vol.exec();
#endif
}

void iDom_Client::slot_fontSize(QString s)
{
    qDebug()<< "font size: "<<s;
    ui->txtAnswer->setFont(QFont ("Arial",s.toInt()));
}

void iDom_Client::slot_getCommandList(QStringList list)
{
    ui->comboBox->clear();
    ui->comboBox->addItems(list);
}

void iDom_Client::on_b_led_14_released()
{
    sendSignalColor(70, 0, 130,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_15_released()
{
    sendSignalColor(255, 192, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_16_released()
{
    sendSignalColor(147, 246, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_17_released()
{
    sendSignalColor(178, 34, 34,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_18_released()
{
    sendSignalColor(128, 0, 128,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_19_released()
{
    sendSignalColor(8, 37, 103,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_20_released()
{
    sendSignalColor(255, 255, 153,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_25_released()
{
    sendSignalColor(207, 47, 47,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_24_released()
{
    sendSignalColor(128, 128, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_23_released()
{
    sendSignalColor(159, 159, 223,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_22_released()
{
    sendSignalColor(112, 32, 31,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_21_released()
{
    sendSignalColor(98, 0, 44,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_12_released()
{
    sendSignalColor(255, 165, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_13_released()
{
    sendSignalColor(128, 0, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_6_released()
{
    sendSignalColor(255,255,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_7_released()
{
    sendSignalColor(255,128,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_8_released()
{
    sendSignalColor(0,128,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_9_released()
{
    sendSignalColor(0,255,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_10_released()
{
    sendSignalColor(204, 93, 43,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_11_released()
{
    sendSignalColor(0, 127, 255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_LED_OFF_released()
{
    emit sendTCP("LED","iDom LED OFF");
    ui->b_extra_color->setStyleSheet(" border-style: outset;border-width: 1px;\
                                     border-color: rgb(255, 255, 255);\
            /* border-radius: 10px;*/\
            border-color: beige;\
    \
padding: 6px;\
    background-color: rgb(0, 0, 0);"  );
}

void iDom_Client::on_b_led_1_released()
{
    sendSignalColor(255,0,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_2_released()
{
    sendSignalColor(0,0,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_3_released()
{
    sendSignalColor(0,255,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_4_released()
{
    sendSignalColor(255,255,51,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_led_5_released()
{
    sendSignalColor(255,0,128,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_b_play_released()
{
    if (ui->b_lockUnlock_HOME->isChecked() == true)
    {
        QMessageBox::critical(this,tr("INFO"),tr("can not play due to house lock!"));
        return;
    }
    emit sendTCP("MPD","MPD start");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_b_all_led_released()
{
    ui->spinBox_fromLED->setValue(0);
    ui->spinBox_toLED->setValue(60);
    ui->from_horizontalSlider->setValue(0);
    ui->to_horizontalSlider_2->setValue(60);
    ui->lcdNumber_fromLED->display(0);
    ui->lcdNumber_toLED->display(60);
}

void iDom_Client::on_to_horizontalSlider_2_valueChanged( )
{   int temp_value = ui->to_horizontalSlider_2->value();

    if (temp_value <= ui->from_horizontalSlider->value())
    {
        ui->from_horizontalSlider->setValue(temp_value-1);
        ui->spinBox_fromLED->setValue(temp_value-1);
    }
    ui->spinBox_toLED->setValue(ui->to_horizontalSlider_2->value());
    ui->lcdNumber_toLED->display(ui->to_horizontalSlider_2->value());
}

void iDom_Client::on_from_horizontalSlider_valueChanged(int value )
{
    int temp_value = ui->from_horizontalSlider->value();
    if (temp_value >= ui->to_horizontalSlider_2->value())
    {
        ui->to_horizontalSlider_2->setValue(temp_value+1);
        ui->spinBox_toLED->setValue(temp_value+1);
    }
    ui->spinBox_fromLED->setValue(value);
    ui->lcdNumber_fromLED->display(ui->from_horizontalSlider->value());
}

void iDom_Client::on_spinBox_toLED_valueChanged(int value)
{
    ui->to_horizontalSlider_2->setValue(value);
    ui->lcdNumber_toLED->display(value);
}

void iDom_Client::on_spinBox_fromLED_valueChanged(int value)
{
    ui->from_horizontalSlider->setValue(value);
    ui->lcdNumber_fromLED->display(value);
}

void iDom_Client::on_b_stop_released()
{
    emit sendTCP("MPD","MPD stop");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_b_PREV_released()
{
    emit sendTCP("MPD","MPD prev");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_b_Next_released()
{
    emit sendTCP("MPD","MPD next");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_b_pause_released()
{
    emit sendTCP("MPD","MPD pause");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_b_volumeUP_released()
{
    if ( pressTime.elapsed() < 220){
        emit sendTCP("MPD","MPD volume up");
        ui->volumeBar->setValue(ui->volumeBar->value()+1);
        emit sendTCP("MPD_volume","MPD get volume");
        droid.vibrate(100);
    }
    else{
        setVolumeDial();
    }
}

void iDom_Client::on_b_volumeDOWN_released()
{
    if ( pressTime.elapsed() < 220){
        emit sendTCP("MPD","MPD volume down");
        ui->volumeBar->setValue(ui->volumeBar->value()-1);
        emit sendTCP("MPD_volume","MPD get volume");
        droid.vibrate(100);
    }
    else{
        setVolumeDial();
    }
}

void iDom_Client::on_b_exit_pressed()
{
    emit sendTCP("console","exit");
}

void iDom_Client::setLcdActual(int c)
{
    ui->lcdNumberActual->display(c);
}

void iDom_Client::setLcdAll(int c)
{
    ui->lcdNumberAll->display(c);
}

void iDom_Client::on_tabWidget_currentChanged( )
{
    emit sendTCP("state", "state all");
    ui->lineEdit_tabName->setText(   ui->tabWidget->tabText(ui->tabWidget->currentIndex())  );
    ui->horizontalSlider_tabNavigate->setValue(ui->tabWidget->currentIndex());


    switch (ui->tabWidget->currentIndex()){
    case 6:
        screenChanged();
        break;
    default:
        break;
    }
}

void iDom_Client::on_b_setNumberMPD_clicked()
{
    bool ok;
    QInputDialog myInputDialog;
    QString id = myInputDialog.getItem(this, tr("select radio stations"),
                                       tr("select radio stations"),mpdItems,7,false, &ok);

    if (ok && !id.isEmpty()){
        int songID = 0;
        songID = 1+ mpdItems.indexOf(id);
        ui->b_setNumberMPD->setText(QString::number( songID ));
        ui->lineEdit_MPD_ACK->setText("play "+id);
        emit sendTCP("MPD","MPD start "+std::to_string(songID));
    }
    droid.vibrate(100);
}

void iDom_Client::on_b_turnOnSleepMode_clicked()
{
    bool ok;
    int i;
    i = QInputDialog::getInt(this,tr("set sleep mode"),tr("minutes"),1,1,1000,1,&ok);
    if (ok){
        emit sendTCP("tools","sleep set "+std::to_string(i));
    }
}

void iDom_Client::on_b_server_clicked()
{
    //    QMessageBox::StandardButton reply;
    //    reply = QMessageBox::question(this, "", "server?",
    //                                  QMessageBox::Close|QMessageBox::Cancel);
    //    if (reply == QMessageBox::Close) {
    //        qDebug() << "Yes was clicked";
    //        emit sendTCP("tools","stop server");
    //        QThread::sleep(1);
    //        on_b_connect_dicsonnect_clicked();
    //    }
    QMessageBox msgBox;
    QPushButton *closeButton = msgBox.addButton(tr("Stop server"), QMessageBox::ActionRole);
    QPushButton *softReloadButton = msgBox.addButton(tr("soft reload"), QMessageBox::ActionRole);
    QPushButton *hardReloadButton = msgBox.addButton(tr("hard reload"), QMessageBox::ActionRole);
    QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
    msgBox.exec();

    if (msgBox.clickedButton() == softReloadButton) {
        qDebug() << "softReloadButton was clicked";
        emit sendTCP("tools","program reload soft");
        QThread::sleep(1);
        on_b_connect_dicsonnect_clicked();
    }
    else if (msgBox.clickedButton() == hardReloadButton) {
        qDebug() << "hardReloadButton was clicked";
        emit sendTCP("tools","program reload hard");
        QThread::sleep(1);
        on_b_connect_dicsonnect_clicked();

    }
    else if (msgBox.clickedButton() == closeButton) {
        emit sendTCP("tools","program stop");
        QThread::sleep(1);
        on_b_connect_dicsonnect_clicked();
    }
}

void iDom_Client::on_b_extra_color_clicked()
{
    QColorDialog color;
    color.setOptions(QColorDialog::ShowAlphaChannel);
    QFont f;
    int size = QGuiApplication::primaryScreen()->geometry().width();
    if (size>1000){
        size = 25;
        qDebug() << "duze";
    }
    else {
        size = 8;
        qDebug() << "male!";
    }
    f.setPixelSize(size);
    color.setFont(f);
    if( color.exec())
    {
        int r,g,b;
        color.currentColor().getRgb(&r,&g,&b);

        sendSignalColor(r,g,b,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
        ui->b_extra_color->setStyleSheet(" border-style: outset; color: rgb(255, 55, 55); background-color: rgb("+QString::number(r)+","+QString::number(g)+"," +QString::number(b)+");  border-width: 1px;   border-color: rgb(255, 255, 255);  border-color: beige;  padding: 6px;"  );
    }
    else{
        ui->b_extra_color->setStyleSheet(" border-style: outset; color: rgb(255, 55, 55); background-color: rgb(0,0,0);  border-width: 1px;   border-color: rgb(255, 255, 255);  border-color: beige;  padding: 6px;"  );
    }
}

void iDom_Client::on_b_put_temperature_clicked()
{
    emit sendTCP("tools","put temperature");
}

void iDom_Client::on_b_goodBye_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "", "stop music and LED?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit sendTCP("MPD","MPD stop");
        emit sendTCP("LED","iDom LED OFF");
        on_b_exit_pressed();
        QThread::sleep(2);
        qApp->exit();
    }
}

void iDom_Client::on_b_ttsInfo_clicked()
{
    emit sendTCP("TTS","iDom text");
}

void iDom_Client::on_b_tabRight_clicked()
{
    int i = ui->horizontalSlider_tabNavigate->value();  //get current value
    ++i;
    if (i > ui->tabWidget->tabBar()->count()-1){
        i=0;
    }
    ui->horizontalSlider_tabNavigate->setValue(i);
}

void iDom_Client::on_b_tabLeft_clicked()
{
    int i = ui->horizontalSlider_tabNavigate->value();  //get current value
    --i;
    if (i < 0){
        i=ui->tabWidget->tabBar()->count()-1;
    }
    ui->horizontalSlider_tabNavigate->setValue(i);
}

void iDom_Client::on_horizontalSlider_tabNavigate_valueChanged(int value)
{
    ui->tabWidget->setCurrentIndex(value);
}

void iDom_Client::on_b_showTemperatureCharts_clicked()
{
    if (wwwWindow != nullptr ){
        qDebug() << "kasuje bo nie jest null";
        delete wwwWindow;
    }
    wwwWindow = new wwwShowWindow();
    wwwWindow->show();
}

void iDom_Client::loadImage(QByteArray d)
{
    pima.loadFromData(d);
    ui->cameraLabel->setPixmap(pima.scaled(ui->cameraLabel->width(),ui->cameraLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
    ui->snap_counter->display(ui->snap_counter->value()+1);
    if (cameraWork == true)
    {
        m_pImgCtrl->getSnap();
    }
    else
    {
        droid.vibrate(100);
    }
}

void iDom_Client::on_b_camera_reload_clicked()
{
    cameraWork = !cameraWork;
    if (cameraWork){
        ui->b_camera_reload->setText("Stop");
        makeInfo("CAMERA","Video Start");
    }
    else{
        ui->b_camera_reload->setText("Start");
        makeInfo("CAMERA","Video Stop");
        ui->snap_counter->display(0);
    }
    m_pImgCtrl->getSnap();
    droid.keepScreenOn(cameraWork);
}

void iDom_Client::on_tabWidget_currentChanged(int index)
{
    if (index != 0){
        cameraWork = false;
        ui->snap_counter->display(0);
    }
}

void iDom_Client::on_b_reloadCameraAddress_clicked()
{
    bool ok;
    QInputDialog myInputDialog;
    QString id = myInputDialog.getText(this, tr("set new camera address"),tr("address:"),QLineEdit::Normal, cameraAddressHTTP , &ok);

    if (ok && !id.isEmpty()){
        m_pImgCtrl->setAddress(id);
        cameraAddressHTTP = id;
        QSettings settings("cyniu", "iDom");
        settings.setValue("cameraAddres", cameraAddressHTTP);
    }
    droid.vibrate(100);
}

void iDom_Client::on_b_oneShotCamera_clicked()
{
    m_pImgCtrl->getSnap();
    makeInfo("Camera","shot taken");
    droid.vibrate(100);
}

void iDom_Client::on_b_connect_dicsonnect_clicked()
{
    if (config->isConnectedToServer == true){
        config->goWhile =false;
        ui->b_connect_dicsonnect->setText("Connect to iDom");
        ui->titleTXT->setText("DISCONNECTED   ");
    }
    else{
        config->worketPTR->start();
        ui->b_connect_dicsonnect->setText("Disconnect from iDom");
    }
}

void iDom_Client::on_b_volumeUP_pressed()
{
    pressTime.start();
}

void iDom_Client::on_b_volumeDOWN_pressed()
{
    pressTime.start();
}

void iDom_Client::setVolumeValueSlot(int i)
{
    qDebug("setVolumeValueSlot()!!!");
    droid.vibrate(100);
    emit sendTCP("MPD","MPD volume "+ std::to_string(i));
    emit sendTCP("MPD_volume","MPD get volume");
}

void iDom_Client::getPing(QString s)
{
    ui->ping->setText(s);
    ui->messagesToSend_number->setText(
                QString::number(config->workerQueue.Size())
                );
}

void iDom_Client::odb_answer_state(QString s)
{
    QStringList sl = s.split(" ");

    for (const auto& s : sl){
        if (s == "cameraLED=OFF" && ui->b_ledCamera->isChecked() == true){
            ui->b_ledCamera->setChecked(false);
        }
        if (s == "cameraLED=ON" && ui->b_ledCamera->isChecked() == false){
            ui->b_ledCamera->setChecked(true);
        }
        ///////////////////////////////////////////////////////////////////
        if (s == "taras_gniazdko=OFF" && ui->b_printer->isChecked() == true){
            ui->b_printer->setChecked(false);
            droid.makeToast("gniazdko na tarasie wyłączone");
        }
        if (s == "taras_gniazdko=ON" && ui->b_printer->isChecked() == false){
            ui->b_printer->setChecked(true);
            droid.makeToast("gniazdko na tarasie włączone");
        }
        ///////////////////////////////////////////////////////////////
        if (s == "fan=OFF" && ui->b_fan->isChecked() == true){
            ui->b_fan->setChecked(false);
            droid.makeToast("wnetylator wyłączony");
        }
        if (s == "fan=ON" && ui->b_fan->isChecked() == false){
            ui->b_fan->setChecked(true);
            droid.makeToast("wentylator uruchomiony");
        }
        ///////////////////////////////////////////////////////////////
        if (s == "listwa=OFF" && ui->b_listwa->isChecked() == true){
            ui->b_listwa->setChecked(false);
            droid.makeToast("listwa wyłączona");
        }
        if (s == "listwa=ON" && ui->b_listwa->isChecked() == false){
            ui->b_listwa->setChecked(true);
            droid.makeToast("listwa uruchomiona");
        }
        ///////////////////////////////////////////////////////////////////
        if (s == "alarm=DEACTIVE" && ui->b_setAlarm->isChecked() == true){
            ui->b_setAlarm->setChecked(false);
            ui->b_setAlarm->setText("SET ALARM CLOCK");
        }
        if (s == "alarm=ACTIVE" && ui->b_setAlarm->isChecked() == false){
            ui->b_setAlarm->setChecked(true);
            ui->b_setAlarm->setText(alarmWindow.getAlarmTimeQString()+ " END ALARM CLOCK");
        }
        ///////////////////////////////////////////////////////////////////
        if (s == "house=UNLOCK" && ui->b_lockUnlock_HOME->isChecked() == true){
            ui->b_lockUnlock_HOME->setChecked(false);
            qDebug() << "UNLOCK HOUSE";
            config->houseLocked = false;
            droid.makeToast("dom odblokowany");
        }
        if (s == "house=UNDEFINE"){
            ui->b_lockUnlock_HOME->setChecked(true);
            droid.makeToast("stan domu niezdefiniowany");
        }
        if (s == "house=LOCK" && ui->b_lockUnlock_HOME->isChecked() == false){
            ui->b_lockUnlock_HOME->setChecked(true);
            qDebug() << "LOCK HOUSE";
            config->houseLocked = true;
            droid.makeToast("dom zablokowany");
        }
        if (s == "burnGas=ACTIVE"){
            QPixmap pix(":/new/prefix1/files/svg/heating-service.svg");
            ui->l_burnGas->setPixmap(pix);
            //setStyleSheet("background-image: url(:/new/prefix1/files/svg/heating-service.svg); background-repeat: no-repeat; background-size: cover;");
        }
        if (s == "burnGas=DEACTIVE"){
            ui->l_burnGas->clear();
        }
        ///////////////////////////////////////////////////////////////////
    }
}

void iDom_Client::alarmHasBeenSet(Clock c)
{
    ui->b_setAlarm->setText(alarmWindow.getAlarmTimeQString()+ " END ALARM CLOCK");
    QString msg = "iDom alarm ON "+QString::number(c.m_h)+":"+ QString::number(c.m_min);
    emit sendTCP("console", msg.toStdString());
}

void iDom_Client::on_b_options_clicked()
{
    optionsWindow.setConfigFile(config);
    optionsWindow.show();
}

void iDom_Client::on_b_sms_clicked()
{
    droid.sendSMS("506496722","test sms ");
    droid.makeToast("wyslano sms:");

    droid.updateAndroidNotification("test testo");
}

void iDom_Client::on_b_ledCamera_clicked()
{
    taskHandlerTimer->start();
    if (ui->b_ledCamera->isChecked() == true)
    {
        emit sendTCP("console","iDom camera LED ON");
        droid.makeToast("zapala leda kamery");
    }
    if (ui->b_ledCamera->isChecked() == false)
    {
        emit sendTCP("console","iDom camera LED OFF");
        droid.makeToast("gasze leda kamery");
    }
    droid.vibrate(200);
}


void iDom_Client::on_b_printer_clicked()
{
    taskHandlerTimer->start();
    if (ui->b_printer->isChecked() == true)
    {
        emit sendTCP("console","light bulb on 99"); //99 id gniazdka na tarasie
    }
    if (ui->b_printer->isChecked() == false)
    {
        emit sendTCP("console","light bulb off 99");
    }
    droid.vibrate(200);
}

void iDom_Client::on_b_setAlarm_clicked()
{
    droid.vibrate(200);
    emit sendTCP("alarm","iDom alarm GET");
    if(ui->b_setAlarm->isChecked() == false){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "", "end alarm?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {

            ui->b_setAlarm->setText("SET ALARM CLOCK");
            makeInfo("ALARM", "alarm został anulowany");
            emit sendTCP("console","iDom alarm OFF");
        }
        else{
            ui->b_setAlarm->setChecked(true);
        }
    }
    else{
#ifdef Q_OS_ANDROID
        alarmWindow.showMaximized();
#else
        alarmWindow.exec();
#endif
        //ui->b_setAlarm->setChecked(true);
    }

}

void iDom_Client::on_b_listwa_clicked()
{
    taskHandlerTimer->start();
    if (ui->b_listwa->isChecked() == true)
    {
        emit sendTCP("console","433MHz switch listwa ON");
    }
    if (ui->b_listwa->isChecked() == false)
    {
        emit sendTCP("console","433MHz switch listwa OFF");
    }
    droid.vibrate(200);
}

void iDom_Client::on_b_lockUnlock_HOME_clicked()
{
    taskHandlerTimer->start();
    if (ui->b_lockUnlock_HOME->isChecked() == false)
    {
        emit sendTCP("console","iDom unlock");
        qDebug() << "UNLOCK HOUSE";
        config->houseLocked = false;
    }
    if (ui->b_lockUnlock_HOME->isChecked() == true)
    {
        emit sendTCP("console","iDom lock");
        qDebug() << "LOCK HOUSE";
        config->houseLocked = true;
    }
    droid.vibrate(200);
}

void iDom_Client::on_b_fan_clicked()
{
    taskHandlerTimer->start();
    if (ui->b_fan->isChecked() == false)
    {
        emit sendTCP("console","433MHz switch fan OFF");
        qDebug() << "start wentylatora";
    }
    if (ui->b_fan->isChecked() == true)
    {
        emit sendTCP("console","433MHz switch fan ON");
        qDebug() << "stop wentylatora";
    }
    droid.vibrate(200);
}

void iDom_Client::on_b_share_fan_clicked()
{
    emit sendTCP("share","iDom link gateway fan");
    droid.vibrate(200);
}


void iDom_Client::on_b_circlePump_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "", "uruchomić pompę C.W.U?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit sendTCP("toast","buderus circPomp");
    }
}

void iDom_Client::on_b_heatingBoiler_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "", "zagrzać wodę w kranie?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit sendTCP("toast","buderus boiler heating");
    }
}

void iDom_Client::on_b_KODI_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "", "uruchomić KODI?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit sendTCP("toast","iDom KODI");
    }
}

void iDom_Client::screenChanged()
{
    ui->b_printer->setIconSize((ui->b_printer->size()*0.6));
    ui->b_listwa->setIconSize(ui->b_listwa->size()*0.6);
    ui->b_lockUnlock_HOME->setIconSize(ui->b_lockUnlock_HOME->size()*0.6);
    ui->b_fan->setIconSize(ui->b_fan->size()*0.6);
    ui->b_heatingBoiler->setIconSize(ui->b_heatingBoiler->size()*0.6);
    ui->b_circlePump->setIconSize(ui->b_circlePump->size()*0.6);
    ui->b_KODI->setIconSize(ui->b_KODI->size()*06);
}

void iDom_Client::on_comboBox_ROOM_currentIndexChanged(int index)
{
    ui->comboBox_BULB->clear();
    ui->comboBox_BULB->addItem("all");
    for(const auto& v : lightConf[ui->comboBox_ROOM->currentText().toStdString()]){
        ui->comboBox_BULB->addItem(v);
    }
}

void iDom_Client::on_b_light_ON_clicked()
{
    if(ui->comboBox_ROOM->currentText() == "all"){
        qDebug() << "zapalam wszystko";
        emit sendTCP("toast","light all on");
    }
    else{
        if(ui->comboBox_BULB->currentText() == "all"){
            std::stringstream msg;
            msg << "light room ";
            msg << ui->comboBox_ROOM->currentText().toStdString();
            msg << " on";
            emit sendTCP("toast", msg.str());
            qDebug() << "wiadomsoc " << QString::fromStdString(msg.str());
        }
        else{
            std::stringstream msg;
            msg << "light bulb on ";
            msg << ui->comboBox_BULB->currentText().mid(0,3).toInt();
            emit sendTCP("toast", msg.str());
            qDebug() << "wiadomsoc " << QString::fromStdString(msg.str());
        }
    }
}

void iDom_Client::on_b_light_OFF_clicked()
{
    if(ui->comboBox_ROOM->currentText() == "all"){
        qDebug() << "gasze wszystko";
        emit sendTCP("toast","light all off");
    }
    else{
        if(ui->comboBox_BULB->currentText() == "all"){
            std::stringstream msg;
            msg << "light room ";
            msg << ui->comboBox_ROOM->currentText().toStdString();
            msg << " off";
            emit sendTCP("toast", msg.str());
            qDebug() << "wiadomsoc " << QString::fromStdString(msg.str());
        }
        else{
            std::stringstream msg;
            msg << "light bulb off ";
            msg << ui->comboBox_BULB->currentText().mid(0,3).toInt();
            emit sendTCP("toast", msg.str());
            qDebug() << "wiadomsoc " << QString::fromStdString(msg.str());
        }
    }
}

void iDom_Client::on_comboBox_currentIndexChanged(int index)
{
    //config->command = txt.toStdString();
    //emit sendTCP("console",config->command);
    on_b_sendConsole_released();
}

