#ifndef TYPES_H
#define TYPES_H
#include <string>

#include "../FANN-test/fann-src/floatfann.h"
#include "../FANN-test/fann-src/fann_cpp.h"

struct NET_CONF{
     float learning_rate;
     unsigned int num_layers;
     unsigned int num_input;
     unsigned int num_hidden;
     unsigned int num_output;
     float desired_error ;
     unsigned int max_iterations;
     unsigned int iterations_between_reports;
     std::string trainingDataPatch = "NULL";
     std::string netFixed = "NULL";
     std::string netFloat = "NULL";
     FANN::training_algorithm_enum trainingAlgo;
};

#endif // TYPES_H
