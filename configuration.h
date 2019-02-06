
/*
    PS4 Controller
*/

USB Usb;

// For USB connection
PS4USB PS4(&Usb);

// For BlueTooth connection
//BTD Btd(&Usb)
// In case you need to pair
//PS4BT PS4(&Btd, PAIR);
// In case you are already paired
//PS4BT PS4(&Btd);

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

enum DriveStatus {
  DRIVING_FORWARD,
  DRIVING_REVERSE,
  DRIVING_LEFT,
  DRIVING_RIGHT,
  DRIVING_STOPPED
} driveStatus = DRIVING_STOPPED;

/*
    Lights
*/

#define PIN_LIGHTS_DS          40 // DS Data
#define PIN_LIGHTS_STCP        41 // ST_CP Storage register clock input
#define PIN_LIGHTS_SHCP        42 // SH_CP Shift register clock input

#define LIGHTS_HEAD_LEFT_1      0
#define LIGHTS_HEAD_LEFT_2      1
#define LIGHTS_HEAD_RIGHT_1     2
#define LIGHTS_HEAD_RIGHT_2     3
#define LIGHTS_HEAD_TURN_LEFT   4
#define LIGHTS_HEAD_TURN_RIGHT  5
#define LIGHTS_TAIL_TURN_LEFT   6
#define LIGHTS_TAIL_TURN_RIGHT  7

#define LIGHTS_TAIL_LEFT        8
#define LIGHTS_TAIL_RIGHT       9
#define LIGHTS_REVERSE_LEFT    10
#define LIGHTS_REVERSE_RIGHT   11

#define LIGHTS_COUNT           16
boolean lights[LIGHTS_COUNT];

#define MAIN_LIGHTS_COUNT       6
int mainLightIndexes[MAIN_LIGHTS_COUNT];

#define TURNING_BLINKING_TIME 300

bool redrawLights;

/*
    Buzzer
*/

#define PIN_BUZZER 53

#define BUZZER_REVERSE_TIME 300

/*
    Laser
*/

#define PIN_LASER                              50
#define PIN_LASER_MOTOR_HORIZONTAL             51
#define PIN_LASER_MOTOR_VERTICAL               52

#define LASER_HORIZONTAL_CENTER_LOCATION       95
#define LASER_HORIZONTAL_ANIMATE_MIN_LOCATION  15
#define LASER_HORIZONTAL_ANIMATE_MAX_LOCATION 165
#define LASER_HORIZONTAL_STEP_SIZE              1 

#define LASER_MOTOR_GROUND_LOCATION           140
#define LASER_MOTOR_GROUND_FAR_LOCATION       110
#define LASER_MOTOR_CEILING_LOCATION           20

Servo laserMotorHorizontal;
Servo laserMotorVertical;

bool laserState;
int laserHorizontalLocation;

enum LASER_HORIZONTAL_STATE
{
  LASER_HORIZONTAL_CENTERED,
  LASER_HORIZONTAL_ANIMATING_LEFT,
  LASER_HORIZONTAL_ANIMATING_RIGHT
} laserHorizontalState = LASER_HORIZONTAL_CENTERED;
