// Global variables
const uint8_t motion_led_pin = 12;
const uint8_t motion_pin = 2;

const uint8_t button_led_pin = 8;
const uint8_t button_pin = 3;

// Set up the serial monitor, input and output pins and interrupts
void setup()
{
	Serial.begin(9600);
  
    // Set the motion sensor and button pins to expect input
	pinMode(motion_pin, INPUT);
  	pinMode(button_pin, INPUT);
  
  	// Set the LED pins to provide output
	pinMode(motion_led_pin, OUTPUT);
  	pinMode(button_led_pin, OUTPUT);
  	
  	// Define interrupts for the motion detection and button press
  	attachInterrupt(digitalPinToInterrupt(motion_pin), detectMotion, CHANGE);
	attachInterrupt(digitalPinToInterrupt(button_pin), detectPress, CHANGE);
}

// Loop that is constantly run as long as power is received
void loop()
{
  	// Add a 100ms delay to simulate system usage
  	delay(100);
}
                    
// Function to run when the motion detector changes states
void detectMotion()
{
  	// If there is motion:
  	if (digitalRead(motion_pin) == HIGH)
  	{
		// Print that motion is detected
    	Serial.print("Motion: DETECTED ");
      
        // Turn the LED on
     	digitalWrite(motion_led_pin, HIGH);

     	// Print that the LED is on
     	Serial.println("| LED: ON");
    }
    
  	// If there is no motion:
  	else 
    {
    	// Print that motion is not detected
    	Serial.print("Motion: UNDETECTED ");
      
        // Turn the LED off
     	digitalWrite(motion_led_pin, LOW);

     	// Print that the LED is on
     	Serial.println("| LED: OFF");
    }
}

// Function to interrupt when the button changes states
void detectPress()
{
  	// If the button is pressed:
  	if (digitalRead(button_pin) == HIGH)
  	{
		// Print that it is pressed
    	Serial.print("Button: PRESSED ");
      
        // Turn the LED on
     	digitalWrite(button_led_pin, HIGH);

     	// Print that the LED is on
     	Serial.println("| LED: ON");
    }
    
  	// If it is not being pressed/is released:
  	else 
    {
    	// Print that button is released
    	Serial.print("Button: RELEASED ");
      
        // Turn the LED off
     	digitalWrite(button_led_pin, LOW);

     	// Print that the LED is on
     	Serial.println("| LED: OFF");
    }
}