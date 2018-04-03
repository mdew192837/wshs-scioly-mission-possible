/*
 * WSHS Science Olympiad State 2018
 * @author Justin Du (MtDu)
*/

// Pins we need
int RECEIVE_PIN = 2;
int SOLENOID = 9;

// Speeds
int SOLENOID_RUN_TIME = 500;

// Booleans
boolean TRIGGERED = false;

void setup() {
  Serial.begin(9600);
  pinMode(RECEIVE_PIN, INPUT_PULLUP);
  pinMode(SOLENOID, OUTPUT);
}

void loop() {
  /*
   * How this works...
   * 1. Make sure we haven't triggered before and we have a signal on 2
   * 2. Run the solenoid (which starts the marble action...)
   * 3. Stop solenoid.
   */
  if ( !digitalRead(RECEIVE_PIN) && !TRIGGERED ) {
    digitalWrite(SOLENOID, HIGH);
    delay(SOLENOID_RUN_TIME);
    digitalWrite(SOLENOID, LOW);
    TRIGGERED = true;
  }
}
