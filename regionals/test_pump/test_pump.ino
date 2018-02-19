boolean triggered = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_reading = digitalRead(2);
  Serial.println(sensor_reading);
  if (sensor_reading == HIGH) {
    Serial.println("SENSOR READING HIGH");
    Serial.println(sensor_reading);  
  }
  if (sensor_reading == HIGH && !triggered) {
    Serial.println("Should be working");
    digitalWrite(13, HIGH);
    triggered = true;
    delay(1500);
  }
  else {
    digitalWrite(13, LOW);
  }
}
