#include <Zumo32U4.h>

// This section initializes the motors, A button, and LCD. We can interact with these using the variables "motors," "buttonA," and "lcd"
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;

// This function is run once, when the Zumo starts up
void setup()
{
    // This section shows the program name and directions on the LCD
    lcd.clear();            // Clears the LCD and puts the cursor at the beginning of the first line
    lcd.print("Start Eng"); // Writes "Start Eng" on the first line
    lcd.gotoXY(0, 1);       // Moves the cursor to the start of the second line
    lcd.print("Press A");   // Writes "Press A" on the second line

    // This function waits for the A button to be pressed before continuing, then prints "Go!!!!" on the LCD.
    buttonA.waitForPress();
    lcd.clear();
    lcd.print("Go!!!!");

    // The "delay" function waits for the specified number of milliseconds to pass (3000 milliseconds = 3 seconds)
    delay(3000);

    // This function causes the motors to drive forwards. The first number is the speed for the left side, the second number is the speed for the right side. You can enter any speed from -400 to 400.
    motors.setSpeeds(200, 200);

    // This function turns the red LED on. It can be turned off again by replacing the 1 with a 0.
    ledRed(1);

    // This sections shows a final message on the LCD
    lcd.clear();
    lcd.print("Done");
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // We currently have no code here, because there isn't anything we want to run multiple times continuously.
}