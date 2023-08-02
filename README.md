# FRC 6328 Zumo Software Training Curriculum

Student code is part of the [ZumoTrainingCode](https://github.com/Mechanical-Advantage/ZumoTrainingCode) repository.

## Summary

6328 has developed a remote-learning software curriculum which uses small, inexpensive robots to teach key robot control concepts through a series of escalating challenges. Students learn by doing in a progressive manner, with support provided by student leads and mentors through online collaboration tools.

## Introduction

6328 has a model of student-led development teams. It is important to us for our student leads to train multiple students on the fundamentals of software for robots so as to be able to distribute development work to multiple team members. This means not just code syntax, but the core robot control concepts: use of sensors and closed-loop control to provide consistent interaction with the physical environment, while accounting for the quirks and real world inconsistencies of both the sensors and the mechanical systems involved.

Our experience is that it is possible, but difficult, to teach beginner students these concepts using a full size FRC robot. For one, we (like most teams) have a limited number of functioning robots at any given time. For another, FRC robots are big, fast, and powerful - which is great on the playing field, but not so great when a student is trying out untested code in the team workspace. (For most of a season one of our walls featured a Wile E. Coyote-like robot-shaped hole in the drywall from a testing session gone awry.)  Finally, there is a lot of complexity in the WPILib framework and the motor controller APIs, which makes even a basic program less approachable for a new student.

The advent of the COVID-19 pandemic and the need for all training to be remote for a while made it urgent that we have a way for students to develop these skills in their own homes. This program was developed in response to that challenge.

## Description

This program is structured around use of an actual robot, for maximum student engagement and to provide real-world experience. For this to be practical, the robot needed to be small in size (for safe use in student homes) and inexpensive enough that the team could purchase a set of them to loan to students. It also needed to be sophisticated enough to provide real control capabilities. The robot needed to have as many sensors as possible - we were looking for something with wheel encoders, a gyro sensor, proximity sensors, and accelerometers. Since we were teaching concepts, and having a real FRC control system was impractical for multiple reasons, we were willing to accept that we would not get Java or WPILib; but we believe that once they grasp the concepts, our programmers will be able to transition from this learning environment into the real FRC environment in a later stage of training. We chose the Pololu Zumo 32U4, an Arduino-based robot that provides a rich set of capability at a price we, or our students and parents, could afford.

Although this is an Arduino based robot, we chose to have the students use VSCode as their development environment, instead of the default Arduino IDE. VSCode has an extension that supports Arduino development, and is a far richer work environment than the functional but basic Arduino code editor. It has the significant advantage that those students who did work on the robot code (or software development as part of 6328’s scouting systems team) are already familiar with it, while new students gain familiarity with the tool. We provide setup instructions for Windows and Mac users to set up the environment.

The training program is structured as a series of challenges that focus on different aspects of robot control. We chose not to focus on the very basics of programming, since a number of our students already have working knowledge; for those completely new, or who are familiar with languages other than C/C++, we link to other tutorials that present this material, and offer one-on-one support to answer questions.

The challenges cover areas including:
* Robot operation without sensors (dead reckoning), demonstrating some of the shortcomings of this approach
* Use of wheel encoders for accurate distance travel
* Proximity sensors
* Gyro sensors (simple and advanced use)
* Line following 
* Maze solving
* Infrared sensors and remote control
* Using accelerometers
* Avoiding obstacles

For students who are able to progress past these, we offer bonus challenges that get into:
* More advanced closed-loop control including PID 
* Precise velocity control
* What’s really necessary to use a gyro sensor chip
* And more…

Not all challenges are posted at this time. Challenges are defined and the details are being developed during the summer 2020 season, with new ones posted as they are ready (at least one per week).

We intend for students to compete in a “robot mini-Sumo” challenge at the end of the summer (with social distance precautions as appropriate at the time).

## Equipment

* The robot used is from Pololu Electronics: https://www.pololu.com/category/170/zumo-32u4-robot
* The specific part number is Pololu item number 3126, an assembled robot with 75:1 gearing: https://www.pololu.com/product/3126
* Some challenges use a simple IR remote control: https://www.pololu.com/product/2777

Pololu has generously offered a discount to FIRST teams. Contact them directly for details.

We offered students the choice of borrowing a team-purchased robot or purchasing their own (as some might want to keep the robot). Roughly a third of our students chose to purchase.

We recommend purchasing a long (8 to 10 foot) micro USB cable for each robot. We found that many students attempted to use “charge only” cables which did not work. Longer cables are nice for challenges where the Arduino serial console is used for data collection from the robot.

Challenges are designed to use household items and do not require special equipment.

## Process and Support

6328 uses Slack for team communication. Our model is that all participating students in this training are members of a Slack channel in which new challenges are announced, and through which students can post questions, share their results and videos of their robots in action, and otherwise collaborate. New challenges are released on the weekend, including a video overview. There is a discussion call early in the week to go over the challenge, students have several days to work on it with support available via Slack or video chat, and then there is another call towards the end of the week to share results, discuss questions that the challenge asked, and gather feedback.

Each challenge is released here on GitHub, and includes a zip file that students unpack into a “ready to open” VSCode development folder where they can create their solution.

For other teams using our training program, 6328’s programming leads and mentors are available to answer questions at softwareremote@team6328.org
