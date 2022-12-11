#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QPushButton>
#include <QUrl>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto video = new QVideoWidget(this);
    video->setGeometry(80,80,this->width(),this->height());
    video->show();

    auto player = new QMediaPlayer(this);
    auto audio = new QAudioOutput(this);

   // connect(player,&QMediaPlayer::errorChanged,this,&MainWindow::mediaPlayerDebugError);
   // connect(player,&QMediaPlayer::mediaStatusChanged,this,&MainWindow::mediaPlayerDebugStatus);

    player->setVideoOutput(video);
    player->setSource(QUrl("rtsp://admin:$506cyniU@192.168.13.207:554/Streaming/channels/201"));

    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

