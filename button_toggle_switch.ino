
//declaring different variables
const int buttonPin = 8;
const int humidifierPin = 7;

//sets up the boolean
int buttonState = false;

void setup() {
  // put your setup code here, to run once:

  //configure the button to behave as an input
  pinMode(buttonPin, INPUT_PULLUP);
  //configure the humidifier to behave as an output
  pinMode(humidifierPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //when button is activated...
  if (digitalRead(buttonPin) == true) {

    //changes buttonState to true
    buttonState = !buttonState;
    //activates the humidifier
    digitalWrite(humidifierPin, buttonState);
  } while (digitalRead(buttonPin) == true);
  //adds an delay between toggle off/on
  delay (50);
}
