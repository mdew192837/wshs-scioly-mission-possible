/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
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
boolean STARTED = false;
boolean FINISHED = false;

void setup() {
  Serial.begin(9600);
  pinMode(READ_PIN, INPUT_PULLUP);
  pinMode(CIRCUIT_PIN, INPUT_PULLUP);
  pinMode(SEND_PIN, OUTPUT);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  while ( !STARTED && !FINISHED ) {
    // Make sure we haven't ran the pump
    // AND
    // The pullup resistor is now LOW
    if ( !STARTED && !digitalRead(RECEIVE_PIN) ) {
      // Speed ranges from 0-255
      // We'll just do 50 as low
      analogWrite(PUMP_PIN, SLOW_SPEED);
      delay(PUMP_RUN_TIME);
      // Pump off
      analogWrite(PUMP_PIN, 0);
      // Update boolean so we don't run the pump again
      STARTED = true;
    }
  }
  // Make sure pump has run and we haven't triggered already
  if ( STARTED && !FINISHED ) {
    // Note to self: If for some reason it doesn't work...
    // Just take out the if! :)
    if ( !digitalRead(CIRCUIT_PIN) ) {
      // Send dat signal!
      digitalWrite(SEND_PIN, HIGH);
      FINISHED = true;
    }
  }
}
