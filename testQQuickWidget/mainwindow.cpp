#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->quickWidget->setSource(QUrl::fromLocalFile(":/p/www.qml"));
    ui->centralWidget->show();

   // e = new QQmlApplicationEngine(":/p/www.qml");

//ui->widget->layout()->addWidget(e);
}

MainWindow::~MainWindow()
{
    delete e;
    delete ui;
}
