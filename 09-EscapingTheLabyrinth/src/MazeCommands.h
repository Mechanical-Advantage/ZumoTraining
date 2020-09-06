#include <Zumo32U4.h>
#include "ZumoGyroPosition.h"

#define WHITE_THRESHOLD 200     // The maximum line sensor reading to be read as white
#define BLACK_THRESHOLD 900     // The minimum line sensor reading to be read as black
#define SENSOR_HISTORY_LENGTH 5 // The number of sensor values to average for detecting intersections
#define BASE_SPEED 150          // The base motor speed while line following

#define FOLLOW_GAIN 0.2           // The gain to use while line following
#define FOLLOW_MAX_TURN_SPEED 200 // The maximum turn speed to use while line following
#define FOLLOW_MIN_TIME 350       // The miniumum number of milliseconds to follow the line before scnning for intersections

#define SCAN_DISTANCE 375       // The amount to drive forward after initial detection of an intersection (encoder ticks)
#define SCAN_GAIN 3.5           // The gain to use while driving forwards to scan an intersection
#define SCAN_COMPLETE_MARGIN 20 // The maximum error to finish scan movement (encoder ticks)

#define TURN_GAIN 30           // The gain to use while turning to an angle
#define TURN_MAX_SPEED 150     // The maximum motor speed to use while turning
#define TURN_COMPLETE_MARGIN 2 // The maximum error to finish a turn (degrees)

Zumo32U4LineSensors lineSensors;
ZumoGyroPosition gyro;
Zumo32U4Encoders encoders;
Zumo32U4Motors motors;

unsigned int sensorValues[5];
bool finished = false; // Whether the finish has been detected (never reset)

// Cardinal directions (which are read using the gyro sensor)
enum Direction
{
    North = 1,
    East = 2,
    South = 4,
    West = 8,
};

// Relative directions (which are based on the current gyro value)
enum RelativeDirection
{
    Left = -90,
    Forward = 0,
    Right = 90,
    Backward = 180
};

// Calibrates the line sensors and gyro sensor (should be placed over the calibration area and not moved)
void calibrate()
{
    // Calibrate the line sensors by turning in place
    lineSensors.initFiveSensors();
    motors.setSpeeds(200, -200);
    unsigned long startTime = millis();
    while (millis() - startTime < 2500)
    {
        lineSensors.calibrate();
    }
    motors.setSpeeds(0, 0);

    // Wait until the robot stops moving, then calibrate the gyro sensor
    delay(500);
    gyro.setup(false);
}

// Utility function for ensuring an angle is between -180° and 180°
double simplifyAngle(double angle)
{
    // Bring the angle to between -180° and 180° by shifting in units of 360°
    while (angle < -180)
    {
        angle += 360;
    }
    while (angle > 180)
    {
        angle -= 360;
    }
    return angle;
}

// Utility function for determing cardinal direction from a relative direction
Direction getDirection(RelativeDirection relativeDirection)
{
    // Calculate the angle for the specific relative direction
    double angle = simplifyAngle(gyro.angle + relativeDirection);

    // Find the nearest cardinal direction
    if (angle > -45 && angle <= 45)
    {
        return North;
    }
    else if (angle > 45 && angle <= 135)
    {
        return East;
    }
    else if (angle <= -45 && angle > -135)
    {
        return West;
    }
    else
    {
        return South;
    }
}

// Follows a line until it finds an intersection or dead end, then returns which cardinal directions are available
int followToTurn()
{
    int availableDirections = 0;        // Tracks all available directions (to be updated as directions are confirmed)
    bool scanningIntersection = false;  // Whether the robot is current moving straight forwards to scan an intersection
    unsigned long startTime = millis(); // The time (ms) that line following started
    int sensorHistory[5][SENSOR_HISTORY_LENGTH];

    // Initialize sensor history to all -1s, to keep track of which values are recorderd
    int sensorIndex;
    for (sensorIndex = 0; sensorIndex < 5; ++sensorIndex)
    {
        int i;
        for (i = 0; i < SENSOR_HISTORY_LENGTH; ++i)
        {
            sensorHistory[sensorIndex][i] = -1;
        }
    }

    while (true)
    {
        // Update the line sensors and gyro continuously
        int linePosition = lineSensors.readLine(sensorValues);
        gyro.update();

        // Update sensor history by shifting to the left and adding the new value
        int avgSensorValues[5];
        int sensorIndex;
        for (sensorIndex = 0; sensorIndex < 5; ++sensorIndex)
        {
            int avgTotal = 0;
            int avgCount = 0;

            int i;
            for (i = 0; i < SENSOR_HISTORY_LENGTH - 1; ++i)
            {
                int newValue = sensorHistory[sensorIndex][i + 1];
                sensorHistory[sensorIndex][i] = newValue;

                // Add to averaging totals if a real value
                if (newValue > 0)
                {
                    avgTotal += newValue;
                    avgCount += 1;
                }
            }

            // Add the current sensor value and calculate the average
            sensorHistory[sensorIndex][SENSOR_HISTORY_LENGTH - 1] = sensorValues[sensorIndex];
            avgTotal += sensorValues[sensorIndex];
            avgCount += 1;
            avgSensorValues[sensorIndex] = avgTotal / avgCount;
        }

        if (scanningIntersection) // Currently moving fowards to center over the intersection
        {
            // If a line is seen on the left side, mark the appropriate cardinal direction as available
            if (avgSensorValues[0] > WHITE_THRESHOLD)
            {
                availableDirections |= getDirection(Left);
            }

            // If a line is seen on the right side, mark the appropriate cardinal direction as available
            if (avgSensorValues[4] > WHITE_THRESHOLD)
            {
                availableDirections |= getDirection(Right);
            }

            // Calculate drive speeds using proportional control
            int leftError = SCAN_DISTANCE - encoders.getCountsLeft();
            int rightError = SCAN_DISTANCE - encoders.getCountsRight();

            motors.setSpeeds(
                constrain(leftError * SCAN_GAIN, BASE_SPEED * -1, BASE_SPEED),
                constrain(rightError * SCAN_GAIN, BASE_SPEED * -1, BASE_SPEED));

            // The robot has centered itself over the intersection
            if (abs(leftError) < SCAN_COMPLETE_MARGIN && abs(rightError) < SCAN_COMPLETE_MARGIN)
            {
                // If a line is seen on the center sensor, mark the appropriate cardinal direction as available
                if (avgSensorValues[2] > WHITE_THRESHOLD)
                {
                    availableDirections |= getDirection(Forward);
                }

                // The intersection detection is done
                break;
            }
        }
        else // No intersection detected yet, line following
        {
            if (millis() - startTime < FOLLOW_MIN_TIME)
            {
                // Follow the line (skips to end of if statement)
            }
            else if (avgSensorValues[0] < WHITE_THRESHOLD && avgSensorValues[1] < WHITE_THRESHOLD && avgSensorValues[2] < WHITE_THRESHOLD && avgSensorValues[3] < WHITE_THRESHOLD && avgSensorValues[4] < WHITE_THRESHOLD) // All sensors are seeing white, so this is a dead end
            {
                // The intersection detection is done
                break;
            }
            else if (avgSensorValues[0] > WHITE_THRESHOLD || avgSensorValues[4] > WHITE_THRESHOLD) // The left or right sensor sees a line, so start centering on the intersection
            {
                // Go directly foward, stop line following
                motors.setSpeeds(BASE_SPEED, BASE_SPEED);

                // Reset the encoders
                encoders.getCountsAndResetLeft();
                encoders.getCountsAndResetRight();

                // Change mode for future cycles
                scanningIntersection = true;
                continue;
            }
            else if (avgSensorValues[1] > BLACK_THRESHOLD || avgSensorValues[2] > BLACK_THRESHOLD || avgSensorValues[3] > BLACK_THRESHOLD) // One of the center three sensors sees black, so we've finished the maze
            {
                // Note the maze as finished
                finished = true;

                // The intersection detection is done
                break;
                continue;
            }

            // Nothing unusual happening, follow the line
            int turnSpeed = constrain((linePosition - 2000) * FOLLOW_GAIN, FOLLOW_MAX_TURN_SPEED * -1, FOLLOW_MAX_TURN_SPEED); // Calculate turn speed using proportional control
            motors.setSpeeds(BASE_SPEED + turnSpeed, BASE_SPEED - turnSpeed);                                                  // Run the motors based on the turn speed
        }
    }

    // Marks the origin direction as available
    availableDirections |= getDirection(Backward);

    // Stop the motors in case the user's code takes a significant length of time
    motors.setSpeeds(0, 0);

    // Return the available directions
    return availableDirections;
}

// Turns to the specified cardinal direction
void turn(Direction targetDirection)
{
    // Determine the target angle in degrees
    double targetAngle;
    switch (targetDirection)
    {
    case North:
        targetAngle = 0;
        break;

    case East:
        targetAngle = 90;
        break;

    case South:
        targetAngle = 180;
        break;

    case West:
        targetAngle = -90;
        break;
    }

    // Run proportional control until within the required margin
    double error;
    do
    {
        gyro.update();                                                                     // Update the gyro sensor
        error = simplifyAngle(targetAngle - gyro.angle);                                   // Calculate the current error
        int turnSpeed = constrain(error * TURN_GAIN, TURN_MAX_SPEED * -1, TURN_MAX_SPEED); // Calculate turn speed using proportional control
        motors.setSpeeds(turnSpeed, turnSpeed * -1);                                       // Run the motors based on the turn speed
    } while (abs(error) > TURN_COMPLETE_MARGIN);

    // Stop the motors in case the user's code takes a significant length of time
    motors.setSpeeds(0, 0);
}