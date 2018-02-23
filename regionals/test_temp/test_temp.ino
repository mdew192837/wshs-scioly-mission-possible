/*
 * WSHS Science Olympiad
 * @author Justin Du & Nilai Vemula
 */

#include "Adafruit_Si7021.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();

// Declare ambientTemp
float ambientTemp;

// Peltier Pin
// Same as transistor
// Default is 0
int PELTIER = 12;

void setup() {
  // Setting up the pin
  pinMode(PELTIER, OUTPUT);
  digitalWrite(PELTIER, LOW);

  // Serial monitor Crt+Alt+M
  Serial.begin(9600);

  Serial.println("Si7021 test!");

  // Make sure we got sensor
  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true);
  }

  // Get the average temp, varies based on environment
  ambientTemp = getAverage();
  Serial.print("Ambient Temperature:          ");
  Serial.println(ambientTemp);
  Serial.print("Peltier State:                ");
  Serial.println(digitalRead(PELTIER));
}

void loop() {
  Serial.println(digitalRead(PELTIER));
  Serial.print("Humidity:    "); Serial.print(sensor.readHumidity(), 2);
  Serial.print("\tTemperature: "); Serial.println(toFahrenheit(sensor.readTemperature()), 2);
  delay(1000);
  // Currently set to 3 degrees F below ambient, subject to change
  if ( toFahrenheit(sensor.readTemperature()) < ( ambientTemp - 3 ) ) {
    // Should just write PELTIER to high here
    digitalWrite(2, LOW);
  }
}

float toFahrenheit(float tempInCelcius) {
  return tempInCelcius * 1.8 + 32;
}

// Get average temp in .5s intervals
// Uses 10 data points
float getAverage() {
  int i;
  float sum = 0;
  float temps[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (i = 0; i < 10; i = i + 1) {
    temps[i] = toFahrenheit(sensor.readTemperature());
    sum = sum + temps[i];
    Serial.println(sum);
    Serial.println(temps[i]);
    delay(500);
  }
  return sum / 10.0;
}

