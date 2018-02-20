
 /* ---------------------    ---------------------
 * | HC-SC04 | Arduino |    | 3 pins  | Arduino |
 * ---------------------    ---------------------
 * |   Vcc   |   5V    |    |   Vcc   |   5V    |
 * |   Trig  |   12    | OR |   SIG   |   13    |
 * |   Echo  |   13    |    |   Gnd   |   GND   |
 * |   Gnd   |   GND   |    
 */

#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
int LED = 8;

void setup() {

  pinMode (LED,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Distance in CM: ");
  // Pass INC as a parameter to get the distance in inches
  Serial.println(ultrasonic.distanceRead());
  if (0 < ultrasonic.distanceRead() < 10 ){
    digitalWrite(LED,HIGH);
  }
  else {
    digitalWrite(LED,LOW);
    
  }
  delay (500);
  }
  

