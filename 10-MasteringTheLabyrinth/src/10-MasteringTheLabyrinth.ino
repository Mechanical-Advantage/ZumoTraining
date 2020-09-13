#include <Zumo32U4.h>
#include "MazeCommands.h"

Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;

// This class defines the path the robot takes, so it stores a sequence of turns (the data) and methods for using that data (the interface)
class Path
{
private:                          // This "private" section contains all of the data/methods that can only be accessed within the class.
    CardinalDirection turns[100]; // This array stores the sequence of turns (recorded during the initial solve and replayed during the repeat solve)

public: // This "public" section contains all of the data/methods that can be accessed outside the class.
    // This method is called during the initial solve for every turn made. It should record the turns (or a subset of them) in the "turns" array. You may need to add more data to the class to accomplish this.
    void addTurn(CardinalDirection newDirection)
    {
        // ADD CODE HERE
    }

    // This method is called during the repeat solve to retrieve the sequence of turns. It should iterate through the "turns" array and return one direction each time. You may need to add more data to the class to accomplish this.
    CardinalDirection getNextTurn()
    {
        // ADD CODE HERE

        return North; // This method must return a cardinal direction. You should comment out this line and replace it with your own cod
    }
};

Path path;                // An instance of the "Path" class. This is the object the rest of the code interacts with to use the above methods
bool repeatSolve = false; // Stores whether to run the initial solve or repeat solve

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

    if (finished) // If the finish was reached, wait for the A button and start the repeat solve.
    {
        // If running repeat solve, stop code
        while (repeatSolve)
        {
        }

        // Not on repeat solve, wait for A button
        buttonA.waitForButton();
        delay(1000);

        finished = false;   // Reset "finished" so that the solve doesn't exit immediately
        repeatSolve = true; // Set "repeatSolve" to true to change the solve logic
        ledGreen(1);        // Turn on the green LED to indicate that the repeat solve is running
        gyro.angle = 0;     // Reset the gyro angle since the robot was moved by hand back to the start
    }
    else // If the finish hasn't been reached, run the initial solve or repeat solve.
    {
        CardinalDirection direction; // The direction to turn (changes depending on whether this is the initial or repeat solve)

        if (repeatSolve) // If running the repeat solve, get the next turn from the "path" object
        {
            direction = path.getNextTurn();
        }
        else // If running the initial solve, get the next turn using the user's algorithm
        {
            direction = getCardinalDirection(getSolveDirection(availableDirections)); // Get the next turn and convert it to a cardinal direction
            path.addTurn(direction);                                                  // Add it to the "path" object
        }

        // Turn in the calculated direction
        turn(direction);
    }
}

// This method is called during the inital solve to retrieve the next turn based on the available directions. This is the same problem that you solved during the previous challenge, so you can copy your code! (Though note that this function needs to RETURN the new direction and NOT TURN TO IT)
RelativeDirection getSolveDirection(int availableDirections)
{
    // ADD CODE HERE (You can copy it from the previous challenge!)

    return Forward; // DO NOT TURN TO THE NEW DIRECTION. This function must instead return a relative direction. You should comment out this line and replace it with your own code
}