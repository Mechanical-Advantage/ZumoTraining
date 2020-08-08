/*
PLEASE READ BEFORE CONTINUING

This code is responsible for reading the Zumo's position using the gyro sensor. This task will be the focus of a later challenge, and solving that problem yourself will be a useful learning experience. As such, we recommend that you ignore the contents of this file for the time being. Thank you!
*/

#include "ZumoGyroPosition.h"

void ZumoGyroPosition::setup(bool g)
{
    Wire.begin();
    a.init();
    a.enableDefault();
    if (g)
    {
        cli();
        TCCR3A = 0;
        TCCR3B = 0;
        TCNT3 = 0;
        OCR3A = 77;
        TCCR3B = bit(WGM32) | bit(CS32) | bit(CS30);
        TIMSK3 |= (1 << OCIE3A);
        sei();
    }
    unsigned long h = millis();
    while (millis() - h < 4000)
    {
        a.read();
        c += 1;
        d += a.g.z;
        if (millis() - h > 1000 && abs(a.g.z - (d / c)) > 100)
        {
            h = millis();
            d = 0;
            c = 0;
        }
    }
    b = true;
}

void ZumoGyroPosition::update()
{
    if (!b)
    {
        return;
    }
    if (e == NULL)
    {
        e = micros();
    }
    interrupts();
    a.read();
    unsigned long i = micros();
    double j = a.g.z - ((double)d / (double)c);
    if (abs(j) < 30)
    {
        j = 0;
    }
    j /= -117.69;
    double k = (double)(i - e) / 1000000;
    angle += (j * k) - ((j - f) * k * 0.5);
    e = i;
    f = j;
}