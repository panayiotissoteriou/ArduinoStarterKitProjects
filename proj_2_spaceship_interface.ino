int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
  // pinMode refers to the digital pins on the arduino
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  // the argument in digitalRead refers to the pin number on the Arduino
  // if there's voltage on the pin, switchState gets value HIGH
  // if there's no voltage, switchState gets value LOW


if (switchState == LOW) {
  // button is not pressed

  //digitalWrite allows you to send 5V or 0V to an output pin
  digitalWrite(3, HIGH); // green LED
  digitalWrite(4, LOW); // red LED
  digitalWrite(5, LOW); // red LED

}

else { // the button is pressed
  digitalWrite(3, LOW); // green LED
  digitalWrite(4, LOW); // red LED
  digitalWrite(5, HIGH); // red LED

  delay(250); // wait .25 seconds
  // toggle the LEDs
  digitalWrite(3, LOW); // green LED - maybe redundant
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(250); // wait a 0.25s
  

  // all these are extra

  digitalWrite(3, HIGH); // green LED
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(250); // wait a 0.25s


  digitalWrite(3, HIGH); // green LED
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(50); // wait a 0.25s

  digitalWrite(3, HIGH); // green LED
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(250); // wait a 0.25s

  digitalWrite(3, LOW); // green LED
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(250); // wait a 0.25s

  
}
} // go back to the beginning of the loop
