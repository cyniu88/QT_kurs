#include "functions.h"
#include <sstream>

int map_f(double value, int from_min, int from_max, int to_min, int to_max)
{
    return (value - from_min) * (to_max - to_min)/(from_max - from_min) + to_min;
}

int foo()
{
    return 6;
}


std::string to_stringAndroid(int value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}





std::string to_Std_string_4(int i)
{
    std::ostringstream ss;
    ss << i;
    std::string s =  ss.str();

    for (int i = s.size() ; i < 4; ++i)
    {
        s+=" ";
    }
    return s;

}
