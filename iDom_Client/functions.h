#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdlib.h>

template <typename T>
std::string to_string(T value);
std::string  RSHash(std::string data ="", unsigned int b = 378551, unsigned int a = 63689);

#endif // FUNCTIONS_H
