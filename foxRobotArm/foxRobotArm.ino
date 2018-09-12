//RobotArmServoの可動範囲(5V 0.3AのDC電源での動作の場合)
//bottomServo:0-150
//frontbackServo:60-120
//updownServo:40-70

#include <VarSpeedServo.h>

VarSpeedServo bottomServo;
VarSpeedServo frontbackServo;
VarSpeedServo updownServo;

void setup(){
  bottomServo.attach(3);
  frontbackServo.attach(5);
  updownServo.attach(6);

  //frontbackServoは角度固定のためsetup内で角度指定
  frontbackServo.write(60);
  frontbackServo.wait();
}

void loop() {
  moveFillPos();
  delay(2000);
  moveWaitPos();
  delay(2000);
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
