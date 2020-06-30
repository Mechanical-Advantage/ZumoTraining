*TODO: Update office hours*

# Challenge #2: Precision, Please

## Overview

### [Video Overview](https://drive.google.com/file/d/1aXa1iA_fBtItPZEm_xknWo3Eckbg9F4s/view?usp=sharing)

You may have encountered some annoying limitations during "Challenge #1: Start Your Engines!" For example, the distance the robot drove sometimes varied. You also couldn't specify a distance in normal units and had to change the timing to compensate for speed. In this challenge, you will address many of these issues by creating a program which drives with far greater precision.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us via Zoom during our "office hours:"

* **Alex**: Mon-Fri, 3-4pm ([Join meeting](http://www.google.com))
* **Samantha**: Thur-Fri, 5-5:30pm ([Join meeting](http://www.google.com))
* **Fred**: Sat-Sun, 10-11am ([Join meeting](http://www.google.com))
* **Victoria**: Mon-Fri, 8-9pm ([Join meeting](http://www.google.com))

## Prerequisites

* You must have completed the previous challenge - "Start Your Engines!" This serves as an introduction to the basic functions of the Zumo.

* You should read through [this article](http://encoder.com/blog/company-news/what-is-an-encoder/), which provides an introduction to encoders. Don't worry if you don't understanding everything so long as you get the gist of what an encoder can do.

## Challenge

1. Download "02-PrecisionPlease.ino" from GitHub and place it in a new folder. It should be placed under "ZumoTesting > 02-StartYourEngines > 02-StartYourEngines.ino" You may have to copy the text from your browser into a new file. Like the previous challenge, this sketch is your template, which you can develop from.

2. Modify "arduino.json" under the ".vscode" folder. The path should now be "02-PrecisionPlease\\02-PrecisionPlease.ino" (or "02-PrecisionPlease/02-PrecisionPlease.ino" on Mac) This will allow you to upload this new sketch.

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