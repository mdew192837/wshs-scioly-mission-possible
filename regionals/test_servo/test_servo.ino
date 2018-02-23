/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object
  myservo.write(100);
}

void loop() {
  myservo.write(170);
  //  for (int spd = 90; spd >= 0; spd += 5) {
  //    myservo.write(spd);
  //    delay(2000);
  //  }
  //  myservo.write(100);
  //  Serial.println(myservo.read());
  //  delay(500);
  //  myservo.write(0);
  //  Serial.println(myservo.read());
  //  delay(500);
  Serial.println(myservo.read());
//  for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    Serial.println(myservo.read());
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(1000);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
//    Serial.println(myservo.read());
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(1000);                       // waits 15ms for the servo to reach the position
//  }
}
