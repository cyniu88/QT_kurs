#include "commandexit.h"

commandEXIT::commandEXIT(std::string name):command(name)
{

}

std::string commandEXIT::execute(std::vector<std::string> &v)
{
    std::cout << " jestem w execute command EXIT! "<< v[0]<< std::endl;

    return v[0]+" "+v[1];
}
