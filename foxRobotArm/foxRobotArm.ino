#include <VarSpeedServo.h>

Servo bottomServo;
Servo frontbackServo;
Servo updownServo;

char inputkey;

int bottomPos;
int frontbackPos;
int updownPos;

void setup(){
//  Serial.begin(9600);
  bottomServo.attach(3);
  frontbackServo.attach(5);
  updownServo.attach(6);
}

void loop() {
  moveFillPos();
  delay(2000);
  moveWaitPos();
  delay(2000);
}

void moveWaitPos(){
//   for(bottomPos=50; bottomPos>=0; bottomPos-=1){
//    for(frontbackPos=50; frontbackPos>=0; frontbackPos-=1){
//      frontbackServo.write(frontbackPos);
//      delay(30);
//    }
//      bottomServo.write(bottomPos);
//      delay(30);
//   }
//  bottomServo.write(0);
  frontbackServo.write(0);
}

void moveFillPos(){
//    for(bottomPos=0; bottomPos<=50; bottomPos+=1){
//      bottomServo.write(bottomPos);
//      delay(30);
//    }
//  bottomServo.write(50);
  frontbackServo.write(50);
}

void servoKey(){
    inputkey =Serial.read();
  if( inputkey !=-1){
    bottomPos = inputkey;
    bottomServoMove();
    Serial.print(inputkey);
  }
}

void bottomServoMove(){
  bottomServo.write(bottomPos);
  delay(1000);
}
