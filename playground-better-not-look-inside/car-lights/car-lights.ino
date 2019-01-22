#include "configuration.h"

#define PIN_DS    3 // DS Data
#define PIN_STCP 10 // ST_CP Storage register clock input
#define PIN_SHCP 13 // SH_CP Shift register clock input

boolean lights[8];

void setup()
{
  pinMode(PIN_DS, OUTPUT);
  pinMode(PIN_STCP, OUTPUT);
  pinMode(PIN_SHCP, OUTPUT);

  // Clear the lights
  writeLights();
}



void loop()
{
  for (int i = 0; i <= 7; i++)
  {
    lights[i] = HIGH;
    writeLights();
    delay(250);
  }

  for (int i = 0; i <= 7; i++)
  {
    lights[i] = LOW;
    writeLights();
    delay(250);
  }
}

void writeLights()
{
  digitalWrite(PIN_STCP, LOW);

  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(PIN_SHCP, LOW);
    digitalWrite(PIN_DS, lights[i]);
    digitalWrite(PIN_SHCP, HIGH);
  }

  digitalWrite(PIN_STCP, HIGH);
}

