/*
  Luuk Witters
  Ruitenwisser Servo
*/

#include<Servo.h>

//Defineer de poorten van de knoppen
const int Button1 = 9;
const int Button2 = 8;
//Begin variabele van de hoek van de servo
int angle = 0;

Servo servo;
void setup() {
  //De knoppen moeten een input geven
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  //Defineer de poort van de servo
  servo.attach(5);
}
void loop() {
  //Variabele aanmaken die de status van de knoppen uitleest
  int btn1State = digitalRead(Button1);
  int btn2State = digitalRead(Button2);

  if (btn1State == HIGH && btn2State == LOW) { //als switchpin1 ingedrukt wordt en switchpin2 niet draait het 120 in 1sec
    draaiServo(8, 10); //Geef een delay van 8 mee. Omdat 120 * 0,008 = 0.96 seconde. Dus bijna een seconde. Wacht daarna heel even voor een soepelere verloop
  }
  else if (btn1State == LOW && btn2State == HIGH) { //als switchpin2 ingedrukt wordt en switchpin1 niet draait het 120 in 0.5 sec
    draaiServo(4, 10); //Geef een delay van 8 mee. Omdat 120 * 0,004 = 0.48 seconde. Dus bijna een halve seconde. Wacht daarna heel even voor een soepelere verloop
  }
  else if (btn1State == HIGH && btn2State == HIGH) { // Worden beide drukknoppen bediend, dan zal de servomotor in 1 s van 0 naar 120⁰ draaien, 2 s in deze stand blijven staan en vervolgens in 1 s terugdraaien naar 0⁰
    draaiServo(8, 2000); //Geef een delay van 8 mee. Omdat 120 * 0,008 = 0.96. Dus bijna een seconde. Wacht daarna 2 seconde voordat die terug gaat.
  }
  else {
    servo.write(0);
  }
}

void draaiServo(int iDelay, int iAngleResetDelay) {
  for (angle = 0; angle <= 120; angle++) {
    servo.write(angle);
    delay(iDelay);
  }
  delay(iAngleResetDelay);

  for (angle = 120; angle >= 0; angle--) {
    servo.write(angle);
    delay(iDelay);

  }
}
