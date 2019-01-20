#include <IRremote.h>
#include "configuration.h"

void setup()
{
  // IR
  pinMode(PIN_IR, INPUT);
  digitalWrite(PIN_IR, HIGH);
  IR.enableIRIn();
  
  // Lights
  pinMode(PIN_LIGHTS_DS, OUTPUT);
  pinMode(PIN_LIGHTS_STCP, OUTPUT);
  pinMode(PIN_LIGHTS_SHCP, OUTPUT);

  mainLightIndexes[0] = LIGHTS_HEAD_LEFT_1;
  mainLightIndexes[1] = LIGHTS_HEAD_LEFT_2;
  mainLightIndexes[2] = LIGHTS_HEAD_RIGHT_1;
  mainLightIndexes[3] = LIGHTS_HEAD_RIGHT_2;
  mainLightIndexes[4] = LIGHTS_TAIL_LEFT;
  mainLightIndexes[5] = LIGHTS_TAIL_RIGHT;

  // Clear the lights
  writeLights();

  // Serial monitor
  Serial.begin(9600);
  while ( ! Serial);
}

void loop()
{
  redrawLights = false;

  updateTurningLights();
  readIR();

  if (redrawLights)
  {
    writeLights();
  }
  
  delay(20);
}

void readIR()
{
  if (IR.decode(&IRresults))
  {
    switch (IRresults.value)
    {
      case TOGGLE_CAR_LIGHTS:
        toggleMainLights();
      break;

      case CAR_FORWARD:
        driveForward();
        setReverseLights(false);
        setTurnLeftLights(false);
        setTurnRightLights(false);
      break;
      
      case CAR_REVERSE:
        driveReverse();
        setReverseLights(true);
        setTurnLeftLights(false);
        setTurnRightLights(false);
      break;

      case CAR_TURN_LEFT:
        driveLeft();
        setReverseLights(false);
        setTurnLeftLights(true);
        setTurnRightLights(false);
      break;

      case CAR_TURN_RIGHT:
        driveRight();
        setReverseLights(false);
        setTurnLeftLights(false);
        setTurnRightLights(true);
      break;

      case CAR_STOP:
        driveStop();
        setReverseLights(false);
        setTurnLeftLights(false);
        setTurnRightLights(false);
      break;
    }

    IRresults.value = 0;
    IR.resume();
  }
}



