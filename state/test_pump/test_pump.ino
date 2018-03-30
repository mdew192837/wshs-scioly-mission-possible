int motorControl = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // ramp up the motor speed
  for(int x = 0; x <= 255; x++){
    analogWrite(motorControl, x);
    delay(50);
  }

  // ramp down the motor speed
  for(int x = 255; x >= 0; x--){
    analogWrite(motorControl, x);
    delay(50);
  }
}
