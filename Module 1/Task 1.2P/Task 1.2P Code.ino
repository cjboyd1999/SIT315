// Set up the serial monitor, input and output pins and interrupt
void setup()
{
	Serial.begin(9600);
  
    // Set the PIR sensor pin to expect input
	pinMode(2, INPUT);
  
  	// Set the LED pin to provide output
	pinMode(13, OUTPUT);
  	
  	// Define interrupt to occur when the input changes and to run the 'detectMotion()' function
  	attachInterrupt(digitalPinToInterrupt(2), detectMotion, CHANGE);
}

// Loop that is constantly run as long as power is received
void loop()
{
  	// Add a 100ms delay to stop the Tinkercad service from lagging and to simulate system usage
  	delay(100);
}
                    
// Function to run when interrupted
void detectMotion()
{
  	// If there is motion:
  	if (digitalRead(2) == HIGH)
  	{
		// Print that motion is detected
    	Serial.print("Motion: DETECTED ");
      
        // Turn the LED on
     	digitalWrite(13, HIGH);

     	// Print that the LED is on
     	Serial.println("| LED: ON");
    }
    
  	// If there is no motion:
  	else 
    {
    	// Print that motion is not detected
    	Serial.print("Motion: UNDETECTED ");
      
        // Turn the LED on
     	digitalWrite(13, LOW);

     	// Print that the LED is on
     	Serial.println("| LED: OFF");
    }
}