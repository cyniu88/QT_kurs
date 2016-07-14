#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
QMediaPlayer *player;
QMediaPlaylist *playlist;
QVideoWidget *videoWidget;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    player = new QMediaPlayer;

    playlist = new QMediaPlaylist(player);
    playlist->addMedia(QUrl("http://example.com/myclip1.mp4"));
    playlist->addMedia(QUrl("http://example.com/myclip2.mp4"));

    videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    videoWidget->show();
    playlist->setCurrentIndex(1);
    player->play();
    return a.exec();
}
