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
std::string RSHash(std::string data, unsigned int b, unsigned int a )
{
    time_t act_time;
    struct tm * act_date;
    time(&act_time);
    act_date = localtime(&act_time);

    char buffer[10];
    strftime(buffer,10,"%M%H%w",act_date);
    std::string str(buffer);
    str+=data;
    unsigned int hash = 0;

    for(std::size_t i = 0; i < str.length(); i++)
    {
        hash = hash * a + str[i];
        a    = a * b;
    }
    return std::to_string((hash & 0x7FFFFFFF));
}

void crypt (std::string & toEncrypt, std::string key)
{
  unsigned int keySize = key.size();

  for (unsigned int i = 0; i < toEncrypt.size (); i++)
    {
      toEncrypt[i] ^= key[keySize];
      std::cout << key[keySize];

      if (keySize==0){
          keySize = key.size();
      }
      else{
      --keySize;
      }
    }

    std::cout << '!' << key.size();
}
