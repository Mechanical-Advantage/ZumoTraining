# Challenge #2: Precision, Please - Post Challenge Review

This information should be reviewed by students indivdually after completion of the challenge or together at the challenge review meeting.

## Calculating Ticks/Inch

While the challenge suggests calculating the conversion from encoder ticks to inches through trial and error, this value can be calculating using the gear ratio of the Zumos:

![Diagram showing how to calculate ticks/inch](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-encoder-translation.jpg)

## Possible Approaches

There are a wide variety of ways to complete this challenge. The goal is to find an approach which:

* Reaches the target as quickly as possible

* Ends up very close to the target

* Doesn't overshoot the target

Let's review some possible approaches using these criteria! To compare approaches, each has been run on an actual Zumo and the encoder value is graphed over time.

### Approach #1: Stop on Target

*Drives at speed 300 until it reaches 12 inches, then stops.*

![Graph of approach #1](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-approach-1.png)

This system is one of the simplest possible, and it reaches the target (12 inches) very quickly. However, it overshoots a large amount and so is not very accurate. How could the accuracy be improved?

### Approach #2: Stop on Target (Slower)

*Drives at speed 120 until it reaches 12 inches, then stops.*

![Graph of approach #2](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-approach-2.png)

By decreasing the speed, the overshoot is reduced significantly meaning the final result is more accurate than the first approach. However, reducing the speed means that the movement takes far longer.

### Approach #3: Stop on Target and Return

*Drives at speed 300 until it reaches 12 inches, then backs up at speed 100 until less than 12 inches.*

![Graph of approach #3](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-approach-3.png)

This is a possible compromise between the first two approaches because it is nearly as fast as the first one with the accuracy of the second. However, it still overshoots signifcantly. Ideally, it should stop at the target on the first attempt.

### Approach #4: Proportional Control (Low Gain)

*Drives at speed (distance remaining * 25).*

![Graph of approach #4](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-approach-4.png)

This is an improved way to get both speed and accuracy without overshoot. The principle of proprotional control is that movement is quicker depending on the distance to the target. This reduces the time the movement takes without sacrificing accuracy (since slow movement is used near the end). When using proportional control, the key is to choose the right "gain" - the factor used in the formula. This example shows what happens when the gain is too low. Eventually, the requested speed falls below the minimum speed where the robot will move, causing it to fall short of the target.

### Approach #5: Proportional Control (Very High Gain)

*Drives at speed (distance remaining * 40,000).*

![Graph of approach #5](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-approach-5.png)

This example shows what happens when the gain is too high. The robot tends to move back and forth across the target multiple time, potentially (as in this case) never finishing the movement. This is called "oscillation". Proportional control works best when you find the "sweet spot" for the gain, where the movement completes without oscillation.

### Approach #6: Proportional Control with Minimum Speed

*Drives at speed (distance remaining * 150), with a minimum speed of 70.*

![Graph of approach #6](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/master/resources/02-approach-6.png)

In some situtations, proportional control can be improved preventing the motors from running below a set speed. This prevents the problem with approach #4, where the motors stop moving short of the target. This approach allows the robot to move quickly and accurately without overshoot.

## Event Loops

During this challenge, you may have encoutered difficulty when figuring out how to structure the code (given that it requires multiple independent movements). In this and future challenge, it is important to understand the event loop structure, which allows code to be complex and expandable. For example, imagine we want the red LED to toggle on and off when we press the A button. Here's a simple way to accomplish that task:

```c
void loop()
{
    buttonA.waitForPress();
    ledRed(1);
    buttonA.waitForPress();
    ledRed(0);
}
```

This is effective, but it does not follow the event loop structure - the main loop is forced to stop and wait for input. When writing an event loop, the main loop should always be running (taking in input as it goes). We could rewrite the above code like this:

```c
bool redOn = false;

void loop()
{
    if (buttonA.getSingleDebouncedPress())
    {
        redOn = !redOn; // Toggle "redOn"
        ledRed(redOn ? 1 : 0); // Set the LED based on "redOn"
    }
}
```

This is signifcantly more complex, so it may seem counterproductive. However, the advantage to using this event loop structure is that it is far more expandable. For example, we might also want to make the B button toggle the yellow LED. This is impossible in the first example but easy in an event loop:

```c\
bool redOn = false;
bool yellowOn = false;

void loop()
{
    if (buttonA.getSingleDebouncedPress())
    {
        redOn = !redOn; // Toggle "redOn"
        ledRed(redOn ? 1 : 0); // Set the LED based on "redOn"
    }
    

    // Duplicate the above code to handle the yellow LED
    if (buttonB.getSingleDebouncedPress())
    {
        yellowOn = !yellowOn; // Toggle "yellowOn"
        ledYellow(yellowOn ? 1 : 0); // Set the LED based on "yellowOn"
    }
}
```

As the challenges become more complex, following this event loop structure will make it far easier to create complex programs.