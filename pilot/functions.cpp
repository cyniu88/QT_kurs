#include "functions.h"

int map_f(double value, int from_min, int from_max, int to_min, int to_max)
{
    return (value - from_min) * (to_max - to_min)/(from_max - from_min) + to_min;
}

int foo()
{
    return 6;
}
