int i = 0;
char buf[20];
int ch[5];
int a,b;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
 if (Serial.available()) {
    buf[i] = Serial.read();
    if (buf[i] == 'e') {
      buf[i] = '\0';
      //Serial.println(buf);

      a = atoi(strtok(buf, ","));
      b = atoi(strtok(NULL, ","));

      Serial.println(a);
      Serial.println(b);
      blink(a,b);
      i = 0;
    }
    else {
      i++;
    }
  }
}

void blink(int x,int y){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(x*1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(y*1000);
}
