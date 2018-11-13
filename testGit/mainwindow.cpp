#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  qDebug() << " danta " << GIT_CURRENT_SHA1 ;
    QString ss = GIT_CURRENT_SHA1;
    ui->label_commit->setText(ss);
}

MainWindow::~MainWindow()
{
    delete ui;
}
