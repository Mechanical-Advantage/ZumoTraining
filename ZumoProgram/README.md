# Zumo Program Template

This template can be used for developing any Zumo program you like. It includes some basic setup and the gyro position class. See the bonus challenges below for suggestions of possible projects.

## Bonus Challenge #1: High Tech Navigator

Use the magnetometer to keep the robot facing north. X and Y values from the magnetometer can be retrieved using `imu.m.x` and `imu.m.y`. You'll need to understand what these values mean, combine them into a heading, and control to north using the motors. Keep in mind that the magnetometer is much more susceptible to noise than many of the other sensors we've been using, so you may need to do extra processing on the data to make it usable.

## Bonus Challenge #2: Virtual Breadcrumbs

Using the gyro and encoders, track the robot's position on a coordinate plane as it is pushed by hand. This process is called "odometry," and should continuously generate an X and Y coordinate. Once the user presses A, the robot should use the calculated position to autonomously drive back to its starting position.