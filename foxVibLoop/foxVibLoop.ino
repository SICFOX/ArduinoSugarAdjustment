#define vib 9

void setup() {
  pinMode(vib,OUTPUT);
}

void loop() {
  digitalWrite(vib,HIGH);
  delay(2000);
  digitalWrite(vib,LOW);
  delay(5000);
}
