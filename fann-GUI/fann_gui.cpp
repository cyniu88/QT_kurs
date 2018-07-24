#include "fann_gui.h"
#include "ui_fann_gui.h"


#include <ios>
#include <iostream>
#include <iomanip>

#include <QDebug>
#include <QFile>
#include <QTextStream>

static Ui::fann_GUI *my_static_ui = nullptr;


fann_GUI::fann_GUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fann_GUI)
{
    ui->setupUi(this);
    my_static_ui = ui;

    QFile file(trainingDataPatch);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString line ;//= in.readLine();
    while (!in.atEnd()) {
        line += in.readLine()+ "\n";
    }
    ui->trainingData->setText(line);
}

fann_GUI::~fann_GUI()
{
    delete ui;
}

int fann_GUI::print_callback(FANN::neural_net &net, FANN::training_data &train,
                             unsigned int max_epochs, unsigned int epochs_between_reports,
                             float desired_error, unsigned int epochs, void *user_data)
{
    std::stringstream log;
    log << "Epochs     " << std::setw(8) << epochs << ". "
        << "Current Error: " << std::left << net.get_MSE() << std::right << std::endl;

    my_static_ui->logBox->append(QString::fromStdString(log.str()));

    int i = (epochs * 100 )/ max_epochs;
    qDebug() << "i ma : " << i << " max_epochs " << max_epochs;
    my_static_ui->progressBar->setValue(i);
    return 0;

}

void fann_GUI::train()
{
    std::stringstream log;
    log << std::endl << "XOR test started." << std::endl;

    const float learning_rate = static_cast<float>(ui->learning_rate->value());
    const unsigned int num_layers = ui->num_layers->value();
    const unsigned int num_input = ui->numInput->value();
    const unsigned int num_hidden = ui->num_hidden->value();
    const unsigned int num_output = ui->num_output->value();
    const float desired_error = static_cast<float>(ui->desired_error->value());
    const unsigned int max_iterations = ui->max_iterations->value();
    const unsigned int iterations_between_reports = ui->iterations_between_reports->value();

    log << std::endl << "Creating network." << std::endl;

    FANN::neural_net net;
    net.create_standard(num_layers, num_input, num_hidden, num_output);

    net.set_learning_rate(learning_rate);

    net.set_activation_steepness_hidden(1.0);
    net.set_activation_steepness_output(1.0);

    net.set_activation_function_hidden(FANN::SIGMOID_SYMMETRIC_STEPWISE);
    net.set_activation_function_output(FANN::SIGMOID_SYMMETRIC_STEPWISE);

    // Set additional properties such as the training algorithm
    //net.set_training_algorithm(FANN::TRAIN_INCREMENTAL);

    // Output network type and parameters
    log << std::endl << "Network Type                         :  ";
    switch (net.get_network_type())
    {
    case FANN::LAYER:
        log << "LAYER" << std::endl;
        break;
    case FANN::SHORTCUT:
        log << "SHORTCUT" << std::endl;
        break;
    default:
        log << "UNKNOWN" << std::endl;
        break;
    }
    //net.print_parameters();

    log << std::endl << "Training network." << std::endl;

    FANN::training_data data;
    if (data.read_train_from_file(trainingDataPatch.toStdString()))
    {
        // Initialize and train the network with the data
        net.init_weights(data);

        log << "Max Epochs " << std::setw(8) << max_iterations << ". "
            << "Desired Error: " << std::left << desired_error << std::right << std::endl;
        ui->logBox->append(QString::fromStdString(log.str()));
        log.clear();
        net.set_callback(print_callback, NULL);
        net.train_on_data(data, max_iterations,
                          iterations_between_reports, desired_error);

        log << std::endl << "Testing network." << std::endl;

        for (unsigned int i = 0; i < data.length_train_data(); ++i)
        {
            // Run the network on the test data
            fann_type *calc_out = net.run(data.get_input()[i]);

            log << "XOR test (" << std::showpos << data.get_input()[i][0] << ", "
                << data.get_input()[i][1] << ") -> " << *calc_out
                << ", should be " << data.get_output()[i][0] << ", "
                << "difference = " << std::noshowpos
                << fann_abs(*calc_out - data.get_output()[i][0]) << std::endl;
        }

        log << std::endl << "Saving network." << std::endl;

        // Save the network in floating point and fixed point
        net.save("train_float.net");
        unsigned int decimal_point = net.save_to_fixed("train_fixed.net");
        data.save_train_to_fixed("xor_fixed.data", decimal_point);

        log << std::endl << "test completed." << std::endl;
        ui->logBox->append(QString::fromStdString(log.str()));
        ui->progressBar->setValue(100);
    }
}


void fann_GUI::on_b_startTrain_clicked()
{
    ui->logBox->clear();
    ui->progressBar->setValue(0);
    train();

}

void fann_GUI::on_trainingData_textChanged()
{


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
