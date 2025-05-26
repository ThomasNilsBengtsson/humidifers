#include <Arduino_LSM9DS1.h>

//declaring pins
int humidifierPin = 3;
int LEDPin = LEDB;       // use blue LED to show readings
int LEDPinError = LEDR;  // use red LED for errors

// declaration variables
int accelerometer;
float x, y, z;
float pulseActive;
float Y;
unsigned long timerActivate = 0;
unsigned long timerDeactivate = 0;
boolean humidifierActive = true;  // by default this humidifier is on upon boot

void setup() {
  // declare used pins as output
  pinMode(humidifierPin, OUTPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(LEDPinError, OUTPUT);

  // turn common anode RGB LED off
  LEDsOff();

  // initialise serial port
  Serial.begin(9600);

  // wait until serial is active
  // NOTE: remove upon depolyment
  while (!Serial) {}

  // initialise accelerometer
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    LEDOn(LEDPinError);
    while (1)
      ;
  }

  // activate the humidifier upon boot
  digitalWrite(humidifierPin, HIGH);
  timerActivate = millis();
  humidifierActive = true;
}

void loop() {

  // execute timed commands
  if (!humidifierActive && millis() > timerDeactivate + pulseActive) {
    digitalWrite(humidifierPin, HIGH);
    LEDOn(LEDPin);
    Serial.println(F("humidifier changing to ON"));

    timerActivate = millis();
    humidifierActive = true;
  }

  if (humidifierActive && millis() > timerActivate + pulseActive * 2) {
    digitalWrite(humidifierPin, LOW);
    LEDOff(LEDPin);
    Serial.println(F("humidifier changing to OFF"));

    timerDeactivate = millis();
    humidifierActive = false;
  }

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    //turns the y's value from decimals to an integer
    Y = y * 1000;

    pulseActive = map(Y, -1000, 1000, 200, 1000);
  }
}

void LEDsOff() {
  digitalWrite(LEDPin, HIGH);
  digitalWrite(LEDPinError, HIGH);
  digitalWrite(LEDG, HIGH);
}

void LEDsOn() {
  digitalWrite(LEDPin, LOW);
  digitalWrite(LEDPinError, LOW);
  digitalWrite(LEDG, LOW);
}

void LEDOn(int led) {
  digitalWrite(led, LOW);
}

void LEDOff(int led) {
  digitalWrite(led, HIGH);
}
