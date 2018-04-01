/*
 * WSHS Science Olympiad State 2018
 * @author Justin Du (MtDu)
*/

// Pins we need
int RECEIVE_PIN = 2;
int SEND_PIN = 13;

// Speeds
int HIGH_SPEED = (int) .75 * 255;
int MOTOR_RUN_TIME = 5000;

// Booleans
boolean TRIGGERED = false;

// Beam Stuff
int sensorState = 0, lastState=0;

void setup() {
  Serial.begin(9600);
  // Might need to set it to input
  // And write it to HIGH
  pinMode(RECEIVE_PIN, INPUT_PULLUP);
  pinMode(SEND_PIN, OUTPUT);
}

void loop() {
  sensorState = digitalRead(RECEIVE_PIN);
  /*
   * How this works...
   * If sensorState is high, then it means beam is still there
   * If lastState is 0, means the beam was broken before but isn't now
   */
  if (sensorState && !lastState) {
    Serial.println(sensorState);
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
    // Make sure we don't trigger it accidentally
    if (!TRIGGERED) {
      digitalWrite(SEND_PIN, HIGH);
      TRIGGERED = true;
    }
  }
  lastState = sensorState;
}
