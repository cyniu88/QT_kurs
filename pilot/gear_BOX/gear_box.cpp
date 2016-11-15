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

void Gear_Box::setAutomaticWork(bool v)
{
    automaticWorkFlag = v;
}

void Gear_Box::automaticGearBoxHandle(int power)
{
    if (automaticWorkFlag == true){
        if (power > 98){
            gearUP();
        }
    }
}
