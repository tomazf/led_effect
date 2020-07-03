// Arduino 7ch LED effect
//
// Ferbi
//
// izhodi so invertirani zaradi optocouplerja !
// 0 = MAX  255 = MIN

#include "src/SoftPWM/SoftPWM.h"      // https://github.com/bhagman/SoftPWM

#define MIN_B 0

uint8_t leds[8] = {2, 3, 4, 5, 6, 7, 8};
uint8_t velikost = sizeof(leds) / sizeof(leds[0]);

// potenciometra
const int pot_1 = A0;
const int pot_2 = A1;

int value_pot_1;
int value_pot_2;

void setup()
{
  SoftPWMBegin();

  for (int i = 0; i < velikost; i++)
    SoftPWMSet(leds[i], 0);

  SoftPWMSetFadeTime(ALL, 2000, 2000);

  //Serial.begin(115200);  
}

void loop()
{
  value_pot_1 = map(analogRead(pot_1), 0, 1023, 0, 255);        // brightness
  value_pot_2 = map(analogRead(pot_2), 0, 1023, 100, 2000);     // delay

  for (int i = 0; i < velikost; i++)
  {
    SoftPWMSet(leds[i], random(MIN_B, value_pot_1));
    //SoftPWMSet(leds[i], value_pot_1);
  }
  delay(random(40, 500) + value_pot_2);
}
