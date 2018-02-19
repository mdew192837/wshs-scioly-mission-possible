/*
 * WSHS Sci Oly - Pump Code
 */

// Only want this pump to trigger one time
boolean triggered = false;

// So that we only print "Not Triggered" when it changes
boolean lastState = false;

// Amount of time we want to run the pump (in ms)
int runPumpTime = 500;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  // When magnet is present, the sensor reads low, so we negate it to get true
  int magnetPresent = !digitalRead(2);
  if (magnetPresent && !lastState) {
    Serial.println("Not Triggered");
    Serial.println(magnetPresent);  
  }
  if (!magnetPresent && !triggered) {
    Serial.println("Triggered");
    // digitalWrite(13, HIGH);
    triggered = true;
    delay(runPumpTime);
  }
  else {
    digitalWrite(13, LOW);
  }
  lastState = magnetPresent;
}
