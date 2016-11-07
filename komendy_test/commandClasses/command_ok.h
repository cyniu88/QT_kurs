#ifndef COMMAND_OK_H
#define COMMAND_OK_H

#include <string>
#include <vector>
#include "../command.h"

class command_ok : public command
{
public:
    command_ok(std::string);
    std::string execute(std::vector <std::string> &v,thread_data * my_data);
};

#endif // COMMAND_OK_H
