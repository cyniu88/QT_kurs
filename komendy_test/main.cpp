#include <iostream>
#include <map>
#include <vector>

#include "commandhandler.h"
thread_data *t;
int main()
{
    std::vector <std::string> mojVector = {"TEST","55"};
    std::cout << "Hello World! " << mojVector[0] <<  std::endl;

    std::cin >> mojVector[0];

    commandHandler mainCommand;

    std::cout << "funkcja: "<< mainCommand.run(mojVector,t)<< std::endl;


    return 0;
}
