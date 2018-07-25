#include "fann_gui.h"
#include "ui_fann_gui.h"


#include <ios>
#include <iostream>
#include <iomanip>

#include <QDebug>
#include <QFile>
#include <QTextStream>


fann_GUI::fann_GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fann_GUI)
{
    ui->setupUi(this);

    QFile file(trainingDataPatch);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line ;//= in.readLine();
    while (!in.atEnd()) {
        line += in.readLine()+ "\n";
    }
    ui->trainingData->setText(line);

    trainingT = new trainingThread(&netConfig);

    QObject::connect(trainingT,SIGNAL(updateProgressBar(int )), this,SLOT(updateProgressBar(int)));
    QObject::connect(trainingT,SIGNAL(updateLog(QString )), this,SLOT(updateLog(QString)));
    QObject::connect(trainingT,SIGNAL(trainingDone()),      this,SLOT(trainingDone()));

    ui->b_save_trainData->setEnabled(false);
}

fann_GUI::~fann_GUI()
{
    delete  trainingT;
    delete ui;
}



void fann_GUI::on_b_startTrain_clicked()
{
    ui->logBox->clear();
    ui->progressBar->setValue(0);
    // TODO  start watku treningowego

    netConfig.learning_rate = static_cast<float>(ui->learning_rate->value());
    netConfig.num_layers = ui->num_layers->value();
    netConfig.num_input = ui->numInput->value();
    netConfig.num_hidden = ui->num_hidden->value();
    netConfig.num_output = ui->num_output->value();
    netConfig.desired_error = static_cast<float>(ui->desired_error->value());
    netConfig.max_iterations = ui->max_iterations->value();
    netConfig.iterations_between_reports = ui->iterations_between_reports->value();
    netConfig.trainingDataPatch = trainingDataPatch.toStdString();

    trainingT->start();

    ui->b_startTrain->setEnabled(false);
}

void fann_GUI::on_trainingData_textChanged()
{
    ui->b_save_trainData->setEnabled(true);
}

void fann_GUI::on_b_save_trainData_clicked()
{
    QFile file( trainingDataPatch );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        QString s = ui->trainingData->toPlainText();
        stream << s << endl;
    }
    ui->b_save_trainData->setEnabled(false);
}

void fann_GUI::on_b_OK_clicked()
{
    FANN::neural_net siec;

    siec.create_from_file("train_float.net");
    //siec.print_connections();

    fann_type kk[2] ;

    if(ui->checkBox_A->isChecked() == true)
        kk[0] = 1.0;
    else
        kk[0] = -1.0;

    if(ui->checkBoxB->isChecked() == true)
        kk[1] = 1.0;
    else
        kk[1] = -1.0;

    fann_type *calc_out = siec.run(kk);

    std::cout << " wynik to : " << calc_out[0] << std::endl;
    ui->result->setText(QString::number(calc_out[0]));
}

void fann_GUI::updateLog(QString s)
{
    ui->logBox->append(s);
}

void fann_GUI::updateProgressBar(int i)
{
    ui->progressBar->setValue(i);
}

void fann_GUI::trainingDone()
{
    ui->b_startTrain->setEnabled(true);
    QMessageBox::information(this,tr("INFO"),tr("training done!"));
}
