#define vib 8 
#define sol1 9

void setup() {
  pinMode(vib,OUTPUT);
  pinMode(sol1,OUTPUT);
}

void loop() {
  solKnock();
  delay(5000);
}

void solKnock(){
  digitalWrite(vib,HIGH);
  for(int i=0; i<20; i++){
  digitalWrite(sol1,HIGH);
  delay(70);
  digitalWrite(sol1,LOW);
  delay(30);
  }
  digitalWrite(vib,LOW);
}
