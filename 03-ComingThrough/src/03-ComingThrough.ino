#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;
Zumo32U4ProximitySensors proxSensors;

// This function is run once, when the Zumo starts up
void setup()
{
    // This clears the LCD (in case something was already on the screen when the program starts)
    lcd.clear();

    // This sets up the proximity sensors to read all three sensors. You can also use "initFrontSensor()" if you don't care about the left and right ones.
    proxSensors.initThreeSensors();
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // This takes a meaurement from the proximity sensors (by sending out pulses and saving which are detected)
    proxSensors.read();

    // This clears the LCD so that the new values can be displayed
    lcd.clear();

    // These print the proximity readings in a grid pattern
    lcd.gotoXY(2, 0);
    lcd.print(proxSensors.countsFrontWithLeftLeds()); // View in front and slight left (front sensor, left emitters)

    lcd.gotoXY(4, 0);
    lcd.print(proxSensors.countsFrontWithRightLeds()); // View in front and slight right (front sensor, right emitters)

    lcd.gotoXY(0, 1);
    lcd.print(proxSensors.countsLeftWithLeftLeds()); // View directly to the left (left sensor, left emitters)

    lcd.gotoXY(2, 1);
    lcd.print(proxSensors.countsLeftWithRightLeds()); // Wider view, particularly to the left (left sensor, right emitters)

    lcd.gotoXY(4, 1);
    lcd.print(proxSensors.countsRightWithLeftLeds()); // Wider view, particularly to the right (right sensor, left emitters)

    lcd.gotoXY(6, 1);
    lcd.print(proxSensors.countsRightWithRightLeds()); // View directly to the right (right sensor, right emitters)

    // This starts the motors when the A button is pressed
    if (buttonA.isPressed())
    {
        motors.setSpeeds(150, 150);
    }

    // This stops the motors if we get too close to a wall
    if (proxSensors.countsFrontWithLeftLeds() + proxSensors.countsFrontWithRightLeds() > 9) // We add together these values to evenly sense objects slightly to the left or right
    {
        motors.setSpeeds(0, 0);
    }

    // This waits before updating the display (if we updated as fast as possible, the values would not be visible)
    delay(150);
}