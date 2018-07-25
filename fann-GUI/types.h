#ifndef TYPES_H
#define TYPES_H
#include <string>

struct NET_CONF{
     float learning_rate;
     unsigned int num_layers;
     unsigned int num_input;
     unsigned int num_hidden;
     unsigned int num_output;
     float desired_error ;
     unsigned int max_iterations;
     unsigned int iterations_between_reports;
     std::string trainingDataPatch;
     std::string netFixed;
     std::string netFloat;
};

#endif // TYPES_H
