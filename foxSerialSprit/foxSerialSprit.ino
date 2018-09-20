int i = 0;
char buf[20];
int ch[5];

void setup() {
  Serial.begin(9600);
}

void loop() {
 if (Serial.available()) {
    buf[i] = Serial.read();
    if (buf[i] == 'e') {
      buf[i] = '\0';
      //Serial.println(buf);

      ch[0] = atoi(strtok(buf, ","));
      ch[1] = atoi(strtok(NULL, ","));

      Serial.println(ch[0]);
      Serial.println(ch[1]);
      i = 0;
    }
    else {
      i++;
    }
  }
}
