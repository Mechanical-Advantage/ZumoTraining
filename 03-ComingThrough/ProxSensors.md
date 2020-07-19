# Zumo Proximity Sensor Reference

The Zumo's proximity sensors are used to detect objects in front and to the sides of the robot. They do not precisely measure the position or location, but instead sense the general presense of objects in a wide range.

The proximity sensors detect objects using infared (IR) light, which is invisible to the human eye. The robot sends out pulses of IR light and detects if they are reflected back, indicating the presense of an object. This is useful, but we'd also like to determine the position of the object - its distance and directin.

## Determining Distance

The proximity sensors can determine the general distance to an object by sending out multiple pulses of varying intensity. Here's an example of how this works:

By default, the Zumo sends out 6 pulses at increasing brightness levels. It records which of the pulses were reflected back. Imagine we run two trials with an object at two distances. These are the results:

Level | Reflected? (Trial A) | Reflected? (Trial B)
--- | --- | ---
Level 1 (darkest) | :heavy_multiplication_x: | :heavy_multiplication_x:
Level 2 | :heavy_multiplication_x: | :heavy_check_mark:
Level 3 | :heavy_multiplication_x: | :heavy_check_mark:
Level 4 | :heavy_multiplication_x: | :heavy_check_mark:
Level 5 | :heavy_check_mark: | :heavy_check_mark:
Level 6 (brightest) | :heavy_check_mark: | :heavy_check_mark:

In which trial was the object closer to the robot?

<details>
    <summary>Answer</summary>
    The object was closer during trial B. When the object is closer to the robot, it reflects more light. Therefore, the pulse doesn't have to be as bright for the light to be detected. In trial A, levels 1-4 were not detected because the object was too far away for enough light to be reflected.
</details>

The proximity sensors report the number of brightness levels that were detected, allowing you to estimate the distance to an object.

## Determining Position

The general location of objects can be determined using the various positions of the IR emitters and sensors. The Zumo has emitters of the left and right sides of the robot. On each side, one emitter is directly on the side while another is in front, marked below. These two emitters always operate together, but each set (side) is controlled independently.

![Diagram of side emitters](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/development/resources/03-emitters.png)

The Zumo has 3 IR sensors - on the left, front, and right sides of the robot. They are visible on the front sensor array under the robot, seen below. Each of these sensors can be read independently.

![Diagram of sensors](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/development/resources/03-sensors.png)

This diagram shows the overall positions of the emitters and sensors top-down:

![Overview diagram of proximity sensors](https://raw.githubusercontent.com/Mechanical-Advantage/Training2020/development/resources/03-overview.png)

When you read the proximity sensors, a series of pulses (see previous section) are sent out on one side, then the other. You can then read the number of brightness levels detected by each of the sensors from the left and right sides - 6 values in total. Feel free to reference this table to see how/why to use each value:

Emitter | Sensor | Method | Purpose
--- | --- | --- | ---
Left | Left | ```countsLeftWithLeftLeds()``` | Detects objects directly to the left.
Right | Left | ```countsLeftWithRightLeds()``` | Detects wider presense of objects, particularly on the left. *Not reliable.*
Left | Front | ```countsFrontWithLeftLeds()``` | Detects objects in front and slightly left.
Right | Front | ```countsFrontWithRightLeds()``` | Detects objects in front and slightly right.
Left | Right | ```countsRightWithLeftLeds()``` | Detects wider presense of objects, particularly on the right. *Not reliable.*
Right | Right | ```countsRightWithRightLeds()``` | Detects objects directly to the right.