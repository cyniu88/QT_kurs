#ifndef FORCE_BACK_H
#define FORCE_BACK_H

#include "../libs/android_functions/android_interface/android_interface.h"

class force_back
{
public:
    force_back();
    void makeForce();
private:
    android_interface droid;
};

#endif // FORCE_BACK_H
