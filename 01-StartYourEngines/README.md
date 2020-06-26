*TODO: Update office hours*

# Challenge #1: Start Your Engines!

### Video overview: <a href="https://youtu.be/_Z69LusV5e8" target="_blank">https://youtu.be/_Z69LusV5e8</a>

## Overview

When starting in a new environment, programmers will often create a "Hello world" program - enough to do something interesting but not overly complex. This is the Zumo version of "Hello world." Your challenge is to begin to explore how to interact with the basic functions of the Zumo - motors, buttons, and LEDs, by programming the Zumo to drive along a simple path.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us via Zoom during our "office hours:"

* **Alex**: Mon-Fri, 3-4pm ([Join meeting](http://www.google.com))
* **Samantha**: Thur-Fri, 5-5:30pm ([Join meeting](http://www.google.com))
* **Fred**: Sat-Sun, 10-11am ([Join meeting](http://www.google.com))
* **Victoria**: Mon-Fri, 8-9pm ([Join meeting](http://www.google.com))

## Prerequisites

* You must have set up your VSCode IDE with Arduino. You can do so by following these instructions for [Mac](https://docs.google.com/presentation/d/1cyeOuGeWGI4tj6PQgyC6Zz0o6Nv5z3nh0UwPVeGp7-I/edit?usp=sharing) or [Windows](https://docs.google.com/presentation/d/1y6T2atl-b8Y2t-8qAfPKwe7EO9_AVQGZKfdK217bZew/edit?usp=sharing).

* If you are new to programming or Arduino specifically, we recommend checking out [this tutorial](https://www.tutorialspoint.com/arduino/index.htm) as an introduction. You don't have to read every page, but it may be useful to get more familiar. You are also free to message us if you'de prefer we talk through some of this.

## Challenge

1. Download the "01-StartYourEngines.ino" from GitHub and place it in a new folder. It should be found under "ZumoTesting > 01-StartYourEngines > 01-StartYourEngines.ino" You may have to copy the text from your browser into a new file. This sketch is your template, which you can develop from. Templates will be provided most of the time as a starting point for these challenges.

2. Modify "arduino.json" under the ".vscode" folder. The path should now be "01-StartYourEngines\\01-StartYourEngines.ino" (or "01-StartYourEngines/01-StartYourEngines.ino" on Mac) This will allow you to upload this new sketch.

3. Try uploading the template sketch. What happens when you press the A button on the Zumo? Read through the code and try to understand what each line does.

4. Your challenge is to use the tools seen in the template to accomplish something more interesting. Try setting up a simple course for the robot to navigate. You should include defined start and end locations, and at least one obstacle. For example, I've created this single design with a coffee mug. The robot needs to cross the start line, circle around the coffee mug, and return across the line. Modify the template so that the Zumo completes the course.

![Track design with one coffee mug](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/development/img/01-simplecourse.jpg)

6. Try more complex courses. Add more obstacles to make the course longer. How reliable are your results as the course gets longer?

7. Try changing the speed of the motors. How does that affect the robot's path? Does it become more or less reliable as the speed increases?

8. Bonus: How could you make your course into a loop, such that the robot returns to where it starts and continues multiple times? How long can it run before going off course?

9. Upload a video of the Zumo completing your most interesting course to Slack along with your code.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**