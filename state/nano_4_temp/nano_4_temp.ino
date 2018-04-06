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
#define ONE_WIRE_BUS 4
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
int MOTOR_PIN = 9;

int RECEIVE_PIN = 2;

int TEMP_DIFFERENTIAL = 2;

int SIGNAL_PIN = 13;

// Pump Stuff
int PUMP_SPEED = 255;
int PUMP_RUN_TIME = 1000;

boolean TRIGGERED = false;

void setup() {
  // Setting up the transistor/motor
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(SIGNAL_PIN, OUTPUT);
  pinMode(RECEIVE_PIN, INPUT_PULLUP);
  digitalWrite(MOTOR_PIN, LOW);
  digitalWrite(SIGNAL_PIN, HIGH);

  // Serial monitor Crt+Alt+M
  Serial.begin(9600);

  Serial.println("Dallas Temperature Test!");

  // Begin getting data
  sensors.begin();

  // Get the average temp, varies based on environment
  AMBIENT_TEMP = getAverage();
  Serial.print("Ambient Temperature:          ");
  Serial.println(AMBIENT_TEMP);
  Serial.print("Peltier State:                ");
  Serial.println(digitalRead(MOTOR_PIN));
}

int temperature;
void loop() {
  // Motor 0 if nothing
  Serial.println("RECEIVE PIN");
  Serial.println(digitalRead(RECEIVE_PIN));
  digitalWrite(MOTOR_PIN, 0);
  digitalWrite(SIGNAL_PIN, HIGH);
  Serial.println("Requesting temps...");
  sensors.requestTemperatures();
  temperature = toFahrenheit(sensors.getTempCByIndex(0));
  Serial.print("Temperature: "); Serial.println(temperature);
  delay(1000);
  // Currently set to 3 degrees F below ambient, subject to change
  // Make sure IR triggers us
  if ( !digitalRead(RECEIVE_PIN) && !TRIGGERED ) {
    Serial.println("Should have ran.");
    // Analog so we can get PWM control
    analogWrite(MOTOR_PIN, PUMP_SPEED);
    // Delay .5 s
    delay(500);
    // Make sure we stop the motor
    digitalWrite(MOTOR_PIN, PUMP_RUN_TIME);
    TRIGGERED = true;
  }
  if ( temperature < ( AMBIENT_TEMP - TEMP_DIFFERENTIAL ) && TRIGGERED ) {
    Serial.println("SENT SIGNAL");
    digitalWrite(SIGNAL_PIN, LOW);
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

