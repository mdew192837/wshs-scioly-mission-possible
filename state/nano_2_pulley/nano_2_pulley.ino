/*
 * WSHS Science Olympiad State 2018
 * @author Justin Du (MtDu)
*/

// Pins we need
int RECEIVE_PIN = 2;
int MOTOR_PIN = 9;
int SEND_PIN = 13;

// Speeds
int HIGH_SPEED = (int) .75 * 255;
int MOTOR_RUN_TIME = 5000;

// Booleans
boolean TRIGGERED = false;

void setup() {
  Serial.begin(9600);
  pinMode(RECEIVE_PIN, INPUT_PULLUP);
  pinMode(SEND_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  /*
   * How this works...
   * 1. Turn motor on (ONLY IF RECEIVE IS LOW AND HASN'T ALREADY BEEN TRIGGERED)
   * 2. Leave motor on for 5s
   * 3. Turn motor off
   * 4. Set triggered to True
   */
  if ( !digitalRead(RECEIVE_PIN) && !TRIGGERED ) {
    analogWrite(9, HIGH_SPEED);
    delay(MOTOR_RUN_TIME);
    analogWrite(9, 0);
    TRIGGERED = true;
  }
}
