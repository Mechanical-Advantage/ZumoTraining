# Challenge #7: Look Up!

## Overview

In this challenge, you will learn to utilize another of the Zumo's inertial sensors. You'll use the accelerometers in conjunction with proportional control to make the robot turn upwards on a tilted surface.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* You should read through [this article](https://learn.sparkfun.com/tutorials/accelerometer-basics/all), which provides an introduction to the accelerometers.

## Challenge

1. Download "07-LookUp.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "07-LookUp.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Run the template code and press the A button to start. The Zumo will begin logging the three accelerometer values over serial (x, y, and z). Open the serial plotter to see these graphed as three series. Try to understand how the robot's position/motion affects each of these values by moving it around - remember that the accelerometer reads both static forces (gravity) and dynamic forces (movement).

4. The goal of the challenge is to make the robot turn to face uphill on a tilted surface. See [this video](https://drive.google.com/file/d/1Mp3jGwwZmozo-XtuSfCt7Z7jfB07bQy0/view?usp=sharing) for an example. The template code includes a simple "on-off" control system, which attempts to bring the offset to 0. The offset is the input to a control system - the difference between the current value and target value. The offset is currently always set to 0, but you should replace it with a formula that computes it from one or more of the accelerometer readings such that:

    * When the offset is positive, the robot should turn right to face uphill.

    * When the offset is zero, the robot is facing uphill and should not move.

    * When the offset is negative, the robot should turn left to face uphill.

    (This is simpler than it might appear - you can solve it using only a single accelerometer reading :wink:)

5. Once you have the code to calculate an appropriate offset, the current control system will be capable to turning the robot to face uphill. However, it is very prone to oscillation (moving back and forth across the target). In part, this is because the control loop is delayed by 50 milliseconds meaning it cannot respond quickly. This limited update speed is reminiscent of the control loops we might include in FRC robot code. The problems of the current approach can be fixed by moving to [proportional control](../02-PrecisionPlease/PostChallenge.md#approach-4-proportional-control-low-gain). Remember, proportional control means that the output speed is calculated as the offset times a constant. This means that the speed is reduced as the target value is approached. **You should replace the current control system with proportional control.**

6. Proportional control will behave very differently depending on the gain (constant factor) you choose. If the gain is too low, the robot won't be able to reach the target. However, if the gain is too high, the robot may oscillate, particularly because fast motion can affect accelerometer readings. The process of finding the optimal gain using trial and error is called "tuning". Tune your robot until you find an optimal balance between speed and accuracy. You may also find it useful to set a minimum speed, so that the robot doesn't stop before reaching the target.

6. Upload a video to Slack of the Zumo facing upwards **using proportional control**.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**