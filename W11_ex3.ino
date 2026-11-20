//exercise 3

int ledPin = 2;                //led that flashes on each bounce
unsigned long ledOffTime = 0;  //the time when the led should turn back off

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, OUTPUT);

  //handshake: send a starting value until p5 answers
  while (Serial.available() <= 0) {
    digitalWrite(LED_BUILTIN, HIGH);  //blink while waiting
    Serial.println("0");              //starting message
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }
}

void loop() {
  //whenever p5 sends something, read it and reply
  if (Serial.available() > 0) {
    int bounce = Serial.parseInt();   //1 if the ball just bounced, else 0

    if (bounce == 1) {
      digitalWrite(ledPin, HIGH);     //turn the led on
      ledOffTime = millis() + 120;    //keep it on for 120 ms
    }

    int sensor = analogRead(A0);      //read the photocell
    Serial.println(sensor);           //send it back to p5 
  }

  //turn the led off once its time is up
  if (millis() > ledOffTime) {
    digitalWrite(ledPin, LOW);
  }
}