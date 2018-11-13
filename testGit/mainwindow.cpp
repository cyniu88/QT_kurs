#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  qDebug() << " data zmina  " << GIT_CURRENT_SHA12 ;
    QString ss2 = GIT_CURRENT_SHA12;
    ui->label_commit->setText(ss2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
