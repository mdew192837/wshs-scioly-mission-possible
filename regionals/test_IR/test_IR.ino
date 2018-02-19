/* 
 * 
 */

#define LEDPIN 13
  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

#define SENSORPIN 4

// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

// TO-DO ensure our action only happens one time

void setup() {
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup

  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);

  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
  }
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW);
  }
  
  if (sensorState && !lastState) {
    Serial.println(sensorState);
    // INSERT - This is where our code should go
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  /* 
   * If it's unbroken, lastState will be 1 until you break it
   * Then immediately after you break, sensor state will be 0 (negated to 1) and lastState is 1
   * Which makes it broken
   * But after it's broken, lastState = 0, so it won't print again
   * Logic persists for vice versa (it'll be unbroken when sensor state becomes 1 bc
   * the lastState will be 0 (negated to 1) initially, then it'll be negated to false
   */
  lastState = sensorState;
}
