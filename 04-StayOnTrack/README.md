# Challenge #4: Stay On Track

## Video Overview: [Click Here](https://drive.google.com/file/d/1QB5DItAjAyKC4624yk5-UHz8wdr-mxJM/view?usp=sharing)

You may not be able to play the video in Google Chrome. Please use another browser (Microsoft Edge, Firefox, Safari, etc.) if you encounter issues.

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

3. Try uploading the template sketch. Place the robot centered on the track (seen below) and press A. It will spin around once to calibrate the line sensors. This records the minimum (lightest) and maximum (darkest) possible values for each sensor, meaning the readings will be accurate regardless of lighting conditions.

![Picture of suggested calibration location](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/04-calibrationpos.jpg)

4. Move the robot so that the front is positioned on the gray square in the corner (seen below) and press B to enter "testing" mode. It will move foward until it leaves the square, then stop.

![Picture of start location](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/04-startpos.jpg)

5. Try moving the robot around the line and observe the readings from the three line sensors, displayed on the LCD. The two values on the top row show the left and right sensors and the value on the bottom row shows the center sensor (this is because the three values don't fit on one row). You can find these sensors under the robot on the front sensor array, seen here:

![Diagram of line sensor locations](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/04-sensors.jpg)

6. In addition to the "testing" mode you've been using, the template has a "timing" mode (which you can activate by pressing A instead of B). This behaves identically except that when the robot reaches the ending gray square it will stop and display the number of seconds since it left the first gray square. Eventually, you will use this mode to test the speed of your line following algorithms. Feel free to continue using the "testing" mode while developing.

5. Read through the template code and try to understand what everything does. This template is significantly more complex that previous challenges, but the most important piece is the "lineFollow" function at the bottom. This function is run as part of the loop and is where you should place your code for the line follower. The three sensor values are stored in the array "sensorValues" - you can see an example of how to read each sensor on lines 111-115. If necessary, we recommend checking out these tutorials on [arrays](https://www.learn-c.org/en/Arrays) and [functions](https://www.learn-c.org/en/Functions).

5. First, implement a very simple line follower using the left and right sensors. When the robot detects a line on the left or right sides, it should stop and turn slightly to correct. Try running this system several times. How well does it work? What can cause it to fail to track the line?

6. Next, expand on this simple algorithm. Remember that each sensor provides a value from 0-1000 based on how dark the reading is (how centered the sensor is on the line). You should scale the response on the left and right sides based on that value. Remember [proportional control](../02-PrecisionPlease/PostChallenge.md#approach-4-proportional-control-low-gain) from challenge #2? :wink:

7. Another approach to line following is to use a single sensor. This involves tracking the edge of the line (the transition between black and white) as opposed to the line as a whole. When the sensor reads 500, this means it is positioned exactly between black and white on the edge of the line. A higher value indicates it is more towards the center of the line while a lower value means it is farther away. Try using this single-sensor technique to track the line. (Hint: Proportional control strikes again!)

8. Now that you've experimented with several methods of line following, your goal is to make the robot navigate the testing track as fast as possible. You can create your algorithm based on one of the methods you've tried already or go in a different direction! Once you're satisfied with your system, post a video to Slack of the robot completing the course along with your time. **To measure your time, use the "timing" mode in the template.** We will hold a *friendly* competition to see who can create the fastest line follower. Ready, set, follow!

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**