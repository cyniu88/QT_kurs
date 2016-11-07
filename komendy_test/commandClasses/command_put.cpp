#include "command_put.h"

command_put::command_put(std::string name):command(name)
{

}

std::string command_put::execute(std::vector<std::string> &v, thread_data *my_data)
{
    std::string str_buf = "command put - wrong paramiter: ";
    if (v.size() > 1){
        if (v[1] =="temperature")
        {
            str_buf.erase();
            CRON temp_CRON(my_data);
            temp_CRON.send_temperature_thingSpeak("47XSQ0J9CPJ4BO2O");
            str_buf = "DONE";
        }
    }
    return str_buf;
}
