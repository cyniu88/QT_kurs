#include "commandhandler.h"

commandHandler::commandHandler()
{
    std::unique_ptr <command> test(new commandTEST("TEST") );
    commandMap.insert( std::make_pair(test->getCommandName(),std::move( test )) );

    std::unique_ptr <command> exit(new commandEXIT("EXIT"));
    commandMap.insert( std::make_pair(exit->getCommandName(),std::move( exit )) );
}

std::string commandHandler::run(std::vector<std::string> &v)
{
    if (commandMap.find(v[0]) == commandMap.end()){
        return "unknown command: "+ v[0];
    }
    else{
    return "result: "+  commandMap[v[0]]->execute(v);
    }
}
