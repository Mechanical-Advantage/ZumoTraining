# Challenge #11: Enter the Ring

## Overview

In this challenge, you'll prepare your code for a sumo competition. The goal of the competition is to find other robots and push them outside of the ring. This will involve using a variety of sensors (which you are already familiar with from previous challenges).

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* We recommend configuring the robot to use all three proximity sensors (the template code assumes this configuration). If you have just finished challenges 9 and 10, you need to switch the jumpers back to the original setup. [Challenge 9](../09-EscapingTheLabyrinth) contained instructions on how to switch the jumpers. **The jumpers should be configured in the opposite direction of what is shown in the video (in the end, the jumpers should be closer to the edge of the sensor board).**

* You should read through [our official rules](http://example.com) for the sumo competition. Feel free to ask for clarifications on any rules.

* You should watch [this video](https://drive.google.com/file/d/1Z5ZyqqKslBiiowdKxmI1soykJrbZ11y9/view?usp=sharing) to see an example of what robot sumo looks like. If you haven't already, this is also a good time to start thinking about your strategy (what worked in the video and what didn't work?)

## Challenge

1. Download "11-EnterTheRing.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "11-EnterTheRing.zip". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Read through the template code, then run it. When running the code, you should first press A, B, or C. Each button triggers a countdown of a different length (as displayed on the LCD). After the countdown, the robot will start moving forwards and then run the code in `loop()` (which currently only reads the line and proximity sensors). We will use this countdown to ensure each robot starts at the same time. You are free to modify the code in the `setup()` function **so long as the behavior of the countdown is not affected**.

4. The first step is to ensure that the robot doesn't drive outside the ring on it's own. In the `loop()` function, you should read each line sensor and turn away if one detects black (using the `BLACK_THRESHOLD`). While you don't have a full sumo ring to test on, we recommend using the maze from the previous challenges to test the line sensing. You have already written similar code for [challenge 4](../04-StayOnTrack), so feel free to start with your previous solution if you don't know where to begin.

5. In addition to staying inside the ring, you should be able to find and target other robots in the ring using the proximity sensors. This means adjusting the speed of the motors to orient towards any potential targets. You can use any small object like a tennis ball to test this logic. Again, you've already completed a similar task for [challenge 3](../03-ComingThrough). You just need to adjust your logic to drive towards anything you detect rather than avoiding it.

6. Hooray! You now have the basics of a sumo program! :tada: You are now free to improve this algorithm as you see fit, including using any of the others sensors on the Zumo. You will also be able to adjust your code throughout the competition to make improvements. Here are a few ideas to get you started:

    * Using the proximity sensors, the robot is currently acting offensively by targeting other robots. What if you played defense instead by avoiding other robots? Which is the better strategy?

    * What speed should the robot be running at? Is faster or slower better? Does it depend on how close the opponent is?

    * What should your first move be? Run towards the opponent, run away, or turn?

    * Often, robots might get stuck with the blades pushing against each other, meaning neither can make progress. Maybe you could try to avoid (or escape) such situations? How could that work?

    * Feel free to look online if there are any other strategies you might want to try.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**