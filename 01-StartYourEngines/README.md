# Challenge #1: Start Your Engines!

## Video Overview: [Click Here](https://drive.google.com/file/d/1qaBay04gGvzOlfpG49dDE3zbFJk2_C-8/view?usp=sharing)

You may not be able to play the video in Google Chrome. Please use another browser (Microsoft Edge, Firefox, Safari, etc.) if you encounter issues.

## Overview

When starting in a new environment, programmers will often create a "Hello world" program - enough to do something interesting but not overly complex. This is the Zumo version of "Hello world." Your challenge is to begin to explore how to interact with the basic functions of the Zumo - motors, buttons, and LEDs, by programming the Zumo to drive along a simple path.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us via Zoom during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have set up your VSCode IDE with Arduino. You can do so by following these instructions for [Mac](https://docs.google.com/presentation/d/1cyeOuGeWGI4tj6PQgyC6Zz0o6Nv5z3nh0UwPVeGp7-I/edit?usp=sharing) or [Windows](https://docs.google.com/presentation/d/1y6T2atl-b8Y2t-8qAfPKwe7EO9_AVQGZKfdK217bZew/edit?usp=sharing).

* If you are new to programming or Arduino specifically, we recommend checking out these resouces:

    * https://www.learn-c.org/en/Welcome - This tutorial provides an introduction to C, the language we will use to program the Zumos. It includes a series of escalating challenges that you can try in your browser. We recommend completing the section "Learn the Basics" but "Advanced" will go beyond the scope of our program.

    * https://www.tutorialspoint.com/arduino/index.htm - This provides an introduction to Arduino specifically, the board which powers the Zumo. This site contains a large amount of information - don't worry about understanding everything.

## Challenge

1. Download "01-StartYourEngines.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." This folder is your template, which you can develop from. Templates will be provided most of the time as a starting point for these challenges.

2. Open this *folder* in VSCode, then click on "01-StartYourEngines.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Try uploading the template sketch. What happens when you press the A button on the Zumo? Read through the code and try to understand what each line does.

4. Your challenge is to use the tools seen in the template to accomplish something more interesting. Try setting up a simple course for the robot to navigate. You should include defined start and end locations, and at least one obstacle. For example, I've created this single design with a coffee mug. The robot needs to cross the start line, circle around the coffee mug, and return across the line. Modify the template so that the Zumo completes the course.

![Track design with one coffee mug](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/01-simplecourse.jpg)

6. Try more complex courses. Add more obstacles to make the course longer. How reliable are your results as the course gets longer? Try to make the robot turn in a variety of ways - how may ways can you think of?

7. Try changing the speed of the motors. How does that affect the robot's path? Does it become more or less reliable as the speed increases?

8. Bonus: How could you make your course into a loop, such that the robot returns to where it starts and continues multiple times? How long can it run before going off course?

9. Upload a video of the Zumo completing your most interesting course to Slack along with your code.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**
