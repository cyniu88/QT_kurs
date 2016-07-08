#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vibrator.h"
#include <QDebug>
#include <QMessageBox>

Vibrator vibrator;



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

void MainWindow::on_pushButton_clicked()
{
    qDebug("wibtuje");
    QMessageBox::information(this, tr("ERROR"),tr("wibruje"));
    vibrator.vibrate(1000);
}
