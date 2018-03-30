#include <Servo.h>

/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void setup() {
  Serial.begin(9600);
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(100);
  delay(1000);
  myservo.write(150);
  delay(1000);
}
