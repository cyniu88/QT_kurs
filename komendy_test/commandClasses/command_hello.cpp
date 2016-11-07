#include "command_hello.h"

command_hello::command_hello(std::string name):command(name)
{

}

std::string command_hello::execute(std::vector<std::string> &v, thread_data *my_data)
{

    return "\nHI !\n";
}
