int m1 = 5;
int m2 = 6;
int m3 = 10;
int m4 = 11;

char bt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    bt = Serial.read();
    
 /*__________________________________________________________*/
 if (bt=='F')
 forward();
 else if (bt=='B')
 backward();
 else if (bt=='R')
 right();
 else if (bt=='L')
 left();
 else if (bt=='S')
 stopp();
  }
  }
  void forward() {
    analogWrite(m1, 155);
    analogWrite(m2, 0);
    analogWrite(m3, 155);
    analogWrite(m4, 0);

  }

  void backward() {
    analogWrite(m1, 0);
    analogWrite(m2, 155);
    analogWrite(m3, 0);
    analogWrite(m4, 155);
  }

  void right() {
    analogWrite(m1, 155);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 155);
  }

  void left() {
    analogWrite(m1, 0);
    analogWrite(m2, 155);
    analogWrite(m3, 155);
    analogWrite(m4, 0);
  }

  void stopp() {
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
  }

