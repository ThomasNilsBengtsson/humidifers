
#include <Arduino_LSM9DS1.h>

//declaring pins
int humidifier = 13;
int humidifier2 = 4;
int accelerometer;

float val;
float Y;

int offtime = 1000;
int ontime = 1000;

float val2;
float Y2;

int isOn = 1;
int OutputState = 1;
unsigned long previousMillis;
unsigned long now = 0;

int isOn2 = 0;
unsigned long now2 = 0;




void setup() {
  //setting upp serial port
  Serial.begin(9600);
  //while (!Serial);
  //Serial.println("Started");

  //if inter
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  //Serial.print(IMU.accelerationSampleRate());
  pinMode(humidifier, OUTPUT);
  //digitalWrite(humidifier, HIGH);
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    //accelerometer = x + y + z;
    //Serial.println(accelerometer);
    //Serial.println(y);
    // delay(200);

    //turns the y's value from decimals to an integer
    Y = y * 1000;


    val = map(Y, -1000, 1000, 200, 1000);

    Serial.println(val);
    delay(50);



    unsigned long currentMillis = millis();

    if ((OutputState == HIGH) && (currentMillis - previousMillis >= ontime)) {
      OutputState = LOW;
      previousMillis = currentMillis;
      digitalWrite(humidifier, OutputState);
    }
    else if ((OutputState == LOW) && (currentMillis - previousMillis >= offtime)) {
      OutputState = HIGH;
      previousMillis = currentMillis;
      digitalWrite(humidifier, OutputState);


    }

      val2 = map(Y, -1000, 1000, 1000, 200);

      Serial.println(val2);

      if (millis() > now2 + val2 ) {
          delay(50);
          digitalWrite(humidifier, isOn2);

          isOn2 = 1 - isOn2;
          now2 = millis();}*/

  }
}
