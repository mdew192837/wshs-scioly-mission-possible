int SEND_PIN = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(SEND_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(SEND_PIN, HIGH);
  delay(2000);
  digitalWrite(SEND_PIN, LOW);
  delay(2000);
}
