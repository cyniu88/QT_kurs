#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMultimedia>
#include <QMediaPlayer>
#include <QVideoWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}
