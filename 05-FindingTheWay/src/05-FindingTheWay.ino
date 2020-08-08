#include <Zumo32U4.h>
#include "ZumoGyroPosition.h"

#define DISPLAY_INTERVAL 100 // The number of milliseconds to wait before updating the LCD

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;
ZumoGyroPosition gyro;

unsigned long lastDisp = 0; // The last time the LCD was updated

// This function is run once, when the Zumo starts up
void setup()
{
    // This writes the inital text to the LCD, telling the user to press A
    lcd.clear();
    lcd.print("Press A");
    lcd.gotoXY(0, 1);
    lcd.print("to cal.");

    // This waits for the A button to be pressed, then updates the LCD and red LED
    buttonA.waitForButton();
    lcd.clear();
    lcd.print(" DO NOT");
    lcd.gotoXY(0, 1);
    lcd.print(" TOUCH!");
    ledRed(1);

    delay(1000);      // Wait one second for the user to remove their hand
    gyro.setup(true); // Calibrates the gyro sensor, meaning it must remain still ("true" indicates that the "update" method will be called automatically - see end of file)
    lcd.clear();      // Remove the warning text from the LCD
    ledRed(0);        // Reset the red LED
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // This displays the current gyro value
    if (millis() - lastDisp > DISPLAY_INTERVAL) // Only update if enough time has passed since last update
    {
        lastDisp = millis(); // Update time of last update
        lcd.clear();
        lcd.print(gyro.angle);
    }

    if (buttonA.getSingleDebouncedPress()) // Runs once after the A button is pressed
    {
        gyro.angle = 0; // Resets the gyro angle to 0
    }
}

// This ensures that the "update" method will be called regularly regardless of any other code that may be running
ISR(TIMER3_COMPA_vect) { gyro.update(); }