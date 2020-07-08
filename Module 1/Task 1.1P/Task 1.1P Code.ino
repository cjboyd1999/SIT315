// Set a constant integer of the analog pin being used
const int tempPin = 0;

// Setup the Arduino to output to digital pin 13
void setup()
{
	pinMode(13, OUTPUT);
}

// Loop to check the current temperature and act upon it changing
void loop()
{
  // Define a float for voltage and degrees Celsius
  float voltage, degreesC;
  
  // Convert the 0-1023 analog input to its real voltage between 0.0 and 5.0
  voltage = analogRead(tempPin) * 0.004882814;
  
  // Convert the voltage into its corresponding temperature in degrees Celcius
  degreesC = (voltage - 0.5) * 100.0;
  
  // Check if the temperature is over 30 degrees Celsius, if so turn the LED on
  if (degreesC > 30)
  {
  	digitalWrite(13, HIGH);
  }
  
  // If the temperature is NOT over 30 degrees Celsius, turn the LED off
  else
  {
  	digitalWrite(13, LOW); 
  }
}