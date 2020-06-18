#include "Ultrasonic.h"


Ultrasonic ultrasonic(7);

int goal = 0;

void setup() {
  
    Serial.begin(9600);

}

void loop() {

    long RangeInCentimeters;


    delay(250);


    RangeInCentimeters = ultrasonic.MeasureInCentimeters();

    Serial.print(RangeInCentimeters); //0~400cm

    Serial.println(" cm");

    if (RangeInCentimeters <= 3 && goal == 0) {
      Serial.println(" ######  #     # ####### ");
      Serial.println(" #     # #     #    #    ");
      Serial.println(" #     # #     #    #    ");
      Serial.println(" ######  #     #    #    ");
      Serial.println(" #     # #     #    #    ");
      Serial.println(" #     # #     #    #    ");
      Serial.println(" ######   #####     #    ");
      goal = 1;
    } 

    if (RangeInCentimeters > 3) {
      goal = 0;
    }

    delay(250);

}
