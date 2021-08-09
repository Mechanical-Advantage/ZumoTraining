# Challenge #6: Following Orders

## Overview

In this challenge, you will use the proximity sensors for a different purpose - remote control! Without the IR emitters, the sensors can be used to receive commands from your remote control, allowing you to drive the robot with it.

*Disclaimer - This challenge is significantly more difficult than the work we've done previously. We recommend making use of the introduction meeting to ask questions and get detailed explanations of the many components involved in the challenge.*

## Support

If you need assistance with anything (even if you just don't know where to start), **please** contact any of us via Slack publicly or privately. You can also meet with us during our "office hours." These hours are listed in a pinned post on Slack.

## Prerequisites

* You must have completed all previous challenges - this challenge builds off what you have previously learned.

* To read commands from the remote control, you need to understand how they are sent. You should read through [this introduction to IR transmission](https://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/) (reading down to, but not including "How to Connect An IR Receiver to Arduino"). This remote uses the NEC encoding type, where commands are sent as a series of short pulses. You should also read through [this explanation of the NEC transmission protocol](https://techdocs.altium.com/display/FPGA/NEC+Infrared+Transmission+Protocol). Note that "µs" stands for microsecond (1/1000th of a millisecond).

* The data in the protocol is encoded using binary. If you are unfamiliar with binary and want an introduction, we suggest watching [this video](https://www.youtube.com/watch?v=ku4KOFQ-bB4). The data from the remote is constructed of 4 bytes with 8 bits each.

* The template makes use of several switch statements and enumerations (enums). If you are unfamiliar with either of these concepts, you should read through these tutorials on [switch statements](https://www.tutorialspoint.com/cprogramming/switch_statement_in_c.htm) and/or [enumerations](https://www.programiz.com/c-programming/c-enumeration).

## Challenge

1. Download "06-FollowingOrders.zip" from GitHub and unzip it to create a new folder. We recommend placing this folder under "Documents." Again, this folder will be your template that you develop from.

2. Open this *folder* in VSCode, then click on "06-FollowingOrders.ino". On Mac, click "Win32" in the lower right corner and change your configuration to "Mac"

3. Read through the template to understand the structure. This template makes use of a state machine - throughout reading the message from the remote, it moves through 6 states - Idle, Lead, LeadComplete, WaitForDataOff, WaitForDataOn, and MessageComplete. Each of these states is accompanied by different logic to interpret the signal from the remote and move to the next state when approproiate. The loop reads the current remote signal and enters a switch statement, where a set of code is run based on the current state. This code can choose to call "setState" to update the current state (which also records the time at which the state changed). Please reference the following diagram to check how the program is intended to move between the 6 states:

![State flow chart](https://raw.githubusercontent.com/Mechanical-Advantage/SummerTraining2020/master/resources/06-statediagram.jpg)

We can also overlay these states on a timeline of how the pulse are sent:

![Timeline of state changes](https://raw.githubusercontent.com/Mechanical-Advantage/SummerTraining2020/master/resources/06-timeline.jpg)

4. While the template includes the general structure of a state machine, it does not have the code to be run in each state. Your challenge is to complete the template program based on the above diagrams, so that the Zumo can interpret commands from the remote. At a minimum, it should be able to drive forwards, backwards, turn left, and turn right using the arrow buttons. Feel free to add more commands if you like! Please refer to the following table for a list of possible commands:

    Button | Message Number | Button | Message Number
    --- | --- | --- | ---
    Volume Down | `0` | Return | `14`
    Play/Pause | `1` | One | `16`
    Volume Up | `2` | Two | `17`
    Setup | `4` | Three | `18`
    Up Arrow | `5` | Four | `20`
    Stop/Mode | `6` | Five | `21`
    Left Arrow | `8` | Six | `22`
    Enter/Save | `9` | Seven | `24`
    Right Arrow | `10` | Eight | `25`
    Zero/Ten | `12` | Nine | `26`
    Down Arrow | `13`

5. If you've added all of the code but find that the robot isn't doing what you expect, you might need to do some debugging. Unfortunately, programs like this can be difficult to debug in real time because the important logic happens very quickly (under 100ms)! Instead, you can log data or state changes over serial as they happen and review them after, making sure everything happened in the right order and looks as you expected. In this case, we'd recommend you use the serial monitor rather than the serial plotter and log lines of text at various points in the program. Remember that you can send data over serial with the function `Serial.println("Hello world");`

6. Upload a video to Slack of the Zumo driving via remote control (along with any other commands you've added).

**Remember, if you are stuck please ask for assistance on Slack or during office hours.**