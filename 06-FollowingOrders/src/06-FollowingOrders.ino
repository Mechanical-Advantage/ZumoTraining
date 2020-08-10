#include <Zumo32U4.h>

Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;
Zumo32U4LCD lcd;

// This enum contains all of the possible commands from the remote. The value of each item is the number received from the remote.
enum Command
{
    VolDown = 0,
    Pause = 1,
    VolUp = 2,
    Setup = 4,
    Up = 5,
    Stop = 6,
    Left = 8,
    Enter = 9,
    Right = 10,
    Num0 = 12,
    Down = 13,
    Return = 14,
    Num1 = 16,
    Num2 = 17,
    Num3 = 18,
    Num4 = 20,
    Num5 = 21,
    Num6 = 22,
    Num7 = 24,
    Num8 = 25,
    Num9 = 26
};

// This enum contains the states we move through as the message is processed.
enum State
{
    Idle,           // No message is currently being received, wait for the leading pulse
    Lead,           // The lead pulse was received, wait for it to turn off
    LeadComplete,   // The lead pulse is finished, wait for the first message pulse
    WaitForDataOff, // A message pulse is being received, wait for it to turn off
    WaitForDataOn,  // A message pulse has ended, wait for the next one
    MessageComplete // The message is complete, look for repeat signals
};

unsigned long stateChangeTime; // The last time (in microseconds) that the state changed
State state = Idle;            // The current state - this is of type "State", referencing the enum above
int readPosition = 0;          // The current bit being read from 0 to 31
int address1 = 0;              // Message byte 1/4 - this should always be 0
int address2 = 0;              // Message byte 2/4 - this should always be 191 (this doesn't follow the standard NEC protocol)
int message1 = 0;              // Message byte 3/4 - this indicates which command is being sent (as seen in the "Command" enum)
int message2 = 0;              // Message byte 4/4 - this is the logical inverse of "message1", meaning it should equal "255 - message1"

// This function is run once, when the Zumo starts up
void setup()
{
    // This clears the LCD (in case something was already on the screen when the program starts)
    lcd.clear();

    // This sets up the proximity sensors to read all three sensors. These sensors can be used to receive IR data when the emitters aren't used
    proxSensors.initThreeSensors();
}

// This function can be used to update the state
void setState(State newState)
{
    state = newState;           // Update the state
    stateChangeTime = micros(); // Save the time the state changed
}

void loop()
{
    // This records whether any of the sensors are receiving a pulse - "readBasic" reads the sensor without using the IR emitters
    bool activated = proxSensors.readBasicLeft() || proxSensors.readBasicFront() || proxSensors.readBasicRight();

    // This sets the yellow LED based on whether a pulse was detected.
    ledYellow(activated ? 1 : 0);

    // This records the time at which the measurement was taken, so that is remains constant throughout the processing logic. You can get the time since the state changed with the expression "now - stateChangeTime"
    unsigned long now = micros();

    // This switch statement run different code depending on the current state. The "break" at the end of each "case" prevents other cases from running.
    switch (state)
    {
    case Idle: // No message is currently being received, wait for the leading pulse
        if (activated)
        {
            // ADD CODE HERE - The lead pulse is starting. Use "setState" to update the state in response.
        }
        break;

    case Lead: // The lead pulse was received, wait for it to turn off
        if (!activated)
        {
            // ADD CODE HERE - The lead pulse is over. What should be updated?
        }
        break;

    case LeadComplete: // The lead pulse is finished, wait for the first message pulse
        if (activated)
        {
            // ADD CODE HERE - The first message pulse is being received. What should be updated?
        }
        else if (now - stateChangeTime > 10000)
        {
            // ADD CODE HERE - 10ms have passed since the lead pulse. This seems to be a false trigger - reset to idle.
        }
        break;

    case WaitForDataOff: // A message pulse is being received, wait for it to turn off
        if (!activated)
        {
            // ADD CODE HERE - A message pulse is complete. Remember that the pulse itself contains no data. What should be updated?
        }
        break;

    case WaitForDataOn: // A message pulse has ended, wait for the next one
        if (activated)
        {
            // ADD CODE HERE - The next pulse was detected, meaning we can record one bit! Update the address/message variables and change the state.
        }
        else if (now - stateChangeTime > 2000)
        {
            // ADD CODE HERE - It's been 2ms since the last message pulse, meaning the message is complete or there was an error. Check the integrity of the message (correct address, message bytes match) and call "runCommand" or go back to idle.
        }
        break;

    case MessageComplete: // The message is complete, look for repeat signals
        if (activated)
        {
            // ADD CODE HERE - A repeat pulse was detected, update the state to "MessageComplete" to reset the state change time
        }
        else if (now - stateChangeTime > 200000)
        {
            // ADD CODE HERE - There was no repeat pulse for 200ms, meaning the message is over. Call "goIdle"
        }
    }
}

// This function should be run once a command is complete, and should update motors, LEDs, etc. based on said command
void runCommand(Command command)
{
    // ADD CODE HERE
}

// This function should be run when a message ends to reset motors, LEDs, etc.
void goIdle()
{
    // ADD CODE HERE
}