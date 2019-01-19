/*detection of ultrasonic distance*/
int watch(){
  long howfar;
  digitalWrite(Trig_PIN,LOW);
  delayMicroseconds(5);                                                                              
  digitalWrite(Trig_PIN,HIGH);
  delayMicroseconds(15);
  digitalWrite(Trig_PIN,LOW);
  howfar=pulseIn(Echo_PIN,HIGH);
  howfar=howfar*0.01657; //how far away is the object in cm
  //Serial.print((int)howfar);
  //Serial.println(" cm");
  return round(howfar);
}
//Meassures distances to the right, left, front, left diagonal, right diagonal and asign them in cm to the variables rightscanval, 
//leftscanval, centerscanval, ldiagonalscanval and rdiagonalscanval (there are 5 points for distance testing)
String watchsurrounding(){
/*  obstacle_status is a binary integer, its last 5 digits stands for if there is any obstacles in 5 directions,
 *   for example B101000 last 5 digits is 01000, which stands for Left front has obstacle, B100111 means front, right front and right ha
 */
 
int obstacle_status =B100000;
  centerscanval = watch();
  if(centerscanval<distancelimit){
    stop_Stop();
    alarm();
    obstacle_status  =obstacle_status | B100;
    }
  head.write(120);
  delay(100);
  ldiagonalscanval = watch();
  if(ldiagonalscanval<distancelimit){
    stop_Stop();
    alarm();
     obstacle_status  =obstacle_status | B1000;
    }
  head.write(170); //Didn't use 180 degrees because my servo is not able to take this angle
  delay(300);
  leftscanval = watch();
  if(leftscanval<sidedistancelimit){
    stop_Stop();
    alarm();
     obstacle_status  =obstacle_status | B10000;
    }
  head.write(120);
  delay(100);
  ldiagonalscanval = watch();
  if(ldiagonalscanval<distancelimit){
    stop_Stop();
    alarm();
    obstacle_status  =obstacle_status | B1000;
    }
  head.write(90); //use 90 degrees if you are moving your servo through the whole 180 degrees
  delay(100);
  centerscanval = watch();
  if(centerscanval<distancelimit){
    stop_Stop();
    alarm();
    obstacle_status  =obstacle_status | B100;
    }
  head.write(40);
  delay(100);
  rdiagonalscanval = watch();
  if(rdiagonalscanval<distancelimit){
    stop_Stop();
    alarm();
    obstacle_status  =obstacle_status | B10;
    }
  head.write(0);
  delay(100);
  rightscanval = watch();
  if(rightscanval<sidedistancelimit){
    stop_Stop();
    alarm();
    obstacle_status  =obstacle_status | 1;
    }
  head.write(90); //Finish looking around (look forward again)
  delay(300);
   String obstacle_str= String(obstacle_status,BIN);
  obstacle_str= obstacle_str.substring(1,6);
  
  return obstacle_str; //return 5-character string standing for 5 direction obstacle status
}


void auto_avoidance(){
 set_Motorspeed(AD_SPEED1,AD_SPEED1);
  go_Advance();  // if nothing is wrong go forward using go() function above.
  ++numcycles;
  if(numcycles>=80){ //Watch if something is around every 100 loops while moving forward 
     stop_Stop();
    String obstacle_sign=watchsurrounding(); // 5 digits of obstacle_sign binary value means the 5 direction obstacle status
      Serial.print("obstacle status=");
        Serial.println(obstacle_sign);
    if( obstacle_sign=="11100" || obstacle_sign=="11000"  || obstacle_sign=="10100"  || obstacle_sign=="01100"  || obstacle_sign=="01110" ||obstacle_sign=="00100"  ||obstacle_sign=="01000" ){
      go_Right();
      delay(turntime);
      stop_Stop();
    }
    if(obstacle_sign=="00111" || obstacle_sign=="00011"  || obstacle_sign=="00101" || obstacle_sign=="00110" || obstacle_sign=="01010"  || obstacle_sign=="00010"  ){
      go_Left();
      delay(turntime);
      stop_Stop();
    }
 
    if(  obstacle_sign=="11111" || obstacle_sign=="01111" ||  obstacle_sign=="10111" ||  obstacle_sign=="11011" ||  obstacle_sign=="11101"  ||  obstacle_sign=="11110"  ){
          go_Back();
		  set_Motorspeed(BACK_SPEED1,BACK_SPEED2);
       delay(backtime);
          stop_Stop();
        }
    numcycles=0; //Restart count of cycles
  }
  distance = watch(); // use the watch() function to see if anything is ahead (when the robot is just moving forward and not looking around it will test the distance in front)
  if (distance<distancelimit){ // The robot will just stop if it is completely sure there's an obstacle ahead (must test 25 times) (needed to ignore ultrasonic sensor's false signals)
  go_Back();
      ++thereis;}
  if (distance>distancelimit){
      thereis=0;} //Count is restarted
  if (thereis > 25){
    stop_Stop(); // Since something is ahead, stop moving.
    thereis=0;
  }
}

