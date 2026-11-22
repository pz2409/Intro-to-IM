void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A1);
  Serial.println(potValue);

  delay(30);
}