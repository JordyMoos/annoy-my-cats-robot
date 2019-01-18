/*Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.*/
//Define L298N Dual H-Bridge Motor Controller Pins
#define dir1PinL  2    //Motor direction
#define dir2PinL  4    //Motor direction
#define speedPinL 6    // Needs to be a PWM pin to be able to control motor speed

#define dir1PinR  7    //Motor direction
#define dir2PinR  8   //Motor direction
#define speedPinR 5    // Needs to be a PWM pin to be able to control motor speed

#define IR_PIN    3 //IR receiver Signal pin connect to Arduino pin 3

// IR remote control buttons
#define IR_BUTTON_1         0x00FFA25D // 16753245
#define IR_BUTTON_2         0x00FF629D // 16736925
#define IR_BUTTON_3         0x00FFE21D // 16769565
#define IR_BUTTON_4         0x00FF22DD // 16720605
#define IR_BUTTON_5         0x00FF02FD // 16712445
#define IR_BUTTON_6         0x00FFC23D // 16761405
#define IR_BUTTON_7         0x00FFE01F // 16769055
#define IR_BUTTON_8         0x00FFA857 // 16754775
#define IR_BUTTON_9         0x00FF906F // 16748655
#define IR_BUTTON_0         0x00FF9867 // 16750695
#define IR_BUTTON_STAR      0x00FF6897 // 16738455
#define IR_BUTTON_HASHTAG   0x00FFB04F // 16756815
#define IR_BUTTON_LEFT      0x00FF10EF // 16716015
#define IR_BUTTON_UP        0x00FF18E7 // 16718055
#define IR_BUTTON_RIGHT     0x00FF5AA5 // 16734885
#define IR_BUTTON_DOWN      0x00FF4AB5 // 16730805
#define IR_BUTTON_OK        0x00FF38C7 // 16726215


#define IR_ADVANCE          IR_BUTTON_UP
#define IR_BACK             IR_BUTTON_DOWN
#define IR_LEFT             IR_BUTTON_LEFT
#define IR_RIGHT            IR_BUTTON_RIGHT
#define IR_STOP             IR_BUTTON_OK

enum DN
{ 
  GO_ADVANCE,
  GO_LEFT,
  GO_RIGHT,
  GO_BACK,
  STOP_STOP, 
  DEF
}Drive_Num=DEF;

bool stopFlag = true;//set stop flag
bool JogFlag = false;
uint16_t JogTimeCnt = 0;
uint32_t JogTime=0;
uint8_t motor_update_flag = 0;


