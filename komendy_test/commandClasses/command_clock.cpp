#include "command_clock.h"

command_clock::command_clock(std::string name):command(name)
{

}

std::string command_clock::execute(std::vector<std::string> &v, thread_data *my_data)
{
    std::string str_buf;

    if (v.size() > 1){
        return  str_buf = "clock set ";//+ send_to_arduino_clock(my_data,command[1]);
    }

    return "can not set clock";

}

std::string command_clock::help()
{
    return "clock <number/string> - put number/string (max 4 digits) to 7segment LCD\n";
}
