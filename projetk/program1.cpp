#include "program1.h"
#include "ui_program1.h"

program1::program1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::program1)
{
    ui->setupUi(this);
}

program1::~program1()
{
    delete ui;
}

void program1::on_pushButton_released()
{

}

void program1::on_pushButton_setNumber_pressed()
{
   // ui->lineEdit->text();

    ui->lcdNumber->display( ui->lineEdit->text()   );
}

void program1::on_pushButton_setNumber_released()
{

#ifdef Q_OS_WIN32

    QMessageBox::critical(this,":(","windows :P");
#endif

#ifdef Q_OS_ANDROID
    QMessageBox::critical(this,":(","android :P");

#endif
}
