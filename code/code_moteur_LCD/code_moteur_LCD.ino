#include <Arduino.h>

//LCD
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//StepMotor
#include "A4988.h"
int RPM = 120;  
int DIR = 5;
int STEP = 6;
int servo_pin = 4;
int IRPin = 3;
int MOTOR_STEPS_P = 400;  //1.8 ° per steps
A4988 stepper(MOTOR_STEPS_P, DIR, STEP);
//IR
#include <Servo.h>
const int sensorPin = A2;  // Pin connected to sensor
int sensorVal;
//servo
Servo eject;

int value;
int detect;


void setup() {
  pinMode(sensorPin, INPUT);
  stepper.begin(RPM);
  stepper.enable();
  eject.attach(servo_pin);
  pinMode(IRPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);

}
void loop() {
  sensorVal = analogRead(sensorPin);
  // Si le capteur infrarouge est activé
  Serial.println(digitalRead(IRPin));

  if (sensorVal < 200) {
    stepper.move(100);
    detection();
  }
  if (sensorVal > 800) {
    stepper.move(-100);
    detection();
  }
  //un tour
  delay(1);
}


void detection() {

  if (digitalRead(IRPin) == LOW) {
    // Déplacer le servomoteur à 180 degrés
    lcd.print("hello, world!");
    eject.write(180);
     // Attendre 1 seconde
    // Ramener le servomoteur à 0 degré
    stepper.move(800);

    eject.write(90);

  }
}
