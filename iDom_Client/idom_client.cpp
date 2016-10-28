
#include <QPixmap>
#include <QStackedWidget>
#include <QDebug>
#include <QDesktopWidget>

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
    QScroller::grabGesture(ui->wynik,QScroller::TouchGesture);


    ui->wynik->setAttribute(Qt::WA_AcceptTouchEvents);

    ////  //////////////////////////    Ladowanie grafiki  ////////////////////////
    QPixmap pix;

    if (pix.load( ":/new/prefix1/files/background.png"   ))
    {
        qDebug("udalo sie  ");
    }



    pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pix);
    this->setPalette(palette);

    QRect rec = QApplication::desktop()->screenGeometry();
    int  height = rec.height();
    int  width  = rec.width();

    std::string s =  std::to_string(height) +" and " + std::to_string(width)  ;

    ui->wynik->setText( QString::fromStdString( s));
#ifdef Q_OS_WIN

    axWidgetTemperature.setControl("{8856f961-340a-11d0-a96b-00c04fd705a2}");

    ui->widgetWWW->layout()->addWidget( axWidgetTemperaturePTR);

    if (ui->tabWidget->currentIndex() == 0 )
    {
        axWidgetTemperature.dynamicCall("Navigate(const QString&)","http://cyniu88.no-ip.pl/wykres.html");
    }
#endif
#ifdef Q_OS_ANDROID
    QtWebView::initialize();
#endif

}

iDom_Client::~iDom_Client()
{
#ifdef Q_OS_WIN
    axWidgetTemperature.deleteLater();
    //delete axWidgetTemperature;
#endif
    // delete okno;
    delete ui;

}

void iDom_Client::on_EXITButton_released()
{
    ui->centralWidget->close();
}

void iDom_Client::scrollTitle()
{
    //toDo

    QString temp = ui->titleTXT->text();
    temp.push_back(temp[0]);
    temp.remove(0,1);
    ui->titleTXT->setText(temp);
}



void iDom_Client::odb_answer(QString s){
    ui->wynik->setText(s);
    ui->wynik->moveCursor(QTextCursor::End);

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
    ui->volumeTXT->setText("volume: " +s+"%");
    ui->volumeBar->setValue(s.toInt());
}



void iDom_Client::errorRead(QString tit, QString msg)
{
    droid.vibrate(300);
#ifdef Q_OS_ANDROID
    QMessageBox::information(this,tit,  msg);
#endif
#ifdef Q_OS_WIN
    trayIcon.showMessage(tit,msg);
#endif


}

void iDom_Client::updateMPDinfo()
{
    emit sendTCP("MPD_title","MPD get_info");

    emit sendTCP("MPD_volume","MPD get_volume");

    qDebug("timer mpd info ");
}

void iDom_Client::updateTemepretureInfo()
{
    emit sendTCP("temperature","RS232 get temperature");
}

void iDom_Client::odb_temperature(QString s)
{
    QString in = s.split(":")[0];
    QString out =s.split(":")[1];
    out = out.split("\r")[0];
    qDebug() << out;
    ui->InsideLCD->display( in   );
    ui->OutsideLCD->display( out);

}





void iDom_Client::on_pushButton_released()
{
    config->command = ui->comboBox->currentText().toStdString();
    emit sendTCP("console",config->command);

}

void iDom_Client::sendSignalColor(int r,int g, int b, int from, int to)
{
    emit sendTCP("LED",
                 "RS232 send LED:["+std::to_string(from)+"-"+std::to_string(to)+"-"+std::to_string(r)+"-"+std::to_string(g)+"-"+std::to_string(b)+"];"
                 );
    std::string s_buffor = "RS232 send LED:["+std::to_string(from)+"-"+std::to_string(to)+"-"+std::to_string(r)+"-"+std::to_string(g)+"-"+std::to_string(b)+"];";
    qDebug() << QString::fromStdString(s_buffor);
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

    emit sendTCP("LED","RS232 send LED_STOP:2;");
}

void iDom_Client::on_redButton_22_released()
{

    sendSignalColor(255,0,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());

}

void iDom_Client::on_pushButton_2_released()
{
    // config->command="RS232 send LED:[1-60-0-0-255];";
    sendSignalColor(0,0,255,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());

}

void iDom_Client::on_pushButton_3_released()
{
    //config->command="RS232 send LED:[1-60-0-255-0];";
    //emit sendTCP("button",config->command);
    sendSignalColor(0,255,0,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_4_released()
{
    //    config->command="RS232 send LED:[1-60-254-254-51];";
    //    emit sendTCP("button",config->command);
    sendSignalColor(255,255,51,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}

void iDom_Client::on_pushButton_5_released()
{
    //config->command="RS232 send LED:[1-60-254-0-128];";
    sendSignalColor(255,0,128,ui->spinBox_fromLED->value(), ui->spinBox_toLED->value());
}


void iDom_Client::on_playButton_released()
{
    emit sendTCP("MPD","MPD start");
    emit sendTCP("MPD_title","MPD get_info");
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

void iDom_Client::on_from_horizontalSlider_valueChanged(int value)
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

void iDom_Client::on_spinBox_toLED_valueChanged()
{
    ui->to_horizontalSlider_2->setValue(ui->spinBox_toLED->value());
    ui->lcdNumber_toLED->display(ui->to_horizontalSlider_2->value());
}

void iDom_Client::on_spinBox_fromLED_valueChanged()
{

    ui->from_horizontalSlider->setValue(ui->spinBox_fromLED->value());
    ui->lcdNumber_fromLED->display(ui->from_horizontalSlider->value());
}



void iDom_Client::on_stopButton_released()
{
    emit sendTCP("MPD","MPD stop");
    emit sendTCP("MPD_title","MPD get_info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButtonPREV_released()
{
    emit sendTCP("MPD","MPD prev");
    emit sendTCP("MPD_title","MPD get_info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButtonNext_released()
{
    emit sendTCP("MPD","MPD next");
    emit sendTCP("MPD_title","MPD get_info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButton_pause_released()
{
    emit sendTCP("MPD","MPD pause");
    emit sendTCP("MPD_title","MPD get_info");
    droid.vibrate(100);
}

void iDom_Client::on_pushButton_volumeUP_released()
{
    emit sendTCP("MPD","MPD volume_up");
    ui->volumeBar->setValue(ui->volumeBar->value()+1);
    emit sendTCP("MPD_volume","MPD get_volume");
    droid.vibrate(100);
}

void iDom_Client::on_pushButton_volumeDOWN_released()
{
    emit sendTCP("MPD","MPD volume_down");
    ui->volumeBar->setValue(ui->volumeBar->value()-1);
    emit sendTCP("MPD_volume","MPD get_volume");
    droid.vibrate(100);
}

void iDom_Client::on_exitButton_pressed()
{

    emit sendTCP("console","exit");
}

void iDom_Client::on_pushButtonupdateinfo_released()
{
    emit sendTCP("MPD_title","MPD get_info");
    QThread::sleep(1);
    emit sendTCP("MPD_volume","MPD get_volume");

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
    if (ui->tabWidget->currentIndex() == 0 )
    {
#ifdef Q_OS_WIN
        axWidgetTemperature .dynamicCall("Navigate(const QString&)","http://cyniu88.no-ip.pl/wykres.html");
#endif
    }
}

void iDom_Client::on_sendEXTRA_clicked()
{
    emit sendExtra();
}
