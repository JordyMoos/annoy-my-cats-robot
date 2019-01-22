// Define L298N Dual H-Bridge Motor Controller Pins
#define dir1PinL  2    // Motor direction
#define dir2PinL  4    // Motor direction
#define speedPinL 6    // Needs to be a PWM pin to be able to control motor speed
#define dir1PinR  7    // Motor direction
#define dir2PinR  8    // Motor direction
#define speedPinR 5    // Needs to be a PWM pin to be able to control motor speed

#define SERVO_PIN 9    // Servo

// From left to right, connect to D3, A1-A3, D10
#define LFSensor_0  3
#define LFSensor_1 A1
#define LFSensor_2 A2
#define LFSensor_3 A3
#define LFSensor_4 10

#define Echo_PIN   11  // Ultrasonic Echo pin
#define Trig_PIN   12  // Ultrasonic Trig pin

#define BUZZ_PIN   A0  // Buzzer

#define IR_PIN     13  // IR receiver Signal pin

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

int sensor[5];
#define AD_SPEED1   200 // Avoidance motor speed
#define BACK_SPEED1 100 // Back speed
#define BACK_SPEED2 150 // Back speed
#define TRACK_SPEED 150 // Line follow motor speed

// Line tracker
int leftscanval, centerscanval, rightscanval, ldiagonalscanval, rdiagonalscanval;
// Ultrasonic
int distancelimit = 30;     // Distance limit for obstacles in front
int sidedistancelimit = 30; // Minimum distance in cm to obstacles at both sides

const int turntime = 800;   // Time the robot spends turning
const int backtime = 600;   // Time the robot spends turning
int distance;
int numcycles = 0;

int thereis;
bool flag1 = false;
bool stopFlag = true;
bool JogFlag = false;
uint16_t JogTimeCnt = 0;
uint32_t JogTime = 0;

#define MAX_PACKETSIZE 32   // Serial receive buffer
char buffUART[MAX_PACKETSIZE];
unsigned int buffUARTIndex = 0;
unsigned long preUARTTick = 0;

enum DS
{
  MANUAL_DRIVE,
  AUTO_DRIVE_LF, // line follow
  AUTO_DRIVE_UO  // Ultrasonic obstruction
} Drive_Status = MANUAL_DRIVE;

enum DN
{ 
  GO_ADVANCE, 
  GO_LEFT, 
  GO_RIGHT,
  GO_BACK,
  STOP_STOP,
  DEF
} Drive_Num = DEF;
