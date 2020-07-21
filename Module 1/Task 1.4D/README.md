# SIT315 - Task 1.4D
### More Inputs Timer Board

In this task, I created an interrupt-driven system using the following components:
- 1 x Arduino Uno
- 1 x Small breadboard
- 1 x Mini breadboard
- 1 x Red LED
- 1 x Green LED
- 1 x Yellow LED
- 1 x Blue LED
- 1 x 250Ω resistor
- 2 x 10kΩ resistor
- 1 x PIR Sensor
- 2 x Pushbutton

https://www.teachmemicro.com/arduino-interrupt-tutorial/

![Tinkercad diagram](https://raw.githubusercontent.com/cjboyd1999/SIT315/master/Module%201/Task%201.4D/Diagram.png "Tinkercad diagram")

This task was to convert my system created in [Task 1.3C](https://github.com/cjboyd1999/SIT315/tree/master/Module%201/Task%201.3C) to work with both another input for an interrupt and a timer interrupt. I achieved this by adding another button and new LED that works identically to the other; interrupt when the button changes states and turn the LED on or off depending on if it is being pressed or released.

The timer's ISR works identically to the others, when called it turns the LED on or off. 

Additionally, the serial monitor prints:
* Which interrupt ocurred (Motion, button, button2 or timer)
* The status of the LED for that given interrupt (on or off).

![Tinkercad serial monitor snippet](https://raw.githubusercontent.com/cjboyd1999/SIT315/master/Module%201/Task%201.4D/Serial%20Monitor.png "Tinkercad serial monitor snippet")

The project can be copied and simulated on Tinkercad using [this](https://www.tinkercad.com/things/laewfSZTbV2) link.