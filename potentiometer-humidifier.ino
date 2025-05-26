
//declaring different variables
int humidifier = 3;
int potentiometer;
int humidiferValue;

void setup() {
  // put your setup code here, to run once:

  //creates a serial port
  Serial.begin(9600);
  //configures the humdifier as an output
  pinMode (humidifier, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //configures the potentiometer to A0
  potentiometer = analogRead(A0);
  //maps the potentiometer's value to the varibale "humidifier value". The numbers works as a threshold for the intenisty of the steam, try changing the number 150 to 0.
  humidiferValue = map(potentiometer, 0, 1023, 150, 255);
  //the humidifiers output correlates to the current value of the potentiometer
  analogWrite(humidifier, humidiferValue);
  //prints the value from the potentiometer
  Serial.println(humidiferValue);
  //adds a delay for the information that is printed in the serial monitor
  delay(500);
}
