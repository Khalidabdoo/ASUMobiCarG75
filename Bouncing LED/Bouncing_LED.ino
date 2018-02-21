
void setup() {
  // put your setup code here, to run once:

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 4; i < 8; i++) {
    digitalWrite(i, 1);
    delay(1000);
    digitalWrite(i, 0);

  }
  for (int j = 6; j > 4; j--) {
    digitalWrite(j, 1);
    delay(1000);
    digitalWrite(j, 0);


  }
}

