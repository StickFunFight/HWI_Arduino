/*
  Luuk Witters
  Opdracht 3: 7 Ledlampjes met potentiemeter
*/
int input;

void setup()
{

  //Pins toekennen aan hun poort
  Serial.begin(9600);
  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (6, OUTPUT);
}

void loop()
{
  //Analoog waarden van 0 tot/m 700 laten lopen
  input = map(analogRead(0), 0, 1023, 0, 700);


  //Als de input hoger is dan 100, dan gaat de LED aan. Anders gaat die uit.
  if (input > 100)
  {
    digitalWrite(13, HIGH);
  }
  else
    digitalWrite(13, LOW);

  //Als de input hoger is dan 200, dan gaat de LED aan. Anders gaat die uit.
  if (input > 200)
  {
    digitalWrite(12, HIGH);
  }
  else
    digitalWrite(12, LOW);

  //Als de input hoger is dan 300, dan gaat de LED aan. Anders gaat die uit.
  if (input > 300)
  {
    digitalWrite(11, HIGH);
  }
  else
    digitalWrite(11, LOW);

  //Als de input hoger is dan 400, dan gaat de LED aan. Anders gaat die uit.
  if (input > 400)
  {
    digitalWrite(10, HIGH);
  }
  else
    digitalWrite(10, LOW);

  //Als de input hoger is dan 500, dan gaat de LED aan. Anders gaat die uit.
  if (input > 500)
  {
    digitalWrite(9, HIGH);
  }
  else
    digitalWrite(9, LOW);

  //Als de input hoger is dan 600, dan gaat de LED aan. Anders gaat die uit.
  if (input > 600)
  {
    digitalWrite(7, HIGH);
  }
  else
    digitalWrite(7, LOW);

  //Als de input hoger is dan 700, dan gaat de LED aan. Anders gaat die uit.
  if (input >= 700)
  {
    digitalWrite(6, HIGH);
  }
  else
    digitalWrite(6, LOW);
}
