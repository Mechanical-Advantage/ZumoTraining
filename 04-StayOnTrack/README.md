# Challenge #4: Stay On Track

## Overview

This challenge will introduce another of the Zumo's many components - the line sensors! Using the line sensors, you will experiment with various methods of making the Zumo follow a line. Then, we will have a friendly competition to see who can create the fastest line follower!

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us via Zoom during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* You should print out and assemble the test track. [Click here](TrackSetup.md) for instructions.

## Challenge

1. Download "04-StayOnTrack.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "04-StayOnTrack.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Try uploading the template sketch. First, place the robot centered on the track and press A. It will spin around once to calibrate the line sensors. Then, move it so that the front is positioned on the gray square in the corner and press A again. It will move foward until it leaves the square, then begin displaying the line sensor values. If you move the robot back to one of the gray squares, it will display the total time since it left the first gray square. Ultimately, this template will be used to time your line following algorithm as it navigates the course. For now, try moving the robot around the line and observe the readings from the three line sensors (which are located on the left, center, and right sides of the sensor array under the robot).

4. Read through the template code. This template is significantly more complex that previous challenges, but you should focus on the "lineFollow" function at the bottom. This function is run as part of the loop and is where you should place your code for the line follower. The three sensor values are stored in the array "sensorValues" - you can see an example of how to read each sensor on lines 91-95.

5. First, try implementing a very simple line follower using the left and right sensors. When the robot detects a line on the left or right sides, it should stop and turn slightly to correct. Try running this system several times. How well does it work? What can cause it to fail to track the line?

6. Next, try expanding on this simple algorithm. Remember that each sensor provides a value from 0-1000 based on how dark the reading is (how centered the sensor is on the line). You could scale the response on the left and right sides based on that value. Remember [proportional control](../02-PrecisionPlease/PostChallenge.md#approach-4-proportional-control-low-gain) from challenge #2? :wink:

7. Another approach to line following is to use a single sensor. This involves tracking the edge of the line (the transition between black and white) as opposed to the line as a whole. When the sensor reads 500, this means it is positioned exactly between black and white on the edge of the line. A higher value indicates it is moves towards the center of the line while a lower value means it is moving away. How could you use this data to track the line? (Hint: Proportional control strikes again!)

8. Now that you've experimented with several methods of line following, your goal is to make the robot navigate the testing track as fast as possible. You can create your algorithm based on one of the methods you've tried already or go in a different direction! Once you're satisfied with your system, post a video to Slack of the robot completing the course along with your time. We will hold a *friendly* competition to see who can create the fastest line follower. Ready, set, follow!

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**