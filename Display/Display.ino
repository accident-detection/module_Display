/*

Pinovi LCD-a koji se spajaju na Arduino:
14 - 12
13 - 11
12 - 10
6 - 8
4 - 7

*/
 
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  // Inicijalizacija pinova od LCD-a

void setup() {
  lcd.begin(20, 4);  // Inicijalizacija, određuje se koliko redova i stupova ima LCD
  
  // Ispis podataka
  lcd.print("Temperatura: ");
  lcd.setCursor(0, 1);  // S setCursor metodom se namjesta ispis podataka na lcd. Prva znamenka određuje stupac, a druga redak
  lcd.print("Vlažnost: ");
}

void loop() {
  // Moguć drugi ispis podataka koji se mijenja s vremenom
}

