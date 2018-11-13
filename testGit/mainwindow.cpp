#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  qDebug() << " data zmina  " << GIT_CURRENT_SHA ;
    QString ss = GIT_CURRENT_SHA;
    ui->label_commit->setText(ss);
}

MainWindow::~MainWindow()
{
    delete ui;
}
