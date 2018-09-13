#define vib 8 
#define sol1 9
#define sol2 10

void setup() {
  pinMode(vib,OUTPUT);
  pinMode(sol1,OUTPUT);
  pinMode(sol2,OUTPUT);
}

void loop() {
  for(int i=9; i<=10; i++){
    solKnock(i);
    delay(1000);
  }
}

void solKnock(int x){
  digitalWrite(vib,HIGH);
  for(int i=0; i<20; i++){
  digitalWrite(x,HIGH);
  delay(70);
  digitalWrite(x,LOW);
  delay(30);
  }
  digitalWrite(vib,LOW);
}
