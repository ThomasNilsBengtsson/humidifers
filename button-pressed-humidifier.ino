
//declaring different variables
const int buttonPin = 8; // Button pin
const int humidifierPin = 7; // Led pin

void setup() {
  // put your setup code here, to run once:

  //configure the button to behave as an input
  pinMode(buttonPin, INPUT_PULLUP);

  //configure the humidifer to behave as an output
  pinMode(humidifierPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // If button is pressed.
  if (digitalRead(buttonPin) == LOW) {
    // activate humidifier
    digitalWrite(humidifierPin, HIGH);
  } else {
    // If button is up, turn the humidifer off
    digitalWrite(humidifierPin, LOW);
  }
  //adds delay between off/on
  delay(100);
}
