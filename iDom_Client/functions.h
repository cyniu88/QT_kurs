#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstdlib>
#include <iostream>

std::string  RSHash(std::string &data, unsigned int b = 378551, unsigned int a = 63689);
void crypt(std::string & toEncrypt, std::string key,bool encrypted);
#endif // FUNCTIONS_H
