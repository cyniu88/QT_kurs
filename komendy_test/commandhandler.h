#ifndef COMMANDHANDLE_H
#define COMMANDHANDLE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <commandtest.h>
#include <commandexit.h>


class commandHandler
{

    std::map<std::string, std::unique_ptr<command> > commandMap;

public:
    commandHandler();

    std::string run(std::vector <std::string> &v);
};

#endif // COMMANDHANDLE_H
