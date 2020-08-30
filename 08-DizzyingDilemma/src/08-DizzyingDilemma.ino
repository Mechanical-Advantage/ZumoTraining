#include <Wire.h>
#include <Zumo32U4.h>

#define DISPLAY_INTERVAL 100 // The number of milliseconds to wait before updating the LCD and logging to serial
#define PROPORTIONAL_GAIN 30 // The gain to use when correcting to 0°

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;
L3G gyro;

unsigned long readTime = 0;     // The time (in microseconds) that the current gyro reading was taken
unsigned long lastReadTime = 0; // The time (in microseconds) that the previous gyro reading was taken
double angle = 0;               // The current gyro angle

unsigned long lastDisp = 0;   // The last time the LCD was updated
bool runProportional = false; // Whether to run the proportional control system

// This function is run once, when the Zumo starts up
void setup()
{
    // This initializes the gyro
    Wire.begin();
    gyro.init();
    gyro.enableDefault();

    // This clears the LCD (in case something was already on the screen when the program starts)
    lcd.clear();

    // This waits until the A button is pressed, updating the LCD accordingly
    lcd.clear();
    lcd.print("Press A");
    buttonA.waitForButton();
    lcd.clear();

    // Update read time to prevent a large time delta on the first cycle
    readTime = micros();
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // This updates the current gyro value
    gyro.read();

    // This updates the two variables tracking sensor read times
    lastReadTime = readTime; // Set the previous read time
    readTime = micros();     // Update the current read time

    // This converts the gyro reading to degrees per second (dps)
    double dps = gyro.g.z / -114.0;

    // This update the current angle based on the user's logic
    updateAngle(dps);

    // This displays the current calculated angle and logs the angular velocty over serial
    if (millis() - lastDisp > DISPLAY_INTERVAL) // Only update if enough time has passed since last update
    {
        lastDisp = millis(); // Update time of last update

        // This updates the angle on the LCD
        lcd.clear();
        lcd.print(angle);

        // This logs the current gyro value over serial
        Serial.println(dps);
    }

    // Run the proportional control system to bring the robot to 0° (if applicable)
    if (runProportional)
    {
        int turnSpeed = angle * PROPORTIONAL_GAIN;   // Calculate turn speed using proportional control
        motors.setSpeeds(turnSpeed * -1, turnSpeed); // Run at calculated speed
    }
    else if (buttonA.isPressed()) // When the A button is pressed, enable the proportional control system
    {
        runProportional = true;
    }
}

// This function should update the "angle" variable based on the current angular velocity
void updateAngle(double dps)
{
    angle += 0; // ADD CODE HERE
}