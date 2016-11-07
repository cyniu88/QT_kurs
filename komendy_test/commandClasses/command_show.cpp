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

