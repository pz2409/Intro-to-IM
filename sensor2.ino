void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  pinMode(9, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int brightness = Serial.parseInt();

    // Remove the newline after the number.
    while (Serial.available() > 0) {
      Serial.read();
    }

    brightness = constrain(brightness, 0, 255);
    analogWrite(9, brightness);
  }
}