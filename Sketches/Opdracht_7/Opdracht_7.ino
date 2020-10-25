/*
   Luuk Witters
   Afstandsmeter met behulp van Ultrasone afstandssensor
*/

#include <Servo.h>

//Variabele aanmaken en pinnen aan poort koppelen
const int TrigPin = 10;
const int EchoPin = 9;
Servo MooieServo;
float Tijdsuur;
float Afstand;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  MooieServo.attach(11);

}

void loop() {

  long Tijdsduur, Afstand;


  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);

  //Trigger stuurt signaal
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  //Trigger stuurt geen signaal meer
  digitalWrite(TrigPin, LOW);

  //Tijdsduur is gelijk aan het signaal dat de echopin binnenkrijgt
  Tijdsuur = pulseIn(EchoPin, HIGH);

  //Als je het signaal dat de echo binnenkreeg door 58 deelt krijg je de afstand in cm
  Afstand = Tijdsuur / 58;
  Serial.println("Afstand in cm ");
  Serial.println(Afstand);

  //Map de waardes van 4cm naar 0 en 10cm naar 180 op basis van de afstand variabele
  int positie = map(Afstand, 4, 10, 0, 180);

  //Op basis van de positie variabele zet je de positie van de servo
  MooieServo.write(positie);
  delay(30);



}
