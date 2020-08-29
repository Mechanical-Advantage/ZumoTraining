# Challenge #8: A Dizzying Dilemma

## Overview

In this challenge, you will use the Zumo's gyro sensor to allow it to maintain orientation as a surface rotates underneath it - with a catch :open_mouth:. Unlike challenge 5, we haven't provided code to convert the gyro sensor's angular velocity measurement to position.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* You should review [this article](https://learn.sparkfun.com/tutorials/gyroscope/all), which provides an introduction to the inner workings of the gyro sensor. Remember that the gyro sensor reports **angular velocity**, and your challenge is to convert a series of velocity measurements to position.

* You should watch through the following three videos, which explain some of the underlying math of this challenge:

    1. [This video](https://www.youtube.com/watch?v=DxJMDJSorMQ) explains how to find displacement (change in position) from velocity graph.

    2. [This video](https://www.youtube.com/watch?v=Ka9xWAmWBow) shows a more advanced example of calculating displacement.

    3. [This video](https://www.youtube.com/watch?v=vPhwP-w5tUU) explains how to create a full position graph (very similar to what we're aiming for) from a velocity graph.

## Challenge

1. Download "08-DizzyingDilemma.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "08-DizzyingDilemma.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Run the template code and press the A button to start. The Zumo will begin logging the gyro value from the z axis (which reads the spinning motion we're interested in). Open the serial plotter to see this value on a graph. Remember that the gyro sensor logs angular velocity. In this case, the template program is logging in degrees per second.

4. Read through the template code and try to understand what everything does. Your challenge will be to add code to the `updateAngle` function so that the `angle` variable tracks the current gyro position. Right now, `angle` is not updated and remains at 0. It's printed to the LCD and will be used in a proportional control system when the A button is pressed a second time. This control system will hold the robot at 0°, like challenge 5.

5. What code should go in the `updateAngle` function? We want to update `angle` based on the current angular velocity. In making this calculation, there are three important inputs; `dps` - the current angular velocity in degrees per second, `readTime` - the time of the current gyro reading in microseconds, and `lastReadTime` - the time of the previous gyro reading in microseconds. Using those values, you should calculate the displacement in degrees from the previous measurement and adjust `angle`. Please review the videos above if you need help. We also have a simplified explanation here (Δ = change):

    ![velocity = Δposition / Δtime](https://latex.codecogs.com/gif.latex?\fn_phv&space;velocity=\frac{\Delta&space;position}{\Delta&space;time})

    ![velocity * Δtime = Δposition](https://latex.codecogs.com/gif.latex?\fn_phv&space;velocity*\Delta&space;time=\Delta&space;position)

8. Upload a video of the Zumo completing the challenge to Slack *along with a screenshot of the graph from the serial plotter*.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**