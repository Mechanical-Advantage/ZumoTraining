#include <Zumo32U4.h>

#define BLACK_THRESHOLD 300 // Any line sensor readings above this value are black. For this challenge, the line sensors are being read without calibration, meaning the values are slightly different than you might be used to (depending on lighting).

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Buzzer buzzer;

Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;
// You are free to instantiate more sensors here (accelerometer, gyro, encoders, etc.)

unsigned int lineSensorValues[3];

void setup()
{
    // This initializes the line sensors and proximity sensors
    lineSensors.initThreeSensors();
    proxSensors.initThreeSensors();

    // This resets the LEDs in case any are currently lit
    ledYellow(0);
    ledGreen(0);
    ledRed(0);

    // This writes the initial instruction text to the LCD, indicating the delay for each btuton
    lcd.clear();
    lcd.print("A=5");
    lcd.gotoXY(4, 0);
    lcd.print("B=15");
    lcd.gotoXY(0, 1);
    lcd.print("C=30");

    // This waits for one of the buttons to be pressed, then records the correct timer length in seconds
    unsigned long timerLength;
    while (true)
    {
        if (buttonA.getSingleDebouncedPress())
        {
            timerLength = 5;
            break;
        }
        if (buttonB.getSingleDebouncedPress())
        {
            timerLength = 15;
            break;
        }
        if (buttonC.getSingleDebouncedPress())
        {
            timerLength = 30;
            break;
        }
    }

    // This loop repeats for each second of the timer
    int i;
    for (i = 0; i < timerLength; ++i) // Loop for the correct length
    {
        // This prints the remaining time to the LCD
        lcd.clear();
        lcd.print(timerLength - i);

        // Creates a "beep" and turns on an LED based on the current time
        if (timerLength - i > 3) // Most of the countdown uses a low pitch/volume and the yellow LED
        {
            buzzer.playFrequency(450, 250, 10);
            ledYellow(1);
        }
        else // The final three seconds are a higher pitch/volume with the red LED
        {
            buzzer.playFrequency(700, 250, 15);
            ledRed(1);
        }

        delay(250);   // Wait for the "beep" to stop
        ledRed(0);    // Turn off the red LED
        ledYellow(0); // Turn off the yellow LED
        delay(750);   // Wait for the rest of the second
    }
    lcd.clear(); // Clear the LCD after the countdown

    // This starts the robot moving fowards
    motors.setSpeeds(200, 200);
}

void loop()
{
    // This reads the line and proximity sensors
    lineSensors.read(lineSensorValues);
    proxSensors.read();

    // ADD CODE HERE
}