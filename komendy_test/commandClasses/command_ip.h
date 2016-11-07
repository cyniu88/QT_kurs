#ifndef COMMAND_IP_H
#define COMMAND_IP_H

#include <iostream>
#include <string>
#include <vector>
#include "../command.h"

class command_ip : public command
{
public:
    command_ip(std::string);
    std::string execute(std::vector <std::string> &v,thread_data * my_data);
};

#endif // COMMAND_IP_H
