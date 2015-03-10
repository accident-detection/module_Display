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
  int statusSensor;
  
  statusSensor = CheckSensorStatus(check);
  
  lcd.setCursor(13, 0);  // Ispis temperature
  lcd.print(DHT.temperature, 1);
  lcd.print(" C");
  lcd.setCursor(13, 1);  // Ispis vlažnosti
  lcd.print(DHT.humidity, 1);
  lcd.print(" %");
  lcd.setCursor(15, 3);  // Ispis error koda na lcd
  lcd.print(statusSensor);

  delay(1000);
}

int CheckSensorStatus (int check) {
 switch (check)
  {
    case DHTLIB_OK:  // Sve je u redu s komunikacijom
        lcd.setCursor(0, 3);
	lcd.print("OK");
        return 400;
    case DHTLIB_ERROR_CHECKSUM:  // Primljeni su krivi podaci
        lcd.setCursor(0, 3);
	lcd.print("Checksum error"); 
	return 401;
    case DHTLIB_ERROR_TIMEOUT: // Komunikacija nije uspijela s senzorom
        lcd.setCursor(0, 3);
	lcd.print("Time out error"); 
	return 402;
    case DHTLIB_ERROR_CONNECT:  // Jedan od pin-ova (vrlo vjerovatno data pin) je odspojen
        lcd.setCursor(0, 3);
        lcd.print("Connect error");
        return 403;
    case DHTLIB_ERROR_ACK_L:  // Data pin spojen na GND ili niski napon
        lcd.setCursor(0, 3);
        lcd.print("Ack Low error");
        return 404;
    case DHTLIB_ERROR_ACK_H:  // Data pin spojen na visoki napon (+3.3V ili vise)
        lcd.setCursor(0, 3);
        lcd.print("Ack High error");
        return 405;
    default:
        lcd.setCursor(0, 3);
        lcd.print("Unknown error"); 
	return 410;
  } 
}
