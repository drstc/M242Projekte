/* Autoren: Angela Meixner und Dragana Ristic
 * Datum: 30.10.2019
 * Version: 1.1
 */
//Led Schnittstelle wird definiert.
int Led = 12 ;
//Schnittstelle für das Mikrophon wird definiert.
int micpin = 13; 
//Einfache Int Variable wird deklariert.
int val = 0;

void setup (){
 //Das LED wird als Output-Schnittstelle definiert.
 pinMode (Led, OUTPUT) ;
 //Das Microphon wird als Input-Schnittstelle definiert.
 pinMode (micpin, INPUT) ;
 //Der Wert des Mikrophons wird auf leise gestellt.
 
}

void loop (){
 //Der Input wird in dieser Zahlvariabel gespeichert.
 val = digitalRead(micpin);
 //Wenn das Mikrophon etwas Lautes wahrnimmt,
 if (val == HIGH){
  //soll das LED für eine halbe Sekunde leuchten,
  digitalWrite (Led, HIGH);
  delay(500);
 }
 //sonst
 else{
  //soll das LED nicht leuchten.
  digitalWrite (Led, LOW);
 }
}
