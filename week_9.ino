int led1 = 9;
int led2 = 10;
int led3 = 11;
int buttonPin = 2;
int buttonLED = 13;
int brightness = 0;

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonLED, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(buttonLED, LOW);   // Pressed: LED off
  } else {
    digitalWrite(buttonLED, HIGH);  // Released: LED on
  }

  int sensorValue = analogRead(A2);

  Serial.print("Button: ");
  Serial.print(buttonState);
  Serial.print("  Light: ");
  Serial.println(sensorValue);

  sensorValue = constrain(sensorValue, 600, 900);
  brightness = map(sensorValue, 600, 900, 40, 255);

  if (sensorValue < 700) {
    analogWrite(led1, brightness);
    analogWrite(led2, 0);
    analogWrite(led3, 0);
  } else if (sensorValue < 800) {
    analogWrite(led1, 0);
    analogWrite(led2, brightness);
    analogWrite(led3, 0);
  } else {
    analogWrite(led1, 0);
    analogWrite(led2, 0);
    analogWrite(led3, brightness);
  }

  delay(30);
}
