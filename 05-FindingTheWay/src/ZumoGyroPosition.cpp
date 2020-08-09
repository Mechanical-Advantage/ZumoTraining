/*
PLEASE READ BEFORE CONTINUING

This code is responsible for reading the Zumo's position using the gyro sensor. This task will be the focus of a later challenge, and solving that problem yourself will be a useful learning experience. As such, we recommend that you ignore the contents of this file for the time being. Thank you!
*/

#include "ZumoGyroPosition.h"

void ZumoGyroPosition::setup(bool i)
{
    Wire.begin();
    a.init();
    a.enableDefault();
    if (i)
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
    unsigned long j = millis();
    while (millis() - j < 5000)
    {
        a.read();
        c += 1;
        d += a.g.z;
        if (millis() - j > 1000)
        {
            e += 1;
            f += abs(a.g.z - ((double)d / (double)c));
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
    if (g == NULL)
    {
        g = micros();
    }
    interrupts();
    a.read();
    unsigned long k = micros();
    double l = a.g.z - ((double)d / (double)c);
    if (abs(l) < (f / (double)e) * 3.5)
    {
        l = 0;
    }
    l /= -117.69;
    double m = (double)(k - g) / 1000000;
    angle += (l * m) - ((l - h) * m * 0.5);
    g = k;
    h = l;
}