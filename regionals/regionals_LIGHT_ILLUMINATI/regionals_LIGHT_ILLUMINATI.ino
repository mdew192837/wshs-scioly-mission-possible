/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
 
For more information see http://learn.adafruit.com/photocells */
 
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the analog resistor divider
boolean spoken = false;
 
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600); 
  pinMode(2, OUTPUT);  
}
 
void loop(void) {
  photocellReading = analogRead(photocellPin);

  digitalWrite(2, HIGH); 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);     // the raw analog reading
 
  // We'll have a few threshholds, qualitatively determined
  if (photocellReading < 250) {
    if (!spoken) {
      delay(9000); //delay to max score
      digitalWrite(2, LOW);
      Serial.println("Trigged");
      spoken = true;
    }
  }
  delay(1000);
}
