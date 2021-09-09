#include <Zumo32U4.h>
#include "ZumoGyroPosition.h"

Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Encoders encoders;
Zumo32U4IMU imu;
ZumoGyroPosition gyroPos;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;
Zumo32U4ProximitySensors proxSensors;

void setup()
{
    lcd.clear();
    imu.enableDefault();
    lineSensors.initThreeSensors(); // or "initFiveSensors()" in the other configuration
    proxSensors.initThreeSensors(); // or "initFrontSensor()" in the other configuration

    // ----- Uncomment the code before if you need to calibrate the gyro -----
    // lcd.print("Press A");
    // lcd.gotoXY(0, 1);
    // lcd.print("to cal.");
    // buttonA.waitForButton();
    // lcd.clear();
    // lcd.print(" DO NOT");
    // lcd.gotoXY(0, 1);
    // lcd.print(" TOUCH!");
    // ledRed(1);
    // delay(1000);
    // gyro.setup(true);
    // ledRed(0);
    // lcd.clear();
}

void loop()
{
}

// This ensures that the gyro's update method will be called regularly regardless of any other code that may be running
ISR(TIMER3_COMPA_vect) { gyroPos.update(); }