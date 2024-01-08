
#include <LiquidCrystal.h>
#define stepPin 3
#define dirPin 4
int pin_pot = A1;
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);  // ouvre le port série
  pinMode(pin_pot, INPUT);
  lcd.begin(16, 2);
  lcd.print("Vitesse moteur");
  
}
void loop() {
  int pot = analogRead(pin_pot);
  int tempo = (pot / 400) +1;
  digitalWrite(dirPin, LOW);  // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for (int x = 0; x < 800; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(700);  // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pot+45);// le delais ne peux pas être<45 sinon moteur bug
  }
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(4-tempo);
}