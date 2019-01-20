#include <IRremote.h>
#include <Servo.h>
#include "configuration.h"

Servo head;

IRrecv IR(IR_PIN);  //   IRrecv object  IR get code from IR remoter
decode_results IRresults;

/*motor control*/
void go_Advance(void)  //Forward
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
}
void go_Left()  //Turn left
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
}
void go_Right()  //Turn right
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
}
void go_Back()  //Reverse
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
}
void stop_Stop()    //Stop
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,LOW);
}

/*set motor speed */
void set_Motorspeed(int speed_L,int speed_R)
{
  analogWrite(speedPinL,speed_L); 
  analogWrite(speedPinR,speed_R);   
}
void buzz_ON()   //open buzzer
{
  digitalWrite(BUZZ_PIN, LOW);
}
void buzz_OFF()  //close buzzer
{
  digitalWrite(BUZZ_PIN, HIGH);
}

void alarm(){
   buzz_ON();
   delay(100);
   buzz_OFF();
}

//WiFi / Bluetooth through the serial control
void do_Uart_Tick()
{

  char Uart_Date=0;
  if(Serial.available()) 
  {
    size_t len = Serial.available();
    uint8_t sbuf[len + 1];
    sbuf[len] = 0x00;
    Serial.readBytes(sbuf, len);
    //parseUartPackage((char*)sbuf);
    memcpy(buffUART + buffUARTIndex, sbuf, len);//ensure that the serial port can read the entire frame of data
    buffUARTIndex += len;
    preUARTTick = millis();
    if(buffUARTIndex >= MAX_PACKETSIZE - 1) 
    {
      buffUARTIndex = MAX_PACKETSIZE - 2;
      preUARTTick = preUARTTick - 200;
    }
  }
  if(buffUARTIndex > 0 && (millis() - preUARTTick >= 100))//APP send flag to modify the obstacle avoidance parameters
  { //data ready
    buffUART[buffUARTIndex] = 0x00;
    if(buffUART[0]=='C') 
    {
      Serial.println(buffUART);
      Serial.println("You have modified the parameters!");//indicates that the obstacle avoidance distance parameter has been modified
      sscanf(buffUART,"CMD%d,%d,%d",&distancelimit,&sidedistancelimit,&turntime);
      // Serial.println(distancelimit);
      // Serial.println(sidedistancelimit);
      // Serial.println(turntime);
    }
    else  Uart_Date=buffUART[0];
    buffUARTIndex = 0;
  }

  switch (Uart_Date)    //serial control instructions
  {
    case '2':Drive_Status=MANUAL_DRIVE; Drive_Num=GO_ADVANCE;Serial.println("forward"); break;
    case '4':Drive_Status=MANUAL_DRIVE; Drive_Num=GO_LEFT; Serial.println("turn left");break;
    case '6':Drive_Status=MANUAL_DRIVE; Drive_Num=GO_RIGHT; Serial.println("turn right");break;
    case '8':Drive_Status=MANUAL_DRIVE; Drive_Num=GO_BACK; Serial.println("go back");break;
    case '5':Drive_Status=MANUAL_DRIVE; Drive_Num=STOP_STOP;buzz_OFF();Serial.println("stop");break;
    case '3':Drive_Status=AUTO_DRIVE_UO; Serial.println("avoid obstacles...");break;
    case '1':Drive_Status=AUTO_DRIVE_LF; Serial.println("line follow...");break;
    default:
        if (IR.decode(&IRresults))
          {
            Serial.println(IRresults.value);
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
    break;
  }
}

//car motor control
void do_Drive_Tick()
{
  if(Drive_Status == MANUAL_DRIVE)
  {
    switch (Drive_Num) 
    {
      case GO_ADVANCE:
          go_Advance();
          set_Motorspeed(255,255);
          JogFlag = true;
          JogTimeCnt = 1;
          JogTime=millis();
          break;
      case GO_LEFT: 
          go_Left();
          set_Motorspeed(255,255);
          JogFlag = true;
          JogTimeCnt = 1;
          JogTime=millis();
          break;
      case GO_RIGHT:  
          go_Right();
          set_Motorspeed(255,255);
          JogFlag = true;
          JogTimeCnt = 1;
          JogTime=millis();
          break;
      case GO_BACK: 
          go_Back();
          set_Motorspeed(255,255);
          JogFlag = true;
          JogTimeCnt = 1;
          JogTime=millis();
          break;
      case STOP_STOP: 
          stop_Stop();
          JogTime = 0;
          break;
      default:
          break;
    }
    Drive_Num=DEF;
    //keep the car running for 100ms
    if(millis()-JogTime>=100)
    {
      JogTime=millis();
      if(JogFlag == true) 
      {
        stopFlag = false;
        if(JogTimeCnt <= 0) 
        {
          JogFlag = false; stopFlag = true;
        }
        JogTimeCnt--;
      }
      if(stopFlag == true) 
      {
        JogTimeCnt=0;
        stop_Stop();
      }
    }
  }
  else if(Drive_Status==AUTO_DRIVE_LF)
  {
    auto_tarcking();
  }
  else if(Drive_Status==AUTO_DRIVE_UO)
  {
   auto_avoidance();
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
  
  pinMode(Trig_PIN, OUTPUT); 
  pinMode(Echo_PIN,INPUT); 

//  pinMode(BUZZ_PIN, OUTPUT);
//  buzz_OFF();  

//  pinMode(IR_PIN, INPUT);
//  digitalWrite(IR_PIN, HIGH);
//  IR.enableIRIn();

  pinMode(LFSensor_0,INPUT);
  pinMode(LFSensor_1,INPUT);
  pinMode(LFSensor_2,INPUT);
  pinMode(LFSensor_3,INPUT);
  pinMode(LFSensor_4,INPUT); 
  Serial.begin(9600);//In order to fit the Bluetooth module's default baud rate, only 9600
  digitalWrite(Trig_PIN,LOW);
  head.attach(SERVO_PIN); //servo
  head.write(90);

  Serial.print("number of digital pins: ");
  Serial.println(NUM_DIGITAL_PINS);
  Serial.print("number of analog inputs: ");
  Serial.println(NUM_ANALOG_INPUTS);
  Serial.println(A0);
  Serial.println(A4);
}

void loop()
{
//  delay(100);
//  do_Uart_Tick();
//  do_Drive_Tick();
}



