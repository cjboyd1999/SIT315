# SIT315 - Task 1.3C
### Multiple Inputs Board

In this task, I created an interrupt-driven system using the following components:
- 1 x Arduino Uno
- 1 x Small breadboard
- 1 x Red LED
- 1 x Green LED
- 1 x 250Ω resistor
- 1 x PIR Sensor
- 1 x Pushbutton
- 1 x 10kΩ resistor

![Tinkercad diagram](https://raw.githubusercontent.com/cjboyd1999/SIT315/master/Module%201/Task%201.3C/Design%20Diagram.png "Tinkercad diagram")

This task was to convert my system created in [Task 1.2P](https://github.com/cjboyd1999/SIT315/tree/master/Module%201/Task%201.2P) to work with multiple inputs. I achieved this by adding a button and new LED that works almost identically to the PIR sensor; interrupt when the button changes states and turn the LED on or off depending on if it is being pressed or released.

Additionally, the serial monitor prints:
* The current status of detected/undected motion and whether the LED is currently on or off; and
* The status of the button being pressed/released and whether it's LED is currently on or off.

![Tinkercad serial monitor snippet](https://raw.githubusercontent.com/cjboyd1999/SIT315/master/Module%201/Task%201.3C/Serial%20Monitor.png "Tinkercad serial monitor snippet")

The project can be copied and simulated on Tinkercad using [this](https://www.tinkercad.com/things/jGkvk7iL40X) link.