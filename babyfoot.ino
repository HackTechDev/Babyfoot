#include "Ultrasonic.h"
#include <SerialLCD.h>
#include <SoftwareSerial.h>

Ultrasonic ultrasonic(7);

SerialLCD slcd(5,6);

int goal = 0;

void setup() {
  
    Serial.begin(9600);
  slcd.begin();
  slcd.setCursor(0, 0);
  slcd.print("");
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
      slcd.setCursor(0, 0);
      slcd.print("BUT"); 
      goal = 1;
    } 

    if (RangeInCentimeters > 3) {
      goal = 0;
      slcd.setCursor(0, 0);
      slcd.print("");
    }

    delay(250);

}
