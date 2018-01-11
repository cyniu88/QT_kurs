#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../libs/emoji/emoji.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setText(QString::fromStdString(EMOJI::emoji(E_emoji::WARNING_SIGN)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
