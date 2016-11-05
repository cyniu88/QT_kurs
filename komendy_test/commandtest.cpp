#include "commandtest.h"

commandTEST::commandTEST(std::string name):command(name)
{

}

std::string commandTEST::execute(std::vector<std::string> &v)
{
    std::cout << " jestem w execute command TEST! "<< v[0]<< std::endl;

    return v[0]+" "+v[1];
}
