#ifndef DATA_H
#define DATA_H

#include <fstream>
#include<cstring>
#include<iostream>
#include <ctime>

using namespace std;

struct record
{
    struct tm data;
    int id;
    float degreesI;
    int smog;
    float degreesO;
};

#endif // DATA_H
