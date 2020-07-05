#include <Zumo32U4.h>

// This section initializes the motors and A button. We can interact with these using the variables "motors" and "buttonA"
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

// This function is run once, when the Zumo starts up
void setup()
{
    // This function waits for the A button to be pressed before continuing.
    buttonA.waitForPress();

    // The "delay" function waits for the specified number of milliseconds to pass (3000 milliseconds = 3 seconds)
    delay(3000);

    // This function causes the motors to drive forwards. The first number is the speed for the left side, the second number is the speed for the right side. You can enter any speed from -400 to 400.
    motors.setSpeeds(200, 200);

    // This function turns the red LED on. It can be turned off again by replacing the 1 with a 0.
    ledRed(1);
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // We currently have no code here, because there isn't anything we want to run multiple times continuously.
}