/*
   Luuk Witters
   Opdracht 4: Temperatuur meter
*/


const int tempmeterPin = A5; //Tempmeter aangesloten op poort A5
int tempWaarde = 0;

void setup() {
  //Start de seriele communicatie
  Serial.begin(9600);

}

void loop() {
  tempWaarde = map(analogRead(tempmeterPin), 0, 1023, 0, 500); //tempmeter analoog waarde omzetten naar laagste punt is  en hoogste punt is 500.
  //Dit omdat de laagst meetbare temperatuur 0 graden celsius is en de hoogst meetbare 500 graden celsius is.

  Serial.print("De temperatuur is: "); //print deze tekst in de seriele monitor
  Serial.print(tempWaarde); //print de waarde die de tempmeter oppikt in de seriele monitor
  delay(3000); //wacht 3 seconde

}
