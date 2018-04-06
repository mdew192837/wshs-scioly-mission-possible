/*
 * WSHS Science Olympiad State 2018
 * @author Justin Du (MtDu)
*/

// Pins we need
int RECEIVE_PIN = 2;
int SECOND_RECEIVE_PIN = 4;
int SOLENOID = 9;
int SEND_PIN = 13;

// Speeds
int SOLENOID_RUN_TIME = 500;

// Booleans
boolean TRIGGERED = false;
boolean ACTION_COMPLETE = false;

void setup() {
  Serial.begin(9600);
  pinMode(RECEIVE_PIN, INPUT_PULLUP);
  pinMode(SECOND_RECEIVE_PIN, INPUT_PULLUP);
  pinMode(SOLENOID, OUTPUT);
  pinMode(SEND_PIN, OUTPUT);
}

void loop() {
  // Until we want to trigger it
  digitalWrite(13, HIGH);

  /*
   * How this works...
   * 1. Make sure we haven't triggered before and we have a signal on 2
   * 2. Run the solenoid (which starts the marble action...)
   * 3. Stop solenoid.
   * 4. Once action is complete, send the signal to pin 13
   */
  if ( !digitalRead(RECEIVE_PIN) && !TRIGGERED ) {
    digitalWrite(SOLENOID, HIGH);
    delay(SOLENOID_RUN_TIME);
    digitalWrite(SOLENOID, LOW);
    TRIGGERED = true;
  }

  if ( !ACTION_COMPLETE && TRIGGERED && !digitalRead(SECOND_RECEIVE_PIN) ) {
    digitalWrite(13, LOW);
    // So it doesn't run again...
    ACTION_COMPLETE = true;
  }
}
