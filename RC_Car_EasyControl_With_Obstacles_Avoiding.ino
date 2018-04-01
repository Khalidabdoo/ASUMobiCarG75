#include <Ultrasonic.h>

int m1 = 3;
int m2 = 5;
int m3 = 6;
int m4 = 9;
int LEDFUSS = 4;
int USSCHECK = 0;
int LMSPEED = 165;
int RMSPEED = 205;

/*
   ex.: Ultrasonic ultrasonic1 (trigpin, echopin)
*/
Ultrasonic FUSS(12, 11);

char bt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(LEDFUSS, OUTPUT);




}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    bt = Serial.read();
   //enable ultrasonic sensor
     if ( bt == 'V'){
      USSCHECK = 1;
    }
    else if ( bt == 'v'){
      USSCHECK = 0;
    }
    stopp(); //initialize with motors stoped

// Car Control   

      switch (bt) {

        case 'F':
          forward();
          break;

        case 'B':
          backward();
          break;

        case 'L':
          left();
          break;

        case 'R':
          right();
          break;
          

      }
  
     //obstacle avoiding technique 
     if( (USSCHECK == 1 )&& (FUSS.distanceRead() < 10) && (FUSS.distanceRead() > 0)) {
      Serial.print("Obstacle Ahead  : "); Serial.println(FUSS.distanceRead());

      stopp();
      delay(500);
      right();
      delay(1200);
      stopp();
      return 0;
    }
     else{
      return 0;
    }
    
  }
}

void forward() {
  analogWrite(m1, LMSPEED);
  analogWrite(m2, 0);
  analogWrite(m3, RMSPEED);
  analogWrite(m4, 0);

}

void backward() {
  analogWrite(m1, 0);
  analogWrite(m2, LMSPEED);
  analogWrite(m3, 0);
  analogWrite(m4, RMSPEED);
}

void right() {
  analogWrite(m1, 0);
  analogWrite(m2, LMSPEED);
  analogWrite(m3, RMSPEED);
  analogWrite(m4, 0);
}

void left() {
  analogWrite(m1, LMSPEED);
  analogWrite(m2, 0);
  analogWrite(m3, 0);
  analogWrite(m4, RMSPEED);
}

void stopp() {
  analogWrite(m1, 0);
  analogWrite(m2, 0);
  analogWrite(m3, 0);
  analogWrite(m4, 0);
}


