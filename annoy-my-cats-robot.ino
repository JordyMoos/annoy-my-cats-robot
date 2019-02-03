#include <IRremote.h>
#include <Servo.h>
#include "configuration.h"

void setup()
{
  // Buzzer
  pinMode(PIN_BUZZER, OUTPUT);
  buzzOff();  
  
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
  //writeLights();

  // Laser
  pinMode(PIN_LASER, OUTPUT);
  setLaser(false);

  // Lasers horizontal motor
  laserMotorHorizontal.attach(PIN_LASER_MOTOR_HORIZONTAL);
  setLaserCenter();
  
  // Lasers vertical motor
  laserMotorVertical.attach(PIN_LASER_MOTOR_VERTICAL);
  laserTargetGround();
  
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
  //  writeLights();
  }

  updateBuzzer();
  updateLaserAnimation();
  
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

      case LASER_TOGGLE:
        toggleLaser();
      break;

      case LASER_HORIZONTAL_CENTER:
        setLaserCenter();
      break;

      case LASER_HORIZONTAL_ANIMATE:
        startLaserAnimation();
      break;

      case LASER_VERTICAL_GROUND:
        laserTarget(LASER_MOTOR_GROUND_LOCATION);
      break;

      case LASER_VERTICAL_GROUND_FAR:
        laserTarget(LASER_MOTOR_GROUND_FAR_LOCATION);
      break;

      case LASER_VERTICAL_CEILING:
        laserTarget(LASER_MOTOR_CEILING_LOCATION);
      break;
    }

    IRresults.value = 0;
    IR.resume();
  }
}

