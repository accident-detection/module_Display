#include <LiquidCrystal.h>
#include <dht.h>
#define DHT11_PIN 6

dht DHT;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(20, 4);
  
  lcd.print("Temperatura: ");
  lcd.setCursor(0, 1);
  lcd.print("Vlaznost: ");  
}

void loop() {
  int check = DHT.read11(DHT11_PIN);
  
  switch (check)
  {
    case DHTLIB_OK:
        lcd.setCursor(0, 3);
	lcd.print("OK"); 
	break;
    case DHTLIB_ERROR_CHECKSUM:
        lcd.setCursor(0, 3);
	lcd.print("Checksum error"); 
	break;
    case DHTLIB_ERROR_TIMEOUT:
        lcd.setCursor(0, 3);
	lcd.print("Time out error"); 
	break;
    case DHTLIB_ERROR_CONNECT:
        lcd.setCursor(0, 3);
        lcd.print("Connect error");
        break;
    case DHTLIB_ERROR_ACK_L:
        lcd.setCursor(0, 3);
        lcd.print("Ack Low error");
        break;
    case DHTLIB_ERROR_ACK_H:
        lcd.setCursor(0, 3);
        lcd.print("Ack High error");
        break;
    default:
        lcd.setCursor(0, 3);
        lcd.print("Unknown error"); 
	break;
  }
  
  lcd.setCursor(13, 0);
  lcd.print(DHT.temperature, 1);
  lcd.print(" C");
  lcd.setCursor(13, 1);
  lcd.print(DHT.humidity, 1);
  lcd.print(" %");
  
  delay(1000);
}
