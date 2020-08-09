#include <Wire.h>
#include <Zumo32U4.h>

class ZumoGyroPosition
{
    L3G a;
    bool b = false;
    int c;
    int32_t d;
    int e;
    double f;
    unsigned long g;
    double h = 0;

public:
    volatile double angle = 0;
    void setup(bool);
    void update();
};