
/*
 Drive
*/

#define PIN_DRIVE_LEFT_1      2
#define PIN_DRIVE_LEFT_2      4
#define PIN_DRIVE_LEFT_SPEED  6

#define PIN_DRIVE_RIGHT_1     7
#define PIN_DRIVE_RIGHT_2     8
#define PIN_DRIVE_RIGHT_SPEED 5

#define DRIVE_FORWARD_SPEED 255
#define DRIVE_REVERSE_SPEED 150
#define DRIVE_TURN_SPEED    150

/*
 Lights
*/

#define PIN_LIGHTS_DS    3 // DS Data
#define PIN_LIGHTS_STCP 10 // ST_CP Storage register clock input
#define PIN_LIGHTS_SHCP 13 // SH_CP Shift register clock input

#define LIGHTS_HEAD_LEFT_1   0
#define LIGHTS_HEAD_LEFT_2   1
#define LIGHTS_HEAD_RIGHT_1  2
#define LIGHTS_HEAD_RIGHT_2  3
#define LIGHTS_TAIL_LEFT     4
#define LIGHTS_TAIL_RIGHT    5
#define LIGHTS_REVERSE_LEFT  6
#define LIGHTS_REVERSE_RIGHT 7

#define LIGHTS_COUNT 8
boolean lights[LIGHTS_COUNT];

#define MAIN_LIGHTS_COUNT 6
int mainLightIndexes[MAIN_LIGHTS_COUNT];
bool redrawLights;

/*
 Infrared
*/

#define PIN_IR A0

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

#define TOGGLE_CAR_LIGHTS IR_BUTTON_STAR
#define CAR_TURN_LEFT     IR_BUTTON_LEFT
#define CAR_TURN_RIGHT    IR_BUTTON_RIGHT
#define CAR_FORWARD       IR_BUTTON_UP
#define CAR_REVERSE       IR_BUTTON_DOWN
#define CAR_STOP          IR_BUTTON_OK

IRrecv IR(PIN_IR);
decode_results IRresults;
