#include "pitches.h"  

const int photoPin = A2;
const int buttonPin = 2;
const int buzzerPin = 8;

//the order goes low to high
int notes[] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5};
const int numNotes = 8;  //number of notes

void setup() {
  Serial.begin(9600);                //can see the photocell values in the serial monitor
  pinMode(buttonPin, INPUT_PULLUP);  //internal pullup so pressed = low
}

void loop() {
  int sensorValue = analogRead(photoPin);  //more light = higher number
  Serial.println(sensorValue);

  //photocell only goes from about 300 to 750
  int light = constrain(sensorValue, 300, 750);

  //split the light range into 8 steps each step is one note in the list
  //751 so the brightest reading gives 7
  int noteIndex = map(light, 300, 751, 0, numNotes);

  //only make sound while the button is held down
  if (digitalRead(buttonPin) == LOW) {
    tone(buzzerPin, notes[noteIndex]);  //play the note that matches the light
  } else {
    noTone(buzzerPin);  //button not pressed so stay quiet
  }

  delay(10);  //small delay so the serial monitor doesnt get flooded
}