
#include <Arduino_LSM9DS1.h>

//declaring pins
int humidifier = 3;

int accelerometer;

float val;
float Y;

//float val2;
//float Y2;

int isOn = 1;
unsigned long now = 0;

//int isOn2 = 0;
unsigned long now2 = 0;

void setup() {

  Serial.begin(9600);
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  pinMode(humidifier, OUTPUT);
  digitalWrite(humidifier, HIGH);
}

void loop() {
  float x, y, z;


  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    //turns the y's value from decimals to an integer
    Y = y * 1000;

    val = map(Y, -1000, 1000, 200, 1000);
    delay(50);
    //Serial.println(val);

    if (millis() > now2 + val * 2) {
      digitalWrite(humidifier, isOn);
      Serial.println("if 2");
      isOn = 1 - isOn;
      now2 = millis();

    }
    if (millis() > now + val) {
      digitalWrite(humidifier, isOn);

      Serial.println ("1");
      isOn = 1 - isOn;
      now = millis();
    }
  }
}
