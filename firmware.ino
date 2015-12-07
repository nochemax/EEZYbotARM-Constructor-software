#include <Servo.h>

Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;

int incomingByte = 0;
int incomingByte1 = 0; 
int incomingByte2 = 0;
int incomingByte3 = 0;

int pos=0;
int pos1=0;
int pos2=0;
int pos3=0;

int incomingByteold =  0; 
int incomingByteold1 = 0;
int incomingByteold2 = 0; 
int incomingByteold3 = 0; 

int incomingBytemenu = 0; 

void setup(){
  
  Serial.begin(9600); 
  servo.attach(9); 
  delay(15);
  servo1.attach(10); 
  delay(15);
  servo2.attach(11);
  delay(15);
  servo3.attach(6);
  delay(15);
}

void loop() {

  switch (incomingBytemenu) {

  case 1:

    while (Serial.available()>1) {
      incomingByte = Serial.read();

      if(incomingByte >= 25 && incomingByte <= 165){
        pos = incomingByte;
      } 
      else{
        pos = pos; 

      }
      servo.write(pos);  
      if (incomingByteold != incomingByte && incomingByte <= 24){
        Serial.flush();
        incomingBytemenu=0;
        incomingByteold=incomingByte;
      }  
    }

    break;
  case 2:

    while (Serial.available()>1) {
      incomingByte1 = Serial.read();

      if(incomingByte1 >= 25 && incomingByte1 <= 165){
        pos1 = incomingByte1;
      } 
      else{
        pos1 = pos1; 

      }
      servo1.write(pos1);  
      if (incomingByteold1 != incomingByte1 && incomingByte <= 24){
        Serial.flush();
        incomingBytemenu=0;
        incomingByteold1=incomingByte1;

      }   
    }

    break;
  case 3:

    while (Serial.available()>1) {
      incomingByte2 = Serial.read();

      if(incomingByte2 >= 25 && incomingByte2 <= 165){
        pos2 =incomingByte2;
      } 
      else{
        pos2 = pos2; 
      }
      servo2.write(pos2);  

      if (incomingByteold2 != incomingByte2 && incomingByte <= 24){
        Serial.flush();
        incomingBytemenu=0;
        incomingByteold2=incomingByte2;
      }
    }
    break;
  case 4:

    while (Serial.available()>1) {
      incomingByte3 = Serial.read();

      if(incomingByte3 >= 25 && incomingByte3 <= 165){
        pos3 =incomingByte3;
      } 
      else{
        pos3 = pos3; 
      }
      servo3.write(pos3);  

      if (incomingByteold3 != incomingByte3 && incomingByte <= 24){
        Serial.flush();
        incomingBytemenu=0;
        incomingByteold3=incomingByte3;
      }
    }
    break;
  default:

    if (Serial.available()>0) {
      incomingBytemenu = Serial.read(); 
      Serial.println(incomingBytemenu, DEC);
      Serial.flush();
    }
    incomingByte = 0; 
    break;
  }
}
