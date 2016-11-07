#include "command_help.h"

command_help::command_help(std::string name):command(name)
{

}

std::string command_help::execute(std::vector<std::string> &v, thread_data *my_data)
{
    std::cout << " jestem w execute command _help! "<< v[0]<< std::endl;

    return v[0]+" "+v[1];
}
