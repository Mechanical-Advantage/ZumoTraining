# Challenge #10: Mastering the Labyrinth

## Overview

In this challenge, you'll build off the work you've done to the solve a maze of lines by making the robot run through the maze a second time using the optimal route.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* The robot must be configured to use all five line sensors. The [previous challenge](../09-EscapingTheLabyrinth) contained instructions on how to switch the jumpers.

* This challenge involves extensive use of arrays. You should go through [this tutorial](https://www.learn-c.org/en/Arrays) if you'd like a refresher.

* This challenge will start to introduce concepts related to *object-oriented programming*. Read through [this introduction](OOIntro.md), which provides some essential background information.

## Challenge

1. Download "10-MasteringTheLabyrinth.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "10-MasteringTheLabyrinth.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Read through the template code and try to understand what everything does. Notice that the "Path" is a separate class, which contains relevant data and an interface for interacting with it. This is built off of the template from the previous challenge, but is designed for running two "solves":

    * The "initial solve" is similar to the previous challenge - the robot navigates to the end of the maze using any strategy (follow the left wall, follow the right wall, random, etc.) The green LED is off for the initial solve.

    * The "repeat solve" happens after the robot has found the optimal path through the maze. The robot goes from start to finish along this optimal path. The green LED is lit for the repeat solve.

4. The first step is to get the initial solve working, using your work from the previous challenge. At the end of the template code is the function `getSolveDirection()`, which is used in the loop during the initial solve. It should contain your code from the previous challenge. However, note that it now needs to **return** the new direction rather than immediately turning. Test the code to make sure it can reach the end of the maze as you expect.

5. The next step is to create an implementation for the "Path" class. The path contains an array of directions, which can be used to record and play back a sequence. Start by making the robot record the sequence of turns from the initial solve and repeat those turns exactly on the repeat solve. You'll have to write to `turns` in `addTurn()` and read from `turns` in `getNextTurn()`. In order to do that, you might need to keep track of where in the array you're currently writing and reading. Maybe some extra attributes would be useful? :wink:

    * Another thing to keep in mind - you should ensure the code can only read from valid locations in the array (index 0-99). The implementation shouldn't read from invalid locations regardless of how the inferface is used (for example, if `getNextTurn()` is called more times than expected). That kind of data protection is another key benefit of an object-oriented structure.

6. Once the code can replay its path exactly, it's time to optimize :star_struck:! We have some hints about how that might work [here](https://docs.google.com/presentation/d/1jDsCbiJ5Ow2rlOxYv3KtA92UxcbsZgj4bfnVatyenZY/edit?usp=sharing), using an example of a simplified maze. It shows the state of the `turns` array during the initial solve and repeat solve.

7. Upload a video to Slack of the Zumo running through the maze twice - once for the initial solve and again using the optimal route.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**