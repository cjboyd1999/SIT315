# SIT315 - Task 1.2P
### Interrupt-driven Board

In this task, I created an interrupt-driven system using the following components:
- 1 x Arduino Uno
- 1 x Small breadboard
- 1 x Red LED
- 1 x 250Ω resistor
- 1 x PIR Sensor

![Tinkercad diagram](https://raw.githubusercontent.com/cjboyd1999/SIT315/master/Module%201/Task%201.2P/Design%20Diagram.png "Tinkercad diagram")

This task was to convert my system created in [Task 1.1P](https://github.com/cjboyd1999/SIT315/tree/master/Module%201/Task%201.1P) to utilise interrupts instead of a single loop. I achieved this by moving the code that checked the sensor's input and changed the LED's status to a new function which is now called whenever the input from the sensor changes from LOW to HIGH or vice versa.

Additionally, the serial monitor outputs the current status of detected/undected motion and whether the LED is currently on or off.

![Tinkercad serial monitor snippet](https://raw.githubusercontent.com/cjboyd1999/SIT315/master/Module%201/Task%201.2P/Serial%20Monitor.png "Tinkercad serial monitor snippet")

The project can be copied and simulated on Tinkercad using [this](https://www.tinkercad.com/things/jQiL88t0UdO) link.