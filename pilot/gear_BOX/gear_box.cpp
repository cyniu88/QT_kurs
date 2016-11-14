#include "gear_box.h"

Gear_Box::Gear_Box(int howManyGear):_howManyGear(howManyGear)
{

}

int Gear_Box::getGear()
{
    return gear;
}

int Gear_Box::howManyGear()
{
    return _howManyGear;
}

void Gear_Box::gearUP()
{
    if (gear < _howManyGear){
        gear++;
    }
}

void Gear_Box::gearDOWN()
{
    if (gear > 1){
        gear--;
    }
}
