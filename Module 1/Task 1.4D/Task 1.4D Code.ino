// INITIALISE GLOBAL VARIABLES
const uint8_t motion_led_pin = 12;
const uint8_t motion_pin = 2;
volatile byte motion_led_state = LOW;

const uint8_t button_led_pin = 11;
const uint8_t button_pin = 8;
volatile byte button_led_state = LOW;

const uint8_t button2_led_pin = 10;
const uint8_t button2_pin = 0;
volatile byte button2_led_state = LOW;

const uint8_t timer_led_pin = 13;
volatile byte timer_led_state = LOW;

// Setup function
void setup()
{
	Serial.begin(115200); // Start the serial monitor

	pinMode(motion_led_pin, OUTPUT);
	pinMode(motion_pin, INPUT_PULLUP);
	PCMSK2 = B00000100; // Enable PCINT18 (pin change interrupt for digital pin 2)

  	pinMode(button_led_pin, OUTPUT);
	pinMode(button_pin, INPUT_PULLUP);
	PCMSK0 = B00000001; // Enable PCINT0 (pin change interrupt for digital pin 8)

	pinMode(button2_led_pin, OUTPUT);
	pinMode(A0, INPUT_PULLUP);
	PCMSK1 = B00000001; // Enable PCINT8 (pin change interrupt for analog pin 0)

	PCIFR = B00000000; // Clear all interrupt flags
	PCICR = B00000111; // Enable PCIE0, PCIE1 and PCIE2

	pinMode(timer_led_pin, OUTPUT);
	TCCR1A = 0; // Set the TCCR1A register to 0
	TCCR1B = 0; // Set the TCCR1B register to 0
	TCCR1B |= (1 << CS12) | (1 << CS10); // Set the CS12 and CS10 bits for a prescaler of 1024
	TIMSK1 |= (1 << TOIE1); // Enable timer overflow
}

// Empty loop
void loop()
{
}

// A function to return the current state of an LED as "On" or "Off"
String getState(byte state)
{
	if (state == HIGH) { return "On"; }
	else if (state == LOW) { return "Off"; }
	else { return "Error"; }
}
                    
// Function to interrupt when the motion detector changes states
ISR(PCINT2_vect)
{
	Serial.print("INTERRUPT: Motion Sensor "); // Print which interrupt happened to the serial monitor
	motion_led_state = !motion_led_state; // Change the state to HIGH or LOW (opposite of current)
	Serial.println(" | STATE: " + getState(motion_led_state)); // Print the state of the LED
	digitalWrite(motion_led_pin, motion_led_state);
}

// Function to interrupt when the button changes states
ISR(PCINT0_vect)
{
	Serial.print("INTERRUPT: Green Button  ");
	button_led_state = !button_led_state;
	Serial.println(" | STATE: " + getState(button_led_state));
	digitalWrite(button_led_pin, button_led_state);	
}

// Function to interrupt when the second button changes states
ISR(PCINT1_vect)
{
	Serial.print("INTERRUPT: Blue Button   ");
	button2_led_state = !button2_led_state;
	Serial.println(" | STATE: " + getState(button2_led_state));
	digitalWrite(button2_led_pin, button2_led_state);
}

// Function to interrupt when the timer overflows (occurs roughly every 4 seconds)
ISR(TIMER1_OVF_vect)
{
	Serial.print("INTERRUPT: Timer         ");
	timer_led_state = !timer_led_state;
	Serial.println(" | STATE: " + getState(timer_led_state));
	digitalWrite(timer_led_pin, timer_led_state);
}