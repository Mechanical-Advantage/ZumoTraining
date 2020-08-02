#include <Zumo32U4.h>

// These lines define two constants, which can be refered to in the code and never change. Making these values constants instead of including them directly in the code makes it easier to adjust them later.
#define WHITE_THRESHOLD 150  // The cutoff value for distinguising white (less than this value is white, higher is gray/black)
#define DISPLAY_INTERVAL 250 // The number of milliseconds to wait before updating the LCD

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;

bool enableTimer;             // Whether to stop when the robot reaches the end
unsigned long startTime;      // The time the robot started line following
unsigned long lastDisp = 0;   // The last time the LCD was updated
unsigned int sensorValues[3]; // The current readings from the line sensors

// This function is run once, when the Zumo starts up
void setup()
{
    // This sets up the line sensors to read the three sensors avilable by default.
    lineSensors.initThreeSensors();

    // This writes the inital text to the LCD, telling the user to press A
    lcd.clear();
    lcd.print("Press A");
    lcd.gotoXY(0, 1);
    lcd.print("to cal.");

    // This waits for the A button to be pressed, then updates the LCD and red LED
    buttonA.waitForButton();
    lcd.clear();
    ledRed(1);

    // This calibrates the line sensors by spinning in place (moving the sensors on and off the line)
    delay(1000);                       // Wait one second for the user to remove their hand
    motors.setSpeeds(200, -200);       // Start turning to the right
    unsigned long calStart = millis(); // Save the time that the turn starts ("millis()" returns the # of milliseconds since the program started)
    while (millis() - calStart < 1750) // Wait for a full turn to complete ("millis() - calStart" is the # of milliseconds since the loop started. The loop should continue as long as this is less than 1750 - 1.75 seconds)
    {
        lineSensors.calibrate(); // Update the calibration based on the current data
    }
    motors.setSpeeds(0, 0); // Stop the motors spinning
    ledRed(0);              // Reset the red LED

    // This updates the LCD post-calibration
    lcd.clear();
    lcd.print("A=timer");
    lcd.gotoXY(0, 1);
    lcd.print("B=test");

    // This waits for the A button or B button to be pressed, then saves whether to enable the timer
    while (true) // Loop until interrupted
    {
        if (buttonA.getSingleDebouncedPress()) // Run if button A has been pressed and released
        {
            enableTimer = true; // Mark the timer as "enabled" - the robot will stop at the gray square
            break;              // Exit the loop
        }
        if (buttonB.getSingleDebouncedPress()) // Run if button B has been pressed and released
        {
            enableTimer = false; // Mark the timer as "disabled" - the robot will not stop at the gray square
            break;               // Exit the loop
        }
    }

    // This updates the LCD and runs until the robot leaves the gray square
    lcd.clear();                // Clear the previous message from the LCD
    delay(1000);                // Wait one second for the user to remove their hand
    motors.setSpeeds(100, 100); // Start moving fowards slowly
    do                          // This "do-while" structure acts as a while loop, but runs the code inside first
    {
        // This reads the line sensor values and saves them the array "sensorValues"
        lineSensors.readCalibrated(sensorValues);
    } while (sensorValues[0] > WHITE_THRESHOLD && sensorValues[1] > WHITE_THRESHOLD && sensorValues[2] > WHITE_THRESHOLD); // Keep looping as long as all of the sensors see white

    motors.setSpeeds(0, 0); // Stops the motors after leaving the start square

    // This saves the time that the robot left the start square
    startTime = millis();
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // This takes meaurements from the line sensors and saves them to the array "sensorValues"
    lineSensors.readCalibrated(sensorValues);

    // This checks for the ending box and displays the final time
    if (enableTimer && millis() - startTime > 3000 && sensorValues[0] > WHITE_THRESHOLD && sensorValues[1] > WHITE_THRESHOLD && sensorValues[2] > WHITE_THRESHOLD) // If timer enabled, check when none of the sensors see white and at least 3 seconds have passed
    {
        unsigned long endTime = millis(); // Save the ending time
        motors.setSpeeds(0, 0);           // Stop the motors
        ledGreen(1);                      // Update the green LED
        lcd.clear();
        lcd.print("Time");
        lcd.gotoXY(0, 1);
        lcd.print((double)(endTime - startTime) / 1000); // Calculate the final time

        // Wait forever
        while (true)
        {
        }
    }

    // This displays the current line sensor readings
    if (millis() - lastDisp > DISPLAY_INTERVAL) // Only update if enough time has passed since last update
    {
        lastDisp = millis(); // Update time of last update
        lcd.clear();
        lcd.print(sensorValues[0]); // Display the reading from the left sensor
        lcd.gotoXY(2, 1);
        lcd.print(sensorValues[1]); // Display the reading from the center sensor
        lcd.gotoXY(4, 0);
        lcd.print(sensorValues[2]); // Display the reading from the right sensor
    }

    // Runs your code to update the motor speeds
    lineFollow();
}

// Runs in "loop" to update the motor speeds. Add your line following code here.
void lineFollow()
{
    // Here, you should read the line sensor values and update the motor speeds accordingly.
    // You can see examples of reading each sensor value on lines 111-115

    // This is a simple example that runs as long as the center sensor is on the line:
    // if (sensorValues[1] > WHITE_THRESHOLD) // True if on gray/black, false if on white
    // {
    //     motors.setSpeeds(200, 200);
    // }
    // else
    // {
    //     motors.setSpeeds(0, 0);
    // }
}