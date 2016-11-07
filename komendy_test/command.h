#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
class LCD_c;
class s_pointer;
struct config;
struct sockaddr_in;
class files_tree;
class Thread_array_struc;
class KEY;
class  MPD_info;
class pilot_led;
class CRON;

struct thread_data{
    int s_client_sock;

    struct config *server_settings;

    LCD_c *mainLCD;
    files_tree *main_tree;

    Thread_array_struc *main_THREAD_arr;
    time_t start;
    time_t now_time;
    int sleeper;
    std::map <std::string , std::unique_ptr <KEY>  > key_map;
    MPD_info *ptr_MPD_info;
    pilot_led * ptr_pilot_led;



    //CRON * main_cron;

};

class command
{
    std::string commandName;
    std::map<std::string, std::unique_ptr<command> > *commandMap;
public:
    command(std::string commandName);
    ~command();
    virtual std::string execute(std::vector<std::string> &v,thread_data * my_data) =0 ;
    virtual std::string getCommandName() ;
};

#endif // COMMAND_H
