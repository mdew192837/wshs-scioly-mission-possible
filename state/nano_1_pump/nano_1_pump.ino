/*
 * WSHS Science Olympiad State 2018
 * @author Justin Du (MtDu)
*/

// Pins we need
int READ_PIN = 2;
int CIRCUIT_PIN = 3;
int PUMP_PIN = 9;
int SEND_PIN = 13;

// Speeds
int SLOW_SPEED = 50;
int PUMP_RUN_TIME = 5000;

// Booleans
boolean ACTION_STARTED = false;
boolean ACTION_FINISHED = false;

void setup() {
  Serial.begin(9600);
  pinMode(READ_PIN, INPUT_PULLUP);
  pinMode(CIRCUIT_PIN, INPUT_PULLUP);
  pinMode(SEND_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  // Until we want to trigger it
  digitalWrite(SEND_PIN, HIGH);

  // Make sure we haven't ran the pump
  // AND
  // The pullup resistor is now LOW
  if ( !ACTION_STARTED && !ACTION_FINISHED && !digitalRead(RECEIVE_PIN ) {
    // Speed ranges from 0-255
    // We'll just do 50 as low
    analogWrite(PUMP_PIN, SLOW_SPEED);
    delay(PUMP_RUN_TIME);
    // Pump off
    analogWrite(PUMP_PIN, 0);
    // Update boolean so we don't run the pump again
    ACTION_STARTED = true;
  }

  // Make sure pump has run and we haven't triggered already
  if ( ACTION_STARTED && !ACTION_FINISHED ) {
    // Note to self: If for some reason it doesn't work...
    // Just take out the if! :)
    if ( !digitalRead(CIRCUIT_PIN) ) {
      // Send dat signal!
      // It's low bc we are using PULL_UP functionality
      // So LOW will be sensed... :)
      digitalWrite(SEND_PIN, LOW);
      ACTION_FINISHED = true;
    }
  }
}
