#include "gear_box.h"
#include <QDebug>
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
        if (power > 98 || power < -98){
            gearUP();
            qDebug() << "automat!";
        }
        else if ((power > 40 && power < 50 && getGear() == 5 )|| (power <-40 && power > -50 && getGear() == 5) ){
            gearDOWN();
        }
        else if ((power > 30 && power < 40 && getGear() >= 4) ||( power <-30 && power > -40 && getGear() >= 4) ){
            gearDOWN();
        }
        else if ((power > 20 && power < 30 && getGear() >= 3) || (power <-20 && power > -30 && getGear() >= 3) ){
            gearDOWN();
        }
        else if ((power > 10 && power < 20 && getGear() >= 2) || (power <-10 && power > -20 && getGear() >= 2) ){
            gearDOWN();
        }
        else if (power == 0){
            gear=1;
        }
    }
}
