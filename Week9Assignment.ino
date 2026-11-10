const int photoPin = A2;
const int buttonPin = 2;
const int analogLed = 9;
const int digitalLed = 7;

const int darkThreshold = 350;  //below this I count the room as dark

void setup() {
  Serial.begin(9600);                //so I can read the sensor values in the serial monitor
  pinMode(buttonPin, INPUT_PULLUP);  //internal pullup so pressed = low
  pinMode(analogLed, OUTPUT);
  pinMode(digitalLed, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(photoPin);  //0 to 1023
  Serial.println(sensorValue);

  //my photocell only goes from about 300 to 750
  //so I constrain to that range and map it to 0 to 255 for the red led
  //bright room = bright red darker room = dimmer red
  int light = constrain(sensorValue, 300, 750);
  int brightness = map(light, 300, 750, 0, 255);
  analogWrite(analogLed, brightness);

  //green led on if the room is dark or the button is pressed
  bool isDark = sensorValue < darkThreshold;
  bool buttonPressed = (digitalRead(buttonPin) == LOW);

  if (isDark || buttonPressed) {
    digitalWrite(digitalLed, HIGH);
  } else {
    digitalWrite(digitalLed, LOW);
  }

  delay(30);  //delay
}