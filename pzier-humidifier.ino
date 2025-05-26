int POT = A0; // Arduino pin assigned to Potentiometer

int BUZZER = 3; // Arduino pin assigned to Buzzer

int frequency;// variable for storing the frequency

void setup() {

  Serial.begin(9600);// initializing the serial communication

  pinMode(BUZZER, OUTPUT); /*Assigning the buzzer the  Output mode*/

}

void loop() {

  int POTValue = analogRead(POT); // read the input on analog pin

  frequency=map(POTValue,0,1023,0,255);/* scalarizing the value of the potentiometer into PWM values*/

  tone(BUZZER,frequency);/*using tone function to generate the tone of the frequency given by POT*/

  Serial.print("\n Value of the potentiometer: ");

  Serial.println(POTValue);// displaying the POT values

  Serial.print("");

  Serial.print("Frequency of the buzzer: ");

  Serial.print(frequency);// displaying the frequency

  Serial.print("");

  delay(500);// time after which the loop function will start again

}
