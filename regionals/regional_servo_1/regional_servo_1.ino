/*
 * WSHS Sci Oly Servo Code
 * For calibrating purposes, go to regional_servo
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

void setup() {
  Serial.begin(9600);
  // Servo to pin 13
  // flipCoinServo.attach(13);
  /*
   * Pin 2 serves as a pullup resistor
   * When we complete the circuit, the sensor pin goes to ground
   * And the sensor reads LOW
   * Otherwise, it reads HIGH, because it's not connected to anything
   */
  pinMode(SENSORPIN, INPUT_PULLUP);
  // turn on the pullup
  // digitalWrite(SENSORPIN, HIGH);
}

void loop() {
  // If the signal pin is LOW
  sensorState = digitalRead(SENSORPIN);

  // If the thing is connected to ground
  if (sensorState == LOW && !triggered) {
    pullUp();
    triggered = true;
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
  // Calibrated using 250 ms increments
  delay(50 * 250);
  pulleyServo.detach();
}
