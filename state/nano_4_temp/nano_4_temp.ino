/*
   WSHS Science Olympiad
   @author Justin Du & Nilai Vemula
*/

/********************************************************************/
// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 

// Declare ambientTemp
float AMBIENT_TEMP;

// Motor
// Transistor opens and closes the circuit
// Default is 0
int MOTOR = 9;

int TEMP_DIFFERENTIAL = 3;

int SIGNAL = 13;

boolean TRIGGERED = false;

void setup() {
  // Setting up the transistor/motor
  pinMode(MOTOR, OUTPUT);
  pinMode(TO_SIGNAL, OUTPUT);
  digitalWrite(MOTOR, LOW);
  digitalWrite(TO_SIGNAL, LOW);

  // Serial monitor Crt+Alt+M
  Serial.begin(9600);

  Serial.println("Dallas Temperature Test!");

  // Make sure we got sensor
  if (!sensor.begin()) {
    Serial.println("Did not find Temperature sensor!");
    while (true);
  }

  // Get the average temp, varies based on environment
  ambientTemp = getAverage();
  Serial.print("Ambient Temperature:          ");
  Serial.println(ambientTemp);
  Serial.print("Peltier State:                ");
  Serial.println(digitalRead(MOTOR));
}

int temperature;
void loop() {
  digitalWrite(MOTOR, LOW);
  digitalWrite(TO_SIGNAL, LOW);
  Serial.println(digitalRead(MOTOR));
  Serial.println("Requesting temps...");
  sensors.requestTemperatures();
  temperature = toFahrenheit(sensors.getTempCByIndex(0)
  Serial.print("Temperature: "); Serial.println(temperature);
  delay(1000);
  // Currently set to 3 degrees F below ambient, subject to change
  if ( digitalRead(2) && !TRIGGERED ) {
    // Analog so we can get PWM control
    analogWrite(MOTOR, 64);
    // Delay .5 s
    delay(500);
    // Make sure we stop the motor
    digitalWrite(MOTOR, LOW);
    TRIGGERED = false;
  }
  if ( temperature < ( AMBIENT_TEMP - TEMP_DIFFERENTIAL ) && TRIGGERED ) {
    digitalWrite(TO_SIGNAL, HIGH);  
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
    sensors.requestTemperatures();
    temps[i] = toFahrenheit(sensors.getTempCByIndex(0));
    sum = sum + temps[i];
    Serial.println(sum);
    Serial.println(temps[i]);
    delay(500);
  }
  return sum / 10.0;
}

