#include "functions.h"
#include <time.h>
#include <sstream>
namespace std {

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}
}
std::string RSHash( )
{
    time_t act_time;
       struct tm * act_date;
       time(&act_time);
       act_date = localtime(&act_time);
       //std::string str="";
       //str = std::to_string(act_date->tm_min+offset)+ std::to_string(act_date->tm_hour)+std::to_string(act_date->tm_wday);

       char buffer[10];
       strftime(buffer,10,"%M%H%w",act_date);
         std::string str(buffer);
   //std::cout<<str<<std::endl;
       unsigned int b    = 378551;
       unsigned int a    = 63689;
       unsigned int hash = 0;

       for(std::size_t i = 0; i < str.length(); i++)
       {
           hash = hash * a + str[i];
           a    = a * b;
       }
       return std::to_string((hash & 0x7FFFFFFF));
}
