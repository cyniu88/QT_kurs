#include <QPixmap>
#include <QStackedWidget>
#include <QDebug>
#include <QDial>
#include <QDesktopWidget>
#include <QColorDialog>
#include <QDateTime>

#ifdef Q_OS_ANDROID

#endif

#include "idom_client.h"
#include "ui_idom_client.h"
#include "workerip.h"
#include "functions.h"

namespace std {
template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}
}

iDom_Client::iDom_Client(iDom_CONFIG *config, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::iDom_Client),
    config(config)
{
    ui->setupUi(this);

#ifdef Q_OS_WIN
    if(QSystemTrayIcon::isSystemTrayAvailable() == false)
    {
        QMessageBox::critical(this,":(","Ninja Mode is not available on this computer. Try again later :P");
    }
    else
    {
        trayIcon.setIcon(QIcon(":/new/prefix1/iDom_client.ico"));
        trayIcon.show();
    }
#endif
    // dodajemy scrolla area  ajki widget  i czym scrolujemy
    QScroller::grabGesture(ui->txtAnswer,QScroller::TouchGesture);
    QScroller::grabGesture(ui->scrollArea,QScroller::TouchGesture);

    ui->txtAnswer->setAttribute(Qt::WA_AcceptTouchEvents);

    ////  //////////////////////////    Ladowanie grafiki  ////////////////////////
    QPixmap pix;

    if (pix.load( ":/new/prefix1/files/background.png"   ))
    {

    }
    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);

    QRect rec = QApplication::desktop()->screenGeometry();
    int  height = rec.height();
    int  width  = rec.width();
    std::string s =  std::to_string(height) +" and " + std::to_string(width)  ;
    ui->txtAnswer->setText( QString::fromStdString( s));

    termoIN.setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Fixed);
    termoOUT.setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Fixed);
    termoIN.setBackgroundColor(Qt::green);
    termoOUT.setBackgroundColor(Qt::green);
    ui->werIN->addWidget(&termoIN);
    ui->werOUT->addWidget(&termoOUT);

    /// nawigate bar
    ///
    ui->lineEdit_tabName->setText(   ui->tabWidget->tabText(ui->tabWidget->currentIndex())  );
    ui->horizontalSlider_tabNavigate->setMaximum(ui->tabWidget->tabBar()->count()-1 );
    ui->horizontalSlider_tabNavigate->setValue(ui->tabWidget->currentIndex());
    ui->tabWidget->tabBar()->hide();

    ui->connectdicsonnectButton->setText("Disconnect from iDom");
    ///////////////////////////// camera part
    m_pImgCtrl = new FileDownloader( QUrl(cameraAddressHTTP));
    QObject::connect( m_pImgCtrl, SIGNAL(downloaded(QByteArray)), this, SLOT(loadImage(QByteArray))   );
    ivona = new QTextToSpeech(this);


//        QVector <QVoice> voi = ivona->availableVoices();
//        ivona->setVoice( voi[1]);
//        qDebug()<<voi[0].name()<< voi.size();
//        QVector<QLocale> locales = ivona->availableLocales();
//        ivona->setLocale(locales[1]);
    QObject::connect( &vol   ,SIGNAL(setVolumeSingnal(int) ) ,this,SLOT ( setVolumeValueSlot(int ) ));
    QObject::connect(&optionsWindow, SIGNAL(s_sendCommandList(QStringList )) ,this,SLOT(slot_getCommandList(QStringList))   );

    //////////////////////////////// config

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
}

iDom_Client::~iDom_Client()
{
    //ivona->say("dowidzenia");
    delete m_pImgCtrl;
    delete wwwWindow;
    delete ivona;
    delete ui;
}

void iDom_Client::setCommandListInOptions()
{
    QString commandString;
    for( auto i = 0; i < ui->comboBox->count(); i++ )
    {
        commandString += ui->comboBox->itemText( i );
        commandString += "*";
    }
    optionsWindow.setCommandList(commandString.split("*"));
}

void iDom_Client::on_exitButton_released()
{
    ui->centralWidget->close();
}

void iDom_Client::scrollTitle()
{
    QString temp = ui->titleTXT->text();
    temp.push_back(temp[0]);
    temp.remove(0,1);
    ui->titleTXT->setText(temp);
}

void iDom_Client::odb_answer(QString s)
{
    ui->txtAnswer->setText(s);
    ui->txtAnswer->moveCursor(QTextCursor::End);
    ui->lcdNumberActual ->display(s.size());
    ui->progressBar->setValue(100);
    droid.vibrate(100);
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
    ui->titleTXT->setText(s+"     ");
}

void iDom_Client::odbMpdVolume(QString s)
{
    ui->volumeTXT->setText("| volume: " +s+"%");
    ui->volumeBar->setValue(s.toInt());
}

void iDom_Client::makeInfo(QString tit, QString msg)
{
    droid.vibrate(300);
    droid.makeToast(msg);
#ifdef Q_OS_WIN
    trayIcon.showMessage(tit,msg);
#endif
}

void iDom_Client::updateMPDinfo()
{
    emit sendTCP("MPD_title","MPD get info");
    emit sendTCP("MPD_volume","MPD get volume");
    qDebug("timer mpd info ");
}

void iDom_Client::updateTemepretureInfo()
{
    emit sendTCP("temperature","iDom temperature");
    emit sendTCP("listMPD", "MPD list");
}

void iDom_Client::odb_temperature(QString s)
{
    QString in = s.split(":")[0];
    QString out =s.split(":")[1];
    out = out.split("\r")[0];
    temperatureString = "Temperature Inside: " + in +"\u2103"+ " Outside: "+ out+ "\u2103"+ " ";
    ui->temperatureTXT->setText(temperatureString);
    ui->InsideLCD_2->display( in   );
    ui->OutsideLCD_2->display( out);
    termoIN.setTemperature(in.toDouble());
    termoOUT.setTemperature(out.toDouble());
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
    ivona->say(s);
}

void iDom_Client::connectDisconnectButtonState(bool state)
{
    if (state == false){
        ui->connectdicsonnectButton->setText("Connect to iDom");
    }
    else{
        ui->connectdicsonnectButton->setText("Disconnect from iDom");
    }
}

void iDom_Client::on_pushButton_released()
{
    config->command = ui->comboBox->currentText().toStdString();
    emit sendTCP("console",config->command);
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
#endif

#ifdef Q_OS_WIN
    vol.exec();
#endif
}

void iDom_Client::slot_getCommandList(QStringList list)
{
    ui->comboBox->clear();
    ui->comboBox->addItems(list);
}

void iDom_Client::on_pushButton_12_released()
{
    sendSignalColor(70, 0, 130,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_13_released()
{
    sendSignalColor(255, 192, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_25_released()
{
    sendSignalColor(147, 246, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_18_released()
{
    sendSignalColor(178, 34, 34,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_19_released()
{
    sendSignalColor(128, 0, 128,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_20_released()
{
    sendSignalColor(8, 37, 103,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_21_released()
{
    sendSignalColor(255, 255, 153,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_17_released()
{
    sendSignalColor(207, 47, 47,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_16_released()
{
    sendSignalColor(128, 128, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_15_released()
{
    sendSignalColor(159, 159, 223,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_14_released()
{
    sendSignalColor(112, 32, 31,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_26_released()
{
    sendSignalColor(98, 0, 44,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_10_released()
{
    sendSignalColor(255, 165, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_11_released()
{
    sendSignalColor(128, 0, 0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_23_released()
{
    sendSignalColor(255,255,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_6_released()
{
    sendSignalColor(255,128,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_7_released()
{
    sendSignalColor(0,128,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_8_released()
{
    sendSignalColor(0,255,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_9_released()
{
    sendSignalColor(204, 93, 43,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_24_released()
{
    sendSignalColor(0, 127, 255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_LED_OFF_Button_37_released()
{
    emit sendTCP("LED","iDom LED OFF");
    ui->pushButton_extra->setStyleSheet(" border-style: outset; color: rgb(255, 255, 255); background-color: rgb(0,0,0);  border-width: 4px;   border-color: rgb(255, 255, 255); border-radius: 10px; border-color: beige; font: bold 19px; padding: 6px;"  );
}

void iDom_Client::on_redButton_22_released()
{
    sendSignalColor(255,0,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_2_released()
{
    sendSignalColor(0,0,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_3_released()
{
    sendSignalColor(0,255,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_4_released()
{
    sendSignalColor(255,255,51,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_5_released()
{
    sendSignalColor(255,0,128,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_playButton_released()
{
    emit sendTCP("MPD","MPD start");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_RESET_pushButton_released()
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

void iDom_Client::on_stopButton_released()
{
    emit sendTCP("MPD","MPD stop");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButtonPREV_released()
{
    emit sendTCP("MPD","MPD prev");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButtonNext_released()
{
    emit sendTCP("MPD","MPD next");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButton_pause_released()
{
    emit sendTCP("MPD","MPD pause");
    emit sendTCP("MPD_title","MPD get info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButton_volumeUP_released()
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

void iDom_Client::on_pushButton_volumeDOWN_released()
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

void iDom_Client::on_exitButton_pressed()
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
    ui->lineEdit_tabName->setText(   ui->tabWidget->tabText(ui->tabWidget->currentIndex())  );
    ui->horizontalSlider_tabNavigate->setValue(ui->tabWidget->currentIndex());
    if (ui->tabWidget->currentIndex() == 0 )
    {
#ifdef Q_OS_WIN
        //  axWidgetTemperature .dynamicCall("Navigate(const QString&)","http://cyniu88.no-ip.pl/wykres.html");
#endif
#ifdef Q_OS_ANDROID

#endif
    }
    else {
#ifdef Q_OS_ANDROID
        //  delete viewTemp;
#endif
    }
}

void iDom_Client::on_setNumberMPD_clicked()
{
    bool ok;
    QInputDialog myInputDialog;
    QString id = myInputDialog.getItem(this, tr("select radio stations"),
                                       tr("select radio stations"),mpdItems,7,false, &ok);

    if (ok && !id.isEmpty()){
        int songID = 0;
        songID = 1+ mpdItems.indexOf(id);
        ui->setNumberMPD->setText(QString::number( songID ));
        ui->lineEdit_MPD_ACK->setText("play "+id);
        emit sendTCP("MPD","MPD start "+std::to_string(songID));
    }
    droid.vibrate(100);
}

void iDom_Client::on_comboBox_currentIndexChanged(QString txt)
{
    config->command = txt.toStdString();
    emit sendTCP("console",config->command);
}

void iDom_Client::on_turnOnSleepModeButton_clicked()
{
    bool ok;
    int i;
    i = QInputDialog::getInt(this,tr("set sleep mode"),tr("minutes"),1,1,1000,1,&ok);
    if (ok){
        emit sendTCP("tools","sleep set "+std::to_string(i));
    }
}

void iDom_Client::on_stopServerButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "", "stop server?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        qDebug() << "Yes was clicked";
        emit sendTCP("tools","stop server");
        QThread::sleep(1);
        on_connectdicsonnectButton_clicked();
    }
}

void iDom_Client::on_pushButton_extra_clicked()
{
    QColorDialog color;
    color.setOptions(QColorDialog::ShowAlphaChannel);
    QFont f;
    int size = QApplication::desktop()->screenGeometry().width() ;
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
        ui->pushButton_extra->setStyleSheet(" border-style: outset; color: rgb(255, 55, 55); background-color: rgb("+QString::number(r)+","+QString::number(g)+"," +QString::number(b)+");  border-width: 4px;   border-color: rgb(255, 255, 255); border-radius: 10px; border-color: beige; font: bold 19px; padding: 6px;"  );
    }
    else{
        ui->pushButton_extra->setStyleSheet(" border-style: outset; color: rgb(255, 255, 255); background-color: rgb(0,0,0);  border-width: 4px;   border-color: rgb(255, 255, 255); border-radius: 10px; border-color: beige; font: bold 19px; padding: 6px;"  );
    }
}

void iDom_Client::on_pushButton_put_temperature_clicked()
{
    emit sendTCP("tools","put temperature");
}

void iDom_Client::on_pushButton_goodBye_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "", "stop music and LED?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        emit sendTCP("MPD","MPD stop");
        emit sendTCP("LED","iDom LED OFF");
        on_exitButton_pressed();
        QThread::sleep(2);
        qApp->exit();
    }
}

void iDom_Client::on_pushButton_ttsInfo_clicked()
{
    emit sendTCP("TTS","iDom text");
}

void iDom_Client::on_tabRightButton_clicked()
{
    int i = ui->horizontalSlider_tabNavigate->value();  //get current value
    ++i;
    if (i > ui->tabWidget->tabBar()->count()-1){
        i=0;
    }
    ui->horizontalSlider_tabNavigate->setValue(i);
}

void iDom_Client::on_tabLeftButton_clicked()
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

void iDom_Client::on_pushButton_showTemperatureCharts_clicked()
{
    if (wwwWindow!= NULL){
        qDebug() << "kasuje bo nie jest null";
        delete wwwWindow;
    }
    wwwWindow = new wwwShowWindow();
    wwwWindow->show();
}

void iDom_Client::loadImage(QByteArray d)
{
    pima.loadFromData(d);
    ui->cameraLabel->setPixmap(  pima.scaled(ui->cameraLabel->width(),ui->cameraLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation) );
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

void iDom_Client::on_camera_button_reload_clicked()
{
    cameraWork = !cameraWork;
    if (cameraWork){
        ui->camera_button_reload->setText("Stop");
        makeInfo("CAMERA","Video Start");
    }
    else{
        ui->camera_button_reload->setText("Start");
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

void iDom_Client::on_reloadCameraAddressButton_clicked()
{
    bool ok;
    QInputDialog myInputDialog;
    QString id = myInputDialog.getText(this, tr("set new camera address"),tr("address:"),QLineEdit::Normal, cameraAddressHTTP , &ok);

    if (ok && !id.isEmpty()){
        m_pImgCtrl->setAddress(id);
    }
    droid.vibrate(100);
}

void iDom_Client::on_oneShotCameraButton_clicked()
{
    m_pImgCtrl->getSnap();
    makeInfo("Camera","shot taken");
    droid.vibrate(100);
}

void iDom_Client::on_connectdicsonnectButton_clicked()
{
    if (config->isConnectedToServer == true){
        config->goWhile =false;
        ui->connectdicsonnectButton->setText("Connect to iDom");
    }
    else{
        config->worketPTR->start();
        ui->connectdicsonnectButton->setText("Disconnect from iDom");
    }
}

void iDom_Client::on_pushButton_volumeUP_pressed()
{
    pressTime.start();
}

void iDom_Client::on_pushButton_volumeDOWN_pressed()
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
}

void iDom_Client::on_optionsButton_clicked()
{
    optionsWindow.show();
}
