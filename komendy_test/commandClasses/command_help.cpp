#include "command_help.h"

command_help::command_help(std::string name):command(name)
{

}

std::string command_help::execute(std::vector<std::string> &v, thread_data *my_data)
{
    std::cout << " jestem w execute command _help! "<< v[0]<< std::endl;

    return v[0]+" "+v[1];
}

std::string command_help::help()
{
    return "help - show help for all command \nhelp <command> - show help for command\n";
}
