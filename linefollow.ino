/*read line folloe sensors*/
String read_sensor_values()
{   int sensorvalue=32;
  sensor[0]= digitalRead(LFSensor_0);
 
  sensor[1]=digitalRead(LFSensor_1);
 
  sensor[2]=digitalRead(LFSensor_2);
 
  sensor[3]=digitalRead(LFSensor_3);
 
  sensor[4]=digitalRead(LFSensor_4);
  sensorvalue +=sensor[0]*16+sensor[1]*8+sensor[2]*4+sensor[3]*2+sensor[4];
 
  String senstr= String(sensorvalue,BIN);
  return senstr.substring(1,6);
}

//Automatic tracking
void auto_tarcking(){
 String sensorval= read_sensor_values();
 Serial.print("sensor status:");
 Serial.println(sensorval);
 if (sensorval=="00100" or sensorval=="01100" or sensorval=="11100" or sensorval=="11000" or sensorval=="10000"  or sensorval=="01000"){ //The black line is in the left of the car, need  left turn 
  
      go_Left();  //Turn left
      set_Motorspeed(0,TRACK_SPEED);
    }
 

 if (sensorval=="00110" or sensorval=="00111" or sensorval=="00011" or sensorval=="00001"  or sensorval=="00010"){ //The black line is  on the right of the car, need  right turn 
  
      go_Right();  //Turn right
        set_Motorspeed(TRACK_SPEED,0);
    }
 
     if (sensorval=="11111" or sensorval=="11011" or sensorval=="01111" or sensorval=="11110"){ //The car front touch stop line, need stop
  
      stop_Stop();  //Turn right
      set_Motorspeed(0,0);
    }

}

