#include <Zumo32U4.h>
#include "MazeCommands.h"

Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;

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

    delay(1000); // Wait one second for the user to remove their hand
    calibrate(); // Calibrate the line sensors and gyro
    ledRed(0);   // Reset the red LED

    // This writes the next set of text to the LCD
    lcd.clear();
    lcd.print("Press A");
    lcd.gotoXY(0, 1);
    lcd.print("to start");

    // Wait for the A button to be pressed again
    buttonA.waitForButton();
    lcd.clear();
    delay(1000);

    // Reset the gyro to its starting angle (normally, this isn't necessary but could be changed if the robot doesn't start facing north)
    gyro.angle = 0;
}

void loop()
{
    int availableDirections = followToTurn(); // Follows a line until it finds an intersection or dead end, then returns which cardinal directions are available

    // This writes the available directions to the screen
    lcd.clear();
    if (availableDirections & North) // This syntax checks if "North" is one of the available directions (we can discuss how this works in more detail for those interested!)
    {
        lcd.print("N");
    }

    lcd.gotoXY(1, 0);
    if (availableDirections & East)
    {
        lcd.print("E");
    }

    lcd.gotoXY(2, 0);
    if (availableDirections & South)
    {
        lcd.print("S");
    }

    lcd.gotoXY(3, 0);
    if (availableDirections & West)
    {
        lcd.print("W");
    }

    // This writes whether the end was reached
    lcd.gotoXY(0, 1);
    lcd.print(finished ? "Done!" : "Cont."); // "finished" stores whether the end has been detected

    // When the A button is pressed, turn to the left.
    buttonA.waitForButton();
    delay(1000);
    Direction leftDirection = getDirection(Left); // The turn function requires a cardinal direction, so we can use the "getDirection" function to find a cardinal direction based on a relative direction ("Left", "Forward", "Right", or "Backward").
    turn(leftDirection);                          // Turn to the correct cardinal direction
}