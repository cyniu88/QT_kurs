#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QDebug>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << " data zmina  " << GIT_CURRENT_SHA12 ;
    QString ss2 = GIT_CURRENT_SHA12;
    QString t = std::getenv("CYNIU");
    ui->label_commit->setText(ss2);
    ui->label_branch->setText(t);
}

MainWindow::~MainWindow()
{
    delete ui;
}
