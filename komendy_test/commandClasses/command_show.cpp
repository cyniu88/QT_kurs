#include "command_show.h"

command_show::command_show(std::string name):command(name)
{

}

std::string command_show::execute(std::vector<std::string> &v, thread_data *my_data)
{
    std::string str_buf = "show what? ";
    if (v.size() > 1){
        if (v[1] =="log")
        {

        }
        else {
            str_buf = "wrong parameter: "+v[1];
        }
    }

    return str_buf;
}

std::string command_show::help()
{
    std::string help = "show <parameter>- for show something";
                    help.append("\n");
                    help.append("parameter:");
                    help.append("\n");
                    help.append("log - show all server log");
                    help.append("\n");

        return help;
}

