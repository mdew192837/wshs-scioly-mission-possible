/* 
 * WSHS Sci Oly IR Code
 */
#include <Servo.h>

// Create Servo object
Servo flipServo;

  // Pin 13: Arduino has an LED connected on pin 13
  // Pin 11: Teensy 2.0 has the LED on pin 11
  // Pin  6: Teensy++ 2.0 has the LED on pin 6
  // Pin 13: Teensy 3.0 has the LED on pin 13

#define SENSORPIN 2

// variables will change:
int sensorState = 0;         // variable for reading the pushbutton status

// TO-DO ensure our action only happens one time
boolean triggered = false;

void setup() {
  // initialize the LED pin as an output:
  // pinMode(LEDPIN, OUTPUT);
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  flipServo.attach(13);
  flipServo.write(150);

  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);

  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    // Serial.println("LOW");
//    digitalWrite(LEDPIN, HIGH);  
  }
  else {
    if (!triggered) {
      // turn LED off:
      Serial.println("HIGH");
      flipServo.write(180);
      flip();
      triggered = true;
    }
//    digitalWrite(LEDPIN, LOW);
  }
  
  /* 
   * If it's unbroken, lastState will be 1 until you break it
   * Then immediately after you break, sensor state will be 0 (negated to 1) and lastState is 1
   * Which makes it broken
   * But after it's broken, lastState = 0, so it won't print again
   * Logic persists for vice versa (it'll be unbroken when sensor state becomes 1 bc
   * the lastState will be 0 (negated to 1) initially, then it'll be negated to false
   */
}

void flip() {
//  flipServo.attach(13);
//  // Calibrated using 250 ms increments
//  flipServo.write(160);
//  Serial.println("Should be 160");
//  delay(3000);
//  flipServo.write(180);
//  Serial.println("Should be 180");
//  delay(3000);
//  flipServo.write(150);
  Serial.println(flipServo.read());
  Serial.println("RAN");
}
