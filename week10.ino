#include "pitches.h"
#define REST 0

int green = A1;
int red = A2;
int yellow = A3;
int controller = A0;
int buzzer = 8;

int greenMelody[] = {
  REST, NOTE_D4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5, NOTE_C5,

};

int redMelody[] = {
 NOTE_A4,
  NOTE_G4, NOTE_AS4, NOTE_A4,
};

int yellowMelody[] = {
 NOTE_F4, NOTE_GS4, NOTE_D4,
  NOTE_D4
};


void setup() {
  pinMode(green, INPUT_PULLUP);
  pinMode(red, INPUT_PULLUP);
  pinMode(yellow, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(green) == LOW) {
    playMelody(greenMelody, green);
  } else if (digitalRead(red) == LOW) {
    playMelody(redMelody, red);
  } else if (digitalRead(yellow) == LOW) {
    playMelody(yellowMelody, yellow);
  } else {
    noTone(buzzer);
  }
}

// All three of your melody arrays contain 16 entries.
void playMelody(int melody[], int buttonPin) {
  for (int i = 0; i < 16; i++) {

    if (digitalRead(buttonPin) == HIGH) {
      noTone(buzzer);
      return;
    }

    int sensorValue = analogRead(controller);
    int noteDuration = map(sensorValue, 0, 1023, 150, 450);

    if (melody[i] == REST) {
      noTone(buzzer);
    } else {
      tone(buzzer, melody[i]);
    }

    // Wait in small steps so releasing the button stops sound.
    for (int time = 0; time < noteDuration; time += 10) {
      if (digitalRead(buttonPin) == HIGH) {
        noTone(buzzer);
        return;
      }

      delay(10);
    }

    noTone(buzzer);
    delay(20);
  }
}