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
        a.readGyro();
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
    a.readGyro();
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