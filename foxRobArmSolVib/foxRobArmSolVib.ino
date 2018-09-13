//RobotArmServoの可動範囲(5V 0.3AのDC電源での動作の場合)
//bottomServo:0-150
//frontbackServo:60-120
//updownServo:40-70

#include <VarSpeedServo.h>

#define vib 8
#define sol1 9
#define sol2 10

VarSpeedServo bottomServo;
VarSpeedServo frontbackServo;
VarSpeedServo updownServo;

int solKnockCount = 25;

void setup(){
  bottomServo.attach(3);
  frontbackServo.attach(5);
  updownServo.attach(6);

  //frontbackServoは角度固定のためsetup内で角度指定
  frontbackServo.write(60);
  frontbackServo.wait();

  //SolenoidとVibrationのピン設定
  pinMode(vib,OUTPUT);
  pinMode(sol1,OUTPUT);
}

void loop() {
  moveFillPos();
  delay(1000);
  solKnock();
  delay(3000);
  moveWaitPos();
  delay(3000);
}

//WaitPositionに戻る関数
void moveWaitPos(){
  updownServo.write(60,20,true);
  bottomServo.write(0,20,true);
  bottomServo.wait();
  updownServo.wait();
}

//砂糖FillPositionに戻る関数
void moveFillPos(){
  bottomServo.write(90,20,true);
  updownServo.write(70,20,true);
  bottomServo.wait();
  updownServo.wait();
}

//SolenoidとVibrationで砂糖を送り出す関数
void solKnock(){
  digitalWrite(vib,HIGH);
  for(int i=0; i<solKnockCount; i++){
  digitalWrite(sol1,HIGH);
  delay(70);
  digitalWrite(sol1,LOW);
  delay(30);
  }
  digitalWrite(vib,LOW);
}
