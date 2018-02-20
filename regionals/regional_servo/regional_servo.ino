/*
 * WSHS Sci Oly Servo Code
 */

#include <Servo.h>

// Sensor pin always on 2
#define SENSORPIN 2

// Create Servo object
Servo pulleyServo;

// Make sure we only trigger it once
boolean triggered = false;

// Sensor state
boolean sensorState = 0, lastState = 0;

// For testing
char move;

void setup() {
  Serial.begin(9600);
  // Servo to pin 13
  // flipCoinServo.attach(13);
  // pinMode as INPUT
  pinMode(SENSORPIN, INPUT_PULLUP);
  // turn on the pullup
  // digitalWrite(SENSORPIN, HIGH);
}

void loop() {
  // Read byte
  move = Serial.read();

  // If the signal pin is LOW
  sensorState = digitalRead(SENSORPIN);

  // If the thing is connected to ground
  if (sensorState == LOW) {
    if (move == 'm') {
      pullUp();
      move = ' ';
    }
    Serial.println(sensorState);
    Serial.println("SENSOR LOW");
  }
  else {
    Serial.println(sensorState);
    Serial.println("SENSOR HIGH");
  }
}

void pullUp() {
  pulleyServo.attach(13);
  delay(250);
  pulleyServo.detach();
}
