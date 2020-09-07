# Challenge #9: Escaping the Labyrinth

## Overview

In this challenge, you'll write the code to navigate a maze of lines. The Zumo will work through the maze to find the ending using a variety of algorithms.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* This challenge makes use of two line sensors we haven't used previously, meaning you must reconfigure the jumpers on the Zumo's front sensor array. [This video](https://drive.google.com/file/d/1sCsUIG6LEr4cQy_7eSqMPwwuEOuQpxoX/view?usp=sharing) demonstrates how to do that. **Be very careful to align the pins correctly when reconnecting the board.** Once connected, you should see that it is centered behind the medal blade with an even gap on each side.

* For reference purposes, a PDF of the maze is available [here](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/09-maze.pdf).

## Challenge

1. Download "09-EscapingTheLabyrinth.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "09-EscapingTheLabyrinth.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Run the template code and place the robot centered on the black calibration line in the corner of the paper (seen below). The exact location/direction on the line doesn't matter so long as the sensors stay on the paper during calibration. Press A to calibrate the line sensors and gyro sensor. When setting up the maze, you should choose a location on a hard surface and with even lighting. You should also avoid anywhere with direct sunlight.

![Picture of calibration position](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/09-calibrationpos.jpg)

4. Move the robot to the start of the maze and point it directly upwards (seen below). The alignment here is critical - make sure the robot is aligned exactly with the direction of the line.

![Picture of start position](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/09-startpos.jpg)

5. Press A to start line following. The robot will run forwards until it finds the first intersection, then stop. The template program will display the available directions on the LCD, both as cardinal directions (north, east, south, west) and relative directions (foward, right, backward, left). The green LED will indicate once the end of the maze has been reached. When you press A again, the robot will turn left and continue following (it will lso display the cardinal direction it turns to on the LCD). Notice that if you continue this cycle, the robot will continue trying to turn left even when a line doesn't exist - your code will have to be careful to avoid this issue.

    * *The line following and turning code can be finnicky. If the robot is behaving unexpectedly (going off the lines, turning to the wrong direction, etc.) please try moving the maze a different environment or starting the calibration in a different location. If the problem persists, please contact us for assistance.*

6. Read over the template code. The loop code uses various functions to assist with maze navigation like `followToTurn()`, `turnRelative()`, and `getCardinalDirection()`. The code for these functions is located in "MazeCommands.h" for those interested. The template code also reads the variable `finished` to determine when the end has been detected.

7. The goal of the challenge is to make the robot find its way from the start of the maze to the end. This means you should replace the section of template code that waits for the A button to be pressed and turns left. Instead, the robot should automatically choose which direction to turn and continue immediately. Here are a few things to consider as you craft your algorithm:

    * The robot will turn to the specified direction even if a line doesn't exist :grimacing:. Make sure to check that a direction is valid before deciding to turn there. You can use the syntax `availableDirections & North` (using any cardinal or relative direction) to check if a particular direction is valid.

    * The robot needs to stop once it reaches the end! You can detect once this needs to happen using the `finished` variable.

    * There are lots of potential algorithms to try - see which ones work best! A good starting point it to "follow the left wall," but what happens if you follow the right wall? What if the direction you choose is random? Can you think of any other algorithms? :thinking:

8. After you've experimented with several algorithms, your goal is to make the robot reach the end of the maze as quickly as possible. Using whatever algorithm you think is fastest, upload a video to Slack of the Zumo navigating to the end of the maze. We will hold a *friendly* competition to see who can create the fastest maze solver. **Note that your robot must be theoetically capable of solving a variety of mazes (or starting in any location on this maze) - it cannot use a known sequence of turns.**

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**