#include "command_cmd.h"

command_cmd::command_cmd(std::string name):command(name)
{

}

std::string command_cmd::execute(std::vector<std::string> &v, thread_data *my_data)
{
    std::cout << " jestem w execute command _cmd! "<< v[0]<< std::endl;

    return v[0]+" "+v[1];
}

std::string command_cmd::help()
{
    return "cmd - read char prom cmd fifo file for unblock video player\n";
}
