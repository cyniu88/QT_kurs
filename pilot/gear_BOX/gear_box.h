#ifndef GEAR_BOX_H
#define GEAR_BOX_H


class Gear_Box
{
    int _howManyGear;
    int gear = 1;

public:
    Gear_Box(int _howManyGear);
    int getGear();
    int howManyGear();
    void gearUP();
    void gearDOWN();
    void setAutomaticWork(bool v);
    void automaticGearBoxHandle(int power);

    bool automaticWorkFlag= true;
};

#endif // GEAR_BOX_H
