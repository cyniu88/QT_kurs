#include "commandhandler.h"
#include "commandClasses/command_big.h"
#include "commandClasses/commandtest.h"
#include "commandClasses/commandexit.h"

commandHandler::commandHandler()
{
    std::unique_ptr <command> test (new commandTEST("TEST") );
    commandMap.insert( std::make_pair(test->getCommandName(),std::move( test )) );

    std::unique_ptr <command> exit(new commandEXIT("EXIT"));
    commandMap.insert( std::make_pair(exit->getCommandName(),std::move( exit )) );

    std::unique_ptr <command> big (new command_big ("big") );
    commandMap.insert( std::make_pair(big->getCommandName(),std::move( big )) );
}

std::string commandHandler::run(std::vector<std::string> &v,thread_data *my_data)
{
    if (commandMap.find(v[0]) == commandMap.end()){
        return "unknown command: "+ v[0];
    }
    else{
    return   commandMap[v[0]]->execute(v,my_data);
    }
}
