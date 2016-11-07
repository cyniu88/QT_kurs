#include "command_ip.h"

command_ip::command_ip(std::string name):command(name)
{

}

std::string command_ip::execute(std::vector<std::string> &v, thread_data *my_data)
{
    return "IP 12123213:" ;//my_data->server_settings->SERVER_IP;
}

std::string command_ip::help()
{
    return "ip - show server IP address";
}
