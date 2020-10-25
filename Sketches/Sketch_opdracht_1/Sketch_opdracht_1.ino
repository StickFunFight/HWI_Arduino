/*
   Luuk Witters opdracht 1
   Lampjes die in een reeks achter elkaar bewegen en weer terugkomen
   Dit proces blijft doorgaan
*/


//Constante toevoegen
const int ledPin1 = 1;
const int ledPin2 = 2;
const int ledPin3 = 3;
const int ledPin5 = 5;
const int ledPin7 = 7;
const int ledPin9 = 9;
const int ledPin11 = 11;
const int ledPin13 = 13;

void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin13, OUTPUT);
}

void loop()
{
  digitalWrite(ledPin1, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin1, LOW); //Zet ledlampje uit

  digitalWrite(ledPin2, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin2, LOW); //Zet ledlampje uit

  digitalWrite(ledPin3, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin3 , LOW); //Zet ledlampje uit

  digitalWrite(ledPin5, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin5, LOW); //Zet ledlampje uit

  digitalWrite(ledPin7, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin7, LOW); //Zet ledlampje uit

  digitalWrite(ledPin9, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin9, LOW); //Zet ledlampje uit

  digitalWrite(ledPin11, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin11, LOW); //Zet ledlampje uit

  digitalWrite(ledPin13, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin13, LOW); //Zet ledlampje uit
  delay(200); // Wacht 0,2 seconde

  digitalWrite(ledPin13, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin13, LOW); //Zet ledlampje uit

  digitalWrite(ledPin11, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin11, LOW); //Zet ledlampje uit

  digitalWrite(ledPin9, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin9, LOW); //Zet ledlampje uit

  digitalWrite(ledPin7, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin7, LOW); //Zet ledlampje uit

  digitalWrite(ledPin5, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin5, LOW); //Zet ledlampje uit

  digitalWrite(ledPin3, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin3 , LOW); //Zet ledlampje uit

  digitalWrite(ledPin2, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin2, LOW); //Zet ledlampje uit

  digitalWrite(ledPin1, HIGH); //Zet ledlampje aan
  delay(200); // Wacht 0,2 seconde
  digitalWrite(ledPin1, LOW); //Zet ledlampje uit
  delay(200); //Wacht 0,2 seconde
}
