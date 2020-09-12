# Introduction to Object-Oriented Programming

Many older programming language like C are *procedural*. This means that programs are designed around the execution of a series of procedures (often called "functions"). However, most newer languages like Java, Python, Swift, or C++ (which we're using for the Zumos) are *object-oriented*. What does that mean?

> An object-oriented language enables a system to be modeled as a set of objects that contain data and provide well defined interfaces for interacting with that data.

This may sound complicated, but it's actually simpler than it appears. This is because object-oriented programming often matches the way systems work in the real world far better than procedural programming. In complex projects (like FRC robot code), using an object-oriented language vastly simplifies the code.

## Classes vs. Objects

* A **class** is a "blueprint" or "recipe" that describes the data and interfaces that make up an object. It's a template for making objects of a particular kind.

* An **object** is an *instance* of a class. It doesn't exist until it is *instantiated*. There can be many instances of the same class, each with its own copy of the data in the object.

Let's use some real world examples to understand the difference between classes and objects.

Class | Object | Explanation
--- | --- | ---
Cookie cutter | Cookie | The cookie cutter describes the form that the cookie takes. It can be used to make many cookies.
Cat | Your cat | The fact that your pet is a "cat" defines the form it takes and what it can do. However, there are many instances of "cat" (many cats) each with their own memories and personalities (data).
Car model (eg. 2012 Honda Civic) | Your car | All cars of the same model have the same functions, but yours has its own "data" (different usage/wear, customizations, bumper stickers, etc.)

## Keeping Data Private - Encapsulation

In object-oriented systems, each object should keep its internal state (data) private. Other objects can only access this data in the ways the object allows. This means the object has control over how the data can be used and interacted with. Again, let's use some real world examples:

* You can feed your cat, but you can't directly change how hungry your cat is. Likewise, you can see when your cat want you to feed them, but you can't directly read how hungry your cat is.

* You can drive your car, but you can't directly change the amount of gas in the gas tank.

* You can plug in your phone to charge, but you can't directly change the charge level.

## Interacting With Data - Abstraction

Since an object stores private data, other objects need a way to interact with that data. Therefore, each object should expose a high-level mechanism for using it. This is its *interface*. This mechanism should hide internal implementation details. It should only reveal operations relevant for the other objects. This also means that an object's internal implementation can change without affecting the system, as long as the interface remains the same. Here are some examples:

* When using your phone, you have just a few buttons and inputs to use (the *interface*). You don't have to understand what's happening under the hood (the *implementation*). Using the phone remains simple despite its complexity.

* When driving a car, you have a limited number of controls (steering wheel, pedals, etc.) You don't have to understand what's happening under the hood (literally). This also means that the *implementation* can change without affecting the *interface*. For example, an electric car is controlled the same as a gas model even though the implementation is completely different!

## Methods and Attributes

Thus far, we've used the words "data" and "interface" to describe the pieces of a class. However, we generally use different terms:

* An object's data are its **attributes**. Attributes are variables within a class.

* An object's implementation is made of **methods**. Methods are functions within a class.

For example, a car might have *attributes* for `fuel` and `maxSpeed` plus *methods* for `refuel()`, `setSpeed()`, and `getSpeed()`.

## FRC Robot Code

It may still be difficult to see how a structure like this is simpler than procedural programming. Let's look at a simple example from the FRC robot code. Our physical robots can each be broken into a set of *subsystems* such as:

* Drive train

* Intake

* Elevator

* Shooter

Our robot code matches this physical structure by defining a class for each type of subsystem, each with a single instance (since the robot only has one of each subsystem!) Each subsystem contains private data that isn't relevant to other objects such as:

* Individual motor controllers

* Position of mechanisms

* State of pneumatics

These are only part of a single subsystem, so they aren't exposed. To interact with them, each subsystem provides methods like `moveToPosition()` or `setSpeed()`. The other parts of the robot code don't know or care about how the subsystem's implementation works (like which motor controllers are being used).

This structure simplifies the robot code because each piece is only exposed to the relevant data and interfaces. It also makes more sense logically, because it matches the physical structure of the robot.