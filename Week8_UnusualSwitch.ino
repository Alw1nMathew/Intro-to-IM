void setup() {
  pinMode(13, OUTPUT);       
  pinMode(A2, INPUT_PULLUP);  
}

void loop() {
  int elbowState = digitalRead(A2);  //reads the switch

  if (elbowState == LOW) {
    digitalWrite(13, HIGH);   //elbow bent, pads touch, LED on
  } else {
    digitalWrite(13, LOW);    //elbow straight, pads apart, LED off
  }
}