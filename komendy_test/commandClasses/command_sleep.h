#ifndef COMMAND_SLEEP_H
#define COMMAND_SLEEP_H

#include <iostream>
#include <string>
#include <vector>
#include "../command.h"

class command_sleep : public command
{
public:
    command_sleep(std::string);
    std::string execute(std::vector <std::string> &v,thread_data * my_data);
    std::string help();
};

#endif // COMMAND_SLEEP_H
