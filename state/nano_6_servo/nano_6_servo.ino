/*
 * WSHS Science Olympiad State 2018
 * @author Justin Du (MtDu)
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int RECEIVE_PIN = 2;

int SWITCH_PIN = 4;

int SEND_PIN = 13;

boolean FINISHED = false;

void setup() {
  Serial.begin(9600);
  // Set up pin 2 as HIGH
  pinMode(RECEIVE_PIN, INPUT_PULLUP);
  pinMode(SEND_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(150);
}

void loop() {
  myservo.write(150);
  if ( !digitalRead(RECEIVE_PIN) && !FINISHED ) {
    delay(500);
    myservo.write(0);
    delay(2000);
    FINISHED = true;
    delay(1000);
  }
  Serial.println(digitalRead(SWITCH_PIN));
  // SWITCH_PIN is low when circuit completes
  if ( FINISHED && !digitalRead(SWITCH_PIN) ) {
    // Writing low bc using PULL_UP functionality
    digitalWrite(SEND_PIN, LOW);
    Serial.println("DONE!");
  }
}
