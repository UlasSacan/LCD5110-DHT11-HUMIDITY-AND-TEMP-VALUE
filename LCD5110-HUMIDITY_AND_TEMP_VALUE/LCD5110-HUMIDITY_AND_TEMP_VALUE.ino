#include <LCD5110_Basic.h>
#include <dht11.h>

LCD5110 myGLCD(8, 9, 10, 11, 12);

#define DHT11PIN 2
dht11 DHT11;

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void setup()
{
  myGLCD.InitLCD();


}

void loop()
{
  int veri = DHT11.read(DHT11PIN);
  int x = DHT11.humidity;
  float y = DHT11.temperature;

  myGLCD.setFont(SmallFont);
  myGLCD.print("Nem", CENTER, 0 );
  myGLCD.print("     %", LEFT, 8 );
  myGLCD.printNumI(x , CENTER, 8);
  myGLCD.print("--------------------", CENTER, 16 );
  delay(100);
  myGLCD.setFont(SmallFont);
  myGLCD.print("Sicaklik", CENTER, 24 );
  myGLCD.printNumI(y , CENTER, 32);
  delay(100);
}
