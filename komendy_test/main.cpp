#include <iostream>
#include <map>
#include <vector>

#include "commandhandler.h"

int main()
{
    std::vector <std::string> mojVector = {"TEST","out"};
    std::cout << "Hello World! " << mojVector[0] <<  std::endl;

    std::cin >> mojVector[0];

    commandHandler mainCommand;

    std::cout << "funkcja: "<< mainCommand.run(mojVector)<< std::endl;


    return 0;
}
