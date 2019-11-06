//Hier werden Libraries importiert und globale Variablen deklariert
#include <TimerOne.h>
#include <Wire.h>
#include <Zumo32U4.h>
Zumo32U4Motors motors;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;
Zumo32U4Encoders encoders;
Zumo32U4ButtonA buttonA;

//Autoren: Angela Meixner und Dragana Ristic
//Datum: 30.10.2019

//Hier werden Grundeinstellungen vorgenommen und die Sensoren initialisiert
void setup() {
  lineSensors.initFiveSensors();
  calibrateLineSensors();

   //Gesicht auf dem Display des Roboters
   lcd.print(" U    U ");
   lcd.gotoXY(0, 1);
   lcd.print("  ____   ");

   
}
//Kalibrieren des Zumo
void calibrateLineSensors()
{
 //Während dem Kalibrieren "Kalibriert" auf dem Display anzeigen
 lcd.clear();
 lcd.print(F("Kalibr."));
 for (uint16_t i = 0; i < 400; i++){
 lcd.gotoXY(0, 1);
 lcd.print("...");
 lineSensors.calibrate();
 }

 //Um den Roboter in Bewegung zu bringen, muss "A" gedrückt werden
 lcd.clear();
 lcd.print(F("Press A"));
  lcd.gotoXY(0, 1);
  lcd.print(F("to goooo"));
  buttonA.waitForButton();
  lcd.clear();
}

//Methode regelt, wie sich der Roboter währenddem Fahren verhält
//Während dem Fahren ist das grüne LED eingeschaltet
void loop(){ 

  uint16_t lineSensorValues[5] = { 0, 0, 0, 0, 0 };
  lineSensors.readCalibrated(lineSensorValues);
  
  //Wenn Sensor 1 auf Weiss ist und Sensor 3 auf Schwarz, dann geradeaus
  if(lineSensorValues[1] < 400 && lineSensorValues[3] > 400) {
     motors.setLeftSpeed(250);
     motors.setRightSpeed(250);
     ledGreen(1);
  }
  //Wenn Sensor 1 auf Schwarz ist, dann nach links fahren
  else if(lineSensorValues[1] > 400){
     motors.setLeftSpeed(-100);
     motors.setRightSpeed(200);
     ledGreen(1);
  }
  //Wenn Sensor 1 auf Weiss ist und Sensor 3 auf Weiss ist, dann nach links fahren
  else if(lineSensorValues[1] < 400 && lineSensorValues[3] < 400){
     motors.setLeftSpeed(200);
     motors.setRightSpeed(-100);
     ledGreen(1);
  }

  
}
