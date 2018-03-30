/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
 
For more information see http://learn.adafruit.com/photocells */
boolean spoken = false;
 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600); 
  pinMode(2, OUTPUT);  
}
 
void loop(void) {
  if (!spoken) {
    delay(9000);
    digitalWrite(2, LOW);
    spoken = true;
  }
}
