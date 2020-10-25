/*
   Luuk Witters
   RGB alle mogelijke kleuren laten zien
*/

//Leds defineren en aan poort koppelen
static int Ledred = 11;
static int Ledblue = 10;
static int Ledgreen = 9;

void setup() {
  pinMode(Ledred, OUTPUT);
  pinMode(Ledblue, OUTPUT);
  pinMode(Ledgreen, OUTPUT);

  //Starten met het rode lampje aan
  digitalWrite(Ledred, HIGH);  //Red LED ON
  digitalWrite(Ledblue, LOW);  //Blue LED OFF
  digitalWrite(Ledgreen, LOW); //Green LED OFF
}

//variabelen voor de kleuren benoemen
int r;
int g;
int b;

void loop() {
  //Begin met waarde r op 250
  r = 255;
  g = 0;
  b = 0;

  //Variabele c blijft groter worden totdat alle 255 kleuren gedaan zijn
  for (int c = 0; c < 255; c++) {
    //Elke keer als variabele c omhoog gaat gaat de waarde van r omlaag en g omhoog
    r = r - 1;
    g = g + 1;

    //geef Ledgreen en Ledred de waarde van g en r
    analogWrite(Ledred, r);
    analogWrite(Ledgreen, g);
    //hele korte delay zodat de kleuren verloop iets soepeler is
    delay(5);
  }
  /*
     In de code hieronder wordt hetzelfde als hierboven gedaan, maar dan voor de groene en blauwe kleuren
  */
  r = 0;
  g = 255;
  b = 0;

  for (int c = 0; c < 255; c++) {
    g = g - 1;
    b = b + 1;

    analogWrite(Ledgreen, g);
    analogWrite(Ledblue, b);

    delay(5);
  }

  r = 0;
  g = 0;
  b = 255;


  for (int c = 0; c < 255; c++) {
    b = b - 1;
    r = r + 1;

    analogWrite(Ledblue, b);
    analogWrite(Ledred, r);

    delay(5);
  }
}
