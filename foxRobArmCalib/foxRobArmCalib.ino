//RobotArmServoの可動範囲(5V 0.3AのDC電源での動作の場合)
//bottomServo:0-150
//frontbackServo:60-120
//updownServo:40-70

#include <VarSpeedServo.h>

VarSpeedServo bottomServo;
VarSpeedServo frontbackServo;
VarSpeedServo updownServo;

#define vib 8
#define sol1 9
#define sol2 10
#define sol3 11
#define sol4 12

char inputKey;  //キーボード入力用の変数
char buf[20];   //Serial通信用バッファの変数
int candyColor;   //砂糖の色(0~3の4通り、0:white,1:red,2:green,3.blue)
int solKnockCount;   //solKnock()でSolenoidが叩く回数
int j = 0;    //Serial通信用のバッファ数

void setup() {
  //RobotArmのServoのピン番号指定
  bottomServo.attach(3);
  frontbackServo.attach(5);
  updownServo.attach(6);

  //frontbackServoは角度固定のためsetup内で角度指定
  frontbackServo.write(10);
  frontbackServo.wait();

  //SolenoidとVibrationのピン設定
  pinMode(vib, OUTPUT);
  pinMode(sol1, OUTPUT);
  pinMode(sol2, OUTPUT);
  pinMode(sol3, OUTPUT);
  pinMode(sol4, OUTPUT);
}

void loop() {
  moveFillPos();
  delay(1000);
  moveWaitPos();
  delay(1000);  
}

//WaitPositionに戻る関数
void moveWaitPos() {
  updownServo.write(60, 20, true);
  bottomServo.write(0, 20, true);
  bottomServo.wait();
  updownServo.wait();
}

//砂糖FillPositionに戻る関数
void moveFillPos() {
  bottomServo.write(0, 20, true);
  updownServo.write(180, 20, true);
  bottomServo.wait();
  updownServo.wait();
}
