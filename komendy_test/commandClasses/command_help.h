#ifndef COMMAND_HELP_H
#define COMMAND_HELP_H

#include <iostream>
#include <string>
#include <vector>
#include "../command.h"

class command_help : public command
{
public:
    command_help(std::string);
    std::string execute(std::vector <std::string> &v,thread_data * my_data);
    std::string help();
};

#endif // COMMAND_HELP_H
