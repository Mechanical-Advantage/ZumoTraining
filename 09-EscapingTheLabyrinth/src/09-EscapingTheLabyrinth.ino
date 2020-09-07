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
    int availableDirections = followToTurn(); // Follows a line until it finds an intersection or dead end, then returns which directions are available

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

    // In additon to reading cardinal directions, the "availableDirections" includes relative directions
    lcd.gotoXY(0, 1);
    if (availableDirections & Forward)
    {
        lcd.print("F");
    }

    lcd.gotoXY(1, 1);
    if (availableDirections & Right)
    {
        lcd.print("R");
    }

    lcd.gotoXY(2, 1);
    if (availableDirections & Backward)
    {
        lcd.print("B");
    }

    lcd.gotoXY(3, 1);
    if (availableDirections & Left)
    {
        lcd.print("L");
    }

    // This indicates whether the end was reached
    ledGreen(finished ? 1 : 0); // "finished" stores whether the end has been detected

    // Wait for the A button to be pressed, then print the cardinal direction to turn
    buttonA.waitForButton();
    lcd.clear();
    lcd.print("Going");
    lcd.gotoXY(0, 1);
    switch (getCardinalDirection(Left)) // "getCardinalDirection" can be used to convert relative directions to cardinal directions
    {
    case North:
        lcd.print("north");
        break;

    case East:
        lcd.print("east");
        break;

    case South:
        lcd.print("south");
        break;

    case West:
        lcd.print("west");
        break;
    }

    // Wait one second, then turn
    delay(1000);
    turn(Left); // Turn to the left. You can also use this function to turn to a specified cardinal direction
}

void iterate()
{
    int availableDirections = followToTurn();
    CardinalDirection origin = getCardinalDirection(Backward);

    CardinalDirection possibleDirections[4] = {North,
                                               East,
                                               South,
                                               West};
    for (int i = 0; i < 4; ++i)
    {
        if (possibleDirections[i] != origin) // Don't go the same way we came in
        {
            if (availableDirections & possibleDirections[i]) // Only go if available
            {
                turn(possibleDirections[i]);
                iterate();
                if (finished)
                {
                    break;
                }
            }
        }
    }

    turn(origin);
    followToTurn();
}