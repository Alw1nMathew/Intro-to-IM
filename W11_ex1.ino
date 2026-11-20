//exercise 1

void setup() {
  Serial.begin(9600);  //start serial so we can send data to p5
}

void loop() {
  int sensorValue = analogRead(A0);  //photocell, 0 to 1023
  Serial.println(sensorValue);       //send it, println adds a \n at the end
  delay(10);                         //small delay so we dont flood p5
}
