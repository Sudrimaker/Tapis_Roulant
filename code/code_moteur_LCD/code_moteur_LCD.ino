#include <Arduino.h>
#include <Servo.h>

#include <LiquidCrystal.h>
#include "A4988.h"

//LCD
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//StepMotor
int RPM = 120;  
int DIR = 5;
int STEP = 6;
int MOTOR_STEPS_P = 400;  //1.8 ° per steps
A4988 stepper(MOTOR_STEPS_P, DIR, STEP);

//servo
int servo_pin = 4;
Servo eject;
int detect;

//capteur IR
int IRPin = 3;
const int sensorPin = A2;  // Pin connected to sensor
int sensorVal;
int value;

//Rasp
int raspberry_pin=A2;
int rasp_val;

void setup() {
  pinMode(sensorPin, INPUT);
  //pinMode(raspberry_pin,INPUT);
  stepper.begin(RPM);
  stepper.enable();
  eject.attach(servo_pin);
  pinMode(IRPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);

}
void loop() {
  sensorVal = analogRead(sensorPin);
  rasp_val=analogRead(raspberry_pin);
  Serial.println(rasp_val);


  if (sensorVal > 800) {
    stepper.move(100);
    if (rasp_val == 1){
      Serial.println("Signal du rasp, objet détecté");
      detection();
      }
  }
  
  if (sensorVal< 200) {
    stepper.move(-100);
  }
  //un tour
  delay(1);
}


void detection() {
  // fait avancer le tapis

  //attend que l'objet arrive
  while (digitalRead(IRPin) == 1){
     stepper.move(100);
     delay(1);
  }
  if (digitalRead(IRPin) == 0) {
    Serial.println("Détection !");
    // Déplacer le servomoteur à 180 degrés
    eject.write(180);
    stepper.move(800);
    // Ramener le servomoteur à 0 degré
    eject.write(90);
  }
}
