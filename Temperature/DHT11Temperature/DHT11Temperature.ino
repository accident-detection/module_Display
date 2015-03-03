// 

#include <dht.h>

dht DHT;

#define DHT11_PIN 5 // Na koji digitalni port se spaja podatkovni pin senzora

void setup()
{
  Serial.begin(19200);
  Serial.println("Test DHT senzora");
  Serial.print("Verzija library-a: ");
  Serial.println(DHT_LIB_VERSION);  // Ispis trenutne verzije library-a, sve verzije od, i uključujući 0.1.13 rade na svim arduinima
  Serial.println("\nTip\tStatus\tVlaznost\tTemperatura");  //Tip: tip senzora, Status: da li je sve u redu s ocitavanjem podataka s senzora
}

void loop()
{
  Serial.print("DHT11\t");
  int check = DHT.read11(DHT11_PIN);  // Čita pin s kojeg se primaju podaci
                                      //DHT11_PIN se moze promijeniti za druge verzije senzora po potrebi
                                      
  // Ispis statusa senzora
  switch (check)
  {
    case DHTLIB_OK:  // Sve je u redu
	Serial.print("OK\t"); 
	break;
    case DHTLIB_ERROR_CHECKSUM: // Primljeni podaci su krivi
	Serial.print("Checksum error\t"); 
	break;
    case DHTLIB_ERROR_TIMEOUT: // Komunikacija s senzorom nije uspijela
	Serial.print("Time out error\t"); 
	break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
        Serial.print("Unknown error\t"); 
	break;
  }
  
  // Ispis primljenih podataka
  Serial.print(DHT.humidity, 1);
  Serial.print(" %");
  Serial.print("\t\t");
  Serial.print(DHT.temperature, 1);
  Serial.println(" C");

  delay(2000);
}
