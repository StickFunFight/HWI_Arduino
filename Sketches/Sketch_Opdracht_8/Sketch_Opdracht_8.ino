/*
   Luuk Witters
   Zet LEDS aan mbc IR sensor en afstandbediening en laat ze knipperen. Bepaal dan de knippersnelheid met de afstandsbediening

   !!!Je kan 1x twee LEDS selecteren en voor die constant de knippersnelheid aanpassen. Om nieuwe LEDS te selecteren moet je resetten!!!
*/

//Voeg de IRRemote library toe
#include<IRremote.h>

//Variabele defineren
decode_results results;
int iTeller = 0;
int iGeheugen1 = 0;
int iGeheugen2 = 0;
unsigned long laatsteTijd = 0;

//Ledpins en IR Sensor koppelen aan hun poort
int ledPin13 = 13;
int ledPin12 = 12;
int ledPin10 = 10;
int ledPin9 = 9;
int IR = 5;
IRrecv irrecv(IR);

//Knoppen 1tm4 van afstandsbediening defineren
long int remote1 = 16582903;
long int remote2 = 16615543;
long int remote3 = 16599223;
long int remote4 = 16591063;

void setup() {
  //Seriele communicatie en de IR Sensor starten
  Serial.begin(9600);
  irrecv.enableIRIn();

  //Aangeven dat ledjes ene output moeten geven
  pinMode (ledPin13, OUTPUT);
  pinMode (ledPin12, OUTPUT);
  pinMode (ledPin10, OUTPUT);
  pinMode (ledPin9, OUTPUT);
}

void loop() {

  //Status van de LEDS ophalen
  int statPin13 = digitalRead(ledPin13);
  int statPin12 = digitalRead(ledPin12);
  int statPin10 = digitalRead(ledPin10);
  int statPin9 = digitalRead(ledPin9);

  //Wanneer de IR Sensor een signaal binnenkrijgt print die dit signaal uit en gaat die verder met signalen zoeken
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume();

    //Als iTeller < 2 voor deze code uit:
    if (iTeller < 2) {

      //Als knop 1,2,3 of 4 wordt ingedrukt voer dan de functie onthoudActie uit een geef de bijbehorende waarde mee (ledPin13, ledPin12, ledPin10, ledPin9)

      if (results.value == remote1 && statPin13 == LOW) {
        onthoudActie(ledPin13);
      }

      else if (results.value == remote2 && statPin12 == LOW) {
        onthoudActie(ledPin12);
      }

      else if (results.value == remote3 && statPin10 == LOW) {
        onthoudActie(ledPin10);
      }

      else if (results.value == remote4 && statPin9 == LOW) {
        onthoudActie(ledPin9);
      }
    }

  }

  //Als iTeller = 2 voor deze code uit:
  if (iTeller == 2) {

    //Als knop 1,2,3 of 4 wordt ingedrukt voor dan de functie knipper uit en geef de bijbehorende waarde mee (100, 200, 300, 400)

    if (results.value == remote1) {
      knipper(100);
    }

    if (results.value == remote2) {
      knipper(200);
    }

    if (results.value == remote3) {
      knipper(300);
    }

    if (results.value == remote4) {
      knipper(400);
    }
  }
}


// Functie die onthoudt welke 2 knoppen als eerst zijn ingedrukt en daarmee de bijbehorende LEDS onthoudt
// Vul de meegestuurde variabele in (ledPin13, ledPin12, ledPin10, ledPin9)
void onthoudActie(int led) {
  //Zet de meegestuurde led op HIGH
  digitalWrite(led, HIGH);

  //Als de waarde van iGeheugen1 nog leeg is voer dan deze code uit
  if (iGeheugen1 == 0) {
    //Verander de waarde van iGeheugen1 naar de meegestuurde LED en doe +1 bij iTeller
    iGeheugen1 = led;
    iTeller++;
  }

  //Als de waarde van iGeheugen1 gevuld is voer dan deze code uit
  else {
    //Verander de waarde van iGeheugen2 naar de meegestuurde LED en doe +1 bij iTeller
    iGeheugen2 = led;
    iTeller++;
  }
}

//Functie die de knippertijd aanpast mbv millis
void knipper(int knipperTijd) {

  //Variabele aanmaken voor de huidigeTijd en vullen met de millis functie
  unsigned long huidigeTijd = millis();
  //Status van meegestuurde iGeheugen 1 & 2 invullen
  int active1 = digitalRead(iGeheugen1);
  int active2 = digitalRead(iGeheugen2);

  //Als de huidigeTijd - laatsteTijd >= knippertijd voer deze code uit
  //Je wacht tot de millis functie de tijd heeft bereikt die gelijk is aan de meegegeven knipperTijd waarde
  if (huidigeTijd - laatsteTijd >= knipperTijd) {
    laatsteTijd = huidigeTijd;

    //Voer deze code uit als active1 en active2 allebei LOW zijn
    if (active1 == LOW && active2 == LOW) {
      //Zet beide LEDS aan
      digitalWrite(iGeheugen1, HIGH);
      digitalWrite(iGeheugen2, HIGH);
    }
    //Anders voer je deze code uit
    else {
      //Zet beide LEDS uit
      digitalWrite(iGeheugen1, LOW);
      digitalWrite(iGeheugen2, LOW);
    }
  }
}
