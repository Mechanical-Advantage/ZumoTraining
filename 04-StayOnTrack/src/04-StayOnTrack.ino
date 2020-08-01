#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;

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
    while (millis() - calStart < 1750) // Wait for a full turn to complete
    {
        lineSensors.calibrate(); // Update the calibration based on the current data
    }
    motors.setSpeeds(0, 0); // Stop the motors spinning
    ledRed(0);              // Reset the red LED

    // This updates the LCD post-calibration
    lcd.clear();
    lcd.print("Press A");
    lcd.gotoXY(0, 1);
    lcd.print("to start");

    // This waits for the A button to be pressed, then moves forward off of the start square
    buttonA.waitForButton();
    motors.setSpeeds(100, 100); // Start moving fowards slowly
    while (true)                // Loop until interrupted
    {
        lineSensors.readCalibrated(sensorValues);                                    // Read the line sensor values and save to the array "sensorValues"
        if (sensorValues[0] < 150 || sensorValues[1] < 150 || sensorValues[2] < 150) // Check for when one of the sensors sees white
        {
            break; // Exit the infinite loop
        }
    }
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
    if (sensorValues[0] > 150 && sensorValues[1] > 150 && sensorValues[2] > 150) // Check when none of the sensors see white
    {
        unsigned long endTime = millis(); // Save the ending time
        motors.setSpeeds(0, 0);           // Stop the motors
        ledGreen(1);                      // Update the greenLED
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
    if (millis() - lastDisp > 250) // Only update if more than 250 ms since last update
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
}