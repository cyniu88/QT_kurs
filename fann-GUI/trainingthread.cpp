#include <string>
#include <ios>
#include <iostream>
#include <iomanip>

#include <QtDebug>
#include <QString>
#include <QMessageBox>

#include "trainingthread.h"

static trainingThread* static_this = nullptr;

trainingThread::trainingThread(NET_CONF *ptr)
{
    netConfigPTR = ptr;
    static_this = this;
}

void trainingThread::run()
{
    train();
    qDebug() <<"thread exit";
    emit trainingDone();
}


int trainingThread::print_callback(FANN::neural_net &net, FANN::training_data &train,
                                   unsigned int max_epochs, unsigned int epochs_between_reports,
                                   float desired_error, unsigned int epochs, void *user_data)
{
    static int i_old = 0;
    std::stringstream log;
    log << "Epochs     " << std::setw(8) << epochs << ". "
        << "Current Error: " << std::left << net.get_MSE() << std::right << std::endl;

    //

    int i = (epochs * 100 )/ max_epochs;
    if (i != i_old )
    {
        qDebug() << "i ma : " << i << " max_epochs " << max_epochs;
        //emit updateProgressBar(i);
        static_this->updateProgressBar(i);
        static_this->updateLog(QString::fromStdString(log.str()));
        i_old = i;
    }
    return 0;

}

void trainingThread::train()
{
    std::stringstream log;
    log << std::endl << " test started." << std::endl;

    const float learning_rate = netConfigPTR->learning_rate ;
    const unsigned int num_layers = netConfigPTR->num_layers;
    const unsigned int num_input = netConfigPTR->num_input;
    const unsigned int num_hidden = netConfigPTR->num_hidden;
    const unsigned int num_output = netConfigPTR->num_output;
    const float desired_error = netConfigPTR->desired_error;
    const unsigned int max_iterations = netConfigPTR->max_iterations;
    const unsigned int iterations_between_reports = netConfigPTR->iterations_between_reports;

    log << std::endl << "Creating network." << std::endl;

    FANN::neural_net net;
    if (netConfigPTR->leyersVector.size() > 1)
    {
        unsigned int vectorSize = netConfigPTR->leyersVector.size();
        unsigned int* leyers = new unsigned int[vectorSize+2];
        leyers[0] = num_input;
        for (unsigned int i = 0; i < vectorSize; ++i)
        {
            leyers[i+1] = netConfigPTR->leyersVector.at(i);
        }

        leyers[num_layers-1] = num_output;

        for ( unsigned int i = 0 ; i< vectorSize+2 ; ++i)
        {
            qDebug() << "vector size: "<< vectorSize+2<<" i:"<<i<< " leyers "<< leyers[i];
        }
        net.create_standard_array(vectorSize+2, leyers);
        //net.create_standard(vectorSize+2, leyers[0], leyers[2],leyers[3], leyers[1]);


        delete[] leyers;
    }
    else
    {
        net.create_standard(num_layers, num_input, num_hidden, num_output);
    }

    net.set_learning_rate(learning_rate);

    net.set_activation_steepness_hidden(1.0);
    net.set_activation_steepness_output(1.0);

    net.set_activation_function_hidden(FANN::SIGMOID_SYMMETRIC_STEPWISE);
    net.set_activation_function_output(FANN::SIGMOID_SYMMETRIC_STEPWISE);

    // Set additional properties such as the training algorithm

    net.set_training_algorithm(netConfigPTR->trainingAlgo);

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
    if (data.read_train_from_file(netConfigPTR->trainingDataPatch))
    {
        // Initialize and train the network with the data
        net.init_weights(data);

        log << "Max Epochs " << std::setw(8) << max_iterations << ". "
            << "Desired Error: " << std::left << desired_error << std::right << std::endl;
         emit updateLog(QString::fromStdString(log.str()));
        log << "dupa";
        log.str("");
        log.clear();
        net.set_callback(print_callback, nullptr);
        net.train_on_data(data, max_iterations,
                          iterations_between_reports, desired_error);

        log << std::endl << "Testing network." << std::endl;

        for (unsigned int i = 0; i < data.length_train_data(); ++i)
        {
            // Run the network on the test data
            fann_type *calc_out = net.run(data.get_input()[i]);

            log << "test (";
            for (unsigned int j = 0; j < num_input; ++j)
            {
                log  << std::showpos << data.get_input()[i][j] << ", ";
                //qDebug()<< "jestem w log<<";
            }
            log <<  ") -> " ;
            for(unsigned int k = 0 ; k < num_output ; ++k)
            {
                log << calc_out[k] <<", ";
            }
            log << ", should be ";
            for(unsigned int k = 0 ; k < num_output ; ++k)
            {
                log << data.get_output()[i][k] <<", ";
            }
            log << std::endl ;
        }

        log << std::endl << "Saving network." << std::endl;

        // Save the network in floating point and fixed point
        net.save(netConfigPTR->netFloat);
        unsigned int decimal_point = net.save_to_fixed(netConfigPTR->netFixed);
        std::string path = netConfigPTR->trainingDataPatch.substr(0,netConfigPTR->trainingDataPatch.size()-5);
        data.save_train_to_fixed(path +"_fixed.data", decimal_point);

        log << std::endl << "test completed." << std::endl;
        emit updateLog(QString::fromStdString(log.str()));
        emit updateProgressBar(100);
    }
}
