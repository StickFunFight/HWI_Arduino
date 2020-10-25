/*
   Luuk Witters
   Opdracht 2 een ledlampje aan en uit kunnen zetten met dezelfde knop
*/

const int ledPin11 = 11; //ledPin11 verbonden aan poort 11
const int btnPin2 = 2; //btnPin2 verbonden aan poort 2s
int btnStatus = 0; //teller voor de status van de btn kliks

void setup()
{
  pinMode(ledPin11, OUTPUT);
  pinMode(btnPin2, INPUT); //De knop moet een input geven
}

void loop()
{
  if (digitalRead(btnPin2) == 1) {        //De button wordt uitgelezen, als die ingedrukt wordt dan lees je van de button 1 uit. Als de button niet ingedrukt is dan lees je 0 uit/
    digitalWrite(ledPin11, HIGH);         //Zet ledPin11 aan
    btnStatus += 1;                       //Geef de teller +1
    delay(150);                           //Delay van 100 zodat de knop het lampje niet meteen weer uitzet als je m ingedrukt houdt
    if (btnStatus % 2 == 0) {             //Als je de teller kan delen door 2 zonder restgetallen te krijgen voer je de functie eronder uit
      digitalWrite(ledPin11, LOW);        //Zet ledPin11 uit
      btnStatus = 0;                      //Zet de teller weer op 0
    }
    delay(150);
  }

}
