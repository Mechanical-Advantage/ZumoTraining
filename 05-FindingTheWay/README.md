# Challenge #5: Finding the Way

## Overview

In this challenge, you will use the Zumo's gyro sensor to allow it to maintain orientation as a surface rotates underneath it. This will utilize some of the control loop concepts covered in previous challenges.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us via Zoom during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* You should read through [this article](https://learn.sparkfun.com/tutorials/gyroscope/all), which provides an introduction to the inner workings of the gyro sensor.

## Challenge

1. Download "05-FindingTheWay.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "05-FindingTheWay.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Try uploading the template sketch. Press A to start the calibration (the article above discusses why this is necessary). During calibration, it is important that the robot remain completely still. After a few seconds, the red LED will turn off and a value will be displayed on the LCD. This indicates the robot's rotation in degrees. You can press A to reset this value to 0.

4. Read through the template code and try to understand what everything does. You may notice that the "gyro" object has the type "ZumoGyroPosition" - this is code that we've written to interface with the gyro sensor. The gyro sensor only reports the uncalibrated angular velocity, not position. Our code uses the raw gyro data to calculate the angle (including handling calibration), simplifying the code you'll be writing.

5. One of the key ways we can debug the Arduino (or an FRC robot :wink:) is by logging data to the computer. On the Arduino, that can be done via a serial connection where, in this case, the Zumo sends data to the computer over USB. You can use the function `Serial.println();` to send one line back to the computer (this can be a string, integer, double, etc). To view this data, you can use the serial monitor (which displays the raw text) or the serial plotter (which graphs numbers). We have instructions for opening each of these interfaces at the end of the VSCode set up instructions for [Mac](https://docs.google.com/presentation/d/1cyeOuGeWGI4tj6PQgyC6Zz0o6Nv5z3nh0UwPVeGp7-I/edit?usp=sharing) or [Windows](https://docs.google.com/presentation/d/1y6T2atl-b8Y2t-8qAfPKwe7EO9_AVQGZKfdK217bZew/edit?usp=sharing). You should adjust the template code so that the gyro angle is logged over serial whenever the LCD is updated. Then, confirm that you can see these values through both the serial monitor and serial plotter.

6. Your goal is to use the gyro sensor to keep the robot pointed in the same direction as a surface rotates underneath it. Here are some ideas for ways to create a rotating surface:

    * Use a lazy susan, which is designed to spin easily. This option is ideal if you have one available.

    * Remove the plate from a microwave, which often has wheels underneath to allow it to spin. Please don't do this without asking and be careful not to damage it.

    * Use a large flat surface like a hardcover book, cutting board, etc. You can spin it around on a table to keep it as level as possible.

7. As the surface moves, the robot should respond quickly and avoid oscillation. You can see how well your solution works by looking at the serial plotter - does it accurately and precisely stay pointed in the target direction, even while the surface is in motion? Try moving the surface very quickly or reversing direction suddenly and see how you can improve the robot's performance.

7. Upload a video of the Zumo completing the challenge to Slack *along with a screenshot of the graph from the serial plotter*.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**