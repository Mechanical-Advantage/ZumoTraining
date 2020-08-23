#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;
LSM303 accel;

unsigned long lastDisp = 0; // The last time the LCD was updated

// This function is run once, when the Zumo starts up
void setup()
{
    // This initializes the acceleromter
    Wire.begin();
    accel.init();
    accel.enableDefault();

    // This clears the LCD (in case something was already on the screen when the program starts)
    lcd.clear();

    // This waits until the A button is pressed, updating the LCD accordingly
    lcd.clear();
    lcd.print("Press A");
    buttonA.waitForButton();
    lcd.clear();
}

// This function contains code to be run continuously - it is looped until the Zumo shuts down or is reset
void loop()
{
    // This updates the current accelerometer value
    accel.readAcc();

    // This waits 50 milliseconds to intentionally slow down the control loop
    delay(50); // DO NOT REMOVE

    // This logs the current accelerometer values, comma separated. This means they can be viewed as separate series in the serial plotter.
    Serial.print(accel.a.x); // Log the x acceleration (left-right)
    Serial.print(",");
    Serial.print(accel.a.y); // Log the y acceleration (forward-backward)
    Serial.print(",");
    Serial.println(accel.a.z); // Log the z acceleration (up-down)

    // This should calculate the offset to the target (positive=turn right, negative=turn left). It should be 0 if the robot is facing uphill.
    double offset = 0; // ADD YOUR OWN EXPRESSION

    // This is a simple "on-off" control system, which is prone to oscillation
    if (offset == 0)
    {
        motors.setSpeeds(0, 0);
    }
    else if (offset > 0)
    {
        motors.setSpeeds(150, -150);
    }
    else
    {
        motors.setSpeeds(-150, 150);
    }
}