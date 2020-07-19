# Zumo Proximity Sensor Reference

The Zumo's proximity sensors are used to detect objects in front and to the sides of the robot. They do not precisely measure the position or location, but instead sense the general presense of objects in a wide range.

The proximity sensors detect objects using infared (IR) light, which is invisible to the human eye. The robot sends out pulses of IR light and detects if they are reflected back, indicating the presense of an object. This is useful, but we'd also like to determine the position of the object - its distance and directin.

## Determining Distance

The proximity sensors can determine the general distance to an object by sending out multiple pulses of varying intensity. Here's an example of how this works:

By default, the Zumo sends out 6 pulses at increasing brightness levels. It records which of the pulses were reflected back. Imagine we run two trials with an object at two distances. These are the results:

Level | Reflected? (Trial A) | Reflected? (Trial B)
--- | --- | --- | ---
Level 1 (darkest) | :heavy_multiplication_x: | :heavy_multiplication_x:
Level 2 | :heavy_multiplication_x: | :heavy_check_mark:
Level 3 | :heavy_multiplication_x: | :heavy_check_mark:
Level 4 | :heavy_multiplication_x: | :heavy_check_mark:
Level 5 | :heavy_check_mark: | :heavy_check_mark:
Level 6 (brightest) | :heavy_check_mark: | :heavy_check_mark: