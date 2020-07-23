# Challenge #3: Coming Through!

## Overview

The previous challenge shows how we can use the Zumo's sensors to our advantage. This challenge will expand on that concept by introducing the proximity sensors, which provide data on the robot's surroundings. Using these sensors, you will create a program that allows the Zumo to navigate complex spaces autonomously.

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us via Zoom during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* You should read through [this page](https://github.com/Mechanical-Advantage/Training2020/blob/development/03-ComingThrough/ProxSensors.md), which explains how the proximity sensors on the Zumo are positioned and how to interpret the data they produce.

## Challenge

1. Download "03-ComingThrough.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your templates that you develop from.

2. Open this *folder* in VSCode, then click on "03-ComingThrough.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Try uploading the template sketch. The LCD shows the 6 values from the proximity sensors (see the reference page for information on what this means). The top row shows the values from the left emitter and the bottom row shows the values from the right emitter. Each row shows the left, front, and right sensors in order.

4. Experiment by moving objects around the Zumo to get a sense of what each value indicates. You can also press A to start driving forwards. The Zumo will automatically stop when it detects an object in front of it.

5. Your challenge is to use the proximity sensors such that the Zumo will autonomously navigate a room on the floor for as long as possible. It should avoid obstacles and walls while driving quickly. There are a wide variety of approaches to this problem that will produce different results. We'd encourage you to start by trying to come up with your own unique approach. However, we also have some hints for potential approaches if you get stuck. Click the arrows below to reveal some starting points or ways to expand your current thinking.

    <details>
        <summary>Approach #1: Basic</summary>
        Think about what the template program already accomplishes - it stops when it detects an object in front of it. This is already most of the way to completing the challenge. Maybe you could adjust it so that the instead of stopping, it tries to find a new direction... :eyes:
    </details>

    <details>
        <summary>Approach #2: Intermediate</summary>
        The Zumo doesn't just detect objects in front of it - you also want avoid obstacles on the sides. The template shows an example of how to stop when an object appears in front. This could be expanded, so that the Zumo stops when it sees an obstacle it any direction! However, we don't just want to stop in place. Maybe it could  change direction instead? :thinking:
    </details>

    <details>
        <summary>Approach #3: Advanced</summary>
        If you've already gotten the Zumo to stop or reorient when it detects an obstacle, let's expand on that. Remember that the proximity sensors detect the distance to an object (starting from quite a ways away). Maybe it could start reacting to an obstacle before it comes too close? How should the response be different depending on the distance?
    </details>

    <details>
        <summary>Approach #4: Expert</summary>
        This problem could be solved with two formulas. Think of the problem this way - you have 6 inputs (the proximity sensors) and 2 outputs (the motor speeds). How can you generate the ideal speed for a particular motor using a formula with the proximity sensors as inputs?
        <details>
            <summary>Example</summary>
            This is an example of a simple calculation for the left motor speed. Try to expand on it!
            
        left motor = 120 + proxSensors.countsLeftWithLeftLeds() * 20
    </details>

6. We can't wait to see what approaches you come up with! Upload a video to Slack of the Zumo running around the floor along with your code.

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**
