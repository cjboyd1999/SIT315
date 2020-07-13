// Set up the serial monitor, input and output pins
void setup()
{
	Serial.begin(9600);
  
    // Set pin 2 to receive input(PIR Sensor)
	pinMode(2, INPUT);
  
  	// Set pin 13 to give output(LED)
	pinMode(13, OUTPUT);
}

// Loop that is constantly run as long as power is received
void loop()
{
  	// If the PIR Sensor detects motion:
	if(digitalRead(2) == HIGH)
    {
      	// Print that motion is detected
    	Serial.print("Motion: DETECTED ");
      
      	// Turn the LED on
      	digitalWrite(13, HIGH);
      
      	// Print that the LED is on
      	Serial.println("| LED: ON");
    }
  	
    // Otherwise, the PIR Sensor is not detecting motion, so:
  	else
    {
      	// Print that motion is not detected
      	Serial.print("Motion: NOT DETECTED ");
      
      	// Turn the LED off (incase it was on)
      	digitalWrite(13, LOW);
      
      	// Print that the LED is off
      	Serial.println("| LED: OFF");
    }
  
  	// Add a 100ms delay to stop the Tinkercad service from lagging
  	delay(100);
}