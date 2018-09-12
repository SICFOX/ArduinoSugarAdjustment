#define vib 9
#define sol1 10

int rotatingSpeed = 255;

char inputkey;

void setup() {
  Serial.begin(9600);
  pinMode(vib,OUTPUT);
  pinMode(sol1,OUTPUT);
}

void loop() {
  knockTimes();
}

void solKnock(){
  analogWrite(vib,rotatingSpeed);
  for(int i=0; i<5; i++){
  digitalWrite(sol1,HIGH);
  delay(70);
  digitalWrite(sol1,LOW);
  delay(30);
  }
  analogWrite(vib,0);
}

void knockTimes(){
  inputkey =Serial.read();
  if( inputkey !=-1){
    switch(inputkey){
      case '1':
        solKnock();
        Serial.println("ノック１回");
        break;
      case '2':
        for(int i=0; i<2; i++){
          solKnock();
        }
        Serial.println("ノック２回");
        break;
        case '3':
        for(int i=0; i<3; i++){
          solKnock();
        }
        Serial.println("ノック3回");
        break;
        case '4':
        for(int i=0; i<4; i++){
          solKnock();
        }
        Serial.println("ノック4回");
        break;
        case '5':
        for(int i=0; i<5; i++){
          solKnock();
        }
        Serial.println("ノック5回");
        break;
    }
  }
}
