
#include "fann-src/floatfann.h"
#include "fann-src/fann_cpp.h"

#include <ios>
#include <iostream>
#include <iomanip>



// Callback function that simply prints the information to std::cout
int print_callback(FANN::neural_net &net, FANN::training_data &train,
    unsigned int max_epochs, unsigned int epochs_between_reports,
    float desired_error, unsigned int epochs, void *user_data)
{
    std::cout << "Epochs     " << std::setw(8) << epochs << ". "
         << "Current Error: " << std::left << net.get_MSE() << std::right << std::endl;
    return 0;
}

// Test function that demonstrates usage of the fann C++ wrapper
void xor_test()
{
    std::cout << std::endl << "kamien test started." << std::endl;

    const float learning_rate = 0.9f;
    const unsigned int num_layers = 4;
    const unsigned int num_input = 6;
    const unsigned int num_hidden = 8;

    const unsigned int num_hidden2 = 5;
    const unsigned int num_output = 3;
    const float desired_error = 0.0001f;
    const unsigned int max_iterations = 3000000;
    const unsigned int iterations_between_reports = 1000;

    std::cout << std::endl << "Creating network." << std::endl;

    FANN::neural_net net;
    net.create_standard(num_layers, num_input, num_hidden,num_hidden2, num_output);

    net.set_learning_rate(learning_rate);

    net.set_activation_steepness_hidden(1.0);
    net.set_activation_steepness_output(1.0);

    net.set_activation_function_hidden(FANN::SIGMOID_SYMMETRIC_STEPWISE);
    net.set_activation_function_output(FANN::SIGMOID_SYMMETRIC_STEPWISE);

    // Set additional properties such as the training algorithm
    //net.set_training_algorithm(FANN::TRAIN_INCREMENTAL);

    // Output network type and parameters
    std::cout << std::endl << "Network Type                         :  ";
    switch (net.get_network_type())
    {
    case FANN::LAYER:
        std::cout << "LAYER" << std::endl;
        break;
    case FANN::SHORTCUT:
        std::cout << "SHORTCUT" << std::endl;
        break;
    default:
        std::cout << "UNKNOWN" << std::endl;
        break;
    }
    //net.print_parameters();

    std::cout << std::endl << "Training network." << std::endl;

    FANN::training_data data;
    if (data.read_train_from_file("kamien.data"))
    {
        // Initialize and train the network with the data
        net.init_weights(data);

        std::cout << "Max Epochs " << std::setw(8) << max_iterations << ". "
            << "Desired Error: " << std::left << desired_error << std::right << std::endl;
        net.set_callback(print_callback, NULL);
        net.train_on_data(data, max_iterations,
            iterations_between_reports, desired_error);

        std::cout << std::endl << "Testing network." << std::endl;

        for (unsigned int i = 0; i < data.length_train_data(); ++i)
        {
            // Run the network on the test data
            fann_type *calc_out = net.run(data.get_input()[i]);

            std::cout << "kamien test (" << std::showpos << data.get_input()[i][0] << ", "
                 << data.get_input()[i][1]<< ", " << data.get_input()[i][2]<< ", " << data.get_input()[i][3]<< ", " << data.get_input()[i][4]<< ", " << data.get_input()[i][5]
                 << ") -> " << calc_out[0] << ","<< calc_out[1] << ","<< calc_out[2] << ","
                 << ", should be " << data.get_output()[i][0] << ", " << data.get_output()[i][1] << ", "<< data.get_output()[i][2] << ", "
                 << "difference = " << std::noshowpos
                 << fann_abs(*calc_out - data.get_output()[i][0]) << std::endl;
        }

        std::cout << std::endl << "Saving network." << std::endl;

        // Save the network in floating point and fixed point
        net.save("kamien_float.net");
        unsigned int decimal_point = net.save_to_fixed("kamien_fixed.net");
        data.save_train_to_fixed("kamien_fixed.data", decimal_point);

        std::cout << std::endl << "kamien test completed." << std::endl;
    }
}

void runNeural()
{
    FANN::neural_net siec;

    siec.create_from_file("kamien_float.net");
    //siec.print_connections();

    fann_type kk[6] = {-1.0f,-1.0f,1.0f,-1.0f,-1.0f,1.0f};

    fann_type *calc_out = siec.run(kk);

    std::cout << " wynik to : " << calc_out[0]<< ":"<< calc_out[1]<< ":"<< calc_out[2] << std::endl;

}
/* Startup function. Syncronizes C and C++ output, calls the test function
   and reports any exceptions */
int main(int argc, char **argv)
{
    try
    {
        std::ios::sync_with_stdio(); // Syncronize std::cout and printf output
        xor_test();
        std::cout << "gramy dalej !!!" << std::endl;
        runNeural();
        std::cout << "KONIEC" <<std::endl;
    }
    catch (...)
    {
        std::cerr << std::endl << "Abnormal exception." << std::endl;
    }
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>

#include <ios>
#include <string>
#include <iostream>
#include <iomanip>

#include "floatfann.h"
#include "fann_cpp.h"



int main(int argc, char**argv) {

  std::std::cout << "=== Loading data ===" << std::std::endl;
  FANN::training_data data;
  if (data.read_train_from_file("data.txt")) {
    std::std::cout << "loaded " << data.length_train_data() << " training examples" << std::std::endl;
    data.shuffle_train_data();

    const float learning_rate = 555;
    const unsigned int num_layers = 3;
    const unsigned int num_input = data.num_input_train_data();
    const unsigned int num_output = data.num_output_train_data();
    const unsigned int num_hidden = 3;
    const float desired_error = 0.001f;
    const unsigned int max_iterations = 466;
    const unsigned int iterations_between_reports = 10;

    std::std::cout << "=== Creating network ===" << std::std::endl;
    std::std::cout << "Input   nodes: " <<  num_input << std::std::endl;
    std::std::cout << "Hiidden nodes: " <<  num_hidden << std::std::endl;
    std::std::cout << "Output  nodes: " <<  num_output << std::std::endl;

    FANN::neural_net net;
    net.create_standard(num_layers, num_input, num_hidden, num_output);
    net.set_learning_rate(learning_rate);

    //net.set_training_algorithm(FANN::TRAIN_INCREMENTAL  );
    net.set_training_algorithm(FANN::TRAIN_QUICKPROP  );
    //net.set_training_algorithm(FANN::TRAIN_BATCH);
    //net.set_training_algorithm(FANN::TRAIN_RPROP);

    net.set_activation_steepness_output(1.0);
    net.set_activation_steepness_hidden(1.0);

    net.set_activation_function_hidden(FANN::SIGMOID_SYMMETRIC);
    net.set_activation_function_output(FANN::SIGMOID);

    net.init_weights(data);

    std::std::cout << "=== Training network ===" << std::std::endl;
    net.train_on_data(data, max_iterations, iterations_between_reports, desired_error);
    std::std::cout << std::std::endl << "Saving network to" << std::string("data.txt") << std::std::endl;

    net.save("data.txt");
  }

  return 0;
}
*/
