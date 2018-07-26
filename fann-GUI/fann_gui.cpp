#include "fann_gui.h"
#include "ui_fann_gui.h"


#include <ios>
#include <iostream>
#include <iomanip>

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>


fann_GUI::fann_GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fann_GUI)
{
    ui->setupUi(this);



    trainingT = new trainingThread(&netConfig);

    QObject::connect(trainingT,SIGNAL(updateProgressBar(int )), this,SLOT(updateProgressBar(int)));
    QObject::connect(trainingT,SIGNAL(updateLog(QString )), this,SLOT(updateLog(QString)));
    QObject::connect(trainingT,SIGNAL(trainingDone()),      this,SLOT(trainingDone()));

    ui->b_save_trainData->setEnabled(false);
    setTrainingAlgorythm();
}

fann_GUI::~fann_GUI()
{
    delete  trainingT;
    delete ui;
}



void fann_GUI::on_b_startTrain_clicked()
{
    if(netConfig.trainingDataPatch == "NULL")
    {
        QMessageBox::critical(this,tr("INFO"),tr("podaj sciezke do danych treningowych!"));

        return;
    }
    if(netConfig.netFloat == "NULL")
    {
        QMessageBox::critical(this,tr("INFO"),tr("podaj sciezke do zapisu sieci !"));

        return;
    }

    ui->progressBar->setValue(0);
    // TODO  start watku treningowego

    netConfig.learning_rate = static_cast<float>(ui->learning_rate->value());
    netConfig.num_layers = static_cast<unsigned int>(ui->num_layers->value());
    netConfig.num_input = static_cast<unsigned int>(ui->numInput->value());
    netConfig.num_hidden = static_cast<unsigned int>(ui->num_hidden->value());
    netConfig.num_output = static_cast<unsigned int>(ui->num_output->value());
    netConfig.desired_error = static_cast<float>(ui->desired_error->value());
    netConfig.max_iterations = static_cast<unsigned int>(ui->max_iterations->value());
    netConfig.iterations_between_reports = static_cast<unsigned int>(ui->iterations_between_reports->value());
   // netConfig.trainingDataPatch = trainingDataPatch.toStdString();

    trainingT->start();

    ui->b_startTrain->setEnabled(false);
}

void fann_GUI::on_trainingData_textChanged()
{
    ui->b_save_trainData->setEnabled(true);
}

void fann_GUI::on_b_save_trainData_clicked()
{
    if(netConfig.trainingDataPatch == "NULL")
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                        "training.data",
                                                        tr("Data (*.data)"));

        std::string path = fileName.toStdString();
        netConfig.trainingDataPatch = path;
    }
    QFile file(QString::fromStdString(netConfig.trainingDataPatch) );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        QString s = ui->trainingData->toPlainText();
        stream << s << endl;
    }
    ui->b_save_trainData->setEnabled(false);
    ui->logBox->append("training data has been saved");

    updateParamiterFromFileDataTraining();
}

void fann_GUI::on_b_OK_clicked()
{
    FANN::neural_net siec;

    if(ui->pathNet->text().size() < 3)
    {
        QMessageBox::critical(this,tr("INFO"),tr("podaj sciezke do sieci"));
        return;
    }
    siec.create_from_file(ui->pathNet->text().toStdString());
    //siec.print_connections();

    fann_type kk[4] ;


    if(ui->checkBox_A->isChecked() == true)
        kk[0] = 1.0;
    else
        kk[0] = -1.0;

    if(ui->checkBoxB->isChecked() == true)
        kk[1] = 1.0;
    else
        kk[1] = -1.0;
    if(ui->checkBoxC->isChecked() == true)
        kk[2] = 1.0;
    else
        kk[2] = -1.0;
    if(ui->checkBoxD->isChecked() == true)
        kk[3] = 1.0;
    else
        kk[3] = -1.0;

    fann_type *calc_out = siec.run(kk);

    std::stringstream log;
    log << " wynik to : " << calc_out[0] << std::endl;
    ui->logBox->append(QString::fromStdString(log.str()));
    ui->result->setText(QString::number(static_cast<double>((calc_out[0]))));
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

void fann_GUI::on_b_loadTrainingData_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "training.data",
                                                    tr("Data (*.data)"));
    ui->logBox->append( "file train  " + fileName) ;
    netConfig.trainingDataPatch = fileName.toStdString();
    loadTrainingDataFromFile();
}

void fann_GUI::loadTrainingDataFromFile()
{
    QFile file(QString::fromStdString(netConfig.trainingDataPatch));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line ;//= in.readLine();
    while (!in.atEnd()) {
        line += in.readLine()+ "\n";
    }
    ui->trainingData->setText(line);
    updateParamiterFromFileDataTraining();
}

void fann_GUI::updateParamiterFromFileDataTraining()
{
    QString s = ui->trainingData->toPlainText();
    int num_in = QString(s.at(2)).toInt();
    int num_out= QString(s.at(4)).toInt();

    ui->numInput->setValue(num_in);
    ui->num_output->setValue(num_out);
}

void fann_GUI::setTrainingAlgorythm()
{
    QString s = ui->net_type->currentText();
    ui->logBox->append("typ sieci: " + s);
    if (s == "FANN::TRAIN_INCREMENTAL")
        netConfig.trainingAlgo = FANN::TRAIN_INCREMENTAL;
    else if (s == "FANN::TRAIN_BATCH")
        netConfig.trainingAlgo = FANN::TRAIN_BATCH;
    else if (s == "FANN::TRAIN_RPROP")
        netConfig.trainingAlgo = FANN::TRAIN_RPROP;
    else if (s == "FANN::TRAIN_QUICKPROP")
        netConfig.trainingAlgo = FANN::TRAIN_QUICKPROP;
}

void fann_GUI::on_b_saveNetfile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                    "myNet.net",
                                                    tr("Data (*.net)"));

    std::string patch = fileName.toStdString();
    netConfig.netFixed = patch.substr(0,patch.size()-4)+"_fixed.net";
    netConfig.netFloat = patch.substr(0,patch.size()-4)+"_float.net";
    ui->logBox->append( "net fixed save to file:  " + QString::fromStdString(netConfig.netFixed)) ;
    ui->logBox->append( "net fload save to file:  " + QString::fromStdString(netConfig.netFloat)) ;
}

void fann_GUI::on_b_loadNet_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "",
                                                    tr("Data (*.net)"));
    ui->logBox->append( "load net  " + fileName) ;
    ui->pathNet->setText(fileName);
}

void fann_GUI::on_b_logClear_clicked()
{
    ui->logBox->clear();
}

void fann_GUI::on_net_type_currentTextChanged(const QString &arg1)
{
    setTrainingAlgorythm();
}
