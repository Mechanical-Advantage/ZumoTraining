#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4Encoders encoders;
Zumo32U4LCD lcd;

// This function is run once, when the Zumo starts up
void setup()
{
    // This clears the LCD (in case something was already on the screen when the program starts)
    lcd.clear();
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // This clears the LCD so that the new values can be displayed
    lcd.clear();

    // This displays the encoder value for the left side on the first row of the LCD
    lcd.print(encoders.getCountsLeft());

    // This moves to the second line (so as not to override the left value)
    lcd.gotoXY(0, 1);

    // This displays the encoder value for the right side of the second row of the LCD
    lcd.print(encoders.getCountsRight());

    // This resets the encoder values for both sides when the A button is pressed
    if (buttonA.isPressed()) {
        encoders.getCountsAndResetLeft();
        encoders.getCountsAndResetRight();
    }

    // This waits before updating the display (if we updated as fast as possible, the values would not be visible)
    delay(150);
}