#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

class command
{
    std::string commandName;
    std::map<std::string, std::unique_ptr<command> > *commandMap;
public:
    command(std::string commandName);
    ~command();
    virtual std::string execute(std::vector<std::string> &v) =0 ;
    virtual std::string getCommandName() ;
};

#endif // COMMAND_H
