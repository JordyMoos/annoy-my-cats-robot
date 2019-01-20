
//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
//****************************************************************

const int dataPin  = 3;  // DS
const int clockPin = 10; // SH_CP
const int latchPin = 13; // ST_CP

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  Serial.begin(9600);
  while (! Serial);
}

void loop() {
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay+= 50) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 255);

    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}
