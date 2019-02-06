// PS4 Dependencies
#include <PS4USB.h>
//#include <PS4BT.h>
//#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

#include <Servo.h>
#include "configuration.h"

void setup() {
    // Serial monitor
    Serial.begin(115200);
    while (!Serial);
    
    // PS4 Controller
    if (Usb.Init() == -1) {
        Serial.println("Something wrong with the controller");
        while (1);
    }
    Serial.println("PS4 library started");

    // Buzzer
    pinMode(PIN_BUZZER, OUTPUT);
    buzzOff();

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
//  writeLights();

    // Laser
    pinMode(PIN_LASER, OUTPUT);
    setLaser(false);

    // Lasers horizontal motor
    laserMotorHorizontal.attach(PIN_LASER_MOTOR_HORIZONTAL);
    startLaserAnimation();

    // Lasers vertical motor
    laserMotorVertical.attach(PIN_LASER_MOTOR_VERTICAL);
    laserTargetGroundFar();
}

void loop() {
//  redrawLights = false;
//  updateTurningLights();

    readPs4Controller();

    /*
    if (redrawLights)
    {
      writeLights();
    }

    updateBuzzer();
     */
}

void readPs4Controller() {
    Usb.Task();

    if (PS4.connected()) {
        // Car direction
        if (isControllerDrivingForward()) {
            driveForward();
            setReverseLights(false);
            setTurnLeftLights(false);
            setTurnRightLights(false);
        } else if (isControllerDrivingBackward()) {
            driveReverse();
            setReverseLights(true);
            setTurnLeftLights(false);
            setTurnRightLights(false);
        } else if (isControllerDrivingLeft()) {
            driveLeft();
            setReverseLights(false);
            setTurnLeftLights(true);
            setTurnRightLights(false);
        } else if (isControllerDrivingRight()) {
            driveRight();
            setReverseLights(false);
            setTurnLeftLights(false);
            setTurnRightLights(true);
        } else {
            driveStop();
            setReverseLights(false);
            setTurnLeftLights(false);
            setTurnRightLights(false);
        }
        
        // Laser direction
        if (isControllerLaserUp()) {
          laserGoUp();
        } else if (isControllerLaserDown()) {
          laserGoDown();
        }
        if (isControllerLaserLeft()) {
          laserGoLeft();
        } else if (isControllerLaserRight()) {
          laserGoRight();
        }

        // Laser light
        if (isToggleLaser()) {
            toggleLaser();
        }

        delay(10);

    } else {
        Serial.println("Controller not connected");
        delay(100);
    }
}
