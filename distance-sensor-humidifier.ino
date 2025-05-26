#define Trigpin 7
#define Echopin 8
#define humidifier 3

float distance;
unsigned long duration;

void setup() {
    
  pinMode (Echopin, INPUT);
  pinMode (Trigpin, OUTPUT);
  pinMode (humidifier, OUTPUT);
  Serial.begin(9600);

  digitalWrite (humidifier, LOW);
  
}

void loop() {
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  duration = pulseIn(Echopin, HIGH);
  distance = duration * 0.034 / 2;
  delay (200);
  Serial.println (" ");
  Serial.print ("Distance = ");
  Serial.print (distance);
  Serial.print (" CM");
  Serial.println (" ");

  if (distance<=30)
  {
    Serial.println ("Someone Is Infront Of the Sensor");
    digitalWrite (humidifier, HIGH);
   
  }
  else 
  {
    Serial.println ("Nobody Is Infront Of the Sensor");
    digitalWrite(humidifier, LOW);
  }
}
