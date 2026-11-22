int led = 9;
int potPin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  // Send the knob reading to p5.js.
  int potValue = analogRead(potPin);
  Serial.println(potValue);

  // Receive the bounce signal from p5.js.
  if (Serial.available() > 0) {
    int message = Serial.read();

    if (message == '1') {
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
    }
  }

  delay(30);
}