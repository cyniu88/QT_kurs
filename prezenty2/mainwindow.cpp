#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QThread>

#include <algorithm>
#include "data.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    on_put_text_textChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_sms_clicked()
{
    QString msg;
    for (int i = 0; i < userVecotr.size(); ++i){
        qDebug() << "\n\n\nvector1 "<< userVecotr.at(i).name << " "<< userVecotr.at(i).surname<< " "<< userVecotr.at(i).id
                 << "vector2 "<< userVecotrCopy.at(i).name << " "<< userVecotrCopy.at(i).surname<< " "<< userVecotrCopy.at(i).id;

        QString tel = userVecotr.at(i).telephone;
        msg = "Witaj ";
        msg.append(userVecotr.at(i).name);
        msg.append(". Jestem automatem do losowania. Na Swieta 2020 przypadl Ci zaszczyt kupna prezentu pod choinke dla: ");
      //  msg.append(". Na Swieta 2018 przypadl Ci zaszczyt kupna prezentu pod choinke dla: ");
        msg.append(userVecotrCopy.at(i).name);
        msg.append(" ");
        msg.append(userVecotrCopy.at(i).surname);
      //  msg.append(". Autor automatu: Krzysztof Druciak");
        sendSMS(i, userVecotr.size(), tel, msg);
        sendSMS(i, userVecotr.size(), tel, "Autor automatu: Krzysztof Druciak");
    }
//droid.sendSMS("+48506496722", msg );
}

void MainWindow::on_put_text_textChanged()
{
    ui->comboBox->clear();
    QString msg = ui->put_text->toPlainText();
    QStringList txt = msg.split("\n");
    ui->comboBox->addItems(txt);
    ui->lcdNumber->display(ui->comboBox->count());
    qDebug()<< "MSG: " << msg ;
}

void MainWindow::on_b_prepareData_clicked()
{
    userVecotr.clear();
    userVecotrCopy.clear();
    for (int index = 0; index < ui->comboBox->count(); index++)
    {
        QStringList hh = ui->comboBox->itemText(index).split(" ");
        int i = index;
        QString fam = hh.at(0);
        QString n = hh.at(1);
        QString sn = hh.at(2);
        QString tel = hh.at(3);
        USER_S uS;
        uS.id = i;
        uS.name = n;
        uS.surname = sn;
        uS.telephone = tel;
        uS.family = fam;
        userVecotr.append(uS);
    }

    userVecotrCopy = userVecotr;

    qDebug() << "vector ma rozmiar: " << userVecotr.size();
    qDebug() << "vector2 ma rozmiar: " << userVecotrCopy.size();

    bool flag = false;
    int counter = 1;
    while (!flag) {
        std::random_shuffle(userVecotrCopy.begin(), userVecotrCopy.end());
  qDebug() << " counter : "  << counter++;
        for (int i = 0; i < userVecotr.size(); ++i){
            if(userVecotr.at(i).id != userVecotrCopy.at(i).id &&
                    userVecotr.at(i).family != userVecotrCopy.at(i).family)
            {
                flag = true;
            }
            else{
                flag = false;
                break;
            }
        }
    }

    for (int i = 0; i < userVecotr.size(); ++i){
        qDebug() << "vector1 "<< userVecotr.at(i).name << " "<< userVecotr.at(i).surname<< " "<< userVecotr.at(i).id
                 << "vector2 "<< userVecotrCopy.at(i).name << " "<< userVecotrCopy.at(i).surname<< " "<< userVecotrCopy.at(i).id;
    }
}

void MainWindow::sendSMS(int i, int max, QString numer, QString msg)
{
    qDebug() << "SMS: "<< numer << " "  << msg;
    droid.sendSMS(numer, msg);
    QThread::sleep(2);
    ui->progressBar->setValue((100*(i+1))/max);
}
