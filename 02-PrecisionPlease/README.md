# Challenge #2: Precision, Please

## Video Overview: [Click Here](https://drive.google.com/file/d/1pSs_jI5-8FlRpv6a2jkbTNq9_bT211vh/view?usp=sharing)

You may not be able to play the video in Google Chrome. Please use another browser (Microsoft Edge, Firefox, Safari, etc.) if you encounter issues.

## Overview

You may have encountered some annoying limitations during "Challenge #1: Start Your Engines!" For example, the distance the robot drove sometimes varied. You also couldn't specify a distance in normal units and had to change the timing to compensate for speed. In this challenge, you will address many of these issues by creating a program which drives with far greater precision.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us via Zoom during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed the previous challenge - "Start Your Engines!" This serves as an introduction to the basic functions of the Zumo.

* You should read through [this article](http://encoder.com/blog/company-news/what-is-an-encoder/), which provides an introduction to encoders. Don't worry if you don't understanding everything so long as you get the gist of what an encoder can do.

## Challenge

1. Download "02-PrecisionPlease.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "02-PrecisionPlease.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Try uploading the template sketch and look at the LCD. What do the two numbers indicate? What does a A button do? Hint: it involves encoders :)

4. You may have noticed that these values aren't a standard unit of measurement. Try to adapt the sketch to display these values in inches. Test your sketch using a ruler. Does it work for a variety of distances?

5. Now we're ready to start driving autonomously! Your first goal is to make the Zumo drive forward exactly 12 inches and stop using the encoders. There are many approaches to this problem, so here are few questions to consider:

   * The Zumo includes separate encoders for the left and right sides. How can you use these two data points to read the distance?

   * How close to the target do you end up? More precision is generally better, but consider how exact you need to be before the difference is negligible.

   * How quickly can you get to the target distance? Can you vary the speed without affecting precision?

   * How smoothly does the Zumo move to the target? Does it ever "overshoot" (move past) the target?

   * Try changing the target distance. Does it behave better or worse? How can you optimize it to work quickly and precisely on a wide variety of distances?

6. Once you have a system you're happy with, we can make the pattern more complex. Try to make your Zumo drive forward 12 inches, then backwards 4 inches at a time until you reach the starting position. Wait for at least one second at each position.

![Diagram of target path](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-path.png)

7. Upload a video of the Zumo completing this final challenge to Slack along with your code.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**

We have provided a [post challenge review](https://github.com/Mechanical-Advantage/Training2020/blob/development/02-PrecisionPlease/PostChallenge.md) (which can be read individually or discussed as a group).