/*
   Simuleer een verkeerslicht

   Luuk Witters
*/

//Variabele definieren en LEDs aan poorten koppelen
char Incoming_value = 0;
int led11 = 11;
int led8 = 8;
int led5 = 5;


void setup() {
  Serial.begin(9600);
  //Led toewijzen
  pinMode(led11, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led5, OUTPUT);
}
void loop()
{ //Bluetooth signaal oppakken
  if (Serial.available() > 0)
  {
    //Signaalwaarde vasthouden en uitprinten
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");        //New line

  }
  //Als de waarde van het signaal 1 is voer onderstaande code uit
  if (Incoming_value == '1')  {

    //Groen en Rood uit, geel aan
    digitalWrite(led5, LOW);
    digitalWrite(led11, LOW);
    digitalWrite(led8, HIGH);
    //wacht 6 seconde
    delay(6000);

    //Geel uit rood aan
    digitalWrite(led8, LOW);
    digitalWrite(led11, HIGH);
    //wacht 12 seconde
    delay(12000);

    //rood uit en groen aan
    digitalWrite(led11, LOW);
    digitalWrite(led5, HIGH);
    / wacht 12 seconde
    delay(12000);

  }

  //Als de waarde van het BT signaal niet 1 is voer onderstaande code uit
  else {

    //Zet alles uit
    digitalWrite(led11, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led8, LOW);
    //Zet geel aan
    digitalWrite(led8, HIGH);
    //Wacht 1 seconde
    delay(1000);
    //Zet geel uit
    digitalWrite(led8, LOW);
    //Wacht 1 seconde
    delay(1000);

  }

}
