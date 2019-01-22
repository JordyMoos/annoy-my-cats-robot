
/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____
   / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \
  | |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
   \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
                    (____/
   www.osoyoo.com IR remote control smart car
   program tutorial : http://osoyoo.com/2017/04/16/control-smart-car-with-ir/
    Copyright John Yu
*/
#include <IRremote.h>
#include "configuration.h"

IRrecv IR(IR_PIN);  //   IRrecv object  IR get code from IR remoter
decode_results IRresults;

/***************motor control***************/
void go_Advance(void)
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL, LOW);
  digitalWrite(dir1PinR, HIGH);
  digitalWrite(dir2PinR, LOW);
  analogWrite(speedPinL, 255);
  analogWrite(speedPinR, 255);
}
void go_Left()
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL, LOW);
  digitalWrite(dir1PinR, LOW);
  digitalWrite(dir2PinR, HIGH);
  analogWrite(speedPinL, 150);
  analogWrite(speedPinR, 150);
}
void go_Right()
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL, HIGH);
  digitalWrite(dir1PinR, HIGH);
  digitalWrite(dir2PinR, LOW);
  analogWrite(speedPinL, 150);
  analogWrite(speedPinR, 150);
}
void go_Back()
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL, HIGH);
  digitalWrite(dir1PinR, LOW);
  digitalWrite(dir2PinR, HIGH);
  analogWrite(speedPinL, 255);
  analogWrite(speedPinR, 255);
}
void stop_Stop()
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL, LOW);
  digitalWrite(dir1PinR, LOW);
  digitalWrite(dir2PinR, LOW);
}

/**************detect IR code***************/
void do_IR_Tick()
{
  if (IR.decode(&IRresults))
  {
    switch (IRresults.value)
    {
      case IR_ADVANCE: Drive_Num = GO_ADVANCE; break;
      case IR_BACK: Drive_Num = GO_BACK; break;
      case IR_LEFT: Drive_Num = GO_LEFT; break;
      case IR_RIGHT: Drive_Num = GO_RIGHT; break;
      case IR_STOP: Drive_Num = STOP_STOP; break;
    }

    IRresults.value = 0;
    IR.resume();
  }
}

/**************car control**************/
void do_Drive_Tick()
{
  switch (Drive_Num)
  {
    case GO_ADVANCE: go_Advance(); break;
    case GO_LEFT: go_Left(); break;
    case GO_RIGHT:  go_Right(); break;
    case GO_BACK: go_Back(); break;
    case STOP_STOP: stop_Stop(); break;
  }
}

void setup()
{
  pinMode(dir1PinL, OUTPUT);
  pinMode(dir2PinL, OUTPUT);
  pinMode(speedPinL, OUTPUT);
  pinMode(dir1PinR, OUTPUT);
  pinMode(dir2PinR, OUTPUT);
  pinMode(speedPinR, OUTPUT);
  stop_Stop();

  pinMode(IR_PIN, INPUT);
  digitalWrite(IR_PIN, HIGH);
  IR.enableIRIn();

  // Setup serial monitor
  Serial.begin(9600);
  while (! Serial);
}

void loop()
{
  do_IR_Tick();
  do_Drive_Tick();
  delay(20);
}
