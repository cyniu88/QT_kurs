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
};

#endif // GEAR_BOX_H
