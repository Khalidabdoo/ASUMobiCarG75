#include <l298n_lib.h>
#include <Ultrasonic.h>


int LEDFUSS = 4;
int USSCHECK = 0;

/*
   ex.: Ultrasonic ultrasonic1 (trigpin, echopin)
*/
Ultrasonic FUSS(12, 11);

char bt = 0;

void setup() {
  set_pins(3, 5, 6, 9, 8, 10);

  Serial.begin(9600);

  pinMode(LEDFUSS, OUTPUT);




}

void loop() {



  if ( (USSCHECK == 1 ) && (FUSS.distanceRead() < 10) && (FUSS.distanceRead() != 0 )) {
    Serial.print("Obstacle Ahead  : "); Serial.println(FUSS.distanceRead());
    digitalWrite(LEDFUSS, HIGH);
    obstacleAvoid();
    return 0;
  }



  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    bt = Serial.read();

    dmot_stop();
    lmot_stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);
    if ( bt == 'V') {
      USSCHECK = 1;
    }

    else if ( bt == 'v') {
      USSCHECK = 0;
    }
    // Car Control
    switch (bt) {

      case 'F' :
        lmot('F', 255);
        dmot('F', 255);
        break;

      case 'B' :
        lmot ('B', 255);
        dmot ('B', 255);
        break;


      case 'R':
        Serial.println("YEMEEEEENNN");
        dmot('F', 255);
        lmot('B', 255);

        break;


      case 'L':

        lmot( 'F', 255);
        dmot('B', 255);
        break;

      case 'I':
        lmot( 'F', 127);
        dmot( 'F', 255);
        break;

      case 'G':
        lmot('F', 255);
        dmot( 'F', 127);
        break;

      case 'J':
        lmot( 'B', 127);
        dmot( 'B', 255);
        break;

      case 'H':
        lmot('B', 255);
        dmot( 'B', 127);
        break;

      case 'S' :
        lmot_stop();
        dmot_stop();



    }
    // End of Car Control





  }
}
void obstacleAvoid() {
  if ((FUSS.distanceRead() < 10 ) && (FUSS.distanceRead() != 0 )) {

    dmot_stop();
    lmot_stop();
    delay(500);
    lmot('B', 200);
    dmot('B', 200);
    delay(400);
    dmot('B', 255);
    lmot('F', 255);
    delay(1000);
    dmot_stop();
    lmot_stop();

  }
}




