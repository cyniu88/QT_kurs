#include "functions.h"
#include <ctime>
#include <sstream>
#include <string>

std::string RSHash(std::string &data, unsigned int b, unsigned int a )
{
    time_t act_time;
    struct tm * act_date;
    time(&act_time);
    act_date = localtime(&act_time);

    char buffer[10];
    strftime(buffer,10,"%M%H%w",act_date);
    std::string str(buffer);
    str += data;
    unsigned int hash = 0;

    for(char i : str)
    {
        hash = hash * a + static_cast<unsigned int>(i);
        a    = a * b;
    }
    std::stringstream key;
    key << (hash & 0x7FFFFFFF);
    return key.str();
}

void crypt (std::string & toEncrypt, std::string key,bool encrypted)
{
    if (!encrypted){
        return;
    }
    unsigned int keySize = key.size()-1;

    for (char & i : toEncrypt)
    {

        if (keySize==0) keySize = key.size()-1;
        else --keySize;
        i ^= key[keySize];
    }
}
