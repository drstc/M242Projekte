/*
 * Autoren: Angela Meixner und Dragana Ristic
 * Datum: 06.11.2019
 * Version: 1.1
 */

//Led Schnittstelle wird definiert für das weisse LED.
int LedWhite=13;
//Led Schnittstelle wird definiert für das rote LED.
int LedRed=8;
//Schalter Schnittstelle wird definiert.
int Shock=3;
//Buzzer Schnittstelle wird definiert.
int buzzer=12;

void setup()
{
  //Das weisse LED wird als Output-Schnittstelle definiert.
  pinMode(LedWhite,OUTPUT);
  //Das LED wird als Output-Schnittstelle definiert.
  pinMode(LedRed,OUTPUT);
  //Der Buzzer wird als Output-Schnittstelle definiert.
  pinMode (buzzer, OUTPUT);
  //Der Schalter wird als Input-Schnittstelle definiert.
  pinMode(Shock,INPUT);
}

void loop(){
  //Wenn der Schalter an ist,
  if(digitalRead(Shock)==HIGH){
    //soll das weisse LED aus sein
    digitalWrite(LedWhite,LOW);
    //soll das rote LED aus sein
    digitalWrite(LedRed,LOW);
    //soll der Buzzer aus sein
    digitalWrite(buzzer,LOW);
}
//sonst
else{
  //bis die Befehle 6 Mal ausgeführt werden.
  for (int i = 0; i <= 5; i++){
    //Der Buzzer soll für eine halbe Sekunde lang klingen
    tone (buzzer, 500, 500);
    //Das weisse LED soll für eine halbe Sekunde leuchten
    digitalWrite(LedWhite,HIGH);
    delay(500);
    //Das weisse LED soll sich ausschalten.
    digitalWrite(LedWhite,LOW);
    //Der Buzzer soll für eine halbe Sekunde lang klingen
     tone (buzzer, 300, 500);
     // Das rote LED soll für eine halbe Sekunde leuchten
    digitalWrite(LedRed,HIGH);
    delay(500);
    //Das rote LED soll sich ausschalten.
    digitalWrite(LedRed,LOW);
    
  }
}
}
